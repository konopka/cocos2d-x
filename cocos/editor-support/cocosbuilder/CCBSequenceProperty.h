#ifndef __CCB_SEQUENCE_PROPERTY_H__
#define __CCB_SEQUENCE_PROPERTY_H__

#include <string>                       // for string
#include "base/CCRef.h"                 // for Ref
#include "base/CCVector.h"              // for Vector
#include "platform/CCPlatformDefine.h"  // for CC_DLL
#include "CCBKeyframe.h"

namespace cocosbuilder {

class CC_DLL CCBSequenceProperty : public cocos2d::Ref
{
public:
    /**
     * @js ctor
     */
    CCBSequenceProperty();
    /**
     * @js NA
     * @lua NA
     */
    ~CCBSequenceProperty();
    
    virtual bool init();
    
    const char* getName();
    void setName(const char* pName);
    
    int getType();
    void setType(int type);
    
    cocos2d::Vector<CCBKeyframe*>& getKeyframes();

private:
    std::string _name;
    int _type;
    cocos2d::Vector<CCBKeyframe*> _keyframes;
};

}

#endif // __CCB_SEQUENCE_PROPERTY_H__
