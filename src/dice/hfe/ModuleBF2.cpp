#include "ModuleBF2.hpp"

using namespace dice::hfe;

/**
 * @brief Adds a reference to this class
 */
void ModuleBF2::addRef()
{
	m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current
 * reference count
 */
uint32_t ModuleBF2::getRef()
{
	return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t ModuleBF2::release()
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
 * @return ModuleBF2*
 */
ModuleBF2* ModuleBF2::queryInterface(uint32_t p_param)
{
	if (p_param == IID_IBase)
		return this;

	if (p_param == IID_IClassServer)
		return this;

	if (p_param == IID_IModule)
		return this;

	return nullptr;
}

void ModuleBF2::getClassList(std::vector<ClassRegInfo>& regInfos)
{
	// TODO: Implement
	/*
    {
        auto regInfo = ClassRegInfo(CID_GameServer,
	 * "dice.bf.gameServer", GameServer::create);
 regInfos.push_back(regInfo);

	 * }
    {
        auto regInfo = ClassRegInfo(world::CID_PlayerManager,
	 * "dice.hfe.world.PlayerManager.Standard", world::PlayerManager::create);

	 * regInfos.push_back(regInfo);
    }
    */
}

// bf2: 008ac450
void ModuleBF2::getSingletonList(
	[[maybe_unused]] std::vector<SingletonRegInfo>& regInfos)
{
}

bool ModuleBF2::init()
{
	// TODO: Implement
	// g_mainConsoleObjects->registerConsoleObjects(game::myList);
	return true;
}

bool ModuleBF2::close()
{
	// TODO: Implement
	// g_mainConsoleObjects->unregisterConsoleObjects(game::myList);
	return true;
}
