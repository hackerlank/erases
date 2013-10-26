#pragma once
#include <vector>
#include "cocos2d.h"
#include "UIItem.h"
#include "UIBase.h"
#include "UISuperBag.h"
#include "UIScrollView.h"
#include "xmlScript.h"
NS_CC_BEGIN
/**
 * ����
 **/
class UIList:public UISuperBag{
public:
	static UIList* create();
	bool init();
	int nowItemId;
	virtual bool setItem(UIItem *item,int id);
	/**
	 * ��ȡ��ǰ���ӵĿ�
	 */
	float getPixelWidth();
	/**
	 * ��ȡ��ǰ���ӵĸ�
	 **/
	float getPixelHeight();
	
	/**
	 * ͨ��bagid��ȡzpos
	 */
	//zPos getZPosByBagId(int bagId);
	CCPoint getPixelPosition(int x,int y);
	const CCSize & getContentSize();
	/**
	 * ����λ��
	 */
	virtual void setPosition(float x,float y);
public:
	/**
	 * ��ȡ��ǰid ������λ��
	 */
	virtual CCPoint getPixelPosition(int id);

	virtual int getNowTouchBagIdByCursorPosition(const CCPoint& pos);
	/**
	 * ��������Ƿ���������
	 */
	virtual bool checkIn(int x,int y);

	float _width; // ��
	float _height; // ��
	float _eachUpSpan; // ÿ���� span
	float _eachLeftSpan; // ÿ����span
	bool vertical;
	UIList()
	{
		vertical = true;
		_width = _height = 0;
		_eachUpSpan = _eachLeftSpan = 0;
		nowItemId = -1;
	}
	float getViewWidth();
	float getViewHeight();
};
/**
 * ��������ͼ��List
 */
class UIViewList:public UIList,public script::tixmlCode{
public:
	static UIViewList *create(script::tixmlCodeNode *node);
	bool initWithNode(script::tixmlCodeNode *node);
	const CCSize & getContentSize();
	void show();
	void hide();
	bool isVisible();
	void addToParent(CCNode *node);
	/**
	 * �������ڵ��µ��ӽڵ�
	 */
	virtual TiXmlElement * makeNode(TiXmlElement *parent = NULL,const std::string &name="base");
	bool doTouch(int touchType,const CCPoint &touchPoint);
	UIViewList()
	{
		view = NULL;
		viewx = viewy = viewh = vieww = 0;
	}
	UIBase *view;
	std::string backName;
	float viewx;
	float viewy;
	float vieww;
	float viewh;
	std::string scrollTypeStr;

	/**
	 * ����λ��
	 */
	virtual void setPosition(float x,float y);

	
};

NS_CC_END