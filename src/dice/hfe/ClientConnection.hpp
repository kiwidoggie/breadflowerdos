#pragma once
#include <dice/hfe/IClientConnection.hpp>

namespace dice::hfe
{
	class GhostManager;
	class PlayerActionManager;

	class ClientConnection : public IClientConnection
	{
	public:
		char _0x8[0x8];
		world::IPlayer* m_player;
		int m_connectionState;
		char _0x1c[0x1C];
		PlayerActionManager* m_playerActionManager;
		GhostManager* m_ghostManager;
		char _0x48[0x1a0];
	};

	static_assert(sizeof(ClientConnection) == 0x1E8);
}	 // namespace dice::hfe
