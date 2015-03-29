/****************************************************************************
 Copyright (c) 2014 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __cocos2d_libs__NodeReader__
#define __cocos2d_libs__NodeReader__

#include "platform/CCGL.h"              // for GLubyte
#include <stdlib.h>                     // for atof, atoi, atol
#include <string>                       // for operator==, string, etc
#include "CCPlatformMacros.h"           // for CC_SAFE_DELETE, USING_NS_CC
#include "base/ccTypes.h"               // for Color4B, Color3B
#include "math/CCGeometry.h"            // for Size
#include "math/Vec2.h"                  // for Vec2, Vec2::ZERO, Point
#include "cocostudio/WidgetReader/NodeReaderProtocol.h"
#include "cocostudio/WidgetReader/NodeReaderDefine.h"

namespace cocostudio
{
    class CC_STUDIO_DLL NodeReader : public cocos2d::Ref, public NodeReaderProtocol
    {
        DECLARE_CLASS_NODE_READER_INFO
        
    public:
        NodeReader();
        ~NodeReader();
        
        static NodeReader* getInstance();
        static void purge();
        
        flatbuffers::Offset<flatbuffers::Table> createOptionsWithFlatBuffers(const tinyxml2::XMLElement* objectData,
                                                                             flatbuffers::FlatBufferBuilder* builder);
        void setPropsWithFlatBuffers(cocos2d::Node* node, const flatbuffers::Table* nodeOptions);
        void setLayoutComponentPropsWithFlatBuffers(cocos2d::Node* node, const flatbuffers::Table* nodeOptions);
        cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
    };
}

#endif /* defined(__cocos2d_libs__NodeReader__) */
