//
// cocos2d
//
#ifndef __CHIPMUNKTEST_H__
#define __CHIPMUNKTEST_H__

#include <vector>                       // for vector
#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer
#include "math/Vec2.h"                  // for Vec2
namespace cocos2d { class Acceleration; }
namespace cocos2d { class Event; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Texture2D; }
namespace cocos2d { class Touch; }
namespace cocos2d { namespace extension { class PhysicsDebugNode; } }
struct cpShape;
struct cpSpace;

class ChipmunkTestLayer : public cocos2d::Layer
{
public:
    ChipmunkTestLayer();
    ~ChipmunkTestLayer();
    void onEnter() override;
    void initPhysics();
    void createResetButton();
    void reset(cocos2d::Ref* sender);

    void addNewSpriteAtPosition(cocos2d::Vec2 p);
    void update(float dt) override;
    void toggleDebugCallback(cocos2d::Ref* sender);
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
    virtual void onAcceleration(cocos2d::Acceleration* acc, cocos2d::Event* event) override;

private:
    cocos2d::Texture2D* _spriteTexture; // weak ref
#if CC_ENABLE_CHIPMUNK_INTEGRATION    
    cocos2d::extension::PhysicsDebugNode* _debugLayer; // weak ref
#endif
    cpSpace* _space; // strong ref
    cpShape* _walls[4];
};

class ChipmunkAccelTouchTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif /* __CHIPMUNKACCELTOUCHTEST_H__ */
