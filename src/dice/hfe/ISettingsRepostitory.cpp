#include "ISettingsRepostitory.hpp"
#include "SettingsRepostitory.hpp"
#include "ClassManager.hpp"
#include "SingletonRegInfo.hpp"

using namespace dice::hfe;

ISettingsRepostitory* dice::hfe::g_Settings = nullptr;

void ISettingsRepostitory::createSingleton()
{
	g_settings = new SettingsRepostitory();
	auto regInfo = SingletonRegInfo("SettingsRepostitory", (IBase**)&g_settings);
	g_classManager->registerSingleton(regInfo);
}
