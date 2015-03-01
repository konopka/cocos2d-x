#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <stddef.h>                     // for size_t
#include <sys/types.h>                  // for ssize_t
#include "2d/CCLayer.h"                 // for Layer
#include "platform/CCPlatformMacros.h" // for USING_NS_CC
#include "math/Vec2.h"                  // for Vec2
namespace cocos2d { class Event; }
namespace cocos2d { class Menu; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Touch; }

USING_NS_CC;

class TestController : public Layer
{
public:
    TestController();
    ~TestController();

    void menuCallback(Ref * sender);
    void closeCallback(Ref * sender);

    bool onTouchBegan(Touch* touches, Event  *event);
    void onTouchMoved(Touch* touches, Event  *event);

    void onMouseScroll(Event *event);
    void addConsoleAutoTest();
    void autorun();
    void startAutoRun();
    void runAllTests(int fd);
    ssize_t readline(int fd, char* ptr, size_t maxlen);
private:
    Vec2 _beginPos;
    Menu* _itemMenu;
    bool _exitThread;
};

#endif
