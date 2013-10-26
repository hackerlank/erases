#pragma once

/**
 * ��Ϸ������
 */
#include "cocos2d.h"
#include "UIPanel.h"
#include "UIItem.h"
#include "UIChoiceList.h"
#include "UIBag.h"
#include "UILabel.h"
#include "UIEditField.h"
#include "UIWindow.h"
NS_CC_BEGIN
class UIEventCallback{
public:
	virtual void init(UIWindow *window) = 0;
};
/**
 * �������Button �� sysui
 */
class UIMain:public script::tixmlCode,public CCObject{
public:
	UIMain()
	{
		window = NULL;
	}
	static UIMain *create(CCNode *scene);
	static UIMain *create(CCNode *scene,UIEventCallback *callback);
	void init(UIEventCallback*callback);
	void takeNode(script::tixmlCodeNode *node);
	virtual void parseCode(script::tixmlCodeNode *code)
	{
		theUILib.parseCode(code); // ��ۿ�ִ�нڵ�
	}
	UIWindow *window;

	bool touchDown(float x,float y);
	bool touchMove(float x,float y);
	bool touchEnd(float x,float y);
};
NS_CC_END