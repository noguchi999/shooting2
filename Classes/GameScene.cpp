#include "GameScene.h"

USING_NS_CC;
using namespace CocosDenshion;
using namespace std;

GameScene::GameScene()
:winSize(Director::getInstance()->getWinSize())
{
    srand((unsigned)time(nullptr));
}

GameScene::~GameScene()
{
    CC_SAFE_RELEASE(background);
    CC_SAFE_RELEASE(warShip);
}

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    scene->addChild(GameScene::create());
    
    return scene;
}

bool GameScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    RewardManager::getInstance()->setScore(0);

    preLoad();
    initialPlacement();
    
    //SimpleAudioEngine::sharedEngine()->playBackgroundMusic(kBGMMain, true);

    scheduleUpdate();
    
    return true;
}

void GameScene::update(float delta)
{   
	createEnemy();
    collisionDetection();
    updateInfomationPanel();
}

void GameScene::preLoad()
{
    //SimpleAudioEngine::sharedEngine()->preloadEffect(kSEMoveBlock);
    //SimpleAudioEngine::sharedEngine()->preloadEffect(kSERemoveBlock);
    //SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(kBGMMain);

    // ƒ{ƒX‚È‚Ç‚Ì‘åŒ^‰æ‘œ‚ÅƒQ[ƒ€ŽÀs’†‚É“Ç‚Ýž‚Þ‚Æˆ—‚ª’x‚­‚È‚é‚æ‚¤‚È‚à‚Ì‚¾‚¯‚â‚ê‚Î[•ª
    ResourceManager::getInstance()->preLoadBatchNode("enemy04.png");
}

void GameScene::initialPlacement()
{
    auto bg1 = Sprite::create("bg1.png");
    auto bg2 = Sprite::create("bg2.png");
    auto bg3 = Sprite::create("bg3.png");
    auto paraNode = ParallaxNode::create();
    paraNode->addChild(bg1, 1, Point(0.5f, 0), Point(0, winSize.height));
    paraNode->addChild(bg2, 2, Point(1.5f, 0), Point(0, winSize.height / 10));
    paraNode->addChild(bg3, 3, Point(2.0f, 0), Point(0, winSize.height / 3));
    paraNode->setPosition(Point(winSize.width, winSize.height / 5));
    addChild(paraNode, kZOrderBackground);
    
    auto move1  = MoveBy::create(10.0f, Point(-winSize.width, 0));
    auto move2  = MoveBy::create(0.0f, Point(winSize.width, 0));
    auto repeat = RepeatForever::create(Sequence::create(move1, move2, nullptr));
    paraNode->runAction(repeat);


    const char* initCountStr = String::createWithFormat("%05d", RewardManager::getInstance()->getScore())->getCString();
    auto score_label         = LabelBMFont::create(initCountStr, "whiteFont.fnt");
    score_label->setPosition(Point(winSize.width * 0.8, winSize.height * 0.1));
    addChild(score_label, kZOrderLabel, kTagScore);


    createPlayer();


    auto left = ArrowLeft::createOperationPanel(warShip);
    left->setPosition(Point(left->getContentSize().width * 1.0f, left->getContentSize().height * 2));
    addChild(left, left->getZOrder(), left->getTag());

    auto right = ArrowRight::createOperationPanel(warShip);
    right->setPosition(Point(right->getContentSize().width * 3.0f, right->getContentSize().height * 2));
    addChild(right, right->getZOrder(), right->getTag());

    auto top = ArrowTop::createOperationPanel(warShip);
    top->setPosition(Point(top->getContentSize().width * 2.0f, top->getContentSize().height * 2));
    addChild(top, top->getZOrder(), top->getTag());
    
    auto under = ArrowUnder::createOperationPanel(warShip);
    under->setPosition(Point(under->getContentSize().width * 2.0f, under->getContentSize().height));
    addChild(under, under->getZOrder(), under->getTag());

    auto attack = NormalAttack::createOperationPanel(warShip);
    attack->setPosition(Point(winSize.width * 0.8f, attack->getContentSize().height * 2));
    addChild(attack, attack->getZOrder(), attack->getTag());

    auto special = SpecialAttack::createOperationPanel(warShip);
    special->setPosition(Point(winSize.width*0.8f + special->getContentSize().width, special->getContentSize().height * 2));
    addChild(special, special->getZOrder(), special->getTag());
}

void GameScene::createPlayer()
{
    if (!getChildByTag(kTagPlayer))
    {
        warShip = WarShip::createPlayer();
        warShip->setPosition(Point(warShip->getContentSize().width * 1.5f, winSize.height/1.7));
        addChild(warShip, warShip->getZOrder(), warShip->getTag());
    }
}

void GameScene::createEnemy()
{
    if (rand()%150 == 1)
	{
        float enemy_height = winSize.height*(rand()%100+1)/100;
        if (enemy_height < winSize.height * 0.4) {
            enemy_height = winSize.height * 0.4;
        } else if (enemy_height > winSize.height * 0.8) {
            enemy_height = winSize.height * 0.8;
        }
        
        auto enemy = Enemy01::createEnemy(warShip);
        enemy->setPosition(winSize.width, enemy_height);
        addChild(enemy, enemy->getZOrder(), enemy->getTag());
        enemy->move();
	}
    else if (rand()%150 == 3)
    {
        float enemy_height = winSize.height*(rand()%100+1)/100;
        if (enemy_height > winSize.height * 0.8)
        {
            enemy_height = winSize.height * 0.8;
        }

        auto enemy = Enemy03::createEnemy(warShip);
        enemy->setPosition(winSize.width, enemy_height);
        addChild(enemy, enemy->getZOrder(), enemy->getTag());
        enemy->move();
    }
    else if (rand()%150 == 4)
    {
        for (int i = 0; i < 4; ++i)
        {
            auto enemy = Enemy04::createEnemy(warShip);
            enemy->setPosition(winSize.width + enemy->getContentSize().width*i, 0);
            addChild(enemy, enemy->getZOrder(), enemy->getTag());
            enemy->move();
        }
    }
}

void GameScene::collisionDetection()
{
    auto children = getChildren();
    for (auto currentNode : children)
    {
        if (currentNode && currentNode->getTag() == kTagEnemy)
        {
            auto enemy = dynamic_cast<Enemy*>(currentNode);
            for (auto targetNode : children)
            {
                if (targetNode && targetNode->getTag() == kTagAlly)
                {
                    auto ally = dynamic_cast<Ally*>(targetNode);
                    if (currentNode->boundingBox().intersectsRect(targetNode->boundingBox()))
                    {
                        ally->hurt(enemy->getPower(), enemy->getSpecialEffect());
                        enemy->hurt(ally->getPower(), ally->getSpecialEffect());
                    }
                }

                if (targetNode && targetNode->getTag() == kTagPlayer)
                {
                    auto player = dynamic_cast<Player*>(targetNode);
                    if (currentNode->boundingBox().intersectsRect(targetNode->boundingBox()))
                    {
                        player->hurt(enemy->getPower(), enemy->getSpecialEffect());
                    }
                }
            }
        }
    }
}

void GameScene::updateInfomationPanel()
{
    auto score = static_cast<LabelBMFont*>(getChildByTag(kTagScore));
    score->setString(String::createWithFormat("%05d", RewardManager::getInstance()->getScore())->getCString());
}