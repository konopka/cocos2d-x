/****************************************************************************
 Copyright (c) 2014 cocos2d-x.org
 
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

#ifndef __TestCpp__UIListViewTest_Editor__
#define __TestCpp__UIListViewTest_Editor__

#include "../UIScene_Editor.h"          // for UIScene_Editor, etc
#include "ui/UIListView.h"              // for ListView, etc
namespace cocos2d { class Ref; }
namespace cocos2d { class __Array; }
namespace cocos2d { namespace ui { class Text; } }

class UIListViewTest_Vertical_Editor : public UIScene_Editor
{
public:
    static void setupListView(cocos2d::ui::ListView* listView);
    UIListViewTest_Vertical_Editor();
    ~UIListViewTest_Vertical_Editor();
    bool init();
    void selectedItemEvent(cocos2d::Ref* pSender, cocos2d::ui::ListView::EventType type);
    virtual void switchLoadMethod(cocos2d::Ref* pSender);
    void configureGUIScene();
protected:
    UI_SCENE_EDITOR_CREATE_FUNC(UIListViewTest_Vertical_Editor)
    cocos2d::ui::Text* _displayValueLabel;
    
    cocos2d::__Array* _array;
};


class UIListViewTest_Horizontal_Editor : public UIScene_Editor
{
public:
    UIListViewTest_Horizontal_Editor();
    ~UIListViewTest_Horizontal_Editor();
    bool init();
    void selectedItemEvent(cocos2d::Ref* pSender, cocos2d::ui::ListView::EventType type);
    virtual void switchLoadMethod(cocos2d::Ref* pSender);
    void configureGUIScene();
protected:
    UI_SCENE_EDITOR_CREATE_FUNC(UIListViewTest_Horizontal_Editor)
    cocos2d::ui::Text* _displayValueLabel;
    
    cocos2d::__Array* _array;
};

#endif /* defined(__TestCpp__UIListViewTest_Editor__) */
