#include "UISuperBag.h"
#include "UIBag.h"
NS_CC_BEGIN
UIItem * UIBagIterator::getNext()
{
	if (index< bag->_items.size())
	{
		index ++;
		return bag->_items.at(index);
	}
	return NULL;
}
/**
 * չʾ
 */
void UISuperBag::show(bool dynamic)
{
	this->setVisible(false);
	for (ITEMS_ITER iter = _items.begin(); iter != _items.end();++iter)
	{
		UIItem *i = *iter;
		if (i)
		{
			i->setVisible(true);
			showItem(i,dynamic);
		}
	}
	this->setVisible(true);
}
/**
 * ����
 */
void UISuperBag::hide()
{
	this->setVisible(false);
	for (ITEMS_ITER iter = _items.begin(); iter != _items.end();++iter)
	{
		UIItem *i = *iter;
		if (i)
		{
			i->setVisible(false);
		}
	}
}

void UISuperBag::execEachItem(stBagExecEach *exec)
{
	if (!exec) return;
	for (ITEMS_ITER iter = _items.begin(); iter != _items.end(); ++iter)
	{
		exec->exec(*iter);
	}
}
/**
 * ������Ŀ
 */
bool UISuperBag::addItem(UIItem *item)
{
	if (!item) return false;
	unsigned int index = 0;
	item->bag = this;
	for (ITEMS_ITER iter = _items.begin(); iter != _items.end();++iter,++index)
	{
		UIItem *i = *iter;
		if (!i)
		{
			_items[index] = item;
			item->bagId = index;
			item->setSize(_eachWidth,_eachHeight);
			this->addChild(item);
			return true;
		}
	}
	
	item->bagId = _items.size();
	_items.push_back(item);
	item->setSize(_eachWidth,_eachHeight);
	this->addChild(item);
	return true;
}

bool UISuperBag::setItem(UIItem *item,int id)
{
	if (!item) return false; 
	item->setSize(_eachWidth,_eachHeight);
	int bagId = id;
	if (bagId >= _items.size())
	{
		_items.resize(bagId + 1);
	}
	item->bagId = bagId;
	_items[bagId] = item;
	this->addChild(item);
	return true;
}
/**
* ��̬������Ŀ��λ��
*/
bool UISuperBag::setBagDynamicPos(UIItem * item,const CCPoint& sPos,const CCPoint& dPos)
{
	if (!item) return false;
	CCPoint srcPos = sPos;

	CCPoint destPos = dPos;
	if (!item->getParent())
	{
		this->addChild(item);
	}
	CCMoveTo *moveAction = CCMoveTo::create(1.5f,destPos);
	CCScaleBy *scaleTo = CCScaleBy::create(0.75f,1.3f);
	CCFiniteTimeAction * seq = CCSequence::create(scaleTo,scaleTo->reverse(),NULL);
	item->runAction(CCSpawn::create(moveAction,seq,NULL));
	return true;
}

/**
* ɾ����Ŀ
*/
bool UISuperBag::removeItem(UIItem *item)
{
	if (!item) return false;
	if (item->bagId < _items.size())
	{
		_items[item->bagId] = NULL;
		return true;
	}
	return false;
}
/**
* �ƶ���Ŀ
*/
bool UISuperBag::moveItem(UIItem *item,int destId)
{
	if (!item) return false;
	UIItem *srcItem = item;
	CCPoint destPos = getPixelPosition(destId);
	CCPoint srcPos =  getPixelPosition(item->bagId);
	int did = destId;
	UIItem *destItem = NULL;
	if (did < _items.size())
	{
		destItem = _items[did];
	}
	if (!destItem && did < _items.size() && srcItem->canMove(did))
	{
		_items[did] = srcItem;
		_items[srcItem->bagId] = NULL;
		srcItem->bagId = did;
	}
	else if (destItem && did < _items.size())
	{
		return false;
		// ����
		if (destItem && srcItem && destItem->canMove(srcItem->bagId) && srcItem->canMove(destItem->bagId))
		{
			_items[did] = srcItem;
			_items[srcItem->bagId] = destItem;
			destItem->bagId = srcItem->bagId;
			srcItem->bagId = did;
		}
	}

	setBagDynamicPos(srcItem,srcPos,destPos);
	setBagDynamicPos(destItem,destPos,srcPos);
	return true;
}
/** 
 * ����Ƿ���������
 */
