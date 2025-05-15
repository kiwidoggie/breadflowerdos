#pragma once

#include <dice/hfe/IClassServer.hpp>

namespace dice
{
    namespace hfe
    {
        const uint32_t IID_IModule = 0x9C40;

        class IModule : public IClassServer
        {
        public:
            virtual bool init() = 0;
            virtual bool close() = 0;
        };
    }
}
