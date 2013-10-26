#pragma once
/**
 * ����ͼƬ�ָ� СͼƬ�ϲ� �����ṩһ�µļ�������
 */
#include "cocos2d.h"
#include <list>
#include <vector>
#include <map>
#include "serialize.h"
#if (0)
#include <png.hpp>
#endif
NS_CC_BEGIN
/**
 * ��������
 */
class TextureIndex : public serialize::Object{
public:
	int textureId; // ������
	int frameId; // �ڲ�֡���
	IMP_SERIALIZE_DATA_FUNC()
	{
		SERIALIZE_DATA(textureId,0);
		SERIALIZE_DATA(frameId,1);
	}
	TextureIndex(int textureId,int frameId)
	{
		this->textureId = textureId;
		this->frameId = frameId;
	}
	TextureIndex()
	{
		textureId = -1;
		frameId = -1;
	}
};
class PngPack;
class PackPng:public CCNode{
public:
	static PackPng* create();
	bool init();
	const CCSize & getContentSize(){
		return size;
	}
	void setPosition(const CCPoint &point)
	{
		CCNode::setPosition(ccpAdd(point,offset));
	}
	CCPoint offset;
	CCSize size;
};
/**
 * ��������
 */
class ObjectData: public serialize::Object{
public:
	std::string pngName; // ��Դ����
	int width_size; // ͼƬ��
	int each_pixel_width; // ÿ����Դ�Ŀ�
	int each_pixel_height; // ÿ����Դ�ĸ�
	int image_width; // ͼƬ��
	int image_height; // ͼƬ��
	std::vector<TextureIndex> frameIds; // ��Դ�б�
	typedef std::vector<TextureIndex>::iterator FRAMEIDS_ITER;
#if (0)
	/**
	 * object ����д�뵽png ͼƬ
	 */
	void write(PngPack *pack,png::image< png::rgba_pixel > & pngbuffer);
#endif
	/**
	 * ��object ������װ��sprite ���ϲ�����node �ڵ�
	 */
	void write(PngPack *pack,CCNode *node);

	void write(PngPack *pack,PackPng *png);
	/**
	 * ��ȡһ������֡
	 */
	CCSpriteFrame* getFrame(PngPack *pack);
	IMP_SERIALIZE_DATA_FUNC()
	{
		SERIALIZE_DATA(pngName,0);
		SERIALIZE_DATA(frameIds,1);
		SERIALIZE_DATA(width_size,2);
		SERIALIZE_DATA(each_pixel_width,3);
		SERIALIZE_DATA(each_pixel_height,4);
		SERIALIZE_DATA(image_width,5);
		SERIALIZE_DATA(image_height,6);
	}
	/**
	 * ���سɹ�
	 */
	virtual void beLoaded( serialize::Stream & ss);
};
/**
 * ֡����
 */
class FrameData : public serialize::Object{
public:
	int x,y,width,height;
	IMP_SERIALIZE_DATA_FUNC()
	{
		SERIALIZE_DATA(x,0);
		SERIALIZE_DATA(y,1);
		SERIALIZE_DATA(width,2);
		SERIALIZE_DATA(height,3);
	}
	FrameData()
	{
		x = y = width = height = 0; 
	}
};
/**
 * ��������
 */
class TextureData:public serialize::Object{
public:
	enum {
		EACH_IMAGE_WIDTH = 256,
		EACH_IMAGE_HEIGHT = 256,
		EACH_TEXTURE_WIDTH = 512,
		EACH_TEXTURE_HEIGHT = 512,
		EACH_BLOCK_WIDTH = 32, // ÿ������Ŀ�
		EACH_BLOCK_HEIGHT = 32, // ÿ������ĸ�
	};
	int textureId; //�ڲ���id ��
	std::vector<FrameData> frames; // ͼƬ�б�Ȼ���е�֡
	std::vector<unsigned char> contents;
	CCTexture2D* texture;
	IMP_SERIALIZE_DATA_FUNC()
	{
		SERIALIZE_DATA(textureId,0);
		SERIALIZE_DATA(frames,1);
		SERIALIZE_DATA(contents,2);
	}
	TextureData()
	{
		texture = NULL;
	}
	/**
	 * ��ȡ���ŵķ�������
	 * return ZeroRect ʱ˵�����ܷ���
	 */
	CCRect getPrefectRect(const CCRect & rect);
#if (0)
	/**
	 * ����ͼƬ��ָ������ ���� framesId
	 * \param img �������img
	 * \param rect �����������
	 */
	int addImgByRect(const png::image< png::rgba_pixel > &img,const CCRect & rect);

