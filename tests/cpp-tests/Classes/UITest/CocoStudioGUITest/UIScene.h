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

#ifndef __TestCpp__UIScene__
#define __TestCpp__UIScene__

#include <new>                          // for nothrow, operator new
#include "2d/CCLayer.h"                 // for Layer
#include "2d/CCScene.h"                 // for Scene
#include "CCPlatformMacros.h"           // for CC_SAFE_DELETE, etc
#include "ui/UIText.h"                  // for Text
#include "ui/UIWidget.h"                // for Widget, etc
class UIScene;
namespace cocos2d { class Ref; }
namespace cocos2d { namespace ui { class Layout; } }

#define UI_SCENE_CREATE_FUNC(UIScene) \
public: \
static cocos2d::Scene* sceneWithTitle(const char * title) \
{ \
    cocos2d::Scene* pScene = cocos2d::Scene::create(); \
    UIScene* uiLayer = new (std::nothrow) UIScene(); \
    if (uiLayer && uiLayer->init()) \
    { \
        uiLayer->autorelease(); \
        uiLayer->getSceneTitle()->setString(title); \
        pScene->addChild(uiLayer); \
    } \
    else \
    { \
        CC_SAFE_DELETE(uiLayer); \
    } \
    return pScene; \
}

class UIScene : public cocos2d::Layer
{
public:
    UIScene();
    ~UIScene();
    bool init();
    // Menu Callbacks
    void toCocosGUITestScene(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    virtual void previousCallback(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    virtual void restartCallback(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    virtual void nextCallback(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    
    /** Title label of the scene. */    
    CC_SYNTHESIZE_READONLY(cocos2d::ui::Text*, _sceneTitle, SceneTitle)
    
    UI_SCENE_CREATE_FUNC(UIScene);
    
protected:
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
    
protected:
    cocos2d::Layer* _uiLayer;
    cocos2d::ui::Layout* _widget;
};

#endif /* defined(__TestCpp__UIScene__) */
