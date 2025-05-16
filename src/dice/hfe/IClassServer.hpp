#pragma once

#include <dice/hfe/ClassRegInfo.hpp>
#include <dice/hfe/IBase.hpp>
#include <dice/hfe/SingletonRegInfo.hpp>
#include <vector>

namespace dice::hfe
{
	const uint32_t IID_IClassServer = 0x9C43;

	class IClassServer : public IBase
	{
	public:
		virtual void getClassList(std::vector<ClassRegInfo>&) = 0;
		virtual void getSingletonList(std::vector<SingletonRegInfo>&) = 0;
	};
}	 // namespace dice::hfe
