#pragma once
#include "cocos2d.h"
USING_NS_CC;
#include "AppMacros.h"


class MemoryContralTest :public Layer
{
public:
	Sprite * spr;
	static Scene *createScene();
	bool init();
	CREATE_FUNC(MemoryContralTest);
	void update(float delta);

};

