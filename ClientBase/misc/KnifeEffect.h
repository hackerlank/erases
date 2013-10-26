/**
 * ʵ�ֵ���Ч��������
 */
#pragma once
#include "cocos2d.h"
#include <list>
NS_CC_BEGIN
class KnifeEffect:public CCLayer{
public:
	CREATE_FUNC(KnifeEffect);
	bool init();
	/** 
	 * ����Ƿ���������
	 */
	bool touchDown(CCTouch* touch);
	/**
	 * ����λ��
	 */
	bool touchMove(CCTouch* touch);
	/**
	 * ֹͣ�϶�
	 */
	bool touchEnd(CCTouch* touch);

	void draw();

	void tick();
private:
	std::list<CCPoint> _points; 
	CCParticleSystem*  m_pParticle ;
	KnifeEffect()
	{
		m_pParticle = NULL;
		isTouchDown = false;
	}
	bool isTouchDown;
};

NS_CC_END