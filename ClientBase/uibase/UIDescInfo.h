#pragma once
#include "cocos2d.h"
#include "UIXmlBag.h"
#include "UICenterBag.h"
#include "xmlScript.h"
#include "UITextArea.h"
NS_CC_BEGIN
/**
 * һ�ֽ�������Ϣ��ʾ
 */
class RpgText:public CCNode{
public:
	static RpgText * create(script::tixmlCodeNode *node);
	static RpgText *create(const char *str,float width,float fontSize,const ccColor3B& color);
	bool init(const char *str,float width,float fontSize,const ccColor3B& color);
	void update(const std::string &content);
private:
	UIMultiLineArea* infoLabel;
	RpgText()
	{
		infoLabel = NULL;
	}
};
class RpgInfoUI:public CCNode,public script::tixmlCode{
public:
	/**
	 * ��ʼ��
	 */
	bool init(const char *fileName);
	/**
	 * ����ڵ�
	 */
	void takeNode(script::tixmlCodeNode *node);
	std::map<std::string,RpgText*> updateContents;
	typedef std::map<std::string,RpgText*>::iterator UPDATE_CONTENTS_ITER;

	std::map<std::string,CCSprite*> sprites; // �����б�
	std::vector<UIViewBag*> bags;
	/**
	 * ����name ָ������ֵ
	 */
	void updateNumber(const std::string& name,int number);

	void updateString(const std::string &name,const std::string& content);
	/**
	 * ����ÿ��tag��չʾ
	 */
	void show(const std::string &name,bool showTag);

	/**
	 * չʾ
	 */
	void show();
	/**
	 * ����
	 */
	void hide();
	/**
	 * ������
	 **/
	bool doTouch(int touchType,const CCPoint &touchPoint);
    UICenterItem * getBtnByName(const std::string & name);
    std::map<std::string,UICenterItem*> buttons;
	//UICenterItem *close;
	const CCSize & getContentSize();
	CCSize backSize;
};

NS_CC_END