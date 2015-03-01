#ifndef __COCOS_DENSHION_TEST__
#define __COCOS_DENSHION_TEST__

#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer
class AudioSlider;
namespace cocos2d { class Node; }

class CocosDenshionTest : public cocos2d::Layer
{
public:
    CocosDenshionTest(void);
    ~CocosDenshionTest(void);

    virtual void onExit() override;

private:
    void addButtons();
    void addSliders();
    void addChildAt(cocos2d::Node *node, float percentageX, float percentageY);

    void updateVolumes(float);

    unsigned int _soundId;
    float _musicVolume;
    float _effectsVolume;
    AudioSlider *_sliderPitch;
    AudioSlider *_sliderPan;
    AudioSlider *_sliderGain;
    AudioSlider *_sliderEffectsVolume;
    AudioSlider *_sliderMusicVolume;
};

class CocosDenshionTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif //__COCOS_DENSHION_TEST__
