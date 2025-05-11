#include "Module.hpp"
#include "ClassRegInfo.hpp"
#include "SingletonRegInfo.hpp"

using namespace dice::hfe;

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
 * @param p_param
 * @return Module*
 */
Module* Module::queryInterface(uint32_t p_param)
{
    if (p_param == IID_IBase)
        return this;

    if (p_param == IID_IClassServer)
        return this;

    if (p_param == IID_IModule)
        return this;

    return nullptr;
}

void Module::getClassList(std::vector<ClassRegInfo>& regInfos)
{
    // TODO: Implement
    /*
    {
        auto regInfo = ClassRegInfo(CID_MemoryPool, "dice.hfe.MemoryPool.Standard", MemoryPool::create);
        regInfos.insert(regInfo);
    }
    {
        auto regInfo = ClassRegInfo(CID_EventManager, "dice.hfe.EventManager", EventManager::create);
        regInfos.insert(regInfo);
    }
    {
        auto regInfo = ClassRegInfo(CID_Profiler, "dice.hfe.Profiler", Profiler::create);
        regInfos.insert(regInfo);
    }
    {
        auto regInfo = ClassRegInfo(CID_DebugCounterManager, "dice.hfe.DebugCounterManager", DebugCounterManager::create);
        regInfos.insert(regInfo);
    }
    */
}

void Module::getSingletonList(std::vector<SingletonRegInfo>& regInfos)
{
    // TODO: Implement
    /*
    {
        auto regInfo = SingletonRegInfo("System", g_system, IID_IBase, CID_System);
        regInfos.insert(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("MainConsoleObjects", g_mainConsoleObjects);
        regInfos.insert(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("BfGlobal_callback", g_bfGlobal_callback);
        regInfos.insert(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("BfGlobal_callbackData", g_bfGlobal_callbackData);
        regInfos.insert(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("DebugOn", g_debugOn);
        regInfos.insert(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("DebugModules", g_debugModules);
        regInfos.insert(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("EventManager", g_eventManager, IID_Base, CID_EventManager, 2);
        regInfos.insert(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("FrameEventManager", g_frameEventManager, IID_Base, CID_EventManager, 2);
        regInfos.insert(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("Profiler", g_profiler, IID_IProfilerClient, CID_Profiler, 2);
        regInfos.insert(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("DebugCounterManager", g_debugCounterManager, IID_IDebugCounterManager, CID_DebugCounterManager, 1);
        regInfos.insert(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("LoadStat", g_loadStat);
        regInfos.insert(regInfo);
    }
    */
}

bool Module::init()
{
    // TODO: Implement
    return true;
}

bool Module::close()
{
    // TODO: Implement
    return true;
}
