#ifndef __BUG_914_H__
#define __BUG_914_H__

#include <vector>                       // for vector
#include "BugsTest.h"                   // for BugsTestBaseLayer
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC
namespace cocos2d { class Event; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Scene; }
namespace cocos2d { class Touch; }

class Bug914Layer : public BugsTestBaseLayer
{
public:
    static cocos2d::Scene* scene();
    virtual bool init() override;

    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event) override;
    void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * event) override;
    void restart(cocos2d::Ref* sender);

    CREATE_FUNC(Bug914Layer);
};

#endif // __BUG_914_H__
