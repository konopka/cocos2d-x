

#include "CustomWidgetCallbackBindTest.h"
#include <functional>                   // for _Bind
#include <new>                          // for nothrow, operator new
#include "../../CustomGUIScene.h"       // for CustomGUITestScene
#include "2d/CCLabel.h"                 // for Label
#include "2d/CCMenu.h"                  // for Menu
#include "2d/CCMenuItem.h"              // for MenuItemLabel
#include "2d/CCScene.h"                 // for Scene
#include "platform/CCPlatformMacros.h" // for USING_NS_CC
#include "CustomRootNodeReader.h"       // for CustomRootNodeReader
#include "VisibleRect.h"                // for VisibleRect
#include "base/CCDirector.h"            // for Director
#include "base/ObjectFactory.h"         // for ObjectFactory, etc
#include "base/ccMacros.h"              // for CC_CALLBACK_1
#include "cocostudio/ActionTimeline/CSLoader.h"  // for CSLoader
#include "math/Vec2.h"                  // for Vec2, Vec2::ZERO

using namespace cocos2d;
using namespace flatbuffers;

void CustomWidgetCallbackBindScene::onEnter()
{
    Scene::onEnter();
    
    auto label = Label::createWithTTF("Back", "fonts/arial.ttf", 20);
    //#endif
    MenuItemLabel* pMenuItem = MenuItemLabel::create(label, CC_CALLBACK_1(CustomWidgetCallbackBindScene::BackCallback, this));
    
    Menu* pMenu = Menu::create(pMenuItem, nullptr);
    
    pMenu->setPosition( Vec2::ZERO );
    pMenuItem->setPosition(VisibleRect::right().x - 50, VisibleRect::bottom().y + 25);
    
    addChild(pMenu, 1);
}

void CustomWidgetCallbackBindScene::runThisTest()
{
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("CustomRootNodeReader",
                                 (ObjectFactory::Instance)CustomRootNodeReader::getInstance);
    
    auto pLayer = CSLoader::createNode("cocosui/CustomTest/CustomWidgetCallbackBindTest/CustomWidgetCallbackBindTest.csb");
    addChild(pLayer);
    
    
    Director::getInstance()->replaceScene(this);
}

void CustomWidgetCallbackBindScene::BackCallback(Ref* pSender)
{
    CustomGUITestScene* pScene = new (std::nothrow) CustomGUITestScene();
    pScene->runThisTest();
    pScene->release();
}