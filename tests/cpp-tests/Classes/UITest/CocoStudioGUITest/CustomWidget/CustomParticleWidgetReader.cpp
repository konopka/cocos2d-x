//
//  CustomParticleWidgetReader.cpp
//  CustomUI
//
//  Created by cai wenzhi on 14-3-7.
//
//

#include "CustomParticleWidgetReader.h"
#include <new>                          // for nothrow, operator new
#include "CustomParticleWidget.h"       // for CustomParticleWidget
#include "cocostudio/CCSGUIReader.h"    // for GUIReader
#include "cocostudio/DictionaryHelper.h"  // for DICTOOL, DictionaryHelper

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;

CustomParticleWidgetReader::CustomParticleWidgetReader()
{
    
}

CustomParticleWidgetReader::~CustomParticleWidgetReader()
{
    
}

static CustomParticleWidgetReader* _instanceCustomParticleWidgetReader = nullptr;

CustomParticleWidgetReader* CustomParticleWidgetReader::getInstance()
{
    if (!_instanceCustomParticleWidgetReader)
    {
        _instanceCustomParticleWidgetReader = new (std::nothrow) CustomParticleWidgetReader();
    }
    return _instanceCustomParticleWidgetReader;
}

void CustomParticleWidgetReader::setProperties(const std::string& classType,
                                          Widget *widget,
                                          const rapidjson::Value &customOptions)
{
    GUIReader* guiReader = GUIReader::getInstance();
    
    CustomParticleWidget* custom = static_cast<CustomParticleWidget*>(widget);
    
    bool isExistPlistFile = DICTOOL->checkObjectExist_json(customOptions, "PlistFile");
    if (isExistPlistFile)
    {
        const char* PlistFile = DICTOOL->getStringValue_json(customOptions, "PlistFile");
        std::string PlistFilePath = guiReader->getFilePath();
        PlistFilePath.append(PlistFile);
        custom->setParticlePlist(PlistFilePath.c_str());
        
    }
}
