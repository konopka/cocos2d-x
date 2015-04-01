#include "TestHeaderLayer.h"
#include "CCPlatformMacros.h"           // for CCLOG, USING_NS_CC
#include "GUI/CCControlExtension/../../ExtensionMacros.h"
#include "base/CCDirector.h"            // for Director

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocosbuilder;

SEL_MenuHandler TestHeaderLayer::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName) {
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onBackClicked", TestHeaderLayer::onBackClicked);

    return nullptr;    
}

Control::Handler TestHeaderLayer::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName) {

    return nullptr;
}

void TestHeaderLayer::onNodeLoaded(cocos2d::Node * node, cocosbuilder::NodeLoader * nodeLoader)
{
    CCLOG("TestHeaderLayer::onNodeLoaded");
}

void TestHeaderLayer::onBackClicked(cocos2d::Ref *pSender) {
    Director::getInstance()->popScene();
}
