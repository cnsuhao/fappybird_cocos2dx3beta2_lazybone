#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "GameScene.h"
#include "test\TestScene.h"
#include "demo\Demo.h"
#include "demo\bird\FlyBirdGame.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto eglView = EGLView::getInstance();

    director->setOpenGLView(eglView);
	
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(320, 480, kResolutionExactFit);


    // create a scene. it's an autorelease object
    //auto scene = HelloWorld::createScene();
	//auto scene = GameScene::createScene();
	//auto scene = Demo::createScene();
	//auto scene = TestScene::createScene();
	auto scene = FlyBirdGame::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
