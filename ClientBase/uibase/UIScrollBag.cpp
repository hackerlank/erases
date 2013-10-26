#include "UIScrollBag.h"
NS_CC_BEGIN

/**
* ��������
*/
UIScrollBag *UIScrollBag::create(int bagWidth,int bagHeight,int eachWidth,int eachHeight,int eachLeftSpan,int eachUpSpan)
{
	UIScrollBag *sbag = new UIScrollBag();
    if (sbag && sbag->init(bagWidth,bagHeight,eachWidth,eachHeight,eachLeftSpan,eachUpSpan))
    {
        sbag->autorelease();
        return sbag;
    }
    CC_SAFE_DELETE(sbag);
    return NULL;
}
bool UIScrollBag::init(int bagWidth,int bagHeight,int eachWidth,int eachHeight,int eachLeftSpan,int eachUpSpan)
{
	setSize((bagWidth) * (eachWidth + eachLeftSpan),bagHeight * (eachHeight + eachUpSpan));
	setPosition(0,0);
	bag = UIUpBag::create(0,0,bagWidth,bagHeight,eachWidth,eachHeight,eachLeftSpan,eachUpSpan);
	this->addContent(bag);
	bag->setExchange(false);
	this->setEditable(false);
	this->showEach();
	return true;
}
bool UIScrollBag::bind(int uiEvent,const FunctionInfo& function)
{
	if (bag) return bag->bind(uiEvent,function);
	return false;
}
/**
 * ������Ŀ
 */
bool UIScrollBag::addItem(UIItem *item)
{
	if (!item) return false;
	if (bag)
	{
		bag->addItem(item);
		return true;
	}
	return false;
}
/**
* չʾ
*/
void UIScrollBag::showEach()
{
	if (bag) bag->show();
}

/**
* ����
*/
void UIScrollBag::hideEach()
{
	
}

/** 
* ����Ƿ���������
*/
bool UIScrollBag::touchDown(float x,float y)
{
	if (UIScrollView::touchDown(x,y)) return true;
	return false;
}
/**
* ����λ��
*/
bool UIScrollBag::touchMove(float x,float y)
{
	if (UIScrollView::touchMove(x,y)) return true;
	return false;
}
/**
* ֹͣ�϶�
*/
bool UIScrollBag::touchEnd(float x,float y)
{
	UIScrollView::touchEnd(x,y);
	return true;
}

/**
 * ���û����λ��
 */
void UIScrollBag::updateSlider()
{
	if (slider && slider->getParent())
	{
		
	}
}

UIItem * UIScrollBag::getNowChoiceItem()
{
	if (bag) return bag->getNowChoiceItem();
	return NULL;
}
NS_CC_END