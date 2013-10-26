#pragma once

#include "MutiObject.h"

NS_CC_BEGIN

class MutiImage:public MutiObject{
public:
	std::string pngName;
	static MutiImage * create();
	static MutiImage * create(script::tixmlCodeNode *node);
	/**
	 * �������ļ��ж�ȡ��Ϣ
	 */
	virtual void readNode(script::tixmlCodeNode *node);
	/**
	 * ����Ϣд��ڵ㵱��
	 */
	TiXmlElement * writeNode(TiXmlElement *parent,const std::string &name);
	
	bool checkIn(const CCPoint &point);
	void rebuild();
};

class MutiBigImage:public MutiObject,public script::tixmlCode{
public:
	static MutiBigImage* create(script::tixmlCodeNode *node);
	static MutiBigImage* create(const char *pngName);
	bool init(const char *pngName);

	void saveToXml(float width_pixel_width,const CCPoint &offset,float image_height,float height_pixel_height,const char *pngName,int width_size,int imgSize);

	static MutiBigImage* createFromXml(const  char *pngName);
	bool initFromXml(const char *pngName);

	void takeNode(script::tixmlCodeNode *node);

	/**
	 * �������ļ��ж�ȡ��Ϣ
	 */
	virtual void readNode(script::tixmlCodeNode *node);
	/**
	 * ����Ϣд��ڵ㵱��
	 */
	TiXmlElement * writeNode(TiXmlElement *parent,const std::string &name);

	bool checkIn(const CCPoint &point);
	void rebuild();
private:
	CCPoint offset;
	std::string pngName;
	CCSize size;
};

class MutiBigTerrain:public MutiObject{
public:
	static MutiBigTerrain* create(script::tixmlCodeNode *node);

	/**
	 * ����һ���ر�
	 */
	static MutiBigTerrain* create(const char *fileName,int width,int height);
	/**
	 * ʹ�������ʼ��
	 */
	virtual bool initWithTexture(CCTexture2D *pTexture, const CCRect& rect, bool rotated);
	/**
	 * ��������
	 */
	void setTextureRect(const CCRect& rect, bool rotated, const CCSize& untrimmedSize);
	/**
	 * ����
	 */
	virtual void draw(void);
	virtual void updateTransform(void);

	bool checkIn(float x,float y);

	void setPosition(const CCPoint &point);

	/**
	 * �������ļ��ж�ȡ��Ϣ
	 */
	virtual void readNode(script::tixmlCodeNode *node);
	/**
	 * ����Ϣд��ڵ㵱��
	 */
	TiXmlElement * writeNode(TiXmlElement *parent,const std::string &name);
	void rebuild();

	bool checkIn(const CCPoint &point);
private:
	std::vector<ccV3F_C4B_T2F> points; // ���㼯��
	int _width;
	int _height;
	int _eachWidth;
	int _eachHeight;
	std::string pngName; // ͼƬ����
};
NS_CC_END