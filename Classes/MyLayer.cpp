#include "MyLayer.h"

Scene * MyLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = MyLayer::create();
	scene->addChild(layer);
	return scene;

}

//MyLayer* MyLayer::create()
//{
//	auto pRet = new MyLayer();
//	if (pRet&& pRet->init())
//	{
//		pRet->autorelease();
//	}
//	else
//	{
//		CC_SAFE_DELETE(pRet);
//	}
//	return pRet;
//}

bool  MyLayer::init()
{ 
	if (!Layer::init())
	{
		return false;
	}
	Size winsize = Director::getInstance()->getWinSize();

	Sprite * spr = Sprite::create("HelloWorld.png");
	spr->setPosition(Vec2(winsize.width / 2, winsize.height / 2));
	addChild(spr);
	return true;

}