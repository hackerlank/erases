#pragma once
#include <vector>
#include "cocos2d.h"
#include "UIItem.h"
#include "UIBase.h"
NS_CC_BEGIN
/**
 *�̶���С�İ����ռ� 
 */

class UIUpBag :public UIBase{
public:
	/**
	 * չʾ
	 */
	void show();
	/**
	 * ����
	 */
	void hide();
	/**
	 * ������Ŀ
	 */
	virtual bool addItem(UIItem *item);
	/**
	 * ����λ��
	 */
	virtual void setPosition(float x,float y);
	
	/**
	 * ���ô�С
	 */
	virtual void setSize(float w,float h);
	/** 
	 * ����Ƿ���������
	 */
	virtual bool touchDown(float x,float y);
	/**
	 * ����λ��
	 */
	virtual bool touchMove(float x,float y);
	/**
	 * ֹͣ�϶�
	 */
	virtual bool touchEnd(float x,float y);
	
	/**
	 * ���ÿɱ༭
	 */
	void setEditable(bool tag){
		_editable = tag;
	}
	/**
	 * ��������
	 */
	static	UIUpBag *create(int viewx,int viewy, int bagWidth,int bagHeight,int eachWidth,int eachHeight,int eachLeftSpan,int eachUpSpan);

	void execEachItem(stBagExecEach *exec);

	void setExchange(bool tag){_exchange = tag;}
	UIItem * getNowChoiceItem();
	bool checkIn(const CCPoint &point);
protected:
	bool _exchange;
	bool _editable;
	int _nowTouchItemId;
	int _viewx; // ��ͼ��ʼ������
	int _viewy; // ��ͼ��ʼ������
	int getViewWidth();
	int getViewHeight();
	int _bagWidth; // ������
	int _bagHeight; // ������
	
	int _eachWidth; // ÿ����
	int _eachHeight;  // ÿ����
	int _eachLeftSpan; // ÿ�����϶
	int _eachUpSpan; // ÿ���Ͽ�϶
	std::vector<UIItem*> _items; // ÿ�������б�
	typedef std::vector<UIItem*>::iterator ITEMS_ITER;
	CCPoint startPoint;
	bool _touchIn;
	UIUpBag()
	{
		_exchange = true;
		_touchIn = false;
		_editable = false;
		_viewx = 0;
		_viewy = 0;
		_bagWidth = 0;
		_bagHeight = 0;
		_eachWidth = 0;
		_eachHeight = 0;
		_eachLeftSpan = 0;
		_eachUpSpan = 0;
		_nowTouchItemId = -1;
	}
	CCPoint nowTouchPoint; 
	virtual void showItem(UIItem *item);
};
NS_CC_END