	/**
	 * ��������ͼƬ��
	 */
	void write(png::image< png::rgba_pixel > &img,int frameId,const CCRect & rect);
	void write(png::image< png::rgba_pixel > &img);
#endif
	/**
	 * ��ȡһ֡
	 */
	CCSpriteFrame * getFrame(int frameId);
	/**
	 * ����������ڽڵ���
	 */
	void write(CCNode *node,int frameId,const CCRect & rect);
	/**
	 * ���سɹ�
	 */
	virtual void beLoaded( serialize::Stream & ss);
};
/**
 * ������Դ�ص�
 */
struct stLoadPackCallback{
	virtual void doGet(int allSize,int nowTap) = 0;
};
/**
 * ��png ���
 */
class PngPack :public serialize::Object{
public:
	PngPack()
	{
	//	loadCallback = NULL;
	}
	static PngPack & getMe()
	{
		static PngPack pack;
		return pack;
	}
	/**
	 * �ϲ�ͼƬ��packϵͳ
	 */
	void addPng(const char *pngName);
	/**
	 * ���浽pack ��
	 */
	void save(const char *packName);
	/**
	 * ��pack �м���
	 */
	void load(const char *packName);
	/**
	 * ��pack �м���
	 */
	void load(const char *packName,stLoadPackCallback *callback);
	/**
	 * ��� �����ݻָ��ɿɶ���png ͼƬ
	 */
	void unpack();
	
	void saveAllTextures();
	TextureData *getTextureByID(int txtId);
public:
	/**
	 * ��ȡ�ϲ���Png
	 */
	PackPng * getPackPng(const char *name);
	/**
	 * ��ȡ�ڵ� �Զ�����ص�ͼƬ��ϳ�Node �ڵ�
	 */
	CCNode * getNode(const char*pngName);
	/**
	 * ��ȡSpriteFrame
	 */
	CCSpriteFrame * getFrame(const char *pngName);
	/**
	 * ��ȡ֡��
	 **/
	bool getFrames(const char *pngName,std::vector<CCSpriteFrame*> & frames);
	/**
	 * ��ȡ����
	 * \param pngName ͼƬ����
	 */	
	CCSprite * getSprite(const char *pngName);

	/**
	 * ��ȡ֡����
	 * \param index ��������
	 */
	FrameData * getFrameData(const TextureIndex &index);
	std::vector<TextureData> textures; // ��������
	std::map<std::string,ObjectData> objects; // ��������
	typedef std::vector<TextureData>::iterator TEXTURES_ITER;
	typedef std::map<std::string,ObjectData>::iterator OBJECTS_ITER;
	IMP_SERIALIZE_DATA_FUNC()
	{
		SERIALIZE_DATA(textures,0);
		SERIALIZE_DATA(objects,1);
	}
	/**
	 * Ԥ������
	 * */
	virtual void preLoad(serialize::Stream & ss){
		allBinarySize = ss.size();
	}
	/**
	 * ���سɹ�
	 */
	virtual void beLoaded(serialize::Stream & ss)
	{
		if (loadCallback)
		{
			loadCallback->doGet(allBinarySize,allBinarySize);
		}
		loadCallback = NULL;
	}
	static stLoadPackCallback *loadCallback;
	int allBinarySize; // �����������ļ��Ĵ�С
	/**
	 * ��ǰ���صĴ�С
	 */
	void doGetBack(int size);
};

NS_CC_END