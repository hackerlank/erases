#include "UIEditField.h"
NS_CC_BEGIN

/**
* �����༭��
*/
UIEditField * UIEditField::create(const CCPoint &position,const CCSize &size,const char *defaultText)
{
	UIEditField *node = new UIEditField();
	if (node)
	{
		node->setSize(size.width,size.height);
		node->setPosition(position.x,position.y);
		if (node && node->init(defaultText))
		{
			
			node->autorelease();
			return node;
		}
	}
	CC_SAFE_DELETE(node);
	return NULL;
}
UIEditField * UIEditField::create()
{
	UIEditField *node = new UIEditField();
	if (node)
	{
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}
void UIEditField::beLoaded()
{
	init("default");
	setPosition(x,y);
}
bool UIEditField::init(const char *defaultText)
{
	_field = CursorTextField::textFieldWithPlaceHolder(defaultText,"Arial",h);
	if (_field)
		this->addChild(_field);
	defaultContent = defaultText;
	return true;
}

/**
* ����λ��
*/
void UIEditField::setPosition(float x,float y)
{
	CCNode::setPosition(ccp(x,y));
	this->x = x;
	this->y = y;
}

/**
* ���ô�С
*/
void UIEditField::setSize(float w,float h)
{
	this->w = w;
	this->h = h;
}
/** 
* ����Ƿ���������
*/
bool UIEditField::touchDown(float x,float y)
{
	CCPoint pos = ccp(x,y);
	_touchIn = false;
	pos = this->convertToNodeSpace(pos);
	nowTouchPoint = ccp(x,y);
	if (_field)
	{
		float x = _field->getPosition().x;
		float y = _field->getPosition().y;
		CCRect rect = CCRectMake(
			x - (_field->getContentSize().width/2),
			y - (_field->getContentSize().height/2),
			_field->getContentSize().width,
			_field->getContentSize().height);
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
bool UIEditField::touchMove(float x,float y)
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
bool UIEditField::touchEnd(float x,float y)
{
	if (_editable && _touchIn)
	{
		this->doEvent(UIBase::EVENT_EDIT_DOWN,this);
	}
	_touchIn = false;
	return true;
}
/**
* ����Ϊ�ɱ༭ģʽ
*/
void UIEditField::setEditable(bool tag)
{
	_editable = tag;
}
std::string UIEditField::getContent()
{
	if (_field)
	{
		return _field->getString();
	}
	return "";
}
void UIEditField::setContent(const char *content)
{
	if (_field)
	{
		_field->setContent(content);
	}
}
/**
 * �������ڵ��µ��ӽڵ�
 */
TiXmlElement * UIEditField::makeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement * editNode = UIBase::makeNode(parent,"editfield");
	if (editNode)
	{
		editNode->SetAttribute("content",defaultContent);
		editNode->SetAttribute("width",w);
		editNode->SetAttribute("height",h);
	}
	return editNode;
}
NS_CC_END