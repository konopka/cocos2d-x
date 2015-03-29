

#include "UICheckBoxTest_Editor.h"
#include <functional>                   // for _Bind
#include "2d/CCLayer.h"                 // for Layer
#include "2d/CCMenuItem.h"              // for MenuItemToggle
#include "2d/CCNode.h"                  // for Node
#include "UITest/CocoStudioGUITest/UICheckBoxTest/../UIScene_Editor.h"
#include "base/CCDirector.h"            // for Director
#include "base/ccMacros.h"              // for CC_CALLBACK_2
#include "cocostudio/ActionTimeline/CSLoader.h"  // for CSLoader
#include "cocostudio/CCSGUIReader.h"    // for GUIReader
#include "math/CCGeometry.h"            // for Size
#include "math/Vec2.h"                  // for Vec2
#include "ui/UIHelper.h"                // for Helper
#include "ui/UILayout.h"                // for Layout
#include "ui/UIText.h"                  // for Text

using namespace cocos2d;
using namespace cocos2d::ui;

UICheckBoxTest_Editor::UICheckBoxTest_Editor()
: _displayValueLabel(nullptr)
{
    
}

UICheckBoxTest_Editor::~UICheckBoxTest_Editor()
{
    
}

void UICheckBoxTest_Editor::switchLoadMethod(cocos2d::Ref *pSender)
{
    MenuItemToggle *item = (MenuItemToggle*)pSender;
    
    switch (item->getSelectedIndex())
    {
        case 0:
        {
            _layout->removeFromParentAndCleanup(true);
            
            _layout = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("cocosui/UIEditorTest/UICheckBox/windows_ui_checkbox_editor_1.json"));
            _touchGroup->addChild(_layout);
            
            this->configureGUIScene();
            
            break;
        }
            
        case 1:
        {
            _layout->removeFromParentAndCleanup(true);
            
            _layout = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromBinaryFile("cocosui/UIEditorTest/UICheckBox/windows_ui_checkbox_editor_1.csb"));
            _touchGroup->addChild(_layout);
            
            this->configureGUIScene();
            
            break;
        }
            
        case 2:
        {
            _layout->removeFromParentAndCleanup(true);
            
            Node* node = CSLoader::createNode("cocosui/UIEditorTest/UICheckBox/crossplatform_UICheckBox_Editor_1.ExportJson");
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
            
            Node* node = CSLoader::createNode("cocosui/UIEditorTest/UICheckBox/crossplatform_UICheckBox_Editor_1.csb");
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

void UICheckBoxTest_Editor::configureGUIScene()
{
    Size screenSize = Director::getInstance()->getWinSize();
    Size rootSize = _layout->getContentSize();
    _touchGroup->setPosition(Vec2((screenSize.width - rootSize.width) / 2,
                                  (screenSize.height - rootSize.height) / 2));
    
    Layout* root = static_cast<Layout*>(_layout->getChildByName("root_Panel"));
    
    Text* back_label = static_cast<Text*>(Helper::seekWidgetByName(root, "back"));
    back_label->addTouchEventListener(CC_CALLBACK_2(UIScene_Editor::toGUIEditorTestScene, this));
    
    _sceneTitle = static_cast<Text*>(Helper::seekWidgetByName(root, "UItest"));
    
    CheckBox* checkbox = static_cast<CheckBox*>(Helper::seekWidgetByName(root, "CheckBox_540"));
    checkbox->addEventListener(CC_CALLBACK_2(UICheckBoxTest_Editor::selectedStateEvent, this));
    
}

bool UICheckBoxTest_Editor::init()
{
    if (UIScene_Editor::init())
    {
        Node* node = CSLoader::createNode("cocosui/UIEditorTest/UICheckBox/crossplatform_UICheckBox_Editor_1.csb");
        Node* child = node->getChildByTag(5);
        child->removeFromParent();
        _layout = static_cast<Layout*>(child);
        _touchGroup->addChild(_layout);
        
        this->configureGUIScene();
        
        _displayValueLabel = Text::create();
        _displayValueLabel->setFontName("fonts/Marker Felt.ttf");
        _displayValueLabel->setFontSize(30);
        _displayValueLabel->setString("No event");
        _displayValueLabel->setPosition(Vec2(_layout->getContentSize().width / 2,
                                              _layout->getContentSize().height - _displayValueLabel->getContentSize().height * 1.75f));
        _touchGroup->addChild(_displayValueLabel,20);
        
        return true;
    }
    
    return false;
}

void UICheckBoxTest_Editor::selectedStateEvent(Ref *pSender, CheckBox::EventType type)
{
    switch (type)
    {
        case CheckBox::EventType::UNSELECTED:
            _displayValueLabel->setString("Unselected");
            break;
            
        case CheckBox::EventType::SELECTED:
            _displayValueLabel->setString("Selected");
            break;
            
        default:
            break;
    }
}
