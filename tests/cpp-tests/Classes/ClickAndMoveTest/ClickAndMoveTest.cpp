#include "ClickAndMoveTest.h"
#include <math.h>                       // for fabs, atanf
#include <functional>                   // for _Bind
#include <new>                          // for nothrow, operator new
#include "../testResource.h"            // for s_pathGrossini
#include "2d/CCActionInterval.h"        // for FadeIn, JumpTo, MoveTo, etc
#include "2d/CCNode.h"                  // for Node
#include "2d/CCSprite.h"                // for Sprite
#include "base/CCDirector.h"            // for Director
#include "base/CCEventDispatcher.h"     // for EventDispatcher
#include "base/CCEventListenerTouch.h"  // for EventListenerTouchOneByOne, etc
#include "base/CCTouch.h"               // for Touch
#include "base/ccMacros.h"              // for CC_CALLBACK_2, etc
#include "base/ccTypes.h"               // for Color4B
#include "math/Vec2.h"                  // for Vec2

using namespace cocos2d;

enum
{
    kTagSprite = 1,
};

void ClickAndMoveTestScene::runThisTest()
{
    auto layer = new (std::nothrow) MainLayer();
    layer->autorelease();

    addChild(layer);
    Director::getInstance()->replaceScene(this);
}

MainLayer::MainLayer()
{
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(MainLayer::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(MainLayer::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto sprite = Sprite::create(s_pathGrossini);
    
    auto layer = LayerColor::create(Color4B(255,255,0,255));
    addChild(layer, -1);
        
    addChild(sprite, 0, kTagSprite);
    sprite->setPosition(20,150);
    
    sprite->runAction( JumpTo::create(4, Vec2(300,48), 100, 4) );
    
    layer->runAction( RepeatForever::create(
                                Sequence::create(
                                        FadeIn::create(1),
                                        FadeOut::create(1),
                                        nullptr)
                      )); 
}

bool MainLayer::onTouchBegan(Touch* touch, Event  *event)
{
    return true;
}

void MainLayer::onTouchEnded(Touch* touch, Event  *event)
{
    auto location = touch->getLocation();

    auto s = getChildByTag(kTagSprite);
    s->stopAllActions();
    s->runAction( MoveTo::create(1, Vec2(location.x, location.y) ) );
    float o = location.x - s->getPosition().x;
    float a = location.y - s->getPosition().y;
    float at = (float) CC_RADIANS_TO_DEGREES( atanf( o/a) );
    
    if( a < 0 ) 
    {
        if(  o < 0 )
            at = 180 + fabs(at);
        else
            at = 180 - fabs(at);    
    }
    
    s->runAction( RotateTo::create(1, at) );
}
