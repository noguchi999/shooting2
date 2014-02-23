#include "Enemy03.h"

USING_NS_CC;

Enemy03::Enemy03()
{
}

Enemy03::~Enemy03()
{
}

const char* Enemy03::getImageFileName()
{
    return "enemy03.png";
}

void Enemy03::move()
{
	auto action = MoveTo::create(1.5f, Point(0, getPositionY()));
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(Enemy03::onActionCompletedThenRemove, this));

	runAction(Sequence::create(action, actionCompleted, nullptr));
}

void Enemy03::attack()
{
}

void Enemy03::attack(Point from, Point to)
{
}

void Enemy03::specialAttack()
{
}

void Enemy03::specialAttack(Point from, Point to)
{
}