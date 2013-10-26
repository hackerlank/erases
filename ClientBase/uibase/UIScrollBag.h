#pragma once
#include "cocos2d.h"
#include "UIItem.h"
#include <vector>
#include "UIUpBag.h"
#include "UIScrollView.h"
NS_CC_BEGIN
/**
 * ʵ������ ������Bag
 */

class UIScrollBag:public UIScrollView{
public:
	/**
	 * ��������
	 */
	static	UIScrollBag *create(int bagWidth,int bagHeight,int eachWidth,int eachHeight,int eachLeftSpan,int eachUpSpan);
	bool init(int bagWidth,int bagHeight,int eachWidth,int eachHeight,int eachLeftSpan,int eachUpSpan);
	/**
	 * ������Ŀ
	 */
	bool addItem(UIItem *item);
	/**
	 * չʾ
	 */
	void showEach();

	/**
	 * ����
	 */
	void hideEach();

	/** 
	 * ����Ƿ���������
	 */
	bool touchDown(float x,float y);
	/**
	 * ����λ��
	 */
	bool touchMove(float x,float y);
	/**
	 * ֹͣ�϶�
	 */
	bool touchEnd(float x,float y);

	UIItem * getNowChoiceItem();
	bool bind(int uiEvent,const FunctionInfo& function);
protected:
	UIScrollBag()
	{
		slider = NULL;
		bag = NULL;
	}
	CCSprite * slider; // ���� ����offset �����ĵ�ǰλ��
	void updateSlider();
	UIUpBag *bag;
};

NS_CC_END