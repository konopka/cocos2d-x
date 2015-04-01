#ifndef __MOUSE_TEST_H_
#define __MOUSE_TEST_H_

#include <string>                       // for string
#include "../BaseTest.h"                // for BaseTest
#include "../testBasic.h"               // for TestScene
#include "CCPlatformMacros.h"           // for CREATE_FUNC
namespace cocos2d { class Event; }
namespace cocos2d { class EventListenerMouse; }
namespace cocos2d { class Label; }
namespace cocos2d { class Ref; }

class BaseMouseTest : public BaseTest
{
public:
    BaseMouseTest(void);
    virtual ~BaseMouseTest(void);
    
    void restartCallback(cocos2d::Ref* sender) override;
    void nextCallback(cocos2d::Ref* sender) override;
    void backCallback(cocos2d::Ref* sender) override;
    
    // overrides
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual void onEnter() override;
};

class MouseTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

class MouseEventTest : public BaseMouseTest
{
public:
    CREATE_FUNC(MouseEventTest);
    MouseEventTest();
    ~MouseEventTest();

    void onMouseDown(cocos2d::Event* event);
    void onMouseUp(cocos2d::Event* event);
    void onMouseMove(cocos2d::Event* event);
    void onMouseScroll(cocos2d::Event* event);

    virtual std::string title() const override;
    virtual std::string subtitle() const override;

private:
	cocos2d::Label*   _labelAction;
	cocos2d::Label*   _labelPosition;
	cocos2d::EventListenerMouse* _mouseListener;
};

class HideMouseTest : public BaseMouseTest
{
public:
    CREATE_FUNC(HideMouseTest);
    HideMouseTest();
    ~HideMouseTest();
    
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    
private:
    cocos2d::EventListenerMouse* _lis;
};

#endif
