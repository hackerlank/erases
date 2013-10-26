#include "MutiMonster.h"
#include "MutiMap.h"
#include "MutiMonsterAI.h"
NS_CC_BEGIN
#define _SMALL_RECT 1 // Ԥռλ ��ֹϵͳ �ж�ռλBUG
//std::map<unsigned int,MutiMonster::COBINE_ACTIONS > MutiMonster::conbineactionmaps;
std::map<std::string,unsigned int> ActionPool::actionsMap;
//std::map<std::string,PrePathDecDirs> MutiMonster::prePaths;
void ActionPool::addAction(const std::string &name)
{
	unsigned int id = getActionIdByName(name);
	if (id != 0)
	{
		addAction(id);
	}
}
void ActionPool::addAction(const unsigned int& actionId)
{
	if (actionType == ALWAYS_ACTION)
	{
		actions = actionId;
	}
	if (actionType == CONBINE_ACTION)
	{
		actions += actionId;
	}
	if (actionType == SINGLE_ACTION)
	{
		actionStack.push_back(actionId);
	}
	/**
	if (actionType == REPLACE_ACTION)
	{
		//����ִ�е�ǰ����
		actions = actionId;
		stopAllActions();
		nextStep();
	}
	**/
}
/**
 * ��ȡ����
 */
unsigned int ActionPool::getAction()
{
	if (actionType == CONBINE_ACTION)
	{
		return actions;
	}
	if (actionType == SINGLE_ACTION)
	{
		if (actionStack.empty()) return 0;
		return actionStack.front();
	}
	if (actionType == ALWAYS_ACTION)
	{
		return actions;
	}
	return 0;
}
unsigned int ActionPool::getActionIdByName(const std::string&name)
{
	ACTIONSMAP_ITER iter = actionsMap.find(name);
	if (iter != actionsMap.end())
	{
		return iter->second;
	}
	return 0;
}
/**
 * �ͷŹ���
 */
void ActionPool::popAction()
{
	if (actionType == CONBINE_ACTION)
	{
		actions = 0;
	}
	if (actionType == SINGLE_ACTION)
	{
		actionStack.pop_front();
	}
}
MutiMonster * MutiMonster::create()
{
	MutiMonster *monster = new MutiMonster();
	if (monster)
	{
		monster->initWithTexture(NULL, CCRectZero);
		monster->autorelease();
		monster->attachSprite(monster);
		return monster;
	}
	CC_SAFE_DELETE(monster);
	return NULL;
}
MutiAIStub* MutiMonster::getStub() // ��ȡ���
{
	stub.npc = this;
	return &stub;
}
/**
 * ���ԴӶ����б��л�ȡһ������ ����Ϊ
 * ���޶�����ִ����ʱ
 * �������ļ��л�ȡ�������ȼ��б� ����ʼ��
 * <actions count="10">
 *	<action name=""  priority=""/>
 * </actions>
 */
void MutiMonster::start(const std::string &actionFile)
{
	std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(actionFile.c_str());
	unsigned long nSize = 0;
	unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
	if (!nSize)return;
	initFromString((char*)buffer);

	// �������ļ��м�����Ϣ
	doAction();

	tryAction("idle");
	CCSprite * test = CCSprite::create("cell.png");
	this->addChild(test);
	test->setPosition(offset);
	this->setAnchorPoint(ccp(offset.x/size.width,offset.y / size.height));
	MutiMonsterQuickSerach::getMe().addObject(this);

	theAILib.execEvent(this->monsterAIID,getStub(),MutiAI::BIRTH); // ��������¼�
}
/**
 * ִ��ĳ������ ��ȡ��ǰ���������ȼ� Ȼ����뵽�б��� Ĭ��Ϊ0
 */
void MutiMonster::tryAction(const std::string& name)
{
	int step = 0;
	PRIORITYMAP_ITER iter = priorityMap.find(name);
	if (iter != priorityMap.end())
	{
		step = iter->second;
	}
	if (step >= actionPools.size())
	{
		actionPools.resize(step+1);
	}
	actionPools[step].addAction(name);
	if (actionPools[step].actionType == ActionPool::REPLACE_ACTION)
	{
		this->stopActionByTag(step);
		nextStep();
	}
}
/**
 * ��һ������ǰϦ ���ݶ���������Ϊ
 */
