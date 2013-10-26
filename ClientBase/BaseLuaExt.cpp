#include "BaseLuaExt.h"
#include "MutiMap.h"
#include "UIWindow.h"
#include "UIBase.h"
#include "UIPanel.h"
#include "LuaCocos2d.h"
#include "UIItem.h"
#include "UISuperBag.h"
extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "tolua++.h"
	#include "tolua_fix.h"
}
#include "lua_tinker.h"
NS_CC_BEGIN

BaseLuaExt* BaseLuaExt::create()
{
	BaseLuaExt * baseLuaExt = new BaseLuaExt();
	if (baseLuaExt)
	{
		baseLuaExt->init();
	}
	return baseLuaExt;
}
void BaseLuaExt::init()
{
	m_state = lua_open();
    luaL_openlibs(m_state);
    tolua_Cocos2d_open(m_state);
	_map = map;
	_monster = monster;
	_mainUI = mainUI;
	initLuaExt();
	 toluafix_open(m_state);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    addLuaLoader(loader_Android);
#endif
    return;
}
/**
 * lua��������չ
 * function function_net(object)
 *		// ��¼�ɹ�
 *		
 * end
 * function doInitMainUI(base) // �ص�����1 
 *      mainUI:bind(1,doLoginIn);
 *      mainUI:bindnetcallbck(1,function_net);
 * end
 * function doLoginIn()
 *		theNet:send(1,"ssss:xxx");
 * end
 * mainUI = createUIMain("xxx.xml"); // xml�ļ�����ʹ�ñ༭������
 */
void BaseLuaExt::initLuaExt()
{
	lua_tinker::class_add<MutiMap>(m_state, "MutiMap");
	lua_tinker::class_def<MutiMap>(m_state, "create", &MutiMap::create); // ����

	lua_tinker::class_add<UIMain>(m_state, "UIMain");
	lua_tinker::class_def<UIMain>(m_state, "create", &UIMain::create); // ����������ϵͳ

	lua_tinker::class_add<UIBase>(m_state, "UIBase");
	lua_tinker::class_mem<UIBase>(m_state, "x", &UIBase::x);
	lua_tinker::class_mem<UIBase>(m_state, "y", &UIBase::y);
	lua_tinker::class_def<UIBase>(m_state, "setVisible", &UIBase::setVisible); // �����Ƿ�ɼ�
	lua_tinker::class_def<UIBase>(m_state, "bind", &UIBase::bindLua); // ��lua�ű�

	lua_tinker::class_add<UIPanel>(m_state, "UIPanel");
	lua_tinker::class_inh<UIPanel, UIBase>(m_state); // �̳�UIbase 
	lua_tinker::class_def<UIPanel>(m_state, "getUILablevalue", &UIPanel::getUILablevalue); // ��ȡ��ǩ�ֶ�ֵ
	lua_tinker::class_def<UIPanel>(m_state, "hide", &UIPanel::hide); // ����
	lua_tinker::class_def<UIPanel>(m_state, "getEditFieldValue", &UIPanel::getEditFieldValue); // ��ȡ������ֶ�ֵ
	lua_tinker::class_def<UIPanel>(m_state, "getUIByName", &UIPanel::getUIByName); // ��ȡ�ؼ�
	
	// StoreBag 
	// ������
	// iter = list:getIterator();
	// iter:getNext();
	//
	lua_tinker::class_add<UIBagIterator>(m_state, "UIBagIterator");
	lua_tinker::class_def<UIBagIterator>(m_state, "getNext", &UIBagIterator::getNext); // ��ȡ��һ����Ŀ
	
	lua_tinker::class_add<CommonUIItem>(m_state, "CommonUIItem"); // ��Ŀ
	lua_tinker::class_def<CommonUIItem>(m_state, "getPanel", &CommonUIItem::getPanel); // ��ȡ��ȡPanel
	lua_tinker::class_def<CommonUIItem>(m_state, "create", &CommonUIItem::create); // ����

	lua_tinker::class_add<UISuperBag>(m_state, "UISuperBag");
	lua_tinker::class_def<UISuperBag>(m_state, "getIterator", &UISuperBag::getIterator); // ��ȡ������
	lua_tinker::class_def<UISuperBag>(m_state, "show", &UISuperBag::show); // չʾ�Լ�

	/**
	 * ����Window
	 */
	lua_tinker::class_add<UIWindow>(m_state,"UIWindow");
	lua_tinker::class_inh<UIWindow, UIBase>(m_state); // �̳�UIbase 
	lua_tinker::class_def<UIWindow>(m_state, "showPanel", &UIWindow::showPanel); // չʾPanel
	lua_tinker::class_def<UIWindow>(m_state, "getPanel", &UIWindow::getPanel); // ��ȡPanel

	/**
	 * panel:bindnetcallbck(1,function); // �����紦����
	 * panel:bindbtnclick("",function); // �󶨰�ť����¼�
	 * net:send(1,""); // ������Ϣ
	 */
	lua_tinker::set(m_state, "theNet", &theNet); // ȫ�ֶ��� ����ģ��
}

void BaseLuaExt::doString(const char*cmd)
{
	 this->executeString(cmd);
	 return;
}

NS_CC_END