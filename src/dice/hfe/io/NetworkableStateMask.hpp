#pragma once

#include <cstddef>

namespace dice
{
	namespace hfe
	{
		namespace io
		{
			struct NetworkableStateMask {

				static constexpr size_t N = 12;

				unsigned int m_Masks[N]; // for each PCO root & child object that has networkable

				NetworkableStateMask() : m_Masks{} {}

				unsigned int& operator[](int index)
				{
					return m_Masks[index];
				}

				void set(const NetworkableStateMask& rhs) {
					for (int i = 0; i < N; i++) {
						m_Masks[i] |= rhs.m_Masks[i];
					}
				}

				void unset(const NetworkableStateMask& rhs) {
					for (int i = 0; i < N; i++) {
						m_Masks[i] &= ~rhs.m_Masks[i];
					}
				}

				void reset() {
					for (int i = 0; i < N; i++) {
						m_Masks[i] = 0xFFFFFFFF;
					}
				}

				void zero() {
					for (int i = 0; i < N; i++) {
						m_Masks[i] = 0;
					}
				}

				bool isSet() {
					unsigned int sum = 0;
					for (int i = 0; i < N; i++) {
						sum |= m_Masks[i];
					}
					return sum;
				}

			};
		}
	}
}
