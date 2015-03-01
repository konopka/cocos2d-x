//
//  PerformanceRendererTest.h
//  cocos2d_samples
//
//  Created by Huabing on 1/10/14.
//
//

#ifndef __PERFORMANCE_RENDERER_TEST_H__
#define __PERFORMANCE_RENDERER_TEST_H__

#include "PerformanceTest.h"            // for PerformBasicLayer
namespace cocos2d { class Scene; }

class RenderTestLayer : public PerformBasicLayer
{
    
public:
    RenderTestLayer();
    virtual ~RenderTestLayer();
    
    virtual void onEnter() override;
    virtual void showCurrentTest() override;
public:
    static cocos2d::Scene* scene();
};

void runRendererTest();
#endif
