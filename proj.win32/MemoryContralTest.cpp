#include "MemoryContralTest.h"

Scene *MemoryContralTest::createScene()
{
	Scene *sc = Scene::create();
	Layer *ly = MemoryContralTest::create();
	sc->addChild(ly);
	return sc;
}

bool MemoryContralTest::init()
{
	if (!Layer::init())
	{
		return false;
	}
	spr = new Sprite();
	spr->retain();
	spr->autorelease();
	scheduleUpdate();
	log("retaint count  = %d", spr->getReferenceCount());
	//spr->retain();
	log("retaint count  = %d", spr->getReferenceCount());
	return true;
}

void MemoryContralTest::update(float delta)
{
	log("spr reference = %d", spr->getReferenceCount());
}

