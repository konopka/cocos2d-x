

#ifndef __TestCpp__UISliderTest_Editor__
#define __TestCpp__UISliderTest_Editor__

#include "../UIScene_Editor.h"          // for UIScene_Editor, etc
#include "ui/UISlider.h"                // for Slider, Slider::EventType
namespace cocos2d { class Ref; }
namespace cocos2d { namespace ui { class Text; } }

class UISliderTest_Editor : public UIScene_Editor
{
public:
    UISliderTest_Editor();
    ~UISliderTest_Editor();
    bool init();
    void sliderEvent(cocos2d::Ref* pSender, cocos2d::ui::Slider::EventType type);
    virtual void switchLoadMethod(cocos2d::Ref* pSender);
    void configureGUIScene();

protected:
    UI_SCENE_EDITOR_CREATE_FUNC(UISliderTest_Editor)
    cocos2d::ui::Text* _displayValueLabel;
};

#endif /* defined(__TestCpp__UISliderTest_Editor__) */
