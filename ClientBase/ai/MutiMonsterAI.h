#pragma once 

/**
 * ����AI
 */

#include "scriptLib.h"
#include "cocos2d.h"
#include <bitset>
NS_CC_BEGIN
class MutiMonster;
class MutiAIStub;
class MonsterAILib;
class MutiEvent{
public:
	int tapTime; // ���ʱ��
	int execCount; // �������Ĵ���
	int execMaxCount;
	cc_timeval startTime; // ����ʱ��
	script::tixmlCodeNode* code; // ִ�д���
	MutiEvent()
	{
		startTime.tv_sec = 0;
		code = NULL;
		tapTime = 0;
		execCount = 0;
		execMaxCount = 0;
	}
	bool checkTimeOut(cc_timeval & nowTime);
};
class MutiAI{
public:
	MutiAI()
	{
		id = 0;
	}
	DWORD id;
	/**
 	 * ִ��һ���¼�
 	 * */
	bool action(MutiAIStub * stub,int event);
	/**
	 * ��ʱִ���¼�
	 */
	bool timer(MutiAIStub * stub,int event);
	enum{
		DEATH = 0, // ����
		BIRTH = 1, // ����
		TARGET_ENTER = 2, // ���������Ұ
		TARGET_LEAVE = 3, // �����뿪��Ұ
		ATTACK_ME = 4, // ���˹���
		IDLE_ACTION = 5, // ����ʱ���
		MEET_TARGET = 6, // �����ڹ�����Χ�� 
		HAD_TARGET = 7, // ��Ŀ���״̬
		HAD_TARGET_LEAVE = 8, // �ж����뿪
		MOVE_TO_DESTIONATION = 9,// �ƶ���Ŀ�ĵ�
		TOUCH_TIME_OUT = 10, // ��������ʱ�����
		ACTION_END = 11, // �������ܽ���
	};
	/**
 	 * ����һ��code
 	 * \param code ����ڵ�
 	 * \param name ��������
 	 * \return ture �ɹ� false ʧ��
 	 * */
	bool addCode(script::tixmlCodeNode* code,script::tixmlCodeNode *info);

	void bindEvent(const std::string &name,script::tixmlCodeNode *code);

	void clearEvent(const std::string &name);

	unsigned int getEventIdByName(const std::string &name);
private:
	std::vector<script::tixmlCodeNode*> events;	
	std::vector<std::vector<MutiEvent> > timeEvts; // ��ʱ����¼� ���������ִ�� �¼�����Ч���ڲ�������
};
typedef int (MonsterAILib::*AIAction)(MutiAIStub *,script::tixmlCodeNode *);

//ִ�е�
class AILibAction{
public:
	int type;
	AIAction action;
};
class MutiMonsterRefrence
{
public:
	MutiMonster * monster;
	int uniqueId; // monster Ψһ���
	cc_timeval touchStartTime; // �ս������targetsʱ��
	int weight; // Ȩֵ
	bool isValid(){return true;} // ��ǰ�����Ƿ���Ч
	bool hadMeet; // �Ƿ�����
	MutiMonsterRefrence()
	{
		CCTime::gettimeofdayCocos2d(&touchStartTime,NULL);
		monster = NULL;
		uniqueId  = -1;
		weight = 0;
		hadMeet = false;
	}
	bool checkTimeOut(int timeout);

	MutiMonsterRefrence & operator=(const MutiMonsterRefrence &ref)
	{
		monster = ref.monster;
		uniqueId = ref.uniqueId;
		touchStartTime = ref.touchStartTime;
		weight = ref.weight;
		return *this;
	}
	std::bitset<32> notifyStates;
	bool checkNotify(int aiEvent)
	{
		return notifyStates.test(aiEvent);
	}
	void setNotify(int aiEvent)
	{
		notifyStates.set(aiEvent);
	}
	void resetNotify(int aiEvent)
	{
		notifyStates.reset(aiEvent);
	}
	
};
struct stTimeInfo{
public:
	cc_timeval startTime; // ��ʼʱ��
	stTimeInfo()
	{
		reset();
	}
	void reset()
	{
		 CCTime::gettimeofdayCocos2d(&startTime,NULL);
	}

	bool checkTimeOut(int timeout)
	{
		cc_timeval nowTime;
		CCTime::gettimeofdayCocos2d(&nowTime,NULL);
		float disTime = CCTime::timersubCocos2d(&startTime,&nowTime) / 1000;
		if (disTime >= timeout)
		{
			return true;
		}
		return false;
	}
};
/**
 * ai ��ִ����
 * */
class MutiAIStub{
public:
	MutiMonsterRefrence tempRef; // Ŀǰ��ʱ����
	MutiMonster *npc;
	std::vector<MutiMonsterRefrence> targetPool; // ����� 0 �Ŷ���ΪĬ�ϴ����
	typedef std::vector<MutiMonsterRefrence>::iterator TARGETPOOL_ITER;
	MutiAIStub()
	{
		npc = NULL;
		ai = NULL;
	}
	MutiAIStub(MutiMonster *npc)
	{
		this->npc = npc;
		ai = NULL;
	}
	void removeTarget();
	int getTargetCount(); // ��ǰ���������
	MutiMonster * getTarget(); // ��ȡ��ǰ����
	MutiMonsterRefrence * getTargetRef(); // ��ȡ��ǰ�����
	void addTarget(MutiMonster *monster); // ���Ӷ���
	void pickSuitTarget(); // ��ѡ���ʵĶ���
	std::bitset<32> notifyStates;
	bool checkNotify(int aiEvent)
	{
		return notifyStates.test(aiEvent);
	}
	void setNotify(int aiEvent)
	{
		notifyStates.set(aiEvent);
	}
	void resetNotify(int aiEvent)
	{
		notifyStates.reset(aiEvent);
	}
	stTimeInfo * getTimer(int id)
	{
		std::map<int,stTimeInfo>::iterator iter = times.find(id);
		if (iter != times.end())
		{
			return &iter->second;
		}
		return NULL;
	}
	void addTimer(int id)
	{
		stTimeInfo *timeInfo = getTimer(id);
		if (timeInfo)
		{
			timeInfo->reset();
		}
		else
		{
			times[id] = stTimeInfo();
		}
	}
	void delTimer(int id)
	{
		std::map<int,stTimeInfo>::iterator iter = times.find(id);
		if (iter != times.end())
		{
			 times.erase(iter);
		}
	}
	MutiAI *ai;
	std::map<int,stTimeInfo> times;
};
/**
 * ִ�п�
 * ���ش���� �� �¼���
 **/
class MonsterAILib:public script::Lib<AILibAction,MutiAIStub,MonsterAILib>
{
public:
	static MonsterAILib & getMe()
	{
		static MonsterAILib lib;
		return lib;
	}
	void initWithFile(const char *fileName);
    /**
     * ֻ����scope="stub" ��ʱ�� type ����Ч
     */
    int var(MutiAIStub* stub,script::tixmlCodeNode * node)
    {
        return script::Lib<AILibAction,MutiAIStub,MonsterAILib>::var(stub,node);
    }
    /**
     * ���
     */
    int print(MutiAIStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<AILibAction,MutiAIStub,MonsterAILib>::print(stub,node);
    }
    /**
     * �������
     **/
    int calc(MutiAIStub* stub,script::tixmlCodeNode * node)
    {
    	return script::Lib<AILibAction,MutiAIStub,MonsterAILib>::calc(stub,node);
    }
    /**
     * ִ�������ڵ�
     **/
    int exec(MutiAIStub* stub,script::tixmlCodeNode * node)
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
    /**
     * ִ���¼�
     * \param npcAIID ai ��
     * \param npc ����
     * \param event �¼�
     * */
    void execEvent(DWORD npcAIID,MutiAIStub *stub,int event);
	void tapExecEvent(DWORD npcAIID,MutiAIStub *stub,int event);
    std::vector<MutiAI*> npcAis;
/////////////////////////////////////////////////////////////////////////    
//			�����չ
////////////////////////////////////////////////////////////////////////
    /**
     * ��������
     * */    
    int putskill(MutiAIStub* stub,script::tixmlCodeNode * node);

	/**
	 * ���ߵ� Ŀ��
	 * <movetotarget/>
	 **/
	int movetotarget(MutiAIStub* stub,script::tixmlCodeNode * node);
	/**
	 * �趨������̵�Ϊ��ǰ�������� �����趨lock����
	 * <lockmindistacetarget/>
	 */
	int lockmindistacetarget(MutiAIStub* stub,script::tixmlCodeNode * node);
	/**
	 * ��Ȩֵ��������� �����趨
	 * <locksuittarget/>
	 **/
	int locksuittarget(MutiAIStub* stub,script::tixmlCodeNode * node);
	/**
	 * ���ߵ�Ŀ�ĵ�
	 * <move targetx="" targety=""/>
	 */
	int move(MutiAIStub* stub,script::tixmlCodeNode * node);
	/**
	 * ����Ŀ����Ȧ
	 * <moverandarround/>
	 */
	int moverandarround(MutiAIStub* stub,script::tixmlCodeNode * node);
	
	/**
	 * �����ǰ�ƶ�·��
	 */
	int clearmovepath(MutiAIStub* stub,script::tixmlCodeNode * node);
	
	/**
	 * ���õ�ǰ����ʱ��
	 */
	int reset_touch_lasttime(MutiAIStub* stub,script::tixmlCodeNode * node);
	/**
	 * ��鹥���ĳ���ʱ��
	 */
	int check_touch_lasttime(MutiAIStub* stub,script::tixmlCodeNode * node);

	/**
	 * ��鵱ǰ��λ��
	 */
	int checknowposition(MutiAIStub* stub,script::tixmlCodeNode * node);

	/**
	 * �����¼���Ӧ����
	 **/
	int bind_event(MutiAIStub* stub,script::tixmlCodeNode * node);
	/**
	 * ����¼�
	 **/
	int clear_event(MutiAIStub* stub,script::tixmlCodeNode * node);
	/**
	 * ��鵱ǰ��Ŀ��
	 */
	int checknowtarget(MutiAIStub* stub,script::tixmlCodeNode * node);


	/**
	 * �����¼����� �����¼��������ٽ��� ������ ��Ҫ�д˻���
	 **/
	int reset_notify(MutiAIStub* stub,script::tixmlCodeNode * node);
	
	/**
	 * ����ʱ��
	 */
	int add_timer(MutiAIStub* stub,script::tixmlCodeNode * node);

	/**
	 * ���ʱ��
	 **/
	int check_timer(MutiAIStub* stub,script::tixmlCodeNode * node);

	/**
	 * ����ʱ��
	 */
	int reset_timer(MutiAIStub* stub,script::tixmlCodeNode * node);

	/**
	 * ɾ��ʱ��
	 */
	int del_timer(MutiAIStub* stub,script::tixmlCodeNode * node);

	/**
	 * �����ﵱǰ��Ϊ
	 */
	int check_now_monster_action(MutiAIStub* stub,script::tixmlCodeNode * node);
};

#define theAILib MonsterAILib::getMe()

NS_CC_END
