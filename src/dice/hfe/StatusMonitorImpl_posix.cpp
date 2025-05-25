#include "StatusMonitorImpl_posix.hpp"

using namespace dice::hfe;

StatusMonitorImpl_posix::StatusMonitorImpl_posix() :
	m_unknown08{ 0 },
	m_unknown0C{ 0 },
	m_unknown10(-1000.0),
	m_scrWindow(nullptr)
{

}
