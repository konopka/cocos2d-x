#include "ComponentsTestScene.h"
#include <new>                          // for nothrow, operator new
#include "../ExtensionsTest.h"          // for ExtensionsTestScene
#include "2d/CCMenu.h"                  // for Menu
#include "2d/CCMenuItem.h"              // for MenuItemFont
#include "2d/CCNode.h"                  // for Node
#include "2d/CCScene.h"                 // for Scene
#include "2d/CCSprite.h"                // for Sprite
#include "CCPlatformMacros.h"           // for CC_BREAK_IF, etc
#include "PlayerController.h"           // for PlayerController
#include "SceneController.h"            // for SceneController
#include "VisibleRect.h"                // for VisibleRect
#include "base/CCDirector.h"            // for Director
#include "base/ccTypes.h"               // for Color3B, Color4B
#include "cocostudio/CCComAttribute.h"  // for ComAttribute
#include "cocostudio/CCComAudio.h"      // for ComAudio
#include "math/CCGeometry.h"            // for Size, Rect
#include "math/Vec2.h"                  // for Vec2, Vec2::ZERO

using namespace cocos2d;
using namespace cocostudio;

ComponentsTestLayer::~ComponentsTestLayer()
{
}

ComponentsTestLayer::ComponentsTestLayer()
{
}

Scene* ComponentsTestLayer::scene()
{
	Scene * scene = nullptr;
	do 
	{
		// 'scene' is an autorelease object
		scene = Scene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		auto layer = ComponentsTestLayer::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool ComponentsTestLayer::init()
{
	bool bRet = false;
	do 
	{
        CC_BREAK_IF(! LayerColor::initWithColor( Color4B(255,255,255,255) ) );
        
        auto root = createGameScene();
        CC_BREAK_IF(!root);
        this->addChild(root, 0, 1);

        root->getChildByTag(1)->addComponent(ComAudio::create());
        root->getChildByTag(1)->addComponent(PlayerController::create());  
        
        root->addComponent(ComAudio::create());
        root->addComponent(ComAttribute::create());
        root->addComponent(SceneController::create());

		bRet = true;
	} while (0);

	return bRet;
}

cocos2d::Node* ComponentsTestLayer::createGameScene()
{
    Node *root = nullptr;
    do 
	{
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto origin = Director::getInstance()->getVisibleOrigin();

       
        auto player = Sprite::create("components/Player.png", Rect(0, 0, 27, 40) );
        
        player->setPosition(origin.x + player->getContentSize().width/2,
                                 origin.y + visibleSize.height/2);
        
        root = cocos2d::Node::create();
        root->addChild(player, 1, 1);
        

        auto itemBack = MenuItemFont::create("Back", [](Ref* sender){
        	auto scene = new (std::nothrow) ExtensionsTestScene();
            scene->runThisTest();
            scene->release();
        });
        
        itemBack->setColor(Color3B(0, 0, 0));
        itemBack->setPosition(VisibleRect::rightBottom().x - 50, VisibleRect::rightBottom().y + 25);
        auto menuBack = Menu::create(itemBack, nullptr);
        menuBack->setPosition(Vec2::ZERO);
        addChild(menuBack);
        
    }while (0);
    
    return root;
}

void runComponentsTestLayerTest()
{
    auto scene = ComponentsTestLayer::scene();
    Director::getInstance()->replaceScene(scene);
}
