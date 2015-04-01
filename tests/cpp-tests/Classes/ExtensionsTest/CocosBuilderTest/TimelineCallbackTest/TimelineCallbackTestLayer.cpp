#include "TimelineCallbackTestLayer.h"
#include "2d/CCActionInterval.h"        // for RotateBy
#include "2d/CCLabel.h"                 // for Label
#include "CCPlatformMacros.h"           // for CC_SAFE_RELEASE, etc
#include "GUI/CCControlExtension/../../ExtensionMacros.h"
#include "audio/include/SimpleAudioEngine.h"  // for SimpleAudioEngine

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace cocosbuilder;

TimelineCallbackTestLayer::TimelineCallbackTestLayer()
: _helloLabel(nullptr)
{}

TimelineCallbackTestLayer::~TimelineCallbackTestLayer()
{
    CC_SAFE_RELEASE(_helloLabel);
    CocosDenshion::SimpleAudioEngine::end();
}

SEL_MenuHandler TimelineCallbackTestLayer::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName) {
    return nullptr;
}

Control::Handler TimelineCallbackTestLayer::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName) {
    return nullptr;
}

SEL_CallFuncN TimelineCallbackTestLayer::onResolveCCBCCCallFuncSelector(Ref * pTarget, const char* pSelectorName)
{
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onCallback1", TimelineCallbackTestLayer::onCallback1);
    CCB_SELECTORRESOLVER_CALLFUNC_GLUE(this, "onCallback2", TimelineCallbackTestLayer::onCallback2);
    return nullptr;
}

bool TimelineCallbackTestLayer::onAssignCCBMemberVariable(Ref * pTarget, const char * pMemberVariableName, Node * pNode) {
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "helloLabel", Label *, this->_helloLabel);
    
    return false;
}

void TimelineCallbackTestLayer::onCallback1(Node* sender)
{
    // Rotate the label when the button is pressed
    this->_helloLabel->runAction(RotateBy::create(1,360));
    this->_helloLabel->setString("Callback 1");
}

void TimelineCallbackTestLayer::onCallback2(Node* sender)
{
    // Rotate the label when the button is pressed
    this->_helloLabel->runAction(RotateBy::create(1,-360));
    this->_helloLabel->setString("Callback 2");
}
