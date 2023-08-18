#include "TickCalculator.hpp"

using namespace dice::hfe;

TickCalculator::TickCalculator(int32_t p_param1, float p_param2) :
    m_unknown00(1.0 / p_param2),
    m_unknown08(0),
    m_unknown10(0),
    m_unknown18(0)
{
}