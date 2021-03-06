#pragma once

#include "MutiObject.h"
NS_CC_BEGIN
class MutiCartoon:public MutiObject{
public:
	MutiCartoon()
	{
		fromSet = true;
	}
	static MutiCartoon * create(); // 创建空信息
	/**
	 * 从节点上创建动画
	 */
	static MutiCartoon * create(script::tixmlCodeNode *node);
	/**
	 * 从配置文件中读取信息
	 */
	virtual void readNode(script::tixmlCodeNode *node);
	bool init();
	/**
	 * 将信息写入节点当中
	 */
	TiXmlElement * writeNode(TiXmlElement *parent,const std::string &name);

	std::vector<std::string> pngNames; // 图片集合
	float tapTime; // 间隔时间
	int repeateTimes; // 重复的次数

	void rebuild();

	bool checkIn(const CCPoint &point);

	bool fromSet; // 尝试从set文件中加载动画

	std::string cartoonName;
};
NS_CC_END