#pragma once
/**
 * ����AI
 */

#include "scriptLib.h"
#include "cocos2d.h"
NS_CC_BEGIN
class UIWindow;
class UIPanel;
class UIBase;
class UIStub;
class UILib;
class UICallback;
typedef int (UILib::*UIAction)(UIStub *,script::tixmlCodeNode *);

//ִ�е�
class UILibAction{
public:
	int type;
	UIAction action;
};

/**
 * ai ��ִ����
 * */
class UIStub{
public:
	UIBase *base;
	UIWindow *window;
	UIStub()
	{
		base = NULL;
		window = NULL;
	}
	UIStub(UIBase *base,UIWindow *window):base(base),window(window)
	{}
};
/**
 * ִ�п�
 * ���ش���� �� �¼���
 **/
class UILib:public script::Lib<UILibAction,UIStub,UILib>
{
public:
	static UILib & getMe()
	{
		static UILib lib;
		return lib;
	}
	void initWithFile(const char *fileName);
    /**
     * ֻ����scope="stub" ��ʱ�� type ����Ч
     */
    int var(UIStub* stub,script::tixmlCodeNode * node)
    {
        return script::Lib<UILibAction,UIStub,UILib>::var(stub,node);
    }
    /**
     * ���
     */
    int print(UIStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<UILibAction,UIStub,UILib>::print(stub,node);
    }
    /**
     * �������
     **/
    int calc(UIStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<UILibAction,UIStub,UILib>::calc(stub,node);
    }
    /**
     * ִ�������ڵ�
     **/
    int exec(UIStub* stub,script::tixmlCodeNode * node)
    {
        execCode(stub,node->getAttr("name"));
        return 0;
    }
    void bindActions();
    void takeNode(script::tixmlCodeNode *node);
    /**
     * �����Դ
     * */
    void destroy();

/////////////////////////////////////////////////////////////////////////    
//			�����չ
////////////////////////////////////////////////////////////////////////
    /**
	 * չʾ�Լ�
	 */
	int showme(UIStub* stub,script::tixmlCodeNode * node);
	/**
	 * �����Լ� 
	 **/
	int hideme(UIStub* stub,script::tixmlCodeNode * node);

	int hideparentpanel(UIStub* stub,script::tixmlCodeNode * node);
	/**
	 * �ı��Լ�λ��
	 **/
	int setposition(UIStub *stub,script::tixmlCodeNode * node);
	/**
	 * չʾpanel 
	 */
	int showpanel(UIStub* stub,script::tixmlCodeNode * node);
	/**
	 * ����Panel
	 */
	int hidepanel(UIStub* stub,script::tixmlCodeNode * node);
	/**
	 * ���������߼�
	 **/
	int bind(UIStub* stub,script::tixmlCodeNode * node);
	/**
	 * ������panel �Ĵ����߼� 
	 */
	int panelbind(UIStub* stub,script::tixmlCodeNode * node);

	/**
	 * ����panel ��UILabel ��ֵ
	 */
	int panel_label_set_value(UIStub* stub,script::tixmlCodeNode * node);
	
	/**
	 * ���ø���
	 */
	int parent_p_label_set_value(UIStub* stub,script::tixmlCodeNode * node);

	/**
	 * ���ø����bind
	 */
	int parent_p_bind(UIStub* stub,script::tixmlCodeNode * node);
	
	/**
	 * չʾ�����ļ�
	 */
	int files_show(UIStub* stub,script::tixmlCodeNode * node);

	/**
	 * ����ѡ���
	 */
	int panel_p_choice(UIStub *stub,script::tixmlCodeNode * node);
};

#define theUILib UILib::getMe()


class UICallbackManager{
public:
	UICallback * getCallback(const std::string &name)
	{
		CALLBACKS_ITER iter = callbacks.find(name);
		if (iter != callbacks.end())
		{
			return iter->second;
		}
		return NULL;
	}
	void addCallback(const std::string &name,UICallback* callback)
	{
		if (getCallback(name)) return;
		callbacks[name] = callback;
	}
	std::map<std::string,UICallback *> callbacks;
	typedef std::map<std::string,UICallback *>::iterator CALLBACKS_ITER;
	static UICallbackManager & getMe()
	{
		static UICallbackManager uicbm;
		return uicbm;
	}
	void clear()
	{
		for (CALLBACKS_ITER iter = callbacks.begin();iter != callbacks.end();++iter)
		{
			if (iter->second) delete iter->second;
		}
		callbacks.clear();
	}
};

#define UICALLBACK(name) UICallbackManager::getMe().getCallback(name)
NS_CC_END