bool UISuperBag::touchDown(float x,float y)
{
	if (!this->isVisible()) return false;
	CCPoint pos = ccp(x,y);
	pos = this->convertToNodeSpace(pos);
	_touchIn = false;
	_nowTouchItemId = -1;
	nowTouchPoint = ccp(x,y);
	if (checkIn(pos.x,pos.y))
	{
		if (!_editable)
		{
			_nowTouchItemId =getNowTouchBagIdByCursorPosition(nowTouchPoint);
			if (_nowTouchItemId < _items.size())
			{
				UIItem * item = _items.at(_nowTouchItemId);
				if (!item || !item->canMove(_nowTouchItemId))
				{
					_nowTouchItemId = -1;
					return false;
				}
				if (item)
				{
					item->setZOrder(2);
					item->doTouch(UIBase::TOUCH_DOWN,ccp(x,y));
				}
			}
		}
		_touchIn = true;
		return true;
	}
	return false;
}


/**
 * ����λ��
 */
bool UISuperBag::touchMove(float x,float y)
{
	if (!this->isVisible()) return false;
	if (!_touchIn) return false;
	CCPoint pos = ccp(x,y);
	if (_editable)
	{
		CCPoint nowPoint = getPosition();
        setPosition(nowPoint.x + pos.x - nowTouchPoint.x,
                                      nowPoint.y + pos.y - nowTouchPoint.y);
		nowTouchPoint = pos;
	}
	else
	{
		if (_nowTouchItemId != -1)
		{
			// �ƶ���ǰѡ��İ�������
			if (_nowTouchItemId < _items.size())
			{
				UIItem * item = _items.at(_nowTouchItemId);
				if (item)
				{
					CCPoint nowPoint = item->getPosition();
					item->setPosition(nowPoint.x + pos.x - nowTouchPoint.x,
                                      nowPoint.y + pos.y - nowTouchPoint.y);
				}
			}
		}
	}
	nowTouchPoint = pos;
	return true;
}
UIItem * UISuperBag::getNowChoiceItem()
{
	UIItem *srcItem = NULL;
	if (oldTouchItemId < _items.size() && oldTouchItemId >= 0)
	{
		srcItem = _items.at(oldTouchItemId);
		return srcItem;
	}
	
	return NULL;
}
/**
 * ֹͣ�϶�
 */
bool UISuperBag::touchEnd(float x,float y)
{
	if (!this->isVisible()) return false;
	CCPoint pos = ccp(x,y);
	pos = this->convertToNodeSpace(pos);
	UIItem *srcItem = NULL;
	if (_nowTouchItemId < _items.size() && _nowTouchItemId >= 0)
	{
		srcItem = _items.at(_nowTouchItemId);
		oldTouchItemId = _nowTouchItemId;
	}
	if (!srcItem){
		_nowTouchItemId = -1;
		_touchIn = false;
		return false;
	}
	if (srcItem)
	{
		srcItem->setZOrder(0);
		srcItem->doTouch(UIBase::TOUCH_END,ccp(x,y));
	}
	UIItem *destItem = NULL;
	if (!_editable)
	{
		nowTouchPoint = ccp(x,y);
		if (checkIn(pos.x,pos.y))
		{
			if (!_editable)
			{
				int nowTouchId = getNowTouchBagIdByCursorPosition(ccp(x,y));
				if (nowTouchId >= _items.size())
				{
					//_items.resize(_bagWidth * _bagHeight);	
				}
				else
				{
					
					
					if (nowTouchId < _items.size() && nowTouchId >= 0)
					{
						destItem = _items.at(nowTouchId);
					}
					
					if (!destItem && nowTouchId < _items.size() && srcItem->canMove(nowTouchId))
					{
						_items[nowTouchId] = srcItem;
						_items[_nowTouchItemId] = NULL;
						srcItem->bagId = nowTouchId;
					}
					else if (destItem && nowTouchId < _items.size())
					{
						// ����
						if (destItem && srcItem && srcItem->canMove(destItem->bagId))
						{
							_items[nowTouchId] = srcItem;
							_items[_nowTouchItemId] = destItem;
							destItem->bagId = _nowTouchItemId;
							srcItem->bagId = nowTouchId;
						}
					}
					else if (!destItem && (nowTouchId < 0 || nowTouchId >= _items.size()))
					{
						this->doEvent(UIBase::EVENT_DRAG_OUT,this); // �ϳ�����
					}
					
				}
			}
			
			//return true;
		}
		else
				this->doEvent(UIBase::EVENT_DRAG_OUT,this); // �ϳ�����
	}
	
	show();
	if (srcItem == destItem)
	{
		this->doEvent(UIBase::EVENT_CLICK_DOWN,this);
	}
	_nowTouchItemId = -1;
	_touchIn = false;
	return true;
}
	
