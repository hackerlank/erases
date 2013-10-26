#pragma once
#include "serialize.h"
#include "vector"
#include <string>
#include "cocos2d.h"
#include "tinyxml.h"
NS_CC_BEGIN
class UIBase;
typedef void (UIBase::*UI_EVENT_HANDLE)(UIBase*);
#define ui_function(_SELECTOR) FunctionInfo((UI_EVENT_HANDLE)(&_SELECTOR),this)

#define ui_object_function(object,_SELECTOR) FunctionInfo((UI_EVENT_HANDLE)(&_SELECTOR),object)
#define REGISTER_EVENT 
class UIItem;
class UIPanel;
class UIWindow;
struct stBagExecEach{
	virtual  void exec(UIItem *item) = 0;
};
#define GET_UI_BYID(Panel,Class,Fieldname,UniqueId)\
	Class *Fieldname = static_cast<Class*>( Panel->getUIById(UniqueId));
#define GET_UI_BYNAME(Panel,Class,Fieldname,UniqueName)\
	Class *Fieldname = static_cast<Class*>( Panel->getUIByName(UniqueName));
// ��ȡ���
#define PANEL(Panel,UniqueName) \
	(static_cast<UIPanel*>( Panel->getUIByName(UniqueName)))
// ��ȡ��ť
#define BUTTON(Panel,UniqueName) \
	((UIButton*) Panel->getUIByName(UniqueName))
// ��ȡ��ǩ
#define LABEL(Panel,UniqueName) \
	(UILabel*) Panel->getUIByName(UniqueName))
// ��ȡ�༭��
#define EIDTFIELD(Panel,UniqueName) \
		(static_cast<UIEditField*>( Panel->getUIByName(UniqueName)))
// ��ȡ�б�
#define LIST(Panel,UniqueName) \
		(static_cast<UIViewList*>( Panel->getUIByName(UniqueName)))
// ��ȡ��ѡ��
#define CHOICE(Panel,UniqueName) \
		(static_cast<UIChoice*>( Panel->getUIByName(UniqueName)))
struct FunctionInfo{
	UI_EVENT_HANDLE handle;
	UIBase *object;
	FunctionInfo()
	{
		object = NULL;
		handle = NULL;
	}
	FunctionInfo(UI_EVENT_HANDLE handle,UIBase *object)
	{
		this->handle = handle;
		this->object = object;
	}
};
struct UICallback{
	virtual void callback(UIBase *base) = 0;
};
/**
 * UI �Ļ�����
 */
class UIBase:public CCNode{
public:
	int uniqueId; // Ψһ���
	std::string name; // �ؼ�����
	std::string uniqueName;
	std::string onCreateCodeName; // ��������
	std::string onClickCodeName; // �������
	enum{
		UI_LABEL = 0, // ��̬�ı���
		UI_IMAGE_BUTTON = 1, // ͼ��ť
		UI_BUTTON = 2, // ��ť
		UI_LIST = 3, // �б�
		UI_CHOICE = 4, // ѡ��
		UI_BAG = 5, // ����
		UI_TEXT_FIELD = 6, // �����
		UI_RICH_TEXT = 7, // ���ı���
		UI_VALUE = 8, // ��ֵ��
		UI_PANEL = 9, // ����
	};
//	SERIALIZE_KIND(0);
	int uiType; // �ؼ�����
	int eventPriority;// �¼����ȼ�
	enum{
		EVENT_NULL = 0, // ���¼�
		EVENT_CLICK_DOWN = 1, // ĳ����Ŀ������
		EVENT_EDIT_DOWN = 2, // ĳ����Ŀ���༭
		EVENT_PANEL_LOAD = 3, // panel�������
		EVENT_DRAG_OUT = 4, //���屻ק��
		EVENT_TOUCH_IN, // ����
		EVENT_TOUCH_MOVE, // �������ƶ�
		EVENT_TOUCH_OUT, // ����
		EVENT_TOUCH_NO_CHILD_IN,
	};
	virtual UIPanel * getPanel();
	/**
	 * ����һ��������ui ���ڳ־û�
	 */
	static UIBase * create(int kind);
	/**
	 * ���¼��������
	 */
	virtual bool bind(int uiEvent,const FunctionInfo& function);
	virtual bool bind(int uiEvnet,UICallback *callback);
	bool bind(int uiEvent,const char *luaFunctionName);
	virtual void doEvent(int uiEvent,UIBase *base);
	UIWindow *getDepthWindow();
	UIBase()
	{
		eventPriority = 0;
		uniqueId = 0;
		x = y = w = h = 0;
		uiType = -1;
	}
	~UIBase()
	{
		for (UI_CALLBACK_ITER iter = event_callbacks.begin(); iter != event_callbacks.end();++iter)
		{
//			if(*iter) delete *iter;
		}
	}
	std::vector<FunctionInfo> event_functions;
	std::vector<UICallback*> event_callbacks;
	typedef std::vector<FunctionInfo>::iterator EVENT_FUNCTIONS_ITER;
	typedef std::vector<UICallback*>::iterator UI_CALLBACK_ITER;
	/**
	 * ����λ��
	 */
	virtual void setPosition(float x,float y) {return;}
	enum{
		TOUCH_DOWN = 0, // ����
		TOUCH_MOVE = 1, // �ƶ�
		TOUCH_END = 2, // ����
	};
	/**
	 * ������
	 * \parma touchType �������
	 * \param touchPoint �����
	 */
	virtual bool doTouch(int touchType,const CCPoint &touchPoint);
	virtual bool doTouch(int touchType,CCTouch* touch)
	{
		return false;
	}
	/**
	 * ���ô�С
	 */
	virtual void setSize(float w,float h) {return;}
	 /** 
	 * ����Ƿ���������
	 */
	virtual bool touchDown(float x,float y) {return false;}
	/**
	 * ����λ��
	 */
	virtual bool touchMove(float x,float y){return false;}
	/**
	 * ֹͣ�϶�
	 */
	virtual bool touchEnd(float x,float y) {return false;}

	/**
	 * ����Ϊ�ɱ༭ģʽ
	 */
	virtual void setEditable(bool tag) {return ;}
	virtual bool isMovable(){return true;}
	/**
	 * ���� �ɼ�
	 */
	void setVisible(bool tag);

	virtual void draw(){
		CCNode::draw();
	}

	virtual  void visit()
	{
		CCNode::visit();
	}
	static std::string toUTF8(const std::wstring& ); 
	/**
	 * �������ڵ��µ��ӽڵ�
	 */
	virtual TiXmlElement * makeNode(TiXmlElement *parent = NULL,const std::string &name="base");
public:
	float x;
	float y;
	float w;
	float h;
};

NS_CC_END
