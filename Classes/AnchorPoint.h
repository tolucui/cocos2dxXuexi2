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
	void mySchedule(float dt);   //float ����Ҫ������Ϊ�궨���schedule_selector ���Ա����ָ�룻
private:
	Sprite*spr;

};

