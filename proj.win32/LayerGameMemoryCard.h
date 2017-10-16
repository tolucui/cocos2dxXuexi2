#pragma once
#include "cocos2d.h"
USING_NS_CC;
#include <vector>
using namespace std;
#include "LayerStart.h"
#include "CardItem.h"

#define  winSize  (Director::getInstance()->getWinSize())

class CardItem;

class LayerGameMemoryCard :public LayerColor
{
public:
	~LayerGameMemoryCard();
	static Scene* createScene(int degree);
	static LayerGameMemoryCard* create(int degree);
	bool init(int degree);
	
	void getAllPoint();
	void getAvailablePoint();
	CC_SYNTHESIZE(int, degree, Degree);
	void addCard();
	void setGridding();
	void ComeTouch();
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onExit();
	vector<Vec2> allPoints2;
	vector<int> vec;
	Vector<CardItem*> cardVector;
};

