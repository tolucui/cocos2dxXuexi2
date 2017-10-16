#pragma once
#include "cocos2d.h"
USING_NS_CC;
#include "AppMacros.h"

class FrameCacheTest :public Layer
{
public:
	static Scene *createScene();
	bool init();
	CREATE_FUNC(FrameCacheTest);

	virtual bool onTouchBegan(Touch *touch, Event *unused_event)override;
	SpriteBatchNode * batchNode;

};

