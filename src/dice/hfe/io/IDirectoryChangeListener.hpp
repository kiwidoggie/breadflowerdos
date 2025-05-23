#pragma once

#include <dice/hfe/IBase.hpp>
#include <string>

namespace dice::hfe::io
{
	const uint32_t IID_IDirectoryChangeListener = 0xB4C1C2FC;

	class IDirectoryChangeListener : public IBase
	{
	public:
		virtual void onDirectoryChange(const std::string&, bool, uint32_t) = 0;
	};
}	 // namespace dice::hfe::io
