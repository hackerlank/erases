/**
 * ���ı��༭��ʵ��
 */

#pragma once
#include "cocos2d.h"
#include "vector"
#include "xmlScript.h"
#include "UIBase.h"
NS_CC_BEGIN
struct stUIRichString{
	std::string name;
	std::string content;
	float x; // ��ʼ������
	float y;  // ��ʼ������
	float fontSize; // �����С
	float width; // ������ռ�Ŀ�
	float height; // ������ռ�ĸ�
	int stringType; //���� 
	ccColor3B color; // ��ɫ
	enum{
		UI_STRING_TYPE_FONT, // ����
		UI_STRING_TYPE_IMG, // ͼ��
	};
	stUIRichString()
	{
		x = y = 0;
		fontSize = 0;
		width = height = 0;
		stringType = UI_STRING_TYPE_FONT;
		color = ccWHITE;
	}
};

/**
 * ���ı�����Գ���ͼƬ ����
 */
class UIRichTextArea :public CCLabelBMFont,public script::tixmlCode{
public:
	static UIRichTextArea* createFromFile(CCNode *parent,const char *fileName);
	static UIRichTextArea* createFromString(CCNode *parent,const char *content);
	/**
	 * ����ʵ�ָú�������
	 */
	void createFontChars();
	void createFonts(const unsigned short * m_sString,int nextFontPositionX,int nextFontPositionY,const ccColor3B& m_tColor,int fontSize);
	void createImage(const char * pngName,float x,float y,float w,float h);

	void update(const std::string& name,const std::string& content);
	std::string getValueByName(const std::string &name);
protected:
	std::vector<stUIRichString> _contents;
	typedef std::vector<stUIRichString>::iterator CONTENTS_ITER;
	/**
	 * �������ļ��м�������
	 * \param node ���ø��ڵ�
	 */
	void takeNode(script::tixmlCodeNode *node);
	float width;
	std::string fntFileName;
	float height;
	CCNode *node ;
	UIRichTextArea()
	{
		node = NULL;
		width = height = 0;
	}
	bool initWithXml(const char *fileName);
	bool initFromString(const char *content);
};

class UIRichArea:public UIBase{
public:
	static UIRichArea * create(const char *fileName);
	static UIRichArea * createFromString(const char *content);
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
	 * ����Ϊ�ɱ༭ģʽ
	 */
	virtual void setEditable(bool tag){}

	void setContent(const std::string& content);

	void update(const std::string& name,const std::string& content);
	std::string getValueByName(const std::string &name);
private:
	bool init(const char *fileName);
	bool initFromString(const char *content);
	UIRichTextArea * _textarea;
};
NS_CC_END