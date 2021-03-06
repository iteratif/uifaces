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

#ifndef __META_TEST_METAGEN_OPERATOR_ARITHMETIC_ASSIGN_H
#define __META_TEST_METAGEN_OPERATOR_ARITHMETIC_ASSIGN_H


#include "cpgf/gmetadefine.h"
#include "cpgf/metadata/gmetadataconfig.h"
#include "cpgf/metadata/private/gmetadata_header.h"
#include "cpgf/gmetapolicy.h"




namespace meta_test { 


inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opAddAssign(MetagenOperatorArithmeticAssign * self, int n) {
    return (*self) += n;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opAddAssign(MetagenOperatorArithmeticAssign * self, const MetagenOperatorArithmeticAssign & other) {
    return (*self) += other;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opAddAssign(MetagenOperatorArithmeticAssign * self, const std::string & s) {
    return (*self) += s;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opSubAssign(MetagenOperatorArithmeticAssign * self, int n) {
    return (*self) -= n;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opSubAssign(MetagenOperatorArithmeticAssign * self, const MetagenOperatorArithmeticAssign & other) {
    return (*self) -= other;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opSubAssign(MetagenOperatorArithmeticAssign * self, const std::string & s) {
    return (*self) -= s;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opMulAssign(MetagenOperatorArithmeticAssign * self, int n) {
    return (*self) *= n;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opMulAssign(MetagenOperatorArithmeticAssign * self, const MetagenOperatorArithmeticAssign & other) {
    return (*self) *= other;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opMulAssign(MetagenOperatorArithmeticAssign * self, const std::string & s) {
    return (*self) *= s;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opDivAssign(MetagenOperatorArithmeticAssign * self, int n) {
    return (*self) /= n;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opDivAssign(MetagenOperatorArithmeticAssign * self, const MetagenOperatorArithmeticAssign & other) {
    return (*self) /= other;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opDivAssign(MetagenOperatorArithmeticAssign * self, const std::string & s) {
    return (*self) /= s;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opModAssign(MetagenOperatorArithmeticAssign * self, int n) {
    return (*self) %= n;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opModAssign(MetagenOperatorArithmeticAssign * self, const MetagenOperatorArithmeticAssign & other) {
    return (*self) %= other;
}
inline MetagenOperatorArithmeticAssign & opErAToRWrapper_MetagenOperatorArithmeticAssign__opModAssign(MetagenOperatorArithmeticAssign * self, const std::string & s) {
    return (*self) %= s;
}


template <typename D>
void buildMetaClass_MetagenOperatorArithmeticAssign(const cpgf::GMetaDataConfigFlags & config, D _d)
{
    (void)config; (void)_d; (void)_d;
    using namespace cpgf;
    
    _d.CPGF_MD_TEMPLATE _constructor<void * ()>();
    _d.CPGF_MD_TEMPLATE _constructor<void * (int)>();
    _d.CPGF_MD_TEMPLATE _field("value", &D::ClassType::value);
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, int)>(mopHolder += mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opAddAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, int))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opAddAssign, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, const MetagenOperatorArithmeticAssign &)>(mopHolder += mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opAddAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, const MetagenOperatorArithmeticAssign &))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opAddAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder += mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opAddAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, const std::string &))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opAddAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, int)>(mopHolder -= mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opSubAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, int))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opSubAssign, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, const MetagenOperatorArithmeticAssign &)>(mopHolder -= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opSubAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, const MetagenOperatorArithmeticAssign &))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opSubAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder -= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opSubAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, const std::string &))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opSubAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, int)>(mopHolder *= mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opMulAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, int))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opMulAssign, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, const MetagenOperatorArithmeticAssign &)>(mopHolder *= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opMulAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, const MetagenOperatorArithmeticAssign &))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opMulAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder *= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opMulAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, const std::string &))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opMulAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, int)>(mopHolder /= mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opDivAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, int))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opDivAssign, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, const MetagenOperatorArithmeticAssign &)>(mopHolder /= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opDivAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, const MetagenOperatorArithmeticAssign &))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opDivAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder /= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opDivAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, const std::string &))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opDivAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, int)>(mopHolder %= mopHolder);
    _d.CPGF_MD_TEMPLATE _method("_opModAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, int))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opModAssign, cpgf::MakePolicy<cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, const MetagenOperatorArithmeticAssign &)>(mopHolder %= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opModAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, const MetagenOperatorArithmeticAssign &))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opModAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
    _d.CPGF_MD_TEMPLATE _operator<MetagenOperatorArithmeticAssign & (*)(cpgf::GMetaSelf, const std::string &)>(mopHolder %= mopHolder, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1> >());
    _d.CPGF_MD_TEMPLATE _method("_opModAssign", (MetagenOperatorArithmeticAssign & (*) (MetagenOperatorArithmeticAssign *, const std::string &))&opErAToRWrapper_MetagenOperatorArithmeticAssign__opModAssign, cpgf::MakePolicy<cpgf::GMetaRuleCopyConstReference<1>, cpgf::GMetaRuleExplicitThis >());
}


} // namespace meta_test




#include "cpgf/metadata/private/gmetadata_footer.h"


#endif
