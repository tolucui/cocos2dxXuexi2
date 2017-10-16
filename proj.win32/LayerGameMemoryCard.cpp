#include "LayerGameMemoryCard.h"

#include <stdlib.h>
#include <time.h>


LayerGameMemoryCard::~LayerGameMemoryCard()
{
	this->removeAllChildren();
	log("LayerGameMemoryCard all clean");
}

 Scene* LayerGameMemoryCard::createScene(int degree)
{
	 Scene* sc = Scene::create();
	 LayerGameMemoryCard* layer = LayerGameMemoryCard::create(degree);
	 sc->addChild(layer);
	 return sc;
}

 LayerGameMemoryCard* LayerGameMemoryCard::create(int degree)
 {
	 LayerGameMemoryCard * pRet = new LayerGameMemoryCard();
	 if (pRet&&pRet->init(degree))
	 {
		 pRet->autorelease();
	 }
	 else
	 {
		 CC_SAFE_DELETE(pRet);
	 }
	 return pRet;
 }

 bool LayerGameMemoryCard::init(int degree)
 {
	 if (!LayerColor::initWithColor(Color4B::WHITE))
	{
		return false;
	}
	//auto item = CardItem::create(2);
	//item->setPosition(Vec2(100, 100));
	//addChild(item);
	 setDegree(degree);
	 setGridding();
	 getAllPoint();
	 getAvailablePoint();
	 addCard();
	 EventListenerCustom * beginTouchListener = EventListenerCustom::create("BEGINTOUCH", CC_CALLBACK_0(LayerGameMemoryCard::ComeTouch, this));
	 _eventDispatcher->addEventListenerWithSceneGraphPriority(beginTouchListener, this);
	return true;

 }

 //添加所有的点的坐标;
void LayerGameMemoryCard::getAllPoint()
 {
	 //allPoints = PointArray::create(60);
	 //allPoints->retain();
	 for (int i = 0; i < 10; i++)
	 {
		 for (int j = 0; j < 6;j++)
		 {
			 allPoints2.push_back((Vec2(80 * i, 80 * j)));
			/* allPoints->addControlPoint(Vec2(80 * i, 80 * j));*/
	//		 log("x = %g , y = %g", allPoints2.at(i * 6 + j).x, allPoints2.at(i * 6 + j).y);
		 }
	 }
 }

//随机出5 + 2 * degree个有效的记忆卡片代号,存入
 void LayerGameMemoryCard::getAvailablePoint()
 {
	 srand(time(NULL));
	 while (1)
	 {
		 int index = rand() % 60;
		 int i = 0;
		 for (; i < vec.size();i++)
		 {
			 if (vec[i] == index)
			 {
				 break;
			 }
		 }
		 if (i==vec.size())
		 {
			 vec.push_back(index);
			 if (vec.size() == 5 + 2 * degree)
			 {
				 break;
			 }
		 }
	 }
 }

 //添加卡片
 void LayerGameMemoryCard::addCard()
 {
	 for (int i = 1; i <= 5+2*degree;i++)
	 {
		 CardItem * item = CardItem::create(i,getDegree());
		 item->setPosition(allPoints2.at(vec[i-1]));
		// log("x = %d , y = ", allPoints->getControlPointAtIndex(vec[i]).x, allPoints->getControlPointAtIndex(vec[i]).y);
		 addChild(item);
		 cardVector.pushBack(item);
	 }
 }

 //设置网格
 void LayerGameMemoryCard::setGridding()
 {
	 for (int i = 0; i <= 10; i++)
	 {
		 auto spr = Sprite::create();

		 spr->setTextureRect(Rect(0, 0, 1, winSize.height));
		 spr->setAnchorPoint(Vec2(0, 0));
		 spr->setPosition(Vec2(80 * i, 0));
		 spr->setColor(Color3B::BLACK);
		 spr->setZOrder(10);
		 addChild(spr);

	 }
	 for (int j = 0; j <= 6; j++)
	 {
		 auto spr = Sprite::create();
		
		 spr->setTextureRect(Rect(0, 0, winSize.width, 1));
		 spr->setAnchorPoint(Vec2(0, 0));
		 spr->setPosition(Vec2(0, 80 * j));
		 spr->setColor(Color3B::BLACK);
		 spr->setZOrder(10);
		 addChild(spr);
	 }
 }


//可以开始点击的启动函数;
 void LayerGameMemoryCard::ComeTouch()
 {
	 EventListenerTouchOneByOne* touch = EventListenerTouchOneByOne::create();
	 touch->onTouchBegan = CC_CALLBACK_2(LayerGameMemoryCard::onTouchBegan, this);
	 _eventDispatcher->addEventListenerWithSceneGraphPriority(touch,this);
	// log("comeTouch");
 }

 //触摸
 bool LayerGameMemoryCard::onTouchBegan(Touch *touch, Event *unused_event)
 {
	// log("touchbegin");
	 Vec2 pt = touch->getLocation();
	 CardItem* spr = *(cardVector.begin());
	 if (spr->getBoundingBox().containsPoint(pt))
	 {
		 spr->setScale(0, 1);
		 spr->showText();
		 //auto move1 = ScaleTo::create(1, 0, 1);
		 auto move2 = ScaleTo::create(0.2f, 1, 1);
		 spr->runAction(move2);
		 cardVector.eraseObject(spr);
	 }
	 else
	 {
		 log("game over");
		 auto sc = LayerStart::createScene();
		 Director::getInstance()->replaceScene(sc);
	 }
	 if (cardVector.empty())
	 {
		 log("game win");
		 auto sc = LayerStart::createScene();
		 Director::getInstance()->replaceScene(sc);
	 }
	 return false;
 }

 void LayerGameMemoryCard::onExit()
 {
	 log("onexit");
	 if (cardVector.empty()==false)
	 {
		 cardVector.clear();
	 }
	 CardItem::flagReset();
 }
