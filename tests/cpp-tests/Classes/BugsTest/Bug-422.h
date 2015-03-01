#ifndef __BUG_422_H__
#define __BUG_422_H__

#include "BugsTest.h"                   // for BugsTestBaseLayer
namespace cocos2d { class Node; }
namespace cocos2d { class Ref; }

class Bug422Layer : public BugsTestBaseLayer
{
public:
    virtual bool init() override;

    void reset();
    void check(Node* target);
    void menuCallback(Ref* sender);
};

#endif // __BUG_422_H__
