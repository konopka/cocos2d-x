

#ifndef __TestCpp__CutomGUIScene__
#define __TestCpp__CutomGUIScene__

#include <vector>                       // for vector
#include "2d/CCLayer.h"                 // for Layer
#include "UITest/CocoStudioGUITest/../../testBasic.h"  // for TestScene
#include "math/Vec2.h"                  // for Vec2
#include "ui/UIWidget.h"                // for Widget, etc
namespace cocos2d { class Event; }
namespace cocos2d { class Menu; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Touch; }

class CustomGUITestMainLayer : public cocos2d::Layer
{
public:
    virtual void onEnter() override;
    void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event) override;
//    void onTouchesMoved(const std::vector<Touch*>& touches, Event  *event) override;    
    
    void touchEvent(cocos2d::Ref* pSender, cocos2d::ui::Widget::TouchEventType type);
    
private:
	cocos2d::Vec2 _beginPos;
	cocos2d::Menu* _itemMenu;
};

class CustomGUITestScene : public TestScene
{
public:
    virtual void onEnter() override;
    virtual void runThisTest();
    void BackCallback(cocos2d::Ref* pSender);
};

#endif /* defined(__TestCpp__CutomGUIScene__) */
