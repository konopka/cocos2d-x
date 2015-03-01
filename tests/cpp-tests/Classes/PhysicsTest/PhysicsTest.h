#ifndef _PHYSICS_TEST_H_
#define _PHYSICS_TEST_H_

#include <string>                       // for string
#include <unordered_map>                // for unordered_map
#include <vector>                       // for vector
#include "../BaseTest.h"                // for BaseTest
#include "../testBasic.h"               // for TestScene
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC
#include "base/ccConfig.h"              // for CC_USE_PHYSICS
#include "math/Vec2.h"                  // for Vec2
#include "physics/CCPhysicsBody.h"
#include "physics/CCPhysicsShape.h"     // for PhysicsMaterial, etc
#include "physics/CCPhysicsWorld.h"     // for PhysicsRayCastInfo, etc
namespace cocos2d { class Acceleration; }
namespace cocos2d { class DrawNode; }
namespace cocos2d { class Event; }
namespace cocos2d { class MenuItemFont; }
namespace cocos2d { class Node; }
namespace cocos2d { class PhysicsContact; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Size; }
namespace cocos2d { class Sprite; }
namespace cocos2d { class SpriteBatchNode; }
namespace cocos2d { class Texture2D; }
namespace cocos2d { class Touch; }

class PhysicsTestScene : public TestScene
{
public:
    PhysicsTestScene();
    
public:
    virtual void runThisTest();
    
    void toggleDebug();
    
private:
    bool _debugDraw;
};

#if CC_USE_PHYSICS == 0
class PhysicsDemoDisabled : public BaseTest
{
public:
    CREATE_FUNC(PhysicsDemoDisabled);
    
    virtual void onEnter() override;
};
#else

class PhysicsDemo : public BaseTest
{
public:
    CREATE_FUNC(PhysicsDemo);

    PhysicsDemo();
    virtual ~PhysicsDemo();
    
    virtual void onEnter() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    
    void restartCallback(cocos2d::Ref* sender) override;
    void nextCallback(cocos2d::Ref* sender) override;
    void backCallback(cocos2d::Ref* sender) override;
    void toggleDebugCallback(cocos2d::Ref* sender);
    
    cocos2d::Sprite* addGrossiniAtPosition(cocos2d::Vec2 p, float scale = 1.0);
    cocos2d::Sprite* makeBall(cocos2d::Vec2 point, float radius, cocos2d::PhysicsMaterial material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);
    cocos2d::Sprite* makeBox(cocos2d::Vec2 point, cocos2d::Size size, int color = 0, cocos2d::PhysicsMaterial material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);
    cocos2d::Sprite* makeTriangle(cocos2d::Vec2 point, cocos2d::Size size, int color = 0, cocos2d::PhysicsMaterial material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);
    
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) override;
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;
    
protected:
    PhysicsTestScene* _scene;
	cocos2d::Texture2D* _spriteTexture;    // weak ref
	cocos2d::SpriteBatchNode* _ball;
    std::unordered_map<int, cocos2d::Node*> _mouses;
};

class PhysicsDemoClickAdd : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoClickAdd);

    virtual ~PhysicsDemoClickAdd();
    void onEnter() override;
    virtual std::string subtitle() const override;
    
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
    void onAcceleration(cocos2d::Acceleration* acc, cocos2d::Event* event) override;
};

class PhysicsDemoLogoSmash : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoLogoSmash);

    void onEnter() override;
    virtual std::string title() const override;
};

class PhysicsDemoPyramidStack : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoPyramidStack);

    void onEnter() override;
    void updateOnce(float delta);
    virtual std::string title() const override;
};

class PhysicsDemoRayCast : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoRayCast);

    PhysicsDemoRayCast();

    void onEnter() override;
    virtual std::string title() const override;
    void update(float delta) override;
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
    
    void changeModeCallback(cocos2d::Ref* sender);
    
    bool anyRay(cocos2d::PhysicsWorld& world, const cocos2d::PhysicsRayCastInfo& info, void* data);
    
private:
    float _angle;
	cocos2d::DrawNode* _node;
    int _mode;
};

class PhysicsDemoJoints : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoJoints);

    void onEnter() override;
    virtual std::string title() const override;
};

class PhysicsDemoActions : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoActions);

    void onEnter() override;
    virtual std::string title() const override;
};

class PhysicsDemoPump : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoPump);

    void onEnter() override;
    void update(float delta) override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) override;
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;
    
private:
    float _distance;
    float _rotationV;
};

class PhysicsDemoOneWayPlatform : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoOneWayPlatform);

    void onEnter() override;
    virtual std::string title() const override;
    
    bool onContactBegin(cocos2d::PhysicsContact& contact);
};

class PhysicsDemoSlice : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoSlice);

    void onEnter() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    
    bool slice(cocos2d::PhysicsWorld& world, const cocos2d::PhysicsRayCastInfo& info, void* data);
    void clipPoly(cocos2d::PhysicsShapePolygon* shape, cocos2d::Vec2 normal, float distance);
    
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) override;
    
private:
    int _sliceTag;
};

class PhysicsDemoBug3988 : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsDemoBug3988);

    void onEnter() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class PhysicsContactTest : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsContactTest);
    
    void onEnter() override;
    void resetTest();
    bool onContactBegin(cocos2d::PhysicsContact& contact);
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    
    void onDecrease(Ref* sender);
    void onIncrease(Ref* sender);
    
private:
    int _yellowBoxNum;
    int _blueBoxNum;
    int _yellowTriangleNum;
    int _blueTriangleNum;
};

class PhysicsPositionRotationTest : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsPositionRotationTest);
    
    void onEnter() override;
    virtual std::string title() const override;
};

class PhysicsSetGravityEnableTest : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsSetGravityEnableTest);
    
    void onEnter() override;
    void onScheduleOnce(float delta);
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class Bug5482 : public PhysicsDemo
{
public:
    CREATE_FUNC(Bug5482);
    
    void onEnter() override;
    void onExit() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    
    void changeBodyCallback(cocos2d::Ref* sender);
private:
    cocos2d::Sprite* _nodeA;
    cocos2d::Sprite* _nodeB;
    cocos2d::PhysicsBody* _body;
    cocos2d::MenuItemFont* _button;
    bool _bodyInA;
};

class PhysicsFixedUpdate : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsFixedUpdate);
    void onEnter() override;
    void updateStart(float delta);
    void addBall();
    virtual void update(float delta) override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class PhysicsTransformTest : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsTransformTest);
    
    void onEnter() override;
    virtual std::string title() const override;
    
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;
    
};

class PhysicsIssue9959 : public PhysicsDemo
{
public:
    CREATE_FUNC(PhysicsIssue9959);
    
    void onEnter() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

#endif
#endif
