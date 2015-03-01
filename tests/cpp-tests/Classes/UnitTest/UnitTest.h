#ifndef __UNIT_TEST__
#define __UNIT_TEST__

#include <string>                       // for string
#include "../BaseTest.h"                // for BaseTest
#include "../testBasic.h"               // for TestScene
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC
namespace cocos2d { class Node; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Value; }
namespace cocos2d { template <class K, class V> class Map; }
namespace cocos2d { template <class T> class Vector; }

class UnitTestScene : public TestScene
{
public:
    virtual void runThisTest() override;
};

class UnitTestDemo : public BaseTest
{
public:
    virtual void onEnter() override;
    virtual void onExit() override;

    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    virtual void restartCallback(cocos2d::Ref* sender) override;
    virtual void nextCallback(cocos2d::Ref* sender) override;
    virtual void backCallback(cocos2d::Ref* sender) override;
};

//-------------------------------------

class TemplateVectorTest : public UnitTestDemo
{
public:
    CREATE_FUNC(TemplateVectorTest);
    virtual void onEnter() override;
    virtual std::string subtitle() const override;
    void constFunc(const cocos2d::Vector<cocos2d::Node*>& vec) const;
};

class TemplateMapTest : public UnitTestDemo
{
public:
    CREATE_FUNC(TemplateMapTest);
    virtual void onEnter() override;
    virtual std::string subtitle() const override;
    void constFunc(const cocos2d::Map<std::string, cocos2d::Node*>& map) const;
};

class ValueTest : public UnitTestDemo
{
public:
    CREATE_FUNC(ValueTest);
    virtual void onEnter() override;
    virtual std::string subtitle() const override;
    void constFunc(const cocos2d::Value& value) const;
};

class UTFConversionTest : public UnitTestDemo
{
public:
    CREATE_FUNC(UTFConversionTest);
    virtual void onEnter() override;
    virtual std::string subtitle() const override;
};

class MathUtilTest : public UnitTestDemo
{
public:
    CREATE_FUNC(MathUtilTest);
    virtual void onEnter() override;
    virtual std::string subtitle() const override;
};

#endif /* __UNIT_TEST__ */
