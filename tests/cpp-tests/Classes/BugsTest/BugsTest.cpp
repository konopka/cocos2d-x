#include "BugsTest.h"
#include <functional>                   // for _Bind, function
#include <new>                          // for nothrow, operator new
#include <vector>                       // for vector
#include "2d/CCLayer.h"                 // for Layer
#include "2d/CCMenu.h"                  // for Menu
#include "2d/CCMenuItem.h"              // for MenuItemFont
#include "2d/CCScene.h"                 // for Scene
#include "Bug-1159.h"                   // for Bug1159Layer
#include "Bug-1174.h"                   // for Bug1174Layer
#include "Bug-350.h"                    // for Bug350Layer
#include "Bug-422.h"                    // for Bug422Layer
#include "Bug-458/Bug-458.h"            // for Bug458Layer
#include "Bug-624.h"                    // for Bug624Layer
#include "Bug-886.h"                    // for Bug886Layer
#include "Bug-899.h"                    // for Bug899Layer
#include "Bug-914.h"                    // for Bug914Layer
#include "Bug-Child.h"                  // for BugChild
#include "BugsTest/Bug-458/../BugsTest.h"  // for BugsTestMainLayer, etc
#include "VisibleRect.h"                // for VisibleRect
#include "base/CCDirector.h"            // for Director
#include "base/CCEventDispatcher.h"     // for EventDispatcher
#include "base/CCEventListenerTouch.h"  // for EventListenerTouchAllAtOnce, etc
#include "base/CCTouch.h"               // for Touch
#include "base/ccMacros.h"              // for CC_CALLBACK_2, etc
#include "math/CCGeometry.h"            // for Size
#include "math/Vec2.h"                  // for Vec2, Vec2::ZERO
namespace cocos2d { class Event; }
namespace cocos2d { class Ref; }

using namespace cocos2d;

#define TEST_BUG(__bug__)									\
{															\
	Scene* scene = Scene::create();					\
	Bug##__bug__##Layer* layer = new (std::nothrow) Bug##__bug__##Layer();	\
	layer->init();                                         \
	scene->addChild(layer);                               \
	Director::getInstance()->replaceScene(scene);     \
	layer->autorelease();                                  \
}

enum
{
    LINE_SPACE = 40,
    kItemTagBasic = 5432,
};

static Vec2 s_tCurPos = Vec2::ZERO;

struct {
	const char *test_name;
	std::function<void(Ref*)> callback;
} g_bugs[] = {
    { "Bug-Child", [](Ref* sender){Director::getInstance()->replaceScene(BugChild::scene());} },
	{ "Bug-350", [](Ref* sender){ TEST_BUG(350)} },
	{ "Bug-422", [](Ref* sender){ TEST_BUG(422)} },
	{ "Bug-458", [](Ref* sender){ TEST_BUG(458)} },
	{ "Bug-624", [](Ref* sender){ TEST_BUG(624)} },
	{ "Bug-886", [](Ref* sender){ TEST_BUG(886)} },
	{ "Bug-899", [](Ref* sender){ TEST_BUG(899)} },
	{ "Bug-914", [](Ref* sender){ TEST_BUG(914)} },
	{ "Bug-1159", [](Ref* sender){ TEST_BUG(1159)} },
	{ "Bug-1174", [](Ref* sender){ TEST_BUG(1174)} },
};

static const int g_maxitems = sizeof(g_bugs) / sizeof(g_bugs[0]);


////////////////////////////////////////////////////////
//
// BugsTestMainLayer
//
////////////////////////////////////////////////////////
void BugsTestMainLayer::onEnter()
{
    Layer::onEnter();

    auto s = Director::getInstance()->getWinSize();
    _itmeMenu = Menu::create();
    MenuItemFont::setFontName("fonts/arial.ttf");
    MenuItemFont::setFontSize(24);
    for (int i = 0; i < g_maxitems; ++i)
    {
        auto pItem = MenuItemFont::create(g_bugs[i].test_name, g_bugs[i].callback);
        pItem->setPosition(s.width / 2, s.height - (i + 1) * LINE_SPACE);
        _itmeMenu->addChild(pItem, kItemTagBasic + i);
    }

    _itmeMenu->setPosition(s_tCurPos);
    addChild(_itmeMenu);

    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(BugsTestMainLayer::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(BugsTestMainLayer::onTouchesMoved, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void BugsTestMainLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
    _beginPos = touches[0]->getLocation();
}

void BugsTestMainLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
{
    auto touchLocation = touches[0]->getLocation();
    float nMoveY = touchLocation.y - _beginPos.y;

    auto curPos  = _itmeMenu->getPosition();
    auto nextPos = Vec2(curPos.x, curPos.y + nMoveY);
    auto winSize = Director::getInstance()->getWinSize();
    if (nextPos.y < 0.0f)
    {
        _itmeMenu->setPosition(Vec2::ZERO);
        return;
    }

    if (nextPos.y > ((g_maxitems + 1)* LINE_SPACE - winSize.height))
    {
        _itmeMenu->setPosition(0, ((g_maxitems + 1)* LINE_SPACE - winSize.height));
        return;
    }

    _itmeMenu->setPosition(nextPos);
    _beginPos = touchLocation;
    s_tCurPos   = nextPos;
}

////////////////////////////////////////////////////////
//
// BugsTestBaseLayer
//
////////////////////////////////////////////////////////
void BugsTestBaseLayer::onEnter()
{
    Layer::onEnter();

    MenuItemFont::setFontName("fonts/arial.ttf");
    MenuItemFont::setFontSize(24);
    auto pMainItem = MenuItemFont::create("Back", CC_CALLBACK_1(BugsTestBaseLayer::backCallback, this));
    pMainItem->setPosition(VisibleRect::rightBottom().x - 50, VisibleRect::rightBottom().y + 25);
    auto menu = Menu::create(pMainItem, nullptr);
    menu->setPosition( Vec2::ZERO );
    addChild(menu);
}

void BugsTestBaseLayer::backCallback(Ref* sender)
{
//    Director::getInstance()->enableRetinaDisplay(false);
    auto scene = new (std::nothrow) BugsTestScene();
    scene->runThisTest();
    scene->autorelease();
}

////////////////////////////////////////////////////////
//
// BugsTestScene
//
////////////////////////////////////////////////////////
void BugsTestScene::runThisTest()
{
    auto layer = new (std::nothrow) BugsTestMainLayer();
    addChild(layer);
    layer->release();

    Director::getInstance()->replaceScene(this);
}
