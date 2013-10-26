#include "UIXmlBag.h"
#include "UIPanel.h"
#include "UILib.h"
NS_CC_BEGIN
//////////////////////////// ���� /////////////////////////////////////
UIRectBag* UIRectBag::create()
{
	UIRectBag *node = new UIRectBag();
	if (node && node->init())
	{
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}
bool UIRectBag::init()
{
	this->_eachHeight = 64;
	this->_eachWidth = 64;
	this->_width = 4;
	this->_height = 4;
	_items.resize(this->_width* this->_height);
	_eachLeftSpan = 1;
	_eachUpSpan = 1;
	CCSprite *bagBack = CCSprite::create("bagback.png");
	if (bagBack)
	{
		this->addChild(bagBack);
		bagBack->setAnchorPoint(ccp(0,0));
		bagBack->setScaleX((65*4) / bagBack->getContentSize().width);
		bagBack->setScaleY((65*4)/ bagBack->getContentSize().height);
	}
	for (int i = 0;i < 16;i++)
	{
		CCSprite *bagItem = CCSprite::create("itemback.png");
		bagItem->setAnchorPoint(ccp(0,0));
		bagItem->setPosition(this->getPixelPosition(i));
		bagItem->setScaleX(this->_eachWidth / bagItem->getContentSize().width);
		bagItem->setScaleY(this->_eachHeight / bagItem->getContentSize().height);
		this->addChild(bagItem);
	}
	return true;
}
bool UIRectBag::setItem(UIItem *item,int id)
{
	if (!item) return false;
//	int x = id % (int)_width ;
//	int y = id / (int)_height;
//	id =  (this->_height - y -1) * _width + x;
	return UISuperBag::setItem(item,id);
}
bool UIRectBag::addItem(int itemId,int itemNum)
{
	int index = 0;
	return false;
}
/**
* ��ȡ��ǰid ������λ��
*/
CCPoint UIRectBag::getPixelPosition(int id)
{
	int x = id % ((int)_width);
	int y = id / _width;
	return getPixelPosition(x,y);
}

CCPoint UIRectBag::getPixelPosition(int x,int y)
{
	CCPoint pos = ccp( x * (_eachWidth + _eachLeftSpan) + _eachLeftSpan,
	(_height - y - 1) * (_eachUpSpan + _eachHeight) + _eachUpSpan);
	return pos;
}
const CCSize & UIRectBag::getContentSize()
{
	return CCSizeMake(_width * (_eachWidth + _eachLeftSpan),_height*(_eachUpSpan + _eachHeight));
}
int UIRectBag::getNowTouchBagIdByCursorPosition(const CCPoint& point)
{
	CCPoint pos = this->convertToNodeSpace(point);
	if ( pos.x >= 0 && pos.y >= 0 && pos.x <= getViewWidth() && pos.y <= getViewHeight())
	{
		int dx = (pos.x) / (_eachWidth + _eachLeftSpan);
		int dy = (pos.y) / (_eachUpSpan + _eachHeight);

		return (_height - dy -1) * _width + dx;
	}
	return -1;
}
float UIRectBag::getViewWidth()
{
	return _width * (_eachWidth + _eachLeftSpan);
}
float UIRectBag::getViewHeight()
{
	return _height * (_eachUpSpan + _eachHeight) ;
}
/**
* ��������Ƿ���������
*/
bool UIRectBag::checkIn(int x,int y)
{
	if ( x >= 0 && y >= 0 && x <= getViewWidth() && y <= getViewHeight())
	{
		int dx = (x) / (_eachWidth + _eachLeftSpan);
		int dy = (y) / (_eachUpSpan + _eachHeight);
		int id = (_height - dy) * _width + dx;
		//if (id < _items.size() && _items.at(id))
			return true;
	}
	return false;
}

float UIRectBag::getPixelWidth()
{
	return (_eachWidth + _eachLeftSpan) * (_items.size() > _width?_width: _items.size());
}
float UIRectBag::getPixelHeight()
{ 
	return (_eachHeight + _eachUpSpan) * ((_items.size() / (int)_width ) +1);
}

/**
* ����UI����
*/
 UIViewBag *UIViewBag::create(const char*bagName)
 {
	UIViewBag *node = new UIViewBag();
	if (node && node->init(bagName))
	{
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
 }
UIViewBag *UIViewBag::create(script::tixmlCodeNode *snode)
{
	UIViewBag *node = new UIViewBag();
	if (node && node->initWithNode(snode))
	{
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}

bool  UIViewBag::doTouch(int touchType,const CCPoint &touchPoint)
{
	if (view)
	{
		return view->doTouch(touchType,touchPoint);
	}
	else
	{
		return UIRectBag::doTouch(touchType,touchPoint);
	}
	return false;
}
bool UIViewBag::initWithNode(script::tixmlCodeNode *node)
{
	if (node->equal("bag"))
	{
		backName = node->getAttr("back");
		CCSprite *back = CCSprite::create(backName.c_str());
		if (back)
		{
			this->addChild(back);
		}
		this->_eachHeight = node->getInt("eachheight");
		this->_eachWidth = node->getInt("eachwidth");
		this->_width = node->getInt("width");
		this->_height = node->getInt("height");
		_items.resize(this->_width* this->_height);
		_eachLeftSpan =  node->getInt("leftspan");
		_eachUpSpan =  node->getInt("upspan");
		script::tixmlCodeNode viewNode = node->getFirstChildNode("face");
		if (viewNode.isValid())
		{
			viewx = viewNode.getFloat("viewx");
			viewy = viewNode.getFloat("viewy");
			vieww = viewNode.getFloat("vieww");
			viewh = viewNode.getFloat("viewh");
			view = UIScrollView::create(viewx,viewy,vieww,viewh);
			scrollTypeStr = node->getAttr("scrollable");
			if (view)
			{
				((UIScrollView*)view)->addContent(this);
				view->setEditable(false);
				if (scrollTypeStr == "true")
				((UIScrollView*)view)->setScrollAble(true);
				else
				((UIScrollView*)view)->setScrollAble(false);
			}
		}
	}
	show();
	return true;
}
/**
 * �������ڵ��µ��ӽڵ�
 */
TiXmlElement * UIViewBag::makeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement * bagNode = UIBase::makeNode(parent,"bag");
	if (bagNode)
	{
		bagNode->SetAttribute("back",backName);
		bagNode->SetAttribute("width",_width);
		bagNode->SetAttribute("height",_height);
		bagNode->SetAttribute("leftspan",_eachLeftSpan);
		bagNode->SetAttribute("upspan",_eachUpSpan);
		bagNode->SetAttribute("eachheight",_eachHeight);
		bagNode->SetAttribute("eachwidth",_eachWidth);
		
		TiXmlElement *faceNode = new TiXmlElement("face");
		bagNode->LinkEndChild(faceNode);
		faceNode->SetAttribute("viewx",viewx);
		faceNode->SetAttribute("viewy",viewy);
		faceNode->SetAttribute("vieww",vieww);
		faceNode->SetAttribute("viewh",viewh);
		faceNode->SetAttribute("scrollable",scrollTypeStr);
	}
	return bagNode;
}
bool UIViewBag::init(const char*bagName)
{
	unsigned long nSize = 0;
	unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData("localshop.xml","rb",&nSize);
	if (!nSize)return false;
	script::tixmlCode::initFromString((char*) buffer);
	show();
	return true;
}
const CCSize & UIViewBag::getContentSize()
{
	return CCSizeMake(this->_eachWidth * this->_width,this->_eachHeight * this->_height);
}
void UIViewBag::show()
{
	UIRectBag::show();
	if (view)
	{
		view->setVisible(true);
	}
}
void UIViewBag::hide()
{
	if (view)
	{
		view->setVisible(false);
	}
}
bool UIViewBag::isVisible()
{
	if (view)
	{
		return view->isVisible();
	}
	return false;
}
void UIViewBag::addToParent(CCNode *node)
{
	if (view)
	{
		node->addChild(view);
	}
	else
	{
		node->addChild(this);
	}
}
void UIViewBag::takeNode(script::tixmlCodeNode *node)
{
	if (node)
	{
		initWithNode(node);
	}
}

XmlBagItem* XmlBagItem::create(script::tixmlCodeNode *snode)
{
	XmlBagItem *node = new XmlBagItem();
	if (node && node->initWithNode(snode))
	{
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return NULL;
}
bool XmlBagItem::initWithNode(script::tixmlCodeNode *node)
{
	panel = UIPanel::createFromNode(node);
	this->addChild(panel);
	panel->setAnchorPoint(ccp(0,0));
	if (panel->back)
	panel->back->setAnchorPoint(ccp(0,0));
	onCreateName = node->getAttr("oncreate");
	return true;
}
bool XmlBagItem::doTouch(int touchType,const CCPoint &touchPoint)
{
	if (panel)
	{
		panel->doTouch(touchType,touchPoint);
	}
	return true;
}
void XmlBagItem::setSize(float width,float height)
{
	if (panel)
	{
		panel->setSize(width,height);
	}
}

void XmlBagItem::doCreateEvent()
{
	UIStub stub(panel,panel->getWindow());
	theUILib.execCode(&stub,this->onCreateName.c_str());
}
NS_CC_END