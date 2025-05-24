#pragma once

#include <cstdint>
#include <string>

namespace dice::hfe
{
	class IBase;

	// bf2: 00a56cdd
	class ClassRegInfo
	{
	public:
		uint32_t id;
		std::string name;
		using CreateFunc = IBase* (*)(uint32_t, IBase*);
		CreateFunc func;

		ClassRegInfo(
			uint32_t p_ID, std::string p_ClassName, CreateFunc p_Function) :
			id(p_ID),
			name(p_ClassName),
			func(p_Function)
		{
		}
	};
}	 // namespace dice::hfe
