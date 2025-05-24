#pragma once

#include <map>

namespace dice::hfe
{
	template <class T, class U> class VariableStorage
	{
	public:
		std::map<T, U> storage;
		void* lastLookup;

	public:
		U& get(const T& key, U& value)
		{
			auto it = storage.find(key);
			lastLookup = &it;

			if (it != storage.end())
			{
				value = it->second;
			}
			return value;
		}

		void set(const T& key, const U& value)
		{
			auto it = storage.find(key);
			lastLookup = &it;

			if (it != storage.end())
			{
				it->second = value;
			}
			else
			{
				storage.insert({key, value});
			}
		}

		bool exists(const std::string& key)
		{
			auto it = storage.find(key);
			lastLookup = &it;
			return it != storage.end();
		}

		size_t erase(const std::string& key)
		{
			return storage.erase(key);
		}
	};
}	 // namespace dice::hfe
