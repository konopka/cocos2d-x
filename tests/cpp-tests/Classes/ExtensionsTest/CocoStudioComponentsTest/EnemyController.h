#ifndef __CC_ENEMYCONTROLLER_H__
#define __CC_ENEMYCONTROLLER_H__

#include "cocostudio/CCComController.h"  // for ComController

class EnemyController : public cocostudio::ComController
{
protected:
    EnemyController(void);
    virtual ~EnemyController(void);
        
public:
    virtual bool init() override;
    virtual void onEnter() override;
    virtual void onExit() override;
    virtual void update(float delta) override;
   
    static EnemyController* create(void);
public:
    void die();
};


#endif  // __FUNDATION__CCCOMPONENT_H__
