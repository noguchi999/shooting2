#ifndef __shooting2__ArrowUnder__
#define __shooting2__ArrowUnder__

#include "cocos2d.h"
#include "Config.h"
#include "OperationPanel.h"
#include "Sprite/Player/PlayerClassLoader.h"

USING_NS_CC;

class ArrowUnder : public OperationPanel, public OperationPanelCreator<ArrowUnder>
{
public:    
    ArrowUnder();
    virtual ~ArrowUnder();

    void update(float delta);

protected:
    virtual const char* getImageFileName();
    virtual void touchBegan(Touch *touch);
    virtual void touchMoved(Touch *touch);
    virtual void touchEnded(Touch *touch);
};

#endif /* defined(__shooting2__ArrowUnder__) */
