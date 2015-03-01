#ifndef __BUG_458_H__
#define __BUG_458_H__

#include "../BugsTest.h"                // for BugsTestBaseLayer
namespace cocos2d { class Ref; }

class Bug458Layer : public BugsTestBaseLayer
{
public:
    virtual bool init() override;
    void selectAnswer(Ref* sender);
};

#endif // __BUG_458_H__
