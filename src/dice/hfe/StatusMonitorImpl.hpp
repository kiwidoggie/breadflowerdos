#pragma once
#include <cstdint>
#include <string>

namespace dice::hfe
{
	class StatusMonitorImpl
	{
	public:
		virtual ~StatusMonitorImpl() = 0;
		virtual void shouldUpdate(bool) = 0;
		virtual void clearScreen() = 0;
		virtual void getDimensions(int32_t*, int32_t*) = 0;
		virtual void outputString(int32_t, int32_t, std::string&) = 0;
		virtual void flushToScreen() = 0;
	};
}	 // namespace dice::hfe
