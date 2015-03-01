#ifndef _USERDEFAULT_TEST_H_
#define _USERDEFAULT_TEST_H_

#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer

class UserDefaultTest : public cocos2d::Layer
{
public:
    UserDefaultTest();
    ~UserDefaultTest();

private:
    void doTest();
};

class UserDefaultTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif // _USERDEFAULT_TEST_H_
