#pragma once
#include "cocos2d.h"
#include "xmlScript.h"
NS_CC_BEGIN
/**
 * �������ƶ���Ŀ�ĵ�ʱչʾ
 */
class stCollideTargetCallback{
public:
	virtual void exec(CCNode *node) = 0;
};
/**
 * ������Ϣ
 */
class CartoonInfo:public CCObject{
public:
	/**
	 * ����������Ϣ ����autorelease
	 */
	static CartoonInfo* create(const CartoonInfo &info);
	static CartoonInfo* create();
	/**
	 * ���ݶ�������������
	 * \param parent ����������ʱ ������ʱSprite
	 */
	CCFiniteTimeAction * createAction(CCNode * self,CCNode *parent,const cocos2d::CCPoint &point,CCNode *target,stCollideTargetCallback * callback);
	int actionTag;
	int cartoonId; // �����ı��
	std::string cartoonName; // ��������
	enum{
		SELF = 0, // ����
		OTHER = 1, // ����
		FOLLOW = 2, // ���涯��
	};
	int cartoonType;// �������� ���� ���� ����

	enum{
		TIME_FRAMES = 0,
		MOVE_FRAMES = 1,
		FOLLOW_FRAMES = 2,
		FOLLOW_ANIMATIONS = 3, 
	};
	int frameType; // ��ʱ��֡ �����ƶ�֡
	
	float needTime; // ����ʱ��
	int actionType; // �������� ���ඨ��
	std::vector<CCSpriteFrame*> frames; // ��ʱ�����ı���	
	int nextConbineType; // ��һ���ϲ�����

	int delayTime; // ��ʱ
	enum{
		SEQUENCE = 0,// ���� 
		TOGETHER = 1, // һ��
	};
	// �ڴ˿��Ƹö����Ĳ��Ÿ���
	bool isValid(){return true;}
	/**
	 * ������һ����������
	 */
	CartoonInfo* addNextCartoonInfo(int nextConbineType,const CartoonInfo& info);
	CartoonInfo* nextCartoon; // ��һ��������Ϣ
	/**
	 * �ͷ�����
	 */
	void release();
	/**
	 * ��������֡
	 */
	CCAnimation * createAnimation(float costtime=0);

	CartoonInfo()
	{
		nextConbineType = SEQUENCE;
		cartoonId = -1;
		actionType = -1;
		cartoonType = -1;
		needTime = -1;
		nextCartoon = NULL;
		actionTag = -1;
		frameType = MOVE_FRAMES;
		delayTime = 0;
	}
	CartoonInfo &operator = (const CartoonInfo &info)
	{
		this->actionType = info.actionType;
		this->cartoonType = info.cartoonType;
		this->nextCartoon = info.nextCartoon;
		this->nextConbineType = info.nextConbineType;
		this->cartoonName = info.cartoonName;
		this->frameType = info.frameType;
		this->frames = info.frames;
		this->needTime = info.needTime;
		this->delayTime = info.delayTime;
		return *this;
	}
};
/**
 * �����ƶ����� �����������Լ����� 
 * ����֡���ƶ������
 */
class CartoonMoveAction:public CCMoveTo{
public:
	
	virtual void update(float time);
	bool isTempTarget;
	CartoonMoveAction()
	{
		isTempTarget = false;
	}

	/**
	 * ��������
	 */
	static CartoonMoveAction* create(const CartoonInfo &cartoonInfo, const CCPoint& position);
	/**
	 * ��ʼ��cartoon �ƶ���Ϊ
	 */
	bool init(const CartoonInfo &cartoonInfo, const CCPoint& position);
	/**
	 * �ͷ��Լ���ռ�е�֡
	 */
	void stop(void);
protected:
	CartoonInfo cartoonInfo;
};
/**
 * �������ƶ��������� 
 */
class CartoonAction:public CCAnimate{
public:
	bool isTempTarget;
	CartoonAction()
	{
		isTempTarget = false;
	}
	virtual void update(float time)
	{
		CCAnimate::update(time);
	}
	static CartoonAction* create(CCAnimation *animation);
	bool init(CCAnimation *animation);
	/**
	 * ������ͨ����
	 */
	static CartoonAction* create(const CartoonInfo &cartoonInfo);
	/**
	 * ��ʼ������
	 */
	bool init(const CartoonInfo &cartoonInfo);
	/**
	 * �ͷ��Լ���ռ�е�֡
	 */
	void stop(void);
};
/**
 * ����һ�����⶯��
 * ����Ŀ����������� 
 * ��target retain ÿ֡����Ƿ�ֻ�� 1 ����1�� ���� ˵��������ʧ ��¼��Ŀ�겻��
 * ����Ķ������ƶ�������
 */

class CartoonFollowAction:public CCMoveTo{
public:
	CartoonFollowAction()
	{
		isTempTarget = false;
		target = NULL;
		callback = NULL;
	}
	 static CartoonFollowAction* create(const CartoonInfo &cartoonInfo,CCNode *target);
	 /**
	 * ����
	 */
	 virtual void update(float t);
	 /**
	 * Ϊʹ������������
	 */
	void stop(void);

	bool initWithAnimation(CCAnimation *pAnimation);

    virtual void startWithTarget(CCNode *pTarget);
	void updateAnimate(float t);
	bool isTempTarget;
	stCollideTargetCallback *callback;
private:
	
	CCNode *target;
	CartoonInfo cartoonInfo;
	/**
	 * ����Animate������
	 */
	CCAnimation* m_pAnimation;
	std::vector<float> m_pSplitTimes;
	int                m_nNextFrame;
	CCSpriteFrame*  m_pOrigFrame;
	unsigned int    m_uExecutedLoops;
	
};

class FollowAnimationAction:public CCMoveTo{
public:
    FollowAnimationAction()
	{
		isTempTarget = false;
		followTarget = NULL;
		callback = NULL;
	}
    static FollowAnimationAction* create(CCNode *target,float needTime);
   
    virtual void update(float t);
    
	void stop(void);
    
    
    virtual void startWithTarget(CCNode *pTarget);
    bool isTempTarget;
	stCollideTargetCallback *callback;
private:
    CCNode *followTarget; // follow it
};
/**
 * ������ ���Բ��Ŷ���
 */
class Cartoon:public CCSprite{
public:
	/** �������ı�
	 * Ŀ��� position
	 * ��̬����Action
	 */
	void runSelfAction(const CartoonInfo &info,const CCPoint &position);

	/**
	 * ����������Ķ��� ָ��Ŀ�ĵ�
	 **/
	void runFlyAction(CCNode* parent,const CartoonInfo &info,const cocos2d::CCPoint &point);
	/**
	 * �������涯��
	 * �����������Ϣ
	 */
	void runFllowAction(CCNode *parent,const CartoonInfo&info,CCNode *target);
    void runState(CCNode *parent, CartoonInfo &info,CCNode *target);
    void runMoveState(CCNode *parent, CartoonInfo &info,CCNode * target,float aniTime = 0);
	void runMoveAction(CCNode *parent,CartoonInfo &info,float animationTime,const CCPoint &point);
	/**
	 * ��϶����Ĳ���
	 * \param parent fly ���ؽڵ�
	 * \param info ������Ϣ
	 * \param point Ŀ�ĵ�
	 * \param target �������
	 */
	void runAction(CCNode *parent,const CartoonInfo*info,const cocos2d::CCPoint &point,CCNode *target,stCollideTargetCallback * callback = NULL);
	/**
	 * ���н�������Ҫ�����ʱ�ڵ�
	 */
	void flyEnd(CCNode *pSender,void *arg);
	/**
	 * ��������
	 */
	void doCartoonEnd();
	/**
	 * ִ����һ��
	 */
	virtual void nextStep(){}

	void attachSprite(CCSprite *sprite)
	{
		this->sprite = sprite;
	}
private:
	CCSprite *sprite;
	
public:
	 /**
	  * ��ĳ����ΪΪ��ʼִ��״̬
	  */
	 void start(int id);
	 void tryNextAction(int id);
	 /**
	  * ���е�ִ����Ϊ
	  */
	 void tryConbineAction(int type);
	 int actionType;
	 int oldActionType;
	 Cartoon()
	 {
		actionType = 0;
		oldActionType = -1;
		sprite = NULL;
	 }
	 /**
	  * ��鵱ǰ��Ϊ
	  */
	 bool isNowAction(int actionType);
	 /**
	  * ��һ��������ȥ����ϵ
	  */
	 void clearAction(int type);
	 /**
	  * �������ȼ� ������Ӧ�Ķ���
	  */
	 void putConbineAction();
protected:
	 void setAction(int actionType);
	 virtual CartoonInfo* makeCartoon(int actionType);
	 virtual void putCartoon(CartoonInfo *action);
	 virtual CartoonInfo* v_makeCartoon(int actionType) {return NULL;};
	 virtual void v_putCartoon(CartoonInfo *action){};
};

struct stFrameInfo{
	std::string frameName;
	CCPoint offset;
	CCSpriteFrame *frame;
	stFrameInfo()
	{
		frame = NULL;
	}
};
class CartoonDirAction{
public:
	std::string FramesName; // ֡����
	std::string frameLoadType; // ֡��������
	std::vector<stFrameInfo> frames;
	CartoonDirAction()
	{
		
	}
	~CartoonDirAction()
	{
		for (std::vector<stFrameInfo>::iterator iter = frames.begin(); iter != frames.end();++iter)
		{
			if (iter->frame) iter->frame->release();
		}
	}
	/**
	 * ��ȡ��֡
	 */
	bool getFrames(std::vector<CCSpriteFrame *> &frames);
	/**
	 * ����ڵ�
	 */
	void takeNode(script::tixmlCodeNode *node);
};

class CartoonXmlAction{
public:
	std::string actionName; // ��������
	int actionType; // ��������
	float needTime; // ��Ҫʱ��
	int frameType; // ֡���� ʱ�� �����ƶ�����
	int cartoonType; // �������� [SELF,OTHER]
	std::map<int,CartoonDirAction> dirActions;
	typedef std::map<int,CartoonDirAction>::iterator DIRACTIONS_ITER;
	/**
	 * ��ȡ֡����
	 * \param frames ֡���� 
	 */
	bool getFrames(int dir,std::vector<CCSpriteFrame *> &frames);
	CartoonXmlAction()
	{
		actionType = 0;
		needTime = 0;
		cartoonType = 0;
		frameType = 0;
	}
	/**
	 * ����ڵ�
	 */
	void takeNode(script::tixmlCodeNode *node);
};
/**
 * ���ȭ
 */
class CartoonConbineAction:public CartoonXmlAction{
public:
	int nextType; // ��һ������
	/**
	 * ����ڵ�
	 */
	void takeNode(script::tixmlCodeNode *node);
	/**
	 * ��������
	 */
	CartoonInfo* getCartoonInfo(int dir);
};

NS_CC_END