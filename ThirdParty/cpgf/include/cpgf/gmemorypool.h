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


#ifndef __GMEMORYPOOL_H
#define __GMEMORYPOOL_H

#include "cpgf/gassert.h"
#include "cpgf/gscopedptr.h"
#include "cpgf/gclassutil.h"

#include <map>


namespace cpgf {

namespace memorypool_internal {


class GMemoryPoolRange
{
public:
	explicit GMemoryPoolRange(void * start);
	GMemoryPoolRange(void * start, void * end);

	GMemoryPoolRange(const GMemoryPoolRange & other);
	GMemoryPoolRange & operator = (const GMemoryPoolRange & other);

	bool operator < (const GMemoryPoolRange & other) const;

private:
	void * start;
	void * end;
};

template <typename T>
struct GMemoryPoolInitializer
{
	static void init(void * p) {
		new (p) T();
	}

	static void deinit(void * p) {
		static_cast<T *>(p)->~T();
	}
};

template <>
struct GMemoryPoolInitializer <void>
{
	static void init(void * /*p*/) {
	}

	static void deinit(void * /*p*/) {
	}
};

class GMemoryPoolChunk;

class GMemoryPoolImplement
{
private:
	typedef std::map<GMemoryPoolRange, GMemoryPoolChunk *> MapType;

public:
	GMemoryPoolImplement(unsigned int blockSize, unsigned int blockCount);
	~GMemoryPoolImplement();

	void * allocate();
	void free(void * p);

	void setInit(void (*funcInit)(void * p));
	void setDeinit(void (*funcDeinit)(void * p));

private:
	void freeAll();
	void freeAllMap(MapType * m);

private:
	const unsigned int blockSize;
	const unsigned int blockCount;
	MapType fullMap;
	MapType freeMap;

	void (*funcInit)(void * p);
	void (*funcDeinit)(void * p);

	GMAKE_NONCOPYABLE(GMemoryPoolImplement)
};


} // namespace memorypool_internal

const unsigned int MemoryPoolDefaultBlockCount = 256;

class GMemoryPool
{
public:
	explicit GMemoryPool(unsigned int blockSize, unsigned int blockCount = MemoryPoolDefaultBlockCount)
		: implement(blockSize, blockCount) {
	}

	void * allocate() {
		return this->implement.allocate();
	}

	void free(void * p) {
		this->implement.free(p);
	}

private:
	memorypool_internal::GMemoryPoolImplement implement;

	GMAKE_NONCOPYABLE(GMemoryPool)
};


template <typename T>
class GObjectPool
{
public:
	explicit GObjectPool(unsigned int objectSize = sizeof(T), unsigned int blockCount = MemoryPoolDefaultBlockCount)
		: implement(objectSize, blockCount) {
		this->implement.setInit(memorypool_internal::GMemoryPoolInitializer<T>::init);
		this->implement.setDeinit(memorypool_internal::GMemoryPoolInitializer<T>::deinit);
	}

	T * allocate() {
		return static_cast<T *>(this->implement.allocate());
	}

	void free(T * p) {
		this->implement.free(p);
	}

private:
	memorypool_internal::GMemoryPoolImplement implement;

	GMAKE_NONCOPYABLE(GObjectPool)
};


class GMemoryPoolManagerImplement;

class GMemoryPoolManager
{
public:
	GMemoryPoolManager();
	~GMemoryPoolManager();

	GMemoryPool * getMemoryPool(unsigned int blockSize, unsigned int blockCount = MemoryPoolDefaultBlockCount);

public:
	static GMemoryPoolManager * getGlobal();

private:
	GScopedPointer<GMemoryPoolManagerImplement> implement;
};


} // namespace cpgf



#endif
