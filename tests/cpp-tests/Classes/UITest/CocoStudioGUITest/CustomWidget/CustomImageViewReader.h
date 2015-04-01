

#ifndef __TestCpp__CustomImageViewReader__
#define __TestCpp__CustomImageViewReader__

#include <string>                       // for string
#include "base/CCRef.h"                 // for Ref
#include "json/document.h"              // for Value
namespace cocos2d { namespace ui { class Widget; } }

class CustomImageViewReader : public cocos2d::Ref
{
public:
    
    CustomImageViewReader();
    ~CustomImageViewReader();
    
    static CustomImageViewReader* getInstance();
    static void purge();
    
    virtual void setProperties(const std::string& classType, cocos2d::ui::Widget* widget, const rapidjson::Value& customOptions);
};

#endif /* defined(__TestCpp__CustomImageViewReader__) */
