#include "UIBase.h"
#include "UIButton.h"
#include "UILabel.h"
#include "UIEditField.h"
#include "UIPanel.h"
#include "UIWindow.h"
NS_CC_BEGIN
//! convert from wstring to UTF8 using self-coding-converting
inline void WStrToUTF8(std::string& dest, const std::wstring& src){
	dest.clear();
	for (size_t i = 0; i < src.size(); i++){
		wchar_t w = src[i];
		if (w <= 0x7f)
			dest.push_back((char)w);
		else if (w <= 0x7ff){
			dest.push_back(0xc0 | ((w >> 6)& 0x1f));
			dest.push_back(0x80| (w & 0x3f));
		}
		else if (w <= 0xffff){
			dest.push_back(0xe0 | ((w >> 12)& 0x0f));
			dest.push_back(0x80| ((w >> 6) & 0x3f));
			dest.push_back(0x80| (w & 0x3f));
		}
		else if (sizeof(wchar_t) > 2 && w <= 0x10ffff){
			dest.push_back(0xf0 | ((w >> 18)& 0x07)); // wchar_t 4-bytes situation
			dest.push_back(0x80| ((w >> 12) & 0x3f));
			dest.push_back(0x80| ((w >> 6) & 0x3f));
			dest.push_back(0x80| (w & 0x3f));
		}
		else
			dest.push_back('?');
	}
}
UIPanel * UIBase::getPanel()
{
	UIPanel * panel = static_cast<UIPanel*>(this->getParent());
	return panel;
}
/**
* ����һ��������ui ���ڳ־û�
*/
UIBase * UIBase::create(int kind)
{
	switch(kind)
	{
	case UIBase::UI_IMAGE_BUTTON: return UIButton::create();
	case UIBase::UI_LABEL:return UILabel::create();
	case UIBase::UI_TEXT_FIELD: return UIEditField::create();
	}
	return NULL;
}
/**
* ���¼��������
*/
bool UIBase::bind(int eventid,const FunctionInfo& function)
{
	if (eventid >= event_functions.size())
		event_functions.resize(eventid + 1);
	event_functions[eventid] = function;
	return true;
}

bool UIBase::bind(int uiEvnet,UICallback *callback)
{
	if (uiEvnet >= event_functions.size())
		event_callbacks.resize(uiEvnet + 1);
	if (event_callbacks[uiEvnet]) return false;
	event_callbacks[uiEvnet] = callback;
	return true;
}

bool UIBase::bind(int uiEvent,const char *luaFunctionName)
{
	/*if (uiEvent >= event_lua_functions.size())
		event_lua_functions.resize(uiEvent + 1);
	if (event_lua_functions[uiEvent]) return false;
	event_lua_functions[uiEvent] = luaFunctionName;*/
	return true;
}
void UIBase::doEvent(int uiEvent,UIBase *base)
{
	if (uiEvent < event_functions.size())
	{
		FunctionInfo& func = event_functions.at(uiEvent);
		if (func.handle)
		{
			UIBase *o = func.object;
			if (o)
			(o->*func.handle)(base);
		}
	}
	else if (uiEvent < event_callbacks.size())
	{
		UICallback *callback = (UICallback*) event_callbacks.at(uiEvent);
		if (callback)
		{
			callback->callback(base);
		}
	}
	//else if (uiEvent < luaFunctionName.size())
	{
		// ִ��lua �ű��Ļص�
		//theLua.execString(luaFunctionName,this);
	}
}
UIWindow *UIBase::getDepthWindow()
{
	CCNode * temp = this;
	UIWindow * window = dynamic_cast<UIWindow*>(temp);
	while (!window)
	{
		temp = temp->getParent();
		window = dynamic_cast<UIWindow*>(temp);
	}
	return window;
}
/**
* ���� �ɼ�
*/
void UIBase::setVisible(bool tag)
{
	CCNode::setVisible(tag);
}

std::string UIBase::toUTF8(const std::wstring& str)
{
	std::string result;
	WStrToUTF8(result, str);
	return result;
}
/**
 * �������ڵ��µ��ӽڵ�
 */
TiXmlElement * UIBase::makeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement *baseNode=new TiXmlElement(name.c_str());
	if (parent)
		parent->LinkEndChild(baseNode);
	//�������
	baseNode->SetAttribute("x",x);
	baseNode->SetAttribute("w",w);
	baseNode->SetAttribute("y",y);
	baseNode->SetAttribute("h",h);
	baseNode->SetAttribute("uniqueid",uniqueId);
	baseNode->SetAttribute("name",name);
	baseNode->SetAttribute("uniquename",uniqueName);
	baseNode->SetAttribute("oncreate",this->onCreateCodeName);
	baseNode->SetAttribute("onclick",this->onClickCodeName);
	return baseNode;
}
/**
 * ������
 * \parma touchType �������
 * \param touchPoint �����
 */
bool UIBase::doTouch(int touchType,const CCPoint &touchPoint)
{
	switch(touchType)
	{
		case TOUCH_DOWN :return this->touchDown(touchPoint.x,touchPoint.y);
		case TOUCH_MOVE :return this->touchMove(touchPoint.x,touchPoint.y);
		case TOUCH_END  :return this->touchEnd(touchPoint.x,touchPoint.y);
	}
	return false;
}
NS_CC_END