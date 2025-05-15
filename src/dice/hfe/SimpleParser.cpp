#include "SimpleParser.hpp"

using namespace dice::hfe;

void SimpleParser::add(int32_t key, std::string const& setting, std::string const& description)
{
	m_settings.emplace(key, setting);
	m_descriptions.emplace(key, description);
}

bool SimpleParser::parseString(const std::string& input, std::list<std::pair<int, std::string>>& outputList) {
    // Clear the list before parsing
    outputList.clear();

    // Add a space at the end to simplify parsing
    std::string workingStr = input + " ";
    char delimiter = this->m_delimiter; // '+'

    size_t pos = workingStr.find(delimiter);
    int32_t successfulParses = 0;

    while (pos != std::string::npos) {
        // Extract the substring up to and including the delimiter
        std::string token = workingStr.substr(0, pos + 1);  // +1 to include the delimiter
        // remove processed part
        workingStr = workingStr.substr(pos + 1);

        int32_t key = 0;
        std::string value;

        // Parse the token into a key-value pair
        if (getKey(token, &key, &value)) {
            outputList.emplace_back(key, value);
            ++successfulParses;
        }

        pos = workingStr.find(delimiter);
    }

    return successfulParses > 0;
}

bool SimpleParser::getKey(const std::string& input, int32_t* outKey, std::string* outValue) {
    *outKey = -1;

    for (auto& [key, setting] : m_settings)
    {
        if (input.compare(0, setting.length(), setting) == 0) {
            *outKey = key;
            if (*outKey == -1) return false;

            // Start parsing the value after the setting
            size_t valueStart = setting.length();
            if (input.length() > valueStart && input[valueStart] == '"') {
                size_t endQuote = input.find('"', valueStart + 1);
                if (endQuote == std::string::npos) return false;
                *outValue = input.substr(valueStart + 1, endQuote - valueStart - 1);
            }
            else {
                // Unquoted: read until next space
                size_t end = valueStart;
                while (end < input.length() && !isspace(input[end])) {
                    ++end;
                }
                *outValue = input.substr(valueStart, end - valueStart);
            }

            return true;
        }
    }

    return false;
}
