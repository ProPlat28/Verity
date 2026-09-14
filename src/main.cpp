#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "MyLayer.hpp"

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
public:
	void onMoreGames(CCObject*) {
		CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, MyLayer::scene()));
	}
};
