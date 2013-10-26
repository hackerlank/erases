
#pragma once
#include <vector>
#include "cocos2d.h"
#include "UIItem.h"
#include "UIBase.h"
NS_CC_BEGIN
/**
 * �������� ��������ʹ��id-pos �Ĺ�ϵ Ĭ���Ǹ�����չ��BAG
 */
class UISuperBag;
class UIBagIterator{
public:
	UIItem * getNext();
	UISuperBag *bag;
	int index ;
	UIBagIterator()
	{
		bag = NULL;
	}
};
class UISuperBag :public UIBase{
public:
	friend class UIBagIterator;
	UIBagIterator bagIterator;
	UIBagIterator * getIterator()
	{
		bagIterator.bag = this;
		bagIterator.index = 0;
		return &bagIterator;
	}
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

	virtual bool setItem(UIItem *item,int id);
	/**
	 * ����λ��
	 */
	virtual void setPosition(float x,float y);
	
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
	virtual bool removeItem(UIItem *item);
	/**
	 * �ƶ���Ŀ
	 */
	virtual bool moveItem(UIItem *item,int destId);
	/**
	 * ���ÿɱ༭
	 */
	void setEditable(bool tag){
		_editable = tag;
	}
	/**
	 * ��������
	 */
	static	UISuperBag *create(int viewx,int viewy,int eachWidth,int eachHeight);
	/**
	 * ִ�а����е�ÿ��Ԫ��
	 */
	void execEachItem(stBagExecEach *exec);

	UIItem * getNowChoiceItem();

	int oldTouchItemId;

	UIItem * getItemById(int id)
	{
		if (id >= 0 && id < _items.size()) return _items[id];
		return NULL;
	}
// ����ʵ�ֺ���
	/**
	 * ��ȡ��ǰid ������λ��
	 */
	virtual CCPoint getPixelPosition(int id);

	virtual int getNowTouchBagIdByCursorPosition(const CCPoint& pos);
	/**
	 * ��������Ƿ���������
	 */
	virtual bool checkIn(int x,int y);
	const CCSize & getContentSize()
	{
		return CCSizeMake(0,0);
	}
	void clear();
protected:
	bool _editable;
	int _nowTouchItemId;
	int _viewx; // ��ͼ��ʼ������
	int _viewy; // ��ͼ��ʼ������
	
	int _eachWidth; // ÿ����
	int _eachHeight;  // ÿ����

	std::vector<UIItem*> _items; // ÿ�������б�
	typedef std::vector<UIItem*>::iterator ITEMS_ITER;

	bool _touchIn;
	UISuperBag()
	{
		oldTouchItemId = -1;
		_touchIn = false;
		_editable = false;
		_viewx = 0;
		_viewy = 0;
	
		_eachWidth = 0;
		_eachHeight = 0;
	
		_nowTouchItemId = -1;
	}
	CCPoint nowTouchPoint; 
	virtual void showItem(UIItem *item,bool dynamic =false);
};
/**
 * Բ�εİ���
 */
class UICircleBag:public UISuperBag{
public:
	/**
	 * ��������
	 */
	static	UICircleBag *create(int viewx,int viewy,int eachWidth,int eachHeight,int minRadius,int maxRadius,int itemCount);

	/**
	 * ��ȡ��ǰid ������λ�� ���λ��
	 */
	virtual CCPoint getPixelPosition(int id);
	/**
	 * ���ݾ���λ��Ѱ��id
	 */
	virtual int getNowTouchBagIdByCursorPosition(const CCPoint& pos);
	/**
	 * ��������Ƿ��������� ���������� ���λ��
	 */
	virtual bool checkIn(int x,int y);


	bool init(int,int,int);
protected:
	std::vector<CCPoint> positions; // ����������λ��
	int minRadius;
	int maxRadius;
};
NS_CC_END