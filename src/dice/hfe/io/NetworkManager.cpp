#include "NetworkManager.hpp"
#include <cstring>

using namespace dice::hfe::io;

// bf2: 007c7440
NetworkManager::NetworkManager()
{
    // TODO: Implement

    auto s_Buffer = new uint8_t[0x8000];
    if (s_Buffer != nullptr)
    {
        memset(s_Buffer, 0, 0x8000);
    }
}

NetworkManager::~NetworkManager()
{
    // TODO: Implement
}

// bf2: 007c8900
void NetworkManager::handleEvent(EventCategory p_Category, uint32_t p_ID, [[maybe_unused]] EventNode* p_EventNode, void* p_Unknown)
{
    // TODO: Implement
}