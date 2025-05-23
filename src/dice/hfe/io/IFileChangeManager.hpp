#pragma once

#include <dice/hfe/IBase.hpp>
#include <string>

namespace dice::hfe::io
{
	class IFileChangeListener;

	const uint32_t IID_IFileChangeManager = 0xB1EEC3FC;

	class IFileChangeManager : public IBase
	{
	public:
		virtual const std::string&
		addListener(IFileChangeListener*, const std::string&, uint32_t) = 0;
		virtual bool
		removeListener(IFileChangeListener*, const std::string&) = 0;
		virtual bool removeListener(dice::hfe::io::IFileChangeListener*) = 0;
		virtual void setEnable(bool) = 0;
		virtual bool getEnable() = 0;
		virtual void setDelayTime(float) = 0;
		virtual float getDelayTime() = 0;
		virtual void update() = 0;
		virtual ~IFileChangeManager() = default;
		virtual void onDirectoryChange(const std::string&, bool, uint32_t) = 0;
		virtual bool allowFileChange(const std::string&) = 0;
	};
}	 // namespace dice::hfe::io
