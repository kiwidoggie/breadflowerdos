#include "ModuleGame.hpp"
#include "EventManager.hpp"

using namespace dice::hfe;

/**
 * @brief Adds a reference to this class
 */
void ModuleGame::addRef()
{
	m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current
 * reference count
 */
uint32_t ModuleGame::getRef()
{
	return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t ModuleGame::release()
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
 * @param p_param
 * @return ModuleGame*
 */
ModuleGame* ModuleGame::queryInterface(uint32_t p_param)
{
	if (p_param == IID_IBase)
		return this;

	if (p_param == IID_IClassServer)
		return this;

	if (p_param == IID_IModule)
		return this;

	return nullptr;
}

void ModuleGame::getClassList(std::vector<ClassRegInfo>& regInfos)
{
	// TODO: Implement
	/*
    {
        auto regInfo = ClassRegInfo(CID_StatsManager,
	 * "dice.hfe.StatsManager", StatsManager::create);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * ClassRegInfo(CID_PlayerStatsManager, "dice.hfe.PlayerStatsManager",
	 * PlayerStatsManager::create);
        regInfos.push_back(regInfo);
    }

	 * {
        auto regInfo = ClassRegInfo(CID_PlayerAwards,
	 * "dice.hfe.PlayerAwards", PlayerAwards::create);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * ClassRegInfo(CID_PlayerStats, "dice.hfe.PlayerStats",
	 * PlayerStats::create);
        regInfos.push_back(regInfo);
    }
    {

	 * auto regInfo = ClassRegInfo(CID_PlayerUnlocks, "dice.hfe.PlayerUnlocks",
	 * PlayerUnlocks::create);
        regInfos.push_back(regInfo);
    }
    {

	 * auto regInfo = ClassRegInfo(CID_SearchForPlayer,
	 * "dice.hfe.SearchForPlayer", SearchForPlayer::create);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * ClassRegInfo(CID_LeaderBoard, "dice.hfe.LeaderBoard",
	 * LeaderBoard::create);
        regInfos.push_back(regInfo);
    }
    {

	 * auto regInfo = ClassRegInfo(CID_PlayerUnlockInfo,
	 * "dice.hfe.PlayerUnlockInfo", PlayerUnlockInfo::create);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * ClassRegInfo(CID_PlayerRankInfo, "dice.hfe.PlayerRankInfo",
	 * PlayerRankInfo::create);
        regInfos.push_back(regInfo);
    }
 {

	 * auto regInfo = ClassRegInfo(CID_ModInfo, "dice.hfe.ModInfo",
	 * ModInfo::create);
        regInfos.push_back(regInfo);
    }
    */
}

void ModuleGame::getSingletonList(std::vector<SingletonRegInfo>& regInfos)
{
	// TODO: Implement
	/*
    {
        auto regInfo = SINGLETON_REG_INFO("ModInfo", g_modInfo,
	 * IID_IModInfo, CID_ModInfo, 2);
        regInfos.push_back(regInfo);
 }

	 */
}

bool ModuleGame::init()
{
	// TODO: Implement
	// g_mainConsoleObjects->registerConsoleObjects(hudInformationLayer::gameList);
	g_eventManager->registerEventHandler(EventCategory::ECMainMenu, this, 0);
	g_eventManager->registerEventHandler(EventCategory::ECGameLogic, this, 0);
	g_eventManager->registerEventHandler(EventCategory::ECCore, this, 0);
	m_initialized = true;
	return true;
}

bool ModuleGame::close()
{
	// TODO: Implement
	g_eventManager->unregisterEventHandler(EventCategory::ECCore, this);
	g_eventManager->unregisterEventHandler(EventCategory::ECGameLogic, this);
	g_eventManager->unregisterEventHandler(EventCategory::ECMainMenu, this);
	// g_mainConsoleObjects->unregisterConsoleObjects(hudInformationLayer::gameList);
	return true;
}

void ModuleGame::handleEvent(
	[[maybe_unused]] EventCategory p_Category, [[maybe_unused]] uint32_t p_ID,
	[[maybe_unused]] EventNode* p_EventNode, [[maybe_unused]] void* p_Data)
{
}
