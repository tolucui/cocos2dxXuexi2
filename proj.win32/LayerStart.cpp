#include "LayerStart.h"
#include "LayerGameMemoryCard.h"

Scene* LayerStart::createScene()
{
	Scene* sc = Scene::create();
	Layer * lyc = LayerStart::create();
	sc->addChild(lyc);
	return sc;
}



bool LayerStart::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto easyItem = MenuItemFont::create("Easy", this, 
		menu_selector(LayerStart::easy));
	auto hardItem = MenuItemFont::create("Hard", this,
		menu_selector(LayerStart::hard));
	auto veryHardItem = MenuItemFont::create("VeryHard", this, 
		menu_selector(LayerStart::veryHard));
	auto quitItem = MenuItemFont::create("Quit", this, 
		menu_selector(LayerStart::quit));

	auto menu = Menu::create(easyItem, hardItem, veryHardItem, quitItem, NULL);
	menu->alignItemsVertically();
	addChild(menu);
	return true;
}


void LayerStart::easy(Ref* ref)
{
	Scene * sc = LayerGameMemoryCard::createScene(ENUM_DEGREE::EASY);
	Director::getInstance()->replaceScene(sc);
}
void LayerStart::hard(Ref* ref)
{
	Scene * sc = LayerGameMemoryCard::createScene(ENUM_DEGREE::HARD);
	Director::getInstance()->replaceScene(sc);
}
void LayerStart::veryHard(Ref* ref)
{
	Scene * sc = LayerGameMemoryCard::createScene(ENUM_DEGREE::VERYHARD);
	Director::getInstance()->replaceScene(sc);
}
void LayerStart::quit(Ref* ref)
{
	exit(1);
}