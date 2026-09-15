#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "MyLayer.hpp"

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
public:
    void onMoreGames(CCObject*) {
        FMODAudioEngine::sharedEngine()->playMusic("Verity.mp3", true, 1.0f, 0);

        CCDirector::sharedDirector()->pushScene(
            CCTransitionFade::create(0.5f, MyLayer::scene())
        );
    }
};
