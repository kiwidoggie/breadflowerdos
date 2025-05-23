#pragma once
#include <dice/hfe/Game.hpp>
#include <dice/hfe/IEventListener.hpp>
#include <dice/hfe/IGameServer.hpp>

#include <map>

namespace dice::hfe
{
	class ServerConnection;

	const uint32_t CID_GameServer = 0x1D8AA;

	class GameServer : public Game, public IGameServer, public IEventListener
	{
	public:
		uint32_t m_refCount;
		char m_unknown90[0x54];
		std::map<unsigned char, ServerConnection*>
			m_clientConnections;	// 0xE8
		char m_unknown118[0x220];

	public:
		// static IBase* create(uint32_t, IBase*);
		// GameServer();
	};
#if defined(WIN32)
	// TODO: Win32 static_assert
#else
	static_assert(sizeof(GameServer) == 0x338);
#endif
}	 // namespace dice::hfe
