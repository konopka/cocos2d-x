#ifndef _EFFECTS_TEST_H_
#define _EFFECTS_TEST_H_

#include "../BaseTest.h"                // for BaseTest
#include "../testBasic.h"               // for TestScene
namespace cocos2d { class NodeGrid; }
namespace cocos2d { class Ref; }

class EffectTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

class TextLayer : public BaseTest
{
protected:
    //UxString    _title;
    cocos2d::NodeGrid* _gridNodeTarget;
public:
    TextLayer(void);
    ~TextLayer(void);

    void checkAnim(float dt);

    virtual void onEnter() override;

    void restartCallback(cocos2d::Ref* sender) override;
    void nextCallback(cocos2d::Ref* sender) override;
    void backCallback(cocos2d::Ref* sender) override;

    void newScene();

    static TextLayer* create();
};

#endif
