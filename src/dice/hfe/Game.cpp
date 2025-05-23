#include "Game.hpp"

using namespace dice::hfe;

Game* dice::hfe::g_game = nullptr;

MapInfo* Game::getMapInfo(MapInfo* mapInfo)
{
	*mapInfo = m_currentMap;
	return mapInfo;
}

bool Game::localRadioMessage(TargetChannel, const std::string&)
{
	// TODO: Implement
	return true;
}

bool Game::localGameInfoMessage(TargetChannel, const std::string&)
{
	// TODO: Implement
	return true;
}

void Game::addPlayerInput(const io::PlayerInput&)
{
	// TODO: Implement
}

void* Game::getObjectFromNetworkableId(const uint16_t&)
{
	// TODO: Implement
	return nullptr;
}

void Game::createAndDestroyObject(const world::IObjectTemplate*)
{
	// TODO: Implement
}

bool Game::destroyObject(world::IObject*)
{
	// TODO: Implement
	return false;
}

void Game::joinSquad(int32_t)
{
	// TODO: Implement
}

void Game::leaveSquad(int32_t)
{
	// TODO: Implement
}

const std::string& Game::listSquadMembers(int32_t, int32_t)
{
	// TODO: Implement
	return "";
}

const std::string& dice::hfe::Game::listSquads(int32_t)
{
	// TODO: Implement
	return "";
}

void Game::changeSquadName(const std::string&, bool)
{
	// TODO: Implement
}

void Game::makeMeCommander()
{
	// TODO: Implement
}

void Game::popNextCommanderApplicant(int32_t)
{
	// TODO: Implement
}

const std::string& Game::getSpottedMessage(uint16_t)
{
	// TODO: Implement
	return "";
}

void Game::sendSpottedMessage(
	world::IPlayer*, uint16_t, Vec2, world::VehicleType)
{
	// TODO: Implement
}

void Game::callForSpecialist(world::IPlayer*, HudNodeTypes)
{
	// TODO: Implement
}

const std::string& Game::getCurrentMapName() const
{
	return m_currentMap.getMapName();
}

const std::string& Game::getCurrentMapGameMode() const
{
	return m_currentMap.getGameMode();
}

const std::string& Game::getCurrentMapLevelPath() const
{
	return m_currentMap.getLevelPath();
}

int32_t Game::getCurrentMapMaxPlayers() const
{
	return m_currentMap.getMaxNumberOfPlayers();
}

uint32_t Game::getCurrentMapSize() const
{
	return m_currentMapSize;
}

void Game::setCurrentMapSize(uint32_t mapSize)
{
	m_currentMapSize = mapSize;
}
