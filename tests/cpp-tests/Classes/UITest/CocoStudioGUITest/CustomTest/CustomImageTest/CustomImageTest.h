

#ifndef __TestCpp__CustomImageScene__
#define __TestCpp__CustomImageScene__

#include "../../../../testBasic.h"      // for TestScene
#include "2d/CCLayer.h"                 // for Layer
namespace cocos2d { class Ref; }

class CustomImageLayer : public cocos2d::Layer
{
public:
    virtual void onEnter() override;
};

class CustomImageScene : public TestScene
{
public:
    virtual void onEnter() override;
    virtual void runThisTest();
    void BackCallback(cocos2d::Ref* pSender);
};

#endif /* defined(__TestCpp__CustomUIScene__) */
