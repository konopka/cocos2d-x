//
//  CustomParticleWidgetTest.h
//  CustomUI
//
//  Created by cai wenzhi on 14-3-7.
//
//

#ifndef __CustomUI__CustomParticleWidgetTest__
#define __CustomUI__CustomParticleWidgetTest__

#include "2d/CCLayer.h"                 // for Layer
#include "2d/CCScene.h"                 // for Scene
namespace cocos2d { class Ref; }

class CustomParticleWidgetLayer : public cocos2d::Layer
{
public:
    virtual void onEnter() override;
};

class CustomParticleWidgetScene : public cocos2d::Scene
{
public:
    virtual void onEnter() override;
    virtual void runThisTest();
    void BackCallback(cocos2d::Ref* pSender);
};

#endif /* defined(__CustomUI__CustomParticleWidgetTest__) */
