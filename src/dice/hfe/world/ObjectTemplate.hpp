#pragma once

#include <dice/hfe/world/IObjectTemplate.hpp>
#include <dice/hfe/IConsoleSaveable.hpp>

namespace dice
{
    namespace hfe
	{
        namespace world
		{
			class ObjectTemplate : public IObjectTemplate, public IConsoleSaveable {
			public:
				virtual void setGameLogicComponents(IObject*);
				virtual void removeGameLogicComponents(IObject*);
				virtual void setHudComponents(IObject*);
				virtual void removeHudComponents(IObject*);

				std::string m_name; //  0x000C | 0x0018
				char _0x20[0x48];
			};

			static_assert(sizeof(ObjectTemplate) == 0x68);
		}
	}
}
