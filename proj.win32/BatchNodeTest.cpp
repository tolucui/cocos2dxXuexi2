#include "BatchNodeTest.h"


Scene*BatchNodeTest::createScene()
{
	Scene *sc = Scene::create();
	Layer *ly = BatchNodeTest::create();
	sc->addChild(ly);
	return sc;
}

bool BatchNodeTest::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//this->setColor(Color3B(0, 255, 255));
	//auto layercolor = LayerColor::create(Color4B(255,255,255,255));
	//addChild(layercolor);
	setTouchEnabled(true);
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	batchNode = SpriteBatchNode::create("CloseNormal.png");
	addChild(batchNode);

	batchNode2 = SpriteBatchNode::create("CloseNormal.png");
	addChild(batchNode2);
	return true;
}

bool BatchNodeTest::onTouchBegan(Touch *pTouch, Event* pEvent)
{
	for (int i = 0; i < 10000;i++)
	{
		Sprite* spr2 = Sprite::create("CloseNormal.png");
		spr2->setPosition(Vec2(CCRANDOM_0_1() * 480, CCRANDOM_0_1() * 320));
		spr2->setZOrder(0);
		batchNode->addChild(spr2);
	}	
	return false;
}