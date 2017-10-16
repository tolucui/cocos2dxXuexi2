#include "TouchTest.h"

Scene *TouchTest::createScene()
{
	Scene *sc = Scene::create();
	Layer *ly = TouchTest::create();
	ly->setZOrder(100);
	noTouch * notouch = noTouch::create();
	notouch->setZOrder(20);
	sc->addChild(ly);
	sc->addChild(notouch);
	return sc;
}

bool TouchTest::init()
{
	if (!Layer::init())
	{
		return false;
	}
	/*setTouchEnabled(true);
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);*/
	EventListenerCustom *eventCustom = EventListenerCustom::create("GAMEOVER",CC_CALLBACK_1(TouchTest::gameOver,this));
	_eventDispatcher->addEventListenerWithFixedPriority(eventCustom,10);
	EventListenerTouchOneByOne *touchOne = EventListenerTouchOneByOne::create();
	touchOne->onTouchBegan = CC_CALLBACK_2(TouchTest::onTouchBegan, this);
	touchOne->onTouchMoved = CC_CALLBACK_2(TouchTest::onTouchMoved, this);
	touchOne->onTouchEnded = CC_CALLBACK_2(TouchTest::onTouchEnded, this);
	touchOne->onTouchCancelled = CC_CALLBACK_2(TouchTest::onTouchCancelled, this);
	touchOne->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithFixedPriority(touchOne, -5);

	auto plane = Sprite::create("hero1.png");
	plane->setPosition(Vec2(100, 100));
	addChild(plane);
	plane->setTag(BY474);

	return true;
}

bool TouchTest::onTouchBegan(Touch *touch, Event *unused_event)  //�����Event����ֻ��ƻ��ƽ̨����
{
	auto plane = (Sprite*)getChildByTag(BY474);
	Vec2 pt = touch->getLocation();   //��ȡ���ǻ���OpenGL����������
	//log("touchX = %f,touchY  = %f", pt.x, pt.y);
	if (plane->boundingBox().containsPoint(pt))
	{
		log("touched");
		return true;
	}
	return false;
}

void TouchTest::onTouchMoved(Touch *touch, Event *unused_event)
{
	log("touchMoved");
	Vec2 pt = touch->getDelta();
	Vec2 pt2 = touch->getLocation();
	auto spr = (Sprite*)getChildByTag(BY474);
	spr->setPosition(spr->getPosition() + pt);
	//log("MoveX =%f,MoveY = %f,touchX = %f,touchY  = %f", pt.x, pt.y, pt2.x, pt2.y);
}
void TouchTest::onTouchEnded(Touch *touch, Event *unused_event)
 {
	log("touchEnded");
	//EventCustom  event("GAMEOVER");
	
	//_eventDispatcher->dispatchEvent(&event);
 }
void TouchTest::onTouchCancelled(Touch *touch, Event *unused_event)
 {
	log("touchCancelled");
 }

void TouchTest::gameOver(EventCustom* event)
{
	log("gameOver");
}
