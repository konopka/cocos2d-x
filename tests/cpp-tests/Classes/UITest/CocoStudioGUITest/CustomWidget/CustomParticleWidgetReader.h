//
//  CustomParticleWidgetReader.h
//  CustomUI
//
//  Created by cai wenzhi on 14-3-7.
//
//

#ifndef __CustomUI__CustomParticleWidgetReader__
#define __CustomUI__CustomParticleWidgetReader__

#include <string>                       // for string
#include "base/CCRef.h"                 // for Ref
#include "json/document.h"              // for Value
namespace cocos2d { namespace ui { class Widget; } }

class CustomParticleWidgetReader : public cocos2d::Ref
{
public:
    CustomParticleWidgetReader();
    ~CustomParticleWidgetReader();
    
    static CustomParticleWidgetReader* getInstance();
    static void purge();
    
    virtual void setProperties(const std::string& classType, cocos2d::ui::Widget* widget, const rapidjson::Value& customOptions);
};

#endif /* defined(__CustomUI__CustomParticleWidgetReader__) */
