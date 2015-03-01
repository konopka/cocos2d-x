#ifndef _SHADER_TEST2_H_
#define _SHADER_TEST2_H_

#include <sys/types.h>                  // for ssize_t
#include <string>                       // for string
#include <vector>                       // for vector
#include "../BaseTest.h"                // for BaseTest
#include "../testBasic.h"               // for TestScene
#include "platform/CCPlatformConfig.h"  // for CC_TARGET_PLATFORM, etc
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC
#include "GUI/CCControlExtension/../../ExtensionMacros.h"
#include "base/CCRef.h"                 // for Ref
#include "base/CCVector.h"              // for Vector
namespace cocos2d { class Event; }
namespace cocos2d { class EventListenerCustom; }
namespace cocos2d { class GLProgramState; }
namespace cocos2d { class Sprite; }
namespace cocos2d { class Touch; }

class ShaderTestDemo2 : public BaseTest
{
public:
    ShaderTestDemo2(void);
    virtual std::string title() const override { return "Effects on Sprites";}
    void restartCallback(cocos2d::Ref* sender) override;
    void nextCallback(cocos2d::Ref* sender) override;
    void backCallback(cocos2d::Ref* sender) override;
};

class ShaderTestScene2 : public TestScene
{
public:
    CREATE_FUNC(ShaderTestScene2);
    virtual void runThisTest();
};


//
// Effect
//
class EffectSprite;

class Effect : public cocos2d::Ref
{
public:
	cocos2d::GLProgramState* getGLProgramState() const { return _glprogramstate; }
    virtual void setTarget(EffectSprite *sprite){}

protected:
    bool initGLProgramState(const std::string &fragmentFilename);
    Effect();
    virtual ~Effect();
	cocos2d::GLProgramState *_glprogramstate;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WP8 || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    std::string _fragSource;
    cocos2d::EventListenerCustom* _backgroundListener;
#endif
};

class EffectSpriteTest : public ShaderTestDemo2
{
public:
    CREATE_FUNC(EffectSpriteTest);
    EffectSpriteTest();
    virtual std::string subtitle() const {return "Different effects on Sprite";}

protected:
    ssize_t _vectorIndex;
    cocos2d::Vector<Effect*> _effects;
    EffectSprite *_sprite;
};

class EffectSpriteLamp : public ShaderTestDemo2
{
public:
    CREATE_FUNC(EffectSpriteLamp);
    EffectSpriteLamp();
    virtual std::string subtitle() const {return "Sprite Lamp effects";}
    //callback
public:
    virtual void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event) override;
    virtual void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event) override;
    virtual void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event) override;
protected:
    EffectSprite *_sprite;
    Effect* _effect;
	cocos2d::Sprite* _lightSprite;
};

#endif
