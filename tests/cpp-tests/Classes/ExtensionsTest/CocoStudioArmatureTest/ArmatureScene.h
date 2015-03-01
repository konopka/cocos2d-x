#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "../../testBasic.h"
#include <stdint.h>                     // for uint32_t
#include <string>                       // for string
#include <vector>                       // for vector
#include "2d/CCLayer.h"                 // for Layer
#include "platform/CCPlatformMacros.h" // for CC_SYNTHESIZE
#include "cocostudio/CCArmature.h"      // for Armature
#include "cocostudio/CCArmatureAnimation.h"  // for MovementEventType
#include "cocostudio/CCArmatureDefine.h"
#include "math/CCGeometry.h"            // for Rect
#include "math/Mat4.h"                  // for Mat4
#include "math/Vec2.h"                  // for Vec2
namespace cocos2d { class DrawNode; }
namespace cocos2d { class Event; }
namespace cocos2d { class MenuItemImage; }
namespace cocos2d { class NodeGrid; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Renderer; }
namespace cocos2d { class Sprite; }
namespace cocos2d { class Touch; }
namespace cocostudio { class BatchNode; }
namespace cocostudio { class Bone; }

#if ENABLE_PHYSICS_BOX2D_DETECT
#include "../../Box2DTestBed/GLES-Render.h"
#include "Box2D/Box2D.h"
#elif ENABLE_PHYSICS_CHIPMUNK_DETECT
#include "chipmunk.h"
#endif

class ArmatureTestScene : public TestScene
{
public: 
	ArmatureTestScene(bool bPortrait = false);

	virtual void runThisTest();

	// The CallBack for back to the main menu scene
	virtual void MainMenuCallback(cocos2d::Ref* pSender);
};

enum {
	TEST_ASYNCHRONOUS_LOADING = 0,
    TEST_DIRECT_LOADING,
	TEST_COCOSTUDIO_WITH_SKELETON,
	TEST_DRAGON_BONES_2_0,
	TEST_PERFORMANCE,
//    TEST_PERFORMANCE_BATCHNODE,
	TEST_CHANGE_ZORDER,
	TEST_ANIMATION_EVENT,
    TEST_FRAME_EVENT,
	TEST_PARTICLE_DISPLAY,
	TEST_USE_DIFFERENT_PICTURE,
	TEST_COLLIDER_DETECTOR,
	TEST_BOUDINGBOX,
	TEST_ANCHORPOINT,
	TEST_ARMATURE_NESTING,
    TEST_ARMATURE_NESTING_2,
    TEST_PLAY_SEVERAL_MOVEMENT,
    TEST_EASING,
    TEST_CHANGE_ANIMATION_INTERNAL,
	TEST_DIRECT_FROM_BINARY,
    TEST_ARMATURE_NODE,
    
	TEST_LAYER_COUNT
};

class ArmatureTestLayer : public cocos2d::Layer
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


class TestAsynchronousLoading : public ArmatureTestLayer
{
public:
	virtual void onEnter() override;
	virtual std::string title() const override;
	virtual std::string subtitle() const override;
    virtual void restartCallback(cocos2d::Ref* pSender);

	void dataLoaded(float percent);
};

class TestDirectLoading : public ArmatureTestLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class TestCSWithSkeleton : public ArmatureTestLayer
{
	virtual void onEnter() override;
	virtual std::string title() const override;
};


class TestDragonBones20 : public ArmatureTestLayer
{
public:
	virtual void onEnter() override;
	virtual std::string title() const override;
};


class TestPerformance : public ArmatureTestLayer
{
public:
	~TestPerformance();

	virtual void onEnter() override;
	virtual std::string title() const override;
	virtual std::string subtitle() const override;
    virtual void onIncrease(Ref* pSender);
    virtual void onDecrease(Ref* pSender);
    virtual void addArmature(int number);
    virtual void addArmatureToParent(cocostudio::Armature *armature);
    virtual void removeArmatureFromParent(int tag);
    virtual void refreshTitle();

	int armatureCount;

	int frames;
	float times;
	float lastTimes;
	bool generated;
};

class TestPerformanceBatchNode : public TestPerformance
{
    virtual void onEnter() override;
    virtual std::string title() const override;
    virtual void addArmatureToParent(cocostudio::Armature *armature);
    virtual void removeArmatureFromParent(int tag);

    cocostudio::BatchNode *batchNode;
};

class TestChangeZorder : public ArmatureTestLayer
{
	virtual void onEnter() override;
	virtual std::string title() const override;
	void changeZorder(float dt);

	int currentTag;
};


class TestAnimationEvent : public ArmatureTestLayer
{
public:

	virtual void onEnter() override;
	virtual std::string title() const override;
	void animationEvent(cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID);
	void callback1();
	void callback2();

	cocostudio::Armature *armature;
};


class TestFrameEvent : public ArmatureTestLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
    void onFrameEvent(cocostudio::Bone *bone, const std::string& evt, int originFrameIndex, int currentFrameIndex);
    void checkAction(float dt);
protected:
    cocos2d::NodeGrid* _gridNode;
};


class TestUseMutiplePicture : public ArmatureTestLayer
{
	virtual void onEnter() override;
	virtual void onExit() override;
	virtual std::string title() const override;
	virtual std::string subtitle() const override;
	void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;

