#include "Cartoon.h"
NS_CC_BEGIN

/**
* ����������Ϣ ����autorelease
*/
CartoonInfo* CartoonInfo::create(const CartoonInfo &info)
{
	CartoonInfo * pRet = new CartoonInfo();
	*pRet = info;
    pRet->autorelease();
    return pRet;
}
CartoonInfo* CartoonInfo::create()
{
	CartoonInfo * pRet = new CartoonInfo();
    pRet->autorelease();
    return pRet;
}
/**
 * ���ݶ�������������
 */
CCFiniteTimeAction * CartoonInfo::createAction(CCNode * self,CCNode *parent,const cocos2d::CCPoint &point,CCNode *target,stCollideTargetCallback * callback)
{
	// �ж����ƶ����Ǿ�ֹ
	CCFiniteTimeAction *action = NULL;
	CCAnimation * animation = NULL;
	if (frameType == FOLLOW_ANIMATIONS)
	{
		FollowAnimationAction * followAction = FollowAnimationAction::create(target,needTime);;
		followAction->isTempTarget = true;
		cartoonType = OTHER;
		followAction->callback = callback;
		animation = createAnimation(needTime);
    
		action = followAction;
	}
	else if (frameType == FOLLOW_FRAMES)
	{
		CartoonFollowAction * followAction = CartoonFollowAction::create(*this,target);
		action = followAction;
		followAction->callback = callback;
		followAction->isTempTarget = true;
		cartoonType = OTHER;
	}
	else if (!point.equals(ccp(-1,-1)) && frameType != TIME_FRAMES)
	{
		// �ƶ�����
		CartoonMoveAction * moveAction = CartoonMoveAction::create(*this,point);
		action = moveAction;
		if (cartoonType == OTHER)
		{
			moveAction->isTempTarget = true;
		}
	}
	else
	{
		// ��ֹ����
		CartoonAction* cartoonAction = CartoonAction::create(*this);
		action = cartoonAction;
		if (cartoonType == OTHER)
		{
			cartoonAction->isTempTarget = true;
		}
	}
	if (!action) return NULL;

	switch(cartoonType)
	{
		case OTHER:
		{
			CCSprite * temp = CCSprite::create();
			if (temp)
			{
				parent->addChild(temp);
				if (animation)
				{
					temp->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
				}
				//temp->setAnchorPoint(ccp(0,0));
				temp->setPosition(self->getPosition());
				action->setTarget(temp);
			}
		}break;
	}
	return action;
}
/**
 * ������һ����������
 */
CartoonInfo* CartoonInfo::addNextCartoonInfo(int nextConbineType,const CartoonInfo& info)
{
	this->nextConbineType = nextConbineType;
	this->nextCartoon = CartoonInfo::create(info);
	return nextCartoon;
}
/**
 * �ͷ�����
 */
void CartoonInfo::release()
{
	for (std::vector<CCSpriteFrame*>::iterator iter = frames.begin(); iter != frames.end();++iter)
	{
		if (*iter)
		{
			(*iter)->release();
		}
	}
}
CCAnimation * CartoonInfo::createAnimation(float costtime)
{
	CCAnimation* animation = CCAnimation::create();
	for (int i = 0; i < frames.size(); i++)
	{
		animation->addSpriteFrame(frames[i]);
	}
	if (frames.empty()) return NULL;
	if (!costtime)
		animation->setDelayPerUnit(needTime / frames.size());
	else
		animation->setDelayPerUnit(costtime / frames.size());
	animation->setRestoreOriginalFrame(true);
	return animation;
}
void CartoonMoveAction::update(float time)
{
	if (m_pTarget)
	{
		m_pTarget->setPosition(ccp(m_startPosition.x + m_delta.x * time,
			m_startPosition.y + m_delta.y * time));
		CCPoint nowPoint = m_pTarget->getPosition();
		float dw = ccpDistance(nowPoint,m_startPosition);
		float da = ccpDistance(m_endPosition,m_startPosition);
		int frameSize = this->cartoonInfo.frames.size();
		int nowFrameId = frameSize - 1;
		if (da) nowFrameId = frameSize * (dw / da);
		if (nowFrameId >= 0 && nowFrameId < frameSize)
		{
			CCSpriteFrame *frame = this->cartoonInfo.frames[nowFrameId];
			if (frame)
			{
				CCSprite *sprite = static_cast<CCSprite*>(m_pTarget);
				if (sprite)
					sprite->setDisplayFrame(frame);
			}
		}
	}
}
	
