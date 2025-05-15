#pragma once

#include <map>
#include <string>
#include <cstdint>
#include <list>

namespace dice
{
    namespace hfe
    {
        class SimpleParser
        {
        public:
            std::map<int32_t, std::string> m_settings;
            std::map<int32_t, std::string> m_descriptions;
            char m_delimiter;

        public:
            void add(int32_t key, std::string const& setting, std::string const& description);
            bool parseString(std::string const&, std::list<std::pair<int32_t, std::string>>&);
            bool getKey(const std::string& input, int32_t* outIndex, std::string* outValue);
        };
    }
}
