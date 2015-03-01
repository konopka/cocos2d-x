//
// Bug-350 
// http://code.google.com/p/cocos2d-iphone/issues/detail?id=350
//

#include "Bug-350.h"
#include "2d/CCSprite.h"                // for Sprite
#include "BugsTest/BugsTest.h"          // for BugsTestBaseLayer
#include "base/CCDirector.h"            // for Director
#include "math/CCGeometry.h"            // for Size

bool Bug350Layer::init()
{
    if (BugsTestBaseLayer::init())
    {
        auto size = cocos2d::Director::getInstance()->getWinSize();
        auto background = cocos2d::Sprite::create("Hello.png");
        background->setPosition(size.width/2, size.height/2);
        addChild(background);
        return true;
    }

    return false;
}
