#pragma once
#include "cocos2d.h"
#include "Mirror_ModeLayer.h"
using namespace cocos2d;
class Mirror_ModeLayer :
	public cocos2d::CCLayer
{
public:
	Mirror_ModeLayer(void);
	~Mirror_ModeLayer(void);

	CREATE_FUNC(Mirror_ModeLayer);
	virtual bool init();
	CC_SYNTHESIZE(Mirror_ModeLayer*,_mirror_modelayer,Mirror_ModeLayer);


	/*
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchesMoved(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
	virtual void ccTouchesEnded(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
	*/

	//���㴥���¼�
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	//virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch,cocos2d::CCEvent *pEvent);
	void registerWithTouchDispatcher();
	virtual void onEnter();
	virtual void onExit();
	void Timeout(float dt);

	void enlarge(CCObject *pSender);
	void store(CCObject *pSender);

	void GamePause(CCObject *pSender);
	void GameResume(CCObject *pSender);
	void  display_score(float dt);
	void second(float dt);

public:
	CCSprite *m_pausebg;

	bool m_selected1;
	bool m_selected2;
	bool m_selected3;
	bool m_selected4;
	bool m_selected5;
	bool m_selected6;
	bool m_selected7;
	bool m_selected8;
	bool m_selected9;
    bool m_haswin;
    long m_timeleave;

	//��㴥���¼�
	/*
	virtual void ccTouchesBegan(CCSet *pTouches,CCEvent *pEvent);
	virtual void ccTouchesMoved(cocos2d::CCSet *pTouches,cocos2d::CCEvent *pEvent);
	virtual void  ccTouchesEnded(cocos2d::CCSet *pTouches,cocos2d::CCEvent *pEvent);
	void registerWithTouchDispatcher(void);
	//��������
	virtual void onEnter();
	virtual void onExit();
	*/

	//�����¼�
//	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	//virtual void ccTouchesMoved(cocos2d::CCSet *pTouches,cocos2d::CCEvent *pEvent);
	//virtual void  ccTouchesEnded(cocos2d::CCSet *pTouches,cocos2d::CCEvent *pEvent);





private:
	int count;


};

