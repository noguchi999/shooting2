#include "Enemy01.h"

USING_NS_CC;

Enemy01::Enemy01()
{
}

Enemy01::~Enemy01()
{
}

const char* Enemy01::getImageFileName()
{
    return "enemy01.png";
}

void Enemy01::move()
{
	auto action = MoveTo::create(3.0f, Point(0, getPositionY()));
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(Enemy01::onActionCompletedThenRemove, this));

	runAction(Sequence::create(action, actionCompleted, nullptr));
}

void Enemy01::attack()
{
}

void Enemy01::attack(Point from, Point to)
{
}

void Enemy01::specialAttack()
{
}

void Enemy01::specialAttack(Point from, Point to)
{
}

void Enemy01::destroy()
{
    auto cuptured_enemy = Enemy02::createEnemy(getTarget());
    cuptured_enemy->setPosition(getPositionX(), getPositionY());
    getParent()->addChild(cuptured_enemy);

    Enemy::destroy();
}
