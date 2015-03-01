//#include <bits/socket_type.h>           // for SOCK_STREAM
#include <errno.h>                      // for EINTR, errno
#include <string.h>                     // for strlen, strcpy, memset, etc
#include <new>                          // for nothrow, operator new
#include <ratio>                        // for ratio
#include "2d/CCLabel.h"                 // for Label, TTFConfig
#include "2d/CCMenu.h"                  // for Menu
#include "2d/CCMenuItem.h"              // for MenuItemImage, etc
#include "2d/CCScene.h"                 // for Scene
#include "ActionManagerTest/ActionManagerTest.h"
#include "ActionsEaseTest/ActionsEaseTest.h"  // for ActionsEaseTestScene
#include "ActionsProgressTest/ActionsProgressTest.h"
#include "ActionsTest/ActionsTest.h"    // for ActionsTestScene
#include "AllocatorTest/AllocatorTest.h"  // for AllocatorTestScene
#include "BillBoardTest/BillBoardTest.h"  // for BillBoardTestScene
#include "BugsTest/BugsTest.h"          // for BugsTestScene
#include "platform/CCPlatformConfig.h"  // for CC_TARGET_PLATFORM, etc
#include "Camera3DTest/Camera3DTest.h"  // for Camera3DTestScene
#include "ChipmunkTest/ChipmunkTest.h"  // for ChipmunkAccelTouchTestScene
#include "ClickAndMoveTest/ClickAndMoveTest.h"
#include "ClippingNodeTest/ClippingNodeTest.h"
#include "CocosDenshionTest/CocosDenshionTest.h"
#include "CocosStudio3DTest/CocosStudio3DTest.h"  // for CS3DTestScene
#include "ConfigurationTest/ConfigurationTest.h"
#include "ConsoleTest/ConsoleTest.h"    // for ConsoleTestScene
#include "CurlTest/CurlTest.h"          // for CurlTestScene
#include "CurrentLanguageTest/CurrentLanguageTest.h"
#include "DrawPrimitivesTest/DrawPrimitivesTest.h"
#include "EffectsAdvancedTest/EffectsAdvancedTest.h"
#include "EffectsTest/EffectsTest.h"    // for EffectTestScene
#include "ExtensionsTest/ExtensionsTest.h"  // for ExtensionsTestScene
#include "FileUtilsTest/FileUtilsTest.h"  // for FileUtilsTestScene
#include "FontTest/FontTest.h"          // for FontTestScene
#include "InputTest/MouseTest.h"        // for MouseTestScene
#include "IntervalTest/IntervalTest.h"  // for IntervalTestScene
#include "LabelTest/LabelTest.h"        // for AtlasTestScene
#include "LabelTest/LabelTestNew.h"     // for AtlasTestSceneNew
#include "LayerTest/LayerTest.h"        // for LayerTestScene
#include "LightTest/LightTest.h"        // for LightTestScene
#include "MenuTest/MenuTest.h"          // for MenuTestScene
#include "MotionStreakTest/MotionStreakTest.h"
#include "MutiTouchTest/MutiTouchTest.h"  // for MutiTouchTestScene
#include "NewAudioEngineTest/NewAudioEngineTest.h"
#include "NewEventDispatcherTest/NewEventDispatcherTest.h"
#include "NewRendererTest/NewRendererTest.h"  // for NewRendererTestScene
#include "NodeTest/NodeTest.h"          // for CocosNodeTestScene
#include "OpenURLTest/OpenURLTest.h"    // for OpenURLTestScene
#include "ParallaxTest/ParallaxTest.h"  // for ParallaxTestScene
#include "Particle3DTest/Particle3DTest.h"  // for Particle3DTestScene
#include "ParticleTest/ParticleTest.h"  // for ParticleTestScene
#include "PerformanceTest/PerformanceTest.h"  // for PerformanceTestScene
#include "PhysicsTest/PhysicsTest.h"    // for PhysicsTestScene
#include "ReleasePoolTest/ReleasePoolTest.h"  // for ReleasePoolTestScene
#include "RenderTextureTest/RenderTextureTest.h"
#include "RotateWorldTest/RotateWorldTest.h"  // for RotateWorldTestScene
#include "SceneTest/SceneTest.h"        // for SceneTestScene
#include "SchedulerTest/SchedulerTest.h"  // for SchedulerTestScene
#include "ShaderTest/ShaderTest.h"      // for ShaderTestScene
#include "ShaderTest/ShaderTest2.h"     // for ShaderTestScene2
#include "SpineTest/SpineTest.h"        // for SpineTestScene
#include "Sprite3DTest/Sprite3DTest.h"  // for Sprite3DTestScene
#include "SpriteTest/SpriteTest.h"      // for SpriteTestScene
#include "TextInputTest/TextInputTest.h"  // for TextInputTestScene
#include "Texture2dTest/Texture2dTest.h"  // for TextureTestScene
#include "TextureCacheTest/TextureCacheTest.h"
#include "TexturePackerEncryptionTest/TextureAtlasEncryptionTest.h"
#include "TileMapTest/TileMapTest.h"    // for TileMapTestScene
#include "TileMapTest/TileMapTest2.h"   // for TileMapTestSceneNew
#include "TouchesTest/TouchesTest.h"    // for PongScene
#include "TransitionsTest/TransitionsTest.h"  // for TransitionsTestScene
#include "UITest/../BaseTest.h"         // for BaseTest
#include "UITest/../testBasic.h"        // for TestScene
#include "UnitTest/UnitTest.h"          // for UnitTestScene
#include "UserDefaultTest/UserDefaultTest.h"  // for UserDefaultTestScene
#include "VisibleRect.h"                // for VisibleRect
#include "ZwoptexTest/ZwoptexTest.h"    // for ZwoptexTestScene
#include "base/CCConsole.h"             // for Console, Console::Command
#include "base/CCDirector.h"            // for Director
#include "base/CCEventDispatcher.h"     // for EventDispatcher
#include "base/CCEventListenerMouse.h"  // for EventListenerMouse
#include "base/CCEventListenerTouch.h"  // for EventListenerTouchOneByOne, etc
#include "base/CCEventMouse.h"          // for EventMouse
#include "base/CCScheduler.h"           // for Scheduler
#include "base/CCTouch.h"               // for Touch
#include "base/ccMacros.h"              // for CC_CALLBACK_1, etc
#include "cocostudio/CCArmatureDataManager.h"  // for ArmatureDataManager
#include "CCApplication.h"				// for Application
#include "math/CCGeometry.h"            // for Size, Rect

