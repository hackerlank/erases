#pragma once
#include "cocos2d.h"
#include "UILabel.h"
#include "UIBase.h"
NS_CC_BEGIN
/**
 * ͨ�������� ������ֵ
 */
class UILineValue:public UIBase{
public:
	/**
	 * ����
	 */
	static UILineValue* create(const char *backname,const char *valuename,float minValue,float maxValue,float defaultValue);
	/**
	 * ��ʼ��
	 */
	bool init(const char *backname,const char *valuename,float minValue,float maxValue,float defaultValue);
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
		//_editable = tag;
	}
	/**
	 * ����λ��
	 */
	virtual void setPosition(float x,float y);
	
	/**
	 * ���ô�С
	 */
	virtual void setSize(float w,float h);

	float getNowValue(){return nowValue;}
protected:
	UILineValue()
	{
		minValue = 0;
		maxValue =100;
		nowValue = 0;
		_back = NULL;
		_span = NULL;
		width = height = 0;
		_touchIn = false;
		_info = NULL;
	}
	CCPoint nowTouchPoint;
	bool _touchIn;
	float width;
	float height;
	float minValue;
	float maxValue;
	float nowValue;
	CCSprite * _back; // ����
	CCSprite *_span; // ��ʾ��
	UILabel * _info;
	void update();
};

NS_CC_END