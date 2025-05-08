#pragma once

namespace dice
{
    namespace hfe
    {
        enum class EventCategory;
        class EventNode;

        class IEventListener
        {
        public:
            virtual void handleEvent(EventCategory p_Category, uint32_t p_Unknown, EventNode* p_EventNode, void*) = 0;
        };
    }
}
