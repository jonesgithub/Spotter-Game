#ifndef _SLIDING_LAYER_H_
#define _SLIDING_LAYER_H_
#include "cocos2d.h"
#include <vector>
#include <iostream>
using namespace std;
using namespace  cocos2d;

//////////////////////////////////////////////////////////////////////////
class CSlidingLayer : public cocos2d::CCLayer
{
public:
	CSlidingLayer();
	~CSlidingLayer();

public:
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent); // ��ָ����ʱ
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouches, cocos2d::CCEvent *pEvent); // ��ָ�ƶ�ʱ
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent); // ��ָ�ſ�ʱ

public:
	void AddSprite(CCSprite* pSprite); // ������ڻ�����ʾ�ľ���
	bool IsMoveLayer() { return m_bMoveLayer; } // �����ж��Ƿ���ָ������

private:
	CCPoint m_ptTouchDown; // �״ΰ��µĴ�����

	typedef vector<CCSprite*> VEC_SPRITE;
	VEC_SPRITE m_vecSprite; // ���鼯��
	int m_nCurSprite; // ��ǰ��ʾ�ľ���

	bool m_bMoveLayer; // �ƶ���
};
#endif