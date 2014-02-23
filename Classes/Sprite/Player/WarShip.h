#ifndef __shooting2__WarShip__
#define __shooting2__WarShip__

#include "cocos2d.h"
#include "Config.h"
#include "Player.h"

USING_NS_CC;

class WarShip : public Player, public PlayerCreator<WarShip>
{
public:    
    WarShip();
    virtual ~WarShip();
    
	virtual void attack() override;
	virtual void attack( Point from, Point to) override;
	virtual void specialAttack() override;
	virtual void specialAttack(Point from, Point to) override;

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__shooting2__WarShip__) */
