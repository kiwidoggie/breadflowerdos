#pragma once

#include <string>
#include <algorithm>

namespace dice
{
	namespace hfe
	{
		struct NoCaseStringCompare
		{
			inline static bool EqualsLowerCase(const char* x, const char* y)
			{
				std::string s_Left(x);
				std::string s_Right(y);

				std::transform(s_Left.begin(), s_Left.end(), s_Left.begin(), ::tolower);
				std::transform(s_Right.begin(), s_Right.end(), s_Right.begin(), ::tolower);

				return s_Left == s_Right;
			}

			inline bool operator() (const char* y, const char* x) const
			{
				return (x && y) ? EqualsLowerCase(y, x) : false;
			}

			inline bool operator() (const std::string& y, const std::string& x) const
			{
				return (x.size() > 0 && y.size() > 0) ? EqualsLowerCase(y.c_str(), x.c_str()) : false;
			}
		};
	}
}