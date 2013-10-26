#pragma once
#include "vector"
#include "cocos2d.h"
#include <algorithm>
#include "xmlScript.h"
NS_CC_BEGIN
/**
 * �����ε�����ϵͳ
 * ÿ��������������
 * ÿż���������Ұ���
 */
class GridIndex{
public:
	enum{
		 STATIC_BLOCK = 1,
		 MONSTER_BLOCK= 1 << 1,
		 HORIZONTAL_BLOCK = 1 << 2, // �����ƶ��赲
		 VERTICAL_BLOCK = 1 << 3, // �����ƶ��赲
	};
	short x;
	short y;
	GridIndex(short x,short y):x(x),y(y)
	{}
	GridIndex()
	{
		x = y = -1;
	}
	GridIndex & operator=(const GridIndex &index)
	{
		x = index.x;
		y = index.y;
		return *this;
	}
	bool isValid()
	{
		return x != -1 && y != -1;
	}
	bool equal(const GridIndex &index)
	{
		return x == index.x && y == index.y;
	}
	const GridIndex &operator + (const GridIndex &index)
	{
		x += index.x;
		y += index.y;
		return *this;
	}
};
/**
 * �����߼�
 **/
struct stSearchLogic{
public:
	virtual bool getNext(GridIndex &index) const
	{
		return false;
	}
};
/**
 * �ص� ��Ե�Ԫ��Ĵ���
 */
struct stExecEach{
public:
	virtual void exec(const GridIndex& index)
	{
		
	}
}; 
/**
 * ����������ϵͳ
 */
template<typename CELLOBJECT>
class HexagonGrids{
public:
	/**
	 * Ĭ�ϻ��ֵĸ���
	 */
	HexagonGrids(unsigned int width,unsigned int height,int cellWidth):width(width),height(height),cellWidth(cellWidth)
	{
		cells.resize(height);
		for (int i = 0; i < height;i++)
		{
			cells[i].resize(width);
		}
	}
	/**
	 * ��ȡ��ͼ�ϵ�ʵ��λ��
	 */
	virtual CCPoint getPointByIndex(const GridIndex& index)
	{
		int offsetx = 0;
		if (index.y % 2 == 1) offsetx = cellWidth /2;
		return ccp(offsetx + index.x * cellWidth,index.y * cellWidth);
	}
	virtual GridIndex getIndexByPoint(const CCPoint &point)
	{
		GridIndex index;
		index.y = point.y / cellWidth;
		int offsetx = 0;
		if (index.y % 2 == 1) offsetx = cellWidth /2;
		index.x = (point.x - offsetx) / cellWidth;
		return index;
	}
	/**
	 * ����Ԫ��
	 * searchType ��������
	 * execEach ÿ��Ԫ�ػᱻִ��
	 */
	void exec(const GridIndex& index,const stSearchLogic &searchType, stExecEach *execEach)
	{
		GridIndex next = index;
		while (searchType.getNext(next)) // ��ȡ��һ����
		{ 
			execEach->exec(next); // ִ�иýڵ�
		}
	}
	/**
	 * ��ȡԪ��
	 */
	CELLOBJECT * getObjectByIndex(const GridIndex &index)
	{
		if (index.x >= 0 && index.y >= 0 && index.x < cells.size() && index.y < cells[index.x].size())
		{
			return &cells[index.x][index.y];
		}
		return NULL;
	}
	/**
	 * ��Ե�Ԫ����д���
	 */
	void execOne(const GridIndex &index, stExecEach *execEach)
	{
		execEach->exec(index); // ִ�иýڵ�
	}
	/**
	 * �������е�����
	 */
	void execAll( stExecEach *execEach)
	{
		for (int i = 0; i < width;i++)
			for (int j = 0; j < height;j++)
			{
				GridIndex index(i,j);
				execEach->exec(index); // ִ�иýڵ�
			}
	}
public:
	int cellWidth;
	unsigned int width;
	unsigned int height;
	std::vector<std::vector<CELLOBJECT> > cells;
	typedef typename std::vector<std::vector<CELLOBJECT> > CELLS_ITER;
};

/**
* \brief ·�������
*/
struct PathPoint
{
	/**
	* \brief ����
	*/
	GridIndex pos;
	/**
	* \brief ��ǰ����
	*/
	int cc;
	/**
	* \brief ·����һ�����ָ��
	*/
	PathPoint *father;
};

/**
* \brief ·��ͷ
*/
struct PathQueue
{
	/**
	* \brief ·���ڵ�ͷָ��
	*/
	PathPoint *node;
	/**
	* \brief ·�����ľ���
	*/
	int cost;
	/**
	* \brief ���캯��
	* \param node ��ʼ����·���ڵ�ͷָ��
	* \param cost ��ǰ���ľ���
	*/
	PathQueue(PathPoint *node,int cost)
	{
		this->node = node;
		this->cost = cost;
	}
	/**
	* \brief �������캯��
	* \param queue ��������Դ����
	*/
	PathQueue(const PathQueue &queue)
	{
		node = queue.node;
		cost = queue.cost;
	}
	/**
	* \brief ��ֵ��������
	* \param queue ����ֵ��Դ����
	* \return ���ؽṹ������
	*/
	PathQueue & operator= (const PathQueue &queue)
	{
		node = queue.node;
		cost = queue.cost;
		return *this;
	}
};

struct stCheckMoveAble{
	virtual bool exec(const GridIndex &index) = 0;
};

/**
 * ��������������ȫ��ͼ��Ѱ·��
 */
template<typename CELLOBJECT>
class AStarSeachInHexagonGrids:public HexagonGrids<CELLOBJECT>{
public:
	std::vector<GridIndex> adjust;
	AStarSeachInHexagonGrids()
	{
		minRadius = 12;
		initCircles();
	}
	AStarSeachInHexagonGrids(unsigned int width,unsigned int height,int cellWidth):HexagonGrids<CELLOBJECT>(width,height,cellWidth)
	{
		cells.resize(width * height);
		minRadius = 12;
		initCircles();
	}
	virtual void initCircles()
	{
		adjust.clear();
		adjust.push_back(GridIndex(-1,0));
		adjust.push_back(GridIndex(0,1));
		adjust.push_back(GridIndex(0,-1));
		adjust.push_back(GridIndex(1,0));
		adjust.push_back(GridIndex(1,1));
		adjust.push_back(GridIndex(1,-1));
	}
	int minRadius;
	/**
	* \brief ��������·��������
	*/
	typedef std::list<PathQueue> PathQueueHead;
	typedef typename PathQueueHead::iterator iterator;
	typedef typename PathQueueHead::reference reference;
	/**
	 * ��¼close ��
	 */
	std::set<int> mapCloses;
	int getGridIndexValue(const GridIndex &index)
	{
		return index.y << 16 + index.x;
	}
	const GridIndex getGridIndexByValue(const int & index)
	{
		GridIndex index;
		index.x = index & 0xffff;
		index.y = (index >> 16) & 0xffff;
		return index;
	}
	/**
	 * ��ȡ��һ�������ƶ��ĸ���
	 */
	bool getNextGridIndex(const GridIndex &src,const GridIndex &dest,GridIndex &out, stExecEach *execEach = NULL,stCheckMoveAble*check = NULL)
	{
		//DisMap����destPosΪ���ĵı߳�Ϊ2 * radius + 1 ��������
		const int width = (2 * minRadius + 1);
		const int height = (2 * minRadius + 1);
		const int MaxNum = width * height ;
		//������·�������ʼ��Ϊ���ֵ
		std::vector<int> pDisMap(MaxNum,MaxNum);
		std::vector<PathPoint> stack(MaxNum * 8 + 1);//�ڶ�ջ�з����ڴ�
		PathQueueHead queueHead;

		//�ӿ�ʼ������м���
		PathPoint *root = &stack[MaxNum * 8];
		root->pos = src;
		root->cc = 0;
		root->father = NULL;
		enter_queue(queueHead,root,root->cc + judge(root->pos,dest));

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

			if (abs(root->pos.x -  dest.x) <= 0 && abs(root->pos.y - dest.y) <= 0)
			{
				//�ҵ�����Ŀ�ĵص�·��
				break;
			}
			std::random_shuffle(adjust.begin(),adjust.end());
			for(int i = 0; i < adjust.size(); i++)
			{
				//�ֱ����Χ8�������м���·��
				bool bCanWalk = true;
				GridIndex tempPos = root->pos;
				tempPos.x += adjust[i].x;
				tempPos.y += adjust[i].y;
				if (moveable(tempPos,check))
				{
					//��·�����л���
					PathPoint *p = root;
					while(p)
					{
						if (p->pos.x == tempPos.x && p->pos.y == tempPos.y)
						{
							//����������Ѿ��ڻ���·���У�������ǰ��
							bCanWalk = false;
							break;
						}
						p = p->father;
					}
					/*
					std::set<int>::iterator iter = mapCloses.find(getGridIndexValue(tempPos));
					if (iter != mapCloses.end())
					{
						bCanWalk = false;
					}
					*/
					//���·�����ݳɹ�����ʾ������ǿ����ߵ�
					if (bCanWalk)
					{
						int distance = 10 * (abs(adjust[i].x) + abs(adjust[i].y));
						int cost = root->cc + distance;
						int f = cost + judge(tempPos,dest);
						int index = (tempPos.y - dest.y + minRadius) * width + (tempPos.x - dest.x + minRadius);
						if (index >= 0
							&& index < MaxNum
							&& f < pDisMap[index])
						{
							//����·�����ϴμ����·����Ҫ�̣���Ҫ���뵽���·��������
							pDisMap[index] = f;
							PathPoint *pNewEntry = &stack[Count * 8 + i];
							pNewEntry->pos = tempPos;
							pNewEntry->cc = cost;
							pNewEntry->father = root;
							enter_queue(queueHead,pNewEntry,f);
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
					if (execEach)
					execEach->exec(root->pos);
					return true;
				}
				if (execEach)
					execEach->exec(root->pos);
				root = root->father;
			}
		}

		return false;
	}
	/**
	* \brief ���ۺ���
	* \param midPos �м���ʱ�����
	* \param endPos ���������
	* \return �����������֮��ľ���
	*/
	int judge(const GridIndex &midPos,const GridIndex &endPos)
	{
		int distance = 10 * abs((long)(midPos.x - endPos.x)) + abs((long)(midPos.y - endPos.y));
		return distance;
	}

	/**
	* \brief ����·������
	* \param queueHead ·������ͷ
	* \param pPoint ��·���ڵ���ӵ�·����
	* \param currentCost ·���Ĺ������
	*/
	void enter_queue(PathQueueHead &queueHead,PathPoint *pPoint,int currentCost)
	{
		PathQueue pNew(pPoint,currentCost);
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
	PathPoint *exit_queue(PathQueueHead &queueHead)
	{
		PathPoint *ret = NULL;
		if (!queueHead.empty())
		{
			reference ref = queueHead.front();
			ret = ref.node;
			queueHead.pop_front();
			mapCloses.insert(getGridIndexValue(ret->pos));
		}
		return ret;
	}
	virtual bool moveable(const GridIndex &dest,stCheckMoveAble*check = NULL)
	{
		if (dest.x < 0 || dest.y < 0) return false; 
		if (dest.x > width || dest.y >= this->height) return false;
		if (check && !check->exec(dest)) return false;
		return true;
	}
};

template<typename CELLOBJECT>
class AStarSeachInGrids:public AStarSeachInHexagonGrids<CELLOBJECT>{
public:
	AStarSeachInGrids(unsigned int width,unsigned int height,int cellWidth):AStarSeachInHexagonGrids<CELLOBJECT>(width,height,cellWidth)
	{
		initCircles();
	}
	virtual void initCircles()
	{
		adjust.clear();
		adjust.push_back(GridIndex(0,-1));
		adjust.push_back(GridIndex(-1,0));
		adjust.push_back(GridIndex(1,0));
		adjust.push_back(GridIndex(0,1));
		adjust.push_back(GridIndex(1,-1));
		adjust.push_back(GridIndex(-1,-1));
		adjust.push_back(GridIndex(-1,1));
		adjust.push_back(GridIndex(1,1));
	}
	/**
	 * ��ȡ��ͼ�ϵ�ʵ��λ��
	 */
	CCPoint getPointByIndex(const GridIndex& index)
	{
		int offsetx = 0;
		return ccp(offsetx + index.x * cellWidth,index.y * cellWidth);
	}
	/**
	 * ���ݵ��ȡ����
	 */
	GridIndex getIndexByPoint(const CCPoint &point)
	{
		GridIndex index;
		index.y = point.y / cellWidth;
		int offsetx = 0;
		index.x = (point.x - offsetx) / cellWidth;
		return index;
	}
};
/**
 * ����һȦ
 */
class XmlSearch:public stSearchLogic{
public:
	virtual bool getNext(GridIndex &index) const
	{
		if (startIndex >= indexs.size()) return false;
		index.x += indexs[startIndex].x;
		index.y += indexs[startIndex].y;
		(*(int*)&startIndex) ++;
		return true;
	}
	XmlSearch()
	{
		startIndex = 0;
	}
	void takeNode(script::tixmlCodeNode *node)
	{
		script::tixmlCodeNode offsetNode = node->getFirstChildNode("point");
		while (offsetNode.isValid())
		{
			GridIndex index;
			index.x = offsetNode.getInt("x");
			index.y = offsetNode.getInt("y");
			indexs.push_back(index);
			offsetNode = offsetNode.getNextNode("point");
		}
	}
	void reset()
	{
		startIndex = 0;
	}
	int startIndex;
	std::vector<GridIndex> indexs;
};
/**
 * ��Ѱ���Թ�����
 */
class SerachTypeManager:public script::tixmlCode{
public:
	static SerachTypeManager &getMe()
	{
		static SerachTypeManager stm;
		return stm;
	}
	SerachTypeManager()
	{
		init();
	}
	std::map<std::string,XmlSearch> searches;
	XmlSearch nullLogic;
	typedef std::map<std::string,XmlSearch>::iterator SEARCHES_ITER;
	void init()
	{
		std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("searchtypes.xml");
		unsigned long nSize = 0;
		unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
		if (!nSize)return;
		initFromString((char*)buffer);
	}
	void takeNode(script::tixmlCodeNode *node)
	{
		if (node && node->equal("Config"))
		{
			script::tixmlCodeNode typeNode = node->getFirstChildNode("search");
			while (typeNode.isValid())
			{
				std::string name = typeNode.getAttr("name");
				XmlSearch search;
				search.takeNode(&typeNode);
				searches[name] = search;
				typeNode = typeNode.getNextNode("search");
			}
		}
	}
	XmlSearch & getSeachByName(const std::string &name)
	{
		SEARCHES_ITER iter = searches.find(name);
		if (iter != searches.end())
		{
			iter->second.reset();
			return iter->second;
		}
		return nullLogic;
	}
};

#define SEARCH_TYPE(name) SerachTypeManager::getMe().getSeachByName(name)
NS_CC_END