

#include "CocoStudioGUITest.h"
#include <functional>                   // for _Bind, function
#include <new>                          // for nothrow, operator new
#include "2d/CCLabel.h"                 // for Label
#include "2d/CCMenu.h"                  // for Menu
#include "2d/CCMenuItem.h"              // for MenuItemFont, MenuItemLabel
#include "2d/CCScene.h"                 // for Scene
#include "CocosGUIScene.h"              // for CocosGUITestScene
#include "CocostudioParserTest.h"       // for CocostudioParserTestScene
#include "CustomGUIScene.h"             // for CustomGUITestScene
#include "GUIEditorTest.h"              // for GUIEditorTestScene
#include "VisibleRect.h"                // for VisibleRect
#include "base/CCDirector.h"            // for Director
#include "base/CCEventDispatcher.h"     // for EventDispatcher
#include "base/CCEventListenerTouch.h"  // for EventListenerTouchAllAtOnce, etc
#include "base/CCTouch.h"               // for Touch
#include "base/ccMacros.h"              // for CC_CALLBACK_2, etc
#include "cocostudio/CCArmatureDataManager.h"  // for ArmatureDataManager
#include "controller.h"                 // for TestController
#include "math/CCGeometry.h"            // for Size

using namespace cocos2d;


enum
{
    LINE_SPACE = 40,
    kItemTagBasic = 1000,
};

static struct
{
	const char *name;
	std::function<void(Ref* sender)> callback;
}
g_guisTests[] =
{
	{
        "GUI Dynamic Create Test",
        [](Ref* sender)
        {
            CocosGUITestScene *scene = new (std::nothrow) CocosGUITestScene();
			scene->runThisTest();
			scene->release();
        }
	},
    {
        "GUI Editor Test",
        [](Ref* sender)
        {
            GUIEditorTestScene* scene = new (std::nothrow) GUIEditorTestScene();
            scene->runThisTest();
            scene->release();
        }
	},
    {
        "Custom GUI Test",
        [](Ref* sender)
        {
            CustomGUITestScene* scene = new (std::nothrow) CustomGUITestScene();
            scene->runThisTest();
            scene->release();
        }
	},
    {
        "Cocostudio Parser Test",
        [](Ref* sender)
        {
            CocostudioParserTestScene* scene = new (std::nothrow) CocostudioParserTestScene();
            scene->runThisTest();
            scene->release();
        }
	},
};

static const int g_maxTests = sizeof(g_guisTests) / sizeof(g_guisTests[0]);

////////////////////////////////////////////////////////
//
// CocoStudioGUIMainLayer
//
////////////////////////////////////////////////////////

static Vec2 _curPos = Vec2::ZERO;

void CocoStudioGUIMainLayer::onEnter()
{
    using namespace ui;
    
    CCLayer::onEnter();
    
    Size s = Director::getInstance()->getWinSize();
    
    _itemMenu = CCMenu::create();
    _itemMenu->setPosition(Vec2::ZERO);
    CCMenuItemFont::setFontName("fonts/arial.ttf");
    CCMenuItemFont::setFontSize(24);
    for (int i = 0; i < g_maxTests; ++i)
    {
        auto pItem = MenuItemFont::create(g_guisTests[i].name, g_guisTests[i].callback);
        pItem->setPosition(s.width / 2, s.height / 4 * 3 - (i + 1) * LINE_SPACE);
        _itemMenu->addChild(pItem, kItemTagBasic + i);
    }
    
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(CocoStudioGUIMainLayer::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(CocoStudioGUIMainLayer::onTouchesMoved, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    addChild(_itemMenu);
}

void CocoStudioGUIMainLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
    auto touch = static_cast<Touch*>(touches[0]);
    
    _beginPos = touch->getLocation();
}


////////////////////////////////////////////////////////
//
// CocoStudioGUITestScene
//
////////////////////////////////////////////////////////

void CocoStudioGUITestScene::onEnter()
{
    CCScene::onEnter();
    
    auto label = Label::createWithTTF("Back", "fonts/arial.ttf", 20);
    //#endif
    MenuItemLabel* pMenuItem = MenuItemLabel::create(label, CC_CALLBACK_1(CocoStudioGUITestScene::BackCallback, this));
    
    Menu* pMenu = Menu::create(pMenuItem, nullptr);
    
    pMenu->setPosition( Vec2::ZERO );
    pMenuItem->setPosition(VisibleRect::right().x - 50, VisibleRect::bottom().y + 25);
    
    addChild(pMenu, 1);
}

void CocoStudioGUITestScene::runThisTest()
{
    Layer* pLayer = new (std::nothrow) CocoStudioGUIMainLayer();
    addChild(pLayer);
    pLayer->release();
    
    CCDirector::getInstance()->replaceScene(this);
}

void CocoStudioGUITestScene::BackCallback(Ref* pSender)
{
    auto scene = Scene::create();
    
    auto layer = new (std::nothrow) TestController();
    scene->addChild(layer);
    layer->release();
    
    Director::getInstance()->replaceScene(scene);
    
    cocostudio::ArmatureDataManager::destroyInstance();
}
