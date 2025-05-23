#pragma once

#include <dice/hfe/IGame.hpp>

namespace dice::hfe
{
	struct MapInfo
	{
		std::string m_gamemode;
		std::string m_levelPath;
		std::string m_mapName;
		int m_maxPlayers;
		bool m_commanderEnabled;
		int m_challengeOrdinal;
		bool _0x24;
		bool _0x25;
		bool m_netBufferNeedsUpdate;	// 0x26
		void* m_netBuffer;				// 0x28
	};

	const uint32_t CID_Game = 0x1D8A9;

	class Game : public IGame
	{
	public:

		MapInfo m_currentMap;
		char _0x38[0x48];
	};

	extern Game* g_game;

#if defined(WIN32)
	// TODO: Win32 static_assert
#else
	static_assert(sizeof(Game) == 0x80);
	static_assert(sizeof(MapInfo) == 0x30);
#endif
}	 // namespace dice::hfe
