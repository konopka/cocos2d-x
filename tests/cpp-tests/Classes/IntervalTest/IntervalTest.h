#ifndef _INTERVAL_TEST_H_
#define _INTERVAL_TEST_H_

#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer
namespace cocos2d { class Label; }

class IntervalLayer : public cocos2d::Layer
{
public:
    IntervalLayer(void);
    virtual ~IntervalLayer();

    virtual void update(float dt) override;

    //CREATE_NODE(IntervalLayer);

protected:
    cocos2d::Label*    _label0;
    cocos2d::Label*    _label1;
    cocos2d::Label*    _label2;
    cocos2d::Label*    _label3;
    cocos2d::Label*    _label4;

    float        _time0, _time1, _time2, _time3, _time4;
};

class IntervalTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif
