#include "LabelTest.h"

Scene *LabelTest::createScene()
{
	Scene *sc = Scene::create();
	Layer *ly = LabelTest::create();
	ly->setZOrder(100);
	sc->addChild(ly);
	return sc;
}

bool LabelTest::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto ttf = Label::createWithTTF("Score", "fonts/Marker Felt.ttf", 20);
	ttf->setPosition(Vec2(100, 100));
	addChild(ttf); 
	return true;
}
