#include "MathModule.hpp"

using namespace dice::hfe;

/**
 * @brief Adds a reference to this class
 */
void MathModule::addRef()
{
    m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current reference count
 */
uint32_t MathModule::getRef()
{
    return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t MathModule::release()
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
 * @return MathModule*
 */
MathModule* MathModule::queryInterface(uint32_t p_param)
{
    if (p_param == IID_IBase)
        return this;

    if (p_param == IID_IClassServer)
        return this;

    if (p_param == IID_IModule)
        return this;

    return nullptr;
}

void MathModule::getClassList([[maybe_unused]] std::vector<ClassRegInfo>& regInfos)
{
}

void MathModule::getSingletonList([[maybe_unused]] std::vector<SingletonRegInfo>& regInfos)
{
}

bool MathModule::init()
{
    // TODO: Implement
    // initMath();
    // console::manager->registerNameForType("Vec2", "vec2");
    // console::manager->registerNameForType("Vec2&", "vec2");
    // console::manager->registerNameForType("const Vec2&", "vec2");
    // console::manager->registerNameForType("Vec3", "vec3");
    // console::manager->registerNameForType("Vec3&", "vec3");
    // console::manager->registerNameForType("const Vec3&", "vec3");
    // console::manager->registerNameForType("Vec4", "vec4");
    // console::manager->registerNameForType("Vec4&", "vec4");
    // console::manager->registerNameForType("const Vec4&", "vec4");
    return true;
}

bool MathModule::close()
{
    // TODO: Implement
    // closeMath();
    return true;
}
