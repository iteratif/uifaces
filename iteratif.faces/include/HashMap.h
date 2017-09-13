#ifndef HASHMAP_H_
#define HASHMAP_H_

#include "itString.h"
#include "Array.h"

namespace iteratif {
	template<class T>
	class HashMapNode {
	public:
		HashMapNode(itString _key, T _value, HashMapNode *_next)
			: Key(_key)
			, Value(_value)
			, Next(_next) {

		}

	public:
		T Value;
		itString Key;
		HashMapNode *Next;
	};

	template<class T>
	class HashMap {
	public:
		HashMap(const int _size = 256);
		~HashMap();

		int GetSize() { return m_map.size(); }
		int GetIndex(const char *_key);
		T Get(const char *_key);
		void Set(const char *_key, T _value);

	private:
		Array<HashMapNode<T>*> m_map;
		int m_maskSize;
	};

	template<class T>
	HashMap<T>::HashMap(const int _size)
		: m_map(_size)
		, m_maskSize(_size - 1) {

	}

	template<class T>
	HashMap<T>::~HashMap() {

	}

	template<class T>
	T HashMap<T>::Get(const char *_key) {
		int index = GetIndex(_key);
		HashMapNode<T> *node = m_map.get(index);
		for (; node != nullptr; node = node->Next) {
			if (strcmp(node->Key, _key) == 0) {
				return node->Value;
			}
		}

		return nullptr;
	}

	template<class T>
	void HashMap<T>::Set(const char *_key, T _value) {
		int result;
		HashMapNode<T> *node = nullptr;
		int index = GetIndex(_key);
		HashMapNode<T> *topNode = m_map.get(index);
		for (node = topNode; node != nullptr; node = node->Next) {
			result = strcmp(node->Key, _key);
			if (result == 0) {
				node->Value = _value;
			}
			if (result > 0) {
				break;
			}
		}

		HashMapNode<T> *newNode = new HashMapNode<T>(_key, _value, topNode);
		m_map.set(newNode, index);
	}

	template<class T>
	int HashMap<T>::GetIndex(const char *_key) {
		return itString::Hash(_key) % m_maskSize;
	}
}

#endif // !HASHMAP_H_

