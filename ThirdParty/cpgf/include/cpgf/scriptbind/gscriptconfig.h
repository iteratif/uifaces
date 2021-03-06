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


#ifndef __GSCRIPTCONFIG_H
#define __GSCRIPTCONFIG_H

#include "cpgf/gclassutil.h"
#include "cpgf/gflags.h"


namespace cpgf {


GMAKE_FINAL(GScriptConfig)

class GScriptConfig : GFINAL_BASE(GScriptConfig)
{
private:
	enum {
		scAccessStaticDataViaInstance = 1 << 0,
		scAccessStaticMethodViaInstance = 1 << 1,
		scAccessEnumTypeViaInstance = 1 << 2,
		scAccessEnumValueViaInstance = 1 << 3,
		scAccessClassViaInstance = 1 << 4,
		scAccessRawData = 1 << 5
	};

	enum {
		DefaultFlags =
				scAccessStaticDataViaInstance
				| scAccessStaticMethodViaInstance
				| scAccessEnumTypeViaInstance
				| scAccessEnumValueViaInstance
				| scAccessClassViaInstance
				| scAccessRawData
	};

public:
	GScriptConfig() : flags(DefaultFlags) {
	}

	GScriptConfig(const GScriptConfig & other) : flags(other.flags) {
	}

	GScriptConfig & operator = (const GScriptConfig & other) {
		this->flags = other.flags;

		return *this;
	}

	void setAccessStaticDataViaInstance(bool set) {
		this->setFlag(scAccessStaticDataViaInstance, set);
	}

	bool allowAccessStaticDataViaInstance() const {
		return this->hasFlag(scAccessStaticDataViaInstance);
	}

	void setAccessStaticMethodViaInstance(bool set) {
		this->setFlag(scAccessStaticMethodViaInstance, set);
	}

	bool allowAccessStaticMethodViaInstance() const {
		return this->hasFlag(scAccessStaticMethodViaInstance);
	}

	void setAccessEnumTypeViaInstance(bool set) {
		this->setFlag(scAccessEnumTypeViaInstance, set);
	}

	bool allowAccessEnumTypeViaInstance() const {
		return this->hasFlag(scAccessEnumTypeViaInstance);
	}

	void setAccessEnumValueViaInstance(bool set) {
		this->setFlag(scAccessEnumValueViaInstance, set);
	}

	bool allowAccessEnumValueViaInstance() const {
		return this->hasFlag(scAccessEnumValueViaInstance);
	}

	void setAccessClassViaInstance(bool set) {
		this->setFlag(scAccessClassViaInstance, set);
	}

	bool allowAccessClassViaInstance() const {
		return this->hasFlag(scAccessClassViaInstance);
	}

	void setAccessRawData(bool set) {
		this->setFlag(scAccessRawData, set);
	}

	bool allowAccessRawData() const {
		return this->hasFlag(scAccessRawData);
	}

private:
	bool hasFlag(unsigned int flag) const {
		return (this->flags & flag) != 0;
	}

	void setFlag(unsigned int flag, bool set) {
		if(set) {
			this->setFlag(flag);
		}
		else {
			this->clearFlag(flag);
		}
	}

	void setFlag(unsigned int flag) {
		this->flags |= flag;
	}

	void clearFlag(unsigned int flag) {
		this->flags &= ~flag;
	}

private:
	unsigned int flags;
};



} // namespace cpgf



#endif

