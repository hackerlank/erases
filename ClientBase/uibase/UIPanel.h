/**
 * ������ ���Գ��� �������� ���ҿ���ӵ���ƶ�����
 */
#pragma once
#include "cocos2d.h"
#include "UIBase.h"
#include "xmlScript.h"
#include "UIButton.h"
#include "UILabel.h"
#include "UINumber.h"
#include "UIImage.h"
#include "UIEditField.h"
#include "UIChoice.h"
#include "UILib.h"
NS_CC_BEGIN
class UIWindow;
struct stExecPanelEach{
	virtual void exec(UIBase *base) = 0;
};
class UIPanel:public UIBase{
public:
	/**
	* ����Button
	*/
	static UIBase * createButton(const CCPoint &position,const CCSize &size,const char * upImgName,const char *downImgName,UIPanel *parent = NULL,int uniqueId = -1);
	static UIBase * createButton(const CCPoint &position,const CCSize &size,const char* buttonName,UIPanel *parent = NULL,int uniqueId = -1);

	/**
	 * ����label
	 **/
	static UIBase *createLabel(const CCPoint &position,const CCSize &size,const char *content,float fontSize,UIPanel *parent = NULL,int uniqueId = -1);

	/**
	 * ����textfield
	 */
	static UIBase *createTextField(const CCPoint& position,const CCSize &size,const char* defaultContent,UIPanel *parent = NULL,int uniqueId = -1);

	/**
	 * ����ͼ��
	 */
	static UIBase *createImage(const CCPoint& position,const CCSize &size,const char *pngName,UIPanel *parent = NULL,int uniqueId = -1);

	/**
	 * ����ѡ���
	 */
	static UIBase *createChoice(const CCPoint &position,const CCSize &size,const char * upImgName,const char *downImgName,UIPanel *parent = NULL,int uniqueId = -1);

	/**
	 * ����lineValue
	 */
	static UIBase *createLineValue(const CCPoint &position,float minValue,float maxValue,float defaultValue,UIPanel * parent = NULL,int uniqueId = -1);
	/**
	 * ����editģʽ
	 */
	void setEditable();

	void addUI(UIBase *base);
	
	bool addGloabUI(UIBase *base);

	 /** 
	 * ����Ƿ���������
	 */
	virtual bool touchDown(float x,float y);
	/**
	 * ����λ��
	 */
	virtual bool touchMove(float x,float y);
	/**
	 * ֹͣ�϶�
	 */
	virtual bool touchEnd(float x,float y);

	/**
	 * ����λ��
	 */
	virtual void setPosition(float x,float y) ;
	
	/**
	 * ���ô�С
	 */
	virtual void setSize(float w,float h) ;
	/**
	 * ��ȡUIBase
	 */
	UIBase *getUIById(int id);

	void setEditable(bool tag);
	static UIPanel* create();

	static UIPanel * createFromNode(script::tixmlCodeNode *node);
	/**
	 * �������ڵ��µ��ӽڵ�
	 */
	void makeXmlFile(const std::string &name);
	bool initXFromNode(script::tixmlCodeNode *node);
	UIWindow *window;
	UIPanel()
	{
		window = NULL;
		_moveable = true;
		_width = 0;
		_height = 0;
		_touchIn = false;
		back = NULL;
		_nowTouchUI = NULL;
		uiType = UIBase::UI_PANEL;
		_onlyMe = false; // ֻ��Ӧ�Լ���ʱ��
	}
	void replaceBack(const char *pngName);
	void  setMovable(bool tag)
	{
		_moveable = tag;
	}
	

	void beLoaded();
	void loadFromFile(const char *fileName);

