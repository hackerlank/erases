#pragma once
#include "cocos2d.h"
#include "xmlScript.h"
#include "HexagonGrids.h"
#include "MutiObject.h"
#include "quickidmanager.h"
#include "MutiMonsterAI.h"
NS_CC_BEGIN
class MutiMap;
class MutiMonster;
class ActionPool{
public:
	static std::map<std::string,unsigned int> actionsMap;
	typedef std::map<std::string,unsigned int>::iterator ACTIONSMAP_ITER;
	unsigned int actions; // ����IDs
	std::list<unsigned int> actionStack;
	typedef std::list<unsigned int>::iterator ACTIONS_ITER;
	void addAction(const std::string &name);
	void addAction(const unsigned int &actionId);
	enum ACTION_TYPE{
		CONBINE_ACTION = 0, // ͬʱ��Ϊ
		SINGLE_ACTION = 1, // ������Ϊ
		ALWAYS_ACTION = 2, // ������Ϊ ���뿪
		REPLACE_ACTION = 3, // �滻ִ��
	};
	ACTION_TYPE actionType; // ��Ϊ����
	/**
	 * ��ȡ����
	 */
	unsigned int getAction();
	/**
	 * �ͷŹ���
	 */
	void popAction();

	static unsigned int getActionIdByName(const std::string&name); 

	ActionPool()
	{
		actions = 0;
		actionType = SINGLE_ACTION;
	}
};
/**
 * ��ǰ���Ƿ��ܹ�ִ��
 */
class MoveCheckLogic{
public:
	std::vector<GridIndex> offsets; // ����ƫ���б�
	bool isCollide; // �ж��Ƿ���ײ
	std::string actionName; // ��Ϊ����
	GridIndex destination; // Ŀ�ĵ�
	int blockType;
	MoveCheckLogic()
	{
		blockType = 1;
		isCollide = false;
	}
	/**
	 * ִ�е�ǰ��Ϊ
	 * \param monster ����
	 * \return �������Ƿ�ִ��
	 **/
	bool doLogic(MutiMonster *monster);
	void takeNode(script::tixmlCodeNode *node);
};
/**
 * ��ǰ��ִ��
 */
class MoveActionLogic{
public:
	std::vector<MoveCheckLogic> checks;
	typedef std::vector<MoveCheckLogic>::iterator CHECKS_ITER;
	MoveActionLogic()
	{
	}
	void takeNode(script::tixmlCodeNode *node);
	void doLogic(MutiMonster *monster);
};
typedef std::list<MoveActionLogic> MOVE_LOGICS;
/**
 * Ԥ�����·��˵��
 */
class PrePathDec{
public:
	int dir; // ����
	MOVE_LOGICS indexs; // �����б�
	void takeNode(script::tixmlCodeNode *node);
};
/**
 * ���������·��
 **/
class PrePathDecDirs{
public:
	std::string name; // ����
	std::vector<PrePathDec> paths;
	void takeNode(script::tixmlCodeNode *node);

	MOVE_LOGICS* getLogic(int dir)
	{
		if (dir < paths.size())
		{
			return &paths.at(dir).indexs;
		}
		return NULL;
	}
};
class MutiMonsterQuickSerach:public QuickIdManager{
public:
	static MutiMonsterQuickSerach &getMe()
	{
		static MutiMonsterQuickSerach me;
		return me;
	}
};
class MutiAIStub;
class MutiMonsterData{
public:
	int eyeshort; // ��Ұ����
	int maxTargets; // ���ͳ������
	int attackdistance; // ��������
	int id;
	int maxLastAttackTime;
	MutiMonsterData()
	{
		maxLastAttackTime = 3;
		id = 0;
		eyeshort = 4;
		maxTargets = 10;
		attackdistance = 2;
	}
};
/**
 * ʵ�ֹ����ڵ�ͼ�ϵĸ��ֶ���
 */
class MutiMonster:public MutiObject,public script::tixmlCode,public QuickObjectBase{
public:
	MutiMonsterData data;
	int uniqueSerachId;
	 /**
	 * ���ÿ���Ψһ����
	 * \param uniqueQuickId ���ÿ���Ψһ����
	 */
	virtual void setUniqueQuickId(int uniqueQuickId)
	{
		this->uniqueSerachId = uniqueQuickId;
	}
	/**
	 * ��ȡ����Ψһ����
	 * \return ����Ψһ����
	 */
	virtual int getUniqueQuickId()
	{
		return uniqueSerachId;
	}
	static MutiMonster * create();
	int dir;
	CCPoint offset; // ���ƫ��
	CCSize size; // �ҵ���Ч���
	MutiMap *map;

	int monsterAIID; // �����AI���
	MutiAIStub stub;
	MutiAIStub* getStub(); // ��ȡ���
	MutiMonster()
	{
		monsterAIID = 0;
		uniqueSerachId = 0;
		dir = 0;
		map = NULL;
		objectType = MutiObject::MOSTER_TYPE;
	}
	/**
	 * ���ԴӶ����б��л�ȡһ������ ����Ϊ
	 * ���޶�����ִ����ʱ
	 * �������ļ��л�ȡ�������ȼ��б� ����ʼ��
	 * <actions count="10">
	 *	<action name=""  priority=""/>
	 * </actions>
	 */
	void start(const std::string &actionFile);
	/**
	 * ִ��ĳ������ ��ȡ��ǰ���������ȼ� Ȼ����뵽�б��� Ĭ��Ϊ0
	 */
	void tryAction(const std::string& name);
	/**
	 * ��һ������ǰϦ ���ݶ���������Ϊ
	 */
	void nextStep();
	void doAIControl();
	void doMoveControl();

