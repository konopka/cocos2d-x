/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __TestCpp__UIButtonTest__
#define __TestCpp__UIButtonTest__

#include "../UIScene.h"                 // for UIScene, etc
#include "ui/UISlider.h"                // for Slider, Slider::EventType
#include "ui/UIWidget.h"                // for Widget, etc
namespace cocos2d { class Ref; }
namespace cocos2d { namespace ui { class Text; } }

class UIButtonTest : public UIScene
{
public:
    UIButtonTest();
    ~UIButtonTest();
    bool init();
    void touchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

protected:
    UI_SCENE_CREATE_FUNC(UIButtonTest)
    cocos2d::ui::Text* _displayValueLabel;
};

class UIButtonTest_Scale9 : public UIScene
{
public:
    UIButtonTest_Scale9();
    ~UIButtonTest_Scale9();
    bool init();
    void touchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
protected:
    UI_SCENE_CREATE_FUNC(UIButtonTest_Scale9)
    cocos2d::ui::Text* _displayValueLabel;
};

class UIButtonTest_Scale9_State_Change : public UIScene
{
public:
    UIButtonTest_Scale9_State_Change();
    ~UIButtonTest_Scale9_State_Change();
    bool init();
    void touchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

protected:
    UI_SCENE_CREATE_FUNC(UIButtonTest_Scale9_State_Change)
    cocos2d::ui::Text* _displayValueLabel;
};

class UIButtonTest_PressedAction : public UIScene
{
public:
    UIButtonTest_PressedAction();
    ~UIButtonTest_PressedAction();
    bool init();
    void touchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
protected:
    UI_SCENE_CREATE_FUNC(UIButtonTest_PressedAction)
    cocos2d::ui::Text* _displayValueLabel;
};

class UIButtonTest_Title : public UIScene
{
public:
    UIButtonTest_Title();
    ~UIButtonTest_Title();
    bool init();
    void touchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
protected:
    UI_SCENE_CREATE_FUNC(UIButtonTest_Title)
    cocos2d::ui::Text* _displayValueLabel;
};

class UIButtonTestRemoveSelf : public UIScene
{
public:
    UIButtonTestRemoveSelf();
    ~UIButtonTestRemoveSelf();
    bool init();
    void touchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
protected:
    UI_SCENE_CREATE_FUNC(UIButtonTestRemoveSelf)
    cocos2d::ui::Text* _displayValueLabel;
};

class UIButtonTestSwitchScale9 : public UIScene
{
public:
    UIButtonTestSwitchScale9();
    ~UIButtonTestSwitchScale9();
    bool init();
    void touchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
protected:
    UI_SCENE_CREATE_FUNC(UIButtonTestSwitchScale9)
    cocos2d::ui::Text* _displayValueLabel;
};

class UIButtonTestZoomScale : public UIScene
{
public:
    UIButtonTestZoomScale();
    ~UIButtonTestZoomScale();
    bool init();
    void sliderEvent(cocos2d::Ref* pSender, cocos2d::ui::Slider::EventType type);

protected:
    UI_SCENE_CREATE_FUNC(UIButtonTestZoomScale)
    cocos2d::ui::Text* _displayValueLabel;
};

class UIButtonTextOnly : public UIScene
{
public:
    UIButtonTextOnly();
    ~UIButtonTextOnly();
    bool init();

protected:
    UI_SCENE_CREATE_FUNC(UIButtonTextOnly)
    cocos2d::ui::Text* _displayValueLabel;
};

class UIButtonIgnoreContentSizeTest : public UIScene
{
public:
    UIButtonIgnoreContentSizeTest();
    ~UIButtonIgnoreContentSizeTest();
    bool init();
    
protected:
    UI_SCENE_CREATE_FUNC(UIButtonIgnoreContentSizeTest)
    cocos2d::ui::Text* _displayValueLabel;
};

class UIButtonTitleEffectTest : public UIScene
{
public:
    UIButtonTitleEffectTest();
    ~UIButtonTitleEffectTest();
    bool init();
    
protected:
    UI_SCENE_CREATE_FUNC(UIButtonTitleEffectTest)
    cocos2d::ui::Text* _displayValueLabel;
};

class UIButtonFlipTest : public UIScene
{
public:
    UIButtonFlipTest();
    ~UIButtonFlipTest();
    bool init();
    
protected:
    UI_SCENE_CREATE_FUNC(UIButtonFlipTest)
    cocos2d::ui::Text* _displayValueLabel;
};

class UIButtonNormalDefaultTest : public UIScene
{
public:
    UIButtonNormalDefaultTest();
    ~UIButtonNormalDefaultTest();
    bool init();
    
protected:
    UI_SCENE_CREATE_FUNC(UIButtonNormalDefaultTest)
    cocos2d::ui::Text* _displayValueLabel;
};

class UIButtonDisableDefaultTest : public UIScene
{
public:
    UIButtonDisableDefaultTest();
    ~UIButtonDisableDefaultTest();
    bool init();
    
protected:
    UI_SCENE_CREATE_FUNC(UIButtonDisableDefaultTest)
    cocos2d::ui::Text* _displayValueLabel;
};
#endif /* defined(__TestCpp__UIButtonTest__) */
