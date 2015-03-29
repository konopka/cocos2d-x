

#ifndef __TestCpp__CustomImageScene__
#define __TestCpp__CustomImageScene__

#include "2d/CCLayer.h"                 // for Layer
#include "../../../../testBasic.h"
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
