//
//  mycartoon.cpp
//  Dragon
//
//  Created by GameDeveloper on 13-9-23.
//
//

#include "mycartoon.h"
#include "tolua++.h"
#include "BaseLuaExt.h"

MyFrame* MyFrame::create(const char *frameName)
{
    CCTexture2D * texure = CCTextureCache::sharedTextureCache()->addImage(frameName);
    MyFrame * temp = MyFrame::create(texure);
    temp->name = frameName;
    return temp;
}
MyFrame * MyFrame::create(cocos2d::CCTexture2D *texture)
{
    MyFrame * frame = new MyFrame;
    CCRect rect = CCRectMake(0, 0, texture->getContentSize().width, texture->getContentSize().height);
    CCSpriteFrame * tempFrame = CCSpriteFrame::createWithTexture(texture,rect);
    if (tempFrame) tempFrame->retain();
    frame->frame = tempFrame;
    return frame;
}
void MyFrame::addFrame(const char *pngName)
{
    CCTexture2D * texure = CCTextureCache::sharedTextureCache()->addImage(pngName);
    MyFrame * temp = MyFrame::create(texure);
    pushFrame(temp);
}
void MyFrame::addFrame(CCTexture2D * texture)
{
    MyFrame * temp = MyFrame::create(texture);
    pushFrame(temp);
}
int MyFrame::getCount(){
    int count = 0;
    MyFrame * temp = this;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}
MyFrame* MyFrame::pushFrame(MyFrame *frame)
{
    MyFrame *pre = this;
    MyFrame *temp = next;
    while (temp) {
        pre = temp;
        temp = temp->next;
    }
    if (pre)
    {
        pre->next = frame;
        pre->next->frameId = pre->frameId + 1;
    }
    return frame;
}
MyCartoon * MyCartoon::create()
{
    MyCartoon * cartoon = new MyCartoon;
    cartoon->autorelease();
    return cartoon;
}
void MyCartoon::pushCartoon(MyCartoon *cartoon)
{
    if (!rootFrame)
    {
        rootFrame = cartoon->rootFrame;
        return;
    }
    MyCartoon *pre = this;
    MyCartoon *temp = next;
    while (temp) {
        pre = temp;
        temp = temp->next;
    }
    if (pre)
    {
        pre->next = cartoon;
        pre->next->blockId = pre->blockId + 1;
        cartoon->retain();
    }
}

int MyCartoon::getCount(){
    int count = 0;
    MyCartoon * temp = this;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}
void MyCartoon::showFrame(int frameStartId,int frameEndId,int timeout,int count,int blockId)
{
    MyCartoon * temp = this;
    while (temp) {
        temp->setFrame(frameStartId,frameEndId,timeout,count);
        temp = temp->next;
    }
    showBlockId = blockId;
}
void MyCartoon::setFrame(int frameStartId,int frameEndId,int timeout,int count)
{
    if (frameEndId < frameStartId) return;
    // 遍历root 获取信息
    MyFrame *frame = rootFrame;
    while (frame) {
        if (frameStartId == frame->frameId)
        {
            nowFrame = frame;
            startFrameId = frameStartId;
            endFrameId = frameEndId;
            nowFrameId = frameStartId;
            break;
        }
        frame = frame->next;
    }
    this->cartoonPlayTimeOut = timeout;
    this->cartoonPlayCount = count;
    eachFrameTime = timeout / (frameEndId - frameStartId);
}
void MyCartoon::visit()
{
    kmGLPushMatrix();
    this->transform();
    
    nextFrame();
    CCNode::visit();
    MyCartoon * frame = next;
    int index = 0;
    while (frame)
    {
        if (this->showBlockId == -1 || this->showBlockId == index)
            frame->visit();
		if (triggerFrames.find(nowFrameId) != triggerFrames.end())
		{
			// 触发帧事件
			lua_getglobal(CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState(), "doCartoonFrame");
            if (!lua_isfunction(CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState(), -1))
            {
                CCLOG("[LUA ERROR] name '%s' does not represent a Lua function", "doCartoonFrame");
                lua_pop(CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState(), 1);
                return;
            }
            tolua_pushusertype(CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState(), this, "MyCartoon");
            int ret = CCLuaEngine::defaultEngine()->getLuaStack()->executeFunction(1);
            CCLuaEngine::defaultEngine()->getLuaStack()->clean();
		}
        index++;
        frame = frame->next;
    }
    kmGLPopMatrix();
}
MyFrame* MyCartoon::pushFrame(MyFrame *frame)
{
    if (rootFrame) rootFrame->pushFrame(frame);
    else rootFrame = frame;
    return frame;
}
void MyCartoon::addFrameEvent(int frameId)
{
	triggerFrames.insert(frameId);
}
void MyCartoon::nextFrame()
{
    if (!eachFrameTime) return;
    cc_timeval nowTime;
    CCTime::gettimeofdayCocos2d(&nowTime, NULL);
    if (CCTime::timersubCocos2d(&this->nowFrameShowTime, &nowTime) >= eachFrameTime)
    {
        if (!nowFrame || nowFrame->frameId > endFrameId || nowFrameId != nowFrame->frameId)
        {
            eachFrameTime = 0;
            if (cartoonPlayCount == -1 || cartoonPlayCount -- > 1)
                setFrame(startFrameId, endFrameId, cartoonPlayTimeOut,cartoonPlayCount);
            // 触发结束事件
			// 传递MyCartoon
			lua_getglobal(CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState(), "doCartoonOver");
            if (!lua_isfunction(CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState(), -1))
            {
                CCLOG("[LUA ERROR] name '%s' does not represent a Lua function", "doCartoonOver");
                lua_pop(CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState(), 1);
                return;
            }
            tolua_pushusertype(CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState(), this, "MyCartoon");
            int ret = CCLuaEngine::defaultEngine()->getLuaStack()->executeFunction(1);
            CCLuaEngine::defaultEngine()->getLuaStack()->clean();
			return;
        }
		
        nowFrameId++;
        sprite->setDisplayFrame(nowFrame->frame);
        nowFrame = nowFrame->next;
        CCTime::gettimeofdayCocos2d(&nowFrameShowTime, NULL);
    }
}

void my_cartoon_file::read(const char *aniFile,MyCartoon * rootCartoon)
{
    FILE *hFile = fopen(aniFile,"rb");
    if (hFile)
    {
        char idle_block[64];
        cartoon_file_head file_head;
        fread(&file_head,1,sizeof(file_head),hFile);
        fread(idle_block,1,64,hFile);
        std::vector<CCTexture2D*> textures; // ???ìo?∫?
        texture_data_len *data_len = new texture_data_len[file_head.textures_count];
        fread(data_len,sizeof(texture_data_len),file_head.textures_count,hFile);
        for (int i = 0; i < file_head.textures_count;i++)
        {
            // 读取纹理长度列表
            texture_data data;
            int size = data_len[i].size;
            if (size <= 0) return;
            data.content = new char[size];
            fread(data.content,1,size,hFile);
            // 读取纹理数据
            CCImage image;
            CCTexture2D *texture = NULL;
            if (image.initWithImageData((void*)data.content,size,  CCImage::kFmtPng))
            {
                texture = new CCTexture2D();
                if( texture && texture->initWithImage(&image) )
                {
                    texture->setAliasTexParameters();
                    textures.push_back(texture);
                }
            }
            delete[] data.content;
        }
        delete[] data_len;
        
        fread(idle_block,1,64,hFile); // ???°?’?–????
        for (int i = 0; i < file_head.sprite_count;i++)
        {
            cartoon_sprite_head sprite_head;
            fread(&sprite_head,sizeof(sprite_head),1,hFile);
            MyCartoon *cartoon = MyCartoon::create();
            for (int i = 0; i < sprite_head.frame_count;i++)
            {
                cartoon_frame_data frame_data;
                fread(&frame_data,sizeof(frame_data),1,hFile);
                if (frame_data.texture_id >= textures.size() ) return;
                MyFrame *frame = MyFrame::create(textures[frame_data.texture_id]);
                cartoon->pushFrame(frame);
                
            }
            cartoon->setPosition(ccp(sprite_head.x,sprite_head.y));
            rootCartoon->pushCartoon(cartoon);
            fread(idle_block,1,64,hFile); //
        }
    }
    fclose(hFile);
}
std::string my_cartoon_file::getwriteablepath(const char*filename)
{
    std::stringstream fileName;
    fileName << CCFileUtils::sharedFileUtils()->getWritablePath()<<filename;
    return fileName.str();
}
void my_cartoon_file::write(const char*aniFile,MyCartoon* rootCartoon)
{
    std::string fileName = getwriteablepath(aniFile);
    cartoon_file_head filehead;
    std::map<std::string,temp_texture> temp_texture_datas;
    typedef std::map<std::string,temp_texture>::iterator temp_texture_datas_iter;
    MyCartoon * temp = rootCartoon;
    while (temp)
    {
        MyFrame *frame = temp->rootFrame;
        while (frame)
        {
            
            temp_texture_datas_iter iter = temp_texture_datas.find(frame->name);
            if (iter != temp_texture_datas.end())
            {
                frame->textureId = iter->second.index;
            }
            else
            {
                //
                temp_texture texture;
                texture.index = temp_texture_datas.size();
                texture.png.read(CCFileUtils::sharedFileUtils()->fullPathForFilename(frame->name.c_str())); //
                temp_texture_datas[frame->name] = texture;
                frame->textureId = texture.index; //
            }
            frame = frame->next;
        }
        temp = temp->next;
    }
    char idle_block[64];
    FILE *hFile = fopen(fileName.c_str(),"wb");
    filehead.sprite_count = rootCartoon->getCount();
    filehead.textures_count = temp_texture_datas.size();
    fwrite(&filehead,1,sizeof(filehead),hFile);
    fwrite(idle_block,64,1,hFile);
    texture_data_len * lens = new texture_data_len[temp_texture_datas.size()];
    std::vector<std::string> texture_strings;
    int index = 0;
    //texture_strings.resize(temp_texture_datas.size());
    filehead.textures_count = temp_texture_datas.size();
    for (temp_texture_datas_iter iter = temp_texture_datas.begin(); iter != temp_texture_datas.end();++iter,++index)
    {
        std::stringstream ss;
        iter->second.png.write_stream(ss);
        lens[index].size = ss.str().size();
        texture_strings.push_back(ss.str());
    }
    fwrite(lens,sizeof(texture_data_len),temp_texture_datas.size(),hFile);
    delete [] lens; //
    for (std::vector<std::string>::iterator iter = texture_strings.begin(); iter != texture_strings.end();++iter)
    {
        fwrite(iter->c_str(),iter->size(),1,hFile); //
    }
    fwrite(idle_block,1,64,hFile); //
    temp = rootCartoon;
    while (temp)
    {
        cartoon_sprite_head sprite_head; //
        sprite_head.x = temp->getPositionX();
        sprite_head.y = temp->getPositionY();
        MyFrame *frame = temp->rootFrame;
        sprite_head.frame_count = frame->getCount();
        fwrite(&sprite_head,sizeof(sprite_head),1,hFile);
        while (frame)
        {
            cartoon_frame_data frame_data;
            frame_data.texture_id = frame->textureId;
            fwrite(&frame_data,1,sizeof(frame_data),hFile);
            frame = frame->next;
        }
        
        fwrite(idle_block,1,64,hFile); //
        temp = temp->next;
    }
    fclose(hFile);
}
