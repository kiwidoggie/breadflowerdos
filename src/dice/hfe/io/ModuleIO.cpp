#include "ModuleIO.hpp"
#include "FileChangeManager.hpp"
#include "FileManager.hpp"
#include "OldConsole.hpp"

using namespace dice::hfe::io;

/**
 * @brief Adds a reference to this class
 */
void ModuleIO::addRef()
{
	m_refCount++;
}

/**
 * @brief Gets the current reference count
 * @return uint32_t Current
 *
 *
 * reference count
 */
uint32_t ModuleIO::getRef()
{
	return m_refCount;
}

/**
 * @brief TODO: Documentation
 * @return uint32_t
 */
uint32_t ModuleIO::release()
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
 * @param p_param
 * @return ModuleIO*
 */
ModuleIO* ModuleIO::queryInterface(uint32_t p_param)
{
	if (p_param == IID_IBase)
		return this;

	if (p_param == IID_IClassServer)
		return this;

	if (p_param == IID_IModule)
		return this;

	return nullptr;
}

void ModuleIO::getClassList(std::vector<ClassRegInfo>& regInfos)
{
	// TODO: Implement
	/*
    {
        auto regInfo = ClassRegInfo(CID_ControlMap,
	 *
	 *
	 * "dice.hfe.io.ControlMap.Standard", ControlMap::create);

	 *
	 *
	 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 *
	 *
	 * ClassRegInfo(CID_NullInputDeviceManager,
	 *
	 *
	 * "dice.hfe.io.InputDeviceManager.Null",
	 * NullInputDeviceManager::create);


	 * * regInfos.push_back(regInfo);

	 * }
    {
        auto regInfo =
	 *
	 *
	 * ClassRegInfo(CID_NullResourceManager,
	 *
	 * "dice.hfe.io.ResourceManager.Null",
	 * NullResourceManager::create);


	 * * regInfos.push_back(regInfo);
    }

	 * {
        auto regInfo =

	 * * ClassRegInfo(CID_NullCacheManager,
	 *
	 * "dice.hfe.io.CacheManager.Null",
	 * NullCacheManager::create);

	 *
	 * regInfos.push_back(regInfo);
    }
    {

	 * auto regInfo =
	 *
	 * ClassRegInfo(CID_ControlMapManager,
	 *
	 *
	 * "dice.hfe.io.ControlMapManager.Standard", ControlMapManager::create);



	 * * * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 *

	 * * ClassRegInfo(CID_ExcelLexicon, "dice.hfe.ExcelLexicon",
	 *
	 *
	 * ExcelLexicon::create);
        regInfos.push_back(regInfo);
    }
    */
}

void ModuleIO::getSingletonList(std::vector<SingletonRegInfo>& regInfos)
{
	// TODO: Implement

	{
		auto regInfo = SINGLETON_REG_INFO(
			"FileManager",
			g_fileManager,
			IID_IFileManager,
			CID_FileManager,
			1);
		regInfos.push_back(regInfo);
	}
	{
		auto s_RegInfo = SINGLETON_REG_INFO(
			"FileChangeManager",
			g_fileChangeManager,
			IID_IFileChangeManager,
			CID_FileChangeManager,
			1);
		regInfos.push_back(s_RegInfo);
	} /*
    {
        auto regInfo =
	 *
		 SINGLETON_REG_INFO("ResourceManager",
		 g_resourceManager,
	 *
		 IID_IResourceManager,
		 CID_NullResourceManager, 1);

	 *
		 regInfos.push_back(regInfo);
    }

		 {
        auto regInfo =

		 * SINGLETON_REG_INFO("CacheManager",
		 g_cacheManager,
		 IID_ICacheManager,
	 * CID_NullCacheManager, 1);


		 regInfos.push_back(regInfo);
    }
 {

	 * auto regInfo =

		 SINGLETON_REG_INFO("AsyncMultiStreamer",
	 * g_asyncMultiStreamer,

		 IID_IAsyncMultiStreamer, CID_AsyncMultiStreamer,
	 * 1);


		 regInfos.push_back(regInfo);
    }
    {
        auto regInfo
	 * =

		 SINGLETON_REG_INFO("InputDeviceManager", g_inputDeviceManager,
	 *

		 IID_IInputDeviceManager, CID_NullInputDeviceManager, 1);

	 *

		 regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 *

		 SINGLETON_REG_INFO("InputManager", g_inputManager, IID_IInputManager,


		 * CID_InputManager, 1);
        regInfos.push_back(regInfo);
    }

		 {


		 * auto regInfo = SINGLETON_REG_INFO("ControlMapManager",

		 *
		 g_controlMapManager, IID_IControlMapManager,
		 CID_ControlMapManager,
		 1);

	 * regInfos.push_back(regInfo);

		 }*/
	{
		auto s_RegInfo = SINGLETON_REG_INFO("MainConsole", g_mainConsole);
		regInfos.push_back(s_RegInfo);
	} /*
    {
        auto regInfo =
	 *

		 SINGLETON_REG_INFO("ActiveMethodConsole", g_activeMethodConsole);



		 * regInfos.push_back(regInfo);
    }
    {
        auto regInfo =
	 *

		 SINGLETON_REG_INFO("Lexicon", g_lexicon, IID_ILexicon,

		 CID_ExcelLexicon,
	 * 2);
        regInfos.push_back(regInfo);
    }


	   */
}

