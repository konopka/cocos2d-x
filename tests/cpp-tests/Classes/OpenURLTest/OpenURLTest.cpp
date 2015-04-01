#include "OpenURLTest.h"
#include <functional>                   // for _Bind
#include <new>                          // for nothrow, operator new
#include "2d/CCLabel.h"                 // for Label
#include "VisibleRect.h"                // for VisibleRect
#include "base/CCDirector.h"            // for Director
#include "base/CCEventDispatcher.h"     // for EventDispatcher
#include "base/CCEventListenerTouch.h"  // for EventListenerTouchAllAtOnce, etc
#include "base/ccMacros.h"              // for CC_CALLBACK_2
#include "platform/CCApplication.h"		// for Application
#include "math/Vec2.h"                  // for Vec2

using namespace cocos2d;

OpenURLTest::OpenURLTest()
{
    auto label = Label::createWithTTF("Open URL Test", "fonts/arial.ttf", 28);
    addChild(label, 0);
    label->setPosition(VisibleRect::center().x, VisibleRect::top().y - 50);

    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesEnded = CC_CALLBACK_2(OpenURLTest::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    // create a label to display the tip string
    _label = Label::createWithTTF("Touch the screen to open\nthe cocos2d-x home page", "fonts/arial.ttf", 22);
    _label->setPosition(VisibleRect::center());
    addChild(_label, 0);

    _label->retain();
}

void OpenURLTest::onTouchesEnded(const std::vector<Touch*>& touches, Event  *event)
{
    Application::getInstance()->openURL("http://www.cocos2d-x.org/");
}

OpenURLTest::~OpenURLTest()
{
    _label->release();
}

void OpenURLTestScene::runThisTest()
{
    auto layer = new (std::nothrow) OpenURLTest();
    addChild(layer);

    Director::getInstance()->replaceScene(this);
    layer->release();
}
