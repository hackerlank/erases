#include "UINumber.h"

NS_CC_BEGIN
/**
 *  ����չʾ����
 */
void UINumber::setNumber(float number)
{
	if (labelAtlas)
	{
		std::stringstream ss;
		ss << number;
		labelAtlas->setString(ss.str().c_str());
	}
}


void UINumber::setColor(const ccColor3B &color)
{
	if (labelAtlas)
	{
		labelAtlas->setColor(color);
		this->color = color;
	}
}
UINumber * UINumber::create(float number,const char *pngName,float width,float height,char tap)
{
	UINumber *node = new UINumber();
	if (node)
	{
		if (node)
		{
			std::stringstream ss;
			ss << number;
			node->pngName = pngName;
			node->labelAtlas = CCLabelAtlas::create(ss.str().c_str(),pngName, width, height, tap);
			node->addChild(node->labelAtlas);
			node->autorelease();
			return node;
		}
	}
	CC_SAFE_DELETE(node);
	return NULL;

}

void UINumber::setPosition(float x,float y)
{
	this->x = x;
	this->y = y;
	CCNode::setPosition(ccp(x,y));
}

void UINumber::setSize(float x,float y)
{
	w = x;
	h = y;
}
 /** 
* ����Ƿ���������
*/
bool UINumber::touchDown(float x,float y)
{
	CCPoint pos = ccp(x,y);
	pos = this->convertToNodeSpace(pos);
	nowTouchPoint = ccp(x,y);
	_touchIn = false;
	if (labelAtlas && _editable)
	{
		if (checkIn(pos))
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
bool UINumber::touchMove(float x,float y)
{
	CCPoint pos = ccp(x,y);
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
bool UINumber::touchEnd(float x,float y)
{
	if (_editable && _touchIn)
	{
		this->doEvent(UIBase::EVENT_EDIT_DOWN,this);
	}
	_touchIn = false;
	if (_editable) return false;
	CCPoint pos = ccp(x,y);
	pos = this->convertToNodeSpace(pos);
	if (labelAtlas)
	{
		
		if (checkIn(pos))
		{
			// �����¼�
			doEvent(UIBase::EVENT_CLICK_DOWN,this);
		}
	}
	return true;
}
bool UINumber::checkIn(const CCPoint &pos)
{
	CCRect rect = CCRectMake(
	labelAtlas->getPosition().x,// - (labelAtlas->getContentSize().width/2),
	labelAtlas->getPosition().y,// - (labelAtlas->getContentSize().height/2),
	labelAtlas->getContentSize().width,
	labelAtlas->getContentSize().height);
	return rect.containsPoint(pos);
}
/**
 * �������ڵ��µ��ӽڵ�
 */
TiXmlElement * UINumber::makeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement * numNode = UIBase::makeNode(parent,"number");
	if (numNode)
	{
		numNode->SetAttribute("pngname",pngName);
		numNode->SetAttribute("x",(int)labelAtlas->getPositionX());
		numNode->SetAttribute("y",(int)labelAtlas->getPositionY());
		numNode->SetAttribute("w",w);
		numNode->SetAttribute("h",h);
		numNode->SetAttribute("tap",".");
		numNode->SetAttribute("number",labelAtlas->getString());
		numNode->SetAttribute("r",color.r);
		numNode->SetAttribute("g",color.g);
		numNode->SetAttribute("b",color.b);
	}
	return numNode;
}
NS_CC_END