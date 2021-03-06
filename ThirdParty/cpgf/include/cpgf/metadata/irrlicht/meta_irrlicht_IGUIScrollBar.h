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

#ifndef __META_IRRLICHT_IGUISCROLLBAR_H
#define __META_IRRLICHT_IGUISCROLLBAR_H


#include "gmetaobjectlifemanager_irrlicht_ireferencecounted.h"
#include "cpgf/gmetadefine.h"
#include "cpgf/metadata/gmetadataconfig.h"
#include "cpgf/metadata/private/gmetadata_header.h"
#include "cpgf/gmetapolicy.h"


using namespace irr;
using namespace irr::gui;


namespace meta_irrlicht { 


template <typename D>
void buildMetaClass_IGUIScrollBar(const cpgf::GMetaDataConfigFlags & config, D _d)
{
    (void)config; (void)_d; (void)_d;
    using namespace cpgf;
    
    _d.CPGF_MD_TEMPLATE _method("setMax", &D::ClassType::setMax);
    _d.CPGF_MD_TEMPLATE _method("getMax", &D::ClassType::getMax);
    _d.CPGF_MD_TEMPLATE _method("setMin", &D::ClassType::setMin);
    _d.CPGF_MD_TEMPLATE _method("getMin", &D::ClassType::getMin);
    _d.CPGF_MD_TEMPLATE _method("getSmallStep", &D::ClassType::getSmallStep);
    _d.CPGF_MD_TEMPLATE _method("setSmallStep", &D::ClassType::setSmallStep);
    _d.CPGF_MD_TEMPLATE _method("getLargeStep", &D::ClassType::getLargeStep);
    _d.CPGF_MD_TEMPLATE _method("setLargeStep", &D::ClassType::setLargeStep);
    _d.CPGF_MD_TEMPLATE _method("getPos", &D::ClassType::getPos);
    _d.CPGF_MD_TEMPLATE _method("setPos", &D::ClassType::setPos);
}


} // namespace meta_irrlicht




#include "cpgf/metadata/private/gmetadata_footer.h"


#endif
