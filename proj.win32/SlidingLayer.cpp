#include "SlidingLayer.h"
#include "cocos2d.h"

using namespace cocos2d;

const int NEXT_SPRITE_SHOW = 50; // �������뻬��ֹͣʱ����룬����������ֵ��������Ϊ�ǻ�����û�г�������Ϊ�������������������
//////////////////////////////////////////////////////////////////////////
CSlidingLayer::CSlidingLayer()
{
	m_ptTouchDown.setPoint(-1, -1);
	m_nCurSprite = 0;
	m_bMoveLayer = false;
}

//////////////////////////////////////////////////////////////////////////
CSlidingLayer::~CSlidingLayer()
{

}

//////////////////////////////////////////////////////////////////////////
bool CSlidingLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	m_ptTouchDown = pTouch->getLocation(); // ��ȡ������
	m_bMoveLayer = false;
	return true;
}

//////////////////////////////////////////////////////////////////////////
void CSlidingLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	m_bMoveLayer = true;
	if (m_vecSprite.size() <= 0)
	{
		return ;
	}

	int nCurSpriteTemp = m_nCurSprite;
	int nWillShowSpriteIndex = m_nCurSprite; // ��Ҫ��ʾ�ľ�������������������һ���ʱ��Ҫ��ʾ�ľ���
	CCPoint ptTouch = pTouch->getLocation();
	if (ptTouch.x > m_ptTouchDown.x) // ���һ���
	{
		nWillShowSpriteIndex--;
	}
	else if (ptTouch.x < m_ptTouchDown.x) // ���󻬶�
	{
		nWillShowSpriteIndex++;
	}
	nWillShowSpriteIndex = __max(0, nWillShowSpriteIndex);
	nWillShowSpriteIndex = __min(nWillShowSpriteIndex, (int)m_vecSprite.size() - 1);
	nCurSpriteTemp = __max(0, nCurSpriteTemp);
	nCurSpriteTemp = __min(nCurSpriteTemp, (int)m_vecSprite.size() - 1);

	// ��ǰҳ�ƶ���ʾ
	int nDalta = ptTouch.x - m_ptTouchDown.x; // ��ָ��ǰ�������Ĵ�������տ�ʼ�����ĵ��X��ֵ
	CCSprite* pSprite = m_vecSprite[nCurSpriteTemp];
	CCAssert(pSprite != NULL, "");
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	pSprite->setPosition(ccp(size.width / 2 + nDalta, size.height / 2)); // �ƶ���ǰҳ
	if (nWillShowSpriteIndex != nCurSpriteTemp) // �ƶ���Ҫ��ʾ��ҳ
	{
		CCSprite* pSpriteWillShow = m_vecSprite[nWillShowSpriteIndex];
		
	//	MUSTEK(pSpriteWillShow);
		if (nWillShowSpriteIndex < nCurSpriteTemp)
		{
			pSpriteWillShow->setPosition(ccp(-size.width / 2 + nDalta, size.height / 2)); // �����ƶ�ʱ����Ҫ��ʾ��ҳ����Ļ��ߣ�ê���ڰ���֮��
		}
		else
		{
			pSpriteWillShow->setPosition(ccp(size.width * 3 / 2 + nDalta, size.height / 2)); // �����ƶ�ʱ����Ҫ��ʾ��ҳ����Ļ�ұߣ�ê����3/2��֮��
		}
	}
}

//////////////////////////////////////////////////////////////////////////
void CSlidingLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	if (m_vecSprite.size() == 0)
	{
		return ;
	}

	CCPoint ptEnd = pTouch->getLocation();
	if (ptEnd.x > m_ptTouchDown.x) // ���һ�
	{
		if (ptEnd.x - m_ptTouchDown.x >= NEXT_SPRITE_SHOW)
		{
			m_nCurSprite--; // ��ǰҳ��Ϊǰһҳ
		}
	}
	else if (ptEnd.x < m_ptTouchDown.x) // ����
	{
		if (m_ptTouchDown.x - ptEnd.x >= NEXT_SPRITE_SHOW)
		{
			m_nCurSprite++; // ��ǰҳ��Ϊ��һҳ
		}
	}
	m_nCurSprite = __min(m_nCurSprite, (int)m_vecSprite.size() - 1);
	m_nCurSprite = __max(0, m_nCurSprite);

	if (m_vecSprite.size() != 0)
	{
		CCSprite* pSprite = m_vecSprite[m_nCurSprite];
		CCAssert(pSprite != NULL, "");
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		pSprite->setPosition(ccp(size.width / 2, size.height / 2)); // ����ǰҳ��ʾ����Ļ�м�

		// Ϊ��ʹ�����������鲻�Ե�ǰҳ������ʾӰ�죬�����Ҿ��鶼�ƶ�����Զ��Զ�ĵط�ȥ
		if (m_nCurSprite >= 1)
		{
			pSprite = m_vecSprite[m_nCurSprite - 1];
			pSprite->setPosition(ccp(-10000, 0));
		}
		if (m_nCurSprite + 1 <= (int)m_vecSprite.size() - 1)
		{
			pSprite = m_vecSprite[m_nCurSprite + 1];
			pSprite->setPosition(ccp(-10000, 0));
		}
	}
}

//////////////////////////////////////////////////////////////////////////
void CSlidingLayer::AddSprite(CCSprite* pSprite)
{
	CCAssert(pSprite != NULL, "");
	m_vecSprite.push_back(pSprite);
}