CartoonMoveAction* CartoonMoveAction::create(const CartoonInfo &cartoonInfo, const CCPoint& position)
{
	CartoonMoveAction *pMove = new CartoonMoveAction();
	pMove->init(cartoonInfo,position);
    pMove->autorelease();
    return pMove;
}
/**
* ��ʼ��cartoon �ƶ���Ϊ
*/
bool CartoonMoveAction::init(const CartoonInfo &cartoonInfo, const CCPoint& position)
{
	this->cartoonInfo = cartoonInfo;
	initWithDuration(cartoonInfo.needTime, position);
	return true;
}

void CartoonMoveAction::stop(void)
{
	CCNode *tempTarget = m_pTarget; 
	CCMoveTo::stop();
	cartoonInfo.release();
	if (isTempTarget)
	{
		tempTarget->removeFromParentAndCleanup(true);
	}
}
CartoonFollowAction* CartoonFollowAction::create(const CartoonInfo &cartoonInfo,CCNode *target)
{
	CartoonFollowAction *pMoveTo = new CartoonFollowAction();
	pMoveTo->initWithDuration(cartoonInfo.needTime, ccp(0,0));
    pMoveTo->autorelease();
	pMoveTo->cartoonInfo = cartoonInfo;
	pMoveTo->initWithAnimation(pMoveTo->cartoonInfo.createAnimation());
	if (target)
	{
		pMoveTo->target = target;
		target->retain();
	}
	return pMoveTo;
}
bool CartoonFollowAction::initWithAnimation(CCAnimation *pAnimation)
{
	float singleDuration = pAnimation->getDuration();
	pAnimation->retain();
    if ( CCActionInterval::initWithDuration(singleDuration * pAnimation->getLoops() ) ) 
    {
        m_nNextFrame = 0;
        this->m_pAnimation = pAnimation;
        m_pOrigFrame = NULL;
        m_uExecutedLoops = 0;

        m_pSplitTimes.resize(pAnimation->getFrames()->count());

        float accumUnitsOfTime = 0;
        float newUnitOfTimeValue = singleDuration / pAnimation->getTotalDelayUnits();

        CCArray* pFrames = pAnimation->getFrames();
        CCARRAY_VERIFY_TYPE(pFrames, CCAnimationFrame*);

        CCObject* pObj = NULL;
        CCARRAY_FOREACH(pFrames, pObj)
        {
            CCAnimationFrame* frame = (CCAnimationFrame*)pObj;
            float value = (accumUnitsOfTime * newUnitOfTimeValue) / singleDuration;
            accumUnitsOfTime += frame->getDelayUnits();
            m_pSplitTimes.push_back(value);
        }    
        return true;
    }
    return false;
}
void CartoonFollowAction::startWithTarget(CCNode *pTarget)
{
	CCActionInterval::startWithTarget(pTarget);
    CCSprite *pSprite = (CCSprite*)(pTarget);
	m_startPosition = pTarget->getPosition();
    CC_SAFE_RELEASE(m_pOrigFrame);

    if (m_pAnimation->getRestoreOriginalFrame())
    {
        m_pOrigFrame = pSprite->displayFrame();
        m_pOrigFrame->retain();
    }
    m_nNextFrame = 0;
    m_uExecutedLoops = 0;
}
/**
* ����
*/
void CartoonFollowAction::update(float t)
{
	if (target && target->retainCount() > 1)
	{
		m_endPosition = target->getPosition();
		m_delta = ccpSub(m_endPosition, m_startPosition);
	}
	if (m_pTarget)
	{
		m_pTarget->setPosition(ccp(m_startPosition.x + m_delta.x * t,
			m_startPosition.y + m_delta.y * t));
		// ����ʱ�����֡��
		updateAnimate(t);
	}
}
void CartoonFollowAction::updateAnimate(float t)
{
	// if t==1, ignore. Animation should finish with t==1
    if( t < 1.0f ) {
        t *= m_pAnimation->getLoops();

        // new loop?  If so, reset frame counter
        unsigned int loopNumber = (unsigned int)t;
        if( loopNumber > m_uExecutedLoops ) {
            m_nNextFrame = 0;
            m_uExecutedLoops++;
        }

        // new t for animations
        t = fmodf(t, 1.0f);
    }

    CCArray* frames = m_pAnimation->getFrames();
    unsigned int numberOfFrames = frames->count();
    CCSpriteFrame *frameToDisplay = NULL;

    for( unsigned int i=m_nNextFrame; i < numberOfFrames; i++ ) {
        float splitTime = m_pSplitTimes.at(i);

        if( splitTime <= t ) {
            CCAnimationFrame* frame = (CCAnimationFrame*)frames->objectAtIndex(i);
            frameToDisplay = frame->getSpriteFrame();
            ((CCSprite*)m_pTarget)->setDisplayFrame(frameToDisplay);
            m_nNextFrame = i+1;

            break;
        }
    }
}
/**
* Ϊʹ������������
*/
void CartoonFollowAction::stop(void)
{
	CCNode *tempTarget = m_pTarget;
	if (callback && target)
	{
		callback->exec(target);
	}
	if (target)
		target->release();
	cartoonInfo.release();
	
	if (m_pAnimation->getRestoreOriginalFrame() && m_pTarget)
    {
        ((CCSprite*)(m_pTarget))->setDisplayFrame(m_pOrigFrame);
    }

    CCActionInterval::stop();
	
	if (isTempTarget)
	{
		tempTarget->removeFromParentAndCleanup(true);
	}
	m_pAnimation->release();
}

FollowAnimationAction* FollowAnimationAction::create(CCNode *target,float needTime)
{
    FollowAnimationAction *pMoveTo = new FollowAnimationAction();
	pMoveTo->initWithDuration(needTime, ccp(0,0));
    pMoveTo->autorelease();
	if (target)
	{
		pMoveTo->followTarget = target;
		target->retain();
	}
	return pMoveTo;
}
    
void FollowAnimationAction::update(float t)
{
    if (followTarget && followTarget->retainCount() > 1)
	{
		m_endPosition = followTarget->getPosition();
		m_delta = ccpSub(m_endPosition, m_startPosition);
	}
	if (m_pTarget)
	{
		m_pTarget->setPosition(ccp(m_startPosition.x + m_delta.x * t,
                                   m_startPosition.y + m_delta.y * t));
	}
}
    
void FollowAnimationAction::stop(void)
{
	if (callback && followTarget)
	{
		callback->exec(followTarget);
	}
    CCNode *tempTarget = m_pTarget;
	if (followTarget)
		followTarget->release();
	
    CCActionInterval::stop();
	
	if (isTempTarget)
	{
		tempTarget->removeFromParentAndCleanup(true);
	}
}
    
void FollowAnimationAction::startWithTarget(CCNode *pTarget)
{
    CCMoveTo::startWithTarget(pTarget);
}

/**
 * ������ͨ����
 */
 CartoonAction* CartoonAction::create(const CartoonInfo &cartoonInfo)
 {
	CartoonAction *pAnimate = new CartoonAction();
	if (pAnimate->init(cartoonInfo))
	{
		pAnimate->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pAnimate);
	}
	return pAnimate;
 
}

CartoonAction* CartoonAction::create(CCAnimation *animation)
{
	CartoonAction *pAnimate = new CartoonAction();
	if (pAnimate->init(animation))
	{
		pAnimate->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pAnimate);
	}
	return pAnimate;
}
bool CartoonAction::init(CCAnimation *animation)
{
	 CCAnimation * pAnimation = animation;
	 if (!pAnimation) return false;
	 initWithAnimation(pAnimation);
	 return true;
}
/**
 * ��ʼ������
 */
 bool CartoonAction::init(const CartoonInfo &cartoonInfo)
 {
	 CartoonInfo c = cartoonInfo;
	 CCAnimation * pAnimation = c.createAnimation();
	 if (!pAnimation) return false;
	 initWithAnimation(pAnimation);
	 c.release();
	 return true;
 }
 /**
 * �ͷ��Լ���ռ�е�֡
 */
void CartoonAction::stop(void)
{
	CCNode *tempTarget = m_pTarget;
	CCAnimate::stop();
	if (isTempTarget)
	{
		tempTarget->removeFromParentAndCleanup(true);
	}
}
/** �������ı�
 * Ŀ��� position
 * ��̬����Action
 */
void Cartoon::runSelfAction(const CartoonInfo &info,const CCPoint &position)
{
	if (position.x != 0 && position.y != 0)
	{
		// �����ƶ�����
		CartoonMoveAction *action = CartoonMoveAction::create(info,position);
		if (action)
		{
			CCAction *seqaction = CCSequence::create(action,
					CCCallFunc::create(this, callfunc_selector(Cartoon::doCartoonEnd)),NULL);
			if (seqaction)
				sprite->runAction(seqaction);
		}
	}
	else
	{
		// ���������� �൱�ھ�ֹ����
		CartoonAction *action = CartoonAction::create(info);
		CCFiniteTimeAction *seqaction = CCSequence::create(action,
					CCCallFunc::create(this, callfunc_selector(Cartoon::doCartoonEnd)),NULL);
		if (seqaction)
			sprite->runAction(seqaction);
	}
}

/**
 * ����������Ķ��� ָ��Ŀ�ĵ�
 **/
void Cartoon::runFlyAction(CCNode* parent,const CartoonInfo &info,const cocos2d::CCPoint &point)
{
	CCSprite *tempSprite = CCSprite::create();
	parent->addChild(tempSprite);
	if (point.x != 0 && point.y != 0)
	{
		// �����ƶ�����
		CartoonMoveAction *moveAction = CartoonMoveAction::create(info,point);
		if (moveAction)
		{
			CCAction *action = CCSequence::create(moveAction,
			CCCallFuncND::create(this, callfuncND_selector(Cartoon::flyEnd), (void*)tempSprite),NULL);
	
			tempSprite->runAction(action);
		}
	}
	else
	{
		// ���������� �൱��ͷ����Ч
		CartoonAction *moveAction = CartoonAction::create(info);
		if (moveAction)
		{
			CCAction *action = CCSequence::create(moveAction,
			CCCallFuncND::create(this, callfuncND_selector(Cartoon::flyEnd), (void*)tempSprite),NULL);
	
			tempSprite->runAction(action);
		}
	}
}
/**
 * �������涯��
 * �����������ʧ
 */
void Cartoon::runFllowAction(CCNode *parent,const CartoonInfo&info,CCNode *target)
{
	CartoonFollowAction * moveAction = CartoonFollowAction::create(info,target);
	if (moveAction)
	{
		CCSprite *tempSprite = CCSprite::create();
		parent->addChild(tempSprite);
		CCAction *action = CCSequence::create(moveAction,
			CCCallFuncND::create(this, callfuncND_selector(Cartoon::flyEnd), (void*)tempSprite),NULL);
	
		tempSprite->runAction(action);
	}
}
void Cartoon::runState(CCNode *parent,CartoonInfo &info,CCNode *target)
{
    CCAnimation * animation = info.createAnimation();
    CCSprite *tempSprite = CCSprite::create();
    parent->addChild(tempSprite);
    tempSprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
}
void Cartoon::runMoveState(CCNode *parent,CartoonInfo &info,CCNode * target,float aniTime)
{
    FollowAnimationAction * follow = FollowAnimationAction::create(target, info.needTime);
    CCSprite *tempSprite = sprite;	
//	if (info.cartoonType == CartoonInfo::OTHER)
	{
		tempSprite = CCSprite::create();
		parent->addChild(tempSprite);
	}
	if (!aniTime) aniTime = info.needTime;
    CCAnimation * animation = info.createAnimation(aniTime);
    tempSprite->setPosition(sprite->getPosition());
    
    tempSprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    CCAction *action = CCSequence::create(follow,
                                          CCCallFuncND::create(this, callfuncND_selector(Cartoon::flyEnd), (void*)tempSprite),NULL);
    tempSprite->runAction(action);
}
void Cartoon::runMoveAction(CCNode *parent,CartoonInfo &info,float animationTime,const CCPoint &point)
{
	CCMoveTo *moveTo = CCMoveTo::create(info.needTime,point);
	CCSprite *tempSprite = sprite;	
//	if (info.cartoonType == CartoonInfo::OTHER)
	{
	//	tempSprite = CCSprite::create();
	//	parent->addChild(tempSprite);
	}
	if (!animationTime) animationTime = info.needTime;
	int step = info.needTime / animationTime;
	animationTime = info.needTime / step;
	CCAnimation * animation = info.createAnimation(animationTime);
	CCFiniteTimeAction *action = CCSpawn::create(CCRepeat::create(CCAnimate::create(animation),step),moveTo,NULL);
	CCFiniteTimeAction *timeAction = CCSequence::create(action,
                                         CCCallFunc::create(this, callfunc_selector(Cartoon::doCartoonEnd)),NULL);
    tempSprite->runAction(timeAction);
}
/**
 * ��϶����Ĳ��� ��ʽ����
 * \param parent fly ���ؽڵ�
 * \param info ������Ϣ
 * \param point Ŀ�ĵ�
 * \param target �������
 * CartoonInfo::create()->addNextCartoonInfo(CartoonInfo::TOGETHER,info1)->addNextCartoonInfo(CartoonInfo::TOGETHER,info2);
 */
