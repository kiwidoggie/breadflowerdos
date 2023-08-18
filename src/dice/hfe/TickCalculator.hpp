#pragma once
#include <cstdint>

namespace dice
{
    namespace hfe
    {
        class TickCalculator
        {
        private:
            float m_unknown00;
            int32_t m_unknown04;
            uint64_t m_unknown08;
            uint64_t m_unknown10;
            uint64_t m_unknown18;
        public:
            TickCalculator(int32_t p_param1, float p_param2);

            int32_t compute(double p_param1);
        };
    }
}