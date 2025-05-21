#include "Game.hpp"

using namespace dice::hfe;

Game* dice::hfe::g_game = nullptr;

MapInfo* Game::getMapInfo(MapInfo* mapInfo)
{
	*mapInfo = m_currentMap;
	return mapInfo;
}
