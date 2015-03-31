

#include "CustomReader.h"
#include <new>                          // for nothrow, operator new
#include "CustomImageView.h"            // for CustomImageView
#include "cocostudio/DictionaryHelper.h"  // for DICTOOL, DictionaryHelper

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;

static CustomReader* _instanceCustomReader = nullptr;

CustomReader::CustomReader()
{
    
}

CustomReader::~CustomReader()
{
    
}

CustomReader* CustomReader::getInstance()
{
    if (!_instanceCustomReader)
    {
        _instanceCustomReader = new (std::nothrow) CustomReader();
    }
    return _instanceCustomReader;
}

void CustomReader::setProperties(const std::string &classType, Widget *widget, const rapidjson::Value &customOptions)
{
    if (classType.compare("CustomImageView") == 0)
    {
        CustomImageView* customImageView = static_cast<CustomImageView*>(widget);
        
        bool isExistText = DICTOOL->getBooleanValue_json(customOptions, "text");
        if (isExistText)
        {
            const char* text = DICTOOL->getStringValue_json(customOptions, "text");
            customImageView->setText(text);
        }
    }
}
