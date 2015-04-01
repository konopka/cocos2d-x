

#include "UITextBMFontTest.h"
#include "2d/CCLayer.h"                 // for Layer
#include "UITest/CocoStudioGUITest/UITextBMFontTest/../UIScene.h"
#include "base/ccTypes.h"               // for Color3B
#include "math/CCGeometry.h"            // for Size
#include "math/Vec2.h"                  // for Vec2
#include "ui/UILayout.h"                // for Layout
#include "ui/UIText.h"                  // for Text
#include "ui/UITextBMFont.h"            // for TextBMFont

using namespace cocos2d;
using namespace cocos2d::ui;

// UITextBMFontTest

bool UITextBMFontTest::init()
{
    if (UIScene::init())
    {
        Size widgetSize = _widget->getContentSize();
        
        Text* alert = Text::create("TextBMFont","TextBMFont",30);
        alert->setColor(Color3B(159, 168, 176));
        alert->setPosition(Vec2(widgetSize.width / 2.0f, widgetSize.height / 2.0f - alert->getContentSize().height * 1.75f));
        _uiLayer->addChild(alert);
        
        // Create the TextBMFont
        TextBMFont* textBMFont = TextBMFont::create("BMFont", "cocosui/bitmapFontTest2.fnt");
        textBMFont->setPosition(Vec2(widgetSize.width / 2, widgetSize.height / 2.0f + textBMFont->getContentSize().height / 8.0f));
        _uiLayer->addChild(textBMFont);
        
        return true;
    }
    return false;
}
