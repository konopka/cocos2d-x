#ifndef __ZWOPTEX_TEST_H__
#define __ZWOPTEX_TEST_H__

#include <string>                       // for string
#include "../BaseTest.h"                // for BaseTest
#include "../testBasic.h"               // for TestScene
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC
namespace cocos2d { class Ref; }
namespace cocos2d { class Sprite; }

class ZwoptexTest : public BaseTest
{
public:
    virtual void onEnter() override;

    void restartCallback(cocos2d::Ref* sender) override;
    void nextCallback(cocos2d::Ref* sender) override;
    void backCallback(cocos2d::Ref* sender) override;

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class ZwoptexGenericTest : public ZwoptexTest
{
public:
    ~ZwoptexGenericTest();
    virtual void onEnter() override;
    void flipSprites(float dt);
    void startIn05Secs(float dt);

    virtual std::string title() const override;
    virtual std::string subtitle() const override;

protected:
	cocos2d::Sprite * sprite1;
	cocos2d::Sprite * sprite2;
    int counter;
};

class ZwoptexTestScene : public TestScene
{
public:
    virtual void runThisTest();

    CREATE_FUNC(ZwoptexTestScene);
};

#endif // __ZWOPTEX_TEST_H__
