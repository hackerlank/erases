#pragma once
#include "cocos2d.h"
#include "vector"
NS_CC_BEGIN
/**
 * ʵ����ɫ�����ı��� ��Ϣչʾ�� ��������򵥵ķ��� 
 */
class UITextArea:public CCLabelBMFont{
public:
	/**
	 * ����UITextArea
	 */
	static UITextArea * create(const char *str, const char *fntFile);
	/**
	 * ����ʵ�ָ��ļ�����
	 */
	void createFontChars();
	/**
	 * ����������ɫ
	 */
	void setColors(int startId,int endId,const ccColor3B& color);
private:
	std::vector<ccColor3B> colors;
};
 
/**
 * �����ı��Ľ������
 **/
class UIMultiLineArea:public CCNode{
public:
	/**
	 * �����ı� ���������Զ����� ����һ�µ���ɫ һ�µĴ�С
	 */
	static UIMultiLineArea *create(const char *str,float width,float fontSize,const ccColor3B& color);

	bool init(const char *str,float width,float fontSize,const ccColor3B& color);

	void update(const std::string &content);
	float width;
	float fontSize;
	ccColor3B color;
};
NS_CC_END