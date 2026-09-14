#include <Geode/Geode.hpp>

class MyLayer : public cocos2d::CCLayer {
public:
    CREATE_FUNC(MyLayer);

    static cocos2d::CCScene* scene();
    bool init();
    void keyBackClicked();
};