	void doActionEndTrrigeEvent();
	/**
	 * ����Ƿ���Ҫֹͣ
	 */
	bool checkNeedStop(const GridIndex &index);
	/**
	 * ִ����Ϊ
	 */
	void doAction();
	/**
	 * �������ļ��л�ȡ��Ϣ
	 **/
	void takeNode(script::tixmlCodeNode *node);
	void initNode(script::tixmlCodeNode *node);
	std::vector<ActionPool> actionPools;
	typedef std::vector<ActionPool>::iterator ACTIONPOOLS_ITER;
	std::map<std::string,int> priorityMap; // ���ȼ��б� �������м���
	typedef std::map<std::string,int>::iterator PRIORITYMAP_ITER;

	CartoonInfo * makeMyCartoon(const unsigned int&,int dir);
	void putMyCartoon(CartoonInfo *info);
	typedef std::vector<CartoonConbineAction> COBINE_ACTIONS;
	/*static*/ std::map<unsigned int,COBINE_ACTIONS > conbineactionmaps; // ��Ϊ��
	typedef std::map<unsigned int,COBINE_ACTIONS >::iterator CONBINEACTIONMAPS_ITER;
	unsigned int nowActionName;

	/*static*/ std::map<std::string,PrePathDecDirs> prePaths; // ����Ԥ�����·��
	typedef std::map<std::string,PrePathDecDirs>::iterator PRE_PATHS_ITER;

	bool checkIn(const CCPoint &point);
	
	std::vector<GridIndex> myindexs; // �Լ��ĸ����б� �������м���
	
	GridIndex getStartMyIndex(); // ��ȡ�Լ�����ʼ����

	bool checkNotDirCollide(const GridIndex &nextIndex,std::vector<GridIndex> &dirindexs,int index=1);
	/**
	 * ��ȡ��Ҫ�½��ĵ������
	 */
	GridIndex getPreDownIndex();
	/**
	 * ���ݵ��ȡ��ͼ��ʵ������λ��
	 */
	CCPoint getLocationByIndex(const GridIndex &index);
	/**
	 * ��ȡ��ǰ������
	 */
	GridIndex getNowIndex();
	int calcDistance(MutiMonster *monster);
	/**
	 * ��鵱ǰ��Ϊ���Ƿ�����Լ�
	 */
	bool isNowAction(const std::string &name);
	/**
	 * ʹ��Star Ѱ·��Ŀ�ĵ�
	 */
	void tryMoveUseAstr(const GridIndex &index);
	/**
	 * ���Astar Ѱ·
 	 */
	void clearAstar();
	void setPosition(const GridIndex &point);
	/**
	 * ��ȡ��point Ϊ��ʼ��·���б� ������ǰ·��
	 */
	void getPreparePath(const std::string &name,const GridIndex &point);

	void setPosition(const CCPoint &point);

	void freshBlock();

	void setMyBlocks(const GridIndex &point);
	void clearMyBlocks(const GridIndex &point);

	void doControl(const std::string &name);

	void doCheckTargets();// ��鵱ǰĿ��

	GridIndex getAroundRandomPoint(); // ��ȡ��Χ�����

	GridIndex getRandomPointInRect(); //��ȡ�����������
public:
	/**
	 * �жϵ�ǰ�Ƿ��ƶ�
	 */
	bool isMoving();
	bool isControl(){return logics.size();}
	
	/**
	 * ��ǰĿ�ĵ� ʹ����Astar
	 */
	GridIndex nowAstarDestination;
	/**
	 * ���ƶ���·��
	 */
	std::list<GridIndex> movePath;

	MOVE_LOGICS logics;
	/**
	 * ��ǰĿ�꼯��
	 */
	std::list<MutiMonster*> targets;
	
	/**
	 * ��ȡ��ǰ��Ŀ��
	 */
	MutiMonster * getNowTarget();
	GridIndex nowLocationIndex; // ���ڵĵ�
	GridIndex maybeLocationIndex; // �����ĵ�
	std::vector<GridIndex> needClearBlocks; // ��Ҫ���ݵ����õ��赲��
	/**
	 * ��ǰ��Ŀ�ĵ�ʱ ����λ�� ���趨���ж��� ʹ��Astar �㷨 ��Astar�㷨ʧ�� ʹ���������Ч���ƶ��Ĳ��� ����Ҫ��ͷ 
	 * ���ȵ�ͷ �ȴ���һ������
	 */
	void moveToUseAstar(const GridIndex &point);
	/**
	 * ���Ե�ͷ
	 */
	void setDir(int dir);
	
	/**
	 * ����ʵ������µİ汾 ʹ������������ϵͳ ����·��Ԥ�ȶ���
	 * ���ռȶ����߼�·������ ���������׶���ײ ������(��ײ��ֹ) �����½��׶���ײ ��ֹ
	 */
	void jumpTo();

	void moveLeft();
public:
	MoveActionLogic idleLogic;
};

NS_CC_END