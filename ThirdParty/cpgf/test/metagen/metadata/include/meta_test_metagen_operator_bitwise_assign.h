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

#ifndef __META_TEST_METAGEN_OPERATOR_BITWISE_ASSIGN_H
#define __META_TEST_METAGEN_OPERATOR_BITWISE_ASSIGN_H


#include "cpgf/gmetadefine.h"
#include "cpgf/metadata/gmetadataconfig.h"
#include "cpgf/metadata/private/gmetadata_header.h"
#include "cpgf/gmetapolicy.h"




namespace meta_test { 


inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitAndAssign(MetagenOperatorBitwiseAssign * self, int n) {
    return (*self) &= n;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitAndAssign(MetagenOperatorBitwiseAssign * self, const MetagenOperatorBitwiseAssign & other) {
    return (*self) &= other;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitAndAssign(MetagenOperatorBitwiseAssign * self, const std::string & s) {
    return (*self) &= s;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitOrAssign(MetagenOperatorBitwiseAssign * self, int n) {
    return (*self) |= n;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitOrAssign(MetagenOperatorBitwiseAssign * self, const MetagenOperatorBitwiseAssign & other) {
    return (*self) |= other;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitOrAssign(MetagenOperatorBitwiseAssign * self, const std::string & s) {
    return (*self) |= s;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitXorAssign(MetagenOperatorBitwiseAssign * self, int n) {
    return (*self) ^= n;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitXorAssign(MetagenOperatorBitwiseAssign * self, const MetagenOperatorBitwiseAssign & other) {
    return (*self) ^= other;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitXorAssign(MetagenOperatorBitwiseAssign * self, const std::string & s) {
    return (*self) ^= s;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opLeftShiftAssign(MetagenOperatorBitwiseAssign * self, int n) {
    return (*self) <<= n;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opLeftShiftAssign(MetagenOperatorBitwiseAssign * self, const MetagenOperatorBitwiseAssign & other) {
    return (*self) <<= other;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opLeftShiftAssign(MetagenOperatorBitwiseAssign * self, const std::string & s) {
    return (*self) <<= s;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opRightShiftAssign(MetagenOperatorBitwiseAssign * self, int n) {
    return (*self) >>= n;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opRightShiftAssign(MetagenOperatorBitwiseAssign * self, const MetagenOperatorBitwiseAssign & other) {
    return (*self) >>= other;
}
inline MetagenOperatorBitwiseAssign & opErAToRWrapper_MetagenOperatorBitwiseAssign__opRightShiftAssign(MetagenOperatorBitwiseAssign * self, const std::string & s) {
    return (*self) >>= s;
}


template <typename D>
void buildMetaClass_MetagenOperatorBitwiseAssign(const cpgf::GMetaDataConfigFlags & config, D _d)
{
    (void)config; (void)_d; (void)_d;
    using namespace cpgf;
    
    _d.CPGF_MD_TEMPLATE _constructor<void * ()>();
    _d.CPGF_MD_TEMPLATE _constructor<void * (int)>();
    _d.CPGF_MD_TEMPLATE _field("value", &D::ClassType::value);
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, int)>(mopHolder &= mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opBitAndAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, int))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitAndAssign, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, const MetagenOperatorBitwiseAssign &)>(mopHolder &= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opBitAndAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, const MetagenOperatorBitwiseAssign &))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitAndAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder &= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opBitAndAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, const std::string &))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitAndAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, int)>(mopHolder |= mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opBitOrAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, int))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitOrAssign, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, const MetagenOperatorBitwiseAssign &)>(mopHolder |= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opBitOrAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, const MetagenOperatorBitwiseAssign &))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitOrAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder |= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opBitOrAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, const std::string &))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitOrAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, int)>(mopHolder ^= mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opBitXorAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, int))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitXorAssign, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, const MetagenOperatorBitwiseAssign &)>(mopHolder ^= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opBitXorAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, const MetagenOperatorBitwiseAssign &))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitXorAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder ^= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opBitXorAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, const std::string &))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opBitXorAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, int)>(mopHolder <<= mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opLeftShiftAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, int))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opLeftShiftAssign, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, const MetagenOperatorBitwiseAssign &)>(mopHolder <<= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opLeftShiftAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, const MetagenOperatorBitwiseAssign &))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opLeftShiftAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder <<= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opLeftShiftAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, const std::string &))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opLeftShiftAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, int)>(mopHolder >>= mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opRightShiftAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, int))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opRightShiftAssign, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, const MetagenOperatorBitwiseAssign &)>(mopHolder >>= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opRightShiftAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, const MetagenOperatorBitwiseAssign &))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opRightShiftAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorBitwiseAssign & (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder >>= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opRightShiftAssign", (MetagenOperatorBitwiseAssign & (*) (MetagenOperatorBitwiseAssign *, const std::string &))&opErAToRWrapper_MetagenOperatorBitwiseAssign__opRightShiftAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
}


} // namespace meta_test




#include "cpgf/metadata/private/gmetadata_footer.h"


#endif
