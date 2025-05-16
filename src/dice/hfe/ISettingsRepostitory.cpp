#include "ISettingsRepostitory.hpp"
#include "ClassManager.hpp"
#include "SettingsRepostitory.hpp"
#include "SingletonRegInfo.hpp"

using namespace dice::hfe;

ISettingsRepostitory* dice::hfe::g_settings = nullptr;

void ISettingsRepostitory::createSingleton()
{
	g_settings = new SettingsRepostitory();
	SingletonRegInfo regInfo =
		SINGLETON_REG_INFO("SettingsRepostitory", g_settings);
	g_classManager->registerSingleton(regInfo);
}
