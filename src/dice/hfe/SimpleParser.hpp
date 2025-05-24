#pragma once

#include <cstdint>
#include <list>
#include <map>
#include <string>

namespace dice::hfe
{
	class SimpleParser
	{
	public:
		std::map<int32_t, std::string> m_settings;
		std::map<int32_t, std::string> m_descriptions;
		char m_delimiter;

	public:
		void
		add(int32_t key, const std::string& setting,
			const std::string& description);
		bool parseString(
			const std::string&, std::list<std::pair<int32_t, std::string>>&);
		bool getKey(
			const std::string& input, int32_t* outIndex, std::string* outValue);
	};
}	 // namespace dice::hfe
