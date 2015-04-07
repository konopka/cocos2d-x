#include "CCBFileLoader.h"
#include <string.h>                     // for strcmp
#include "cocosbuilder/CCNodeLoader.h"  // for NodeLoader

using namespace cocos2d;


namespace cocosbuilder {

#define PROPERTY_CCBFILE "ccbFile"

void CCBFileLoader::onHandlePropTypeCCBFile(Node * pNode, Node * pParent, const char * pPropertyName, Node * pCCBFileNode, CCBReader * ccbReader) {
    if(strcmp(pPropertyName, PROPERTY_CCBFILE) == 0) {
        ((CCBFile*)pNode)->setCCBFileNode(pCCBFileNode);
    } else {
        NodeLoader::onHandlePropTypeCCBFile(pNode, pParent, pPropertyName, pCCBFileNode, ccbReader);
    }
}

}
