#include "Module.hpp"
#include "ClassRegInfo.hpp"
#include "SingletonRegInfo.hpp"
#include "System.hpp"
#include "EventManager.hpp"
#include "MemoryPool.hpp"
#include "Profiler.hpp"

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
    {
        auto regInfo = ClassRegInfo(CID_MemoryPool, "dice.hfe.MemoryPool.Standard", MemoryPool::create);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = ClassRegInfo(CID_EventManager, "dice.hfe.EventManager", EventManager::create);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = ClassRegInfo(CID_Profiler, "dice.hfe.Profiler", Profiler::create);
        regInfos.push_back(regInfo);
    }
    // TODO: Implement
    /*
    {
        auto regInfo = ClassRegInfo(CID_DebugCounterManager, "dice.hfe.DebugCounterManager", DebugCounterManager::create);
        regInfos.push_back(regInfo);
    }
    */
}

void Module::getSingletonList(std::vector<SingletonRegInfo>& regInfos)
{
    // TODO: Implement
    {
        auto regInfo = SingletonRegInfo("System", (IBase**)&g_system, IID_IBase, CID_System);
        regInfos.push_back(regInfo);
    }
    /*
    {
        auto regInfo = SingletonRegInfo("MainConsoleObjects", g_mainConsoleObjects);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("BfGlobal_callback", g_bfGlobal_callback);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("BfGlobal_callbackData", g_bfGlobal_callbackData);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("DebugOn", g_debugOn);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("DebugModules", g_debugModules);
        regInfos.push_back(regInfo);
    }
    */
    {
        auto regInfo = SingletonRegInfo("EventManager", (IBase**)&g_eventManager, IID_IBase, CID_EventManager, 2);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("FrameEventManager", (IBase**)&g_frameEventManager, IID_IBase, CID_EventManager, 2);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("Profiler", (IBase**)&g_profiler, IID_IProfilerClient, CID_Profiler, 2);
        regInfos.push_back(regInfo);
    }
    /*
    {
        auto regInfo = SingletonRegInfo("DebugCounterManager", g_debugCounterManager, IID_IDebugCounterManager, CID_DebugCounterManager, 1);
        regInfos.push_back(regInfo);
    }
    {
        auto regInfo = SingletonRegInfo("LoadStat", g_loadStat);
        regInfos.push_back(regInfo);
    }
    */
}

bool Module::init()
{
    // TODO: Implement
    //mainConsoleObjects->registerConsoleObjects(classManager::coreList);
    g_profilerClient = g_profiler;
    g_eventManager->registerEvent(EventCategory::ECCore, 2, "ECCoreCEPreLoad");
    g_eventManager->registerEvent(EventCategory::ECCore, 3, "ECCoreCEPostLoad");
    g_eventManager->registerEvent(EventCategory::ECCore, 4, "ECCoreCEUpdateLoadStats");
    g_eventManager->registerEvent(EventCategory::ECCore, 6, "ECCoreCEShutdownGame");
    g_eventManager->registerEvent(EventCategory::ECCore, 7, "ECCoreCEResourcesLoaded");
    g_eventManager->registerEvent(EventCategory::ECCore, 8, "ECCoreCEDebugTextHook");
    g_eventManager->registerEvent(EventCategory::ECCore, 9, "ECCoreCECollectSystemInfo");
    g_eventManager->registerEvent(EventCategory::ECCore, 13, "ECCoreCEUnloadLevel");
    g_eventManager->registerEvent(EventCategory::ECCore, 14, "ECCoreCEAbortLoadLevel");
    g_eventManager->registerEvent(EventCategory::ECCore, 15, "ECCoreCEActivateApp");
    g_eventManager->registerEvent(EventCategory::ECCore, 16, "ECCoreCEPeakWinMessages");
    g_eventManager->registerEvent(EventCategory::ECCore, 10, "ECCoreCEStartPerformanceTest");
    g_eventManager->registerEvent(EventCategory::ECCore, 11, "ECCoreCEStopPerformanceTest");
    g_eventManager->registerEvent(EventCategory::ECCore, 12, "ECCoreCEReportPerformanceInfo");
    return true;
}

bool Module::close()
{
    // TODO: Implement
    return true;
}
