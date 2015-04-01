

#ifndef __TestCpp__CustomReader__
#define __TestCpp__CustomReader__

#include <string>                       // for string
#include "base/CCRef.h"                 // for Ref
#include "json/document.h"              // for Value
namespace cocos2d { namespace ui { class Widget; } }

class CustomReader : public cocos2d::Ref
{
public:
    CustomReader();
    ~CustomReader();
    
    static CustomReader* getInstance();
    static void purge();
    
    virtual void setProperties(const std::string& classType, cocos2d::ui::Widget* widget, const rapidjson::Value& customOptions);
};

#endif /* defined(__TestCpp__CustomReader__) */
