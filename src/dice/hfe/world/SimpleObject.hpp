#pragma once

#include <dice/hfe/world/Object.hpp>

namespace dice
{
    namespace hfe
	{
        namespace world
		{
			class SimpleObject : public Object {
			public:
				char _0x218[0x20];
			};

			static_assert(sizeof(SimpleObject) == 0x238);
		}
	}
}

