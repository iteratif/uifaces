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


// Auto generated file, don't modify.

#ifndef __META_TEST_METAGEN_OPERATOR_CONSTNESS_H
#define __META_TEST_METAGEN_OPERATOR_CONSTNESS_H


#include "cpgf/gmetadefine.h"
#include "cpgf/metadata/gmetadataconfig.h"
#include "cpgf/metadata/private/gmetadata_header.h"
#include "cpgf/gmetapolicy.h"




namespace meta_test { 


inline MetagenOperatorConstness opErAToRWrapper_MetagenOperatorConstness__opAdd(MetagenOperatorConstness * self, int n) {
    return (*self) + n;
}
inline MetagenOperatorConstness opErAToRWrapper_MetagenOperatorConstness__opSub(const MetagenOperatorConstness * self, int n) {
    return (*self) - n;
}


template <typename D>
void buildMetaClass_MetagenOperatorConstness(const cpgf::GMetaDataConfigFlags & config, D _d)
{
    (void)config; (void)_d; (void)_d;
    using namespace cpgf;
    
    _d.CPGF_MD_TEMPLATE _constructor<void * ()>();
    _d.CPGF_MD_TEMPLATE _constructor<void * (int)>();
    _d.CPGF_MD_TEMPLATE _field("value", &D::ClassType::value);
    _d.CPGF_MD_TEMPLATE _method("constSelf", &D::ClassType::constSelf);
    _d.CPGF_MD_TEMPLATE _method("constSelfRef", &D::ClassType::constSelfRef, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<-1> >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorConstness (*)(cpgf::GMetaSelf, int)>(mopHolder + mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opAdd", (MetagenOperatorConstness (*) (MetagenOperatorConstness *, int))&opErAToRWrapper_MetagenOperatorConstness__opAdd, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorConstness (*)(const cpgf::GMetaSelf &, int)>(mopHolder - mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opSub", (MetagenOperatorConstness (*) (const MetagenOperatorConstness *, int))&opErAToRWrapper_MetagenOperatorConstness__opSub, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
}


} // namespace meta_test




#include "cpgf/metadata/private/gmetadata_footer.h"


#endif
