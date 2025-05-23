#pragma once

#include <dice/hfe/IEventManager.hpp>
#include <map>

namespace dice::hfe
{
	const uint32_t CID_EventManager = 0x9C75;

	class EventManager : public IEventManager
	{
	public:
		struct EventHandlerRegistryNode
		{
			IEventListener* listener;
			EventHandlerRegistryNode* next;
			int32_t priority;
		};

	public:
		uint32_t m_refCount;
		uint32_t m_dispatchCounter;
		uint32_t m_unknown10;
		EventNode* m_currentEvent;
		double m_currentTime;
		EventHandlerRegistryNode*
			m_eventHandlerRegistry[static_cast<size_t>(EventCategory::ECCount)];
		// NotificationEventNode m_eventNode; // offset 0x88 (bf2: 0073d693)
		// size 0x38 (bf2: 0073d08b)
		char m_eventNode[0x38];
		uint32_t m_unknownC0;
		std::map<int32_t, std::string>
			m_eventRegistry[static_cast<size_t>(EventCategory::ECCount)];

	public:
		static IBase* create(uint32_t, IBase*);
		EventManager();

		virtual void addRef() override;
		virtual uint32_t getRef() override;
		virtual uint32_t release() override;
		virtual IBase* queryInterface(uint32_t p_param) override;
		virtual uint32_t postEvent(EventCategory, EventNode*, float) override;
		virtual uint32_t
		postEvent(EventCategory, uint32_t, void*, float) override;
		virtual uint32_t
		postEventNextUpdate(EventCategory, EventNode*) override;
		virtual uint32_t
		postEventNextUpdate(EventCategory, uint32_t, void*) override;
		virtual bool processEvents(float) override;
		virtual void removePendingEvents() override;
		virtual bool removeEvent(uint32_t) override;
		virtual bool registerEventHandler(
			EventCategory, IEventListener*, int32_t = 0) override;
		virtual bool
		unregisterEventHandler(EventCategory, IEventListener*) override;
		virtual bool
		registerEvent(EventCategory, uint32_t, const std::string&) override;
		virtual bool unregisterEvent(EventCategory, uint32_t) override;
		virtual ~EventManager();
	};
#if defined(WIN32)
	// TODO: Win32 static_assert
#else
	static_assert(sizeof(EventManager) == 0x308);	 // bf2: 0084d743
#endif

	extern EventManager* g_eventManager;
	extern EventManager* g_frameEventManager;
}	 // namespace dice::hfe
