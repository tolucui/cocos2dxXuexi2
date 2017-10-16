#pragma once
#include "cocos2d.h"
USING_NS_CC;
#include "AppMacros.h"

class BatchNodeTest :public Layer
{
public:
	static Scene *createScene();
	bool init();
	CREATE_FUNC(BatchNodeTest);
	virtual bool onTouchBegan(Touch *pTouch, Event* pEvent);
	SpriteBatchNode *batchNode;
	SpriteBatchNode *batchNode2;
};