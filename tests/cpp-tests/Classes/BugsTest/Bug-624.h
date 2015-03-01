#ifndef __BUG_624_H__
#define __BUG_624_H__

#include "BugsTest.h"                   // for BugsTestBaseLayer
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC
namespace cocos2d { class Acceleration; }
namespace cocos2d { class Event; }

class Bug624Layer : public BugsTestBaseLayer
{
public:
    virtual ~Bug624Layer();
    virtual bool init() override;
    void switchLayer(float dt);
    virtual void onAcceleration(cocos2d::Acceleration* acc, cocos2d::Event* event) override;

    CREATE_FUNC(Bug624Layer);
};

class Bug624Layer2 : public BugsTestBaseLayer
{
public:
    virtual ~Bug624Layer2();
    virtual bool init() override;
    void switchLayer(float dt);
    virtual void onAcceleration(cocos2d::Acceleration* acc, cocos2d::Event* event) override;

    CREATE_FUNC(Bug624Layer2);
};

#endif // __BUG_624_H__
