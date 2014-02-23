#ifndef __shooting2__GameScene__
#define __shooting2__GameScene__

#include "cocos2d.h"
#include "Config.h"
#include "SimpleAudioEngine.h"
#include "Manager/ResourceManager.h"
#include "Manager/RewardManager.h"
#include "Sprite/OperationPanel/OperationPanelClassLoader.h"
#include "Sprite/Player/PlayerClassLoader.h"
#include "Sprite/Player/WarShip.h"
#include "Sprite/Enemy/EnemyClassLoader.h"
#include "Sprite/Ally/AllyClassLoader.h"

using namespace std;
USING_NS_CC;

class GameScene : public Layer
{
public:
    GameScene();
    virtual ~GameScene();
    
    virtual bool init();
    static Scene* createScene();
    CREATE_FUNC(GameScene);
    
private:
    Sprite*  background;
    WarShip* warShip;
    Size     winSize;
    
    void update(float delta);
    
    void preLoad();
    void initialPlacement();
    void createPlayer();
    void createEnemy();
    void collisionDetection();
    void updateInfomationPanel();
};
#endif /* defined(__shooting2__GameScene__) */
