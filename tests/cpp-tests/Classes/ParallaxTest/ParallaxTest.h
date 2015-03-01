#ifndef _PARALLAX_TEST_H_
#define _PARALLAX_TEST_H_

#include <sys/types.h>                  // for ssize_t
#include <string>                       // for string
#include <vector>                       // for vector
#include "../BaseTest.h"                // for BaseTest
#include "../testBasic.h"               // for TestScene
#include "2d/CCSprite.h"                // for Sprite
#include "base/CCVector.h"              // for Vector
#include "math/Vec2.h"                  // for Vec2
namespace cocos2d { class Event; }
namespace cocos2d { class MotionStreak; }
namespace cocos2d { class Node; }
namespace cocos2d { class ParallaxNode; }
namespace cocos2d { class Ref; }
namespace cocos2d { class TextureAtlas; }
namespace cocos2d { class Touch; }

class ParallaxDemo : public BaseTest
{
protected:
    cocos2d::TextureAtlas* _atlas;

public:
    ParallaxDemo(void);
    ~ParallaxDemo(void);

    virtual std::string title() const override;
    virtual void onEnter() override;

    void restartCallback(cocos2d::Ref* sender) override;
    void nextCallback(cocos2d::Ref* sender) override;
    void backCallback(cocos2d::Ref* sender) override;
};

class Parallax1 : public ParallaxDemo
{
protected:
    cocos2d::Node*        _root;
    cocos2d::Node*        _target;
    cocos2d::MotionStreak*        _streak;

public:
    Parallax1();
    virtual std::string title() const override;
};

class Parallax2 : public ParallaxDemo
{
protected:
    cocos2d::Node*        _root;
    cocos2d::Node*        _target;
    cocos2d::MotionStreak*        _streak;

public:
    Parallax2();
    
    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event) override;

    virtual std::string title() const override;
};

class Issue2572 : public ParallaxDemo
{
protected:
	cocos2d::ParallaxNode* _paraNode;
    float _moveTimer;
    float _addTimer;
	cocos2d::Vector<cocos2d::Sprite*> _childList;
    ssize_t _preListSize;
    int _printCount;
    
    float _addChildStep;
    float _wholeMoveTime;
	cocos2d::Vec2 _wholeMoveSize;

    virtual void update(float dt) override;
    
public:
    Issue2572();
    
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class ParallaxTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif
