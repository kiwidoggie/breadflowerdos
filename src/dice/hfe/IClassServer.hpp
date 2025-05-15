#pragma once

#include <vector>
#include <dice/hfe/IBase.hpp>
#include <dice/hfe/ClassRegInfo.hpp>
#include <dice/hfe/SingletonRegInfo.hpp>

namespace dice
{
    namespace hfe
    {
        const uint32_t IID_IClassServer = 0x9C43;

        class IClassServer : public IBase
        {
        public:
            virtual void getClassList(std::vector<ClassRegInfo>&) = 0;
            virtual void getSingletonList(std::vector<SingletonRegInfo>&) = 0;
        };
    }
}
