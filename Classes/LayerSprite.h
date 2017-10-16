#pragma once
#include "cocos2d.h"
USING_NS_CC;
#include "AppMacros.h"

class LayerSprite :public Layer
{
public:
	static Scene *createScene();
	bool init();
	CREATE_FUNC(LayerSprite);
};

