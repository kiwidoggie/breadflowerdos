#include "ModuleGameLogic.hpp"

using namespace dice::hfe;

/**
 * @brief Adds a reference to this class
 */
void ModuleGameLogic::addRef()
{
    m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current reference count
 */
uint32_t ModuleGameLogic::getRef()
{
    return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t ModuleGameLogic::release()
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
 * @return ModuleGameLogic*
 */
ModuleGameLogic* ModuleGameLogic::queryInterface(uint32_t p_param)
{
    if (p_param == IID_IBase)
        return this;

    if (p_param == IID_IClassServer)
        return this;

    if (p_param == IID_IModule)
        return this;

    return nullptr;
}

void ModuleGameLogic::getClassList(std::vector<ClassRegInfo>& regInfos)
{
    // TODO: Implement
    /*
    {
        auto regInfo = ClassRegInfo(CID_SquadManager, "dice.bf.SquadManager", SquadManager::create);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = ClassRegInfo(CID_ClientSquadManager, "dice.bf.ClientSquadManager", ClientSquadManager::create);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = ClassRegInfo(CID_ClientGameLogic, "dice.bf.clientGameLogic", ClientGameLogic::create);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = ClassRegInfo(CID_ServerGameLogic, "dice.bf.serverGameLogic", ServerGameLogic::create);
        regInfos.push_back(regInfo);
    }
    */
}

void ModuleGameLogic::getSingletonList(std::vector<SingletonRegInfo>& regInfos)
{
}

bool ModuleGameLogic::init()
{
    // TODO: Implement
    // g_mainConsoleObjects->registerConsoleObjects(gameLogic::myList);
    // world::playerManager->function0xd0(world::CID_Player, "Player");
    return true;
}

bool ModuleGameLogic::close()
{
    // TODO: Implement
    // g_mainConsoleObjects->unregisterConsoleObjects(gameLogic::myList);
    return true;
}
