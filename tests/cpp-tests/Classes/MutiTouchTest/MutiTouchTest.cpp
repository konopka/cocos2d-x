#include "MutiTouchTest.h"
#include <functional>                   // for _Bind
#include <new>                          // for nothrow, operator new
#include "2d/CCDrawNode.h"              // for DrawNode
#include "2d/CCLabel.h"                 // for Label
#include "2d/CCNode.h"                  // for Node
#include "VisibleRect.h"                // for VisibleRect
#include "base/CCDirector.h"            // for Director
#include "base/CCEventDispatcher.h"     // for EventDispatcher
#include "base/CCEventListenerTouch.h"  // for EventListenerTouchAllAtOnce, etc
#include "base/CCMap.h"                 // for Map
#include "base/CCTouch.h"               // for Touch
#include "base/ccMacros.h"              // for CC_CALLBACK_2
#include "base/ccTypes.h"               // for Color3B, Color3B::BLUE, etc
#include "math/CCGeometry.h"            // for Size
#include "math/Vec2.h"                  // for Vec2

using namespace cocos2d;

static const Color3B* s_TouchColors[5] = {
    &Color3B::YELLOW,
    &Color3B::BLUE,
    &Color3B::GREEN,
    &Color3B::RED,
    &Color3B::MAGENTA
};

class TouchPoint : public Node
{
public:
    TouchPoint(const Vec2 &touchPoint, const Color3B &touchColor)
    {
        DrawNode* drawNode = DrawNode::create();
        auto s = Director::getInstance()->getWinSize();
        Color4F color(touchColor.r/255.0f, touchColor.g/255.0f, touchColor.b/255.0f, 1.0f);
        drawNode->drawLine(Vec2(0, touchPoint.y), Vec2(s.width, touchPoint.y), color);
        drawNode->drawLine(Vec2(touchPoint.x, 0), Vec2(touchPoint.x, s.height), color);
        drawNode->drawDot(touchPoint, 3, color);
        addChild(drawNode);
    }

    static TouchPoint* touchPointWithParent(Node* pParent, const Vec2 &touchPoint, const Color3B &touchColor)
    {
        auto pRet = new (std::nothrow) TouchPoint(touchPoint, touchColor);
        pRet->setContentSize(pParent->getContentSize());
        pRet->setAnchorPoint(Vec2(0.0f, 0.0f));
        pRet->autorelease();
        return pRet;
    }
};

bool MutiTouchTestLayer::init()
{
    if (Layer::init())
    {
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(MutiTouchTestLayer::onTouchesBegan, this);
        listener->onTouchesMoved = CC_CALLBACK_2(MutiTouchTestLayer::onTouchesMoved, this);
        listener->onTouchesEnded = CC_CALLBACK_2(MutiTouchTestLayer::onTouchesEnded, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        
        auto title = Label::createWithSystemFont("Please touch the screen!", "", 24);
        title->setPosition(VisibleRect::top()+Vec2(0, -40));
        addChild(title);
        
        return true;
    }
    return false;
}

static Map<int, TouchPoint*> s_map;

void MutiTouchTestLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
    for ( auto &item: touches )
    {
        auto touch = item;
        auto location = touch->getLocation();
        auto touchPoint = TouchPoint::touchPointWithParent(this, location, *s_TouchColors[touch->getID()%5]);

        addChild(touchPoint);
        s_map.insert(touch->getID(), touchPoint);
    }
}

void MutiTouchTestLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
{
    for( auto &item: touches)
    {
        auto touch = item;
        auto pTP = s_map.at(touch->getID());
        auto location = touch->getLocation();
        
        removeChild(pTP, true);
        s_map.erase(touch->getID());
        
        auto touchPointNew = TouchPoint::touchPointWithParent(this, location, *s_TouchColors[touch->getID()%5]);
        addChild(touchPointNew);
        s_map.insert(touch->getID(), touchPointNew);
    }
}

void MutiTouchTestLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event  *event)
{
    for ( auto &item: touches )
    {
        auto touch = item;
        auto pTP = s_map.at(touch->getID());
        removeChild(pTP, true);
        s_map.erase(touch->getID());
    }
}

void MutiTouchTestLayer::onTouchesCancelled(const std::vector<Touch*>& touches, Event  *event)
{
    onTouchesEnded(touches, event);
}

void MutiTouchTestScene::runThisTest()
{
    auto layer = MutiTouchTestLayer::create();

    addChild(layer, 0);

    Director::getInstance()->replaceScene(this);
}
