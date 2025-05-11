#include "Module.hpp"

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

void Module::getClassList(std::vector<ClassRegInfo>&)
{
    // TODO: Implement
}

void Module::getSingletonList(std::vector<SingletonRegInfo>&)
{
    // TODO: Implement
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
