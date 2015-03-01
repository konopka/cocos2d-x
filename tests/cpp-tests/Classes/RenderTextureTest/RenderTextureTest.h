#ifndef _RENDERTEXTURE_TEST_H_
#define _RENDERTEXTURE_TEST_H_

#include <stdint.h>                     // for uint32_t
#include <string>                       // for string
#include <vector>                       // for vector
#include "../BaseTest.h"                // for BaseTest
#include "../testBasic.h"               // for TestScene
#include "2d/CCSprite.h"                // for Sprite
#include "platform/CCPlatformMacros.h" // for CREATE_FUNC
#include "base/CCVector.h"              // for Vector
#include "math/Mat4.h"                  // for Mat4
#include "math/Vec2.h"                  // for Vec2
#include "renderer/CCCustomCommand.h"   // for CustomCommand
namespace cocos2d { class Event; }
namespace cocos2d { class Rect; }
namespace cocos2d { class Ref; }
namespace cocos2d { class RenderTexture; }
namespace cocos2d { class Renderer; }
namespace cocos2d { class SpriteBatchNode; }
namespace cocos2d { class Touch; }

class RenderTextureTest : public BaseTest
{
public:
    virtual void onEnter() override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void restartCallback(cocos2d::Ref* sender) override;
    void nextCallback(cocos2d::Ref* sender) override;
    void backCallback(cocos2d::Ref* sender) override;
};

class RenderTextureSave : public RenderTextureTest
{
public:
    CREATE_FUNC(RenderTextureSave);
    RenderTextureSave();
    ~RenderTextureSave();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
    void clearImage(cocos2d::Ref *pSender);
    void saveImage(cocos2d::Ref *pSender);

private:
	cocos2d::RenderTexture *_target;
	cocos2d::Vector<cocos2d::Sprite*> _brushs;
};

class RenderTextureIssue937 : public RenderTextureTest
{
public:
    CREATE_FUNC(RenderTextureIssue937);
    RenderTextureIssue937();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
};

class RenderTextureScene : public TestScene
{
public:
    virtual void runThisTest();
};

class RenderTextureZbuffer : public RenderTextureTest
{
public:
    CREATE_FUNC(RenderTextureZbuffer);
    RenderTextureZbuffer();

    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
    void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;

    void renderScreenShot();

private:
    cocos2d::SpriteBatchNode *mgr;;

    cocos2d::Sprite *sp1;
    cocos2d::Sprite *sp2;
    cocos2d::Sprite *sp3;
    cocos2d::Sprite *sp4;
    cocos2d::Sprite *sp5;
    cocos2d::Sprite *sp6;
    cocos2d::Sprite *sp7;
    cocos2d::Sprite *sp8;
    cocos2d::Sprite *sp9;
};

class RenderTextureTestDepthStencil : public RenderTextureTest
{
public:
    CREATE_FUNC(RenderTextureTestDepthStencil);
    RenderTextureTestDepthStencil();
    virtual ~RenderTextureTestDepthStencil();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;
private:
	cocos2d::CustomCommand _renderCmds[4];
    void onBeforeClear();
    void onBeforeStencil();
    void onBeforDraw();
    void onAfterDraw();
    
private:
	cocos2d::RenderTexture* _rend;
	cocos2d::Sprite* _spriteDS;
	cocos2d::Sprite* _spriteDraw;
};

class RenderTextureTargetNode : public RenderTextureTest
{
private:
    cocos2d::Sprite *sprite1, *sprite2;
    cocos2d::RenderTexture *renderTexture;
public:
    CREATE_FUNC(RenderTextureTargetNode);
    RenderTextureTargetNode();
    
    virtual void update(float t);
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    
    void touched(cocos2d::Ref* sender);
};

class RenderTexturePartTest : public RenderTextureTest
{
public:
    CREATE_FUNC(RenderTexturePartTest);
    RenderTexturePartTest();
    virtual ~RenderTexturePartTest();
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    
private:
	cocos2d::RenderTexture* _rend;
	cocos2d::Sprite* _spriteDraw;
};

class SpriteRenderTextureBug : public RenderTextureTest
{
public:
    
    class SimpleSprite : public cocos2d::Sprite
    {
    public:
        static SimpleSprite* create(const char* filename, const cocos2d::Rect &rect);
        SimpleSprite();
        ~SimpleSprite();
        virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags);
    public:
		cocos2d::RenderTexture *_rt;
    };
        
public:
    CREATE_FUNC(SpriteRenderTextureBug);
    SpriteRenderTextureBug();
    
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) override;
    virtual std::string title() const override;
    virtual std::string subtitle() const override;
    
    SimpleSprite* addNewSpriteWithCoords(const cocos2d::Vec2& p);
};

#endif
