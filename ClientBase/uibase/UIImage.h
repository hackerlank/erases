#pragma once
#include "cocos2d.h"
#include "UIBase.h"
NS_CC_BEGIN

class UIImage :public UIBase{
public:
	static UIImage * create(const char *imgName);

	bool init(const char *imgName);
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
	 * ����λ��
	 */
	virtual void setPosition(float x,float y);
	
	/**
	 * ���ô�С
	 */
	virtual void setSize(float w,float h);
	void setEditable(bool tag){
		_editable = tag;
	}
	/**
	 * �������ڵ��µ��ӽڵ�
	 */
	virtual TiXmlElement * makeNode(TiXmlElement *parent = NULL,const std::string &name="base");

	bool _editable;
	CCSprite *image;
	std::string imgName;
	UIImage()
	{
		_editable = false;
		image = NULL;
		_touchIn = false;
	}
	bool _touchIn;
	CCPoint nowTouchPoint;
};

NS_CC_END