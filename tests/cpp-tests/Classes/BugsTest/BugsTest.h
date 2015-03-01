#ifndef __BUGS_TEST_H__
#define __BUGS_TEST_H__

#include "../testBasic.h"
#include "2d/CCLayer.h"

namespace cocos2d {	class Vec2; }
namespace cocos2d { class Menu; }

class BugsTestMainLayer : public cocos2d::Layer
{
public:
    virtual void onEnter() override;

    void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event) override;
    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event) override;

protected:
	cocos2d::Vec2 _beginPos;
	cocos2d::Menu* _itmeMenu;
};

class BugsTestBaseLayer : public cocos2d::Layer
{
public:
    virtual void onEnter() override;
    void backCallback(cocos2d::Ref* sender);
};

class BugsTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif
