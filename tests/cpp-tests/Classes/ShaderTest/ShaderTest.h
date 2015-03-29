#ifndef _SHADER_TEST_H_
#define _SHADER_TEST_H_

#include <stdint.h>                     // for uint32_t
#include <string>                       // for string
#include "../BaseTest.h"                // for BaseTest
#include "../testBasic.h"               // for TestScene
#include "2d/CCNode.h"                  // for Node
#include "GUI/CCControlExtension/CCControl.h"  // for Control, etc
#include "math/Mat4.h"                  // for Mat4
#include "math/Vec2.h"                  // for Vec2
#include "platform/CCPlatformMacros.h"  // for CREATE_FUNC
#include "renderer/CCCustomCommand.h"   // for CustomCommand

namespace cocos2d { class Label; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Renderer; }
namespace cocos2d { class Sprite; }
namespace cocos2d { namespace extension { class ControlSlider; } }
namespace cocos2d { namespace ui { class Slider; } }

class ShaderTestDemo : public BaseTest
{
public:
    ShaderTestDemo(void);

    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void restartCallback(cocos2d::Ref* sender) override;
    void nextCallback(cocos2d::Ref* sender) override;
    void backCallback(cocos2d::Ref* sender) override;

    CREATE_FUNC(ShaderTestDemo);
};

class ShaderMonjori : public ShaderTestDemo
{
public:
    ShaderMonjori();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual bool init() override;
};

class ShaderMandelbrot : public ShaderTestDemo
{
public:
    ShaderMandelbrot();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual bool init() override;
};

class ShaderJulia : public ShaderTestDemo
{
public:
    ShaderJulia();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual bool init() override;
};

class ShaderHeart : public ShaderTestDemo
{
public:
    ShaderHeart();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual bool init() override;
};

class ShaderFlower : public ShaderTestDemo
{
public:
    ShaderFlower();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual bool init() override;
};

class ShaderPlasma : public ShaderTestDemo
{
public:
    ShaderPlasma();

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual bool init() override;
};

class SpriteBlur;
class ShaderBlur : public ShaderTestDemo
{
public:
    ShaderBlur();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual bool init() override;
    void createSliderCtls();
    void onRadiusChanged(cocos2d::Ref* sender, cocos2d::extension::Control::EventType controlEvent);
    void onSampleNumChanged(cocos2d::Ref* sender, cocos2d::extension::Control::EventType controlEvent);
    
protected:
    SpriteBlur* _blurSprite;
	cocos2d::extension::ControlSlider* _sliderRadiusCtl;
	cocos2d::extension::ControlSlider* _sliderNumCtrl;
};

class ShaderRetroEffect : public ShaderTestDemo
{
public:
    ShaderRetroEffect();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    bool init() override;
    void update(float dt) override;
protected:
	cocos2d::Label* _label;
    float           _accum;
};

class ShaderNode : public cocos2d::Node
{
public:
    static ShaderNode* shaderNodeWithVertex(const std::string &vert, const std::string &frag);

    virtual void update(float dt) override;
    virtual void setPosition(const cocos2d::Vec2 &newPosition) override;
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;

protected:
    ShaderNode();
    ~ShaderNode();

    bool initWithVertex(const std::string &vert, const std::string &frag);
    void loadShaderVertex(const std::string &vert, const std::string &frag);

    void onDraw(const cocos2d::Mat4 &transform, uint32_t flags);

    cocos2d::Vec2 _center;
    cocos2d::Vec2 _resolution;
    float      _time;
    std::string _vertFileName;
    std::string _fragFileName;
	cocos2d::CustomCommand _customCommand;
};

class ShaderTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

class ShaderLensFlare : public ShaderTestDemo
{
public:
    ShaderLensFlare();
    
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual bool init() override;
};

class ShaderGlow : public ShaderTestDemo
{
public:
    ShaderGlow();
    
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual bool init() override;
};

class ShaderMultiTexture : public ShaderTestDemo
{
    static const int rightSpriteTag = 2014;
public:
    ShaderMultiTexture();
	cocos2d::ui::Slider* createSliderCtl();
    void changeTexture(cocos2d::Ref*);
    int _changedTextureId;
	cocos2d::Sprite *_sprite;

    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual bool init() override;
};

#endif
