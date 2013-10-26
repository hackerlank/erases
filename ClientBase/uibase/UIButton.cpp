#include "UIButton.h"
#include "UILib.h"
NS_CC_BEGIN
/**
 * ����
 */
UIButton* UIButton::create(const char *upSprite,const char *downSprite)
{
	UIButton *node = new UIButton();
	if (node)
	{
		node->_up = CCSprite::create(upSprite);
		node->_down = CCSprite::create(downSprite);
		node->upPngName = upSprite;
		node->downPngName = downSprite;
		if (node->_up && node->_down)
		{
			node->addChild(node->_up);
			node->addChild(node->_down );
			node->_up->setVisible(true);
			node->_down->setVisible(false);
			node->autorelease();
			return node;
		}
	}
	CC_SAFE_DELETE(node);
	return NULL;
}
UIButton* UIButton::createWithPngNames(const char *upName,const char *downName,const char *moveName,const char *text,float fontSize)
{
	UIButton *node = new UIButton();
	if (node)
	{
		node->_up = CCSprite::create(upName);
		node->_down = CCSprite::create(downName);
		node->_move = CCSprite::create();
		node->_textLabel = CCLabelTTF::create(text, "Arial", fontSize);
		node->upPngName = upName;
		node->downPngName = downName;
		if (node->_up && node->_down && node->_move)
		{
			node->addChild(node->_up);
			node->addChild(node->_down );
			node->addChild(node->_move);
			node->addChild(node->_textLabel);
			node->_up->setVisible(true);
			node->_down->setVisible(false);
			node->_move->setVisible(false);
			node->autorelease();
			return node;
		}
	}
	CC_SAFE_DELETE(node);
	return NULL;
}
UIButton*UIButton::create()
{
	UIButton *node = new UIButton();
	if (node)
	{
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}
void UIButton::beLoaded()
{
	_up = CCSprite::create(upPngName.c_str());
	_down = CCSprite::create(downPngName.c_str());
	if (_up && _down)
	{
		addChild(_up);
		addChild(_down );
		_up->setVisible(true);
		_down->setVisible(false);
		setPosition(x,y);
		setSize(w,h);
		setContent(content);
	}
}
TiXmlElement * UIButton::makeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement * btnNode = UIBase::makeNode(parent,"button");
	if (btnNode)
	{
		btnNode->SetAttribute("downimg",downPngName);
		btnNode->SetAttribute("upimg",upPngName);
		if (_textLabel)
			btnNode->SetAttribute("name",_textLabel->getString());
	}
	return btnNode;
}
/** 
 * ����Ƿ���������
 */
bool UIButton::touchDown(float x,float y)
{
	CCPoint pos = ccp(x,y);
	_touchIn = false;
	pos = this->convertToNodeSpace(pos);
	nowTouchPoint = ccp(x,y);
	if (_up && _down)
	{
		if (checkIn(pos))
		{
			if (!_editable)
			{
				_up->setVisible(false);
				_down->setVisible(true);
				if (_move)
				{
					_move->setVisible(false);
				}
			}
			_touchIn = true;
			return true;
		}
	}
	return false;
}
/**
 * ����λ��
 */
bool UIButton::touchMove(float x,float y)
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
	pos = this->convertToNodeSpace(pos);
	if (_up && _down)
	{
		if (checkIn(pos))
		{
			if (_move)
			{
				_up->setVisible(false);
				_down->setVisible(false);
				_move->setVisible(true);
			}
		}
	}
	return false;
}
/**
 * ֹͣ�϶�
 */
bool UIButton::touchEnd(float x,float y)
{
	bool  tag = false;
	if (_editable && _touchIn)
	{
		this->doEvent(UIBase::EVENT_EDIT_DOWN,this);
		tag = true;
	}
	
	if (_editable) return false;
	CCPoint pos = ccp(x,y);
	pos = this->convertToNodeSpace(pos);
	if (_up && _down && _touchIn)
	{
		_up->setVisible(true);
		_down->setVisible(false);
		if (_move)
		{
			_move->setVisible(false);
		}
		if (checkIn(pos))
		{
			// �����¼�
			doEvent(UIBase::EVENT_CLICK_DOWN,this);
			UIStub stub(this,NULL);
			theUILib.execCode(&stub,this->onClickCodeName.c_str());
			tag = true;
		}
		else
			tag = false;
	}
	_touchIn = false;
	return tag;
}
bool UIButton::checkIn(const CCPoint &pos)
{
	float width = _up->getContentSize().width * _up->getScaleX();
	float height = _up->getContentSize().height * _up->getScaleY();
	float x = _up->getPositionX() - (width/2);
	float y = _up->getPositionY() - (height/2);
	CCRect rect = CCRectMake(x,y,width,height);
	return rect.containsPoint(pos);
}
void UIButton::setPosition(float x,float y)
{
	CCNode::setPosition(ccp(x,y));
	this->x = x;
	this->y = y;
}

