

#ifndef __TestCpp__GUIEditorTest__
#define __TestCpp__GUIEditorTest__

#include <vector>                       // for vector
#include "../../testBasic.h"            // for TestScene
#include "2d/CCLayer.h"                 // for Layer
#include "math/Vec2.h"                  // for Vec2
namespace cocos2d { class Event; }
namespace cocos2d { class Menu; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Touch; }

class GUIEditorMainLayer : public cocos2d::Layer
{
public:
    virtual void onEnter() override;
    void menuCallback(cocos2d::Ref* pSender);
    void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event) override;
    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event) override;
private:
	cocos2d::Vec2 _beginPos;
	cocos2d::Menu* _itemMenu;
    
	int _testcount;
};

class GUIEditorTestScene : public TestScene
{
public:
    virtual void onEnter() override;
    virtual void runThisTest();
    void BackCallback(cocos2d::Ref* pSender);
};

#endif /* defined(__TestCpp__GUIEditorTest__) */
