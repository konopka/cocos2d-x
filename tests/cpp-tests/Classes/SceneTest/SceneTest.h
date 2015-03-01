#ifndef _SCENE_TEST_H_
#define _SCENE_TEST_H_

#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer, LayerColor
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC

using namespace cocos2d;

class SceneTestLayer1 : public cocos2d::Layer
{
public:
    SceneTestLayer1();
    ~SceneTestLayer1();

    virtual void onEnter() override;
    virtual void onEnterTransitionDidFinish() override;

    void testDealloc(float dt);
    void onPushScene(cocos2d::Ref* sender);
    void onPushSceneTran(cocos2d::Ref* sender);
    void onQuit(cocos2d::Ref* sender);

    //CREATE_NODE(SceneTestLayer1);
} ;

class SceneTestLayer2 : public cocos2d::Layer
{
    float    _timeCounter;
public:
    SceneTestLayer2();

    void testDealloc(float dt);
    void onGoBack(cocos2d::Ref* sender);
    void onReplaceScene(cocos2d::Ref* sender);
    void onReplaceSceneTran(cocos2d::Ref* sender);

    //CREATE_NODE(SceneTestLayer2);
} ;

class SceneTestLayer3 : public LayerColor
{
public:
    SceneTestLayer3();
    bool init();
    virtual void testDealloc(float dt);
    void item0Clicked(cocos2d::Ref* sender);
    void item1Clicked(cocos2d::Ref* sender);
    void item2Clicked(cocos2d::Ref* sender);
    void item3Clicked(cocos2d::Ref* sender);
    CREATE_FUNC(SceneTestLayer3)
} ;

class SceneTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif
