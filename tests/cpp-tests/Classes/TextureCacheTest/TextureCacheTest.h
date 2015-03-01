#ifndef _TEXTURECACHE_TEST_H_
#define _TEXTURECACHE_TEST_H_

#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer
namespace cocos2d { class Label; }
namespace cocos2d { class Texture2D; }

class TextureCacheTest : public cocos2d::Layer
{
public:
    TextureCacheTest();
    void addSprite();
    void loadingCallBack(cocos2d::Texture2D *texture);

private:
    cocos2d::Label *_labelLoading;
    cocos2d::Label *_labelPercent;
    int _numberOfSprites;
    int _numberOfLoadedSprites;
};

class TextureCacheTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif // _TEXTURECACHE_TEST_H_
