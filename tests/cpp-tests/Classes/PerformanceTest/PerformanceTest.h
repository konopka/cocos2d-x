#ifndef __PERFORMANCE_TEST_H__
#define __PERFORMANCE_TEST_H__

#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer
#include "math/Vec2.h"                  // for Vec2
namespace cocos2d { class Event; }
namespace cocos2d { class Menu; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Touch; }

class PerformanceMainLayer : public cocos2d::Layer
{
public:
    virtual void onEnter() override;
    
    bool onTouchBegan(cocos2d::Touch* touches, cocos2d::Event *event) override;
    void onTouchMoved(cocos2d::Touch* touches, cocos2d::Event *event) override;
    
    void onMouseScroll(cocos2d::Event *event);
protected:
    cocos2d::Vec2 _beginPos;
    cocos2d::Menu* _itemMenu;
    
    static cocos2d::Vec2 _CurrentPos;
};

class PerformBasicLayer : public cocos2d::Layer
{
public:
    PerformBasicLayer(bool bControlMenuVisible, int nMaxCases = 0, int nCurCase = 0);

    virtual void onEnter() override;

    virtual void restartCallback(cocos2d::Ref* sender);
    virtual void nextCallback(cocos2d::Ref* sender);
    virtual void backCallback(cocos2d::Ref* sender);
    virtual void showCurrentTest() = 0;

    virtual void toMainLayer(cocos2d::Ref* sender);

protected:
    bool _controlMenuVisible;
    int  _maxCases;
    int  _curCase;
};

class PerformanceTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif
