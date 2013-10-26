//
//  mycartoon.h
//  Dragon
//
//  Created by GameDeveloper on 13-9-23.
//
//

#ifndef Dragon_mycartoon_h
#define Dragon_mycartoon_h
#include "cocos2d.h"
#include "png.hpp"
#include "BaseLuaExt.h"
using namespace cocos2d;
class MyFrame{
public:
    int textureId;
    int frameId;
    std::string name;
    CCSpriteFrame *frame;
    MyFrame *next;
    MyFrame()
    {
        frame = NULL;
        frameId = 0;
        next = NULL;
        textureId = -1;
    }
    void addFrame(const char*pngName);
    
    void addFrame(CCTexture2D * texture);
    
    MyFrame* pushFrame(MyFrame *frame);
    static MyFrame*create (CCTexture2D *texture);
    static MyFrame* create(const char *frameName);
    int getCount();
};

/**
 * 我的卡通
 */
class MyCartoon:public CCNode{
public:
    static MyCartoon *create();
    MyFrame * rootFrame;
    CCSprite *sprite; // sprite对象
    MyCartoon * next;
    MyFrame* pushFrame(MyFrame * frame);
    MyCartoon()
    {
        rootFrame = NULL;
        sprite = NULL;
        next = NULL;
        eachFrameTime = 0;
        startFrameId = endFrameId = 0;
        showBlockId = -1;
        CCTime::gettimeofdayCocos2d(&nowFrameShowTime, NULL);
        sprite = CCSprite::create();
        nowFrame = NULL;
        this->addChild(sprite);
        blockId = -1;
        cartoonPlayCount = -1;
        cartoonPlayTimeOut = -1;
        nowFrameId = -1;
    }
    int getCount();
    int blockId;
    void pushCartoon(MyCartoon *cartoon);
    int showBlockId; // 展示的块
    cc_timeval nowFrameShowTime;
    void nextFrame();
    MyFrame *nowFrame;//当前桢
    int startFrameId;
    int cartoonPlayCount;
    int cartoonPlayTimeOut;
    int endFrameId;
    int nowFrameId;
    int eachFrameTime; // 每桢间隔时间
    void setFrame(int frameStartId,int frameEndId,int timeout,int count = -1);
    void showFrame(int frameStartId,int frameEndId,int timeout,int count = -1,int blockId = -1);
    void visit();
	void addFrameEvent(int frameId);
	std::set<int> triggerFrames;
};

#pragma pack(1)
struct cartoon_file_head{
	char version[4];
	int sprite_count;
	int all_frame_count;
	int textures_count;
	char idle_value[36]; // ?’÷μ
	void clear()
	{
		memset(this,0,sizeof(*this));
	}
	cartoon_file_head()
	{
		clear();
	}
};
struct texture_data_len{
	int size;
	texture_data_len()
    {
        size = 0;
    }
};
struct texture_data{ // ???ì????
	char *content;
	void clear()
	{
		memset(this,0,sizeof(*this));
	}
	texture_data()
	{
		clear();
	}
};

struct cartoon_sprite_head{
	int frame_count;
	int x;
	int y;
	int w;
	int h;
	void clear()
	{
		memset(this,0,sizeof(*this));
	}
	cartoon_sprite_head()
	{
		clear();
	}
};
struct cartoon_frame_data{
	int texture_id; //
	int tx,ty,tw,th; //
	int ox,oy; //
	int w,h; //
	void clear()
	{
		memset(this,0,sizeof(*this));
	}
	cartoon_frame_data()
	{
		clear();
	}
};
#pragma pack()

class temp_texture{
public:
	int index;
	std::string pngName;
	png::image< png::rgba_pixel > png;
	temp_texture()
	{
		index = 0;
	}
};

class my_cartoon_file{
public:
    void read(const char *aniFile,MyCartoon * rootCartoon);
    void write(const char*aniFile,MyCartoon* rootCartoon);
    static  std::string getwriteablepath(const char*filename);
};
#endif
