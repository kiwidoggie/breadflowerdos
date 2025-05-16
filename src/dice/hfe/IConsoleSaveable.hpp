#pragma once

#include <dice/hfe/IBase.hpp>
#include <dice/hfe/io/IStream.hpp>

namespace dice::hfe
{
	class IConsoleSaveable : IBase
	{
	public:
		virtual void makeScript(io::IStream*) = 0;
	};
}	 // namespace dice::hfe
