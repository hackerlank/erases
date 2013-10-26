#include "UIChoice.h"
NS_CC_BEGIN
/**
* ����ѡ���
*/
UIChoice*UIChoice::create(const char *upSprite,const char *downSprite)
{
	UIChoice *node = new UIChoice();
	if (node)
	{
		node->_up = CCSprite::create(upSprite);
		node->_down = CCSprite::create(downSprite);
		if (node->_up && node->_down)
		{
			node->addChild(node->_up);
			node->addChild(node->_down );
			node->setChoiced(false);
			node->autorelease();
			return node;
		}
	}
	CC_SAFE_DELETE(node);
	return NULL;
}

/** 
* ����Ƿ���������
*/
bool UIChoice::touchDown(float x,float y)
{
	CCPoint pos = ccp(x,y);
	pos = this->convertToNodeSpace(pos);
	nowTouchPoint = ccp(x,y);
	if (_up && _down)
	{
		CCRect rect = CCRectMake(
			_up->getPosition().x - (_up->getContentSize().width/2),
			_up->getPosition().y - (_up->getContentSize().height/2),
			_up->getContentSize().width,
			_up->getContentSize().height);
		if (rect.containsPoint(pos))
		{
			_touchIn = true;
			return true;
		}
	}
	return false;
}
/**
* ����λ��
*/
bool UIChoice::touchMove(float x,float y)
{
	CCPoint pos = ccp(x,y);
//	pos = this->convertToNodeSpace(pos);
	if (_editable && _touchIn)
	{
		CCPoint nowPoint = getPosition();
        setPosition(nowPoint.x + pos.x - nowTouchPoint.x,
                                      nowPoint.y + pos.y - nowTouchPoint.y);
		nowTouchPoint = pos;
		return true;
	}
	return false;
}
/**
* ֹͣ�϶�
*/
bool UIChoice::touchEnd(float x,float y)
{
	_touchIn = false;
	if (_editable) return false;
	CCPoint pos = ccp(x,y);
	pos = this->convertToNodeSpace(pos);
	if (_up && _down)
	{
		CCRect rect = CCRectMake(
			_up->getPosition().x - (_up->getContentSize().width/2),
			_up->getPosition().y - (_up->getContentSize().height/2),
			_up->getContentSize().width,
			_up->getContentSize().height);
		if (rect.containsPoint(pos))
		{
			_choiced = !_choiced;
			setChoiced(_choiced);
			doEvent(UIBase::EVENT_CLICK_DOWN,this);
		}
	}
	return true;
}
void UIChoice::setChoiced(bool tag)
{
	_choiced = tag;
	if (_choiced)
	{
		_up->setVisible(false);
		_down->setVisible(true);
	}
	else
	{
		_up->setVisible(true);
		_down->setVisible(false);
	}
}
/**
* ����λ��
*/
void  UIChoice::setPosition(float x,float y)
{
	CCNode::setPosition(ccp(x,y));
	this->x = x;
	this->y = y;
}
	
/**
* ���ô�С
*/
void  UIChoice::setSize(float w,float h)
{
	if (_up)
	{
		_up->setScaleX( w / _up->getContentSize().width);
		_up->setScaleY( h / _up->getContentSize().height);
	}
	if (_down)
	{
		_down->setScaleX( w / _down->getContentSize().width);
		_down->setScaleY( h / _down->getContentSize().height);
	}
	this->w = w;
	this->h = h;
}
NS_CC_END