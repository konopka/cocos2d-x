//
//  UIFocusTest.h
//  cocos2d_tests
//
//  Created by guanghui on 5/4/14.
//
//

#ifndef __cocos2d_tests__UIFocusTest__
#define __cocos2d_tests__UIFocusTest__

#include "../UIScene.h"                 // for UI_SCENE_CREATE_FUNC, etc
#include "ui/UIWidget.h"                // for Widget, etc
namespace cocos2d { class EventListenerFocus; }
namespace cocos2d { class Menu; }
namespace cocos2d { class Ref; }
namespace cocos2d { namespace ui { class Layout; } }
namespace cocos2d { namespace ui { class ListView; } }
namespace cocos2d { namespace ui { class Text; } }

class UIFocusTestBase : public UIScene
{
public:
    UIFocusTestBase();
    virtual ~UIFocusTestBase();
    bool init();
    
    virtual void onLeftKeyPressed();
    virtual void onRightKeyPressed();
    virtual void onUpKeyPressed();
    virtual void onDownKeyPressed();
    virtual void onFocusChanged(cocos2d::ui::Widget* widgetLostFocus, cocos2d::ui::Widget* widgetGetFocus);

    void onImageViewClicked(cocos2d::Ref* ref, cocos2d::ui::Widget::TouchEventType touchType);

protected:
    cocos2d::Menu *_dpadMenu;
    cocos2d::ui::Widget *_firstFocusedWidget;
    cocos2d::EventListenerFocus *_eventListener;
};

class UIFocusTestHorizontal : public UIFocusTestBase
{
public:
    UIFocusTestHorizontal();
    virtual ~UIFocusTestHorizontal();
    bool init();
   
    
    void toggleFocusLoop(cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType);
    
protected:
    UI_SCENE_CREATE_FUNC(UIFocusTestHorizontal);
    cocos2d::ui::Layout *_horizontalLayout;
    cocos2d::ui::Text *_loopText;
};

class UIFocusTestVertical : public UIFocusTestBase
{
public:
    UIFocusTestVertical();
    virtual ~UIFocusTestVertical();
    bool init();
   
    
    void toggleFocusLoop(cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType);
protected:
    UI_SCENE_CREATE_FUNC(UIFocusTestVertical);
    cocos2d::ui::Layout *_verticalLayout;
    cocos2d::ui::Text *_loopText;
};

class UIFocusTestNestedLayout1 : public UIFocusTestBase
{
public:
    UIFocusTestNestedLayout1();
    virtual ~UIFocusTestNestedLayout1();
    bool init();
    
    
    void toggleFocusLoop(cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType);
protected:
    UI_SCENE_CREATE_FUNC(UIFocusTestNestedLayout1);
    cocos2d::ui::Layout *_verticalLayout;
    cocos2d::ui::Text *_loopText;
};

class UIFocusTestNestedLayout2 : public UIFocusTestBase
{
public:
    UIFocusTestNestedLayout2();
    virtual ~UIFocusTestNestedLayout2();
    bool init();
    
    
    void toggleFocusLoop(cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType);
protected:
    UI_SCENE_CREATE_FUNC(UIFocusTestNestedLayout2);
    cocos2d::ui::Layout *_horizontalLayout;
    cocos2d::ui::Text *_loopText;
};

class UIFocusTestNestedLayout3 : public UIFocusTestBase
{
public:
    UIFocusTestNestedLayout3();
    virtual ~UIFocusTestNestedLayout3();
    bool init();
    
    
    void toggleFocusLoop(cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType);
protected:
    UI_SCENE_CREATE_FUNC(UIFocusTestNestedLayout3);
    cocos2d::ui::Layout *_verticalLayout;
    cocos2d::ui::Text *_loopText;
};

class UIFocusTestListView : public UIFocusTestBase
{
public:
    UIFocusTestListView();
    virtual ~UIFocusTestListView();
    bool init();
    
    
    void toggleFocusLoop(cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType);
protected:
    UI_SCENE_CREATE_FUNC(UIFocusTestListView);
    cocos2d::ui::ListView *_listView;
    cocos2d::ui::Text *_loopText;
};



#endif /* defined(__cocos2d_tests__UIFocusTest__) */
