#pragma once
#include "cocos2d.h"
#include "UIBase.h"
NS_CC_BEGIN

class UILabel:public UIBase{
public:
	static UILabel* create(const char *content,float fontSize);
	static UILabel* create();
	void beLoaded();
	bool initWithContent(const char *content,float fontSize);

	void setPosition(float x,float y);

	void setSize(float x,float y);

	 /** 
	 * ����Ƿ���������
	 */
	virtual bool touchDown(float x,float y) ;
	/**
	 * ����λ��
	 */
	virtual bool touchMove(float x,float y);
	/**
	 * ֹͣ�϶�
	 */
	virtual bool touchEnd(float x,float y);
	/**
	 *  ����չʾ����
	 */
	void setContent(const char *content);

	void setEditable(bool tag)
	{
		_editable = tag;
	}
	std::string getContent(){if (text) return text->getString();return "";}
	void setColor(const ccColor3B &color); 
	
	UILabel()
	{
		_touchIn = false;
		_editable = false;
		text = NULL;
		uiType = UIBase::UI_LABEL;
	}
	/**
	 * �������ڵ��µ��ӽڵ�
	 */
	virtual TiXmlElement * makeNode(TiXmlElement *parent = NULL,const std::string &name="base");
private:
	CCLabelTTF *text;
	CCPoint nowTouchPoint;
	bool _editable;
	bool _touchIn;
	std::string content;
	ccColor3B color;
};

NS_CC_END