#pragma once
#include <cstdint>

namespace dice::hfe
{
	enum class EventCategory;
	class EventNode;

	const uint32_t IID_IEventListener = 0x9C4A;

	class IEventListener
	{
	public:
		virtual void handleEvent(
			EventCategory p_Category, uint32_t p_Type, EventNode* p_EventNode,
			void* p_Data) = 0;
	};
}	 // namespace dice::hfe
