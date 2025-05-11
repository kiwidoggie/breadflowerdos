#include "BF2EngineSetup.hpp"
#include "BF2Engine.hpp"
#include "io/io.hpp"
#include "io/NetworkManager.hpp"

using namespace dice::hfe;

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
    return false;
}

// bf2: 004df3f0
bool BF2EngineSetup::initLateModules()
{
    // TODO: Implement
    return false;
}

// bf2: 004def40
bool BF2EngineSetup::initFileSystem()
{
    // TODO: Implement
    return false;
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

// bf2: 004df050
bool BF2EngineSetup::initNetwork()
{
    // Implemented

    // Allocate a new network manager
    io::g_NetworkManager = new io::NetworkManager();

    // Validate network manager
    if (io::g_NetworkManager != nullptr)
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
    if (io::g_NetworkManager != nullptr)
    {
        // vtable call: (**(code **)(*io::networkManager + 0x10))();
        io::g_NetworkManager = nullptr;
    }
}