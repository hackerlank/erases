#include "UIWindow.h"

NS_CC_BEGIN
FunctionInfo exitFunction; // �˳�����
UIWindow * UIWindow::create()
{
	UIWindow *pRet = new UIWindow();
    if (pRet)
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
void UIWindow::setCursor(CCSprite *cursor)
{
	if (_cursor)
	{
		this->removeChild(_cursor,true);
	}
	_cursor = cursor;
	if (cursor)
		this->addChild(cursor);
}
/**
 * ����һ������
 */
void UIWindow::addPanel(UIPanel *panel)
{
	if (!panel) return;
	_panels.push_back(panel);
	this->addChild(panel);
}
UIPanel *UIWindow::getPanel(const std::string &name)
{
	PANELS temps = _panels;
	for (PANELS_ITER iter = temps.begin(); iter != temps.end(); ++iter)
	{
		UIPanel * panel = *iter;
		if (panel && panel->name == name)
			return panel;
	}
	for (BASES_ITER iter = _bases.begin() ; iter != _bases.end();++iter)
	{
		UIBase *base =*iter;
		if (base && base->uiType == UIBase::UI_PANEL)
		{
			UIPanel *pan = (UIPanel*) base;
			if (pan && pan->name == name)
				return pan;
		}
	}
	return NULL;
}
/**
 * ����ui
 */
void UIWindow::addUI(UIBase *base)
{
	for (BASES_ITER iter = _bases.begin() ; iter != _bases.end();++iter)
	{
		if (base == *iter)
		{
			return;
		}
	}
	insertBase(base);
	this->addChild(base);
}
void UIWindow::setNowTouchPanel(UIPanel * pan)
{
	_nowTouchPanel = pan;
	PANELS temps = _panels;
	for (PANELS_ITER iter = temps.begin(); iter != temps.end(); ++iter)
	{
		UIPanel * panel = *iter;
		if (panel && !panel->isMovable())
		{
			panel->setZOrder(0);
		}
	}
	for (BASES_ITER iter = _bases.begin() ; iter != _bases.end();++iter)
	{
		UIBase *base =*iter;
		if (base && base->isMovable())
		{
			base->setZOrder(0);
		}
	}
	if (pan->isMovable())
		pan->setZOrder(1);
}
/** 
 * ����Ƿ���������
 */
bool UIWindow::touchDown(float x,float y)
{
	nowCursorPoint = ccp(x,y);
	
	if (_models.size())
	{
		_nowModel = _models.back();
		_nowModel->touchDown(x,y);
		return true;
	}
	_nowTouchUI = NULL;
	for (BASES_ITER iter = _bases.begin() ; iter != _bases.end();++iter)
	{
		UIBase *base = *iter;
		if (base && base->touchDown(x,y))
		{
			_nowTouchUI = base;
			return true;
		}
	}
//	_nowTouchPanel = NULL;
	PANELS temps = _panels;
	for (PANELS_ITER iter = temps.begin(); iter != temps.end(); ++iter)
	{
		UIPanel * panel = *iter;
		if (panel && panel->touchDown(x,y))
		{
			setNowTouchPanel(panel);
			return true;
		}
	}
	
	return false;
}
void UIWindow::release()
{
	
}

void UIWindow::setEndFunction(const FunctionInfo &function)
{
	function.object->retain();
	exitFunction = function;
	endFlag = true;
}
/**
 * ��panel ����Ϊģ̬
 */
void UIWindow::pushModel(UIPanel *panel)
{
	for (std::vector<UIPanel*>::iterator iter = _models.begin(); iter != _models.end();++iter)
	{
		if (*iter == panel)
		{
			return;
		}
	}
	_models.push_back(panel);
	panel->setZOrder(_models.size() + 100);
	panel->beginModel();
}
/**
 * ������ǰģ̬��
 */
void UIWindow::popModel()
{
	if (_models.size())
	{
		_models.back()->endModel();
		_models.pop_back();
	}
}
/**
 * ����λ��
 */
bool UIWindow::touchMove(float x,float y)
{
	nowCursorPoint = ccp(x,y);
	if (_cursor)
	{
		_cursor->setPosition(ccp(x,y));
	}
	
	if (_nowModel)
	{
		_nowModel->touchMove(x,y);
		return true;
	}
	if (_nowTouchPanel && _nowTouchPanel->touchMove(x,y))
		return true;
	
	if (_nowTouchUI)
	{
		if (_nowTouchUI->touchMove(x,y))
		{
			return true;
		}
	}
	PANELS temps = _panels;
	for (PANELS_ITER iter = temps.begin(); iter != temps.end(); ++iter)
	{
		UIPanel * panel = *iter;
		if (panel && panel->touchMove(x,y))
		{
			return true;
		}
	}
	return false;
}
/**
 * ֹͣ�϶�
 */
bool UIWindow::touchEnd(float x,float y)
{
	nowCursorPoint = ccp(x,y);
	bool tag = false;
	
	if (_nowModel)
	{
		_nowModel->touchEnd(x,y);
		_nowModel = NULL;
		return false;
	}
	//if (_nowTouchPanel)_nowTouchPanel->setZOrder(100);
	_nowTouchUI = NULL;
	BASES tbases = _bases;
	for (BASES_ITER iter = tbases.begin() ; iter != tbases.end();++iter)
	{
		UIBase *base = *iter;
		if (base && base->touchEnd(x,y))
		{
			tag = true;
		}
	}
//	_nowTouchPanel = NULL;
	PANELS temps = _panels;
	for (PANELS_ITER iter = temps.begin(); iter != temps.end(); ++iter)
	{
		UIPanel * panel = *iter;
		if (panel && panel->touchEnd(x,y))
		{
			tag = true;
		}
	}
	return tag;
}

CCPoint UIWindow::getCursorPoint()
{
	return nowCursorPoint;
}
/**
 * ɾ����ǰ�Panel
 */
void UIWindow::removeNowPanel()
{
	if (_nowTouchPanel)
	{
		PANELS temps = _panels;
		for (PANELS_ITER iter = temps.begin(); iter != temps.end(); ++iter)
		{
			if (_nowTouchPanel == *iter)
			{
				temps.erase(iter);
				break;
			}
		}
		this->removeChild(_nowTouchPanel,true);
	}
}

void  UIWindow::insertBase(UIBase *base)
{
	for (BASES_ITER iter = _bases.begin() ; iter != _bases.end();++iter)
	{
		UIBase *src = *iter;
		if (src && src->eventPriority <= base->eventPriority)
		{
			_bases.insert(iter,base);
			return;
		}
	}
	_bases.push_back(base);
}
void UIWindow::showErr(const std::string& info)
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	if (!_errLbl)
	{
		_errLbl = CCLabelTTF::create(info.c_str(),"Arial",64);
		this->addChild(_errLbl,102);
	}
	if (_errLbl)
	{
		_errLbl->setPosition(ccp(visibleSize.width / 2,visibleSize.height / 2));
		_errLbl->runAction(CCMoveBy::create(1.5f,ccp(0,125)));
		_errLbl->runAction(CCFadeOut::create(1.5));
		_errLbl->setColor(ccc3(255,0,0));
	}
}
UIPanel *UIWindow::showPanel(const std::string &name)
{
	UIPanel * bp = this->getPanel(name);
	if (!bp)
	{
		std::stringstream namestr;
		if (name.find("xml") != std::string::npos)
			namestr << name;
		if (name.find("dialog") != std::string::npos)
			namestr << name;
		else
			namestr << name << ".xml";
		CommonPanel *panel = CommonPanel::create(this,namestr.str().c_str());
		panel->name = name;
		return panel;
	}
	else return bp;
}
NS_CC_END