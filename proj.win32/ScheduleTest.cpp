#include "ScheduleTest.h"


Scene *ScheduleTest::createScene()
{
	Scene *sc = Scene::create();
	Layer *ly = ScheduleTest::create();
	sc->addChild(ly);
	return sc;
}

bool ScheduleTest::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Sprite* spr = Sprite::create("sprite/plant.png");
	spr->setPosition(Vec2(100, winSize.height / 2));
	addChild(spr);
	spr->setTag(100);
	schedule(schedule_selector(ScheduleTest::mySchedule));

	/*MoveBy *by = MoveBy::create(2, Vec2(300, 0));
	auto by2 = (MoveBy*)by->reverse();
	Sequence * sq = Sequence::create(by, by2, NULL);
	spr->runAction(RepeatForever::create(sq));*/
	//scheduleUpdate();  
	//scheduleOnce(schedule_selector(ScheduleTest::mySchedule), 2);
	
	//schedule(schedule_selector(ScheduleTest::mySchedule)); 
	//schedule(schedule_selector(ScheduleTest::mySchedule), 1,3,1);//1s�Ժ�ÿ��1sִ��һ�λص�,�ظ�3��(��ִ��4��);
	return true;
}


bool ScheduleTest::onTouchBegan(Touch *touch, Event *unused_event)
{
	Sprite *spr;
	bool flag = true;
	for (int i = 0; i < 1000; i++)
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


void ScheduleTest::update(float delta)  //����Ĳ�����:һ֡��ʱ��
{
	//CCLOG("dt = %g", delta);

}

#define V  (300 / 2)
#define VREVERSE (-(300/2))
static float v = V;

void ScheduleTest::mySchedule(float dt)
{
	if (dt > 0.2f)
		return;
	auto *spr = (Sprite*)getChildByTag(100);
	static bool flag = true;
	//ע��Ҫ���ǿ�֡,����ʹ��,
	//��Ϊ����ĳһ֡������λ�ÿ�����Χ��,�ٶȾͻ�һֱ��+150��-150��ѭ��
	//static float v = V;
	//if((unsigned)spr->getPosition().x-100<400) ;
	//else v = -v;
	//Ҫʹ��Ҳ����, �����ں�����ͷ�����ȶ�dt���ж�, ��΢���ȶ���dt���޳�,
	if ((unsigned)spr->getPosition().x - 100< 300);
	else v = -v;
	/*else if (spr->getPosition().x > 400)
		v = VREVERSE;*/
	CCLOG("X = %g,dt = %g,v = %g", spr->getPosition().x,dt, v);
	spr->setPositionX(spr->getPosition().x + v*dt);

}