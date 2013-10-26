#pragma once
#include "cocos2d.h"
NS_CC_BEGIN
/**
* \brief ����ƫ�Ƽ��������ֵ
*/
struct zAdjust
{
	int x;    /**< ������*/
	int y;    /**< ������*/
};
/**
* \brief ��������
*/
struct zPos
{
	int x;    /**< ������*/
	int y;    /**< ������*/
	/**
	* \brief ���캯��
	*
	*/
	zPos()
	{
		x = 0;
		y = 0;
	}
	/**
	* \brief ���캯��
	*
	*/
	zPos(const int x,const int y)
	{
		this->x = x;
		this->y = y;
	}
	/**
	* \brief �������캯��
	*
	*/
	zPos(const zPos &pos)
	{
		x = pos.x;
		y = pos.y;
	}
	/**
	* \brief ����+=�������
	*
	*/
	const zPos & operator+= (const zAdjust &pos)
	{
		x += pos.x;
		y += pos.y;
		return *this;
	}
	/**
	* \brief ����==�߼��������
	*
	*/
	const bool operator== (const zPos &pos) const
	{
		return (x == pos.x && y == pos.y);
	}
	
};

/**
* \brief A*Ѱ·�㷨ģ��
* ����step��ʾ������radius��ʾ�����뾶
*/
template <int step = 1,int radius = 12>
class zAStar
{

private:

	/**
	* \brief ·�������
	*/
	struct zPathPoint
	{
		/**
		* \brief ����
		*/
		zPos pos;
		/**
		* \brief ��ǰ����
		*/
		int cc;
		/**
		* \brief ·����һ�����ָ��
		*/
		zPathPoint *father;
	};

	/**
	* \brief ·��ͷ
	*/
	struct zPathQueue
	{
		/**
		* \brief ·���ڵ�ͷָ��
		*/
		zPathPoint *node;
		/**
		* \brief ·�����ľ���
		*/
		int cost;
		/**
		* \brief ���캯��
		* \param node ��ʼ����·���ڵ�ͷָ��
		* \param cost ��ǰ���ľ���
		*/
		zPathQueue(zPathPoint *node,int cost)
		{
			this->node = node;
			this->cost = cost;
		}
		/**
		* \brief �������캯��
		* \param queue ��������Դ����
		*/
		zPathQueue(const zPathQueue &queue)
		{
			node = queue.node;
			cost = queue.cost;
		}
		/**
		* \brief ��ֵ��������
		* \param queue ����ֵ��Դ����
		* \return ���ؽṹ������
		*/
		zPathQueue & operator= (const zPathQueue &queue)
		{
			node = queue.node;
			cost = queue.cost;
			return *this;
		}
	};

	/**
	* \brief ��������·��������
	*/
	typedef std::list<zPathQueue> zPathQueueHead;
	typedef typename zPathQueueHead::iterator iterator;
	typedef typename zPathQueueHead::reference reference;

	/**
	* \brief ���ۺ���
	* \param midPos �м���ʱ�����
	* \param endPos ���������
	* \return �����������֮��ľ���
	*/
	int judge(const zPos &midPos,const zPos &endPos)
	{
		int distance = abs((long)(midPos.x - endPos.x)) + abs((long)(midPos.y - endPos.y));
		return distance;
	}

	/**
	* \brief ����·������
	* \param queueHead ·������ͷ
	* \param pPoint ��·���ڵ���ӵ�·����
	* \param currentCost ·���Ĺ������
	*/
	void enter_queue(zPathQueueHead &queueHead,zPathPoint *pPoint,int currentCost)
	{
		zPathQueue pNew(pPoint,currentCost);
		if (!queueHead.empty())
		{
			for(iterator it = queueHead.begin(); it != queueHead.end(); it++)
			{
				//���а�cost��С�����˳������
				if ((*it).cost > currentCost)
				{
					queueHead.insert(it,pNew);
					return;
				}
			}
		}
		queueHead.push_back(pNew);
	}

	/**
	* \brief ��·�������е����������
	* \param queueHead ·������ͷ
	* \return ���������·��
	*/
	zPathPoint *exit_queue(zPathQueueHead &queueHead)
	{
		zPathPoint *ret = NULL;
		if (!queueHead.empty())
		{
			reference ref = queueHead.front();
			ret = ref.node;
			queueHead.pop_front();
		}
		return ret;
	}

public:

	/**
	* \brief Ѱ·�������ж��м���Ƿ�ɴ�Ŀ�ĵ�
	*
	*  return (scene->zPosShortRange(tempPos,destPos,radius)
	*      && (!scene->checkBlock(tempPos) //Ŀ���ɴ����������Ŀ���
	*        || tempPos == destPos));
	*
	* \param tempPos Ѱ·���̵��м��
	* \param destPos Ŀ�ĵ�����
	* \param radius Ѱ·��Χ��������Χ����ΪĿ�ĵز��ɴ�
	* \return �����Ƿ�ɵ���Ŀ�ĵ�
	*/
	virtual bool moveable(const zPos &tempPos,const zPos &destPos,const int radius1 = 12){
		if (tempPos.x < 0 || tempPos.y < 0) return false;
		return true;
	}
	/**
	* \brief �����ĳһ�������ƶ�
	* \param direct ����
	* \param step ��ʾ����
	* \return �ƶ��Ƿ�ɹ�
	*/
	virtual bool moveTo(zPos &dest){return false;};
	/**
	* \brief ʹ�����ĳһ�����ƶ�
	* ��Ѱ·�㷨���ƶ�
	* \param srcPos �������
	* \param destPos Ŀ�ĵ�����
	* \return �ƶ��Ƿ�ɹ�
	*/
	bool gotoFindPath(const zPos &srcPos,const zPos &destPos);
	
	bool getNextPos(const zPos &srcPos,const zPos&destPos,zPos &out,int step1=1,int radius1=12);
};

template<int step,int radius>
bool zAStar<step,radius>::gotoFindPath(const zPos &srcPos,const zPos &destPos)
{
	//DisMap����destPosΪ���ĵı߳�Ϊ2 * radius + 1 ��������
	const int width = (2 * radius + 1);
	const int height = (2 * radius + 1);
	const int MaxNum = width * height ;
	//������·�������ʼ��Ϊ���ֵ
	std::vector<int> pDisMap(MaxNum,MaxNum);
	std::vector<zPathPoint> stack(MaxNum * 8 + 1);//�ڶ�ջ�з����ڴ�
	zPathQueueHead queueHead;

	//�ӿ�ʼ������м���
	zPathPoint *root = &stack[MaxNum * 8];
	root->pos = srcPos;
	root->cc = 0;
	root->father = NULL;
	enter_queue(queueHead,root,root->cc + judge(root->pos,destPos));

	int Count = 0;
	//�������,ѭ������MaxNum�������
	while(Count < MaxNum)
	{
		root = exit_queue(queueHead);
		if (NULL == root)
		{
			//Ŀ��㲻�ɴ�
			return false;
		}

		if (root->pos == destPos)
		{
			//�ҵ�����Ŀ�ĵص�·��
			break;
		}

		const zAdjust adjust[8] =
		{
			{  0 * step,-1 * step }, // 
			{  -1 * step,0 * step },
			{  1 * step,0 * step  }, // ��
			{  0 * step,1 * step  },
			{  1 * step,-1 * step },
			{  -1 * step,-1 * step},
			{  -1 * step,1 * step },
			{ 1 * step, 1 *step}
		};
		for(int i = 0; i < 4; i++)
		{
			//�ֱ����Χ8�������м���·��
			bool bCanWalk = true;
			zPos tempPos = root->pos;
			tempPos += adjust[i];

			if (moveable(tempPos,destPos))
			{
				//��·�����л���
				zPathPoint *p = root;
				while(p)
				{
					if (p->pos == tempPos)
					{
						//����������Ѿ��ڻ���·���У�������ǰ��
						bCanWalk = false;
						break;
					}
					p = p->father;
				}

				//���·�����ݳɹ�����ʾ������ǿ����ߵ�
				if (bCanWalk)
				{
					int cost = root->cc + 1;
					int index = (tempPos.y - destPos.y + radius) * width + (tempPos.x - destPos.x + radius);
					if (index >= 0
						&& index < MaxNum
						&& cost < pDisMap[index])
					{
						//����·�����ϴμ����·����Ҫ�̣���Ҫ���뵽���·��������
						pDisMap[index] = cost;
						zPathPoint *pNewEntry = &stack[Count * 8 + i];
						pNewEntry->pos = tempPos;
						pNewEntry->cc = cost;
						pNewEntry->father = root;
						enter_queue(queueHead,pNewEntry,pNewEntry->cc + judge(pNewEntry->pos,destPos));
					}
				}
			}
		}

		Count++;
	}

	if (Count < MaxNum)
	{
		//����·����PointHead��,��ֻ��һ��
		while(root)
		{
			//�����ڶ����ڵ�
			if (root->father != NULL
				&& root->father->father == NULL)
			{
				return moveTo(root->pos);
			}

			root = root->father;
		}
	}

	return false;
}

template<int step2,int radius2>
bool zAStar<step2,radius2>::getNextPos(const zPos &srcPos,const zPos&destPos,zPos &out,int step1,int radius1)
{
	//DisMap����destPosΪ���ĵı߳�Ϊ2 * radius + 1 ��������
	const int width = (2 * radius1 + 1);
	const int height = (2 * radius1 + 1);
	const int MaxNum = width * height ;
	//������·�������ʼ��Ϊ���ֵ
	std::vector<int> pDisMap(MaxNum,MaxNum);
	std::vector<zPathPoint> stack(MaxNum * 8 + 1);//�ڶ�ջ�з����ڴ�
	zPathQueueHead queueHead;

	//�ӿ�ʼ������м���
	zPathPoint *root = &stack[MaxNum * 8];
	root->pos = srcPos;
	root->cc = 0;
	root->father = NULL;
	enter_queue(queueHead,root,root->cc + judge(root->pos,destPos));

	int Count = 0;
	//�������,ѭ������MaxNum�������
	while(Count < MaxNum)
	{
		root = exit_queue(queueHead);
		if (NULL == root)
		{
			//Ŀ��㲻�ɴ�
			return false;
		}

		if (abs(root->pos.x -  destPos.x) <= step1 && abs(root->pos.y - destPos.y) <= step1)
		{
			//�ҵ�����Ŀ�ĵص�·��
			break;
		}

		const zAdjust adjust[8] =
		{
			{  1 * step1,0 * step1 },
			{  0 * step1,-1 * step1 },
			{  0 * step1,1 * step1  },
			{  -1 * step1,0 * step1 },
			{  1 * step1,-1 * step1 },
			{  -1 * step1,-1 * step1},
			{  -1 * step1,1 * step1 },
			{ 1 * step1, 1 *step1}
		};
		for(int i = 0; i < 4; i++)
		{
			//�ֱ����Χ8�������м���·��
			bool bCanWalk = true;
			zPos tempPos = root->pos;
			tempPos += adjust[i];

			if (moveable(tempPos,destPos))
			{
				//��·�����л���
				zPathPoint *p = root;
				while(p)
				{
					if (p->pos == tempPos)
					{
						//����������Ѿ��ڻ���·���У�������ǰ��
						bCanWalk = false;
						break;
					}
					p = p->father;
				}

				//���·�����ݳɹ�����ʾ������ǿ����ߵ�
				if (bCanWalk)
				{
					int cost = root->cc + 1;
					int index = (tempPos.y - destPos.y + radius1) * width + (tempPos.x - destPos.x + radius1);
					if (index >= 0
						&& index < MaxNum
						&& cost < pDisMap[index])
					{
						//����·�����ϴμ����·����Ҫ�̣���Ҫ���뵽���·��������
						pDisMap[index] = cost;
						zPathPoint *pNewEntry = &stack[Count * 8 + i];
						pNewEntry->pos = tempPos;
						pNewEntry->cc = cost;
						pNewEntry->father = root;
						enter_queue(queueHead,pNewEntry,pNewEntry->cc + judge(pNewEntry->pos,destPos));
					}
				}
			}
		}

		Count++;
	}

	if (Count < MaxNum)
	{
		//����·����PointHead��,��ֻ��һ��
		while(root)
		{
			//�����ڶ����ڵ�
			if (root->father != NULL
				&& root->father->father == NULL)
			{
				out = root->pos;
				return true;
			}

			root = root->father;
		}
	}

	return false;
}
NS_CC_END
