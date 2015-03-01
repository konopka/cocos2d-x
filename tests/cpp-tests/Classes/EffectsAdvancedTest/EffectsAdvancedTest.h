#ifndef _EFFECT_ADVANCED_TEST_H_
#define _EFFECT_ADVANCED_TEST_H_

#include <string>                       // for string
#include "../BaseTest.h"                // for BaseTest
#include "../testBasic.h"               // for TestScene
namespace cocos2d { class Node; }
namespace cocos2d { class Ref; }
namespace cocos2d { class TextureAtlas; }

class EffectAdvanceTextLayer: public BaseTest
{
protected:
    cocos2d::TextureAtlas* _atlas;

    std::string    _title;

    cocos2d::Node* _bgNode;
    cocos2d::Node* _target1;
    cocos2d::Node* _target2;

public:
    virtual void onEnter() override;
    ~EffectAdvanceTextLayer(void);

    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void restartCallback(cocos2d::Ref* sender) override;
    void nextCallback(cocos2d::Ref* sender) override;
    void backCallback(cocos2d::Ref* sender) override;
};

class Effect1 : public EffectAdvanceTextLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class Effect2 : public EffectAdvanceTextLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class Effect3 : public EffectAdvanceTextLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class Effect4 : public EffectAdvanceTextLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
};

class Effect5 : public EffectAdvanceTextLayer
{
public:
    virtual void onEnter() override;
    virtual void onExit() override;
    virtual std::string title() const override;
};

class Issue631 : public EffectAdvanceTextLayer
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class EffectAdvanceScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif
