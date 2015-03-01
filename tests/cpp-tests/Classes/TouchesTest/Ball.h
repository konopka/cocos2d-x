#ifndef _BALL_H_
#define _BALL_H_

#include "2d/CCSprite.h"                // for Sprite
#include "platform/CCPlatformMacros.h" // for USING_NS_CC
#include "math/Vec2.h"                  // for Vec2

class Paddle;

namespace cocos2d { class Texture2D; }

USING_NS_CC;

class Ball : public Sprite
{
    Vec2 _velocity;
public:
    Ball(void);
    virtual ~Ball(void);

    float radius();
    //BOOL initWithTexture(Texture2D* aTexture);
    //virtual void setTexture(Texture2D* newTexture);
    void move(float delta);
    void collideWithPaddle(Paddle* paddle);


public:
    void setVelocity(Vec2 velocity){_velocity = velocity;}
    Vec2 getVelocity(){return _velocity;}

public:
    static Ball* ballWithTexture(Texture2D* aTexture);
};

#endif
