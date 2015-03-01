#ifndef _PADDLE_H_
#define _PADDLE_H_

#include "2d/CCSprite.h"                // for Sprite
#include "platform/CCPlatformMacros.h" // for USING_NS_CC
#include "base/CCRef.h"                 // for Clonable
#include "math/CCGeometry.h"            // for Rect
namespace cocos2d { class Event; }
namespace cocos2d { class Texture2D; }
namespace cocos2d { class Touch; }

USING_NS_CC;

typedef enum tagPaddleState 
{
    kPaddleStateGrabbed,
    kPaddleStateUngrabbed
} PaddleState; 

class Paddle : public Sprite, public Clonable
{
    PaddleState        _state;

public:
    Paddle(void);
    virtual ~Paddle(void);

    Rect getRect();
    bool initWithTexture(Texture2D* aTexture) override;
    virtual void onEnter() override;
    virtual void onExit() override;
    bool containsTouchLocation(Touch* touch);
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    virtual Paddle* clone() const override;

    static Paddle* createWithTexture(Texture2D* aTexture);
};

#endif
