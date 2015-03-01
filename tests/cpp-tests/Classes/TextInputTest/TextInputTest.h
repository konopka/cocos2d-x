#ifndef __TEXT_INPUT_TEST_H__
#define __TEXT_INPUT_TEST_H__

#include <stddef.h>                     // for size_t
#include <string>                       // for string
#include "../BaseTest.h"                // for BaseTest
#include "../testBasic.h"               // for TestScene
#include "2d/CCLayer.h"                 // for Layer
#include "2d/CCTextFieldTTF.h"          // for TextFieldTTF (ptr only), etc
#include "base/CCIMEDelegate.h"         // for IMEDelegate, etc
#include "math/Vec2.h"                  // for Vec2

namespace cocos2d { class Action; }
namespace cocos2d { class Event; }
namespace cocos2d { class Node; }
namespace cocos2d { class Ref; }
namespace cocos2d { class Touch; }

class KeyboardNotificationLayer;

/**
@brief    TextInputTest for retain prev, reset, next, main menu buttons.
*/
class TextInputTest : public BaseTest
{
    KeyboardNotificationLayer * _notificationLayer;
public:
    TextInputTest();

    void restartCallback(cocos2d::Ref* sender) override;
    void nextCallback(cocos2d::Ref* sender) override;
    void backCallback(cocos2d::Ref* sender) override;

    virtual std::string title() const override;
    void addKeyboardNotificationLayer(KeyboardNotificationLayer * layer);
    
    virtual void onEnter() override;
};

//////////////////////////////////////////////////////////////////////////
// KeyboardNotificationLayer for test IME keyboard notification.
//////////////////////////////////////////////////////////////////////////

class KeyboardNotificationLayer : public cocos2d::Layer, public cocos2d::IMEDelegate
{
public:
    KeyboardNotificationLayer();

    virtual std::string subtitle() const = 0;
    virtual void onClickTrackNode(bool bClicked) = 0;

    virtual void keyboardWillShow(cocos2d::IMEKeyboardNotificationInfo& info);

    // Layer
    bool onTouchBegan(cocos2d::Touch  *touch, cocos2d::Event  *event);
    void onTouchEnded(cocos2d::Touch  *touch, cocos2d::Event  *event);

protected:
	cocos2d::Node * _trackNode;
	cocos2d::Vec2  _beginPos;
};

//////////////////////////////////////////////////////////////////////////
// TextFieldTTFDefaultTest for test TextFieldTTF default behavior.
//////////////////////////////////////////////////////////////////////////

class TextFieldTTFDefaultTest : public KeyboardNotificationLayer
{
public:
    // KeyboardNotificationLayer
    virtual std::string subtitle() const override;
    virtual void onClickTrackNode(bool bClicked) override;

    // Layer
    virtual void onEnter() override;
};

//////////////////////////////////////////////////////////////////////////
// TextFieldTTFActionTest
//////////////////////////////////////////////////////////////////////////

class TextFieldTTFActionTest : public KeyboardNotificationLayer, public cocos2d::TextFieldDelegate
{
	cocos2d::TextFieldTTF *    _textField;
	cocos2d::Action *          _textFieldAction;
    bool                _action;
    int                 _charLimit;       // the textfield max char limit

public:
    void callbackRemoveNodeWhenDidAction(cocos2d::Node * node);

    // KeyboardNotificationLayer
    virtual std::string subtitle() const override;
    virtual void onClickTrackNode(bool bClicked) override;

    // Layer
    virtual void onEnter() override;
    virtual void onExit() override;

    // TextFieldDelegate
    virtual bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF * sender) override;
    virtual bool onTextFieldDetachWithIME(cocos2d::TextFieldTTF * sender) override;
    virtual bool onTextFieldInsertText(cocos2d::TextFieldTTF * sender, const char * text, size_t nLen) override;
    virtual bool onTextFieldDeleteBackward(cocos2d::TextFieldTTF * sender, const char * delText, size_t nLen) override;
    virtual bool onDraw(cocos2d::TextFieldTTF * sender);
};

class TextInputTestScene : public TestScene
{
public:
    virtual void runThisTest();
};

#endif    // __TEXT_INPUT_TEST_H__
