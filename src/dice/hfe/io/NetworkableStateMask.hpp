#pragma once

#include <cstddef>

namespace dice::hfe::io
{
	struct NetworkableStateMask
	{

		static constexpr size_t N = 12;

		unsigned int m_masks[N];	// for each PCO root & child object
									// that has networkable

		NetworkableStateMask() :
			m_masks{}
		{
		}

		unsigned int& operator[](int index)
		{
			return m_masks[index];
		}

		void set(const NetworkableStateMask& rhs)
		{
			for (size_t i = 0; i < N; i++)
			{
				m_masks[i] |= rhs.m_masks[i];
			}
		}

		void unset(const NetworkableStateMask& rhs)
		{
			for (size_t i = 0; i < N; i++)
			{
				m_masks[i] &= ~rhs.m_masks[i];
			}
		}

		void reset()
		{
			for (size_t i = 0; i < N; i++)
			{
				m_masks[i] = 0xFFFFFFFF;
			}
		}

		void zero()
		{
			for (size_t i = 0; i < N; i++)
			{
				m_masks[i] = 0;
			}
		}

		bool isSet()
		{
			unsigned int sum = 0;
			for (size_t i = 0; i < N; i++)
			{
				sum |= m_masks[i];
			}
			return sum;
		}
	};
}	 // namespace dice::hfe::io
