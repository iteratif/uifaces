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

#ifndef __META_TEST_METAGEN_OPERATOR_ARITHMETIC_H
#define __META_TEST_METAGEN_OPERATOR_ARITHMETIC_H


#include "cpgf/gmetadefine.h"
#include "cpgf/metadata/gmetadataconfig.h"
#include "cpgf/metadata/private/gmetadata_header.h"
#include "cpgf/gmetapolicy.h"




namespace meta_test { 


inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opAdd(const MetagenOperatorArithmetic * self, int n) {
    return (*self) + n;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opAdd(const MetagenOperatorArithmetic * self, const MetagenOperatorArithmetic & other) {
    return (*self) + other;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opAdd(const MetagenOperatorArithmetic * self, const std::string & s) {
    return (*self) + s;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opSub(MetagenOperatorArithmetic * self, int n) {
    return (*self) - n;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opSub(MetagenOperatorArithmetic * self, const MetagenOperatorArithmetic & other) {
    return (*self) - other;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opSub(MetagenOperatorArithmetic * self, const std::string & s) {
    return (*self) - s;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opMul(MetagenOperatorArithmetic * self, int n) {
    return (*self) * n;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opMul(MetagenOperatorArithmetic * self, const MetagenOperatorArithmetic & other) {
    return (*self) * other;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opMul(MetagenOperatorArithmetic * self, const std::string & s) {
    return (*self) * s;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opDiv(MetagenOperatorArithmetic * self, int n) {
    return (*self) / n;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opDiv(MetagenOperatorArithmetic * self, const MetagenOperatorArithmetic & other) {
    return (*self) / other;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opDiv(MetagenOperatorArithmetic * self, const std::string & s) {
    return (*self) / s;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opMod(MetagenOperatorArithmetic * self, int n) {
    return (*self) % n;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opMod(MetagenOperatorArithmetic * self, const MetagenOperatorArithmetic & other) {
    return (*self) % other;
}
inline MetagenOperatorArithmetic opErAToRWrapper_MetagenOperatorArithmetic__opMod(MetagenOperatorArithmetic * self, const std::string & s) {
    return (*self) % s;
}


template <typename D>
void buildMetaClass_MetagenOperatorArithmetic(const cpgf::GMetaDataConfigFlags & config, D _d)
{
    (void)config; (void)_d; (void)_d;
    using namespace cpgf;
    
    _d.CPGF_MD_TEMPLATE _constructor<void * ()>();
    _d.CPGF_MD_TEMPLATE _constructor<void * (int)>();
    _d.CPGF_MD_TEMPLATE _field("value", &D::ClassType::value);
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(const cpgf::GMetaSelf &, int)>(mopHolder + mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opAdd", (MetagenOperatorArithmetic (*) (const MetagenOperatorArithmetic *, int))&opErAToRWrapper_MetagenOperatorArithmetic__opAdd, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(const cpgf::GMetaSelf &, const MetagenOperatorArithmetic &)>(mopHolder + mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opAdd", (MetagenOperatorArithmetic (*) (const MetagenOperatorArithmetic *, const MetagenOperatorArithmetic &))&opErAToRWrapper_MetagenOperatorArithmetic__opAdd, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(const cpgf::GMetaSelf &, const std::string &)>(mopHolder + mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opAdd", (MetagenOperatorArithmetic (*) (const MetagenOperatorArithmetic *, const std::string &))&opErAToRWrapper_MetagenOperatorArithmetic__opAdd, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(cpgf::GMetaSelf, int)>(mopHolder - mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opSub", (MetagenOperatorArithmetic (*) (MetagenOperatorArithmetic *, int))&opErAToRWrapper_MetagenOperatorArithmetic__opSub, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(cpgf::GMetaSelf, const MetagenOperatorArithmetic &)>(mopHolder - mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opSub", (MetagenOperatorArithmetic (*) (MetagenOperatorArithmetic *, const MetagenOperatorArithmetic &))&opErAToRWrapper_MetagenOperatorArithmetic__opSub, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder - mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opSub", (MetagenOperatorArithmetic (*) (MetagenOperatorArithmetic *, const std::string &))&opErAToRWrapper_MetagenOperatorArithmetic__opSub, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(cpgf::GMetaSelf, int)>(mopHolder * mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opMul", (MetagenOperatorArithmetic (*) (MetagenOperatorArithmetic *, int))&opErAToRWrapper_MetagenOperatorArithmetic__opMul, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(cpgf::GMetaSelf, const MetagenOperatorArithmetic &)>(mopHolder * mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opMul", (MetagenOperatorArithmetic (*) (MetagenOperatorArithmetic *, const MetagenOperatorArithmetic &))&opErAToRWrapper_MetagenOperatorArithmetic__opMul, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder * mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opMul", (MetagenOperatorArithmetic (*) (MetagenOperatorArithmetic *, const std::string &))&opErAToRWrapper_MetagenOperatorArithmetic__opMul, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(cpgf::GMetaSelf, int)>(mopHolder / mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opDiv", (MetagenOperatorArithmetic (*) (MetagenOperatorArithmetic *, int))&opErAToRWrapper_MetagenOperatorArithmetic__opDiv, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(cpgf::GMetaSelf, const MetagenOperatorArithmetic &)>(mopHolder / mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opDiv", (MetagenOperatorArithmetic (*) (MetagenOperatorArithmetic *, const MetagenOperatorArithmetic &))&opErAToRWrapper_MetagenOperatorArithmetic__opDiv, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder / mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opDiv", (MetagenOperatorArithmetic (*) (MetagenOperatorArithmetic *, const std::string &))&opErAToRWrapper_MetagenOperatorArithmetic__opDiv, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(cpgf::GMetaSelf, int)>(mopHolder % mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opMod", (MetagenOperatorArithmetic (*) (MetagenOperatorArithmetic *, int))&opErAToRWrapper_MetagenOperatorArithmetic__opMod, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(cpgf::GMetaSelf, const MetagenOperatorArithmetic &)>(mopHolder % mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opMod", (MetagenOperatorArithmetic (*) (MetagenOperatorArithmetic *, const MetagenOperatorArithmetic &))&opErAToRWrapper_MetagenOperatorArithmetic__opMod, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmetic (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder % mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opMod", (MetagenOperatorArithmetic (*) (MetagenOperatorArithmetic *, const std::string &))&opErAToRWrapper_MetagenOperatorArithmetic__opMod, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
}


} // namespace meta_test




#include "cpgf/metadata/private/gmetadata_footer.h"


#endif
