#pragma once

#include <map>

namespace dice
{
    namespace hfe
    {
        template <class T, class U>
        class VariableStorage
        {
        public:
            std::map<T, U> storage;
            void* lastLookup;

        public:
            U& get(T const& key, U& value)
            {
                auto it = storage.find(key);
                lastLookup = &it;

                if (it != storage.end())
                {
                    value = it->second;
                }
                return value;
            }
            void set(T const& key, U const& value)
            {
                auto it = storage.find(key);
                lastLookup = &it;

                if (it != storage.end())
                {
                    it->second = value;
                }
                else
                {
                    storage.insert({ key, value });
                }
            }
            bool exists(std::string const& key)
            {
                auto it = storage.find(key);
                lastLookup = &it;
                return it != storage.end();
            }
            size_t erase(std::string const& key)
            {
                return storage.erase(key);
            }
        };
    }
}
