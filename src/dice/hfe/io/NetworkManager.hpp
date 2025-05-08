#pragma once
#include <dice/hfe/IEventListener.hpp>
#include <cstdint>

namespace dice
{
    namespace hfe
    {
        enum class EventCategory;

        namespace io
        {
            class SocketManager;

            class NetworkManager :
                public IEventListener
            {
            public:
                uint8_t m_unknown08[0x180];

            public:
                NetworkManager();
                virtual void handleEvent(EventCategory p_Category, uint32_t p_Unknown, EventNode* p_EventNode, void*);
                virtual ~NetworkManager();
            };
            
            static_assert(sizeof(NetworkManager) == 0x188);

            
        }
    }
}