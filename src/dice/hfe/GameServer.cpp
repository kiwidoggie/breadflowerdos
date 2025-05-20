#include "GameServer.hpp"
#include "EventManager.hpp"

using namespace dice::hfe;
/*
IBase* GameServer::create(uint32_t id, IBase* base)
{
    // TODO: Implement
    if (base == nullptr)
    {
        auto gameServer = new GameServer();
        if (gameServer->queryInterface(id) == nullptr)
        {
            gameServer->release();
        }

        base = static_cast<Game*>(gameServer);
    }

    return base;
}

GameServer::GameServer() : m_refCount(1)
{
    // TODO: Implement
    g_eventManager->registerEventHandler(EventCategory::ECNetwork, this);
    g_eventManager->registerEventHandler(EventCategory::ECCore, this);
    g_eventManager->registerEventHandler(EventCategory::ECHud, this);
    g_eventManager->registerEventHandler(EventCategory::ECGameLogic, this);
}
*/
