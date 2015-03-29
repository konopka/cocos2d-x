

#ifndef __TestCpp__UIRichTextTest__
#define __TestCpp__UIRichTextTest__

#include "../UIScene.h"                 // for UIScene, etc
#include "ui/UIWidget.h"                // for Widget, etc
namespace cocos2d { class Ref; }
namespace cocos2d { namespace ui { class RichText; } }

class UIRichTextTest : public UIScene
{
public:
    UIRichTextTest();
    ~UIRichTextTest();
    bool init();
    void touchEvent(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    
protected:
    UI_SCENE_CREATE_FUNC(UIRichTextTest)
    
protected:
    cocos2d::ui::RichText* _richText;
};

#endif /* defined(__TestCpp__UIRichTextTest__) */
