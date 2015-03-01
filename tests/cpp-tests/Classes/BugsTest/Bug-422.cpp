//
// Bug-422 test case by lhunath
// http://code.google.com/p/cocos2d-iphone/issues/detail?id=422
//

#include "Bug-422.h"
#include <functional>                   // for _Bind
#include "2d/CCMenu.h"                  // for Menu
#include "2d/CCMenuItem.h"              // for MenuItemFont, etc
#include "2d/CCNode.h"                  // for Node
#include "BugsTest/BugsTest.h"          // for BugsTestBaseLayer
#include "base/CCConsole.h"             // for log
#include "base/ccMacros.h"              // for CCRANDOM_0_1, CC_CALLBACK_1
#include "math/Vec2.h"                  // for Vec2

using namespace cocos2d;

bool Bug422Layer::init()
{
    if (BugsTestBaseLayer::init())
    {
        reset();
        return true;
    }

    return false;
}

void Bug422Layer::reset()
{
    static int localtag = 0;
    localtag++;

    // TO TRIGGER THE BUG:
    // remove the itself from parent from an action
    // The menu will be removed, but the instance will be alive
    // and then a new node will be allocated occupying the memory.
    // => CRASH BOOM BANG
    auto node = getChildByTag(localtag-1);
    log("Menu: %p", node);
    removeChild(node, true);
//    [self removeChildByTag:localtag-1 cleanup:NO];

    auto item1 = MenuItemFont::create("One", CC_CALLBACK_1(Bug422Layer::menuCallback, this) );
    log("MenuItemFont: %p", item1);
	MenuItem *item2 = MenuItemFont::create("Two", CC_CALLBACK_1(Bug422Layer::menuCallback, this) );
    auto menu = Menu::create(item1, item2, nullptr);
    menu->alignItemsVertically();

    float x = CCRANDOM_0_1() * 50;
    float y = CCRANDOM_0_1() * 50;
    menu->setPosition(menu->getPosition() + Vec2(x,y));
    addChild(menu, 0, localtag);    

    //[self check:self];
}

void Bug422Layer::check(Node* t)
{
    auto& children = t->getChildren();
    for(const auto &child : children) {
        log("%p, rc: %d", child, child->getReferenceCount());
        check(child);
    }
}

void Bug422Layer::menuCallback(Ref* sender)
{
    reset();
}