void Cartoon::runAction(CCNode *parent,const CartoonInfo*info,const cocos2d::CCPoint &point,CCNode *target,stCollideTargetCallback * callback)
{
	if (!info) return;
	CartoonInfo * root =(CartoonInfo*) info;
	int nextConbine = root->nextConbineType;
	CCFiniteTimeAction *preAction = NULL;
	CCFiniteTimeAction *nowAction = NULL;
	while(root)
	{
		nowAction = root->createAction(sprite,parent,point,target,callback);
		if (!preAction)
		{
			preAction = CCSequence::create(nowAction,NULL);
		}
		else
		{
			switch(nextConbine)
			{
				case CartoonInfo::SEQUENCE:
				{
					preAction = CCSequence::create(preAction,nowAction,NULL);
				}break;
				case CartoonInfo::TOGETHER:
				{
					preAction = CCSpawn::create(preAction,nowAction,NULL);
				}break;
			}
		}
		nextConbine = root->nextConbineType;
		root = root->nextCartoon;
	}
	if (preAction)
	{
		CCFiniteTimeAction *seqaction = CCSequence::create(preAction,/*CCDelayTime::create(0.5),*/
					CCCallFunc::create(this, callfunc_selector(Cartoon::doCartoonEnd)),NULL);
		
		if (seqaction)
		{
			seqaction->setTag(info->actionTag);
			sprite->runAction(seqaction);
		}
	}
}
void Cartoon::flyEnd(CCNode *pSender,void *arg)
{
	if (pSender)
	{
		pSender->removeFromParentAndCleanup(true);
	}
//	doCartoonEnd();
}
void Cartoon::doCartoonEnd()
{
	nextStep();
	this->putConbineAction();
}

 /**
* ��ĳ����ΪΪ��ʼִ��״̬
*/
void Cartoon::start(int id)
{
	tryNextAction(id);
	CartoonInfo *cartoonInfo = makeCartoon(id);
	if (cartoonInfo)
		putCartoon(cartoonInfo);
}
void Cartoon::tryNextAction(int id)
{
	actionType = id;
}
/**
* ���е�ִ����Ϊ
*/
void Cartoon::tryConbineAction(int type)
{
	actionType |= type;
}

/**
* ��鵱ǰ��Ϊ
*/
bool Cartoon::isNowAction(int actionType)
{
	if (oldActionType == -1) return false;
	return (oldActionType & actionType);
}
/**
* ��һ��������ȥ����ϵ
*/
void Cartoon::clearAction(int type)
{
	actionType &= ~type;
}
/**
* �������ȼ� ������Ӧ�Ķ���
*/
void Cartoon::putConbineAction()
{

	for (int i = 0; i < 16;i++)
	{
		if (actionType & (1 << i))
		{
			CartoonInfo *cartoonInfo = makeCartoon(1<<i);
			if (cartoonInfo)
			{
				clearAction(1<<i);
				putCartoon(cartoonInfo);
				return ;
			}
		}
	}
	CartoonInfo *cartoonInfo = makeCartoon(1<<5);
	if (cartoonInfo)
	{
		clearAction(1<<5);
		putCartoon(cartoonInfo);
		return ;
	}
}

void Cartoon::setAction(int actionType)
{
	oldActionType = actionType;
}
CartoonInfo* Cartoon::makeCartoon(int actionType)
{
	oldActionType = actionType; 
	return v_makeCartoon(actionType);
}
void Cartoon::putCartoon(CartoonInfo *action)
{
	v_putCartoon(action);
}


/**
 * ��ȡ��֡
 */
bool CartoonDirAction::getFrames(std::vector<CCSpriteFrame *> &frames)
{
	for (std::vector<stFrameInfo>::iterator iter = this->frames.begin(); iter != this->frames.end();++iter)
	{
		
		CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage(iter->frameName.c_str());
		CCSpriteFrame *frame = iter->frame;
		if (texture && !iter->frame)
		{
			frame = CCSpriteFrame::frameWithTexture(texture,CCRectMake(0,0,texture->getContentSize().width,texture->getContentSize().height));
			frame->retain();
			frame->setOffset(iter->offset);
			iter->frame = frame;
		}
		if (frame)
		{
			frame->retain();
			frames.push_back(frame);
		}
	}
	return true;
}
void CartoonDirAction::takeNode(script::tixmlCodeNode *node)
{
	frameLoadType = node->getAttr("framestype");
	FramesName = node->getAttr("framenode");
		
	script::tixmlCodeNode frameNode = node->getFirstChildNode("frame");
	while(frameNode.isValid())
	{
		stFrameInfo info;
		info.frameName = frameNode.getAttr("name");
		info.offset.x = frameNode.getInt("offsetx");
		info.offset.y = frameNode.getInt("offsety");
		frames.push_back(info);
		frameNode = frameNode.getNextNode("frame");
	}
}
void CartoonConbineAction::takeNode(script::tixmlCodeNode *node)
{
	CartoonXmlAction::takeNode(node);
	std::string nextTypeStr = node->getAttr("nexttype");
	if (nextTypeStr == "conbine")
	{
		nextType = 1;
	}
	else
		nextType = 0;
}
/**
 * ��������
 */
CartoonInfo* CartoonConbineAction::getCartoonInfo(int dir)
{
	CartoonInfo *info = CartoonInfo::create();
	if (getFrames(dir,info->frames))
	{
		info->actionType = actionType;
		info->cartoonName = actionName;
		info->needTime = needTime;
		info->frameType = frameType;
		info->nextConbineType = this->nextType;
		info->cartoonType = cartoonType;
	}
	return info;
}
/**
 * ����ڵ�
 */
void CartoonXmlAction::takeNode(script::tixmlCodeNode *node)
{
	actionName = node->getAttr("name");
	node->getAttr("type",actionType);
	std::string frameTypeStr = node->getAttr("frametype");
	if (frameTypeStr == "follow")
	{
		this->frameType = CartoonInfo::FOLLOW_FRAMES;
	}
	else if (frameTypeStr == "times")
	{
		this->frameType = CartoonInfo::TIME_FRAMES;
	}
	else if (frameTypeStr == "followanimations")
	{
		this->frameType = CartoonInfo::FOLLOW_ANIMATIONS;
	}
	else 
	{
		this->frameType = CartoonInfo::MOVE_FRAMES;
	}
	std::string cartoonTypeStr = node->getAttr("cartoontype");
	if (cartoonTypeStr == "other")
	{
		this->cartoonType = CartoonInfo::OTHER;
	}
	else
	{
		this->cartoonType = CartoonInfo::SELF;
	}
	script::tixmlCodeNode dirNode = node->getFirstChildNode("dir");
	if(dirNode.isValid())
	{
		int dirId = 0;
		CartoonDirAction dirAction;
		dirNode.getAttr("id",dirId);
		dirAction.takeNode(&dirNode);
		dirActions[dirId] = dirAction;
	}
	node->getAttr("needtime",needTime);
	node->getAttr("actiontype",actionType);
}
/**
 * ��ȡ֡����
 * \param frames ֡���� 
 */
bool CartoonXmlAction::getFrames(int dir,std::vector<CCSpriteFrame *> &frames)
{
	DIRACTIONS_ITER iter = dirActions.find(dir);
	if (iter != dirActions.end())
	{
		if (iter->second.frameLoadType == "frames")
		{
			return iter->second.getFrames(frames);
		}
		if (iter->second.frameLoadType == "pack")
		{
			std::string &framesName = iter->second.FramesName;
		//	return PngPack::getMe().getFrames(framesName.c_str(),frames);
		}
	}
	return false;
}

NS_CC_END