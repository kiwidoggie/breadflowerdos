#pragma once
#include <cstdint>

namespace dice::hfe
{
	struct UIntHashFunc
	{
		unsigned int operator()(unsigned int t)
		{
			return t;
		}
	};

	template <class K, class V, class H> struct Hash
	{

		struct Node
		{
			Node* next;
			K key;
			V value;
		};

		Node** table;		  // 0x00
		unsigned int size;	  // 0x8
		int _0xC;			  // XXX: no clue what that is, seems like just mem
							  // padding
		H hash_fun;			  // 0x10

		bool find(const K& key, V* val)
		{
			unsigned int hash = hash_fun(key);
			Node* n = table[hash % size];
			while (n && key != n->key)
			{
				n = n->next;
			}
			if (n)
			{
				*val = n->value;
				return true;
			}
			return false;
		}

		bool hasKey(const K& key)
		{
			unsigned int hash = hash_fun(key);
			Node* n = table[hash % size];
			while (n && key != n->key)
			{
				n = n->next;
			}
			if (n)
			{
				return true;
			}
			return false;
		}

		bool insert(const K& key, const V& val)
		{
			unsigned int hash = hash_fun(key);
			std::size_t index = hash % size;

			Node* n = table[index];
			while (n)
			{
				if (key == n->key)
				{
					return false;
				}
				n = n->next;
			}

			if (Node* nn = new Node())
			{
				nn->next = table[index];
				nn->key = key;
				nn->value = val;
				table[index] = nn;
			}
			else
			{
				table[index] = nullptr;
			}
			return true;
		}
	};
}	 // namespace dice::hfe
