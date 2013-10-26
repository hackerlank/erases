#include "UIScrollView.h"
NS_CC_BEGIN

UIScrollView* UIScrollView::create(float x,float y,float w,float h)
{
	UIScrollView *node = new UIScrollView();
    if (node)
    {
		node->setSize(w,h);
		node->setPosition(x,y);
        node->autorelease();
        return node;
    }
    CC_SAFE_DELETE(node);
    return NULL;
}
/**
* ���ô�С
*/
void UIScrollView::setSize(float width,float height)
{
	_width = width;
	_height = height;
}
/**
* ����λ��
*/
void UIScrollView::setPosition(float x,float y)
{
	CCNode::setPosition(ccp(x,y));
	_x = x;
	_y  = y;
}
	
/**
 * ��������
 */
bool UIScrollView::addContent(UIBase*node)
{
	if (!node) return false;
//	if (child) this->removeAllChildrenWithCleanup(true);
	this->addChild(node);
	child = node;
	return true;
}
/**
 * ��Ⱦǰ����
 */
void UIScrollView::visit()
{
	// ���ݿռ�ü�
	CCSize szLimitSize= CCSizeMake(_width ,_height);

	CCPoint worldPt = this->getPosition();// ccp(_x,_y);
	worldPt = this->getParent()->convertToWorldSpace(worldPt);
	CCSize size;

	if (CC_CONTENT_SCALE_FACTOR() != 1)
	{
		size.height = szLimitSize.height * CC_CONTENT_SCALE_FACTOR();
		size.width = szLimitSize.width * CC_CONTENT_SCALE_FACTOR();
		worldPt = ccpMult(worldPt, CC_CONTENT_SCALE_FACTOR());
	}
	else

	{
		size.width = szLimitSize.width;
		size.height =szLimitSize.height;
	}
	glEnable(GL_SCISSOR_TEST);  
	CCDirector::sharedDirector()->getOpenGLView()->setScissorInPoints(worldPt.x ,worldPt.y,  size.width, size.height);
	CCNode::visit();  
	glDisable(GL_SCISSOR_TEST);  
}


/** 
 * ����Ƿ���������
 */
bool UIScrollView::touchDown(float x,float y)
{
	if (!this->isVisible()) return false;
	CCPoint pos = ccp(x,y);
	nowTouchPoint = pos;
	startTouchPoint = pos;
	_touchIn = false; 
//	pos = this->convertToNodeSpace(pos);
	if (!checkIn(pos.x,pos.y)) return false;
	if (child && child->touchDown(x,y)) 
	{
		_touchIn = true;
		return true;
	}
	if (checkIn(pos.x,pos.y))
	{
		_touchIn = true;
		return true;
	}
	return false;
}
/**
 * ����λ��
 */
bool UIScrollView::touchMove(float x,float y)
{
	if (!this->isVisible()) return false;
	CCPoint pos = ccp(x,y);
	if (_editable && _touchIn)
	{
		CCPoint nowPoint = ccp(_x,_y);
		float x = nowPoint.x + pos.x - nowTouchPoint.x;
		float y = nowPoint.y + pos.y - nowTouchPoint.y;
		setPosition(x,y);
		nowTouchPoint = pos;
		return true;
	}
	if (!scrollTag)
		if (_touchIn && child && child->touchMove(x,y)) return true;
	if (_touchIn && child && scrollTag)
	{
		CCPoint nowPoint = child->getPosition();
		float x = nowPoint.x + pos.x - nowTouchPoint.x;
		float y = nowPoint.y + pos.y - nowTouchPoint.y;
		if ((_scrollDir == UP_DOWN))
		{
			x = nowPoint.x;
		}
		else if (_scrollDir == LEFT_RIGHT)
		{
			y = nowPoint.y;
		}
		child->setPosition(x,y);
                                      ;
		nowTouchPoint = pos;
		return true;
	}
	return false;
}
/**
 * ֹͣ�϶�
 */
bool UIScrollView::touchEnd(float x,float y)
{
	if (!this->isVisible()) return false;
	_touchIn = false;
	//if (!scrollTag || startTouchPoint.equals(ccp(x,y)))
	if (child)  child->touchEnd(x,y);
	if (_editable) return false;
	return true;
}

bool UIScrollView::checkIn(float x,float y)
{
	CCPoint pos = getPosition();
	pos = this->getParent()->convertToWorldSpace(pos);
	CCRect rect = CCRectMake(
			pos.x,
			pos.y,
			_width,
			_height);
	if (rect.containsPoint(ccp(x,y)))
	{
		return true;
	}
	return false;
}
void UIScrollView::setBack(const char *backName)
{
	if (!back)
	{
		back = CCSprite::create(backName);
		this->addChild(back,19);
		back->setAnchorPoint(ccp(0,0));
	}
	else back->initWithFile(backName);
	back->setScaleX(_width/back->getContentSize().width);
	back->setScaleY(_height/ back->getContentSize().height);
}
NS_CC_END