/**
* ����λ��
*/
void UISuperBag::setPosition(float x,float y)
{
	CCNode::setPosition(ccp(x,y));
	this->x = x;
	this->y = y;
}
	
/**
* ���ô�С
*/
void UISuperBag::setSize(float w,float h)
{
	this->w = w;
	this->h = h;
}
/**
 * ��������
 */
UISuperBag *UISuperBag::create(int viewx,int viewy, int eachWidth,int eachHeight)
{
	UISuperBag *bag = new UISuperBag();
	bag->_viewx= viewx;
	bag->_viewy = viewy;

	bag->_eachWidth = eachWidth;
	bag->_eachHeight = eachHeight;

    if (bag)
    {
        bag->autorelease();
        return bag;
    }
    CC_SAFE_DELETE(bag);
    return NULL;
}

void UISuperBag::showItem(UIItem *item,bool dynamic)
{
	if (!item) return;
	int bagId = item->bagId;
	if (bagId < 0) return;
	CCPoint pos = getPixelPosition(bagId);
	if (dynamic)
	{
		setBagDynamicPos(item,ccp(pos.x,0),pos);
	}
	else
	{
		item->setPosition(pos.x,pos.y);
	}
}

void UISuperBag::clear()
{
	_items.clear();
	this->removeAllChildrenWithCleanup(true);
}
/**
* ��������Ƿ���������
*/
bool UISuperBag::checkIn(int x,int y)
{
	CCPoint pos = ccp(x,y);
	if ( pos.x >= _viewx && pos.y >= _viewy && pos.x <= _viewx * _items.size() * _eachWidth && pos.y <=  _eachHeight)
		return true;
	return false;
}

int UISuperBag::getNowTouchBagIdByCursorPosition(const CCPoint& point)
{
	CCPoint pos = this->convertToNodeSpace(point);
	if (checkIn(pos.x,pos.y))
	{
		int dx = (pos.x - _viewx) / (_eachWidth);

		return dx;
	}
	return -1;
}
/**
 * ��ȡ��ǰid ������λ��
 */
CCPoint UISuperBag::getPixelPosition(int id)
{
	return ccp(_viewx + id * _eachWidth,_viewy);
}

/**
 * ��������
 */
UICircleBag *UICircleBag::create(int viewx,int viewy,int eachWidth,int eachHeight,int minRadius,int maxRadius,int itemCount)
{
	UICircleBag *bag = new UICircleBag();
	bag->_viewx= viewx;
	bag->_viewy = viewy;

	bag->_eachWidth = eachWidth;
	bag->_eachHeight = eachHeight;

    if (bag && bag->init(minRadius,maxRadius,itemCount))
    {
        bag->autorelease();
        return bag;
    }
    CC_SAFE_DELETE(bag);
    return NULL;
}
bool UICircleBag::init(int minRadius,int maxRadius,int itemCount)
{
	float dangle = 2 * 3.1415926 / itemCount;
	for (int i = 0; i < itemCount; i ++)
	{
		float nowAngle = i * dangle;
		CCPoint nowPoint = ccp( _viewx + maxRadius * cos(nowAngle),_viewy + maxRadius * sin(nowAngle));
		positions.push_back(nowPoint);
	}
	minRadius = minRadius;
	return true;
}
/**
 * ��ȡ��ǰid ������λ��
 */
CCPoint UICircleBag::getPixelPosition(int id)
{
	if (id < - 1 && id >= positions.size()) return ccp(-1,-1);
	return positions.at(id);
}
int UICircleBag::getNowTouchBagIdByCursorPosition(const CCPoint& point)
{
	CCPoint pos = this->convertToNodeSpace(point);
	// ����Ƿ���6��������
	if (checkIn(pos.x,pos.y))
	{	
		for ( int i = 0; i < positions.size();i++)
		{
			CCRect rect = CCRectMake(positions[i].x,positions[i].y,_eachWidth,_eachHeight);
			if (rect.containsPoint(pos))
			{
				return i;
			}
		}
	}
	return -1;
}
/**
* ��������Ƿ��������� ����������
*/
bool UICircleBag::checkIn(int x,int y)
{
	CCPoint pos = ccp(x,y);
	for ( int i = 0; i < positions.size();i++)
	{
		CCRect rect = CCRectMake(positions[i].x,positions[i].y,_eachWidth,_eachHeight);
		if (rect.containsPoint(pos))
		{
			return true;
		}
	}
	float distance = ccpDistance(pos,ccp(_viewx,_viewy));
	if (distance < minRadius)
	{
		return true;
	}
	return false;
}
NS_CC_END