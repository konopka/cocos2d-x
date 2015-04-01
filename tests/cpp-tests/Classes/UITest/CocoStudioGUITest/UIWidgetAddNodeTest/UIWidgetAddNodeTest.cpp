

#include "UIWidgetAddNodeTest.h"
#include "2d/CCLayer.h"                 // for Layer
#include "2d/CCSprite.h"                // for Sprite
#include "UITest/CocoStudioGUITest/UIWidgetAddNodeTest/../UIScene.h"
#include "base/ccTypes.h"               // for Color3B
#include "math/CCGeometry.h"            // for Size, Rect
#include "math/Vec2.h"                  // for Vec2
#include "ui/UILayout.h"                // for Layout
#include "ui/UIText.h"                  // for Text
#include "ui/UIWidget.h"                // for Widget

using namespace cocos2d;
using namespace cocos2d::ui;

// UIWidgetAddNodeTest

UIWidgetAddNodeTest::UIWidgetAddNodeTest()
{
    
}

UIWidgetAddNodeTest::~UIWidgetAddNodeTest()
{
}

bool UIWidgetAddNodeTest::init()
{
    if (UIScene::init())
    {
        Size widgetSize = _widget->getContentSize();
        
        // Add the alert
        Text* alert = Text::create();
        alert->setString("Widget Add Node");
        alert->setFontName("fonts/Marker Felt.ttf");
        alert->setFontSize(30);
        alert->setColor(Color3B(159, 168, 176));
        alert->setPosition(Vec2(widgetSize.width / 2.0f, widgetSize.height / 2.0f - alert->getContentSize().height * 1.75));
        _uiLayer->addChild(alert);
        
        // Create the ui node container
        Widget* widget = Widget::create();
        widget->setPosition(Vec2(widgetSize.width / 2.0f, widgetSize.height / 2.0f));
        _uiLayer->addChild(widget);
        
        Sprite* sprite = Sprite::create("cocosui/ccicon.png");
        sprite->setPosition(Vec2(0, sprite->getBoundingBox().size.height / 4));
        widget->addChild(sprite);
        
        return true;
    }
    return false;
}
