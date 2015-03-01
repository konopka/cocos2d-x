#ifndef __SCENEEDITORTESTSCENE_H__
#define __SCENEEDITORTESTSCENE_H__

#include <stdint.h>                     // for uint32_t
#include <string>                       // for string
#include "2d/CCLayer.h"                 // for Layer
#include "ExtensionsTest/CocoStudioSceneTest/../../testBasic.h"
#include "cocostudio/CCArmatureAnimation.h"  // for MovementEventType
#include "math/Mat4.h"                  // for Mat4
#include "ui/UIWidget.h"                // for Widget, etc
namespace cocos2d { class Event; }
namespace cocos2d { class EventListener; }
namespace cocos2d { class Label; }
namespace cocos2d { class MenuItemImage; }
namespace cocos2d { class Node; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Renderer; }
namespace cocos2d { class Touch; }
namespace cocostudio { class Armature; }

class SceneEditorTestScene : public TestScene
{
public: 
	SceneEditorTestScene(bool bPortrait = false);

	virtual void runThisTest();

	// The CallBack for back to the main menu scene
	virtual void MainMenuCallback(cocos2d::Ref* pSender);
};

enum {
	TEST_LOADSCENEEDITORFILE = 0,
    TEST_SPIRTECOMPONENT,
    TEST_ARMATURECOMPONENT,
    TEST_UICOMPONENT,
    TEST_TMXMAPCOMPONENT,
    TEST_PARTICLECOMPONENT,
    TEST_EFEECTCOMPONENT,
    TEST_BACKGROUNDCOMPONENT,
    TEST_ATTRIBUTECOMPONENT,
    TEST_TRIGGER,
	TEST_SCENEEDITOR_COUNT
};

class SceneEditorTestLayer : public cocos2d::Layer
{
public:
	virtual void onEnter() override;
	virtual void onExit() override;

	virtual std::string title();
	virtual std::string subtitle();

	virtual void restartCallback(cocos2d::Ref* pSender);
	virtual void nextCallback(cocos2d::Ref* pSender);
	virtual void backCallback(cocos2d::Ref* pSender);

	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;

protected:
	cocos2d::MenuItemImage *restartItem;
	cocos2d::MenuItemImage *nextItem;
	cocos2d::MenuItemImage *backItem;
    
protected:
	virtual void changeLoadTypeCallback(cocos2d::Ref *pSender);
	virtual void defaultPlay() = 0; // must to be overrided
	void loadFileChangeHelper(std::string& filePathName );  // switch json& csb

private:
	bool _isCsbLoad;   // default is false
    cocos2d::Label* _loadtypelb;
	static const char* _loadtypeStr[2];
    
protected:
    cocos2d::Node* _rootNode;
    std::string _filePath;
};

class LoadSceneEdtiorFileTest : public SceneEditorTestLayer
{
public:
	LoadSceneEdtiorFileTest();
	~LoadSceneEdtiorFileTest();

    virtual std::string title();
	virtual void onEnter() override;
    virtual void onExit() override;
    cocos2d::Node* createGameScene();
private:
	void defaultPlay();
};


class SpriteComponentTest : public SceneEditorTestLayer
{
public:
	SpriteComponentTest();
	~SpriteComponentTest();

    virtual std::string title();
	virtual void onEnter() override;
    virtual void onExit() override;
    cocos2d::Node* createGameScene();

private:
	void defaultPlay();
};

class ArmatureComponentTest : public SceneEditorTestLayer
{
public:
	ArmatureComponentTest();
	~ArmatureComponentTest();

    virtual std::string title();
	virtual void onEnter() override;
    virtual void onExit() override;
    cocos2d::Node* createGameScene();

private:
	void defaultPlay();
};

class UIComponentTest : public SceneEditorTestLayer
{
public:
	UIComponentTest();
	~UIComponentTest();

    virtual std::string title();
	virtual void onEnter() override;
    virtual void onExit() override;
    cocos2d::Node* createGameScene();
	void touchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
private:
	void defaultPlay();
};

class TmxMapComponentTest : public SceneEditorTestLayer
{
public:
	TmxMapComponentTest();
	~TmxMapComponentTest();

    virtual std::string title();
	virtual void onEnter() override;
    virtual void onExit() override;
    cocos2d::Node* createGameScene();
private:
	void defaultPlay();

};

class ParticleComponentTest : public SceneEditorTestLayer
{
public:
	ParticleComponentTest();
	~ParticleComponentTest();

    virtual std::string title();
	virtual void onEnter() override;
    virtual void onExit() override;
    cocos2d::Node* createGameScene();
protected:
	void defaultPlay();
};

class EffectComponentTest : public SceneEditorTestLayer
{
public:
	EffectComponentTest();
	~EffectComponentTest();

    virtual std::string title();
	virtual void onEnter() override;
    virtual void onExit() override;
    cocos2d::Node* createGameScene();
    void animationEvent(cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID);
private:
	void defaultPlay();
	
};

class BackgroundComponentTest : public SceneEditorTestLayer
{
public:
	BackgroundComponentTest();
	~BackgroundComponentTest();

    virtual std::string title();
	virtual void onEnter() override;
    virtual void onExit() override;
    cocos2d::Node* createGameScene();
private:
	void defaultPlay();
};

class AttributeComponentTest : public SceneEditorTestLayer
{
public:
	AttributeComponentTest();
	~AttributeComponentTest();

    virtual std::string title();
	virtual void onEnter() override;
    virtual void onExit() override;
	bool initData();
    cocos2d::Node* createGameScene();
    
private:
	void defaultPlay();
};

class TriggerTest : public SceneEditorTestLayer
{
public:
	TriggerTest();
	~TriggerTest();

    virtual std::string title();
    virtual void onEnter() override;
    virtual void onExit() override;
    
	// default implements are used to call script callback if exist
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event); 
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event); 
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event); 
    virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event);

	// update of game
	void gameLogic(float dt);
    
    // create scene
    cocos2d::Node* createGameScene();
  
private:
    void defaultPlay();

    cocos2d::EventListener* _touchListener;
};

#endif  // __HELLOWORLD_SCENE_H__
