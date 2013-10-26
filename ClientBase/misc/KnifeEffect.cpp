#include "KnifeEffect.h"
NS_CC_BEGIN
bool KnifeEffect::init()
{
	m_pParticle = CCParticleFireworks::create();
	
	m_pParticle->setTexture( CCTextureCache::sharedTextureCache()->addImage("stars.png") );
	m_pParticle->setVisible(false);
	this->addChild(m_pParticle);
	m_pParticle->stopSystem();
	isTouchDown = false;
	return true;
}
/** 
 * ����Ƿ���������
 */
bool KnifeEffect::touchDown(CCTouch* touch)
{
	CCPoint location = touch->locationInView();	
	//��Ӷ��㵽����
//	_points.push_back(location);
	if (m_pParticle)
	{
		m_pParticle->resetSystem();
		//m_pParticle->setPosition(location);
		m_pParticle->setVisible(false);
		isTouchDown = true;
	}
	return true;
}
/**
 * ����λ��
 */
bool KnifeEffect::touchMove(CCTouch* touch)
{
	CCPoint start = touch->locationInView();		
	
	start = CCDirector::sharedDirector()->convertToGL(start);
	if (m_pParticle && isTouchDown)
	{
		m_pParticle->setVisible(true);
		m_pParticle->setPosition(start) ;
	}
	CCPoint end = touch->previousLocationInView();
	end = CCDirector::sharedDirector()->convertToGL(end);
	CCPoint __p1, __p2 ;
	__p1=end;
	__p2=start;
	
	start= __p1;
	end  = __p2;
	float distance = ccpDistance(start, end);
	if (distance > 1)
	{
		int d = (int)distance;
		for (int i = 0; i < d; i++ )
		{
			float difx = end.x - start.x;
			float dify = end.y - start.y;
			float delta = (float)i / distance;
			CCPoint p;
			p.x = start.x + (difx * delta);
			p.y = start.y + (dify * delta); 
			
			_points.push_back(p);
		}
	}
	return true;
}
/**
 * ֹͣ�϶�
 */
bool KnifeEffect::touchEnd(CCTouch* touch)
{
	_points.clear();
	if (m_pParticle)
		m_pParticle->stopSystem();
	isTouchDown = false;
	return true;
}

void KnifeEffect::draw()
{
	CCSize s = CCDirector::sharedDirector()->getVisibleSize();
	
	float initlw = 0.2;
	float lwc=0.1;
	
	float ps = 1;
	int pl = _points.size();
	
	CCPoint pr;
	std::list <CCPoint>::iterator b = _points.begin();
	
	for(;b!=_points.end();b++)
	{
		CCPoint pt = *b;
		ps++;
	
		//�����߶εĴ�ϸ��ʹ�ﵽ��ͷϸ�м�ֵ�Ч��
		if (ps > (pl -30 )) // initlw > 5 )
		{
		   initlw=initlw-lwc;
		}
		else 
		{
		  if (initlw < 6 ) 
		  {
			initlw =initlw+lwc;
		  }
		}
			
		glLineWidth( initlw);
		if (pr.x > 1 && pr.y > 1 ) 
		{
			//���߶Σ�Ҳ����ʹ�õ�
			ccDrawLine(pr, pt );
		}
		
		pr = *b;
	}
	
	unsigned int pointcount = _points.size();
	//Ϊ��ʹ�߶β�����
	while (pointcount >200) {
		_points.pop_front();
		pointcount=_points.size();
	}
	glLineWidth(1);
}

void KnifeEffect::tick()
{
	_points.clear();
	unsigned int pointcount = _points.size();
	//Ϊ��ʹ�߶β�����
	int count = 2;
	while (count -- > 0)
	{
		if (pointcount > 0) {
			_points.pop_front();
			pointcount=_points.size();
		}
	}
}
NS_CC_END