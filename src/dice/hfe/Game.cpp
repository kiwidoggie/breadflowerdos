#include "Game.hpp"

using namespace dice::hfe;

Game* dice::hfe::g_game = nullptr;

MapInfo* Game::getMapInfo(MapInfo* mapInfo)
{
	*mapInfo = m_currentMap;
	return mapInfo;
}

bool Game::localRadioMessage(TargetChannel, std::string const&)
{
	// TODO: Implement
	return true;
}

bool Game::localGameInfoMessage(TargetChannel, std::string const&)
{
	// TODO: Implement
	return true;
}

void Game::addPlayerInput(io::PlayerInput const&)
{
	// TODO: Implement
}

void* Game::getObjectFromNetworkableId(uint16_t const&)
{
	// TODO: Implement
	return nullptr;
}

void Game::createAndDestroyObject(world::IObjectTemplate const*)
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

std::string const& Game::listSquadMembers(int32_t, int32_t)
{
	// TODO: Implement
	return "";
}

std::string const& dice::hfe::Game::listSquads(int32_t)
{
	// TODO: Implement
	return "";
}

void Game::changeSquadName(std::string const&, bool)
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

std::string const& Game::getSpottedMessage(uint16_t)
{
	// TODO: Implement
	return "";
}

void Game::sendSpottedMessage(world::IPlayer*, uint16_t, Vec2, world::VehicleType)
{
	// TODO: Implement
}

void Game::callForSpecialist(world::IPlayer*, HudNodeTypes)
{
	// TODO: Implement
}

std::string const& Game::getCurrentMapName() const
{
	return m_currentMap.getMapName();
}

std::string const& Game::getCurrentMapGameMode() const
{
	return m_currentMap.getGameMode();
}

std::string const& Game::getCurrentMapLevelPath() const
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
