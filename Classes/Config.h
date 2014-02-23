#ifndef __shooting2__Config_h
#define __shooting2__Config_h

enum kTag
{
	kTagUnDefine   = -1,
    kTagBackground = 1,
    kTagLabel,
    kTagPlayer,
    kTagOperationPanel,
    kTagEnemy,
	kTagAlly,
    kTagEffect,
    kTagScore
};

enum kZOrder
{
    kZOrderBackground,
    kZOrderLabel,
    kZOrderGameOver,
    kZOrderMovableSprite,
    kZOrderOperationPanel,
    kZOrderEffect
};

#endif /* defined(__shooting2__Config_h) */