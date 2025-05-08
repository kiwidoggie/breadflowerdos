#pragma once

#include <dice/hfe/IBase.hpp>
#include <dice/hfe/io/IStream.hpp>

namespace dice
{
	namespace hfe
	{
		class IConsoleSaveable : IBase {
		public:
			virtual void makeScript(io::IStream*) = 0;
		};
	}
}
