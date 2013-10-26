#include "UIChoiceList.h"
NS_CC_BEGIN

UIChoiceList* UIChoiceList::create(const CCRect & viewRect,int eachWidth,int eachHeight)
{
	UIChoiceList *bag = new UIChoiceList();
	bag->_viewx= viewRect.origin.x;
	bag->_viewy = viewRect.origin.y;
	bag->_viewWidth = viewRect.size.width;
	bag->_viewHeight = viewRect.size.height;
	bag->_eachItemWidth = eachWidth;
	bag->_eachItemHeight = eachHeight;
    if (bag)
    {
        bag->autorelease();
        return bag;
    }
    CC_SAFE_DELETE(bag);
    return NULL;
}
/**
 * ����ʹÿ�����嶯̬��չʾ����
 */
void UIChoiceList::showEachDynamic()
{
	if (_items.size() && !_nowChoiceItem)
	{
		_nowChoiceItem = _items.at(0);
		_nowChoiceItem = _nowChoiceItem->clone();
		this->addChild(_nowChoiceItem);
	}
	/**
	 * չʾ�Լ���choiceλ��
	 */
	_nowChoiceItem->setPosition(_viewx,_viewy + _viewHeight);
	UIList::showEachDynamic();
}
void UIChoiceList::showEach()
{
	if (_items.size() && !_nowChoiceItem)
	{
		_nowChoiceItem = _items.at(0);
		_nowChoiceItem = _nowChoiceItem->clone();
		this->addChild(_nowChoiceItem);
	}
	/**
	 * չʾ�Լ���choiceλ��
	 */
	_nowChoiceItem->setPosition(_viewx,_viewy + _viewHeight);
	UIList::showEach();
}
/**
 * ������Ŀѡ��
 **/
void UIChoiceList::doItemDown(UIItem *item)
{
	if (!item) return;

	if (_nowChoiceItem)
	{
		_nowChoiceItem->bagId = item->bagId;
		_nowChoiceItem->setPosition(_viewx,_viewy + _viewHeight);
	}
	this->doEvent(UIBase::EVENT_CLICK_DOWN,this);
	this->hideEach();
	showTag = false;
}
UIItem * UIChoiceList::getItemByBagId(int bagId)
{
	if (bagId >= 0 && bagId < _items.size())
	{
		return _items.at(bagId);
	}
	return NULL;
}
 /** 
 * ����Ƿ���������
 */
bool UIChoiceList::touchDown(float x,float y)
{
	CCPoint pos = ccp(x,y);
	nowTouchPoint = ccp(x,y);
	pos = this->convertToNodeSpace(pos);
	if (_nowChoiceItem && _nowChoiceItem->checkIn(pos.x,pos.y))
	{
		_touchIn = true;
		return true;
	}
	if (!showTag) return false;
	return UIList::touchDown(x,y);
}
/**
 * ����λ��
 */
bool UIChoiceList::touchMove(float x,float y)
{
	CCPoint pos = ccp(x,y);
	if (_touchIn && _editable)
	{
		CCPoint nowPoint =getPosition();
        setPosition(nowPoint.x + pos.x - nowTouchPoint.x,
                                      nowPoint.y + pos.y - nowTouchPoint.y);
		nowTouchPoint = pos;
		return true;
	}
	if (!showTag) return false;
	return UIList::touchMove(x,y);
}
/**
 * ֹͣ�϶�
 */
bool UIChoiceList::touchEnd(float x,float y)
{
	if (_editable && _touchIn)
	{
		this->doEvent(UIBase::EVENT_EDIT_DOWN,this);
	}
	_touchIn = false;
	CCPoint pos = ccp(x,y);
	pos = this->convertToNodeSpace(pos);
	if (_nowChoiceItem && _nowChoiceItem->checkIn(pos.x,pos.y))
	{
		if (showTag)
			UIList::hideEach();
		else
			UIList::showEachDynamic();
		showTag  = !showTag;
		return true;
	}
	if (!showTag) return false;
	return UIList::touchEnd(x,y);
}
/**
 * ���õ�ǰ��ѡ���id
 */
void UIChoiceList::setChoiceId(int id)
{
	if (_nowChoiceItem)
	{
		_nowChoiceItem->bagId = id;
		_nowChoiceItem->setPosition(_viewx,_viewy + _viewHeight);
	}
	this->doEvent(UIBase::EVENT_CLICK_DOWN,this);
	this->hideEach();
	showTag = false;
}
/**
* ����λ��
*/
void UIChoiceList::setPosition(float x,float y)
{
	CCNode::setPosition(x,y);
}
	
/**
* ���ô�С
*/
void UIChoiceList::setSize(float w,float h)
{
	this->setScaleX(w / this->getContentSize().width);
	this->setScaleY(h / this->getContentSize().height);
}

void UIChoiceList::setEditable(bool tag)
{
	 _editable = tag;
}
NS_CC_END