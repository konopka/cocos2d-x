#ifndef _CURL_TEST_H_
#define _CURL_TEST_H_

#include <vector>                       // for vector
#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer
namespace cocos2d { class Event; }
namespace cocos2d { class Label; }
namespace cocos2d { class Touch; }

class CurlTest : public cocos2d::Layer
{
public:
    CurlTest();
    ~CurlTest();

    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event  *event);

private:
    cocos2d::Label*         _label;
};

class CurlTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif // _CURL_TEST_H_
