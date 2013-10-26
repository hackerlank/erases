#include "MutiMap.h"
#include "MutiMonster.h"
#include "MapCoordLine.h"
#include "UIMapLib.h"
NS_CC_BEGIN
MutiMap * MutiMap::create(script::tixmlCodeNode *node)
{
	MutiMap *map = new MutiMap();
	if (map)
	{
		map->readNode(node);
		map->autorelease();
		return map;
	}
	CC_SAFE_DELETE(map);
	return NULL;
}
MutiMap * MutiMap::create(const char *fileName)
{
	MutiMap *map = new MutiMap();
	if (map)
	{
		std::string startui = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName);
		unsigned long nSize = 0;
		unsigned char * buffer = CCFileUtils::sharedFileUtils()->getFileData(startui.c_str(),"rb",&nSize);
		if (!nSize)return false;
		map->initFromString((char*)buffer);
		map->fileName = fileName;
		map->autorelease();
		return map;
	}
	CC_SAFE_DELETE(map);
	return NULL;
}
void  MutiMap::takeNode(script::tixmlCodeNode *node)
{
	if (node && node->equal("Config"))
	{
		script::tixmlCodeNode mapNode = node->getFirstChildNode("map");
		showGridsTag = true;
		readNode(&mapNode);
		window = UIWindow::create();
		CCNode::addChild(window,1000);
	}
}
/**
 * ѡ�����
 */
MutiObject *MutiMap::pickObject(const CCPoint &pixelPoint)
{
	if (!this->isVisible() || isHide) return NULL;
	MutiObject *object = NULL;
	for (IMAGES_ITER iter = _images.begin(); iter != _images.end();++iter)
	{
		if (*iter && (*iter)->checkIn(pixelPoint))
		{
			object = *iter;
		}
	}
	for (CARTOONS_ITER iter = _cartoons.begin(); iter != _cartoons.end();++iter)
	{
		if (*iter && (*iter)->checkIn(pixelPoint))
		{
			object = *iter;
		}
	}
	for (BIG_IMAGES_ITER iter = _bigImages.begin();iter != _bigImages.end();++iter)
	{
		if (*iter && (*iter)->checkIn(pixelPoint))
		{
			object = *iter;
		}
	}
	for (BIG_TERRAINS_ITER iter = _bigTerrains.begin();iter != _bigTerrains.end();++iter)
	{
		if (*iter && (*iter)->checkIn(pixelPoint))
		{
			object = *iter;
		}
	}
	for (MONSTERS_ITER iter = _monsters.begin();iter != _monsters.end();++iter)
	{
		if (*iter && (*iter)->checkIn(pixelPoint))
		{
			object = *iter;
		}
	}
	// ������ͼ�ϵ��¼�
	CCPoint pos = this->convertToNodeSpace(pixelPoint);
	UIMapStub stub;
	stub.nowTouchPoint = pos;
	stub.nowTouchObject = object;
	stub.map = this;
	stub.window = window;
	theMapUILib.execCode(&stub,this->pickCode.c_str());
	return object;
}
/** 
 * ����Ƿ���������
 */
bool MutiMap::touchDown(float x,float y)
{
	if (window) return window->touchDown(x,y);
	return false;
}
/**
 * ����λ��
 */
bool MutiMap::touchMove(float x,float y)
{
	if (window) return window->touchMove(x,y);
	return false;
}
/**
 * ֹͣ�϶�
 */
bool MutiMap::touchEnd(float x,float y)
{
	if (window) return window->touchEnd(x,y);
	return false;
}
void MutiMap::execEachBg(stExecEachBackgroud *bg)
{
	bg->exec(this);
	for (GROUDS_ITER iter = _grouds.begin();iter != _grouds.end();++iter)
	{
		bg->exec(*iter);
	}
}
void MutiMap::execAllMonster(stExecEachMonster *exec)
{
	for (MONSTERS_ITER iter = _monsters.begin();iter != _monsters.end();++iter)
	{
		if (*iter)
		{
			exec->exec(*iter);
		}
	}
}
/**
 * �������ļ��ж�ȡ��Ϣ
 */
void MutiMap::readNode(script::tixmlCodeNode *node)
{
	script::tixmlCodeNode &mapNode = *node;
	if (mapNode.isValid())
	{
		zOrder = mapNode.getInt("zorder");
		ratio.x = mapNode.getFloat("rationx");
		ratio.y = mapNode.getFloat("rationy");
		offset.x = mapNode.getInt("offsetx");
		offset.y = mapNode.getInt("offsety");
		fileName = mapNode.getAttr("name");
		
		CCSize size;
		size.width = mapNode.getInt("width");
		size.height = mapNode.getInt("height");
		CCSize gridSize;
		gridSize.width = mapNode.getInt("gridsize");
		gridSize.height = mapNode.getInt("gridsize");
		if (!size.width) size.width = 10;
		if (!size.height) size.height =10;
		if (!gridSize.width) gridSize.width = 64;
		if (!gridSize.height) gridSize.height = 64;
		pickCode = mapNode.getAttr("pickcode");
		if (!_grids) _grids = new AStarSeachInGrids<int>(size.width,size.height,gridSize.width);
		if (showGridsTag)
		{
			MapCoordLine *mapCoordLine = MapCoordLine::create("HelloWorld.png",size.width * gridSize.width,size.height * gridSize.height,gridSize.width,gridSize.height);
			
			if (mapCoordLine)
			{
				CCNode::addChild(mapCoordLine);
			}
		}
		if (mapNode.isValid())
		{
			script::tixmlCodeNode imageNode = mapNode.getFirstChildNode("image");
			while(imageNode.isValid())
			{
				MutiImage *image = MutiImage::create(&imageNode);
				if (image)
				{
					CCNode::addChild(image);
					_images.push_back(image);
				}
				imageNode = imageNode.getNextNode("image");
			}
			script::tixmlCodeNode cartoonNode = mapNode.getFirstChildNode("cartoon");
			while(cartoonNode.isValid())
			{
				MutiCartoon *cartoon = MutiCartoon::create(&cartoonNode);
				if (cartoon)
				{
					CCNode::addChild(cartoon);
					_cartoons.push_back(cartoon);
				}
				cartoonNode = cartoonNode.getNextNode("cartoon");
			}
			script::tixmlCodeNode bigImageNode = mapNode.getFirstChildNode("bigimage");
			while(bigImageNode.isValid())
			{
				MutiBigImage *image = MutiBigImage::create(&bigImageNode);
				if (image)
				{
					CCNode::addChild(image);
					_bigImages.push_back(image);
				}
				bigImageNode = bigImageNode.getNextNode("bigimage");
			}
			script::tixmlCodeNode bigTerrainNode = mapNode.getFirstChildNode("bigterrain");
			while(bigTerrainNode.isValid())
			{
				MutiBigTerrain *image = MutiBigTerrain::create(&bigTerrainNode);
				if (image)
				{
					CCNode::addChild(image);
					_bigTerrains.push_back(image);
				}
				bigTerrainNode = bigTerrainNode.getNextNode("bigterrain");
			}
			/**
			 * ��ȡ�赲����Ϣ
			 */
			script::tixmlCodeNode blockNode = mapNode.getFirstChildNode("blocks");
			if (blockNode.isValid())
			{
				script::tixmlCodeNode indexNode = blockNode.getFirstChildNode("index");
				while (indexNode.isValid())
				{
					GridIndex index;
					index.x = indexNode.getInt("x");
					index.y = indexNode.getInt("y");
					setBlock(index,indexNode.getInt("value"));
					indexNode = indexNode.getNextNode("index");
				}
			}
			/**
			 * �ݹ�ķ�ʽ�����ӽڵ�
			 */
			script::tixmlCodeNode childMapNode = mapNode.getFirstChildNode("map");
			while (childMapNode.isValid())
			{
				MutiMap *map = MutiMap::create(&childMapNode);
				if (map)
				{
					this->addChild(map,map->zOrder,map->ratio,map->offset);
					_grouds.push_back(map);
				}
				childMapNode = childMapNode.getNextNode("map");
			}

		}
	}
	showGrids();
}
void MutiMap::addImage(MutiImage *image)
{
	CCNode::addChild(image);
	_images.push_back(image);
}
void MutiMap::addCartoon(MutiCartoon *cartoon)
{
	CCNode::addChild(cartoon);
	_cartoons.push_back(cartoon);
}
void MutiMap::addMonster(MutiMonster *monster)
{
	monster->map = this;
	_monsters.push_back(monster);
	CCNode::addChild(monster,10);
}
void MutiMap::addMap(MutiMap *map)
{
	this->addChild(map,map->zOrder,map->ratio,map->offset);
	_grouds.push_back(map);
}
void MutiMap::addBigImage(MutiBigImage *bigImage)
{
	CCNode::addChild(bigImage);
	_bigImages.push_back(bigImage);
}
void MutiMap::addSprite(CCSprite *sprite)
{
	CCNode::addChild(sprite);
}
struct stWriteGrids:stExecEach{
	void exec(const GridIndex& index)
	{
		int * value = grids->getObjectByIndex(index);
		if (value && *value !=0 )
		{
			TiXmlElement *indexNode=new TiXmlElement("index");
			if (blockNode)
				blockNode->LinkEndChild(indexNode);
			indexNode->SetAttribute("x",index.x);
			indexNode->SetAttribute("y",index.y);
			indexNode->SetAttribute("value",*value);
		}
	}
	HexagonGrids<int> * grids;
	TiXmlElement  *blockNode;
	stWriteGrids(HexagonGrids<int> * grids,TiXmlElement  *blockNode):grids(grids),blockNode(blockNode)
	{}
};
/**
* ����Ϣд��ڵ㵱��
*/
TiXmlElement * MutiMap::writeNode(TiXmlElement *parent,const std::string &name)
{
	TiXmlElement *mapNode=new TiXmlElement(name.c_str());
	if (parent)
		parent->LinkEndChild(mapNode);
	mapNode->SetAttribute("zorder",zOrder);
	mapNode->SetDoubleAttribute("rationx",ratio.x);
	mapNode->SetDoubleAttribute("rationy",ratio.y);
	mapNode->SetAttribute("offsetx",offset.x);
	mapNode->SetAttribute("offsety",offset.y);
	mapNode->SetAttribute("name",fileName);
	for (IMAGES_ITER iter = _images.begin(); iter != _images.end();++iter)
	{
		if (*iter)
			(*iter)->writeNode(mapNode,"image");
	}
	for (CARTOONS_ITER iter = _cartoons.begin(); iter != _cartoons.end();++iter)
	{
		if (*iter)
			(*iter)->writeNode(mapNode,"cartoon");
	}
	for (GROUDS_ITER iter = _grouds.begin(); iter != _grouds.end();++iter)
	{
		if (*iter)
			(*iter)->writeNode(mapNode,"map");
	}
	for (BIG_IMAGES_ITER iter = _bigImages.begin(); iter != _bigImages.end();++iter)
	{
		if (*iter)
			(*iter)->writeNode(mapNode,"bigimage");
	}
	for (BIG_TERRAINS_ITER iter = _bigTerrains.begin(); iter != _bigTerrains.end();++iter)
	{
		if (*iter)
			(*iter)->writeNode(mapNode,"bigterrain");
	}
	/**
	 * д���赲��
	 */
	TiXmlElement *blockNode=new TiXmlElement("blocks");
	if (mapNode)
		mapNode->LinkEndChild(blockNode);
	stWriteGrids exec(_grids,blockNode);
	if (_grids)
		_grids->execAll(&exec);
	return mapNode;
}

/**
 * ����ͼ���浽�ļ�
 */
void MutiMap::write(const std::string &name)
{
	TiXmlDocument *pDoc=new TiXmlDocument; //����һ���ĵ���ָ��
	//���һ��xmlͷ��
	TiXmlDeclaration *pDeclaration=new TiXmlDeclaration("1.0","UTF-8","");
	pDoc->LinkEndChild(pDeclaration);
	//���XMl�ĸ��ڵ�
	TiXmlElement *configNode= new TiXmlElement("Config");
	pDoc->LinkEndChild(configNode);
	
	TiXmlElement *mapNode = writeNode(configNode,"map");

	pDoc->SaveFile(name);
}

void MutiMap::hide()
{
	isHide = true;
	for (IMAGES_ITER iter = _images.begin(); iter != _images.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(false);
	}
	for (CARTOONS_ITER iter = _cartoons.begin(); iter != _cartoons.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(false);
	}
	for (GROUDS_ITER iter = _grouds.begin(); iter != _grouds.end();++iter)
	{
		if (*iter)
			(*iter)->hide();
	}
	for (BIG_IMAGES_ITER iter = _bigImages.begin(); iter != _bigImages.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(false);
	}
	for (BIG_TERRAINS_ITER iter = _bigTerrains.begin(); iter != _bigTerrains.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(false);
	}
}
void MutiMap::show()
{
	isHide = false;
	for (IMAGES_ITER iter = _images.begin(); iter != _images.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(true);
	}
	for (CARTOONS_ITER iter = _cartoons.begin(); iter != _cartoons.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(true);
	}
	for (GROUDS_ITER iter = _grouds.begin(); iter != _grouds.end();++iter)
	{
		if (*iter)
			(*iter)->show();
	}
	for (BIG_IMAGES_ITER iter = _bigImages.begin(); iter != _bigImages.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(true);
	}
	for (BIG_TERRAINS_ITER iter = _bigTerrains.begin(); iter != _bigTerrains.end();++iter)
	{
		if (*iter)
			(*iter)->setVisible(true);
	}
}
struct stShowEachGrids:stExecEach{
	void exec(const GridIndex& index)
	{
		int * value = grids->getObjectByIndex(index);
		if (value && *value !=0)
		{
			std::stringstream ss;
			ss << *value;
			CCSprite * test = CCSprite::create("cell.png");
			CCLabelTTF *label = CCLabelTTF::create(ss.str().c_str(),"Arial",32);
			if (label)
			{
				test->addChild(label);
			}
			test->setPosition(grids->getPointByIndex(index));
			map->addSprite(test);
			test->setAnchorPoint(ccp(0,0));
			map->tempDebugBlocks.push_back(test);
		}
	}
	HexagonGrids<int> * grids;
	MutiMap *map;
	stShowEachGrids(HexagonGrids<int> * grids,MutiMap *map):grids(grids),map(map)
	{
		for (std::vector<CCSprite*>::iterator iter = map->tempDebugBlocks.begin(); iter != map->tempDebugBlocks.end();++iter)
		{
			map->removeChild(*iter,true);
		}
		map->tempDebugBlocks.clear();
	}
};
struct stCheckValid:public stCheckMoveAble{
	bool exec(const GridIndex &index) 
	{
		int * value = grids->getObjectByIndex(index);
		if (!value || *value != 0)
		{
			return false;
		}
		return true;
	}
	stCheckValid(HexagonGrids<int> * grids):grids(grids)
	{}
	HexagonGrids<int> * grids;
};
struct stCheckValid1:public stCheckMoveAble{
	bool exec(const GridIndex &index) 
	{
		int * value = grids->getObjectByIndex(index);
		if (!value || *value != uniqueId)
		{
			return false;
		}
		return true;
	}
	stCheckValid1(HexagonGrids<int> * grids,int uniqueId):grids(grids),uniqueId(uniqueId)
	{}
	HexagonGrids<int> * grids;
	int uniqueId;
};
void MutiMap::showGrids()
{
	stShowEachGrids exec(_grids,this);
	for (int i = 3; i < 10;i++)
	{
	//	setBlock(GridIndex(i,2), GridIndex::STATIC_BLOCK);
	}
	_grids->execAll(&exec);
	//stCheckValid check(_grids);
	/**
	 * ����Ѱ·�㷨
	 */
	//GridIndex out;
	//_grids->getNextGridIndex(GridIndex(0,0),GridIndex(5,2),out,&exec,&check);
}
CCPoint  MutiMap::getLocationByIndex(const GridIndex &index)
{
	return _grids->getPointByIndex(index);
}
bool  MutiMap::getNextPosition(const GridIndex &src,const GridIndex &dest,GridIndex &out)
{
	stCheckValid check(_grids);
	return _grids->getNextGridIndex(src,dest,out,NULL,&check);
}
/**
 * Ѱ��ָ��ͨ·
 */
bool  MutiMap::getNextPosition(const GridIndex &src,const GridIndex &dest,GridIndex &out,int uniqueId)
{
	stCheckValid1 check(_grids,uniqueId);
	return _grids->getNextGridIndex(src,dest,out,NULL,&check);
}
/**
 * �����赲����Ϣ
 */
void MutiMap::setBlock(const GridIndex &index,int bvalue)
{
	if (_grids)
	{
		int * value = _grids->getObjectByIndex(index);
		if (value)
		{
			*value |= bvalue;
		}
	}
}
void MutiMap::clearBlock(const GridIndex &index,int bvalue)
{
	if (_grids)
	{
		int * value = _grids->getObjectByIndex(index);
		if (value)
		{
			*value &= ~bvalue;
		}
	}
}
void MutiMap::setBlockByTouchPoint(const CCPoint &touchPoint,int value)
{
	CCPoint point = this->convertToNodeSpace(touchPoint);
	GridIndex index = _grids->getIndexByPoint(point);
	if (value)
		setBlock(index,value);
	else
		clearBlock(index,0xffffffff);
	//stShowEachGrids exec(_grids,this);
	//_grids->execOne(index,&exec);
}
GridIndex MutiMap::getIndexByLocation(const CCPoint &point)
{
	return _grids->getIndexByPoint(point);
}

bool MutiMap::checkCollide(const GridIndex &location,std::vector<GridIndex> *relateGrid,int blockType)
{
	if (_grids)
	{
		int * value = _grids->getObjectByIndex(location);
		if (!value || *value & blockType)
		{
			return true;
		}
		if (relateGrid)
		{
			for (std::vector<GridIndex>::iterator iter = relateGrid->begin();iter != relateGrid->end();++iter)
			{
				int * value = _grids->getObjectByIndex(*iter);
				if (!value || *value & blockType)
				{
					return true;
				}
			}
		}
		return false;
	}
	return false;
}
NS_CC_END