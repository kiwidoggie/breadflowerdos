#include "ClassManager.hpp"

using namespace dice::hfe;

ClassManager* dice::hfe::g_classManager = nullptr;

/**
 * @brief Adds a reference to this class
 */
void ClassManager::addRef()
{
    m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current reference count
 */
uint32_t ClassManager::getRef()
{
    return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t ClassManager::release()
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
 * @return System*
 */
ClassManager* ClassManager::queryInterface(uint32_t p_param)
{
    if (p_param == IID_IBase)
        return this;

    if (p_param == IID_IClassManager)
        return this;

    return nullptr;
}

ClassManager::~ClassManager()
{
    // TODO: Implement
}

void ClassManager::registerServer(IClassServer*)
{
    // TODO: Implement
}

void ClassManager::unregisterServer(IClassServer*)
{
    // TODO: Implement
}

void ClassManager::setDefaultClass(unsigned int, unsigned int)
{
    // TODO: Implement
}

bool ClassManager::getDefaultClass(unsigned int, unsigned int&)
{
    // TODO: Implement
    return false;
}

bool ClassManager::getClassName(unsigned int, std::string&)
{
    // TODO: Implement
    return false;
}

bool ClassManager::getClassID(std::string const&, unsigned int&)
{
    // TODO: Implement
    return false;
}

bool ClassManager::createInstance(unsigned int, IBase*)
{
    // TODO: Implement
    return false;
}

bool ClassManager::createInstance(unsigned int, unsigned int, IBase*)
{
    // TODO: Implement
    return false;
}

bool ClassManager::createInstance(std::string const&, unsigned int, IBase*)
{
    // TODO: Implement
    return false;
}

bool ClassManager::setSingletonClass(std::string const&, unsigned int)
{
    // TODO: Implement
    return false;
}

bool ClassManager::getSingletonClass(std::string const&, unsigned int&)
{
    // TODO: Implement
    return false;
}

void ClassManager::registerSingleton(SingletonRegInfo const&)
{
    // TODO: Implement
}

void ClassManager::unregisterSingleton(std::string const&)
{
    // TODO: Implement
}

void* ClassManager::getSingleton(std::string const&)
{
    // TODO: Implement
    return nullptr;
}

void* ClassManager::getSingletonAs(std::string const&, unsigned int)
{
    // TODO: Implement
    return nullptr;
}

void ClassManager::registerSimpleSingleton(std::string const&, void*)
{
    // TODO: Implement
}

void ClassManager::unregisterSimpleSingleton(std::string const&)
{
    // TODO: Implement
}

void* ClassManager::getSimpleSingleton(std::string const&) const
{
    // TODO: Implement
    return nullptr;
}

void ClassManager::getPrintableSingletonList() const
{
    // TODO: Implement
}

void ClassManager::getAllClassIncludingSubstring(std::string const&, std::vector<std::string>&) const
{
    // TODO: Implement
}

void ClassManager::initSingletons()
{
    // TODO: Implement
}
