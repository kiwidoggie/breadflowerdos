#pragma once

#include <dice/hfe/EventCategory.hpp>
#include <dice/hfe/IBase.hpp>
#include <string>

namespace dice::hfe
{
	class EventNode;
	class IEventListener;

	const uint32_t IID_IEventManager = 0x9C4A;

	class IEventManager : public IBase
	{
	public:
		virtual uint32_t postEvent(EventCategory, EventNode*, float) = 0;
		virtual uint32_t postEvent(EventCategory, uint32_t, void*, float) = 0;
		virtual uint32_t postEventNextUpdate(EventCategory, EventNode*) = 0;
		virtual uint32_t
		postEventNextUpdate(EventCategory, uint32_t, void*) = 0;
		virtual bool processEvents(float) = 0;
		virtual void removePendingEvents() = 0;
		virtual bool removeEvent(uint32_t) = 0;
		virtual bool
		registerEventHandler(EventCategory, IEventListener*, int32_t) = 0;
		virtual bool unregisterEventHandler(EventCategory, IEventListener*) = 0;
		virtual bool
		registerEvent(EventCategory, uint32_t, const std::string&) = 0;
		virtual bool unregisterEvent(EventCategory, uint32_t) = 0;
	};
}	 // namespace dice::hfe
