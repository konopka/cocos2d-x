//
// Bug-624
// http://code.google.com/p/cocos2d-iphone/issues/detail?id=624
//

#include "Bug-624.h"
#include <functional>                   // for _Bind
#include "2d/CCLabel.h"                 // for Label
#include "2d/CCScene.h"                 // for Scene
#include "2d/CCTransition.h"            // for TransitionFade
#include "BugsTest/BugsTest.h"          // for BugsTestBaseLayer
#include "CCDevice.h"                   // for Device
#include "base/CCConsole.h"             // for log
#include "base/CCDirector.h"            // for Director
#include "base/CCEventDispatcher.h"     // for EventDispatcher
#include "base/CCEventListenerAcceleration.h"
#include "base/CCRef.h"                 // for CC_SCHEDULE_SELECTOR
#include "base/ccMacros.h"              // for CC_CALLBACK_2
#include "base/ccTypes.h"               // for Acceleration (ptr only), etc
#include "math/CCGeometry.h"            // for Size

using namespace cocos2d;

////////////////////////////////////////////////////////
//
// Bug624Layer
//
////////////////////////////////////////////////////////
Bug624Layer::~Bug624Layer()
{
    Device::setAccelerometerEnabled(false);
}

bool Bug624Layer::init()
{
    if(BugsTestBaseLayer::init())
    {
        auto size = Director::getInstance()->getWinSize();
        auto label = Label::createWithTTF("Layer1", "fonts/Marker Felt.ttf", 36.0f);

        label->setPosition(size.width/2, size.height/2);
        addChild(label);
        
        Device::setAccelerometerEnabled(true);
        auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(Bug624Layer::onAcceleration,  this));
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

        schedule(CC_SCHEDULE_SELECTOR(Bug624Layer::switchLayer), 5.0f);

        return true;
    }
    
    return false;
}

void Bug624Layer::switchLayer(float dt)
{
    unschedule(CC_SCHEDULE_SELECTOR(Bug624Layer::switchLayer));

    auto scene = Scene::create();    
    scene->addChild(Bug624Layer2::create(), 0);
    Director::getInstance()->replaceScene(TransitionFade::create(2.0f, scene, Color3B::WHITE));
}

void Bug624Layer::onAcceleration(Acceleration* acc, Event* event)
{    
    log("Layer1 accel");
}

////////////////////////////////////////////////////////
//
// Bug624Layer2
//
////////////////////////////////////////////////////////
Bug624Layer2::~Bug624Layer2()
{
    Device::setAccelerometerEnabled(false);
}

bool Bug624Layer2::init()
{
    if(BugsTestBaseLayer::init())
    {
        auto size = Director::getInstance()->getWinSize();
        auto label = Label::createWithTTF("Layer2", "fonts/Marker Felt.ttf", 36.0f);

        label->setPosition(size.width/2, size.height/2);
        addChild(label);
        
        Device::setAccelerometerEnabled(true);
        auto listener = EventListenerAcceleration::create(CC_CALLBACK_2(Bug624Layer2::onAcceleration, this));
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        
        
        schedule(CC_SCHEDULE_SELECTOR(Bug624Layer2::switchLayer), 5.0f);

        return true;
    }

    return false;
}

void Bug624Layer2::switchLayer(float dt)
{
    unschedule(CC_SCHEDULE_SELECTOR(Bug624Layer::switchLayer));

    auto scene = Scene::create();    
    scene->addChild(Bug624Layer::create(), 0);
    Director::getInstance()->replaceScene(TransitionFade::create(2.0f, scene, Color3B::RED));
}

void Bug624Layer2::onAcceleration(Acceleration* acc, Event* event)
{    
    log("Layer2 accel");
}