void MutiMonster::nextStep()
{
//	 TODO
#ifdef _SMALL_RECT
	//map->clearBlock(nowLocationIndex,GridIndex::MONSTER_BLOCK);
	this->freshBlock();
#endif
	//nowLocationIndex = this->maybeLocationIndex;
	//doMoveControl();
	doAIControl();
	doActionEndTrrigeEvent();
	doAction();
	doCheckTargets();
	
}
void MutiMonster::doAIControl()
{
	// ����Ƿ����յ�
	// ���ڼ�����
	if (nowAstarDestination.isValid() && !nowAstarDestination.equal(getNowIndex()) && !isMoving()) // ʹ��Astar ����Ѱ·
		moveToUseAstar(nowAstarDestination);
	if (nowAstarDestination.isValid() && nowAstarDestination.equal(getNowIndex()))
	{
		if (!stub.checkNotify(MutiAI::MOVE_TO_DESTIONATION))
		{
			stub.setNotify(MutiAI::MOVE_TO_DESTIONATION);
			theAILib.execEvent(this->monsterAIID,this->getStub(),MutiAI::MOVE_TO_DESTIONATION); // �ƶ���Ŀ�ĵ�
		}
	}
}
/**
 * ִ�е�ǰ��Ϊ
 * \param monster ����
 * \return �������Ƿ�ִ��
 **/
bool MoveCheckLogic::doLogic(MutiMonster *monster)
{
	GridIndex temp = monster->getStartMyIndex();
	if (monster->checkNotDirCollide(monster->getStartMyIndex(),offsets) && !isCollide)
	{
		temp.x += this->destination.x;
		temp.y += this->destination.y;
		monster->movePath.push_back(temp);
		monster->tryAction(this->actionName);
		return true;
	}
	if (!monster->checkNotDirCollide(monster->getStartMyIndex(),offsets,blockType) && isCollide)
	{
		temp.x += this->destination.x;
		temp.y += this->destination.y;
		monster->movePath.push_back(temp);
		monster->tryAction(this->actionName);
		return true;
	}
	return false;
}
void MoveCheckLogic::takeNode(script::tixmlCodeNode *node)
{
	actionName = node->getAttr("name");
	std::string collideStr = node->getAttr("collide");
	if (collideStr == "true")
	{
		isCollide = true;
	}
	else
	{
		isCollide = false;
	}
	destination.x = node->getInt("x");
	destination.y = node->getInt("y");
	blockType = node->getInt("blocktype");
	script::tixmlCodeNode offsetNode = node->getFirstChildNode("offset");
	while (offsetNode.isValid())
	{
		GridIndex offset;
		offset.x = offsetNode.getInt("x");
		offset.y = offsetNode.getInt("y");
		offsets.push_back(offset);
		offsetNode = offsetNode.getNextNode("offset");
	}
}
/**
 * �ƶ�������
 */
void MutiMonster::doMoveControl()
{
	if (!isControl())
	{
		idleLogic.doLogic(this);
	}
	else// �ⲿ������
	{
		MoveActionLogic &logic = logics.front();
		logic.doLogic(this);
		logics.pop_front();
	}
}
void MoveActionLogic::takeNode(script::tixmlCodeNode *node)
{
	script::tixmlCodeNode movelogicNode = node->getFirstChildNode("movelogic");
	while (movelogicNode.isValid())
	{
		MoveCheckLogic check;
		check.takeNode(&movelogicNode);
		checks.push_back(check);
		movelogicNode = movelogicNode.getNextNode("movelogic");
	}
}
void MoveActionLogic::doLogic(MutiMonster *monster)
{
	for (CHECKS_ITER iter = checks.begin();iter != checks.end();++iter)
	{
		if (iter->doLogic(monster))
		{
			return;
		}
	}
}
void PrePathDec::takeNode(script::tixmlCodeNode *node)
{
	dir = node->getInt("dir");
	script::tixmlCodeNode pointNode = node->getFirstChildNode("logic");
	while(pointNode.isValid())
	{
		MoveActionLogic point;
		point.takeNode(&pointNode);
		indexs.push_back(point);
		pointNode = pointNode.getNextNode("logic");
	}
}
void PrePathDecDirs::takeNode(script::tixmlCodeNode *node)
{
	name = node->getAttr("name");
	script::tixmlCodeNode pathNode = node->getFirstChildNode("path");
	while(pathNode.isValid())
	{
		PrePathDec dec;
		dec.takeNode(&pathNode);
		paths.push_back(dec);
		pathNode = pathNode.getNextNode("path");
	}
}
/**
 * �������ļ��л�ȡ��Ϣ
 **/
void MutiMonster::takeNode(script::tixmlCodeNode *node)
{
	initNode(node);
}
void MutiMonster::initNode(script::tixmlCodeNode *node)
{
	// ������϶���
	script::tixmlCodeNode conbinesNode = node->getFirstChildNode("conbineactions");
	if (conbinesNode.isValid() && conbineactionmaps.empty())
	{
		script::tixmlCodeNode actionsNode = conbinesNode.getFirstChildNode("actions");
		while(actionsNode.isValid())
		{
			unsigned int actionsName = actionsNode.getInt("name");
			script::tixmlCodeNode actionNode = actionsNode.getFirstChildNode("action");
			COBINE_ACTIONS actions_vec;
			while(actionNode.isValid())
			{
				CartoonConbineAction rpgAction;
				rpgAction.takeNode(&actionNode);
				actions_vec.push_back(rpgAction);
				actionNode = actionNode.getNextNode("action");
			}
			conbineactionmaps[actionsName] = actions_vec;
			actionsNode = actionsNode.getNextNode("actions");
		}
	}
	script::tixmlCodeNode actionPriorityNode = node->getFirstChildNode("actionpriority");
	if (actionPriorityNode.isValid())
	{
		script::tixmlCodeNode priorityNode = actionPriorityNode.getFirstChildNode("priority");
		while (priorityNode.isValid())
		{
			std::string name = priorityNode.getAttr("name");
			int value = priorityNode.getInt("poolid");
			priorityMap[name] = value;

			std::string actionName = priorityNode.getAttr("name");
			unsigned int id = priorityNode.getInt("actionid");
			ActionPool::actionsMap[actionName] = id;

			priorityNode = priorityNode.getNextNode("priority");
		}
	}
	script::tixmlCodeNode actionPoolsNode = node->getFirstChildNode("actionpools");
	if (actionPoolsNode.isValid())
	{
		script::tixmlCodeNode poolNode = actionPoolsNode.getFirstChildNode("pool");
		while (poolNode.isValid())
		{
			int id = poolNode.getInt("id");
			std::string typeStr = poolNode.getAttr("type");
			if (id >= actionPools.size()) actionPools.resize(id + 1);
			if (typeStr == "always")
				actionPools[id].actionType = ActionPool::ALWAYS_ACTION;
			if (typeStr == "single")
				actionPools[id].actionType = ActionPool::SINGLE_ACTION;
			if (typeStr == "conbine")
				actionPools[id].actionType = ActionPool::CONBINE_ACTION;
			if (typeStr == "replace")
				actionPools[id].actionType = ActionPool::REPLACE_ACTION;
			poolNode = poolNode.getNextNode("pool");
		}

	}
	// ���ض������ֶ�Ӧ��ID
	script::tixmlCodeNode actionNameNode = node->getFirstChildNode("actionnames");
	if (actionNameNode.isValid())
	{
		script::tixmlCodeNode actionNode = actionNameNode.getFirstChildNode("action");
		while (actionNode.isValid())
		{
			std::string actionName = actionNode.getAttr("name");
			unsigned int id = actionNode.getInt("id");
			ActionPool::actionsMap[actionName] = id;
			actionNode = actionNode.getNextNode("action");
		}
	}
	script::tixmlCodeNode myindexsNode = node->getFirstChildNode("myindexs");
	if (myindexsNode.isValid())
	{
		script::tixmlCodeNode indexNode = myindexsNode.getFirstChildNode("index");
		while (indexNode.isValid())
		{
			GridIndex index;
			index.x = indexNode.getInt("x");
			index.y = indexNode.getInt("y");
			myindexs.push_back(index); // �Լ�ռ�ݵĸ�����
			indexNode = indexNode.getNextNode("index");
		}
	}
	script::tixmlCodeNode myRectNode = node->getFirstChildNode("rect");
	if (myRectNode.isValid())
	{
		offset.x = myRectNode.getInt("x");
		offset.y = myRectNode.getInt("y");
		size = CCSizeMake(myRectNode.getInt("w"),myRectNode.getInt("h"));
	}
	script::tixmlCodeNode prePathNode = node->getFirstChildNode("prepaths");
	while (prePathNode.isValid())
	{
		PrePathDecDirs prePath;
		prePath.takeNode(&prePathNode);
		prePaths[prePath.name] = prePath;
		prePathNode = prePathNode.getNextNode("prepaths");
	}
	script::tixmlCodeNode idleNode = node->getFirstChildNode("idleaction");
	if (idleNode.isValid())
	{
		idleLogic.takeNode(&idleNode);
	}
}
void MutiMonster::doAction()
{
	int step =0;
	for (ACTIONPOOLS_ITER iter = actionPools.begin(); iter != actionPools.end();++iter,++step)
	{
		unsigned int actionId = iter->getAction();
		if (actionId != 0)
		{
			CartoonInfo *cartoonInfo = makeMyCartoon(actionId,dir);
			if (cartoonInfo && cartoonInfo->isValid())
			{
				nowActionName = actionId;
				iter->popAction();
				cartoonInfo->actionTag = step;
				putMyCartoon(cartoonInfo);
				return ;
			}
			iter->popAction();
		}
	}
	// ִ��һ���ջص�
	CCSprite::runAction(CCSequence::create(CCDelayTime::create(0.5),
					CCCallFunc::create(this, callfunc_selector(MutiMonster::nextStep)),NULL));
	
}

