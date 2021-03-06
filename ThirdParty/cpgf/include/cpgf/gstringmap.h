/*
  cpgf Library
  Copyright (C) 2011 - 2013 Wang Qi http://www.cpgf.org/
  All rights reserved.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/


#ifndef __GSTRINGMAP_H
#define __GSTRINGMAP_H

#include "cpgf/gassert.h"

#include <map>

#include <string.h>

namespace cpgf {

struct GStringMapNewKey
{
	static const char * allocateKey(const char * key) {
		size_t len = strlen(key) + 1;
		char * ns = new char[len];
		memmove(ns, key, len);
		return ns;
	}

	static void freeKey(const char * key) {
		delete[] key;
	}
};

struct GStringMapReuseKey
{
	static const char * allocateKey(const char * key) {
		return key;
	}

	static void freeKey(const char * /*key*/) {
	}
};

template <typename T, typename KeyOp = GStringMapNewKey>
class GStringMap
{
private:
	struct CStringCompare {
		bool operator () (const char * a, const char * b) const {
			return strcmp(a, b) < 0;
		}
	};

	typedef std::map<const char *, T, CStringCompare> MapType;

public:
	typedef typename MapType::iterator iterator;
	typedef typename MapType::const_iterator const_iterator;

public:
	~GStringMap() {
		this->clear();
	}

	iterator begin() {
		return this->stringMap.begin();
	}

	const_iterator begin() const {
		return this->stringMap.begin();
	}

	iterator end() {
		return this->stringMap.end();
	}

	const_iterator end() const {
		return this->stringMap.end();
	}

	bool hasKey(const char * key) const {
		return this->stringMap.find(key) != this->stringMap.end();
	}

	bool isEmpty() const {
		return this->stringMap.empty();
	}
	
	int getCount() const {
		return static_cast<int>(this->stringMap.size());
	}

	iterator find(const char * key) {
		return this->stringMap.find(key);
	}

	const_iterator find(const char * key) const {
		return this->stringMap.find(key);
	}

	void set(const char * key, const T & value) {
		typename MapType::iterator it = this->stringMap.find(key);
		if(it == this->stringMap.end()) {
			this->stringMap.insert(std::make_pair(KeyOp::allocateKey(key), value));
		}
		else {
			it->second = value;
		}
	}

	bool remove(const char * key) {
		typename MapType::iterator it = this->stringMap.find(key);
		if(it != this->stringMap.end()) {
			KeyOp::freeKey(it->first);
			this->stringMap.erase(it);

			return true;
		}
		else {
			return false;
		}
	}

	void clear() {
		for(typename MapType::iterator it = this->stringMap.begin(); it != this->stringMap.end(); ++it) {
			KeyOp::freeKey(it->first);
		}

		this->stringMap.clear();
	}

private:
	MapType stringMap;
};



} // namespace cpgf



#endif

