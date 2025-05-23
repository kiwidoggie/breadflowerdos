#include "GameLogicCompModule.hpp"

using namespace dice::hfe::world;

/**
 * @brief Adds a reference to this class
 */
void GameLogicCompModule::addRef()
{
	m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current
 * reference count
 */
uint32_t GameLogicCompModule::getRef()
{
	return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t GameLogicCompModule::release()
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
 * @return GameLogicCompModule*

 */
GameLogicCompModule* GameLogicCompModule::queryInterface(uint32_t iid)
{
	if (iid == IID_IBase)
		return this;

	if (iid == IID_IClassServer)
		return this;

	if (iid == IID_IModule)
		return this;

	return nullptr;
}

void GameLogicCompModule::getClassList(std::vector<ClassRegInfo>& regInfos)
{
	// TODO: Implement
	/*
    {
        auto regInfo = ClassRegInfo(CID_ArmorGLCompTemplate,
	 * "dice.hfe.world.TemplateComponent.Armor",
	 * ClassFactory<ArmorGLCompTemplate>::create);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * ClassRegInfo(CID_AbilityGLCompTemplate,
	 * "dice.hfe.world.TemplateComponent.Ability",
	 * ClassFactory<AbilityGLCompTemplate>::create);

	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 * ClassRegInfo(CID_RadioGLCompTemplate,
	 * "dice.hfe.world.TemplateComponent.Radio",
	 * ClassFactory<RadioGLCompTemplate>::create);

	 * regInfos.push_back(regInfo);
    }
    */
}

void GameLogicCompModule::getSingletonList(
	[[maybe_unused]] std::vector<SingletonRegInfo>& regInfos)
{
}

bool GameLogicCompModule::init()
{
	// TODO: Implement
	// g_mainConsoleObjects->registerConsoleObjects(gameLogicCompTemplList);
	return true;
}

bool GameLogicCompModule::close()
{
	// TODO: Implement
	// g_mainConsoleObjects->unregisterConsoleObjects(gameLogicCompTemplList);
	return true;
}
