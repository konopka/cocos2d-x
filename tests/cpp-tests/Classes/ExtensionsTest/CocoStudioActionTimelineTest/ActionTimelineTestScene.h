#ifndef __ANIMATION_TEST_SCENE_H__
#define __ANIMATION_TEST_SCENE_H__

#include <string>                       // for string
#include <vector>                       // for vector
#include "../../testBasic.h"            // for TestScene
#include "2d/CCLayer.h"                 // for Layer
namespace cocos2d { class Event; }
namespace cocos2d { class MenuItemImage; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Touch; }
namespace cocostudio { namespace timeline { class ActionTimeline; } }
namespace cocostudio { namespace timeline { class Frame; } }

class ActionTimelineTestScene : public TestScene
{
public: 
    ActionTimelineTestScene(bool bPortrait = false);

    virtual void runThisTest();

    // The CallBack for back to the main menu scene
    virtual void MainMenuCallback(cocos2d::Ref* pSender);
};

enum {
    TEST_ANIMATIONELEMENT = 0,
    TEST_CHANGE_PLAY_SECTION,
//    TEST_TIMELINE_FRAME_EVENT,
    TEST_TIMELINE_PERFORMACE,
    TEST_TIMELINEACTION_ANIMATIONLIST,
    TEST_TIMELINEPROJECTNODE,
    TEST_PROJECTNODEFORSIMALATOR,
    TEST_NODELOADEDCALLBACK,
    
    TEST_ANIMATION_LAYER_COUNT
};

class ActionTimelineTestLayer : public cocos2d::Layer
{
public:
    virtual std::string title() const;
    virtual std::string subtitle() const;

    virtual void restartCallback(cocos2d::Ref* pSender);
    virtual void nextCallback(cocos2d::Ref* pSender);
    virtual void backCallback(cocos2d::Ref* pSender);

    // overrides
    virtual void onEnter() override;
    virtual void onExit() override;

protected:
    cocos2d::MenuItemImage *restartItem;
    cocos2d::MenuItemImage *nextItem;
    cocos2d::MenuItemImage *backItem;
};


class TestActionTimeline : public ActionTimelineTestLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class TestChangePlaySection : public ActionTimelineTestLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;

	void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;

protected:
	cocostudio::timeline::ActionTimeline* action;
};

class TestTimelineFrameEvent : public ActionTimelineTestLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;

    void onFrameEvent(cocostudio::timeline::Frame* frame);
};

class TestTimelinePerformance : public ActionTimelineTestLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class TestTimelineAnimationList : public ActionTimelineTestLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class TestTimelineProjectNode : public ActionTimelineTestLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class TestProjectNodeForSimulator : public ActionTimelineTestLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class TestTimelineNodeLoadedCallback : public ActionTimelineTestLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
    
    void nodeLoadedCallback(cocos2d::Ref* sender);

};

#endif  // __ANIMATION_SCENE_H__
