#ifndef _TextureAtlasEncryption_TEST_H_
#define _TextureAtlasEncryption_TEST_H_

#include <string>                       // for string
#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer

class TextureAtlasEncryptionDemo : public cocos2d::Layer
{
public:
    virtual std::string title() const;
    virtual std::string subtitle() const;
    virtual void onEnter() override;

protected:
    std::string    _title;
};

class TextureAtlasEncryptionTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif
