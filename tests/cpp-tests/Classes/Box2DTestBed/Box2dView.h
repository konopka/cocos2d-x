#ifndef _BOX2D_VIEW_H_
#define _BOX2D_VIEW_H_

//#include "cocos2d.h"
#include "../testBasic.h"
#include "renderer/CCCustomCommand.h"
#include "2d/CCLayer.h"
namespace cocos2d { class EventListenerTouchOneByOne; }
namespace cocos2d { class EventListenerKeyboard; }

class MenuLayer : public cocos2d::Layer
{
    int        m_entryID;
	cocos2d::EventListenerTouchOneByOne* _touchListener;
public:
    MenuLayer(void);
    virtual ~MenuLayer(void);

    bool initWithEntryID(int entryId);

    void restartCallback(cocos2d::Ref* sender);
    void nextCallback(cocos2d::Ref* sender);
    void backCallback(cocos2d::Ref* sender);


    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

public:
    static MenuLayer* menuWithEntryID(int entryId);
};

struct TestEntry;
class Test;
class Box2DView : public cocos2d::Layer
{
	cocos2d::EventListenerTouchOneByOne* _touchListener;
	cocos2d::EventListenerKeyboard* _keyboardListener;
    TestEntry*    m_entry;
    Test*        m_test;
    int            m_entryID;
public:
    Box2DView(void);
    virtual ~Box2DView(void);

    bool initWithEntryID(int entryId);
    std::string title() const;
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;

//    virtual void registerWithTouchDispatcher();
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event);
    //virtual void accelerometer(UIAccelerometer* accelerometer, Acceleration* acceleration);

    static Box2DView* viewWithEntryID(int entryId);
protected:
    void onDraw(const cocos2d::Mat4 &transform, uint32_t flags);

	cocos2d::CustomCommand _customCmd;
};

class Box2dTestBedScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif
