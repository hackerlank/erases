#include "UICenterBag.h"
#include "PngPack.h"
//#include "HBGame.h"
//#include "RpgResourceManager.h"
NS_CC_BEGIN

UICenterItem * UICenterItem::create(const char *upName,const char * downName,const CCSize & size)
{
	UICenterItem *pRet = new UICenterItem();
    if (pRet && pRet->init(upName, downName,size))
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}
bool UICenterItem::init(const char *upName,const char * downName,const CCSize & size)
{
	downShow = getFrameByFileName(downName);//theUIPack->getFrame(downName);
	upShow = getFrameByFileName(upName);//theUIPack->getFrame(upName);
    if (!downShow || !upShow) return false;
	CCSprite::initWithSpriteFrame(upShow);
	this->setScaleX(size.width / this->getContentSize().width);
	this->setScaleY(size.height / this->getContentSize().height);
	//this->setAnchorPoint(ccp(0,0));
	downShow->retain();
	this->itemSize = size;
	upShow->retain();
	return true;
}
CCSpriteFrame * UICenterItem::getFrameByFileName(const char *pngName)
{
	CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage(pngName);
    if (!texture) return NULL;
	CCSpriteFrame *frame = CCSpriteFrame::frameWithTexture(texture,CCRectMake(0,0,texture->getContentSize().width,texture->getContentSize().height));
	return frame;
}
void UICenterItem::startProcess()
{
	valid = false;
	// ����һ������ ������ʱ�䵽��valid ����Ϊtrue
	CCAnimation* animation = CCAnimation::create();
		std::string frameNames[] = {
			std::string("skill_p_00000.png"),
			std::string("skill_p_00001.png"),
			std::string("skill_p_00002.png"),
			std::string("skill_p_00003.png"),
			std::string("skill_p_00004.png"),
			std::string("skill_p_00005.png"),
		};
	for (int i = 0; i < 3; i++)
	{
		CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage(frameNames[i].c_str());
		
		CCSpriteFrame *frame = CCSpriteFrame::frameWithTexture(texture,CCRectMake(0,0,texture->getContentSize().width,texture->getContentSize().height));
		
		animation->addSpriteFrame(frame);
	}
	CCSprite * temp = CCSprite::create();
	this->getParent()->addChild(temp);
	temp->setPosition(this->getPosition());
	animation->setDelayPerUnit(1.5f / 2);
	animation->setRestoreOriginalFrame(true);
	temp->runAction(CCSequence::create(CCAnimate::create(animation),
		CCCallFuncND::create(this, callfuncND_selector(UICenterItem::actionEnd_setValid), (void*)temp),NULL));

}
void UICenterItem::actionEnd_setValid(CCNode *pSender,void *arg)
{
	CCSprite * temp = (CCSprite*) arg;
	temp->removeFromParentAndCleanup(true);
	valid = true;
}
/**
* չʾ
*/
void UICenterItem::show()
{
	this->setVisible(true);
}
/**
* չʾ
*/
void UICenterItem::showOnlyMe()
{
	this->setVisible(true);
}
/**
* ����
*/
void UICenterItem::hide()
{
	this->setVisible(false);
}

/**
* ����Ƿ�����
* \param touchPoint �����
* \return true ���� false ������
*/
bool UICenterItem::checkIn(const CCPoint & touchPoint)
{
	if (disable) return false;
	if (!this->isVisible()) return false;
	CCPoint target = this->convertToNodeSpace(touchPoint);
	float width = this->getContentSize().width;
	float height = this->getContentSize().height;
	CCPoint pos = getPosition();
	CCRect rect = CCRectMake(
			 0,
			 0,
			width,
			height);
	if (rect.containsPoint(target))
	{
		return true;
	}
	return false;
}
/**
* ����touch �¼�
* \param touchType �������
* \param touchPoint ����ĵ�
*/
bool  UICenterItem::onTouch(int touchType,const CCPoint &touchPoint)
{
	if (!this->isVisible()) return false;
	switch(touchType)
	{
		case UICenterItem::TOUCH_DOWN:
		{
			if (checkIn(touchPoint))
			{
				inTouch = true;
				nowTouchPoint = touchPoint;
				if (!choiceAble)
					initWithSpriteFrame(downShow);
			}
		}break;
		case UICenterItem::TOUCH_END:
		{
			if (inTouch)
			{
				if (choiceAble)
				{
					if (up)
					{
						up = false;
						initWithSpriteFrame(downShow);
					}
					else
					{
						up = true;
						initWithSpriteFrame(upShow);
					}
				}
				else
				{
					initWithSpriteFrame(upShow);
				}
				if (checkIn(touchPoint))
					onClick();
			}

			inTouch = false;
		}break;
	}
	//this->setAnchorPoint(ccp(0,0));
	return inTouch;
}

bool UICenterItem::doTouchCanMove(int touchType,const CCPoint &touchPoint)
{
	if (!this->isVisible()) return false;
	switch(touchType)
	{
		case UICenterItem::TOUCH_DOWN:
		{
			if (checkIn(touchPoint))
			{
				inTouch = true;
				nowTouchPoint = touchPoint;
				if (!choiceAble)
					initWithSpriteFrame(downShow);
				return  true;
			}
		}break;
		case UICenterItem::TOUCH_MOVE:
		{
			if (inTouch && canMove)
			{
				CCPoint nowPoint = getPosition();
				setPosition(ccp(nowPoint.x + touchPoint.x - nowTouchPoint.x,
                                  nowPoint.y + touchPoint.y - nowTouchPoint.y));
				nowTouchPoint = touchPoint;
				return true;
			}
		}break;
		case UICenterItem::TOUCH_END:
		{
			if (inTouch)
			{
				if (choiceAble)
				{
					if (up)
					{
						up = false;
						initWithSpriteFrame(downShow);
					}
					else
					{
						up = true;
						initWithSpriteFrame(upShow);
					}
				}
				else
				{
					initWithSpriteFrame(upShow);
				}
				if (checkIn(touchPoint))
					onClick();
			}

			inTouch = false;
			
		}break;
	}
	//this->setAnchorPoint(ccp(0,0));
	return false;
}
void UICenterItem::setText(const std::string& textContent)
{
	CCLabelTTF *text = CCLabelTTF::create(textContent.c_str(),"Arial",32);
	if (text)
	{
		text->setPosition(ccp(32,32));
		this->addChild(text);
	}
}
/**
 * ������
 */
void UICenterItem::onClick()
{
	if (!eventOn)
	{
		return ;
	}
	if (eventHandle)
		eventHandle->doClick(this);
	//CCDirector::sharedDirector()->replaceScene( CCTransitionFlipY::create(0.5,HBGame::scene()) );
}
UICenterBag * UICenterBag::create(const char *upName,const char * downName,const CCSize & rect)
{
	UICenterBag *pRet = new UICenterBag();
    if (pRet && pRet->init(upName, downName,rect))
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}
bool UICenterBag::init(const char *upName,const char * downName,const CCSize & size)
{
	if (UICenterItem::init(upName,downName,size))
	{
		this->hideWithOutMe();
		return true;
	}
	return false;
}
/**
 * ���ӵ���
 * \param ����
 * \param item ��Ŀ
 */
void UICenterBag::addItem(int dirType,UICenterItem *item)
{
	item->itemId = _items[dirType].size();
	item->dirType = dirType;
	_items[dirType].push_back(item);
	this->addChild(item,-1 * item->itemId);
	item->parent = this;
}
/**
 * չʾ
 */
void UICenterBag::show()
{
	this->setVisible(true);
	int index = 0;
	for ( ITEMS_ITER iter = _items.begin(); iter != _items.end();++iter,++index)
	{
		for (DIR_ITEMS_ITER pos = iter->begin(); pos != iter->end();++pos)
		{
			(*pos)->showOnlyMe();
			showItem(index,*pos);
		}
	}
	openTag = true;
}
/**
 * ����
 */
void UICenterBag::hide()
{
	this->setVisible(false);
	for ( ITEMS_ITER iter = _items.begin(); iter != _items.end();++iter)
		for (DIR_ITEMS_ITER pos = iter->begin(); pos != iter->end();++pos)
		{
			(*pos)->hide();
		}
	openTag = false;
}
void UICenterBag::hideWithOutMe()
{
	for ( ITEMS_ITER iter = _items.begin(); iter != _items.end();++iter)
		for (DIR_ITEMS_ITER pos = iter->begin(); pos != iter->end();++pos)
		{
			(*pos)->hide();
		}
	openTag = false;
}


/**
 * չʾ��Ŀ
 * \param item ��չʾ��item
 */
void UICenterBag::showItem(int dirType,UICenterItem *item)
{
	CCPoint dir[4] = {
		CCPoint(-1,0),// �������
		CCPoint(1,0), // �ұ�����
		CCPoint(0,-1), // ��������
		CCPoint(0,1),// ��������
	};

	CCPoint dest = //ccpAdd(this->getPosition(),
		ccp(dir[dirType].x * (item->itemId + 1)* (eachSpan + eachWidth) + 32,dir[dirType].y * (item->itemId + 1)* (eachSpan + eachHeight) + 32);
		//);
	item->setPosition(ccp(32,32));
	int index = _items[dirType].size() - item->itemId; // item->itemId
	CCFiniteTimeAction *action1 = CCSequence::create(CCDelayTime::create(0.3f*index),CCMoveTo::create(0.3f,dest),NULL);
	//item->setPosition(dest);
	CCFiniteTimeAction * action2 = CCSequence::create(CCHide::create(),CCDelayTime::create(0.3f*index),CCShow::create(),CCFadeIn::create(0.5),NULL);
	CCFiniteTimeAction *spawn = CCSpawn::create(action1,action2,NULL);
	item->runAction(spawn);
}
bool UICenterBag::onTouch(int touchType,CCTouch* touch)
{
	CCPoint touchPoint = touch->getLocation();
	switch(touchType)
	{
		case TOUCH_DOWN:
		{
			if (nowTouch) return false;
			if (onTouch(touchType,touchPoint))
			{
				nowTouch = touch;
				return true;
			}
			return false;
		}break;
	}
	if (nowTouch != touch) return false;
	if (touchType == TOUCH_END)
	{
		nowTouch = NULL;
	}
	return onTouch(touchType,touchPoint);
}
/**
 * ����touch �¼�
 * \param touchType �������
 * \param touchPoint ����ĵ�
 */
bool UICenterBag::onTouch(int touchType,const CCPoint &touchPoint)
{
	if (!this->isVisible()) return false;
	CCPoint nowPos = this->convertToNodeSpace(touchPoint);
	if (UICenterItem::checkIn(touchPoint))
	{
		nowMove = true;
	}
	if (nowMove)
	{
		if (canMove)
		{
			if (parent)
			{
				if (touchType == UICenterItem::TOUCH_MOVE)
				{
					if (inTouch)
					{
						CCPoint nowPoint = parent->getPosition();
						parent->setPosition(ccp(nowPoint.x + touchPoint.x - nowTouchPoint.x,
										  nowPoint.y + touchPoint.y - nowTouchPoint.y));
						nowTouchPoint = touchPoint;
						return true;
					}
				}
			}
		}
		if (doTouchCanMove(touchType,touchPoint))
				return true;
		if (touchType == UICenterItem::TOUCH_END)
			nowMove = false;
	}
	switch(touchType)
	{
		case UICenterItem::TOUCH_DOWN:
		{
			for ( ITEMS_ITER iter = _items.begin(); iter != _items.end();++iter)
				for (DIR_ITEMS_ITER pos = iter->begin(); pos != iter->end();++pos)
				{
					if ((*pos)->checkIn(touchPoint))
					{
						nowTouchItem = *pos;
					}
				}
			nowTouchPoint = touchPoint;
		}break;
		case UICenterItem::TOUCH_MOVE:
		{
			if (nowTouchItem && canItemMove)
			{
				nowTouchItem->setPosition(nowPos); // �����ƶ���Ŀ
				if (!nowTouchPoint.equals(touchPoint))
				{
					nowItemMove = true;
					nowTouchItem->setEventOff();
				}
			}
		}break;
	}
	if (nowTouchItem)
	{
		nowTouchItem->onTouch(touchType,touchPoint);
	}
	switch(touchType)
	{
		case UICenterItem::TOUCH_END:
		{
			if (nowItemMove)
			{
				nowTouchItem->setEventOn();
				if (canExchange)
				{
					// TODO ��������
					UICenterItem *destItem = NULL;
					for ( ITEMS_ITER iter = _items.begin(); iter != _items.end();++iter)
						for (DIR_ITEMS_ITER pos = iter->begin(); pos != iter->end();++pos)
						{
							if ((*pos)->checkIn(touchPoint) && *pos != nowTouchItem)
							{
								destItem = *pos;
							}
						}
					if (destItem != nowTouchItem && destItem)
					{
						_items[destItem->dirType][destItem->itemId] = nowTouchItem;
						_items[nowTouchItem->dirType][nowTouchItem->itemId] = destItem;
						int dirType = destItem->dirType;
						int itemId = destItem->itemId;
						destItem->dirType = nowTouchItem->dirType;
						destItem->itemId = nowTouchItem->itemId;
						nowTouchItem->dirType = dirType;
						nowTouchItem->itemId = itemId;
					}
					if (destItem)
						showItem(destItem->dirType,destItem);
				}
				showItem(nowTouchItem->dirType,nowTouchItem);
				
			}
			nowTouchItem = NULL;
			nowMove = false;
			nowItemMove = false;
		}break;
	}
	if (nowTouchItem) return true;
	return false;
}
void UICenterBag::onClick()
{
	bool showTag = !this->isOpen();
	if (!showTag)
		hideWithOutMe();
	else
		show();
}
/**
* ����Ƿ�����
* \param touchPoint �����
* \return true ���� false ������
*/
bool UICenterBag::checkIn(const CCPoint & touchPoint)
{
	if (UICenterItem::checkIn(touchPoint)) return true;
	for ( ITEMS_ITER iter = _items.begin(); iter != _items.end();++iter)
	{
		for (DIR_ITEMS_ITER pos = iter->begin(); pos != iter->end();++pos)
		{
			if ((*pos)->checkIn(touchPoint))
				return true;
		}
	}
	return false;
}

/**
 * �������ļ��л�ȡ�ڵ�λ����Ϣ
 */

