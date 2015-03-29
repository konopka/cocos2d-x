#include "CustomRootNodeReader.h"
#include "2d/CCNode.h"                  // for Node
#include "CCPlatformMacros.h"           // for CustomRootNode::create, etc
#include "CustomRootNode.h"             // for CustomRootNode
namespace flatbuffers { class Table; }

USING_NS_CC;

    

static CustomRootNodeReader* _instanceCustomRootNodeReader = nullptr;

CustomRootNodeReader* CustomRootNodeReader::getInstance()
{
    if (!_instanceCustomRootNodeReader)
    {
        _instanceCustomRootNodeReader = new CustomRootNodeReader();
    }

    return _instanceCustomRootNodeReader;
}

void CustomRootNodeReader::purge()
{
    CC_SAFE_DELETE(_instanceCustomRootNodeReader);
}

Node* CustomRootNodeReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
    CustomRootNode* node = CustomRootNode::create();

    setPropsWithFlatBuffers(node, nodeOptions);

    return node;
}