bool ModuleIO::init()
{
	// TODO: Implement
	/*
    g_mainConsoleObjects->registerConsoleObjects(fileManager::myList);



	 * * * g_mainConsoleObjects->registerTypeConversion("std::string",
	 *
	 * "string");


	 * g_system->resetExactTime();


	 *
	 * addConstantToAllConsoles("c_Debug",
	 * "0");

	 *
	 * addConstantToAllConsoles("c_Release", "1");


	 *
	 *
	 * addConstantToAllConsoles("c_Xbox", "0");

	 *
	 *
	 * addConstantToAllConsoles("c_Win32", "1");


	 *
	 *
	 * addConstantToAllConsoles("c_DTDebug", "0");

	 *
	 *
	 * addConstantToAllConsoles("c_DTInfo", "1");

	 *
	 *
	 * addConstantToAllConsoles("c_DTWarning", "2");

	 *
	 *
	 * addConstantToAllConsoles("c_DTAssert", "3");

	 *
	 *
	 * addConstantToAllConsoles("c_DTError", "4");


	 *
	 *
	 * addConstantFloatHelper("c_CMMinFallTime", 0.001f);

	 *
	 *
	 * addConstantFloatHelper("c_CMNonRepetive", 10000.f);

	 *
	 *
	 * addConstantFloatHelper("c_CMPushAndHold", 0.f);

	 *
	 *
	 * addConstantFloatHelper("c_CMDoubleTap", 1000.f);


	 *
	 *
	 * addConstantHelper("c_noAccess", 0);

	 *
	 * addConstantHelper("c_endUserAccess",
	 * 1);

	 *
	 * addConstantHelper("c_fullAccess", 2);

	 *
	 *
	 * addConstantHelper("c_totalAccess", 7);

 addConstantHelper("c_GIMenu",


	 * * * 0);
    addConstantHelper("c_GIToggleConsole", 1);

	 *
	 *
	 * addConstantHelper("c_GIEscape", 2);
    addConstantHelper("c_GIUp",
	 * 3);


	 * * addConstantHelper("c_GIDown", 4);

	 * addConstantHelper("c_GILeft",
	 * 5);

	 *
	 * addConstantHelper("c_GIRight", 6);

	 * addConstantHelper("c_GIDelete",

	 * * 30);
 addConstantHelper("c_GIBack",
	 * 31);

	 *
	 * addConstantHelper("c_GIPageUp", 7);

	 *
	 * addConstantHelper("c_GIPageDown",
	 * 8);

	 *
	 * addConstantHelper("c_GIRightShift", 9);

	 *
	 *
	 * addConstantHelper("c_GILeftShift", 10);

	 *
	 *
	 * addConstantHelper("c_GILeftCtrl", 11);

	 *
	 *
	 * addConstantHelper("c_GIRightCtrl", 12);

	 *
	 * addConstantHelper("c_GILeftAlt",
	 * 13);

	 *
	 * addConstantHelper("c_GIRightAlt", 14);

	 * addConstantHelper("c_GIOk",

	 * * 15);
    addConstantHelper("c_GIAltOk", 16);

	 *
	 *
	 * addConstantHelper("c_GITab", 28);
    addConstantHelper("c_GIEnter",


	 * * * 29);
    addConstantHelper("c_GICancel", 17);

	 *
	 *
	 * addConstantHelper("c_GIMenuSelect0", 37);

	 *
	 *
	 * addConstantHelper("c_GIMenuSelect1", 38);

	 *
	 *
	 * addConstantHelper("c_GIMenuSelect2", 39);

	 *
	 *
	 * addConstantHelper("c_GIMenuSelect3", 40);

	 *
	 *
	 * addConstantHelper("c_GIMenuSelect4", 41);

	 *
	 *
	 * addConstantHelper("c_GIMenuSelect5", 42);

	 *
	 *
	 * addConstantHelper("c_GIMenuSelect6", 43);

	 *
	 *
	 * addConstantHelper("c_GIMenuSelect7", 44);

	 *
	 *
	 * addConstantHelper("c_GIMenuSelect8", 45);

	 *
	 *
	 * addConstantHelper("c_GIMenuSelect9", 46);

	 * addConstantHelper("c_GIQuit",

	 * * 27);

	 * addConstantHelper("c_GIMouseLookX", 20);

	 *
	 *
	 * addConstantHelper("c_GIMouseLookY", 21);

	 *
	 *
	 * addConstantHelper("c_GIMouseWheelDown", 26);

	 *
	 *
	 * addConstantHelper("c_GIMouseWheelUp", 25);

	 *
	 *
	 * addConstantHelper("c_GISayAll", 22);
 addConstantHelper("c_GISayTeam",


	 * * * 23);
    addConstantHelper("c_GISaySquad", 24);

	 *
	 *
	 * addConstantHelper("c_GIVoipPushToTalk", 61);

	 *
	 *
	 * addConstantHelper("c_GIVoipUseLeaderChannel", 56);

	 *
	 *
	 * addConstantHelper("c_GIScreenShot", 18);

	 *
	 *
	 * addConstantHelper("c_GITogglePause", 19);

	 *
	 *
	 * addConstantHelper("c_GITacticalComm", 33);

	 *
	 *
	 * addConstantHelper("c_GIRadioComm", 34);

	 *
	 * addConstantHelper("c_GIMapZoom",
	 * 36);

	 *
	 * addConstantHelper("c_GIMapSize", 35);

	 *
	 *
	 * addConstantHelper("c_GI3dMap", 57);
    addConstantHelper("c_GIYes",


	 * * * 47);
    addConstantHelper("c_GINo", 48);

	 *
	 *
	 * addConstantHelper("c_GIAutoAccept", 49);

	 *
	 *
	 * addConstantHelper("c_GICreateSquad", 50);

	 *
	 *
	 * addConstantHelper("c_GIJoinSquad", 51);

	 *
	 *
	 * addConstantHelper("c_GISelectSquad", 52);

	 *
	 *
	 * addConstantHelper("c_GIHotRankUp", 54);

	 *
	 *
	 * addConstantHelper("c_GIShowScoreboard", 55);

	 *
	 *
	 * addConstantHelper("c_GIDeselectAll", 59);

	 *
	 *
	 * addConstantHelper("c_GISelectAll", 58);

	 * addConstantHelper("c_GILeader",

	 * * 60);

	 * addConstantHelper("c_GIToggleFreeCamera", 53);

	 *
	 *
	 * addConstantHelper("c_GINone", 74);


	 *
	 *
	 * addConstantFloatHelper("c_NIGhostAlways", -1.f);


	 *
	 *
	 * addConstantHelper("c_PIShowScoreBoard", 63);

	 *
	 *
	 * addConstantHelper("c_PILie", 37);
    addConstantHelper("c_PICrouch",


	 * * * 38);
    addConstantHelper("c_PIYaw", 0);

	 *
	 * addConstantHelper("c_PIPitch",
	 * 1);
 addConstantHelper("c_PIRoll",

	 * * 2);

	 * addConstantHelper("c_PIThrottle", 3);

	 *
	 *
	 * addConstantHelper("c_PIMouseLookX", 4);

	 *
	 *
	 * addConstantHelper("c_PIMouseLookY", 5);

	 *
	 * addConstantHelper("c_PICameraX",
	 * 6);

	 *
	 * addConstantHelper("c_PICameraY", 7);

	 *
	 *
	 * addConstantHelper("c_PINumInput", 64);
 addConstantHelper("c_PIFire",


	 * * * 8);
    addConstantHelper("c_PIAltFire", 31);

	 *
	 *
	 * addConstantHelper("c_PIFlareFire", 47);

	 * addConstantHelper("c_PIReload",

	 * * 32);

	 * addConstantHelper("c_PISelectFunc", 33);

	 *
	 *
	 * addConstantHelper("c_PIAction", 9);
    addConstantHelper("c_PIUse",


	 * * * 10);
    addConstantHelper("c_PIMouseLook", 11);

	 *
	 *
	 * addConstantHelper("c_PIDrop", 34);
 addConstantHelper("c_PINextItem",


	 * * * 60);
    addConstantHelper("c_PIPrevItem", 61);

	 *
	 *
	 * addConstantHelper("c_PICommunication", 62);

	 *
	 *
	 * addConstantHelper("c_PIAltSprint", 12);

	 * addConstantHelper("c_PISprint",

	 * * 13);

	 * addConstantHelper("c_PIToggleCameraMode", 35);

	 *
	 *
	 * addConstantHelper("c_PICameraMode1", 39);

	 *
	 *
	 * addConstantHelper("c_PICameraMode2", 40);

	 *
	 *
	 * addConstantHelper("c_PICameraMode3", 41);

	 *
	 *
	 * addConstantHelper("c_PICameraMode4", 42);

	 *
	 *
	 * addConstantHelper("c_PIToggleCamera", 36);

	 *
	 * addConstantHelper("c_PINone",
	 * 64);

	 *
	 * addConstantHelper("c_PIWeaponSelect1", 14);

	 *
	 *
	 * addConstantHelper("c_PIWeaponSelect2", 15);

	 *
	 *
	 * addConstantHelper("c_PIWeaponSelect3", 16);

	 *
	 *
	 * addConstantHelper("c_PIWeaponSelect4", 17);

	 *
	 *
	 * addConstantHelper("c_PIWeaponSelect5", 18);

	 *
	 *
	 * addConstantHelper("c_PIWeaponSelect6", 19);

	 *
	 *
	 * addConstantHelper("c_PIWeaponSelect7", 20);

	 *
	 *
	 * addConstantHelper("c_PIWeaponSelect8", 21);

	 *
	 *
	 * addConstantHelper("c_PIWeaponSelect9", 22);

	 *
	 *
	 * addConstantHelper("c_PIPositionSelect1", 23);

	 *
	 *
	 * addConstantHelper("c_PIPositionSelect2", 24);

	 *
	 *
	 * addConstantHelper("c_PIPositionSelect3", 25);

	 *
	 *
	 * addConstantHelper("c_PIPositionSelect4", 26);

	 *
	 *
	 * addConstantHelper("c_PIPositionSelect5", 27);

	 *
	 *
	 * addConstantHelper("c_PIPositionSelect6", 28);

	 *
	 *
	 * addConstantHelper("c_PIPositionSelect7", 29);

	 *
	 *
	 * addConstantHelper("c_PIPositionSelect8", 30);

	 *
	 *
	 * addConstantHelper("c_PIRadio1", 48);
 addConstantHelper("c_PIRadio2",


	 * * * 49);
    addConstantHelper("c_PIRadio3", 50);

	 *
	 *
	 * addConstantHelper("c_PIRadio4", 51);
 addConstantHelper("c_PIRadio5",


	 * * * 52);
    addConstantHelper("c_PIRadio6", 53);

	 *
	 *
	 * addConstantHelper("c_PIRadio7", 54);
 addConstantHelper("c_PIRadio8",


	 * * * 55);
    addConstantHelper("c_PIScreenShot", 56);

	 *
	 *
	 * addConstantHelper("c_PIToolTip", 57);
 addConstantHelper("c_PISayAll",


	 * * * 58);
    addConstantHelper("c_PISayTeam", 59);

	 *
	 *
	 * addConstantHelper("c_PISelectPrimWeapon", 43);

	 *
	 *
	 * addConstantHelper("c_PISelectSecWeapon", 44);

	 *
	 *
	 * addConstantHelper("c_PIToggleWeapon", 45);

	 *
	 *
	 * addConstantHelper("c_PIToggleFireRate", 46);
    */
	return true;
}

bool ModuleIO::close()
{
	// TODO: Implement
	// g_mainConsoleObjects->unregisterConsoleObjects(fileManager::myList);
	return true;
}
