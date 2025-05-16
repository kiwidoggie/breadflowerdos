#include "BF2Log.hpp"
#include "Debug.hpp"

using namespace dice::hfe;

BF2Log::~BF2Log()
{
}

bool BF2Log::initDebugCallback()
{
	// TODO: Implement
	/*
	setDebugCallback(DebugType::DTDebug, debugCallback, this);
	setDebugCallback(DebugType::DTWarning, debugCallback, this);
	setDebugCallback(DebugType::DTAssert, debugCallback, this);
	setDebugCallback(DebugType::DxAssert, debugCallback, this);
	setDebugCallback(DebugType::DTInfo, debugCallback, this);
	setDebugCallback(DebugType::DTError, debugCallback, this);
	setDebugCallback(DebugType::Log, debugCallback, this);
	*/
	return true;
}

bool BF2Log::initLogFiles()
{
	return true;
}