using namespace cocos2d;

// C++ includes
#include <functional>
#include <string>
#include <chrono>
#include <thread>
// test inclues
#include "AppDelegate.h"
#include "controller.h"
#include "testResource.h"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32) && (CC_TARGET_PLATFORM != CC_PLATFORM_WP8) && (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#else
#include <io.h>
#include <WS2tcpip.h>
#endif
#include "UITest/UITest.h"

typedef struct _Controller{
	const char *test_name;
	std::function<TestScene*()> callback;
} Controller;
Controller g_aTestNames[] = {

    //
    // TESTS MUST BE ORDERED ALPHABETICALLY
    //     violators will be prosecuted
    //
	{ "ActionManager", [](){return new ActionManagerTestScene(); } },
	{ "Actions - Basic", [](){ return new ActionsTestScene(); } },
	{ "Actions - Ease", [](){return new ActionsEaseTestScene();} },
	{ "Actions - Progress", [](){return new ProgressActionsTestScene(); } },
    { "Allocator - Basic", [](){return new AllocatorTestNS::AllocatorTestScene(); } },
    { "Audio - CocosDenshion", []() { return new CocosDenshionTestScene(); } },
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    { "Audio - NewAudioEngine", []() { return new AudioEngineTestScene(); } },
#endif
#if CC_ENABLE_BOX2D_INTEGRATION
	{ "Box2d - Basic", []() { return new Box2DTestScene(); } },
	{ "Box2d - TestBed", []() { return new Box2dTestBedScene(); } },
#endif
	{ "Bugs", []() { return new BugsTestScene(); } },
	{ "Chipmunk", []() { return new ChipmunkAccelTouchTestScene(); } },
	{ "Click and Move", [](){return new ClickAndMoveTestScene(); } },
	{ "Configuration", []() { return new ConfigurationTestScene(); } },
	{ "Console", []() { return new ConsoleTestScene(); } },
	{ "Curl", []() { return new CurlTestScene(); } },
	{ "Current Language", []() { return new CurrentLanguageTestScene(); } },
    { "CocosStudio3D Test", []() { return new CS3DTestScene(); } },
    { "EventDispatcher", []() { return new EventDispatcherTestScene(); } },
	{ "Effects - Advanced", []() { return new EffectAdvanceScene(); } },
	{ "Effects - Basic", [](){return new EffectTestScene();} },
	{ "Extensions", []() { return new ExtensionsTestScene(); } },
	{ "FileUtils", []() { return new FileUtilsTestScene(); } },
	{ "Fonts", []() { return new FontTestScene(); } },
	{ "Interval", [](){return new IntervalTestScene(); } },
    { "Node: BillBoard Test", [](){  return new BillBoardTestScene(); }},
    { "Node: Camera 3D Test", [](){  return new Camera3DTestScene(); }},
	{ "Node: Clipping", []() { return new ClippingNodeTestScene(); } },
	{ "Node: Draw", [](){return new DrawPrimitivesTestScene();} },
    { "Node: Label - New API", [](){return new AtlasTestSceneNew(); } },
	{ "Node: Label - Old API", [](){return new AtlasTestScene(); } },
	{ "Node: Layer", [](){return new LayerTestScene();} },
    { "Node: Light", [](){return new LightTestScene();} },
	{ "Node: Menu", [](){return new MenuTestScene();} },
	{ "Node: MotionStreak", [](){return new MotionStreakTestScene();} },
	{ "Node: Node", [](){return new CocosNodeTestScene();} },
	{ "Node: Parallax", [](){return new ParallaxTestScene(); } },
	{ "Node: Particles", [](){return new ParticleTestScene(); } },
	{ "Node: Particle3D (PU)", [](){  return new Particle3DTestScene(); }},
	{ "Node: Physics", []() { return new PhysicsTestScene(); } },
	{ "Node: RenderTexture", [](){return new RenderTextureScene(); } },
	{ "Node: Scene", [](){return new SceneTestScene();} },
	{ "Node: Spine", []() { return new SpineTestScene(); } },
	{ "Node: Sprite", [](){return new SpriteTestScene(); } },
    { "Node: Sprite3D", [](){  return new Sprite3DTestScene(); }},
	{ "Node: TileMap", [](){return new TileMapTestScene(); } },
	{ "Node: FastTileMap", [](){return new TileMapTestSceneNew(); } },
	{ "Node: Text Input", [](){return new TextInputTestScene(); } },
    { "Node: UI", [](){  return new UITestScene(); }},
    { "Mouse", []() { return new MouseTestScene(); } },
	{ "MultiTouch", []() { return new MutiTouchTestScene(); } },
	{ "Performance tests", []() { return new PerformanceTestScene(); } },
    { "Renderer", []() { return new NewRendererTestScene(); } },
    { "ReleasePool", [](){ return new ReleasePoolTestScene(); } },
	{ "Rotate World", [](){return new RotateWorldTestScene(); } },
	{ "Scheduler", [](){return new SchedulerTestScene(); } },
#if CC_TARGET_PLATFORM != CC_PLATFORM_WP8
	{ "Shader - Basic", []() { return new ShaderTestScene(); } },
    { "Shader - Sprite", []() { return new ShaderTestScene2(); } },
#endif
	{ "Texture2D", [](){return new TextureTestScene(); } },
	{ "TextureCache", []() { return new TextureCacheTestScene(); } },
	{ "TexturePacker Encryption", []() { return new TextureAtlasEncryptionTestScene(); } },
	{ "Touches", [](){return new PongScene();} },
	{ "Transitions", [](){return new TransitionsTestScene();} },
    { "Unit Test", []() { return new UnitTestScene(); }},
    { "URL Open Test", []() { return new OpenURLTestScene(); } },
	{ "UserDefault", []() { return new UserDefaultTestScene(); } },
	{ "Zwoptex", []() { return new ZwoptexTestScene(); } }
};

