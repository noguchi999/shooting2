#ifndef __shooting2__BattleManager__
#define __shooting2__BattleManager__

#include "cocos2d.h"
#include "Config.h"

USING_NS_CC;

class BattleManager
{
public:
    enum SpecialEffect
    {
        Nothing,
        Capture
    };

    static BattleManager* getInstance();

    CC_SYNTHESIZE(int, score, Score);

    void reset();

private:
    BattleManager(){};
    bool init();
};

#endif /* defined(__shooting2__BattleManager__) */
