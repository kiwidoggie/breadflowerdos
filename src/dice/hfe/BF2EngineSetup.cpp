#include "BF2EngineSetup.hpp"

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