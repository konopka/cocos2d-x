
#include "CustomImageTest.h"
#include <functional>                   // for _Bind
#include <new>                          // for nothrow, operator new
#include "../../CustomGUIScene.h"       // for CustomGUITestScene
#include "../../CustomWidget/CustomImageView.h"  // for CustomImageView
#include "../../CustomWidget/CustomImageViewReader.h"
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
#include "ui/UILayout.h"                // for Layout

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace cocostudio;

void CustomImageLayer::onEnter()
{
    Layer::onEnter();
    
    GUIReader* guiReader = GUIReader::getInstance();
    guiReader->registerTypeAndCallBack("CustomImageView",
                                       &CustomImageView::createInstance,
                                       CustomImageViewReader::getInstance(),
                                       parseselector(CustomImageViewReader::setProperties));
    
    Layout* layout = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("cocosui/CustomImageViewTest/NewProject_2_1.ExportJson"));
    addChild(layout);        
}


// CustomImageScene


void CustomImageScene::onEnter()
{
    Scene::onEnter();
    
    auto label = Label::createWithTTF("Back", "fonts/arial.ttf", 20);
    //#endif
    MenuItemLabel* pMenuItem = MenuItemLabel::create(label, CC_CALLBACK_1(CustomImageScene::BackCallback, this));
    
    Menu* pMenu = Menu::create(pMenuItem, nullptr);
    
    pMenu->setPosition( Vec2::ZERO );
    pMenuItem->setPosition(VisibleRect::right().x - 50, VisibleRect::bottom().y + 25);
    
    addChild(pMenu, 1);
}

void CustomImageScene::runThisTest()
{
    Layer* pLayer = new (std::nothrow) CustomImageLayer();
    addChild(pLayer);
    pLayer->release();
    
    Director::getInstance()->replaceScene(this);
}

void CustomImageScene::BackCallback(Ref* pSender)
{
    CustomGUITestScene* pScene = new (std::nothrow) CustomGUITestScene();
    pScene->runThisTest();
    pScene->release();
}
