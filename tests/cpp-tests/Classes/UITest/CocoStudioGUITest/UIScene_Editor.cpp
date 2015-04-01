

#include "UIScene_Editor.h"
#include <functional>                   // for _Bind
#include "2d/CCMenu.h"                  // for Menu
#include "2d/CCMenuItem.h"              // for MenuItem, MenuItemFont, etc
#include "GUIEditorTest.h"              // for GUIEditorTestScene
#include "UISceneManager_Editor.h"      // for UISceneManager_Editor
#include "VisibleRect.h"                // for VisibleRect
#include "base/CCDirector.h"            // for Director
#include "base/CCVector.h"              // for Vector
#include "base/ccMacros.h"              // for CC_CALLBACK_1
#include "math/CCGeometry.h"            // for Size
#include "math/Vec2.h"                  // for Vec2, Vec2::ZERO

using namespace cocos2d;
using namespace cocos2d::ui;

UIScene_Editor::UIScene_Editor()
: _sceneTitle(nullptr)
, _touchGroup(nullptr)
, _layout(nullptr)
{
    
}

UIScene_Editor::~UIScene_Editor()
{
    
}

bool UIScene_Editor::init()
{
    if (Layer::init())
    {
        _touchGroup = Layer::create();
        addChild(_touchGroup);                
        
        //add switch
        MenuItem* pLoadJsonItem = MenuItemFont::create("Switch to Windows Json Load");
        MenuItem* pLoadBinaryItem = MenuItemFont::create("Switch to Windows Binary Load");
        MenuItem* pLoadJsonItemCrossPlatForm = MenuItemFont::create("Switch to Cross PlatForm Json Load");
        MenuItem* pLoadBinaryItemCrossPlatForm = MenuItemFont::create("Switch to Cross PlatForm Binary Load");
        
        pLoadJsonItem->setTag(1);
        pLoadBinaryItem->setTag(2);
        pLoadJsonItemCrossPlatForm->setTag(3);
        pLoadBinaryItemCrossPlatForm->setTag(4);
        
        
        Vector<MenuItem*> array;;
        array.pushBack(pLoadBinaryItem);
        array.pushBack(pLoadJsonItemCrossPlatForm);
        array.pushBack(pLoadBinaryItemCrossPlatForm);
        array.pushBack(pLoadJsonItem);
        
        MenuItemToggle *pToggleItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(UIScene_Editor::switchLoadMethod,this), array);
        
        pToggleItem->setTag(1);
        
        MenuItem* selectedItem = pToggleItem->getSelectedItem();
        pToggleItem->setPosition(Vec2(VisibleRect::center().x, VisibleRect::center().y - selectedItem->getContentSize().height * 3.75f));
        
        Menu* pMenu =Menu::create(pToggleItem, nullptr);
        pMenu->setPosition( Vec2::ZERO );
        
//        addChild(pMenu, 1, 1);

        return true;
    }
    
    return false;
}

void UIScene_Editor::switchLoadMethod(cocos2d::Ref *pSender)
{
    //subclass should override this method
}

void UIScene_Editor::previousCallback(Ref* sender, Widget::TouchEventType event)
{
    switch (event)
    {
        case Widget::TouchEventType::ENDED:
            Director::getInstance()->replaceScene(UISceneManager_Editor::sharedUISceneManager_Editor()->previousUIScene());
            break;
            
        default:
            break;
    }
}

void UIScene_Editor::nextCallback(Ref* sender, Widget::TouchEventType event)
{
    switch (event)
    {
        case Widget::TouchEventType::ENDED:
            Director::getInstance()->replaceScene(UISceneManager_Editor::sharedUISceneManager_Editor()->nextUIScene());
            break;
            
        default:
            break;
    }
}

void UIScene_Editor::toGUIEditorTestScene(Ref* sender, Widget::TouchEventType event)
{
    switch (event)
    {
        case Widget::TouchEventType::ENDED:
        {
            UISceneManager_Editor::sharedUISceneManager_Editor()->purge();
            
            GUIEditorTestScene* pScene = new (std::nothrow) GUIEditorTestScene();
            pScene->runThisTest();
            pScene->release();
        }
            break;
            
        default:
            break;
    }
}
