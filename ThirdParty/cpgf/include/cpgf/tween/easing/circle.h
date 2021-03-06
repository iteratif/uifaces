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


#ifndef __TWEEN_EASING_CIRCLE_H
#define __TWEEN_EASING_CIRCLE_H

#include "cpgf/tween/gtweencommon.h"

#include <math.h>

namespace cpgf {

struct CircleEase
{
public:
	static GTweenEaseType easeIn() {
		return &_easeIn;
	}
	
	static GTweenEaseType easeOut() {
		return &_easeOut;
	}
	
	static GTweenEaseType easeInOut() {
		return &_easeInOut;
	}
	
private:
	static GTweenNumber _easeIn(const GTweenEaseParam * param) {
		GTweenNumber t = param->current / param->total;
		return -sqrt(1.0f - t * t) + 1.0f;
	}
	
	static GTweenNumber _easeOut(const GTweenEaseParam * param) {
		GTweenNumber t = param->current / param->total - 1.0f;
		return sqrt(1.0f - t * t);
	}
	
	static GTweenNumber _easeInOut(const GTweenEaseParam * param) {
		GTweenNumber t = param->current / (param->total * 0.5f);
		if(t < 1.0f) {
			return -0.5f * (sqrt(1.0f - t * t) - 1.0f);
		}
		else {
			t -= 2.0f;
			return 0.5f * (sqrt(1.0f - t * t) + 1);
		}
	}
};


} // namespace cpgf


#endif