void UIButton::setSize(float w,float h)
{
	if (_up)
	{
		_up->setScaleX(w / _up->getContentSize().width);
		_up->setScaleY(h / _up->getContentSize().height);
	}
	if (_down)
	{
		_down->setScaleX(w / _down->getContentSize().width);
		_down->setScaleY(h / _down->getContentSize().height);
	}
	this->w = w;
	this->h = h;
}


/**
 * ����
 */
UITextButton* UITextButton::create(const char *text)
{
	UITextButton *node = new UITextButton();
	if (node)
	{
		node->_textUp = CCLabelTTF::create(text, "Arial", 12);
		node->_textDown = CCLabelTTF::create(text, "Arial", 16);
		if (node->_textUp && node->_textDown)
		{
			node->addChild(node->_textUp);
			node->addChild(node->_textDown );
			node->_textUp->setVisible(true);
			node->_textDown->setVisible(false);
		//	node->_textUp->retain();
		//	node->_textDown->retain();
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
bool UITextButton::touchDown(float x,float y)
{
	CCPoint pos = ccp(x,y);
	_touchIn = false;
	pos = this->convertToNodeSpace(pos);
	nowTouchPoint = ccp(x,y);
	if (_textUp && _textDown)
	{
		float width = _textUp->getContentSize().width * _textUp->getScaleX();
		float height = _textUp->getContentSize().height * _textUp->getScaleY();
		CCRect rect = CCRectMake(
			_textUp->getPosition().x - (width/2),
			_textUp->getPosition().y - (height/2),
			width,
			height);
		if (rect.containsPoint(pos))
		{
			if (!_editable)
			{
				_textUp->setVisible(false);
				_textDown->setVisible(true);
			}
			_touchIn = true;
			return true;
		}
	}
	return false;
}
/**
 * ����λ��
 */
bool UITextButton::touchMove(float x,float y)
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
bool UITextButton::touchEnd(float x,float y)
{
	if (_editable && _touchIn)
	{
		this->doEvent(UIBase::EVENT_EDIT_DOWN,this);
	}
	_touchIn = false;
	if (_editable) return false;
	CCPoint pos = ccp(x,y);
	pos = this->convertToNodeSpace(pos);
	if (_textDown && _textUp)
	{
		float width = _textUp->getContentSize().width * _textUp->getScaleX();
		float height = _textUp->getContentSize().height * _textUp->getScaleY();
		CCRect rect = CCRectMake(
			_textUp->getPosition().x - (width/2),
			_textUp->getPosition().y - (_textUp->getContentSize().height/2),
			width,
			height);
		_textUp->setVisible(true);
		_textDown->setVisible(false);
		if (rect.containsPoint(pos))
		{
			// �����¼�
			doEvent(UIBase::EVENT_CLICK_DOWN,this);
			UIStub stub(this,NULL);
			theUILib.execCode(&stub,this->onClickCodeName.c_str());
		}
		
	}
	return true;
}
void UITextButton::setPosition(float x,float y)
{
	CCNode::setPosition(ccp(x,y));
	this->x = x;
	this->y = y;
}

void UITextButton::setSize(float w,float h)
{
	this->w = w;
	this->h = h;
	if (_textUp)
	{
		_textUp->setScaleX(w / _textUp->getContentSize().width);
		_textUp->setScaleY(h / _textUp->getContentSize().height);
	}
	if (_textDown)
	{
	//	_textDown->setScaleX(w / _textDown->getContentSize().width);
	//	_textDown->setScaleY(h / _textDown->getContentSize().height);
	}
}

NS_CC_END