UIXmlStoreBag *UIXmlStoreBag::create(script::tixmlCodeNode *node)
{
	UIXmlStoreBag *pRet = new UIXmlStoreBag();
    if (pRet && pRet->init(node))
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}
bool UIXmlStoreBag::init(script::tixmlCodeNode *node)
{
	// �������� ���Ҵ�������
	upImg = node->getAttr("upname");
	downImg = node->getAttr("downname");
	width = node->getInt("width");
	height = node->getInt("height");
	int x = node->getInt("x");
	int y = node->getInt("y");
	this->setPosition(ccp(x,y));
	std::string moveable = node->getAttr("moveable");
	if (moveable == "false")
	{
		this->setMovable(false);
	}
	if (moveable == "true")
	{
		this->setMovable(true);
	}
	if (UICenterBag::init(upImg.c_str(),downImg.c_str(),CCSizeMake(width,height)))
	{
		// ����һЩ��Ŀ	
		script::tixmlCodeNode itemNode = node->getFirstChildNode("item");
		while (itemNode.isValid())
		{
			std::string upImg = node->getAttr("upname");
			std::string downImg = node->getAttr("downname");
			int width = node->getInt("width");
			int height = node->getInt("height");
		
			int dirType = UICenterBag::LEFT_SET;

			UICenterItem *item = UICenterItem::create(upImg.c_str(),downImg.c_str(),CCSizeMake(width,height));
			item->dirStr = node->getAttr("dir");
			if (item->dirStr == "left")
			{
				dirType = UICenterBag::LEFT_SET;
			}
			if (item->dirStr == "right")
			{
				dirType = UICenterBag::RIGHT_SET;
			}
			if (item->dirStr == "up")
			{
				dirType = UICenterBag::UP_SET;
			}
			if (item->dirStr == "down")
			{
				dirType = UICenterBag::DOWN_SET;
			}
			addItem(dirType,item);
			itemNode = itemNode.getNextNode("item");
		}
		script::tixmlCodeNode posNode = node->getFirstChildNode("position");
		while(posNode.isValid())
		{
			int id = 0;
			CCPoint pos;
			posNode.getAttr("id",id);
			posNode.getAttr("x",pos.x);
			posNode.getAttr("y",pos.y);
			int dirType = 0;
			std::string dirStr = node->getAttr("dir");
			if (dirStr == "left")
			{
				dirType = UICenterBag::LEFT_SET;
			}
			if (dirStr == "right")
			{
				dirType = UICenterBag::RIGHT_SET;
			}
			if (dirStr == "up")
			{
				dirType = UICenterBag::UP_SET;
			}
			if (dirStr == "down")
			{
				dirType = UICenterBag::DOWN_SET;
			}
			if (dirType >= pointList.size())
			{
				pointList.resize(dirType + 1);
			}
			if (id >= pointList[dirType].size())
			{
				pointList[dirType].resize(id + 1);
			}
			pointList[dirType][id] = pos;
			posNode = posNode.getNextNode("position");
		}
	}
	show();
	return true;
}
void UIXmlStoreBag::makeNode(TiXmlElement *parent)
{
	parent->SetAttribute("upname",upImg);
	parent->SetAttribute("downname",downImg);
	parent->SetAttribute("x",(int)this->getPositionX());
	parent->SetAttribute("y",(int)this->getPositionY());
	parent->SetAttribute("width",width);
	parent->SetAttribute("height",height);
}
/**
* չʾ��Ŀ
* \param item ��չʾ��item
*/
void UIXmlStoreBag::showItem(int dirType,UICenterItem *item)
{
	if (dirType < pointList.size())
	{
		if (item->itemId < pointList[dirType].size())
		{
			item->setPosition(pointList[dirType][item->itemId]);
		}
	}
}
/**
 * �������ڵ��µ��ӽڵ�
 */
TiXmlElement * UIStoreBag::makeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement * storeBag = UIBase::makeNode(parent,"storebag");
	if (storeBag)
	{
		storeBag->SetAttribute("uniquename",uniqueName);
		_bag->makeNode(storeBag);
	}
	return storeBag;
}
/**
 * ������UIBaseϵͳ
 */

UIStoreBag *UIStoreBag::create(script::tixmlCodeNode *node)
{
	UIStoreBag *pRet = new UIStoreBag();
    if (pRet && pRet->init(node))
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}
bool UIStoreBag::init(script::tixmlCodeNode *node)
{
	_bag = UIXmlStoreBag::create(node);
	if (_bag)
	{
		this->addChild(_bag);
	}
	return true;
}
/**
* ����touch �¼�
* \param touchType �������
* \param touchPoint ����ĵ�
*/
bool UIStoreBag::doTouch(int touchType,const CCPoint &touchPoint)
{
	if (_bag)
	{
		return _bag->onTouch(touchType,touchPoint);
	}
	return false;
}
void UIStoreBag::setEditable(bool tag)
{
	if (_bag)
	{
		_bag->setMovable(tag);
	}
}

NS_CC_END
