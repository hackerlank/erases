#pragma once
#include "cocos2d.h"
#include "UIBase.h"
#include "xmlScript.h"
NS_CC_BEGIN
/**
 * �¼�������
 */
class UICenterItem;
class UIEvent:public CCObject{
public:
	virtual void doClick(UICenterItem *item) = 0;
};
template<class CHILD_EVENT>
class UIEventCallback:public UIEvent{
public:
	static CHILD_EVENT*create()
	{
		CHILD_EVENT *pRet = new CHILD_EVENT();
		pRet->autorelease();
		return pRet;
	}
};
/**
 * ���ɰ�������Ŀ
 */
class UICenterItem:public CCSprite{
public:
	bool disable;
	bool up;
	std::string uniqueName;
	UICenterItem *parent;
	/**
	 * ����һ����Ŀ
	 */
	static UICenterItem * create(const char *upName,const char * downName,const CCSize & rect);
	bool init(const char *upName,const char * downName,const CCSize & rect);
	enum{
		BAG_ITEM, // ���Ե����Ӳ˵�
		FUNC_ITEM, // ���й��ܵ��Ӳ˵�
	};
	UIEvent* eventHandle; // �¼�����
	void bind(UIEvent *eventHandle)
	{
		this->eventHandle = eventHandle;
		eventHandle->retain();
	}
	void setDisable(bool tag){
		this->disable = tag;
	}
	void setEventOn(){eventOn = true;}
	void setEventOff(){eventOn = false;}
	void setText(const std::string& textContent);

	CCSpriteFrame* downShow;
	CCSpriteFrame* upShow;
	int itemId;
	int itemType;
	int dirType;
	bool inTouch;
	bool eventOn;
	CCSize itemSize;
	CCPoint nowTouchPoint;
	bool canMove; // ��ʶ�Ƿ���ƶ�
	bool choiceAble; // ѡ���ʶ
	UICenterItem()
	{
		choiceAble = false;
		disable = false;
		up = true;
		canMove = false;
		dirType = -1;
		inTouch = false;
		downShow = NULL;
		upShow = NULL;
		itemType = FUNC_ITEM;
		parent = NULL;
		eventHandle = NULL;
		eventOn = true;
		valid = true;
	}
	std::string dirStr;
	~UICenterItem()
	{
		if (upShow) upShow->release();
		if (downShow) downShow->release();
		if (eventHandle) eventHandle->release();
	}

	/**
	 * չʾ
	 */
	virtual void show();
	/**
	 * չʾ
	 */
	virtual void showOnlyMe();
	/**
	 * ����
	 */
	virtual void hide();
	enum{
		TOUCH_DOWN = 0,
		TOUCH_MOVE = 1,
		TOUCH_END = 2,
	};
	/**
	 * ����Ƿ�����
	 * \param touchPoint �����
	 * \return true ���� false ������
	 */
	virtual bool checkIn(const CCPoint & touchPoint);
	/**
	 * ����touch �¼�
	 * \param touchType �������
	 * \param touchPoint ����ĵ�
	 */
	virtual bool onTouch(int touchType,const CCPoint &touchPoint);
	/**
	 * �����ƶ��Ĳ���
	 **/
	bool doTouchCanMove(int touchType,const CCPoint &touchPoint);
	/**
	 * ������
	 */
	virtual void onClick();

	CCSpriteFrame * getFrameByFileName(const char *pngName);
	
	bool valid; // �Ƿ���Ч
	void startProcess();
	void actionEnd_setValid(CCNode *pSender,void *arg);
};
/**
 * ����
 */
class UICenterBag:public UICenterItem{
public:
	static UICenterBag * create(const char *upName,const char * downName,const CCSize & rect);
	bool init(const char *upName,const char * downName,const CCSize & rect);
	std::vector<std::vector<UICenterItem*> > _items;
	typedef std::vector<UICenterItem*>::iterator DIR_ITEMS_ITER;
	typedef std::vector<std::vector<UICenterItem*> >::iterator ITEMS_ITER;
	UICenterItem *nowTouchItem;
	bool nowMove; // ��ʶ��ǰ�Ƿ��ƶ���Ŀ
	bool nowItemMove; // ��ʶ��ǰ�Ƿ��ƶ���Ŀ
	bool canExchange; // �Ƿ���Խ���
	bool canItemMove; // ��ʶ��ǰ�Ƿ�����ƶ���Ŀ
	CCTouch *nowTouch;
	enum{
		LEFT_SET = 0, // �������
		RIGHT_SET = 1, // �ұ�����
		DOWN_SET = 2, // ��������
		UP_SET = 3, // ��������
	};
	UICenterBag()
	{
		nowTouch = NULL;
		canMove = false;
		canExchange = false;
		canItemMove = false;
		nowItemMove = false;
		nowMove = false;
		nowTouchItem = NULL;
		itemType = BAG_ITEM;
		_items.resize(4);
		eachWidth = 64;
		eachHeight = 64;
		eachSpan = 1;
		openTag = false;
	}
	void setMovable(bool tag)
	{
		canMove = tag;
	}
	void setExchange()
	{
		canExchange = true;
		canItemMove = true;
	}
	/**
	 * ���ӵ���
	 * \param ����
	 * \param item ��Ŀ
	 */
	void addItem(int dirType,UICenterItem *item);
	/**
	 * չʾ
	 */
	void show();
	/**
	 * ����
	 */
	void hide();
	bool openTag;
	bool isOpen(){return openTag;}
	void hideWithOutMe();
	int eachWidth; // ÿ����
	int eachHeight; // ÿ����
	int eachSpan; // ÿ�����ӵĿ�϶

	/**
	 * չʾ��Ŀ
	 * \param item ��չʾ��item
	 */
	virtual void showItem(int dirType,UICenterItem *item);
	/**
	 * ����touch �¼�
	 * \param touchType �������
	 * \param touchPoint ����ĵ�
	 */
	virtual bool onTouch(int touchType,const CCPoint &touchPoint);
	virtual bool onTouch(int touchType,CCTouch* touch);
	/**
	 * ������
	 */
	virtual void onClick();
	/**
	 * ����Ƿ�����
	 * \param touchPoint �����
	 * \return true ���� false ������
	 */
	virtual bool checkIn(const CCPoint & touchPoint);
};
/**
 * �������ļ��л�ȡ�ڵ�λ����Ϣ
 */
class UIXmlStoreBag:public UICenterBag{
public:
	static UIXmlStoreBag *create(script::tixmlCodeNode *node);
	bool init(script::tixmlCodeNode *node);
	/**
	 * չʾ��Ŀ
	 * \param item ��չʾ��item
	 */
	virtual void showItem(int dirType,UICenterItem *item);
	std::string upImg;
	std::string downImg;
	int width;
	int height;
	UIXmlStoreBag()
	{
		width = height = 0;
	}
	std::vector<std::vector<CCPoint> > pointList;

	void makeNode(TiXmlElement *parent);
};
/**
 * ������UIBaseϵͳ
 */
class UIStoreBag:public UIBase{
public:
	static UIStoreBag *create(script::tixmlCodeNode *node);
	bool init(script::tixmlCodeNode *node);
	/**
	 * ����touch �¼�
	 * \param touchType �������
	 * \param touchPoint ����ĵ�
	 */
	virtual bool doTouch(int touchType,const CCPoint &touchPoint);
	UIStoreBag()
	{
		_bag = NULL;
	}
	/**
	 * �������ڵ��µ��ӽڵ�
	 */
	virtual TiXmlElement * makeNode(TiXmlElement *parent = NULL,const std::string &name="base");

	void setEditable(bool tag);
private:
	UIXmlStoreBag *_bag;
};
NS_CC_END