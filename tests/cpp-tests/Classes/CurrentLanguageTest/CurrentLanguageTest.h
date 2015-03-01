#ifndef _CURRENT_LANGUAGE_TEST_H_
#define _CURRENT_LANGUAGE_TEST_H_

#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer

class CurrentLanguageTest : public cocos2d::Layer
{
public:
    CurrentLanguageTest();
};

class CurrentLanguageTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif // _CURRENT_LANGUAGE_TEST_H_
