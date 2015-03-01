#ifndef _ACTION_MANAGER_TEST_H_
#define _ACTION_MANAGER_TEST_H_

#include <string>                       // for string
#include "../BaseTest.h"                // for BaseTest
#include "../testBasic.h"               // for TestScene
namespace cocos2d { class Node; }
namespace cocos2d { class Ref; }
namespace cocos2d { class TextureAtlas; }

class ActionManagerTest: public BaseTest
{
protected:
	cocos2d::TextureAtlas* _atlas;

    std::string    _title;

public:
    ActionManagerTest(void);
    ~ActionManagerTest(void);

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    void restartCallback(cocos2d::Ref* sender) override;
    void nextCallback(cocos2d::Ref* sender) override;
    void backCallback(cocos2d::Ref* sender) override;
};

class CrashTest : public ActionManagerTest
{
public:
    virtual std::string subtitle() const override;
    virtual void onEnter() override;
    void removeThis();
};

class LogicTest : public ActionManagerTest
{
public:
    virtual std::string subtitle() const override;
    virtual void onEnter() override;
    void bugMe(cocos2d::Node* node);
};

class PauseTest : public ActionManagerTest
{
public:
    virtual std::string subtitle() const override;
    virtual void onEnter() override;
    void unpause(float dt);
};

class StopActionTest : public ActionManagerTest
{
public:
    virtual std::string subtitle() const override;
    virtual void onEnter() override;
    void stopAction();
};

class StopAllActionsTest : public ActionManagerTest
{
public:
    virtual std::string subtitle() const override;
    virtual void onEnter() override;
    void stopAction(float time);
};

class ResumeTest : public ActionManagerTest
{
public:
    virtual std::string subtitle() const override;
    virtual void onEnter() override;
    void resumeGrossini(float time);
};

class ActionManagerTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif
