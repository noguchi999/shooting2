#ifndef __shooting2__ResourceManager__
#define __shooting2__ResourceManager__

#include "cocos2d.h"
#include "Config.h"

USING_NS_CC;
using namespace std;

class ResourceManager
{
public:
    static ResourceManager* getInstance();
    virtual ~ResourceManager();

    void preLoadBatchNode(const string fileName);
    SpriteBatchNode* getBatchNode(const string fileName);
    
private:
    ResourceManager(){};

    bool init();
    void before();

    Dictionary* pool;
};

#endif /* defined(__shooting2__ResourceManager__) */
