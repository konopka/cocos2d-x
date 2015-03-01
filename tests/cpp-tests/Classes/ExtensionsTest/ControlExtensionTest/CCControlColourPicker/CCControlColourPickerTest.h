/*
 * ControlColourPickerTest.h
 *
 * Copyright (c) 2012 Yannick Loriot
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#include "../CCControlScene.h"          // for CONTROL_SCENE_CREATE_FUNC, etc
#include "platform/CCPlatformMacros.h" // for CC_SYNTHESIZE_RETAIN
#include "GUI/CCControlExtension/../../ExtensionMacros.h"
#include "GUI/CCControlExtension/CCControl.h"  // for Control, etc
namespace cocos2d { class Label; }
namespace cocos2d { class Ref; }

class ControlColourPickerTest : public ControlScene
{
public:
    ControlColourPickerTest();
    virtual ~ControlColourPickerTest();
    bool init();
    /** Callback for the change value. */
    void colourValueChanged(cocos2d::Ref *sender, cocos2d::extension::Control::EventType controlEvent);

    CC_SYNTHESIZE_RETAIN(cocos2d::Label*, _colorLabel, ColorLabel)

    CONTROL_SCENE_CREATE_FUNC(ControlColourPickerTest)
};

