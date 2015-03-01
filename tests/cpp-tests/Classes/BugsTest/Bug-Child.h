//
//  Bug-Child.h
//  cocos2d_tests
//
//  Created by NiTe Luo on 5/12/14.
//
//

#ifndef __Bug_Child__
#define __Bug_Child__

#include "BugsTest.h"                   // for BugsTestBaseLayer
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC
namespace cocos2d { class Menu; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Scene; }
namespace cocos2d { class Sprite; }

class BugChild : public BugsTestBaseLayer
{
public:
    static cocos2d::Scene* scene();
    virtual bool init() override;
    
    void switchChild(cocos2d::Ref* sender);
    
    CREATE_FUNC(BugChild);
    
protected:
    
	cocos2d::Sprite* parent1;
	cocos2d::Sprite* parent2;
    
	cocos2d::Sprite* child;
    
	cocos2d::Menu* menu;
};

#endif /* defined(__Bug_Child__) */
