#include "ObjTemplPortalModule.hpp"

using namespace dice::hfe::world;

/**
 * @brief Adds a reference to this class
 */
void ObjTemplPortalModule::addRef()
{
	m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current
 * reference count
 */
uint32_t ObjTemplPortalModule::getRef()
{
	return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t ObjTemplPortalModule::release()
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
 * @return
 * ObjTemplPortalModule*
 */
ObjTemplPortalModule* ObjTemplPortalModule::queryInterface(uint32_t iid)
{
	if (iid == IID_IBase)
		return this;

	if (iid == IID_IClassServer)
		return this;

	if (iid == IID_IModule)
		return this;

	return nullptr;
}

void ObjTemplPortalModule::getClassList(std::vector<ClassRegInfo>& regInfos)
{
	// TODO: Implement
	/*
    {
        auto regInfo = ClassRegInfo(CID_PortalManager (0x10ec7a00),
	 * "dice.hfe.world.PortalManager.Standard",
	 * ClassFactory<PortalManager>::create);
 regInfos.push_back(regInfo);
 }

	 */
}

void ObjTemplPortalModule::getSingletonList(
	std::vector<SingletonRegInfo>& regInfos)
{
	// TODO: Implement
	/*
    {
        auto regInfo = SINGLETON_REG_INFO("PortalManager",
	 * g_portalManager, IID_IPortalManager (0xe140c2fb), CID_PortalManager
	 * (0x10ec7a00), 1);
        regInfos.push_back(regInfo);
    }
    */
}

bool ObjTemplPortalModule::init()
{
	// TODO: Implement
	// g_mainConsoleObjects->registerConsoleObjects(portalManager::objTemplPortalList);
	return true;
}

bool ObjTemplPortalModule::close()
{
	// TODO: Implement
	// g_mainConsoleObjects->unregisterConsoleObjects(portalManager::objTemplPortalList);
	return true;
}
