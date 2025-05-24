#include "ModuleNetworkables.hpp"

using namespace dice::hfe;

/**
 * @brief Adds a reference to this class
 */
void ModuleNetworkables::addRef()
{
	m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current
 * reference count
 */
uint32_t ModuleNetworkables::getRef()
{
	return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t ModuleNetworkables::release()
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
 * @return ModuleNetworkables*

 */
ModuleNetworkables* ModuleNetworkables::queryInterface(uint32_t iid)
{
	if (iid == IID_IBase)
		return this;

	if (iid == IID_IClassServer)
		return this;

	if (iid == IID_IModule)
		return this;

	return nullptr;
}

void ModuleNetworkables::getClassList(std::vector<ClassRegInfo>& regInfos)
{
	// TODO: Implement
	/*
	{
		auto regInfo = ClassRegInfo(CID_SimpleObjectNetworkable,
	 * "dice.bf2.Networkable.SimpleObject", SimpleObjectNetworkable::create);

	 * regInfos.push_back(regInfo);
	}
	{
		auto regInfo =
	 * ClassRegInfo(CID_RotationalBundleNetworkable,
	 * "dice.bf2.Networkable.RotationalBundle",
	 * RotationalBundleNetworkable::create);
 regInfos.push_back(regInfo);
 }

	 * {
		auto regInfo = ClassRegInfo(CID_FreeCameraNetworkable,
	 * "dice.bf2.Networkable.FreeCamera", FreeCameraNetworkable::create);

	 * regInfos.push_back(regInfo);
	}
	{
		auto regInfo =
	 * ClassRegInfo(CID_OverheadCameraNetworkable,
	 * "dice.bf2.Networkable.OverheadCamera",
	 * OverheadCameraNetworkable::create);
		regInfos.push_back(regInfo);

	 * }
	{
		auto regInfo = ClassRegInfo(CID_SpringNetworkable,
	 * "dice.bf2.Networkable.Spring", SpringNetworkable::create);

	 * regInfos.push_back(regInfo);
	}
	{
		auto regInfo =
	 * ClassRegInfo(CID_ItemNetworkable, "dice.bf2.Networkable.Item",
	 * ItemNetworkable::create);
		regInfos.push_back(regInfo);
	}
 {

	 * auto regInfo = ClassRegInfo(CID_DestroyableObjectNetworkable,
	 * "dice.bf2.Networkable.DestroyableObject",
	 * DestroyableObjectNetworkable::create);
 regInfos.push_back(regInfo);
 }

	 * {
		auto regInfo =
	 * ClassRegInfo(CID_DestroyableWindowsBundleNetworkable ,
	 * "dice.bf2.Networkable.DestroyableWindowsBundle",
	 * DestroyableWindowsBundleNetworkable::create);

	 * regInfos.push_back(regInfo);
	}
	{
		auto regInfo =
	 * ClassRegInfo(CID_SoldierNetworkable , "dice.bf2.Networkable.Soldier",
	 * SoldierNetworkable::create);
		regInfos.push_back(regInfo);
	}

	 * {
		auto regInfo = ClassRegInfo(CID_PlayerControlObjectNetworkable
	 * , "dice..bf2.Networkable.PlayerControlObject",
	 * PlayerControlObjectNetworkable::create);
 regInfos.push_back(regInfo);

	 * }
	{
		auto regInfo = ClassRegInfo(CID_KitNetworkable ,
	 * "dice.bf2.Networkable.Kit", KitNetworkable::create);

	 * regInfos.push_back(regInfo);
	}
	{
		auto regInfo =
	 * ClassRegInfo(CID_GenericProjectileNetworkable ,
	 * "dice.bf2.Networkable.GenericProjectile",
	 * GenericProjectileNetworkable::create);
 regInfos.push_back(regInfo);
 }

	 * {
		auto regInfo = ClassRegInfo(CID_ControlPointNetworkable ,
	 * "dice.bf2.Networkable.ControlPoint", ControlPointNetworkable::create);

	 * regInfos.push_back(regInfo);
	}
	{
		auto regInfo =
	 * ClassRegInfo(CID_EngineNetworkable , "dice.bf2.Networkable.Engine",
	 * EngineNetworkable::create);
		regInfos.push_back(regInfo);
	}

	 * {
		auto regInfo = ClassRegInfo(CID_TargetObjectNetworkable ,
	 * "dice.bf2.Networkable.TargetObject", TargetObjectNetworkable::create);

	 * regInfos.push_back(regInfo);
	}
	{
		auto regInfo =
	 * ClassRegInfo(CID_TriggerableTargetNetworkable ,
	 * "dice.bf2.Networkable.TriggerableTarget",
	 * TriggerableTargetNetworkable::create);
 regInfos.push_back(regInfo);
 }

	 */
}

void ModuleNetworkables::getSingletonList(
	[[maybe_unused]] std::vector<SingletonRegInfo>& regInfos)
{
}

bool ModuleNetworkables::init()
{
	return true;
}

bool ModuleNetworkables::close()
{
	return true;
}
