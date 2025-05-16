#include "ObjTemplBaseModule.hpp"

using namespace dice::hfe::world;

/**
 * @brief Adds a reference to this class
 */
void ObjTemplBaseModule::addRef()
{
	m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current
 * reference count
 */
uint32_t ObjTemplBaseModule::getRef()
{
	return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t ObjTemplBaseModule::release()
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
 * @return ObjTemplBaseModule*

 */
ObjTemplBaseModule* ObjTemplBaseModule::queryInterface(uint32_t iid)
{
	if (iid == IID_IBase)
		return this;

	if (iid == IID_IClassServer)
		return this;

	if (iid == IID_IModule)
		return this;

	return nullptr;
}

void ObjTemplBaseModule::getClassList(std::vector<ClassRegInfo>& regInfos)
{
	// TODO: Implement
	/*
    {
        auto regInfo = ClassRegInfo(CID_ObjectTemplateManager,
	 * "dice.hfe.world.ObjectTemplateManager.Standard",
	 * ClassFactory<ObjectTemplateManager>::create);

	 * regInfos.push_back(regInfo);
    }
    */
}

void ObjTemplBaseModule::getSingletonList(
	[[maybe_unused]] std::vector<SingletonRegInfo>& regInfos)
{
}

bool ObjTemplBaseModule::init()
{
	// TODO: Implement
	// g_mainConsoleObjects->registerConsoleObjects(objTemplBaseList);
	return true;
}

bool ObjTemplBaseModule::close()
{
	// TODO: Implement
	// g_mainConsoleObjects->unregisterConsoleObjects(objTemplBaseList);
	return true;
}
