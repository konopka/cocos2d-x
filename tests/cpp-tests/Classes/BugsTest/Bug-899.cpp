//
// Bug-899
// http://code.google.com/p/cocos2d-iphone/issues/detail?id=899
//
// Test coded by: JohnnyFlash
//

#include "Bug-899.h"
#include "2d/CCSprite.h"                // for Sprite
#include "BugsTest/BugsTest.h"          // for BugsTestBaseLayer
#include "math/Vec2.h"                  // for Vec2, Vec2::ZERO

using namespace cocos2d;

bool Bug899Layer::init()
{
//    Director::getInstance()->enableRetinaDisplay(true);
    if (BugsTestBaseLayer::init())
    {
        auto bg = Sprite::create("Images/bugs/RetinaDisplay.jpg");
        addChild(bg, 0);
        bg->setAnchorPoint(Vec2::ZERO);

        return true;
    }
    return false;
}
