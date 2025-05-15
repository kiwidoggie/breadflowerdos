#include "Module.hpp"

using namespace dice::hfe::world;

/**
 * @brief Adds a reference to this class
 */
void Module::addRef()
{
    m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current reference count
 */
uint32_t Module::getRef()
{
    return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t Module::release()
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
 * @return Module*
 */
Module* Module::queryInterface(uint32_t iid)
{
    if (iid == IID_IBase)
        return this;

    if (iid == IID_IClassServer)
        return this;

    if (iid == IID_IModule)
        return this;

    return nullptr;
}

void Module::getClassList([[maybe_unused]] std::vector<ClassRegInfo>& regInfos)
{
}

void Module::getSingletonList(std::vector<SingletonRegInfo>& regInfos)
{
    // TODO: Implement
    /*
    {
        auto regInfo = SINGLETON_REG_INFO("ObjectManager", g_objectManager, IID_IObjectManager, CID_ObjectManager, 1);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = SINGLETON_REG_INFO("ObjectTemplateManager", g_objectTemplateManager, IID_IObjectTemplateManager, CID_ObjectTemplateManager, 1);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = SINGLETON_REG_INFO("PlayerManager", g_playerManager, IID_IPlayerManager, CID_PlayerManager, 1);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = SINGLETON_REG_INFO("WindManager", g_windManager, IID_IWindManager, CID_WindManager, 1);
        regInfos.push_back(regInfo);
    }
    */
}

bool Module::init()
{
    // TODO: Implement
    /*
    g_mainConsoleObjects->registerConsoleObjects(objectManager::myList);
    g_mainConsoleObjects->registerTypeConversion("IObject*", "object");
    g_mainConsoleObjects->registerTypeConversion("IObject_ptrproxy", "object");
    g_mainConsoleObjects->registerTypeConversion("world::IObject*", "object");
    g_mainConsoleObjects->registerTypeConversion("world::IObject_ptrproxy", "object");
    g_mainConsoleObjects->registerTypeConversion("IObjectTemplate*", "objectTemplate");
    g_mainConsoleObjects->registerTypeConversion("IObjectTemplate_ptrproxy", "objectTemplate");
    g_mainConsoleObjects->registerTypeConversion("world::IObjectTemplate*", "objectTemplate");
    g_mainConsoleObjects->registerTypeConversion("world::IObjectTemplate_ptrproxy", "objectTemplate");
    g_mainConsoleObjects->registerTypeConversion("const IObjectTemplate*", "objectTemplate");
    g_mainConsoleObjects->registerTypeConversion("const IObjectTemplate_ptrproxy", "objectTemplate");
    g_mainConsoleObjects->registerTypeConversion("const world::IObjectTemplate*", "objectTemplate");
    g_mainConsoleObjects->registerTypeConversion("const world::IObjectTemplate_ptrproxy", "objectTemplate");
    */
    return true;
}

bool Module::close()
{
    // TODO: Implement
    // g_mainConsoleObjects->unregisterConsoleObjects(objectManager::myList);
    return true;
}
