#pragma once

#include <vector>
#include <dice/hfe/IBase.hpp>

namespace dice
{
    namespace hfe
    {
        class ClassRegInfo;
        class SingletonRegInfo;
        const uint32_t IID_IClassServer = 0x9C43;

        class IClassServer : public IBase
        {
        public:
            virtual void getClassList(std::vector<ClassRegInfo>&) = 0;
            virtual void getSingletonList(std::vector<SingletonRegInfo>&) = 0;
        };
    }
}
