#pragma once
#include "cocos2d.h"
USING_NS_CC;

class AnchorPoint:public Layer
{
public:
	static	Scene* createScene();
	static AnchorPoint* create();
	bool init();
//	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags);
	void mySchedule(float dt);   //float 参数要带是因为宏定义的schedule_selector 类成员函数指针；
private:
	Sprite*spr;

};

