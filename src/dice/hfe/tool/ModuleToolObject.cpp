#include "ModuleToolObject.hpp"

using namespace dice::hfe::tool;

/**
 * @brief Adds a reference to this class
 */
void ModuleToolObject::addRef()
{
	m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current
 * reference count
 */
uint32_t ModuleToolObject::getRef()
{
	return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t ModuleToolObject::release()
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
 * @return ModuleToolObject*
 */
ModuleToolObject* ModuleToolObject::queryInterface(uint32_t iid)
{
	if (iid == IID_IBase)
		return this;

	if (iid == IID_IClassServer)
		return this;

	if (iid == IID_IModule)
		return this;

	return nullptr;
}

void ModuleToolObject::getClassList(
	[[maybe_unused]] std::vector<ClassRegInfo>& regInfos)
{
}

void ModuleToolObject::getSingletonList(
	[[maybe_unused]] std::vector<SingletonRegInfo>& regInfos)
{
}

bool ModuleToolObject::init()
{
	// TODO: Implement
	// g_mainConsoleObjects->registerConsoleObjects(myList);
	return true;
}

bool ModuleToolObject::close()
{
	// TODO: Implement
	// g_mainConsoleObjects->unregisterConsoleObjects(myList);
	return true;
}
