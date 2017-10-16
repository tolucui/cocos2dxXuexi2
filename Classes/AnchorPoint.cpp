#include "AnchorPoint.h"

Scene* AnchorPoint::createScene()
{
	Scene* sc = Scene::create();
	Layer* anchorPoint = AnchorPoint::create();
	CCLOG("ignore");  //ignore锚点, 其实锚点的位置还是在Vec2(0.5f,0.5f);
	CCLOG("anchor.x=%f,anchor.y=%f", anchorPoint->getAnchorPoint().x, anchorPoint->getAnchorPoint().y);
	CCLOG("position.x=%f,position.y=%f", anchorPoint->getPosition().x, anchorPoint->getPosition().y);

	//CCLOG("not ignore");
	//anchorPoint->ignoreAnchorPointForPosition(false);  //不忽略锚点
	//CCLOG("anchor.x=%f,anchor.y=%f", anchorPoint->getAnchorPoint().x, anchorPoint->getAnchorPoint().y);
	//CCLOG("position.x=%f,position.y=%f", anchorPoint->getPosition().x, anchorPoint->getPosition().y);

	sc->addChild(anchorPoint);
	return sc;
}
AnchorPoint* AnchorPoint::create()
{
	auto anch = new AnchorPoint();
	if (anch&&anch->init())
	{
		anch->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(anch);
	}
	return anch;
}
bool AnchorPoint::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size winsize = Director::getInstance()->getWinSize();
	spr = Sprite::create("anchor3.png");

	spr->setColor(Color3B(255,255,0));
	spr->setAnchorPoint(Vec2(0.5f, 0.5f));
	spr->setPosition(winsize.width/3, winsize.height/3);
	this->addChild(spr); 

	//spr->ignoreAnchorPointForPosition(true); //设置精灵1忽略锚点
	CCLOG("spr.anchor.x = %f, spr1.anchor.y = %f", spr->getAnchorPoint().x, spr->getAnchorPoint().y);
	CCLOG("spr.position.x = %f, spr1.position.y = %f", spr->getPosition().x, spr->getPosition().y);//ignore, x= 480,y=320; noignore,x=480,y=320;结论:setposition是以左下角坐标为原点?
	
	Sprite * spr2 = Sprite::create("anchor1.png");

	spr2->setPosition(0, 0);
	spr->addChild(spr2);
	CCLOG("spr2.position.x = %f, spr2.position.y = %f", spr->getPosition().x, spr->getPosition().y);


	return true;
}

 
void AnchorPoint::mySchedule(float dt)
{
	static float ro = 0;
	ro += 30;
	spr->setRotation(ro);
}