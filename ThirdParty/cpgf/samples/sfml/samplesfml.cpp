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


#include "../samplescriptbindutil.h"

#include "cpgf/scriptbind/gscriptbindapi.h"
#include "cpgf/scriptbind/gscriptbindutil.h"
#include "cpgf/gmetaapi.h"
#include "cpgf/gmetadefine.h"
#include "cpgf/gscopedptr.h"
#include "cpgf/gapiutil.h"
#include "cpgf/gscopedinterface.h"

#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;
using namespace cpgf;

void scriptTrace(const char * s)
{
	cout << "script message: " << s << endl;
}

int main(int argc, char * argv[])
{
	ScriptHelper scriptHelper(argc, argv);
	
	GDefineMetaGlobal()
		._class(
			GDefineMetaNamespace::declare("test")
				._method("scriptTrace", &scriptTrace)
		)
	;

	GScopedInterface<IMetaClass> metaClass(scriptHelper.borrowService()->findClassByName("sfml"));
	scriptSetValue(scriptHelper.borrowScriptObject(), "sfml", GScriptValue::fromClass(metaClass.get()));
	
	metaClass.reset(scriptHelper.borrowService()->findClassByName("test"));
	scriptSetValue(scriptHelper.borrowScriptObject(), "test", GScriptValue::fromClass(metaClass.get()));

	scriptHelper.execute();
	
	return 0;
}
