#ifndef _FONT_TEST_H_
#define _FONT_TEST_H_

#include <string>                       // for string
#include "../BaseTest.h"                // for BaseTest
#include "../testBasic.h"               // for TestScene
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC
namespace cocos2d { class Ref; }

class FontTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

class FontTest : public BaseTest
{
public:
    FontTest();
    void showFont(const char *pFont);

    void restartCallback(cocos2d::Ref* sender) override;
    void nextCallback(cocos2d::Ref* sender) override;
    void backCallback(cocos2d::Ref* sender) override;
    virtual std::string title() const override;

    CREATE_FUNC(FontTest);
};

#endif // _FONT_TEST_H_
