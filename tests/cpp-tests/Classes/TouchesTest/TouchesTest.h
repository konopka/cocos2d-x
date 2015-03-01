#ifndef _TOUCHES_TEST__H_
#define _TOUCHES_TEST__H_

#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer
#include "platform/CCPlatformMacros.h" // for USING_NS_CC
#include "base/CCVector.h"              // for Vector
#include "math/Vec2.h"                  // for Vec2

USING_NS_CC;

class PongScene : public TestScene
{
public:
    PongScene();

    virtual void runThisTest();
};

class Ball;
class Paddle;
class PongLayer : public Layer
{
private:
    Ball*       _ball;
    Vector<Paddle*>    _paddles;
    Vec2     _ballStartingVelocity; 
public:
    PongLayer();
    ~PongLayer();

    void resetAndScoreBallForPlayer(int player);
    void doStep(float delta);
};

#endif
