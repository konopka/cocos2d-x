#ifndef _MENUTESTLAYER_H_
#define _MENUTESTLAYER_H_

#include "2d/CCLayer.h"                 // for Layer
#include "GUI/CCControlExtension/CCControl.h"  // for Control, etc
#include "base/CCRef.h"                 // for Ref (ptr only), etc
#include "cocosbuilder/CCBMemberVariableAssigner.h"
#include "cocosbuilder/CCBReader.h"
#include "cocosbuilder/CCBSelectorResolver.h"  // for CCBSelectorResolver
namespace cocos2d { class Label; }
namespace cocos2d { class Node; }

class MenuTestLayer
    : public cocos2d::Layer
    , public cocosbuilder::CCBSelectorResolver
    , public cocosbuilder::CCBMemberVariableAssigner 
{
    public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MenuTestLayer, create);

        MenuTestLayer();
        virtual ~MenuTestLayer();

        virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
        virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
        virtual bool onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * node);

        void onMenuItemAClicked(cocos2d::Ref * sender);
        void onMenuItemBClicked(cocos2d::Ref * sender);
        void onMenuItemCClicked(cocos2d::Ref * sender);

    private:
        cocos2d::Label * mMenuItemStatusLabelBMFont;
};

#endif