static int g_testCount = sizeof(g_aTestNames) / sizeof(g_aTestNames[0]);
static Controller *currentController = nullptr;
#define LINE_SPACE          40

static Vec2 s_tCurPos = Vec2::ZERO;

//sleep for t seconds
static void wait(int t)
{
    std::chrono::milliseconds dura( t * 1000 );
    std::this_thread::sleep_for( dura );
}

TestController::TestController()
: _beginPos(Vec2::ZERO)
,_exitThread(false)
{
    // add close menu
    auto closeItem = MenuItemImage::create(s_pathClose, s_pathClose, CC_CALLBACK_1(TestController::closeCallback, this) );
    auto menu =Menu::create(closeItem, nullptr);

    menu->setPosition( Vec2::ZERO );
    closeItem->setPosition(VisibleRect::right().x - 30, VisibleRect::top().y - 30);

    // add menu items for tests
    TTFConfig ttfConfig("fonts/arial.ttf", 24);
    _itemMenu = Menu::create();
    for (int i = 0; i < g_testCount; ++i)
    {
        auto label = Label::createWithTTF(ttfConfig, g_aTestNames[i].test_name);       
        auto menuItem = MenuItemLabel::create(label, CC_CALLBACK_1(TestController::menuCallback, this));

        _itemMenu->addChild(menuItem, i + 10000);
        menuItem->setPosition(VisibleRect::center().x, (VisibleRect::top().y - (i + 1) * LINE_SPACE));
    }

    _itemMenu->setContentSize(Size(VisibleRect::getVisibleRect().size.width, (g_testCount + 1) * (LINE_SPACE)));
    _itemMenu->setPosition(s_tCurPos);
    addChild(_itemMenu);

    addChild(menu, 1);

    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(TestController::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(TestController::onTouchMoved, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    auto mouseListener = EventListenerMouse::create();
    mouseListener->onMouseScroll = CC_CALLBACK_1(TestController::onMouseScroll, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
}

TestController::~TestController()
{
}

void TestController::menuCallback(Ref * sender)
{
	Director::getInstance()->purgeCachedData();

    // get the userdata, it's the index of the menu item clicked
    auto menuItem = static_cast<MenuItem *>(sender);
    int idx = menuItem->getLocalZOrder() - 10000;

    // create the test scene and run it
    auto scene = g_aTestNames[idx].callback();

    if (scene)
    {
        scene->runThisTest();
        scene->release();
    }
}

void TestController::closeCallback(Ref * sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

bool TestController::onTouchBegan(Touch* touch, Event  *event)
{
    _beginPos = touch->getLocation();
    return true;
}

void TestController::onTouchMoved(Touch* touch, Event  *event)
{
    auto touchLocation = touch->getLocation();    
    float nMoveY = touchLocation.y - _beginPos.y;

    auto curPos  = _itemMenu->getPosition();
    auto nextPos = Vec2(curPos.x, curPos.y + nMoveY);

    if (nextPos.y < 0.0f)
    {
        _itemMenu->setPosition(Vec2::ZERO);
        return;
    }

    if (nextPos.y > ((g_testCount + 1)* LINE_SPACE - VisibleRect::getVisibleRect().size.height))
    {
        _itemMenu->setPosition(0, ((g_testCount + 1)* LINE_SPACE - VisibleRect::getVisibleRect().size.height));
        return;
    }

    _itemMenu->setPosition(nextPos);
    _beginPos = touchLocation;
    s_tCurPos   = nextPos;
}

void TestController::onMouseScroll(Event *event)
{
    auto mouseEvent = static_cast<EventMouse*>(event);
    float nMoveY = mouseEvent->getScrollY() * 6;

    auto curPos  = _itemMenu->getPosition();
    auto nextPos = Vec2(curPos.x, curPos.y + nMoveY);

    if (nextPos.y < 0.0f)
    {
        _itemMenu->setPosition(Vec2::ZERO);
        return;
    }

    if (nextPos.y > ((g_testCount + 1)* LINE_SPACE - VisibleRect::getVisibleRect().size.height))
    {
        _itemMenu->setPosition(0, ((g_testCount + 1)* LINE_SPACE - VisibleRect::getVisibleRect().size.height));
        return;
    }

    _itemMenu->setPosition(nextPos);
    s_tCurPos   = nextPos;
}


void TestController::runAllTests(int fd)
{
    AppDelegate* app = (AppDelegate *)Application::getInstance();
    Scheduler *sched = Director::getInstance()->getScheduler();
    for (int i = 0; i < g_testCount; i++)
    {

        // create the test scene and run it
        std::string  msg("autotest: running test:");
        msg += g_aTestNames[i].test_name;
        send(fd, msg.c_str(), strlen(msg.c_str()),0);
        send(fd, "\n",1,0);

        currentController = &g_aTestNames[i];
        sched->performFunctionInCocosThread( [&](){
            auto scene = currentController->callback();
            if(scene)
            {
                scene->runThisTest();
                scene->release();
            }
        } );
        wait(1);
        BaseTest* firstTest = app->getCurrentTest();
        if(firstTest == nullptr)
        {
            continue;
        }
        std::string  t1("");
        t1 += firstTest->subtitle();
        send(fd, t1.c_str(), strlen(t1.c_str()),0);
        send(fd, "\n",1,0);
        wait(2);

        while(1)
        {
            if(_exitThread)
            {
                return;
            }
            //currentTest->nextCallback(nullptr);
            sched->performFunctionInCocosThread( [&](){
                BaseTest *t = app->getCurrentTest();
                if(t != nullptr)
                {
                    t->nextCallback(nullptr);
                }
            } );
            wait(1);
            BaseTest * curTest = app->getCurrentTest();
            if(curTest == nullptr)
            {
                break;
            }
            std::string  title("");
            title += curTest->subtitle();
            send(fd, title.c_str(), strlen(title.c_str()),0);
            send(fd, "\n",1,0);
            wait(2);

            if(t1 == title)
            {
                break;
            }
        }
    }
    std::string  msg("autotest run successfully!");
    send(fd, msg.c_str(), strlen(msg.c_str()),0);
    send(fd, "\n",1,0);
    return;
}
void TestController::addConsoleAutoTest()
{
    auto console = Director::getInstance()->getConsole();
    
    static struct Console::Command autotest = {
        "autotest", 
        "testcpp autotest command, use -h to list available tests", 
        [this](int fd, const std::string& args)
        {
            Scheduler *sched = Director::getInstance()->getScheduler();
            if(args == "help" || args == "-h")
            {
                const char msg[] = "usage: autotest ActionsTest\n\tavailable tests: ";
                send(fd, msg, sizeof(msg),0);
                send(fd, "\n",1,0);
                for(int i = 0; i < g_testCount; i++)
                {
                    send(fd, "\t",1,0);
                    send(fd, g_aTestNames[i].test_name, strlen(g_aTestNames[i].test_name)+1,0);
                    send(fd, "\n",1,0);
                }
                const char help_main[] = "\tmain, return to main menu\n";
                send(fd, help_main, sizeof(help_main),0);

                const char help_next[] = "\tnext, run next test\n";
                send(fd, help_next, sizeof(help_next),0);
                
                const char help_back[] = "\tback, run prev test\n";
                send(fd, help_back, sizeof(help_back),0);
                
                const char help_restart[] = "\trestart, restart current test\n";
                send(fd, help_restart, sizeof(help_restart),0);
                return;
            }
            if(args == "main")
            {
                
                sched->performFunctionInCocosThread( [&]()
                {
                    auto scene = Scene::create();
                    auto layer = new (std::nothrow) TestController();
                    scene->addChild(layer);
                    layer->release();
                    Director::getInstance()->replaceScene(scene);
                    cocostudio::ArmatureDataManager::destroyInstance();
                } );
                return;
            }
            const char msg_notest[] = "autotest: can't detect running test.\n";
            AppDelegate* app = (AppDelegate *)Application::getInstance();
            BaseTest* currentTest = app->getCurrentTest();
            if(args == "next")
            {
                if(currentTest != nullptr)
                {
                    //currentTest->nextCallback(nullptr);
                    sched->performFunctionInCocosThread( [&](){
                            currentTest->nextCallback(nullptr);
                        } );
                }
                else
                {
                    send(fd, msg_notest, sizeof(msg_notest),0);
                }
                return;
            }
            if(args == "back")
            {
                if(currentTest != nullptr)
                {
                    sched->performFunctionInCocosThread( [&](){
                        currentTest->backCallback(nullptr);
                    } );
                }
                else
                {
                    send(fd, msg_notest, sizeof(msg_notest),0);
                }
                return;
            }

            if(args == "restart")
            {
                if(currentTest != nullptr)
                {
                    sched->performFunctionInCocosThread( [&](){
                        currentTest->restartCallback(nullptr);
                    } );
                }
                else
                {
                    send(fd, msg_notest, sizeof(msg_notest),0);
                }
                return;
            }

            if(args == "run")
            {
                _exitThread = false;
                std::thread t = std::thread( &TestController::runAllTests, this, fd);
                t.detach();
                return;
            }

            if(args == "stop")
            {
                _exitThread = true;
                std::string  msg("autotest: autotest stopped!");
                send(fd, msg.c_str(), strlen(msg.c_str()),0);
                send(fd, "\n",1,0);
                return;
            }

            for(int i = 0; i < g_testCount; i++)
            {
                if(args == g_aTestNames[i].test_name)
                {
                    currentController = &g_aTestNames[i];
                    std::string  msg("autotest: running test:");
                    msg += args;
                    send(fd, msg.c_str(), strlen(msg.c_str()),0);
                    send(fd, "\n",1,0);

                        
                    sched->performFunctionInCocosThread( [&](){
                        auto scene = currentController->callback();
                        if(scene)
                        {
                            scene->runThisTest();
                            scene->release();
                        }
                    } );
                    return;
                }
            }

            //no match found,print warning message
            std::string  msg("autotest: could not find test:");
            msg += args;
            send(fd, msg.c_str(), strlen(msg.c_str()),0);
            send(fd, "\n",1,0);
        }
        
    };
    console->addCommand(autotest);
}

void TestController::startAutoRun()
{
   
    std::thread t = std::thread( &TestController::autorun, this);
    t.detach();
}

ssize_t TestController::readline(int fd, char* ptr, size_t maxlen)
{
    size_t n, rc;
    char c;

    for( n = 0; n < maxlen - 1; n++ ) {
        if( (rc = recv(fd, &c, 1, 0)) ==1 ) {
            *ptr++ = c;
            if(c == '\n') {
                break;
            }
        } else if( rc == 0 ) {
            return 0;
        } else if( errno == EINTR ) {
            continue;
        } else {
            return -1;
        }
    }

    *ptr = 0;
    return n;
}

void TestController::autorun()
{
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int sfd, s;

    /* Obtain address(es) matching host/port */
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;    /* Allow IPv4 or IPv6 */
    hints.ai_socktype = SOCK_STREAM; /* stream socket */
    hints.ai_flags = 0;
    hints.ai_protocol = 0;          /* Any protocol */

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2),&wsaData);
#endif

    s = getaddrinfo("localhost", "5678", &hints, &result);
    if (s != 0) 
    {
       CCLOG("autotest: getaddrinfo error");
        return;
    }

    /* getaddrinfo() returns a list of address structures.
      Try each address until we successfully connect(2).
      If socket(2) (or connect(2)) fails, we (close the socket
      and) try the next address. */

    for (rp = result; rp != nullptr; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype,
                    rp->ai_protocol);
        if (sfd == -1)
            continue;

        if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1)
            break;                  /* Success */

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
        closesocket(sfd);
#else
        close(sfd);
#endif
    }

    if (rp == nullptr) {               /* No address succeeded */
        CCLOG("autotest: could not connect!");
        return;
    }

    freeaddrinfo(result);           /* No longer needed */
    
    std::string tmp = "autotest run\n";

    char cmd[512];

    strcpy(cmd, tmp.c_str());
    wait(3);
    send(sfd,cmd,strlen(cmd),0);
    while(true)
    {
        char resp[512];
        readline(sfd, resp, 512);
        if(strcmp(resp, "autotest run successfully!\n") == 0)
        {
            break;
        }
        wait(3);
    }
    
    tmp = "director end\n";
    strcpy(cmd, tmp.c_str());
    send(sfd,cmd,strlen(cmd),0);
    wait(1);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
        closesocket(sfd);
        WSACleanup();
#else
        close(sfd);
#endif
    return;
}


