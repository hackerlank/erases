#pragma once

#include "MutiObject.h"
NS_CC_BEGIN
class MutiCartoon:public MutiObject{
public:
	MutiCartoon()
	{
		fromSet = true;
	}
	static MutiCartoon * create(); // ��������Ϣ
	/**
	 * �ӽڵ��ϴ�������
	 */
	static MutiCartoon * create(script::tixmlCodeNode *node);
	/**
	 * �������ļ��ж�ȡ��Ϣ
	 */
	virtual void readNode(script::tixmlCodeNode *node);
	bool init();
	/**
	 * ����Ϣд��ڵ㵱��
	 */
	TiXmlElement * writeNode(TiXmlElement *parent,const std::string &name);

	std::vector<std::string> pngNames; // ͼƬ����
	float tapTime; // ���ʱ��
	int repeateTimes; // �ظ��Ĵ���

	void rebuild();

	bool checkIn(const CCPoint &point);

	bool fromSet; // ���Դ�set�ļ��м��ض���

	std::string cartoonName;
};
NS_CC_END