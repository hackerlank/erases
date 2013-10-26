#pragma once
#include "cocos2d.h"
#include "xmlScript.h"
#include "Cartoon.h"
NS_CC_BEGIN

class MutiObject :public Cartoon{
public:
	enum MUTIOBJECT_TYPE{
		NULL_TYPE = -1,
		IMAGE_TYPE = 0,
		MOSTER_TYPE = 1,
		MUTIMAP_TYPE = 2,
	};
	MUTIOBJECT_TYPE objectType;
	/**
	 * �������ļ��ж�ȡ��Ϣ
	 */
	virtual void readNode(script::tixmlCodeNode *node);
	/**
	 * ����Ϣд��ڵ㵱��
	 */
	virtual TiXmlElement * writeNode(TiXmlElement *parent,const std::string &name);

	bool checkIn(const CCPoint &point){return false;}

	void setBaseInfo(float x,float y,float w,float h);
	virtual void freshBlock(){}
	void rebuild();
	float w;
	float h;
	MutiObject()
	{
		w = h = 0;
		objectType = NULL_TYPE;
	}
};

NS_CC_END