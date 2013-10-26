#pragma once
#include "cocos2d.h"
#include "UIList.h"
NS_CC_BEGIN
/**
 * ʵ�������б��
 */

class UIChoiceList:public UIList{
public:
	static UIChoiceList* create(const CCRect & viewRect,int eachWidth,int eachHeight);
	/**
	 * ����ʹÿ�����嶯̬��չʾ����
	 */
	void showEachDynamic();
	void showEach();
	/**
	 * ������Ŀѡ��
	 **/
	 void doItemDown(UIItem *item);

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

	/**
	 * ����λ��
	 */
	virtual void setPosition(float x,float y);
	
	/**
	 * ���ô�С
	 */
	virtual void setSize(float w,float h) ;

	virtual void setEditable(bool tag);
	int getNowChoiceId(){if (_nowChoiceItem) return _nowChoiceItem->bagId; return -1;}
	UIItem *getNowChoiceItem(){return _nowChoiceItem;}
	UIItem * getItemByBagId(int bagId);

	void setChoiceId(int id);
private:
	UIItem * _nowChoiceItem; // ��ǰѡ�е���Ŀ
	bool _touchIn;
	bool _editable;
	bool showTag;
	UIChoiceList()
	{
		showTag = true;
		_touchIn = false;
		_editable = false;
		_nowChoiceItem = NULL;
	}
};

NS_CC_END