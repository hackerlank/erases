/**
 * ʵ�ִ��вü�����Ĺ�����ͼ
 */
#pragma once
#include "cocos2d.h"
#include "UIBase.h"
NS_CC_BEGIN
class UIScrollView:public UIBase{
public:
	static UIScrollView* create(float x,float y,float w,float h);
	/**
	 * ���ô�С
	 */
	void setSize(float width,float height);
	/**
	 * ����λ��
	 */
	void setPosition(float x,float y);
	/**
	 * ��������
	 */
	bool addContent(UIBase*node);
	/**
	 * ��Ⱦǰ����
	 */
	virtual void visit();
	/**
	 * create ��������
	 */
	CREATE_FUNC(UIScrollView);
	bool init(){return true;}
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

	bool checkIn(float x,float y);
	enum{
		UP_DOWN = 1, // �����ƶ�
		LEFT_RIGHT = 2, // �����ƶ�
		SCROLL_ALL = 3, // ���������ƶ�
	};
	/**
	 * ���ù�������
	 */
	void setScrollType(int scollType)
	{
		_scrollDir = scollType;
	}
	void setScrollAble(bool tag)
	{
		scrollTag = tag;
	}
	virtual void setEditable(bool tag){
		_editable = tag;
	}
	UIBase* child;
	/**
	 * �������ڵ��µ��ӽڵ�
	 */
	virtual TiXmlElement * makeNode(TiXmlElement *parent = NULL,const std::string &name="base")
	{
		if (child)
			return child->makeNode(parent,name);
		return NULL;
	}
	void setBack(const char *backName);
	CCSprite *back;
protected:
	bool scrollTag;
	int _scrollDir; // ���ù�������
	bool _touchIn; // �Ƿ��ڸ������ڲ���
	CCPoint nowTouchPoint; // ��ǰtouch �ĵ�
	CCPoint startTouchPoint;
	bool _editable;
	float _x;
	float _y;
	float _width;
	float _height;
	UIScrollView()
	{
		back = NULL;
		scrollTag = true;
		_editable = true;
		_x = _y = _width = _height = 0;
		child = NULL;
		_scrollDir = LEFT_RIGHT;
		_touchIn = false;
	}
};

NS_CC_END