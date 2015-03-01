#ifndef _OPEN_URL_TEST_H_
#define _OPEN_URL_TEST_H_

#include <vector>                       // for vector
#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer
namespace cocos2d { class Event; }
namespace cocos2d { class Label; }
namespace cocos2d { class Touch; }

class OpenURLTest : public cocos2d::Layer
{
public:
    OpenURLTest();
    ~OpenURLTest();

    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event  *event);
private:
    cocos2d::Label* _label;
};

class OpenURLTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif // _OPEN_URL_TEST_H_
