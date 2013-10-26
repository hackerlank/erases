#pragma once
#include "cocos2d.h"
NS_CC_BEGIN
/**
 * ��ֵ��
 **/
class UIValue:public CCLayer{
public:
	/**
	 * ������ֵ��
	 */
	static UIValue * create(const char *backPng,const char *valuePng,float maxvalue);
	/**
	 * ������ֵ
	 */
	void setValue(float value);

	void showNumber();
	float getMaxValue(){return _maxvalue;}
	float getValue(){return _value;}
	void setMaxValue(int value){_maxvalue = value;}
private:
	CCSprite *_valuePng;
	CCSprite *_backPng;
	CCLabelTTF* numberText;
	
	float _maxvalue;
	float _value;
	UIValue()
	{
		_valuePng = NULL;
		_backPng = NULL;
		_maxvalue = _value = 0;
		numberText = NULL;
	}
	void init(const char *backPng,const char *valuePng,float maxvalue);
};

NS_CC_END