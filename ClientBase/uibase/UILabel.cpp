#include "UILabel.h"
NS_CC_BEGIN
UILabel* UILabel::create(const char *content,float fontSize)
{
	UILabel *node = new UILabel();
	if (node)
	{
		if (node->initWithContent(content,fontSize))
		{
			node->autorelease();
			return node;
		}
	}
	CC_SAFE_DELETE(node);
	return NULL;
}
UILabel* UILabel::create()
{
	UILabel *node = new UILabel();
	if (node)
	{
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}
void UILabel::beLoaded()
{
	initWithContent(this->content.c_str(),16);
	setPosition(x,y);
	setSize(w,h);
}
bool UILabel::initWithContent(const char *content,float fontSize)
{
	text = CCLabelTTF::create(content, "Arial", fontSize);
	this->addChild(text);
	this->content = content;
	return true;
}
void UILabel::setColor(const ccColor3B &color)
{
	if (text)
		text->setColor(color);
	this->color = color;
}
void UILabel::setPosition(float x,float y)
{
	this->x = x;
	this->y = y;
	CCNode::setPosition(ccp(x,y));
}
void UILabel::setSize(float x,float y)
{
	if (text)
	{
	//	text->setScaleX(x / text->getContentSize().width);
	//	text->setScaleY(y /text->getContentSize().height);
	}
	this->w = x;
	this->h = y;
}
 /** 
* ����Ƿ���������
*/
bool UILabel::touchDown(float x,float y)
{
	CCPoint pos = ccp(x,y);
	pos = this->convertToNodeSpace(pos);
	nowTouchPoint = ccp(x,y);
	_touchIn = false;
	if (text && _editable)
	{
		CCRect rect = CCRectMake(
			text->getPosition().x - (text->getContentSize().width/2),
			text->getPosition().y - (text->getContentSize().height/2),
			text->getContentSize().width,
			text->getContentSize().height);
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
bool UILabel::touchMove(float x,float y)
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
bool UILabel::touchEnd(float x,float y)
{
	if (_editable && _touchIn)
	{
		this->doEvent(UIBase::EVENT_EDIT_DOWN,this);
	}
	_touchIn = false;
	if (_editable) return false;
	CCPoint pos = ccp(x,y);
	pos = this->convertToNodeSpace(pos);
	if (text)
	{
		CCRect rect = CCRectMake(
			text->getPosition().x - (text->getContentSize().width/2),
			text->getPosition().y - (text->getContentSize().height/2),
			text->getContentSize().width,
			text->getContentSize().height);
		if (rect.containsPoint(pos))
		{
			// �����¼�
			doEvent(UIBase::EVENT_CLICK_DOWN,this);
		}
	}
	return true;
}

/**
*  ����չʾ����
*/
void UILabel::setContent(const char *content)
{
	if (text)
	{
		text->setString(content);
	}
	this->content = content;
}
/**
 * �������ڵ��µ��ӽڵ�
 */
TiXmlElement * UILabel::makeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement * lblNode = UIBase::makeNode(parent,"label");
	if (lblNode)
	{
		lblNode->SetAttribute("content",text->getString());
		lblNode->SetAttribute("fontsize",text->getFontSize());
		lblNode->SetAttribute("r",color.r);
		lblNode->SetAttribute("g",color.g);
		lblNode->SetAttribute("b",color.b);
	}
	return lblNode;
}
NS_CC_END