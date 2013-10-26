#pragma once
#include "cocos2d.h"
#include "UISuperBag.h"
#include "xmlScript.h"
#include "UIScrollView.h"
NS_CC_BEGIN
class UIPanel;
/**
 * ����
 **/
class UIRectBag:public UISuperBag{
public:
	static UIRectBag* create();
	bool init();
	int nowItemId;
	virtual bool setItem(UIItem *item,int id);
	virtual bool addItem(int itemId,int itemNum);
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
	UIRectBag()
	{
		_width = _height = 0;
		_eachUpSpan = _eachLeftSpan = 0;
		nowItemId = -1;
	}
	float getViewWidth();
	float getViewHeight();
};

/**
 * ����
 */
class UIViewBag:public UIRectBag,public script::tixmlCode{
public:
	/**
	 * ����UI����
	 */
	static UIViewBag *create(const char*bagName);
	static UIViewBag *create(script::tixmlCodeNode *node);
	bool initWithNode(script::tixmlCodeNode *node);
	bool init(const char*bagName);
	const CCSize & getContentSize();
	void show();
	void hide();
	bool isVisible();
	void addToParent(CCNode *node);
	void takeNode(script::tixmlCodeNode *node);
	/**
	 * �������ڵ��µ��ӽڵ�
	 */
	virtual TiXmlElement * makeNode(TiXmlElement *parent = NULL,const std::string &name="base");
	bool doTouch(int touchType,const CCPoint &touchPoint);
	UIViewBag()
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
};

class XmlBagItem:public UIItem{
public:
	static XmlBagItem* create(script::tixmlCodeNode *node);
	bool initWithNode(script::tixmlCodeNode *node);
	XmlBagItem()
	{
		panel = NULL;
	}
	virtual bool doTouch(int touchType,const CCPoint &touchPoint);
	UIPanel * getPanel(){return panel;}
	virtual void setSize(float width,float height);

	void doCreateEvent();

	std::string onCreateName;
private:
	UIPanel *panel;
};
NS_CC_END