CartoonInfo * MutiMonster::makeMyCartoon(const unsigned int &name,int dir)
{
	CONBINEACTIONMAPS_ITER iter = conbineactionmaps.find(name);
	if (iter != conbineactionmaps.end())
	{
		COBINE_ACTIONS& actions = iter->second;
		CartoonInfo *root = NULL;
		CartoonInfo * temp = NULL;
		for (COBINE_ACTIONS::iterator pos = actions.begin(); pos != actions.end();++pos)
		{
			if (temp)
			{
				temp->nextCartoon = pos->getCartoonInfo(dir);
				temp = temp->nextCartoon;
				temp->nextConbineType = pos->nextType;
			}
			else if (!root)
			{
				root = pos->getCartoonInfo(dir);
				temp = root;
				temp->nextConbineType = pos->nextType;
				continue;
			}
			else
			{
				break;
			}
		}
		return root;
	}
	return NULL;
}
bool MutiMonster::isMoving()
{
	return !movePath.empty();
}
/**
 * ���ܵȿ��Խ�������Ϊ��
 */
void MutiMonster::putMyCartoon(CartoonInfo *info)
{
	if (!info) return;
	 //������
	if (isMoving())
	{
		CCPoint dest = getLocationByIndex(movePath.front());
		movePath.pop_front();
		runAction(this->getParent(),info,dest,getNowTarget());
	}
	else
	{
		runAction(this->getParent(),info,ccp(-1,-1),getNowTarget());
	}
}

// �����ƶ���
void MutiMonster::moveToUseAstar(const GridIndex &point)
{
		//ʹ��Astar �ƶ�
	GridIndex nextIndex;
#ifdef _SMALL_RECT
	if (map->getNextPosition(getNowIndex(),point,nextIndex))
#else
	if (map->getNextPosition(getNowIndex(),point,nextIndex,uniqueSerachId))
#endif
	{
		nowLocationIndex = getNowIndex();
#ifdef _SMALL_RECT
		maybeLocationIndex = nextIndex;
		map->setBlock(maybeLocationIndex,GridIndex::MONSTER_BLOCK);
		map->setBlock(nowLocationIndex,GridIndex::MONSTER_BLOCK);
		this->needClearBlocks.push_back(nowLocationIndex);
		this->needClearBlocks.push_back(maybeLocationIndex);
#else
		clearMyBlocks(nowLocationIndex);
		setMyBlocks(nextIndex);
#endif	
		movePath.push_back(nextIndex);
		tryAction("move");
	}
}
void MutiMonster::setMyBlocks(const GridIndex &point)
{
	for (int i = 0; i < myindexs.size();i++)
	{
		GridIndex temp = myindexs[i];
		temp.x += point.x;
		temp.y += point.y;
		map->setBlock(temp,uniqueSerachId);
	}
}
void MutiMonster::clearMyBlocks(const GridIndex &point)
{
	for (int i = 0; i < myindexs.size();i++)
	{
		GridIndex temp = myindexs[i];
		temp.x += point.x;
		temp.y += point.y;
		map->clearBlock(temp,uniqueSerachId);
	}
}
void MutiMonster::tryMoveUseAstr(const GridIndex &index)
{
	nowAstarDestination = index;
}
void MutiMonster::clearAstar()
{
	nowAstarDestination.x = -1;
	nowAstarDestination.y = -1;
}
void MutiMonster::jumpTo()
{
	this->getPreparePath("jump",this->getStartMyIndex());
}
void MutiMonster::doControl(const std::string &name)
{
	this->getPreparePath(name,this->getStartMyIndex());
}
void MutiMonster::moveLeft()
{
	this->getPreparePath("left",this->getStartMyIndex());
}
GridIndex MutiMonster::getStartMyIndex()
{
	GridIndex index = getNowIndex();
	index.x += myindexs.size()?myindexs.at(0).x:0;
	index.y += myindexs.size()?myindexs.at(0).y:0;
	return index;
}
bool MutiMonster::checkIn(const CCPoint &point)
{
	CCPoint pos = this->convertToNodeSpace(point);
	float width = 64;
	float height = 64;
	float x = offset.x-32;
	float y = offset.y-32;
	CCRect rect = CCRectMake(x,y,width,height);
	return rect.containsPoint(pos);
}

/**
 * ���ݵ��ȡ��ͼ��ʵ������λ��
 */
CCPoint MutiMonster::getLocationByIndex(const GridIndex &index)
{
	if (!map) return ccp(-1,-1);
	return map->getLocationByIndex(index);
}
/**
 * ��ȡ��ǰ������
 */
GridIndex MutiMonster::getNowIndex()
{
	GridIndex index =  map->getIndexByLocation(this->getPosition());
	return index;
}

/**
 * ��鵱ǰ��Ϊ���Ƿ�����Լ�
 */
bool MutiMonster::isNowAction(const std::string &name)
{
	unsigned int id = ActionPool::getActionIdByName(name);
	if (id & nowActionName) return true;
	return false;
}
MutiMonster * MutiMonster::getNowTarget()
{
	return stub.getTarget();
}

void MutiMonster::setPosition(const GridIndex &point)
{
	CCSprite::setPosition(map->getLocationByIndex(point));
#ifndef _SMALL_RECT
	setMyBlocks(point);
#endif
}
void MutiMonster::setPosition(const CCPoint &point)
{
	CCPoint dest = point;//map->getLocationByIndex(map->getIndexByLocation(point));
	CCSprite::setPosition(dest);
	map->showGrids();
}

void MutiMonster::freshBlock()
{
	for (unsigned int index = 0; index < this->needClearBlocks.size();index++)
	{
		map->clearBlock(this->needClearBlocks[index],GridIndex::MONSTER_BLOCK);
	}
	this->needClearBlocks.clear();
	nowLocationIndex = getNowIndex();
	map->setBlock(nowLocationIndex,GridIndex::MONSTER_BLOCK);
	this->needClearBlocks.push_back(nowLocationIndex);
}

bool MutiMonster::checkNotDirCollide(const GridIndex &nextIndex,std::vector<GridIndex> &dirindexs,int index)
{
	std::vector<GridIndex> tempindexs;
	for (std::vector<GridIndex>::iterator iter = dirindexs.begin(); iter != dirindexs.end();++iter)
	{
		GridIndex temp;
		temp.x = nextIndex.x + iter->x;
		temp.y = nextIndex.y + iter->y;
		tempindexs.push_back(temp);
	}
	if (map->checkCollide(nextIndex,&tempindexs,index)) return false;
	return true;
}

/**
* ��ȡ��Ҫ�½��ĵ������
*/
GridIndex MutiMonster::getPreDownIndex()
{
	GridIndex start = this->getStartMyIndex();
	return GridIndex(start.x,start.y-1);
}
/**
* ��ȡ��point Ϊ��ʼ��·���б� ������ǰ·��
*/
void MutiMonster::getPreparePath(const std::string &name,const GridIndex &point)
{
	PRE_PATHS_ITER iter = prePaths.find(name);
	if (iter != prePaths.end() && iter->second.paths.size())
	{
		logics = *iter->second.getLogic(0);
	}
}

