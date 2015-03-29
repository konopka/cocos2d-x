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

#include "ParticleReader.h"
#include <string>                       // for string, operator==, etc
#include "2d/CCLabel.h"                 // for Label
#include "2d/CCParticleSystem.h"        // for ParticleSystem, etc
#include "2d/CCParticleSystemQuad.h"    // for ParticleSystemQuad
#include "CCFileUtils.h"                // for FileUtils
#include "CCPlatformMacros.h"           // for CC_SAFE_DELETE, USING_NS_CC
#include "cocostudio/CSParseBinary_generated.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"
#include "deprecated/CCString.h"        // for __String
#include "flatbuffers/flatbuffers.h"    // for Table (ptr only), etc
#include "tinyxml2.h"                   // for XMLElement, XMLAttribute

USING_NS_CC;
using namespace flatbuffers;

namespace cocostudio
{
    IMPLEMENT_CLASS_NODE_READER_INFO(ParticleReader)
    
    ParticleReader::ParticleReader()
    {
        
    }
    
    ParticleReader::~ParticleReader()
    {
        
    }
    
    static ParticleReader* _instanceParticleReader = nullptr;
    
    ParticleReader* ParticleReader::getInstance()
    {
        if (!_instanceParticleReader)
        {
            _instanceParticleReader = new ParticleReader();
        }
        
        return _instanceParticleReader;
    }
    
    void ParticleReader::purge()
    {
        CC_SAFE_DELETE(_instanceParticleReader);
    }
    
    Offset<Table> ParticleReader::createOptionsWithFlatBuffers(const tinyxml2::XMLElement *objectData,
                                                               flatbuffers::FlatBufferBuilder *builder)
    {
        auto temp = NodeReader::getInstance()->createOptionsWithFlatBuffers(objectData, builder);
        auto nodeOptions = *(Offset<WidgetOptions>*)(&temp);
        
        std::string path = "";
        std::string plistFile = "";
        int resourceType = 0;
        
        // child elements
        const tinyxml2::XMLElement* child = objectData->FirstChildElement();
        while (child)
        {
            std::string name = child->Name();
            
            if (name == "FileData")
            {
                const tinyxml2::XMLAttribute* attribute = child->FirstAttribute();
                
                while (attribute)
                {
                    name = attribute->Name();
                    std::string value = attribute->Value();
                    
                    if (name == "Path")
                    {
                        path = value;
                    }
                    else if (name == "Type")
                    {
                        resourceType = 0;
                    }
                    else if (name == "Plist")
                    {
                        plistFile = value;
                    }
                    
                    attribute = attribute->Next();
                }
            }
            
            child = child->NextSiblingElement();
        }
        
        auto options = CreateParticleSystemOptions(*builder,
                                                   nodeOptions,
                                                   CreateResourceData(*builder,
                                                                      builder->CreateString(path),
                                                                      builder->CreateString(plistFile),
                                                                      resourceType));
        
        return *(Offset<Table>*)(&options);
    }
    
    void ParticleReader::setPropsWithFlatBuffers(cocos2d::Node *node,
                                                 const flatbuffers::Table *particleOptions)
    {
        auto options = (ParticleSystemOptions*)particleOptions;
        auto nodeReader = NodeReader::getInstance();
        nodeReader->setPropsWithFlatBuffers(node, (Table*)options->nodeOptions());
    }
    
    Node* ParticleReader::createNodeWithFlatBuffers(const flatbuffers::Table *particleOptions)
    {
        ParticleSystemQuad* particle = nullptr;
        
        auto options = (ParticleSystemOptions*)particleOptions;
        auto fileNameData = options->fileNameData();
        
        bool fileExist = false;
        std::string errorFilePath = "";
        std::string path = fileNameData->path()->c_str();
        int resourceType = fileNameData->resourceType();
        switch (resourceType)
        {
            case 0:
            {
                if (FileUtils::getInstance()->isFileExist(path))
                {
                    fileExist = true;
                }
                else
                {
                    errorFilePath = path;
                    fileExist = false;
                }
                break;
            }
                
            default:
                break;
        }
        if (fileExist)
        {
            particle = ParticleSystemQuad::create(path);
            if (particle)
            {
                setPropsWithFlatBuffers(particle, (Table*)particleOptions);
                particle->setPositionType(ParticleSystem::PositionType::GROUPED);
            }
        }
        else
        {
            Node* node = Node::create();
            setPropsWithFlatBuffers(node, (Table*)particleOptions);
            auto label = Label::create();
            label->setString(__String::createWithFormat("%s missed", errorFilePath.c_str())->getCString());
            node->addChild(label);
            return node;
        }
        
        return particle;
    }
    
}
