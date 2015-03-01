#ifndef __DATAVISITOR_TEST_H__
#define __DATAVISITOR_TEST_H__

#include <string>                       // for string
#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC

class PrettyPrinterDemo : public cocos2d::Layer
{
public:
    virtual std::string title() const;
    virtual std::string subtitle() const;
    virtual void onEnter() override;
    void addSprite();
protected:
    std::string    _title;
};

class DataVisitorTestScene : public TestScene
{
public:
    virtual void runThisTest();

    CREATE_FUNC(DataVisitorTestScene);
};

#endif // __DATAVISITOR_TEST_H__
