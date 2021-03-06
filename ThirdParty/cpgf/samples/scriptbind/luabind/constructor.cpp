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


#include "luabind_common.h"


namespace {


void doTest()
{
	using namespace cpgf;
	using namespace testscript;

	TestLuaContext context;
	context.doString("print(\"Constructor\")");

	GScopedInterface<IMetaClass> metaClass(context.getService()->findClassByName("testscript::TestObject"));
	testCheckAssert(metaClass);
	
	context.getBinding()->bindClass("TestObject", metaClass.get());

	context.doString(""
		LINE(a = TestObject())
		LINE(assert(a.value == Magic1))
		
		LINE(b = TestObject(a))
		LINE(assert(b.value == Magic2))
	);
}


gTestCase(doTest);



}
