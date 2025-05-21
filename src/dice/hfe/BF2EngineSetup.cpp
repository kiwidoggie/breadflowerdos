#include "BF2EngineSetup.hpp"
#include "BF2Engine.hpp"
#include "io/io.hpp"
#include "io/NetworkManager.hpp"
#include "ClassManager.hpp"
#include "MemoryPool.hpp"

#include "Module.hpp"
#include "ModuleBF2.hpp"
#include "ModuleGame.hpp"
#include "ModuleGameLogic.hpp"
#include "MathModule.hpp"
#include "io/ModuleIO.hpp"
#include "io/FileModule.hpp"
#include "world/Module.hpp"
#include "world/ObjectModule.hpp"
#include "world/ObjTemplPortalModule.hpp"
#include "ModuleNetworkables.hpp"
#include "world/ObjTemplBaseModule.hpp"
#include "tool/ModuleToolObject.hpp"
#include "world/PhysicsModule.hpp"
#include "io/NetworkModule.hpp"
#include "world/GameLogicCompModule.hpp"
#include "SpawnSystemModule.hpp"

using namespace dice::hfe;

std::vector<IModule*> dice::hfe::g_modules;

// bf2: 004def00
BF2EngineSetup::BF2EngineSetup(BF2Engine* p_Engine) :
    m_engine(p_Engine),
    m_unknown08(nullptr),
    m_unknown10(nullptr),
    m_unknown18(0)
{

}

// bf2: 004df0d0
BF2EngineSetup::~BF2EngineSetup()
{
    // TODO: Implement
    // io::shutdownSocketManager();
    // if (io::networkManager != nullptr)
    // call some vtb
    // io::networkManager = nullptr;
}

// bf2: 004df490
bool BF2EngineSetup::initModules()
{
    // TODO: Implement
    auto module = new Module();
    g_modules.push_back(module);
    auto moduleBF2 = new ModuleBF2();
    g_modules.push_back(moduleBF2);
    auto moduleGame = new ModuleGame();
    g_modules.push_back(moduleGame);
    auto moduleGameLogic = new ModuleGameLogic();
    g_modules.push_back(moduleGameLogic);
    auto mathModule = new MathModule();
    g_modules.push_back(mathModule);
    auto moduleIO = new io::ModuleIO();
    g_modules.push_back(moduleIO);
    auto fileModule = new io::FileModule();
    g_modules.push_back(fileModule);
    auto worldModule = new world::Module();
    g_modules.push_back(worldModule);
    auto objectModule = new world::ObjectModule();
    g_modules.push_back(objectModule);
    auto objTemplPortalModule = new world::ObjTemplPortalModule();
    g_modules.push_back(objTemplPortalModule);
    auto moduleNetworkables = new ModuleNetworkables();
    g_modules.push_back(moduleNetworkables);
    auto objTemplBaseModule = new world::ObjTemplBaseModule();
    g_modules.push_back(objTemplBaseModule);
    auto moduleToolObject = new tool::ModuleToolObject();
    g_modules.push_back(moduleToolObject);
    auto physicsModule = new world::PhysicsModule();
    g_modules.push_back(physicsModule);
    /*
    auto animModule = new animationTools::AnimModule();
    g_modules.push_back(animModule);
    */
    auto networkModule = new io::NetworkModule();
    g_modules.push_back(networkModule);
    /*
    auto bfSoundModule = new BfSoundModule();
    g_modules.push_back(bfSoundModule);
    auto bfMaterialSystemModule = new world::BFMaterialSystemModule();
    g_modules.push_back(bfMaterialSystemModule);
    auto scoreSystemModule = new world::ScoreSystemModule();
    g_modules.push_back(scoreSystemModule);
    auto gameLogicObjTemplBaseModule = new world::GameLogicObjTemplBaseModule();
    g_modules.push_back(gameLogicObjTemplBaseModule);
    auto gameLogicObjTemplFxModule = new world::GameLogicObjTemplFxModule();
    g_modules.push_back(gameLogicObjTemplFxModule);
    auto gameLogicObjTemplVehicleModule = new world::GameLogicObjTemplVehicleModule();
    g_modules.push_back(gameLogicObjTemplVehicleModule);
    auto gameLogicObjTemplBFModule = new world::GameLogicObjTemplBFModule();
    g_modules.push_back(gameLogicObjTemplBFModule);
    */
    auto gameLogicCompModule = new world::GameLogicCompModule();
    g_modules.push_back(gameLogicCompModule);
    auto spawnSystemModule = new SpawnSystemModule();
    g_modules.push_back(spawnSystemModule);
    for(auto l_module : g_modules)
    {
        g_classManager->registerServer(l_module);
    }
    
    g_classManager->setDefaultClass(IID_IMemoryPool, CID_MemoryPool);
    g_classManager->initSingletons();

    for (auto l_module : g_modules)
    {
        if (!l_module->init())
        {
            l_module->close();
            g_classManager->unregisterServer(l_module);
        }
    }
    /*
    setSpawnManager(CID_SpawnManager); // 0xc487
    world::setMaterialManager(world::CID_MaterialManager); // 0xc4af
    world::setScoreManager(world::CID_ScoreManager); // 0xc4af
    */
    
    return true;
}

// bf2: 004df3f0
bool BF2EngineSetup::initLateModules()
{
    // TODO: Implement
    return true;
}

// bf2: 004def40
bool BF2EngineSetup::initFileSystem()
{
    // TODO: Implement
    return true;
}

// bf2: 004deff0
bool BF2EngineSetup::initRenderer()
{
    // TODO: Implement

    // Validate our engine pointer
    if (m_engine == nullptr)
        return false;
    
    // Get <unknown> class
    auto s_unknown = m_engine->m_unknown30;
    if (s_unknown == nullptr)
        return false;
    
    // if ((plVar1 != (long *)0x0) && (cVar2 = (**(code **)(*plVar1 + 0x10))(), cVar2 != '\0'))
    // TODO: Call some vtable from m_unknown30
    // TODO: if the call returned true, return 1 otherwise return 0

    return false;
}

bool BF2EngineSetup::initConsole()
{
    return true;
}

// bf2: 004df050
bool BF2EngineSetup::initNetwork()
{
    // Implemented

    // Allocate a new network manager
    io::g_networkManager = new io::NetworkManager();

    // Validate network manager
    if (io::g_networkManager != nullptr)
    {
        // Create/set a new socket manager
        auto s_SocketManager = io::setSocketManager();

        // If created successfully, return true
        return s_SocketManager ? true : false;
    }

    return false;
}

// bf2: 004df190
bool BF2EngineSetup::shutdownModules()
{
    // TODO: Implement

    // Shutdown our network communications
    shutdownNetwork();

    // Close the engine logging
    if (m_engine)
        m_engine->closeLog();

    return false;
}

// bf2: 004df090
void BF2EngineSetup::shutdownNetwork()
{
    // TODO: Implement

    // io:: shutdownSocketManager
    if (io::g_networkManager != nullptr)
    {
        // vtable call: (**(code **)(*io::networkManager + 0x10))();
        io::g_networkManager = nullptr;
    }
}