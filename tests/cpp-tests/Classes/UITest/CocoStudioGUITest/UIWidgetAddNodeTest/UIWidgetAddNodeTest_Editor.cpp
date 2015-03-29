

#include "UIWidgetAddNodeTest_Editor.h"
#include <functional>                   // for _Bind
#include "2d/CCLayer.h"                 // for Layer
#include "2d/CCMenuItem.h"              // for MenuItemToggle
#include "2d/CCNode.h"                  // for Node
#include "2d/CCSprite.h"                // for Sprite
#include "UITest/CocoStudioGUITest/UIWidgetAddNodeTest/../UIScene_Editor.h"
#include "base/CCDirector.h"            // for Director
#include "base/ccMacros.h"              // for CC_CALLBACK_2
#include "cocostudio/ActionTimeline/CSLoader.h"  // for CSLoader
#include "cocostudio/CCSGUIReader.h"    // for GUIReader
#include "math/CCGeometry.h"            // for Size
#include "math/Vec2.h"                  // for Vec2
#include "ui/UIHelper.h"                // for Helper
#include "ui/UILayout.h"                // for Layout
#include "ui/UIText.h"                  // for Text
#include "ui/UIWidget.h"                // for Widget

using namespace cocos2d;
using namespace cocos2d::ui;

// UIWidgetAddNodeTest_Editor

UIWidgetAddNodeTest_Editor::UIWidgetAddNodeTest_Editor()
{
    
}

UIWidgetAddNodeTest_Editor::~UIWidgetAddNodeTest_Editor()
{
    
}

void UIWidgetAddNodeTest_Editor::switchLoadMethod(cocos2d::Ref *pSender)
{
    MenuItemToggle *item = (MenuItemToggle*)pSender;
    
    switch (item->getSelectedIndex())
    {
        case 0:
        {
            _layout->removeFromParentAndCleanup(true);
            
            _layout = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("cocosui/UIEditorTest/UIWidgetAddNode/windows_ui_widget_add_node_editor.json"));
            
            _touchGroup->addChild(_layout);
            
            this->configureGUIScene();
            
            break;
        }
            
        case 1:
        {
            _layout->removeFromParentAndCleanup(true);
            
            _layout = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromBinaryFile("cocosui/UIEditorTest/UIWidgetAddNode/windows_ui_widget_add_node_editor.csb"));
            
            _touchGroup->addChild(_layout);
            
            this->configureGUIScene();
            
            break;
        }
            
        case 2:
        {
            _layout->removeFromParentAndCleanup(true);

            Node* node = CSLoader::createNode("cocosui/UIEditorTest/UIWidgetAddNode/crossplatform_UIWidgetAddNode_Editor_1.ExportJson");
            Node* child = node->getChildByTag(5);
            child->removeFromParent();
            _layout = static_cast<Layout*>(child);
            _touchGroup->addChild(_layout);
            
            this->configureGUIScene();
            
            break;
        }
            
        case 3:
        {
            _layout->removeFromParentAndCleanup(true);
            
            Node* node = CSLoader::createNode("cocosui/UIEditorTest/UIWidgetAddNode/crossplatform_UIWidgetAddNode_Editor_1.csb");
            Node* child = node->getChildByTag(5);
            child->removeFromParent();
            _layout = static_cast<Layout*>(child);
            _touchGroup->addChild(_layout);
            
            this->configureGUIScene();
            
            break;
        }
            
        default:
            break;
    }
}

void UIWidgetAddNodeTest_Editor::configureGUIScene()
{
    Size screenSize = Director::getInstance()->getWinSize();
    Size rootSize = _layout->getContentSize();
    _touchGroup->setPosition(Vec2((screenSize.width - rootSize.width) / 2,
                                  (screenSize.height - rootSize.height) / 2));
    
    Layout* root = static_cast<Layout*>(_layout->getChildByName("root_Panel"));
    
    Text* back_label = static_cast<Text*>(Helper::seekWidgetByName(root, "back"));
    back_label->addTouchEventListener(CC_CALLBACK_2(UIScene_Editor::toGUIEditorTestScene, this));
    
    _sceneTitle = static_cast<Text*>(Helper::seekWidgetByName(root, "UItest"));
    
    
    // Create the ui widget
    Widget* widget = Widget::create();
    widget->setPosition(Vec2(rootSize.width / 2.0f, rootSize.height / 2.0f));
    widget->setLocalZOrder(_layout->getLocalZOrder() + 1);
    _layout->addChild(widget);
    
    Sprite* sprite = Sprite::create("cocosui/ccicon.png");
    widget->addChild(sprite);

    
}


bool UIWidgetAddNodeTest_Editor::init()
{
    if (UIScene_Editor::init())
    {
        Node* node = CSLoader::createNode("cocosui/UIEditorTest/UIWidgetAddNode/crossplatform_UIWidgetAddNode_Editor_1.csb");
        Node* child = node->getChildByTag(5);
        child->removeFromParent();
        _layout = static_cast<Layout*>(child);
        _touchGroup->addChild(_layout);
        
        this->configureGUIScene();
        
        return true;
    }
    
    return false;
}

