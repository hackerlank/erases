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
class UIMapStub;
class UIMapLib;
class UICallback;
class MutiObject;
class MutiMap;
typedef int (UIMapLib::*UIMapAction)(UIMapStub *,script::tixmlCodeNode *);

//ִ�е�
class UIMapLibAction{
public:
	int type;
	UIMapAction action;
};

/**
 * ai ��ִ����
 * */
class UIMapStub{
public:
	MutiMap *map;
	UIWindow *window;
	MutiObject *nowTouchObject;// ��ǰ�Ӵ��Ķ���
	CCPoint nowTouchPoint; // ��ǰ�Ӵ��ĵ�
	UIMapStub()
	{
		map = NULL;
		window = NULL;
		nowTouchObject = NULL;
	}
};
/**
 * ִ�п�
 * ���ش���� �� �¼��� 
 * ��Ӧ�����¼� ����¼� �� touch�¼� ���Դ���������Ϊ ����UI��չʾ
 **/
class UIMapLib:public script::Lib<UIMapLibAction,UIMapStub,UIMapLib>
{
public:
	UIMapLib()
	{
		bindActions();
	}
	static UIMapLib & getMe()
	{
		static UIMapLib lib;
		return lib;
	}
	void initWithFile(const char *fileName);
    /**
     * ֻ����scope="stub" ��ʱ�� type ����Ч
     */
    int var(UIMapStub* stub,script::tixmlCodeNode * node)
    {
        return script::Lib<UIMapLibAction,UIMapStub,UIMapLib>::var(stub,node);
    }
    /**
     * ���
     */
    int print(UIMapStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<UIMapLibAction,UIMapStub,UIMapLib>::print(stub,node);
    }
    /**
     * �������
     **/
    int calc(UIMapStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<UIMapLibAction,UIMapStub,UIMapLib>::calc(stub,node);
    }
    /**
     * ִ�������ڵ�
     **/
    int exec(UIMapStub* stub,script::tixmlCodeNode * node)
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
	 * �������� 
	 */
	int show_panel(UIMapStub* stub,script::tixmlCodeNode * node);
	/**
	 * �������й����ƶ���touch��
	 */
	int move_allmonsters_to_touch_point(UIMapStub* stub,script::tixmlCodeNode * node);
	/**
	 * ��鵱ǰ��������
	 */
	int check_object_type(UIMapStub* stub,script::tixmlCodeNode * node);
	/**
	 * ��ǰѡ��Ϊ��
	 */
	 int check_null_pick(UIMapStub* stub,script::tixmlCodeNode * node);
};

#define theMapUILib UIMapLib::getMe()

NS_CC_END
