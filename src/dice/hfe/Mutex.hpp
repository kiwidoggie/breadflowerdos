#pragma once
#include <mutex>

namespace dice::hfe
{
	class Mutex
	{
	public:
		std::mutex m_Mutex;

	public:
		Mutex();
		~Mutex();
	};
}	 // namespace dice::hfe
