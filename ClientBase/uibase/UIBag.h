#pragma once
#include <vector>
#include "cocos2d.h"
#include "UIItem.h"
#include "UIBase.h"
NS_CC_BEGIN
/**
 *�̶���С�İ����ռ� 
 */

class UIBag :public UIBase{
public:
	/**
	 * չʾ
	 */
	void show(bool dynamic = false);
	/**
	 * ����
	 */
	void hide();
	/**
	 * ������Ŀ
	 */
	virtual bool addItem(UIItem *item);

	bool setItem(UIItem *item,int x,int y);
	/**
	 * ����λ��
	 */
	virtual void setPosition(float x,float y);
	bool setItem(UIItem *item,int bagId);
	/**
	 * ���ô�С
	 */
	virtual void setSize(float w,float h);
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
	 * ��̬������Ŀ��λ��
	 */
	virtual bool setBagDynamicPos(UIItem * item,const CCPoint& sPos,const CCPoint& dPos);
	
	/**
	 * ɾ����Ŀ
	 */
	virtual bool removeItem(UIItem *item,bool wait =true);
	/**
	 * �ƶ���Ŀ
	 */
	virtual bool moveItem(UIItem *item,const CCPoint& dPos,bool exchange = false);
	/**
	 * ���ÿɱ༭
	 */
	void setEditable(bool tag){
		_editable = tag;
	}
	/**
	 * ��������
	 */
	static	UIBag *create(int viewx,int viewy, int bagWidth,int bagHeight,int eachWidth,int eachHeight,int eachLeftSpan,int eachUpSpan);

	void execEachItem(stBagExecEach *exec);

	UIItem * getNowChoiceItem();

	int oldTouchItemId;

	UIItem * getItemById(int id)
	{
		if (id >=0 && id < _items.size()) return _items[id];
		return NULL;
	}
	int getWidth()
	{
		return _bagWidth;
	}
	int getHeight()
	{
		return _bagHeight;
	}
	UIItem * getItemByPos(int x,int y)
	{
		int id = x + y *_bagWidth;
		return getItemById(id);
	}
	CCPoint getPixelPosition(int x,int y);

	int getNowTouchBagIdByCursorPosition(const CCPoint& pos);

	void setBackgroud(const char *backpngName);
protected:
	CCSprite *back;
	bool _editable;
	int _nowTouchItemId;
	int _viewx; // ��ͼ��ʼ������
	int _viewy; // ��ͼ��ʼ������
	int getViewWidth();
	int getViewHeight();
	int _bagWidth; // ������
	int _bagHeight; // ������
	
	int _eachWidth; // ÿ����
	int _eachHeight;  // ÿ����
	int _eachLeftSpan; // ÿ�����϶
	int _eachUpSpan; // ÿ���Ͽ�϶
	std::vector<UIItem*> _items; // ÿ�������б�
	typedef std::vector<UIItem*>::iterator ITEMS_ITER;
	std::set<UIItem*> _waitRemoveItems;
	bool _touchIn;
	UIBag()
	{
		back = NULL;
		oldTouchItemId = -1;
		_touchIn = false;
		_editable = false;
		_viewx = 0;
		_viewy = 0;
		_bagWidth = 0;
		_bagHeight = 0;
		_eachWidth = 0;
		_eachHeight = 0;
		_eachLeftSpan = 0;
		_eachUpSpan = 0;
		_nowTouchItemId = -1;
	}
	CCPoint nowTouchPoint; 
	virtual void showItem(UIItem *item,bool dynamic =false);
};
NS_CC_END