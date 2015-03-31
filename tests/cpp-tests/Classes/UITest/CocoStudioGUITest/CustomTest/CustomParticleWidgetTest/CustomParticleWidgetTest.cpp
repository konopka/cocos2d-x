//
//  CustomParticleWidgetTest.cpp
//  CustomUI
//
//  Created by cai wenzhi on 14-3-7.
//
//

#include "CustomParticleWidgetTest.h"
#include <functional>                   // for _Bind
#include <new>                          // for nothrow, operator new
#include "../../CustomGUIScene.h"       // for CustomGUITestScene
#include "../../CustomWidget/CustomParticleWidget.h"
#include "../../CustomWidget/CustomParticleWidgetReader.h"
#include "2d/CCLabel.h"                 // for Label
#include "2d/CCMenu.h"                  // for Menu
#include "2d/CCMenuItem.h"              // for MenuItemLabel
#include "platform/CCPlatformMacros.h" // for USING_NS_CC
#include "GUI/CCControlExtension/../../ExtensionMacros.h"
#include "VisibleRect.h"                // for VisibleRect
#include "base/CCDirector.h"            // for Director
#include "base/ccMacros.h"              // for CC_CALLBACK_1
#include "cocostudio/CCSGUIReader.h"    // for GUIReader, parseselector
#include "math/Vec2.h"                  // for Vec2, Vec2::ZERO
namespace cocos2d { class Ref; }


USING_NS_CC;

using namespace ui;
using namespace cocostudio;


// CustomParticleWidgetLayer


void CustomParticleWidgetLayer::onEnter()
{
    Layer::onEnter();
    
    GUIReader* guiReader = GUIReader::getInstance();
    guiReader->registerTypeAndCallBack("CustomParticleWidget",
                                       &CustomParticleWidget::createInstance,
                                       CustomParticleWidgetReader::getInstance(),
                                       parseselector(CustomParticleWidgetReader::setProperties));
    
    CustomParticleWidget* custom = CustomParticleWidget::create();
    custom->setParticlePlist("Particles/BoilingFoam.plist");
    custom->setPosition(Vec2(VisibleRect::center()));
    addChild(custom, 10, -1);
}


// CustomImageScene


void CustomParticleWidgetScene::onEnter()
{
    Scene::onEnter();
    
    Layer* pLayer = new (std::nothrow) CustomParticleWidgetLayer();
    addChild(pLayer);
    pLayer->release();
    
    auto label = Label::createWithTTF("Back", "fonts/arial.ttf", 20);
    //#endif
    MenuItemLabel* pMenuItem = MenuItemLabel::create(label, CC_CALLBACK_1(CustomParticleWidgetScene::BackCallback, this));
    
    Menu* pMenu = Menu::create(pMenuItem, nullptr);
    
    pMenu->setPosition( Vec2::ZERO );
    pMenuItem->setPosition(VisibleRect::right().x - 50, VisibleRect::bottom().y + 25);
    
    addChild(pMenu, 1);
}

void CustomParticleWidgetScene::runThisTest()
{
    Layer* pLayer = new (std::nothrow) CustomParticleWidgetLayer();
    addChild(pLayer);
    pLayer->release();
    
    Director::getInstance()->replaceScene(this);
}

void CustomParticleWidgetScene::BackCallback(Ref* pSender)
{
    CustomGUITestScene* pScene = new (std::nothrow) CustomGUITestScene();
    pScene->runThisTest();
    pScene->release();
}
