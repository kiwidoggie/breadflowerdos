#pragma once
#include <string>

namespace dice
{
    namespace hfe
    {
        class BF2Engine;

        // BF2 size: 0x8 (validated from bf2: 0040b724)
        class BF2
        {
        private:
            BF2Engine* m_bf2Engine;
        public:
            bool init(std::string& p_commandArgs);
            bool run();
        };
    }
}