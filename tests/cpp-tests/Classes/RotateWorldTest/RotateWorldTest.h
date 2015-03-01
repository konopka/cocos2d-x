#ifndef _ROTATE_WORLD_TEST_H_
#define _ROTATE_WORLD_TEST_H_

#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC

class RotateWorldTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

class SpriteLayer : public cocos2d::Layer
{
public:
    virtual void onEnter() override;
    CREATE_FUNC(SpriteLayer)
};

class TestLayer : public cocos2d::Layer
{
public:
    virtual void onEnter() override;

    CREATE_FUNC(TestLayer)
};

class RotateWorldMainLayer : public cocos2d::Layer
{
public:
    virtual void onEnter() override;

    CREATE_FUNC(RotateWorldMainLayer)
};

#endif
