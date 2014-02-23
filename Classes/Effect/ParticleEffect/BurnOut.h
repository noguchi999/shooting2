#ifndef __shooting2__BurnOut__
#define __shooting2__BurnOut__

#include "cocos2d.h"
#include "Config.h"
#include "ParticleEffect.h"

USING_NS_CC;

class BurnOut : public ParticleEffect, public EffectCreator<BurnOut>
{
public:    
    BurnOut();
    virtual ~BurnOut();

    virtual void runAction() override;

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__shooting2__BurnOut__) */
