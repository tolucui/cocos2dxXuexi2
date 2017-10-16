#pragma once
#include "cocos2d.h"
USING_NS_CC;


class LayerStart :public Layer
{
public:
	bool init();
	static Scene* createScene();
	CREATE_FUNC(LayerStart);

	void easy(Ref* ref);
	void hard(Ref* ref);
	void veryHard(Ref* ref);
	void quit(Ref* ref);

	enum ENUM_DEGREE
	{
		EASY,
		HARD,
		VERYHARD
	};
};

