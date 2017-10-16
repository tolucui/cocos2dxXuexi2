#include "FrameCacheTest.h"


Scene *FrameCacheTest::createScene()
{
	Scene *sc = Scene::create();
	Layer *ly = FrameCacheTest::create();
	sc->addChild(ly);
	return sc;
}
bool FrameCacheTest::init()
{
	if (!Layer::init())
	{
		return false;
	}
	setTouchEnabled(true);
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	SpriteFrameCache::getInstance()->removeSpriteFrames();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("plant.plist");
	//batchNode = SpriteBatchNode::create("plant2.png");
	//addChild(batchNode);

	return true;
}


bool FrameCacheTest::onTouchBegan(Touch *touch, Event *unused_event)
{
	Sprite *spr;
	bool flag = true;
	for (int i = 0; i < 1000;i++)
	{
		if (flag)
		{
			spr = Sprite::createWithSpriteFrameName("p_3_01.png");
			spr->setZOrder(0);
		}
		else
		{
			spr = Sprite::createWithSpriteFrameName("p_2_01.png");
			spr->setZOrder(0);
		}
		addChild(spr);
		spr->setPosition(Vec2(CCRANDOM_0_1() * 480, CCRANDOM_0_1() * 320));	
		flag = !flag;
	}
	return false;
}

