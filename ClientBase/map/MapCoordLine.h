#pragma once
#include "cocos2d.h"
#include <vector>
NS_CC_BEGIN
/**
 * ����������
 */

class MapCoordLine:public CCSprite{
public:
	/**
	 * ����һ��������
	 */
	static MapCoordLine* create(const char *fileName,int width,int height,int eachWidth,int eachHeight);
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
	/**
	 * ����˵����Ϣ
	 */
	void initDescInfo();
private:
	int _width; // ��
	int _height; // ��
	int _eachWidth; // �����
	int _eachHeight; // �����
	std::vector<ccV3F_C4B_T2F> points; // ���㼯��
};

NS_CC_END