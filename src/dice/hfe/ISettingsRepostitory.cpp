#include "ISettingsRepostitory.hpp"
#include "SettingsRepostitory.hpp"
#include "ClassManager.hpp"
#include "SingletonRegInfo.hpp"

using namespace dice::hfe;

ISettingsRepostitory* dice::hfe::g_Settings = nullptr;

void ISettingsRepostitory::createSingleton()
{
	g_Settings = new SettingsRepostitory();
	auto regInfo = SingletonRegInfo("SettingsRepostitory", g_Settings);
	g_classManager->registerSingleton(regInfo);
}