	void saveToFile(const char *fileName);
	UIPanel * getPanel(){return this;}
	void execEach(stExecPanelEach *exec);
	/**
	 * չʾ�Լ��� ֻ��Ӧ�����¼�
	 */
	void beginModel(){_onlyMe = true;}
	bool isModel(){return _onlyMe;}
	void endModel(){_onlyMe = false;}
	UIBase *getUIByName(std::string name);
	void removeBack()
	{
		if (back)
		{
			this->removeChild(back,true);
			back = NULL;
		}
	}
	UIButton * createBtn(script::tixmlCodeNode &btnNode);
	UILabel * createLblFromNode(script::tixmlCodeNode * node);
	UINumber *createNumFromNode(script::tixmlCodeNode *node);
    UIImage * createImgFromNode(script::tixmlCodeNode *node);
	UIChoice * createChoiceFromNode(script::tixmlCodeNode *node);
    UIEditField *createFieldFromNode(script::tixmlCodeNode *node);
	void showByAction(int actionId);
	CCSprite *back;
	virtual bool isMovable(){return _moveable;}
	UIWindow *getWindow();
	void bindBtnClick(const std::string &btnName,UICallback *callback);
	void bindChoiceClick(const std::string &btnName,UICallback *callback);
	std::string getEditFieldValue(const std::string &name);
	template<typename CLASS>
	bool getEditFieldValue(const std::string &name,CLASS& object)
	{
		std::string value = getEditFieldValue(name);
		object = atoi(value.c_str());
		return true;
	}
	void setEditFielValue(const std::string &name,const std::string& value);
	template<typename CLASS>
	void setEditFielValue(const std::string &name,CLASS& object)
	{
		std::stringstream ss;
		ss << object;
		setEditFielValue(name,ss.str());
	}
	void setUILabelvalue(const std::string &name,const std::string& value);
	std::string getUILablevalue(const std::string &name);
	void hide();
protected:
	CCPoint nowTouchPoint;
	bool _moveable;
	bool _touchIn;
	std::vector<UIBase*> childuis;
	typedef std::vector<UIBase*>::iterator CHILD_UIS_ITER;
	/**
	 * ϵͳ�Ļ������漯��
	 */
	std::vector<UIBase*> uis;
	std::map<std::string,UIBase *> nameuis;
	typedef std::map<std::string,UIBase*>::iterator NAME_UIS_ITER;
	float _width;
	float _height;
	UIBase *_nowTouchUI;
	bool _onlyMe;
	std::string backimg;
	static int const ALIGN_TOP = 1 << 0;
	static int const ALIGN_X_CENTER = 1 << 1;
	static int const ALIGN_DOWN = 1 << 2;
	static int const ALIGN_RIGHT = 1 << 3;
	static int const ALIGN_LEFT = 1 << 4;
	static int const ALIGN_Y_CENTER = 1 << 5;
	
};

template<class CHILD>
class BaseDialog:public script::tixmlCode,public UIPanel{
public:
	static CHILD* create(UIWindow *window,const char *uixml)
	{
		CHILD *node = new CHILD();
		if (node)
		{
			node->window = window;
			node->initFromFile(uixml);
			node->autorelease();
			return node;
		}
		CC_SAFE_DELETE(node);
		return NULL;
	}
	static CHILD* create(UIWindow *window,script::tixmlCodeNode* snode)
	{
		CHILD *node = new CHILD();
		if (node)
		{
			node->window = window;
			node->initWithNode(snode);
			node->autorelease();
			return node;
		}
		CC_SAFE_DELETE(node);
		return NULL;
	}
	bool initFromFile(const char *fileName)
	{
		uiXmlName = fileName;
		std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName);
		unsigned long nSize = 0;
		unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
		if (!nSize)return false;
		if (script::tixmlCode::initFromString((char*)buffer))
		{
			doInitEvent();
			UIStub stub(this,window);
			theUILib.execCode(&stub,this->onCreateCodeName.c_str());
			return true;
		}
		return false;
	}
	void initWithNode(script::tixmlCodeNode* node)
	{	
		initWithPanelNode(node);
		doInitEvent();
		UIStub stub(this,window);
		theUILib.execCode(&stub,this->onCreateCodeName.c_str());
	}
	/**
	 * �������ļ��м�������
	 * \param node ���ø��ڵ�
	 */
	void takeNode(script::tixmlCodeNode *node)
	{
		if (node && node->equal("Config"))
		{
 			// ����Label TextArea Button ���ɽ���ϵͳ
			// ������ӭ����
			script::tixmlCodeNode mainNode = node->getFirstChildNode("start");
			if (!mainNode.isValid()) mainNode = node->getFirstChildNode("panel");

			initWithPanelNode(&mainNode);
		}
		vTakeNode(node);
	}
	void initWithPanelNode(script::tixmlCodeNode *node)
	{
		std::string root = node->getAttr("root");
		if (node->isValid())
		{
			this->initXFromNode(node);
			if (root != "")
			{
				window->addUI(this);
			}
			else
				window->addPanel(this);		
			this->setZOrder(12);
		}
	}
	virtual void parseCode(script::tixmlCodeNode *code)
	{
		theUILib.parseCode(code); // ��ۿ�ִ�нڵ�
	}
	virtual void vTakeNode(script::tixmlCodeNode *node){}
	BaseDialog()
	{
		window = NULL;
	}
	std::string uiXmlName;
protected:
	virtual void doInitEvent(){}
};
NS_CC_END