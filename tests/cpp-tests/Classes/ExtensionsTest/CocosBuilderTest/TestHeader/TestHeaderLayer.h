#ifndef _TESTHEADERLAYER_H_
#define _TESTHEADERLAYER_H_

#include "2d/CCLayer.h"                 // for Layer
#include "GUI/CCControlExtension/CCControl.h"  // for Control, etc
#include "base/CCRef.h"                 // for Ref (ptr only), etc
#include "cocosbuilder/CCBReader.h"
#include "cocosbuilder/CCBSelectorResolver.h"  // for CCBSelectorResolver
#include "cocosbuilder/CCNodeLoaderListener.h"  // for NodeLoaderListener
namespace cocos2d { class Node; }
namespace cocosbuilder { class NodeLoader; }

class TestHeaderLayer
    : public cocos2d::Layer
    , public cocosbuilder::CCBSelectorResolver
, public cocosbuilder::NodeLoaderListener
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(TestHeaderLayer, create);

        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
        virtual void onNodeLoaded(cocos2d::Node * node, cocosbuilder::NodeLoader * nodeLoader);
    
        void onBackClicked(cocos2d::Ref * sender);
};

#endif
