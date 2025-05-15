#pragma once
#include <dice/hfe/Game.hpp>
#include <dice/hfe/IGameServer.hpp>
#include <dice/hfe/IEventListener.hpp>
#include <dice/hfe/ServerConnection.hpp>

#include <map>

namespace dice
{
    namespace hfe
    {
        const uint32_t CID_GameServer = 0x1D8AA;

        class GameServer : public Game, public IGameServer, public IEventListener
        {
        public:
            char m_unknown90[0x58];
            std::map<unsigned char, ServerConnection*> m_clientConnections; // 0xE8
            char m_unknown118[0x220];
        };

        static_assert(sizeof(GameServer) == 0x338);
    }
}