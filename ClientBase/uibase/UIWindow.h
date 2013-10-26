#pragma once
/**
 * ȫ�ֱ���
 * ϵͳ�г���dialog dialog����Ƕ��
 */
#include "cocos2d.h"
#include "UIPanel.h"
NS_CC_BEGIN
class CommonPanel:public BaseDialog<CommonPanel>
{};
class UIWindow:public CCNode{
public:

	static UIWindow * create();
	/**
	 * ����һ������
	 */
	void addPanel(UIPanel *panel);

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

	UIPanel * getNowTouchPanel(){return _nowTouchPanel;}
	/**
	 * ɾ����ǰ�Panel
	 */
	void removeNowPanel();
	/**
	 * �������ͼƬ
	 */
	void setCursor(CCSprite *sprite);
	/**
	 * ����ui
	 */
	void addUI(UIBase *base);

	void setNowTouchPanel(UIPanel * pan);
	static bool isClose()
	{
		return false;
	}
	CCPoint getCursorPoint();
	static void release();

	void setEndFunction(const FunctionInfo &function);
	/**
	 * չʾ��ǰ������Ϣ
	 */
	void showErr(const std::string& info);
	UIPanel *getPanel(const std::string &name);
	UIPanel *showPanel(const std::string &name);
	/**
	 * ��panel ����Ϊģ̬
	 */
	void pushModel(UIPanel *panel);
	/**
	 * ������ǰģ̬��
	 */
	void popModel();
private:
	CCLabelTTF * _errLbl;
	void insertBase(UIBase *base);
	typedef std::list<UIPanel*> PANELS;
	PANELS _panels;
	typedef PANELS::iterator PANELS_ITER;
	typedef std::list<UIBase*> BASES;
	std::vector<UIPanel*> _models;
	BASES _bases;
	typedef BASES::iterator BASES_ITER;
	UIPanel *_nowTouchPanel;
	UIPanel *_nowModel;
	CCSprite *_cursor; // ����α�
	UIBase *_nowTouchUI;
	CCPoint nowCursorPoint;
	bool endFlag;
	UIWindow()
	{
		_nowModel = NULL;
		_errLbl = NULL;
		endFlag = false;
		_nowTouchUI = NULL;
		_cursor = NULL;
		_nowTouchPanel = NULL;
	}
};
NS_CC_END
