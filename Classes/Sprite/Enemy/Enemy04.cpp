#include "Enemy04.h"

USING_NS_CC;

Enemy04::Enemy04()
{
    max_life = 3;
    setLife(max_life);
}

Enemy04::~Enemy04()
{
}

const char* Enemy04::getImageFileName()
{
    return "enemy04.png";
}

void Enemy04::update(float delta)
{
    Enemy::update(delta);
    
    if (getStatus() == Status::Normal && getDuration() <= 0)
    {
        if (rand()%300 == 1)
        {
            attack();
        }
    }
}

void Enemy04::move()
{
    auto winSize = Director::getInstance()->getWinSize();
    float x = getPositionX();
    float y = getPositionY();

    ccBezierConfig bezier;
    bezier.controlPoint_1 = Point(winSize.width, winSize.height);
    bezier.controlPoint_2 = Point(0, winSize.height * 0.8);
    bezier.endPosition    = Point(x, y);
    ActionInterval* bezierMove = BezierTo::create(10.0f, bezier);
    FiniteTimeAction* actionCompleted = CallFuncN::create(CC_CALLBACK_1(Enemy04::onActionCompletedThenRemove, this));
                    
    runAction(Sequence::create(bezierMove, actionCompleted, nullptr));
}

void Enemy04::attack()
{
    auto parent = getParent();
    if (parent)
    {
        auto bullet = EnemyNormalBullet::createEnemy(getTarget());
        bullet->setColor(Color3B::RED);
        bullet->setPosition(getPositionX(), getPositionY());
        parent->addChild(bullet);

        bullet->move();
    }
}

void Enemy04::attack(Point from, Point to)
{
}

void Enemy04::specialAttack()
{
}

void Enemy04::specialAttack(Point from, Point to)
{
}
