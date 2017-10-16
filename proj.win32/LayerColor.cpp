#include "LayerColor.h"

Scene *LayerColor2::createScene()
{
	Scene *sc = Scene::create();
	Layer *ly = LayerColor2::create();
	sc->addChild(ly);
	return sc;
}

bool LayerColor2::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//this->setColor(Color3B(0, 255, 255));
	//auto layercolor = LayerColor::create(Color4B(255,255,255,255));
	//addChild(layercolor);

	Sprite* spr = Sprite::create();
	spr->setTextureRect(Rect(0, 0, 50, 50));
	spr->setColor(Color3B::YELLOW);
	spr->setAnchorPoint(Vec2(0, 0));
	addChild(spr);
	CCLOG("layerAnchorx = %f,layerAnchorY = %f", this->getAnchorPoint().x, this->getAnchorPoint().y);
	Vec2 toWorld = this->convertToWorldSpaceAR(spr->getPosition());
	CCLOG("x=%f,y = %f", toWorld.x, toWorld.y);

	/*auto layerGradient = LayerGradient::create(Color4B(0, 255, 0, 255), Color4B(0, 0, 255, 255));
	addChild(layerGradient);*/
	return true;
}
