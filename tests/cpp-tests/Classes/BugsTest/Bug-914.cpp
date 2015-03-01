//
//  HelloWorldLayer.m
//  EAGLViewBug
//
//  Created by Wylan Werth on 7/5/10.
//  Copyright BanditBear Games 2010. All rights reserved.
//

// Import the interfaces
#include "Bug-914.h"
#include <functional>                   // for _Bind
#include "2d/CCLabel.h"                 // for Label
#include "2d/CCLayer.h"                 // for LayerColor
#include "2d/CCMenu.h"                  // for Menu
#include "2d/CCMenuItem.h"              // for MenuItemFont
#include "2d/CCScene.h"                 // for Scene
#include "BugsTest/BugsTest.h"          // for BugsTestBaseLayer
#include "base/CCConsole.h"             // for log
#include "base/CCDirector.h"            // for Director
#include "base/CCEventDispatcher.h"     // for EventDispatcher
#include "base/CCEventListenerTouch.h"  // for EventListenerTouchAllAtOnce, etc
#include "base/ccMacros.h"              // for CC_CALLBACK_2, etc
#include "base/ccTypes.h"               // for Color4B
#include "math/CCGeometry.h"            // for Size
#include "math/Vec2.h"                  // for Vec2

using namespace cocos2d;

Scene* Bug914Layer::scene()
{
    // 'scene' is an autorelease object.
    auto scene = Scene::create();
    // 'layer' is an autorelease object.
    auto layer = Bug914Layer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Bug914Layer::init()
{
    // always call "super" init
    // Apple recommends to re-assign "self" with the "super" return value
    if (BugsTestBaseLayer::init())
    {
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(Bug914Layer::onTouchesBegan, this);
        listener->onTouchesMoved = CC_CALLBACK_2(Bug914Layer::onTouchesMoved, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        
        // ask director the the window size
        auto size = Director::getInstance()->getWinSize();
        LayerColor *layer;
        for( int i=0;i < 5;i++)
        {
            layer = LayerColor::create(Color4B(i*20, i*20, i*20,255));
            layer->setContentSize(Size(i*100, i*100));
            layer->setPosition(size.width/2, size.height/2);
            layer->setAnchorPoint(Vec2(0.5f, 0.5f));
            layer->ignoreAnchorPointForPosition(false);
            addChild(layer, -1-i);
        }

        // create and initialize a Label
        auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 64.0f);
        auto item1 = MenuItemFont::create("restart", CC_CALLBACK_1(Bug914Layer::restart, this));

        auto menu = Menu::create(item1, nullptr);
        menu->alignItemsVertically();
        menu->setPosition(size.width/2, 100);
        addChild(menu);

        // position the label on the center of the screen
        label->setPosition(size.width /2 , size.height/2);

        // add the label as a child to this Layer
        addChild(label);
        return true;
    }
    return false;
}

void Bug914Layer::onTouchesMoved(const std::vector<Touch*>& touches, Event * event)
{
    log("Number of touches: %d", (int)touches.size());
}

void Bug914Layer::onTouchesBegan(const std::vector<Touch*>& touches, Event * event)
{
    onTouchesMoved(touches, event);
}

void Bug914Layer::restart(Ref* sender)
{
    Director::getInstance()->replaceScene(Bug914Layer::scene());
}