int MutiMonster::calcDistance(MutiMonster *monster)
{
	if (!monster) return -1;
	GridIndex nowIndex = this->getNowIndex();
	GridIndex destIndex = monster->getNowIndex();
	
	return abs(nowIndex.x - destIndex.x) + abs(nowIndex.y - destIndex.y);
}
//TODO AI ���¼����� ��Ҫ�Ƿ���Ŀ�� �鿴Ŀ��״̬
struct stSeachTargets:stExecEachMonster{
	void exec(MutiMonster *temp)
	{
		MutiMonster * target = temp;
		if (target != this->monster)
		{
			if (monster->stub.getTargetCount() < monster->data.maxTargets)
			{
				monster->stub.addTarget(target);
				theAILib.execEvent(monster->monsterAIID,monster->getStub(),MutiAI::TARGET_ENTER);
			}
		}
	}
	stSeachTargets(MutiMonster *monster):monster(monster)
	{
	
	}
	MutiMonster *monster;
};
void MutiMonster::doCheckTargets()
{
	theAILib.execEvent(this->monsterAIID,getStub(),MutiAI::IDLE_ACTION); // ����Ƭִ��
	// �Ȳ�ѯMutiMonster �Ƿ���Ч
	for (MutiAIStub::TARGETPOOL_ITER iter = stub.targetPool.begin(); iter != stub.targetPool.end();++iter)
	{
		if (!iter->isValid()) // ��ǰ��Ч��
		{
			iter->monster = NULL;
			iter->uniqueId = -1;
		}
		// ����Ƿ�Զ����
		if (iter->monster && iter->monster->calcDistance(this) > data.eyeshort)
		{
			stub.tempRef = *iter;
			theAILib.execEvent(this->monsterAIID,getStub(),MutiAI::HAD_TARGET_LEAVE);
		}
	}
	if (stub.getTargetCount() < data.maxTargets)
	{
		stSeachTargets exec(this);
		// �����ö���
		map->execAllMonster(&exec);
	}
	
	if (stub.getTargetCount() && !stub.checkNotify(MutiAI::HAD_TARGET))
	{
		theAILib.execEvent(this->monsterAIID,getStub(),MutiAI::HAD_TARGET); // ������״̬
		stub.setNotify(MutiAI::HAD_TARGET);
	}
	else
	{
		stub.resetNotify(MutiAI::HAD_TARGET); // ������״̬����
	}
	MutiMonsterRefrence *ref = stub.getTargetRef();
	if (ref && ref->checkTimeOut(data.maxLastAttackTime) && !ref->checkNotify(MutiAI::TOUCH_TIME_OUT))
	{
		theAILib.execEvent(this->monsterAIID,getStub(),MutiAI::TOUCH_TIME_OUT); // �Ե�ǰ����е����,ֱ���ⲿ���� ���� ��ǰ��������
		ref->setNotify(MutiAI::TOUCH_TIME_OUT);
	}
	int target = this->calcDistance(stub.getTarget());
	if (target > data.eyeshort)
	{
		stub.removeTarget();
		theAILib.execEvent(this->monsterAIID,getStub(),MutiAI::TARGET_LEAVE); // ������Ŀ���뿪��
	}
	// ����Ƿ��ڹ�����Χ��
	if (ref)
	{
		if (target >= 0 && target < data.attackdistance && !ref->checkNotify(MutiAI::MEET_TARGET))
		{
			theAILib.execEvent(this->monsterAIID,getStub(),MutiAI::MEET_TARGET); // ���Թ����Ķ�����
			ref->setNotify(MutiAI::MEET_TARGET);
		}
		else
		{
			ref->resetNotify(MutiAI::MEET_TARGET); // �����뿪������Χ��
		}
	}
}
struct stExecEachGrid:public stExecEach
{
	virtual void exec(const GridIndex& index)
	{
		int *value = grids->getObjectByIndex(index);
		if (value && 0 == *value )
		{
			indexs.push_back(index);
		}
	}
	GridIndex getIndex()
	{
		if (indexs.size())
			return indexs.at(CCRANDOM_0_1() * indexs.size());
		return GridIndex(-1,-1);
	}
	std::vector<GridIndex> indexs;
	AStarSeachInHexagonGrids<int>* grids;
	stExecEachGrid(AStarSeachInHexagonGrids<int> *grids):grids(grids){
	
	}
};
/**
 * ��ȡ��Χ���һ����Ч��
 */
GridIndex MutiMonster::getAroundRandomPoint()
{
	stExecEachGrid exec(this->map->getGrids());
	this->map->getGrids()->exec(this->getNowIndex(),SEARCH_TYPE("arround"),&exec);
	return exec.getIndex();
}

GridIndex MutiMonster::getRandomPointInRect()//��ȡ�����������
{
	stExecEachGrid exec(this->map->getGrids());
	this->map->getGrids()->exec(this->getNowIndex(),SEARCH_TYPE("rect"),&exec);
	return exec.getIndex();
}

void MutiMonster::doActionEndTrrigeEvent()
{
	if (stub.getTargetCount() && !stub.checkNotify(MutiAI::ACTION_END))
	{
		theAILib.execEvent(this->monsterAIID,getStub(),MutiAI::ACTION_END); // ��������
		stub.setNotify(MutiAI::ACTION_END);
	}
}
NS_CC_END