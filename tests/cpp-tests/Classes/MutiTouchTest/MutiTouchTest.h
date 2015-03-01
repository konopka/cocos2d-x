#ifndef __MUTITOUCHTEST_H__
#define __MUTITOUCHTEST_H__

#include <vector>                       // for vector
#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC
namespace cocos2d { class Event; }
namespace cocos2d { class Touch; }

class MutiTouchTestLayer : public cocos2d::Layer
{
public:
    bool init();

    void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event  *event);
    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event  *event);
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event  *event);
    void onTouchesCancelled(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event  *event);

    CREATE_FUNC(MutiTouchTestLayer)
};

class MutiTouchTestScene : public TestScene
{
 public:
  virtual void runThisTest();
};

#endif /* __MUTITOUCHTEST_H__ */
