#pragma once
#include "cocos2d.h"
USING_NS_CC;
#include "AppMacros.h"

class ScheduleTest :public Layer
{
public:

	static Scene *createScene();
	bool init();
	CREATE_FUNC(ScheduleTest);
	virtual bool onTouchBegan(Touch *touch, Event *unused_event)override;
	SpriteBatchNode * batchNode;
	void update(float delta)override;
	void mySchedule(float dt);
};


