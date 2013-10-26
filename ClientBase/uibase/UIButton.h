#pragma once
#include "cocos2d.h"
#include "UIBase.h"
NS_CC_BEGIN
/**
 * ������ť
 */
class UIButton:public UIBase{
public:
	/**
	 * ����
	 */
	static UIButton*create(const char *upSprite,const char *downSprite);
	static UIButton*create();
	static UIButton * createWithPngNames(const char *upName,const char *downName,const char *moveName,const char *text,float fontSize=16);
	void beLoaded();
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
	bool checkIn(const CCPoint &pos);
	void setEditable(bool tag){
		_editable = tag;
	}
	void setPosition(float x,float y);
	void setSize(float w,float h);

	void setContent(std::string content)
	{
		this->content = content;
		if (_textLabel)
		_textLabel->setString(content.c_str());
	}
	void setColor(const ccColor3B &color)
	{
		if (_textLabel)
			_textLabel->setColor(color);
	}
	std::string getContent()
	{
		return content;
	}
	UIButton()
	{
		_move = NULL;
		_editable = false;
		_up = NULL;
		_down = NULL;
		_touchIn = false;
		uiType = UIBase::UI_BUTTON;
	}
public:
	std::string upPngName;
	std::string downPngName;
	std::string content;
	virtual TiXmlElement * makeNode(TiXmlElement *parent = NULL,const std::string &name="");
	//SERIALIZE_KIND(UIBase::UI_IMAGE_BUTTON);
private:
	bool _editable; // �Ƿ��ѡ
	bool _touchIn;
	CCSprite *_up; 
	CCSprite *_down;
	CCSprite *_move; // �ƶ�ʱ����
	CCLabelTTF * _textLabel;
	CCPoint nowTouchPoint;
};

/**
 * �����ı���ť
 */
class UITextButton:public UIBase{
public:
	/**
	 * ����
	 */
	static UITextButton*create(const char *text);

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
	void setPosition(float x,float y);
	void setSize(float w,float h);
	UITextButton()
	{
		_editable = false;
		_textDown = NULL;
		_textUp = NULL;
		_touchIn = false;
		uiType = UIBase::UI_BUTTON;
	}
	IMP_SERIALIZE_DATA_FUNC()
	{
		SERIALIZE_DATA(x,0);
		SERIALIZE_DATA(y,1);
		SERIALIZE_DATA(w,2);
		SERIALIZE_DATA(h,3);
		SERIALIZE_DATA(uniqueId,4);
		SERIALIZE_DATA(name,5);
		SERIALIZE_DATA(uiType,6);
		SERIALIZE_DATA(content,7);
	}
	void setColor(const ccColor3B &color)
	{
		if (_textDown)
			_textDown->setColor(color);
		if (_textUp)
			_textUp->setColor(color);
	}
public:
	std::string content;
private:
	bool _editable; // �Ƿ��ѡ
	bool _touchIn;
	CCLabelTTF * _textDown;
	CCLabelTTF * _textUp;
	CCPoint nowTouchPoint;
};

NS_CC_END