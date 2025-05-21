#include "PlayerManager.hpp"
#include "IPlayer.hpp"

using namespace dice::hfe::world;

dice::hfe::IBase* PlayerManager::create(uint32_t id, IBase* playerManager)
{
    if (playerManager == nullptr)
    {
        playerManager = new PlayerManager();
        if (playerManager->queryInterface(id) == nullptr)
        {
            playerManager->release();
        }
    }

    return playerManager;
}

PlayerManager::PlayerManager() : m_refCount(1)
{
    // TODO: Implement
}

/**
 * @brief Adds a reference to this class
 */
void PlayerManager::addRef()
{
    m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current reference count
 */
uint32_t PlayerManager::getRef()
{
    return m_refCount;
}

/**
 * @brief Removes a reference from this class. Calls the deconstructor if there are no more references.
 * @return uint32_t Current reference count
 */
uint32_t PlayerManager::release()
{
    m_refCount--;
    if (m_refCount != 0)
    {
        return m_refCount;
    }

    delete this;
    return 0;
}

/**
 * @brief TODO: Documentation
 * @param iid
 * @return PlayerManager*
 */
dice::hfe::IBase* PlayerManager::queryInterface(uint32_t iid)
{
    if (iid == IID_IBase)
        return this;

    if (iid == IID_IPlayerManager)
        return this;

    return nullptr;
}

void PlayerManager::addPlayer(IPlayer* player)
{
    // SingletonServer::m_iNametagManager->function0x38();

    m_players.push_back(player);
    m_idToPlayerMap[player->getId()] = player;

    // TODO: some StringHash that basically does this: m_playerMap[player->getName()] = player;

    setActivePlayer(player);
}

void PlayerManager::removePlayer(IPlayer* player)
{
    // TODO: Implement
}

void PlayerManager::removePlayerId(int32_t id)
{
    // TODO: Implement
}

IPlayer* PlayerManager::getPlayerFromName(std::string const& name)
{
    // TODO: Implement
    return nullptr;
}

IPlayer* PlayerManager::getPlayerFromId(int32_t id)
{
    auto it = m_idToPlayerMap.find(id);
    return it != m_idToPlayerMap.end() ? it->second : nullptr;
}

IPlayer* PlayerManager::getNextPlayerFromId(int32_t id)
{
    auto it = m_idToPlayerMap.find(id);
    if (it == m_idToPlayerMap.end())
        return nullptr;

    ++it;

    if (it != m_idToPlayerMap.end()) {
        return it->second;
    }

    if (m_idToPlayerMap.empty())
        return nullptr;

    it = m_idToPlayerMap.begin();
    return it->second;
}

IPlayer* PlayerManager::getPlayerFromProfileId(int32_t id)
{
    // TODO: Implement
    return nullptr;
}

IPlayer* PlayerManager::getPlayerFromIdString(std::string const& name)
{
    // TODO: Implement
    return nullptr;
}

IPlayer* PlayerManager::getLocalHumanPlayer()
{
    return m_localPlayer;
}

IPlayer* PlayerManager::setLocalHumanPlayer(IPlayer* player)
{
    if (player != nullptr)
    {
        player->updateClientSettings();
    }
    m_localPlayer = player;
    return player;
}

IPlayer* PlayerManager::setLocalHumanPlayer(int32_t id)
{
    m_localPlayer = getPlayerFromId(id);
    if (m_localPlayer != nullptr)
    {
        m_localPlayer->updateClientSettings();
    }
    return m_localPlayer;
}

std::list<IPlayer*>& PlayerManager::getPlayers()
{
    return m_players;
}

std::list<IPlayer*>& PlayerManager::getPlayersSortedByScore()
{
    // TODO: Implement
    auto players = std::list<IPlayer*>();
    return players;
}

std::list<IPlayer*>& PlayerManager::getPlayersSortedByRank()
{
    // TODO: Implement
    auto players = std::list<IPlayer*>();
    return players;
}

std::list<IPlayer*>& PlayerManager::getPlayers(int32_t teamId)
{
    m_tempPlayers.clear();

    for (auto& player : m_players)
    {
        if (player->getTeam() == teamId) {
            m_tempPlayers.push_back(player);
        }
    }

    return m_tempPlayers;
}

std::list<IPlayer*>& PlayerManager::getPlayersSortedByScore(int32_t teamId)
{
    // TODO: Implement
    auto players = std::list<IPlayer*>();
    return players;
}

std::list<IPlayer*>& PlayerManager::getPlayersSortedByRank(int32_t teamId)
{
    // TODO: Implement
    auto players = std::list<IPlayer*>();
    return players;
}

std::list<IPlayer*>& PlayerManager::getPlayersInSquad(int32_t teamId, int32_t squadId)
{
    m_tempPlayers.clear();

    for (auto& player : m_players)
    {
        if (player->getTeam() == teamId && player->getSquadId() == squadId) {
            m_tempPlayers.push_back(player);
        }
    }

    return m_tempPlayers;
}

std::list<IPlayer*>& PlayerManager::getPlayersInSquadSortedByScore(int32_t teamId, int32_t squadId)
{
    // TODO: Implement
    auto players = std::list<IPlayer*>();
    return players;
}


std::list<IPlayer*>& PlayerManager::getPlayersInSquadSortedByRank(int32_t teamId, int32_t squadId)
{
    // TODO: Implement
    auto players = std::list<IPlayer*>();
    return players;
}

std::list<IPlayer*>& PlayerManager::getTeamSquadLeaders(int32_t teamId)
{
    m_tempPlayers.clear();

    for (auto& player : m_players)
    {
        if (player->getIsSquadLeader() && player->getTeam() == teamId) {
            m_tempPlayers.push_back(player);
        }
    }

    return m_tempPlayers;
}

void PlayerManager::updatePlayers(float dt)
{
    // TODO: Implement
    /*for (auto& player : m_players)
    {
        getPlayer(player)->update(dt);
    }*/
}

void PlayerManager::registerPlayerClass(uint32_t classId, const std::string& className)
{
    m_playerClasses[classId] = className;
}

void PlayerManager::getPlayerClasses(std::list<std::pair<uint32_t, std::string>>& outList) const
{
    for (const auto& kv : m_playerClasses) {
        outList.emplace_back(kv.first, kv.second);
    }
}

std::string const& PlayerManager::getClassNameFromPlayerClassID(uint32_t) const
{
    // TODO: Implement
    return "";
}

IPlayer* PlayerManager::createPlayer(uint32_t, std::string const&, int32_t)
{
    // TODO: Implement
    return nullptr;
}

IPlayer* PlayerManager::createPlayer(std::string const&, std::string const&, int32_t)
{
    // TODO: Implement
    return nullptr;
}

bool PlayerManager::saveAllPlayers(std::string const&)
{
    // TODO: Implement
    return false;
}

IPlayer* PlayerManager::getActivePlayer() const
{
    return m_activePlayer;
}

void PlayerManager::setActivePlayer(IPlayer* player)
{
    m_activePlayer = player;
}

uint32_t PlayerManager::getNumberOfPlayers() const
{
    return m_players.size();
}

uint32_t PlayerManager::getNumberOfHumanPlayers() const
{
    uint32_t playerCount = 0;
    
    for (auto& player : m_players)
    {
        if (!player->getIsAIPlayer())
        {
            ++playerCount;
        }
    }

    return playerCount;
}

uint32_t PlayerManager::getNumberOfAliveHumanPlayers() const
{
    uint32_t playerCount = 0;

    for (auto& player : m_players)
    {
        if (!player->getIsAIPlayer() && player->getIsConnected()) // TODO: is this a bug in bf2? shouldn't this be getIsAlive()?
        {
            ++playerCount;
        }
    }

    return playerCount;
}

uint32_t PlayerManager::getNrOfPlayerInTeam(int32_t teamId)
{
    uint32_t playerCount = 0;

    for (auto& player : m_players)
    {
        if (player->getTeam() == teamId)
        {
            ++playerCount;
        }
    }

    return playerCount;
}

uint32_t PlayerManager::getNrOfPlayerInSquads(int32_t teamId)
{
    uint32_t playerCount = 0;

    for (auto& player : m_players)
    {
        if (player->getTeam() == teamId && player->getSquadId() != 0)
        {
            ++playerCount;
        }
    }

    return playerCount;
}

uint32_t PlayerManager::getNrOfPlayersInSquad(int32_t teamId, int32_t squadId)
{
    uint32_t playerCount = 0;

    for (auto& player : m_players)
    {
        if (player->getTeam() == teamId && player->getSquadId() == squadId)
        {
            ++playerCount;
        }
    }

    return playerCount;
}

std::list<IPlayer*>& PlayerManager::getInvitedPlayers(int32_t teamId, int32_t squadId)
{
    m_tempPlayers.clear();

    for (auto& player : m_players)
    {
        if (player->getTeam() == teamId && player->getSquadId() != squadId && player->getIsInvitedToSquad(squadId))
        {
            m_tempPlayers.push_back(player);
        }
    }

    return m_tempPlayers;
}

uint32_t PlayerManager::getNrOfActiveSquads(int32_t teamId)
{
    uint32_t activeSquadCount = 0;
    // TODO: should we use sth like SquadId::SquadCount? That way we can increase the max squad count later on.
    for (size_t squadId = 1; squadId <= 10; squadId++)
    {
        if (getNrOfPlayersInSquad(teamId, squadId) > 0)
        {
            activeSquadCount++;
        }
    }
    
    return activeSquadCount;
}

int32_t PlayerManager::getTeamToAddPlayer(float, float)
{
    // TODO: Implement
    return 0;
}

bool PlayerManager::deactivatePlayer(int32_t)
{
    // TODO: Implement
    return false;
}

bool PlayerManager::reactivatePlayer(int32_t)
{
    // TODO: Implement
    return false;
}

bool PlayerManager::renamePlayer(IPlayer*, std::string)
{
    // TODO: Implement
    return false;
}
