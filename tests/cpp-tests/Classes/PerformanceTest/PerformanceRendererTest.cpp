//
//  PerformanceRendererTest.cpp
//  cocos2d_samples
//
//  Created by Huabing on 1/10/14.
//
//

#include "PerformanceRendererTest.h"
#include <new>                          // for nothrow, operator new
#include "2d/CCScene.h"                 // for Scene
#include "2d/CCTMXTiledMap.h"           // for TMXTiledMap
#include "platform/CCPlatformMacros.h" // for CCLOG, CC_UNUSED
#include "PerformanceTest/PerformanceTest.h"  // for PerformBasicLayer
#include "base/CCDirector.h"            // for Director
#include "math/CCGeometry.h"            // for Size

using namespace cocos2d;

RenderTestLayer::RenderTestLayer()
: PerformBasicLayer(true, 1, 1)
{
}

RenderTestLayer::~RenderTestLayer()
{
}

Scene* RenderTestLayer::scene()
{
    auto scene = Scene::create();
    RenderTestLayer *layer = new (std::nothrow) RenderTestLayer();
    scene->addChild(layer);
    layer->release();
    
    return scene;
}

void RenderTestLayer::onEnter()
{
    PerformBasicLayer::onEnter();
    auto map = cocos2d::TMXTiledMap::create("TileMaps/map/sl.tmx");
    
    Size CC_UNUSED s = map->getContentSize();
    CCLOG("ContentSize: %f, %f", s.width,s.height);
    
    addChild(map,-1);
    
    //map->setAnchorPoint( Vec2(0, 0) );
    //map->setPosition( Vec2(-20,-200) );
}

void RenderTestLayer::showCurrentTest()
{
    
}

void runRendererTest()
{
    auto scene = RenderTestLayer::scene();
	cocos2d::Director::getInstance()->replaceScene(scene);
}
