#include "NetworkModule.hpp"

using namespace dice::hfe::io;

/**
 * @brief Adds a reference to this class
 */
void NetworkModule::addRef()
{
    m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current reference count
 */
uint32_t NetworkModule::getRef()
{
    return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t NetworkModule::release()
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
 * @return NetworkModule*
 */
NetworkModule* NetworkModule::queryInterface(uint32_t iid)
{
    if (iid == IID_IBase)
        return this;

    if (iid == IID_IClassServer)
        return this;

    if (iid == IID_IModule)
        return this;

    return nullptr;
}

void NetworkModule::getClassList(std::vector<ClassRegInfo>& regInfos)
{
    // TODO: Implement
    /*
    {
        auto regInfo = ClassRegInfo(CID_NetworkableInfoManager, "dice.hfe.io.NetworkableInfoManager.Standard", NetworkableInfoManager::create);
        regInfos.push_back(regInfo);
    }
    */
}

void NetworkModule::getSingletonList(std::vector<SingletonRegInfo>& regInfos)
{
    // TODO: Implement
    /*
    {
        auto regInfo = SINGLETON_REG_INFO("NetworkableInfoManager", g_networkableInfoManager, IID_INetworkableInfoManager, CID_NetworkableInfoManager, 1);
        regInfos.push_back(regInfo);
    }
    */
}

bool NetworkModule::init()
{
    // TODO: Implement
    // g_mainConsoleObjects->registerConsoleObjects(getActiveNetworkableInfo::moduleNetworkList);
    return true;
}

bool NetworkModule::close()
{
    // TODO: Implement
    // g_mainConsoleObjects->unregisterConsoleObjects(getActiveNetworkableInfo::moduleNetworkList);
    return true;
}
