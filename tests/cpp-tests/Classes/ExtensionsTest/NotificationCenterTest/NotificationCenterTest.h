#ifndef __NOTIFICATIONCENTERTEST_H__
#define __NOTIFICATIONCENTERTEST_H__

#include "2d/CCLayer.h"                 // for Layer
namespace cocos2d { class Ref; }

class NotificationCenterTest : public cocos2d::Layer
{
public:
    NotificationCenterTest();
    void toExtensionsMainLayer(cocos2d::Ref* sender);
    void toggleSwitch(cocos2d::Ref *sender);
    void connectToSwitch(cocos2d::Ref *sender);
    void doNothing(cocos2d::Ref *sender);
};

void runNotificationCenterTest();

#endif /* __NOTIFICATIONCENTERTEST_H__ */
