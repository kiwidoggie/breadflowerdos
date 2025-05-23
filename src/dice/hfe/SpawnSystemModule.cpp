#include "SpawnSystemModule.hpp"

using namespace dice::hfe;

/**
 * @brief Adds a reference to this class
 */
void SpawnSystemModule::addRef()
{
	m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current reference count
 */
uint32_t SpawnSystemModule::getRef()
{
	return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t SpawnSystemModule::release()
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
 * @return SpawnSystemModule*
 */
SpawnSystemModule* SpawnSystemModule::queryInterface(uint32_t iid)
{
	if (iid == IID_IBase)
		return this;

	if (iid == IID_IClassServer)
		return this;

	if (iid == IID_IModule)
		return this;

	return nullptr;
}

void SpawnSystemModule::getClassList(std::vector<ClassRegInfo>& regInfos)
{
	// TODO: Implement
	/*
	{
		auto regInfo = ClassRegInfo(CID_SpawnPointTemplate, "dice.bf.SpawnPoint", SpawnPointTemplate::create);
		regInfos.push_back(regInfo);
	}
	{
		auto regInfo = ClassRegInfo(CID_SpawnManager, "dice.bf.SpawnManager", SpawnManager::create);
		regInfos.push_back(regInfo);
	}
	*/
}

void SpawnSystemModule::getSingletonList([[maybe_unused]] std::vector<SingletonRegInfo>& regInfos)
{
}

bool SpawnSystemModule::init()
{
	//g_mainConsoleObjects->registerConsoleObjects(getSpawnManager::SpawnSystemList);
	//world::g_objectTemplateManager->function0x28(CID_SpawnPointTemplate, "SpawnPoint");
	return true;
}

bool SpawnSystemModule::close()
{
	return true;
}
