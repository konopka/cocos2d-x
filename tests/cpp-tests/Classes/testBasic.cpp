#include "testBasic.h"
#include <new>                          // for nothrow, operator new
#include "2d/CCLabel.h"                 // for Label, TTFConfig
#include "2d/CCMenu.h"                  // for Menu
#include "2d/CCMenuItem.h"              // for MenuItemLabel
#include "VisibleRect.h"                // for VisibleRect
#include "base/CCDirector.h"            // for Director
#include "base/ccConfig.h"              // for CC_USE_PHYSICS
#include "cocostudio/CCArmatureDataManager.h"  // for ArmatureDataManager
#include "controller.h"                 // for TestController
#include "math/Vec2.h"                  // for Vec2, Vec2::ZERO
namespace cocos2d { class Ref; }

TestScene::TestScene(bool bPortrait, bool physics/* = false*/)
{
    if (physics)
    {
#if CC_USE_PHYSICS
        TestScene::initWithPhysics();
#else
        Scene::init();
#endif
    }
    else
    {
        Scene::init();
    }
}

void testScene_callback(Ref *sender )
{
    auto scene = Scene::create();

    auto layer = new (std::nothrow) TestController();
    scene->addChild(layer);
    layer->release();

    Director::getInstance()->replaceScene(scene);

    cocostudio::ArmatureDataManager::destroyInstance();
}

void TestScene::onEnter()
{
    Scene::onEnter();

    //add the menu item for back to main menu
    TTFConfig ttfConfig("fonts/arial.ttf", 20);
    auto label = Label::createWithTTF(ttfConfig,"MainMenu");

    auto menuItem = MenuItemLabel::create(label, testScene_callback );
    auto menu = Menu::create(menuItem, nullptr);

    menu->setPosition( Vec2::ZERO );
    menuItem->setPosition( Vec2( VisibleRect::right().x - 50, VisibleRect::bottom().y + 25) );

    addChild(menu, 1);
}
