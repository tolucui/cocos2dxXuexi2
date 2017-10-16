#include "LayerSprite.h"


Scene *LayerSprite::createScene()
{
	Scene *sc = Scene::create();
	Layer *ly = LayerSprite::create();
	sc->addChild(ly);
	return sc;
}
bool LayerSprite::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto bg = Sprite::create("sprite/background.jpg",Rect(0,0,480,320));
	bg->setPosition(winSize.width / 2, winSize.height / 2);
	addChild(bg);
	Texture2D *texture = Director::getInstance()->getTextureCache()->addImage("sprite/plant.png");
	auto plant = Sprite::createWithTexture(texture);
	plant->setPosition(Vec2(30, winSize.height / 2));
	addChild(plant);

	Texture2D *texture2 = Director::getInstance()->getTextureCache()->addImage("sprite/bullet.png");
	auto bullet = Sprite::createWithTexture(texture2);
	bullet->setPosition(Vec2(30+100, winSize.height / 2));
	addChild(bullet);

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprite/zombie.plist");
	Sprite *zembie1 = Sprite::createWithSpriteFrameName(("z_1_attack_01.png"));
	zembie1->setPosition(Vec2(winSize.width-30, winSize.height / 2));
	addChild(zembie1);

	SpriteFrame * frame = SpriteFrame::create("sprite/p_1_01.png", Rect(0, 0, 80, 80));

	Sprite *sun = Sprite::createWithSpriteFrame(frame);

	sun->setPosition(Vec2(30, winSize.height *2/ 3));
	addChild(sun);

	auto layercolor = LayerColor::create(Color4B(0, 255, 0,255));
	addChild(layercolor);
	layercolor->setZOrder(-1);
	CCLOG("LayerColorZorder = %d", layercolor->getZOrder());
	return true;
}
