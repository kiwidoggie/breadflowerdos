#include "PhysicsModule.hpp"

using namespace dice::hfe::world;

/**
 * @brief Adds a reference to this class
 */
void PhysicsModule::addRef()
{
	m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current
 * reference count
 */
uint32_t PhysicsModule::getRef()
{
	return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t PhysicsModule::release()
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
 * @return PhysicsModule*
 */
PhysicsModule* PhysicsModule::queryInterface(uint32_t iid)
{
	if (iid == IID_IBase)
		return this;

	if (iid == IID_IClassServer)
		return this;

	if (iid == IID_IModule)
		return this;

	return nullptr;
}

void PhysicsModule::getClassList(std::vector<ClassRegInfo>& regInfos)
{
	// TODO: Implement
	/*
    {
        auto regInfo = ClassRegInfo(CID_BasicPhysicsSystem,
	 * "dice.hfe.world.PhysicsSystem.Basic",
	 * ClassFactory<BasicPhysicsSystem>::create);
 regInfos.push_back(regInfo);

	 * }
    {
        auto regInfo = ClassRegInfo(CID_PhysicsNode,
	 * "dice.hfe.world.PhysicsNode.Basic", ClassFactory<PhysicsNode>::create);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * ClassRegInfo(CID_PhysicsNodeManager,
	 * "dice.hfe.world.PhysicsNodeManager.Basic",
	 * ClassFactory<PhysicsNodeManager>::create);
 regInfos.push_back(regInfo);

	 * }
    {
        auto regInfo = ClassRegInfo(CID_ResponsePhysics,
	 * "dice.hfe.world.ResponsePhysics.Basic",
	 * ClassFactory<ResponsePhysics>::create);
 regInfos.push_back(regInfo);
 }

	 * {
        auto regInfo = ClassRegInfo(CID_ResponsePhysicsManager,
	 * "dice.hfe.world.ResponsePhysicsManager.Basic",
	 * ClassFactory<ResponsePhysicsManager>::create);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * ClassRegInfo(CID_Heightmap, "dice.hfe.world.Heightmap",
	 * Heightmap::create);
        regInfos.push_back(regInfo);
    }
    {

	 * auto regInfo = ClassRegInfo(CID_HeightmapEditable,
	 * "dice.hfe.world.HeightmapEditable", HeightmapEditable::create);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * ClassRegInfo(CID_HeightmapCluster, "dice.hfe.world.HeightmapCluster",
	 * HeightmapCluster::create);
        regInfos.push_back(regInfo);
    }
 {

	 * auto regInfo = ClassRegInfo(CID_HeightmapClusterEditable,
	 * "dice.hfe.world.HeightmapClusterEditable",
	 * HeightmapClusterEditable::create);
        regInfos.push_back(regInfo);

	 * }
    {
        auto regInfo = ClassRegInfo(CID_CollisionManager,
	 * "dice.hfe.world.CollisionManager", CollisionManager::create);

	 * regInfos.push_back(regInfo);
    }
    */
}

void PhysicsModule::getSingletonList(std::vector<SingletonRegInfo>& regInfos)
{
	// TODO: Implement
	/*
    {
        auto regInfo = SINGLETON_REG_INFO("BasicPhysicsSystem",
	 * g_basicPhysicsSystem, IID_IPhysicsSystem, CID_BasicPhysicsSystem, 1);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * SINGLETON_REG_INFO("PhysicsNodeManager", g_physicsNodeManager,
	 * IID_IPhysicsNodeManager, CID_PhysicsNodeManager, 1);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * SINGLETON_REG_INFO("ResponsePhysicsManager", g_responsePhysicsManager,
	 * IID_IResponsePhysicsManager, CID_ResponsePhysicsManager, 1);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * SINGLETON_REG_INFO("HeightmapCluster", g_heightmapCluster,
	 * IID_IHeightmapCluster, CID_HeightmapCluster, 1);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * SINGLETON_REG_INFO("CollisionManager", g_collisionManager,
	 * IID_ICollisionManager, CID_CollisionManager, 1);

	 * regInfos.push_back(regInfo);
    }
    */
}

bool PhysicsModule::init()
{
	// TODO: Implement
	// g_mainConsoleObjects->registerConsoleObjects(collisionManager::myList);
	return true;
}

bool PhysicsModule::close()
{
	// TODO: Implement
	// g_mainConsoleObjects->unregisterConsoleObjects(collisionManager::myList);
	return true;
}
