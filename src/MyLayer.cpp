#include <Geode/Geode.hpp>
#include "MyLayer.hpp"

using namespace geode::prelude;

CCScene* MyLayer::scene() {
    auto layer = MyLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);

    return scene;
}

bool MyLayer::init() {
    if (!CCLayer::init()) return false;
    FMODAudioEngine::sharedEngine()->playMusic("Verity.mp3", true, 1.0f, 0);

    auto winSize = CCDirector::sharedDirector()->getWinSize();
       
    auto background = createLayerBG();
    background->setColor({ 0, 88, 219 });
    this->addChild(background);

    auto menu = CCMenu::create();
    menu->setPosition({ winSize.width * 0.5f, winSize.height * 0.5f });
    menu->setContentSize({ winSize.width, winSize.height });
    menu->setAnchorPoint({ 0.f, 0.f });
    this->addChild(menu);

    auto text = CCLabelBMFont::create("Hello, world!", "bigFont.fnt");
    text->setPosition({ winSize.width * 0.5f, winSize.height * 0.5f });
    this->addChild(text);

    auto backBtn = addBackButton(this);
    backBtn->setPosition({ (0 - (winSize.width / 2)) + 22.f, (winSize.height / 2) - 22.f });
    menu->addChild(backBtn);

    return true;
}

void MyLayer::keyBackClicked() {
    auto engine = FMODAudioEngine::sharedEngine();

    engine->stopMusic(true);

    CCDirector::sharedDirector()->popSceneWithTransition(
        0.5f,
        PopTransition::kPopTransitionFade
    );
}
