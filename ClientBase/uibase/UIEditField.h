#pragma once
#include "cocos2d.h"
#include "UIBase.h"
#include "CursorTextField.h"
NS_CC_BEGIN
class UIEditField:public UIBase{
public:
	/**
	 * �����༭��
	 */
	static UIEditField * create(const CCPoint &position,const CCSize &size,const char *defaultText); 
	
	bool init(const char *defaultText);

	/**
	 * ����λ��
	 */
	virtual void setPosition(float x,float y);
	
	/**
	 * ���ô�С
	 */
	virtual void setSize(float w,float h) ;
	 /** 
	 * ����Ƿ���������
	 */
	virtual bool touchDown(float x,float y);
	/**
	 * ����λ��
	 */
	virtual bool touchMove(float x,float y) ;
	/**
	 * ֹͣ�϶�
	 */
	virtual bool touchEnd(float x,float y);

	/**
	 * ����Ϊ�ɱ༭ģʽ
	 */
	virtual void setEditable(bool tag);
	std::string getContent();
	void setContent(const char *content);

	static UIEditField * create();
	void beLoaded();
	/**
	 * �������ڵ��µ��ӽڵ�
	 */
	virtual TiXmlElement * makeNode(TiXmlElement *parent = NULL,const std::string &name="base");
private:
	bool _editable;
	bool _touchIn;
	CursorTextField *_field;
	CCPoint nowTouchPoint;
	std::string defaultContent;
	UIEditField()
	{
		_touchIn = false;
		_editable = false;
		_field = NULL;
		uiType = UIBase::UI_TEXT_FIELD;
	}
};

NS_CC_END