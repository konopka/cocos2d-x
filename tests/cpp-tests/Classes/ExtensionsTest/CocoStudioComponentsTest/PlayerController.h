#ifndef __CC_PLAYERCONTROLLER_H__
#define __CC_PLAYERCONTROLLER_H__

#include <vector>                       // for vector
#include "cocostudio/CCComController.h"  // for ComController
namespace cocos2d { class Event; }
namespace cocos2d { class Touch; }

class PlayerController : public cocostudio::ComController
{
protected:
    PlayerController(void);
    virtual ~PlayerController(void);
    
public:
    virtual void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event  *event) override;
    
public:
    virtual bool init() override;
    virtual void onEnter() override;
    virtual void onExit() override;
    virtual void update(float delta) override;
   
   static PlayerController* create(void);
};


#endif  // __FUNDATION__CCCOMPONENT_H__
