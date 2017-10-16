#pragma once
#include "cocos2d.h"
USING_NS_CC;
#include "AppMacros.h"

class TouchTest :public Layer
{
public:
	enum MyEnum
	{
		BY474
	};
	static Scene *createScene();
	bool init();
	CREATE_FUNC(TouchTest);
	virtual bool onTouchBegan(Touch *touch, Event *unused_event)override;
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	virtual void onTouchCancelled(Touch *touch, Event *unused_event);
	void gameOver(EventCustom* event);
	SpriteBatchNode * batchNode;
	
};

class noTouch :public LayerColor
{
public:
	enum MyEnum
	{
		BY474
	};
	CREATE_FUNC(noTouch);
	bool init()
	{
		if (!LayerColor::init())
		{
			return false;
		}
		//EventListenerCustom *eventCustom = EventListenerCustom::create("GAMEOVER", CC_CALLBACK_1(TouchTest::gameOver, this));
		//_eventDispatcher->addEventListenerWithFixedPriority(eventCustom, -1);
		EventListenerTouchOneByOne *touchOne = EventListenerTouchOneByOne::create();
		touchOne->onTouchBegan = CC_CALLBACK_2(noTouch::onTouchBegan, this);
		touchOne->onTouchMoved = CC_CALLBACK_2(noTouch::onTouchMoved, this);
		touchOne->onTouchEnded = CC_CALLBACK_2(noTouch::onTouchEnded, this);
		touchOne->onTouchCancelled = CC_CALLBACK_2(noTouch::onTouchCancelled, this);
	/*	touchOne->setSwallowTouches(true);*/
		_eventDispatcher->addEventListenerWithFixedPriority(touchOne, 1);

		auto plane = Sprite::create("hero1.png");
		plane->setPosition(Vec2(CCRANDOM_0_1() * 480, CCRANDOM_0_1() * 320));
		addChild(plane);
		plane->setTag(BY474);

		return true;
	}
	virtual bool onTouchBegan(Touch *touch, Event *unused_event)override
	{
		auto plane = (Sprite*)getChildByTag(BY474);
		Vec2 pt = touch->getLocation();   //获取的是基于OpenGL的世界坐标
		log("touchX = %f,touchY  = %f", pt.x, pt.y);
		if (plane->boundingBox().containsPoint(pt))
		{
			log("notouchBegan");
			return true;
		}
		return false;
	}
	virtual void onTouchMoved(Touch *touch, Event *unused_event)
	{
		log("notouchMoved");
		Vec2 pt = touch->getDelta();
		Vec2 pt2 = touch->getLocation();
		auto spr = (Sprite*)getChildByTag(BY474);
		spr->setPosition(spr->getPosition() + pt);

	}
	virtual void onTouchEnded(Touch *touch, Event *unused_event)
	{
		log("notouchEnded");
	}
};
