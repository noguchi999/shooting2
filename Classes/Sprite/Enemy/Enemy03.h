#ifndef __shooting2__Enemy03__
#define __shooting2__Enemy03__

#include "cocos2d.h"
#include "Config.h"
#include "Enemy.h"

USING_NS_CC;

class Enemy03 : public Enemy, public EnemyCreator<Enemy03>
{
public:    
    Enemy03();
    virtual ~Enemy03();

    virtual void move() override;
	virtual void attack() override;
	virtual void attack(Point from, Point to) override;
	virtual void specialAttack() override;
	virtual void specialAttack(Point from, Point to) override;

protected:
    virtual const char* getImageFileName() override;
};

#endif /* defined(__shooting2__Enemy03__) */
