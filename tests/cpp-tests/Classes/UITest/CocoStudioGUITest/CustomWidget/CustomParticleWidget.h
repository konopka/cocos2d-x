//
//  CustomParticleWidget.h
//  CustomUI
//
//  Created by cai wenzhi on 14-3-7.
//
//

#ifndef __CustomUI__CustomParticleWidget__
#define __CustomUI__CustomParticleWidget__

#include "math/Vec2.h"                  // for Vec2
#include "ui/UIWidget.h"                // for Widget
namespace cocos2d { class ParticleSystem; }
namespace cocos2d { class Ref; }

class CustomParticleWidget : public cocos2d::ui::Widget
{
public:
    
    CustomParticleWidget();
    ~CustomParticleWidget();
    
    static CustomParticleWidget* create();
    static cocos2d::Ref* createInstance();
    
    void setParticlePlist(const char* plist);
    const char* getParticlePlist() const;
    
    void setParticlePosition(const cocos2d::Vec2& pos);
    const cocos2d::Vec2& getParticlePosition() const;
    
    void playParticle();
    
    void stopParticle();
    
protected:
    virtual bool init() override;
    virtual void initRenderer();
    
    virtual void removeAllChildren();
    
protected:
    cocos2d::ParticleSystem* _emitter;
    const char* _emitterPlist;
    cocos2d::Vec2 _emitterPostion;
    
};

#endif /* defined(__CustomUI__CustomParticleWidget__) */
