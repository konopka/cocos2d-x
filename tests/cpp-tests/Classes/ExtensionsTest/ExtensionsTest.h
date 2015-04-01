#ifndef __EXTENSIONS_TEST_H__
#define __EXTENSIONS_TEST_H__

#include <vector>                       // for vector
#include "2d/CCLayer.h"                 // for Layer
#include "ExtensionsTest/CocoStudioSceneTest/../../testBasic.h"
#include "math/Vec2.h"                  // for Vec2
namespace cocos2d { class Event; }
namespace cocos2d { class Menu; }
namespace cocos2d { class Touch; }

class ExtensionsMainLayer : public cocos2d::Layer
{
public:
    virtual void onEnter() override;

	void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event  *event) override;
    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event  *event) override;

	cocos2d::Vec2 _beginPos;
	cocos2d::Menu* _itemMenu;

	int _testcount;
    
protected:
    void onMouseScroll(cocos2d::Event* event);
};

class ExtensionsTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif /* __EXTENSIONS_TEST_H__ */
