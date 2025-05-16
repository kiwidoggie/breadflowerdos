#pragma once

#include "IBase.hpp"
#include <string>

namespace dice::hfe
{
	const uint32_t IID_IProfilerClient = 0xD6EAD;

	class IProfilerClient : public IBase
	{
	public:
		virtual void startGlobalTimer() = 0;
		virtual void stopGlobalTimer() = 0;
		virtual void startTimer(unsigned int&, const char*, float) = 0;
		virtual void stopTimer(unsigned int) = 0;
		virtual void getTimerIdByName(const char*, unsigned int&) = 0;
		virtual void setEnable(bool) = 0;
		virtual bool getEnable() = 0;
		virtual void pauseVTune() = 0;
		virtual bool getEnablePageFaults() const = 0;
		virtual void setEnablePageFaults(bool) = 0;
		virtual void reportToFile(const std::string&) = 0;
	};
}	 // namespace dice::hfe
