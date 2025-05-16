#include "ObjectModule.hpp"

using namespace dice::hfe::world;

/**
 * @brief Adds a reference to this class
 */
void ObjectModule::addRef()
{
	m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current
 * reference count
 */
uint32_t ObjectModule::getRef()
{
	return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t ObjectModule::release()
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
 * @return ObjectModule*
 */
ObjectModule* ObjectModule::queryInterface(uint32_t iid)
{
	if (iid == IID_IBase)
		return this;

	if (iid == IID_IClassServer)
		return this;

	if (iid == IID_IModule)
		return this;

	return nullptr;
}

void ObjectModule::getClassList(std::vector<ClassRegInfo>& regInfos)
{
	// TODO: Implement
	/*
    {
        auto regInfo = ClassRegInfo(CID_ObjectManager,
	 * "dice.hfe.world.ObjectManager.Standard", ObjectManager::create);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * ClassRegInfo(CID_WindManager, "dice.hfe.world.WindManager.Standard",
	 * WindManager::create);
        regInfos.push_back(regInfo);
    }
    {

	 * auto regInfo = ClassRegInfo(CID_Object, "dice.hfe.world.Object.Standard",
	 * Object::create);
        regInfos.push_back(regInfo);
    }
    {
 auto
	 * regInfo = ClassRegInfo(CID_ObjectPriorityCalculator,
	 * "dice.hfe.world.ObjectPriorityCalculator.Standard",
	 * ObjectPriorityCalculator::create);
        regInfos.push_back(regInfo);

	 * }
    {
        auto regInfo = ClassRegInfo(CID_QuadTreeCuller,
	 * "dice.hfe.world.Culler.QuadTreeCuller", QuadTreeCuller::create);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * ClassRegInfo(CID_BinTreeCuller, "dice.hfe.world.Culler.BinTreeCuller",
	 * BinTreeCuller::create);
        regInfos.push_back(regInfo);
    }
    */
}

void ObjectModule::getSingletonList(
	[[maybe_unused]] std::vector<SingletonRegInfo>& regInfos)
{
}

bool ObjectModule::init()
{
	// TODO: Implement
	// g_mainConsoleObjects->registerConsoleObjects(Object::ObjectManager::objectList);
	return true;
}

bool ObjectModule::close()
{
	// TODO: Implement
	// g_mainConsoleObjects->unregisterConsoleObjects(Object::ObjectManager::objectList);
	return true;
}
