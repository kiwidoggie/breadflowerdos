#pragma once
#include <dice/hfe/io/INetworkable.hpp>

namespace dice
{
    namespace hfe
    {
        namespace io
        {
            class NetworkableBase : public INetworkable {
            public:
                char m_Unknown50[0x20];
            };
        }
    }
}
