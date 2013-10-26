#pragma once
#include "cocos2d.h"
#include "UIBase.h"
NS_CC_BEGIN
/**
 * ѡ���
 */
class UIChoice:public UIBase{
public:
	/**
	 * ����ѡ���
	 */
	static UIChoice*create(const char *upSprite,const char *downSprite);

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
	
	void setEditable(bool tag){
		_editable = tag;
	}
	/**
	 * ����λ��
	 */
	virtual void setPosition(float x,float y);
	
	/**
	 * ���ô�С
	 */
	virtual void setSize(float w,float h);
	bool isChoiced(){return _choiced;}

	void setChoiced(bool);
private:
	bool _choiced; // ѡ������
	bool _editable; // �Ƿ��ѡ
	CCSprite *_up; 
	CCSprite *_down;
	bool _touchIn;
	UIChoice()
	{
		_touchIn = false;
		_choiced = false;
		_editable = false;
		_up = false;
		_down = false;
		uiType = UIBase::UI_CHOICE;
	}
	CCPoint nowTouchPoint;
};

NS_CC_END