#pragma once
#include "cocos2d.h"
 
class pick_pattern :
	public cocos2d::CCScene
{
public:
	pick_pattern(void);
	~pick_pattern(void);
     CREATE_FUNC(pick_pattern);
	 virtual bool init();
	 void normal_mode(CCObject *pSender); //����ģʽ
	 void mirror_mode(CCObject *pSender);  //����ģʽ
	 void sliding_mode(CCObject *pSender);  //����ģʽ
	 void clover_mode(CCObject *pSender);   //��Ҷ��ģʽ
	 void anti_tradition_mode(CCObject *pSender); //����ͳģʽ
	 void puzzle_mode(CCObject *pSender);    //ƴͼģʽ
	 void ReturnGame(CCObject *pSender);



};

