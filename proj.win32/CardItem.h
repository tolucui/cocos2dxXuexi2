#pragma once
#include "cocos2d.h"
USING_NS_CC;
#include "LayerGameMemoryCard.h"
class LayerGameMemoryCard;
class CardItem :public Sprite
{
public:
	//~CardItem();
	bool init(int index,int degree);
	static CardItem *create(int index,int degree);
	void showWhite(float delta);
	void showText();
	void flagPlus(){ flag++; };
	static void flagReset(){ flag = 0; };
private:
	Sprite * sprBg;
	Label * labelNum;
	CC_SYNTHESIZE(int, degree, Degree);
	static int flag;

};


