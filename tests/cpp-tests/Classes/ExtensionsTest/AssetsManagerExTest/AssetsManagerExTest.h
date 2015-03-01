#ifndef __AssetsManagerEx_Test_H__
#define __AssetsManagerEx_Test_H__

#include <string>                       // for string
#include "../../BaseTest.h"             // for BaseTest
#include "../../testBasic.h"            // for TestScene
#include "platform/CCPlatformMacros.h" // for USING_NS_CC
#include "GUI/CCControlExtension/../../ExtensionMacros.h"
namespace cocos2d { class Label; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Sprite; }
namespace cocos2d { namespace extension { class AssetsManagerEx; } }
namespace cocos2d { namespace extension { class EventListenerAssetsManagerEx; } }

USING_NS_CC;
USING_NS_CC_EXT;

class AssetsManagerExTestLayer : public BaseTest
{
public:
    AssetsManagerExTestLayer(const std::string& spritePath);
    ~AssetsManagerExTestLayer(void);
    
    virtual std::string title() const override;
    void onEnter() override;
    
    virtual void restartCallback(Ref* sender) override;
    virtual void nextCallback(Ref* sender) override;
    virtual void backCallback(Ref* sender) override;
    
private:
    Sprite *_background;
    std::string _spritePath;
};

class AssetsManagerExTestScene : public TestScene
{
public:
    AssetsManagerExTestScene(std::string background);
    virtual void runThisTest() override;
};

class AssetsManagerExLoaderScene : public TestScene
{
public:
    AssetsManagerExLoaderScene();
    
    virtual void runThisTest() override;
    
    virtual void onExit() override;
    
    static int currentScene;
    
private:
    AssetsManagerEx *_am;
    Label *_progress;
    EventListenerAssetsManagerEx* _amListener;
};

#endif /* defined(__AssetsManagerEx_Test_H__) */