	int displayIndex;
	cocostudio::Armature *armature;
};

class TestParticleDisplay : public ArmatureTestLayer
{
	virtual void onEnter() override;
	virtual void onExit() override;
	virtual std::string title() const override;
	virtual std::string subtitle() const override;
	void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;

	int animationID;
	cocostudio::Armature *armature;
};




#if ENABLE_PHYSICS_BOX2D_DETECT

class ContactListener;

class TestColliderDetector : public ArmatureTestLayer
{
public:
	~TestColliderDetector();

	virtual void onEnter() override;
	virtual void onExit() override;
	virtual std::string title() const override;
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::at4 &transform, uint32_t flags) override;
	virtual void update(float delta);

	void onFrameEvent(cocostudio::Bone *bone, const std::string& evt, int originFrameIndex, int currentFrameIndex);

	void initWorld();


	cocostudio::Armature *armature;
	cocostudio::Armature *armature2;

	cocos2d::extension::PhysicsSprite *bullet;

	b2World *world;
	ContactListener *listener;
	GLESDebugDraw *debugDraw;
};


#elif ENABLE_PHYSICS_CHIPMUNK_DETECT


class TestColliderDetector : public ArmatureTestLayer
{
public:
	~TestColliderDetector();

	virtual void onEnter() override;
	virtual void onExit() override;
	virtual std::string title() const override;
	virtual void update(float delta);

	void onFrameEvent(cocostudio::Bone *bone, const char *evt, int originFrameIndex, int currentFrameIndex);

	void initWorld();


	cocostudio::Armature *armature;
	cocostudio::Armature *armature2;

	cocos2d::extension::PhysicsSprite *bullet;


	cpSpace *space;

	static int beginHit(cpArbiter *arb, cpSpace *space, void *unused);
	static void endHit(cpArbiter *arb, cpSpace *space, void *unused);

	void destroyCPBody(cpBody *body);
};
#elif ENABLE_PHYSICS_SAVE_CALCULATED_VERTEX
class TestColliderDetector : public ArmatureTestLayer
{
public:
    ~TestColliderDetector();
    
    virtual void onEnter() override;
    virtual std::string title() const override;
    virtual void update(float delta);
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;
    
    void onFrameEvent(cocostudio::Bone *bone, const std::string& evt, int originFrameIndex, int currentFrameIndex);
    
    void initWorld() {};
    cocostudio::Armature *armature;
    cocostudio::Armature *armature2;
    
	cocos2d::DrawNode *drawNode;
    cocos2d::Sprite *bullet;
};
#endif





class TestBoundingBox : public ArmatureTestLayer
{
public:
	virtual void onEnter() override;
	virtual std::string title() const override;
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;

	cocostudio::Armature *armature;
	cocos2d::Rect rect;
    
protected:
	cocos2d::DrawNode* _drawNode;
};

class TestAnchorPoint : public ArmatureTestLayer
{
public:
	virtual void onEnter() override;
	virtual std::string title() const override;
};

class TestArmatureNesting : public ArmatureTestLayer
{
public:
	virtual void onEnter() override;
	virtual void onExit() override;
	virtual std::string title() const override;
	void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;

	cocostudio::Armature *armature;
	int weaponIndex;
};

class Hero : public cocostudio::Armature
{
public:
    static Hero *create(const char *name);
    Hero();

    virtual void changeMount(cocostudio::Armature *armature);
    virtual void playWithIndex(int index);

    CC_SYNTHESIZE(cocostudio::Armature*, m_pMount, Mount);
    CC_SYNTHESIZE(cocos2d::Layer*, m_pLayer, Layer);
};

class TestArmatureNesting2 : public ArmatureTestLayer
{
public:
    virtual void onEnter() override;
    virtual void onExit() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;

    void changeMountCallback(Ref* pSender);
    virtual cocostudio::Armature *createMount(const char *name, cocos2d::Vec2 position);

private:
    Hero *hero;

    cocostudio::Armature *horse;
    cocostudio::Armature *horse2;
    cocostudio::Armature *bear;


    bool touchedMenu;
};

class TestPlaySeveralMovement : public ArmatureTestLayer
{      
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};


class TestEasing : public ArmatureTestLayer
{      
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
    void updateSubTitle();

    int animationID;
    cocostudio::Armature *armature;
};

class TestChangeAnimationInternal : public ArmatureTestLayer
{
public:
    virtual void onEnter()override;
    virtual void onExit() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
};


#define BINARYFILECOUNT 6
class TestLoadFromBinary : public ArmatureTestLayer
{
public:
	virtual void onEnter() override;
    virtual std::string title() const override;
	virtual std::string subtitle() const override;
    
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
    
    
	void dataLoaded(float percent);
    
private:
    cocostudio::Armature *m_armature; // current armature
	static const char*  m_binaryFilesNames[BINARYFILECOUNT];
	static const char*  m_armatureNames[BINARYFILECOUNT];
	int m_armatureIndex;   // index of sync loaded armature, default -1 is none
};

class TestArmatureNode : public ArmatureTestLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

#endif  // __HELLOWORLD_SCENE_H__
