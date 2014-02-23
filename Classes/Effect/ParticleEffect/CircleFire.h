#ifndef __shooting2__CircleFire__
#define __shooting2__CircleFire__

#include "cocos2d.h"
#include "Config.h"
#include "ParticleEffect.h"

USING_NS_CC;

class CircleFire : public ParticleEffect, public EffectCreator<CircleFire>
{
public:    
    CircleFire();
    virtual ~CircleFire();

    virtual void runAction() override;

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__shooting2__CircleFire__) */
