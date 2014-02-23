#ifndef __shooting2__RewardManager__
#define __shooting2__RewardManager__

#include "cocos2d.h"
#include "Config.h"

USING_NS_CC;

class RewardManager
{
public:
    static RewardManager* getInstance();

    CC_SYNTHESIZE(int, score, Score);

    void reset();

private:
    RewardManager(){};
    bool init();
};

#endif /* defined(__shooting2__RewardManager__) */
