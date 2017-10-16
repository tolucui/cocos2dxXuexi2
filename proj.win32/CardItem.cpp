#include "CardItem.h"

int CardItem::flag = 0;
//CardItem::~CardItem()
//{
//	this->sprBg->removeFromParent();
//	this->labelNum->removeFromParent();
//}

CardItem *CardItem::create(int index,int degree)
{
	auto pRet = new CardItem();
	if (pRet&&pRet->init(index,degree))
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

bool CardItem::init(int index,int degree)
{
	if (!Sprite::init())
	{
		return false;
	}
	setDegree(degree);
	setContentSize(Size(80, 80));
	setAnchorPoint(Vec2(0, 0));

	/*添加文字*/
	String *str = String::createWithFormat("%d", index);
	labelNum = Label::createWithTTF(str->getCString(), "fonts/Marker Felt.ttf", 30);

	labelNum->setPosition(Vec2(40, 40));
	labelNum->setTextColor(Color4B::YELLOW);
	labelNum->setZOrder(1);
	addChild(labelNum);
	//添加颜色精灵;
	sprBg = Sprite::create();
	sprBg->setTextureRect(Rect(0, 0, 80, 80));
	sprBg->setAnchorPoint(Vec2(0, 0));
	sprBg->setColor(Color3B::BLACK);
	addChild(sprBg);
	this->scheduleOnce(schedule_selector(CardItem::showWhite), 3.0f-degree);
	return true;
}


void CardItem::showWhite(float delta)
{
	labelNum->setVisible(false);
	sprBg->setVisible(false);
	flag++;
	log("show White %d", flag);
	if (flag == 5 + degree)
	{
		EventCustom eventBeginTouch = EventCustom("BEGINTOUCH");
		_eventDispatcher->dispatchEvent(&eventBeginTouch);
		log("dispatchEvent beginTouch");
	}
}

void CardItem::showText()
{
	labelNum->setVisible(true);
	sprBg->setVisible(true);
}