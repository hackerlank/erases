//
//  CocosNet.cpp
//  Dragon
//
//  Created by GameDeveloper on 13-10-20.
//
//

#include "CocosNet.h"
#include "mythread.h"
#if (1)
#include "CCLuaEngine.h"
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "tolua++.h"
#include "tolua_fix.h"
}
#endif
class WorkThread:public thread::Thread{
public:
	WorkThread():thread::Thread("WORKTHREAD"){
		net = NULL;
	}
    
	void run()
	{
		net->run();
	}
	CocosNet *net;
};
void IO::start(CocosNet *net)
{
	WorkThread * work = new WorkThread;
	work->net = net;
	work->start();
}
using namespace cocos2d;
using namespace mynet;
void CocosNet::newClient(int index,const char *ip,unsigned short port)
{
    if (index < clients.size())
    {
        mynet::Client *client = clients[index];
        if (client)
        {
            if (!client->checkValid())
            {
                client->reconnect();
                pool->bindEvent(client,IN_EVT|OUT_EVT);
            }
            return;
        }
    }
    mynet::Client *client = new mynet::Client(ip,port);
	
	pool->bindEvent(client,IN_EVT|OUT_EVT);
    
    if (index >= clients.size())
    {
        clients.resize(index + 1);
    }
    clients[index] = client;
}
void CocosNet::updateClient(int index)
{
    if (index < clients.size())
    {
        mynet::Client *client = clients[index];
        if (client)
        {
            if (!client->checkValid())
            {
                client->reconnect();
                pool->bindEvent(client,IN_EVT|OUT_EVT);
            }
            return;
        }
    }
}

void CocosNet::updateTimer(float dt)
{
    popCommands();
}

void CocosNet::init()
{
    if (valid) return;
    if (pool) return;
	valid = true;
    pool = new EventPool();
	pool->init();
    cocos2d::CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(CocosNet::updateTimer), this, 1.0f/15.0f, false);
    io.start(this);
}
void CocosNet::sendCmd(int index,void *cmd,unsigned int len)
{
    if (index < clients.size())
    {
        mynet::Client *client = clients[index];
        if (client)
            client->sendCmd(cmd,len);
    }
}
void CocosNet::stop()
{
    cocos2d::CCDirector::sharedDirector()->getScheduler()->unscheduleSelector(schedule_selector(CocosNet::updateTimer),this);
    valid = false;
    
}

/**
 * 
 */
void CocosNet::run()
{
#if (1)
	while (valid) // 
	{
		EventBase *evt = pool->pullEvent();
		if (evt)
		{
			if (evt->isErr()) // 
			{
				Connection *conn = (Connection*) evt->target;
				if (conn)
				{
					conn->destroy();
					//delete conn;
				}
				continue;
			}
			if (evt->isOut()) //
			{
				Connection *connEvt = (Connection*) evt->target;
				if (evt->target)
				{
					connEvt->doSend(evt);
				}
			}
			if (evt->isIn()) //
			{
				Connection *connEvt = (Connection*) evt->target;
				if (evt->target)
				{
					connEvt->doRead(evt,this);
				}
			}
            
		}
	}
#endif
}

void CocosNet::sendtoServer(int index,LuaReqData *reqData)
{
    this->updateClient(index);
    protoStringCmd cmd;
    setReqData(reqData);
    cmd.reqID = reqData->reqId;
    cmd.content = reqData->content;
    reqData->retain();
    sendObject(index, &cmd);
}
static long filesize(FILE *stream)
{
	long curpos, length;
	curpos = ftell(stream);
	fseek(stream, 0L, SEEK_END);
	length = ftell(stream);
	fseek(stream, curpos, SEEK_SET);
	return length;
}

void CocosNet::handle(void *cmd, unsigned int len)
{
#if (1)
	// ¥¶¿Ìªÿµ˜
    if (*(int*) cmd == 1)
    {
        protoStringCmd stringCmd;
        stringCmd.parsecmd(cmd, len);
        printf("%s",stringCmd.content.c_str());
        LuaReqData *reqData = (LuaReqData*)getReqData(stringCmd.reqID);
        if (reqData)
        {
            // lua ¥¶¿Ì∑Ω Ω
            lua_getglobal(CCLuaEngine::defaultEngine()->getLuaState(), "doLuaNetCallback");
            if (!lua_isfunction(CCLuaEngine::defaultEngine()->getLuaState(), -1))
            {
                CCLOG("[LUA ERROR] name '%s' does not represent a Lua function", "doLuaNetCallback");
                lua_pop(CCLuaEngine::defaultEngine()->getLuaState(), 1);
                return;
            }
    
            tolua_pushusertype(CCLuaEngine::defaultEngine()->getLuaState(), reqData, "LuaReqData");
            CCLuaEngine::defaultEngine()->pushString(stringCmd.content.c_str());
            //int ret = CCLuaEngine::defaultEngine()->getLuaStack()->executeFunction(2);
			lua_pcall(CCLuaEngine::defaultEngine()->getLuaState(),2,0,0);
            //CCLuaEngine::defaultEngine()->clean();


            removeReqData(reqData);
            reqData->release();
        }
    }
    if (*(int*) cmd == 8)
    {
        stSendFileInfo rev;
        rev.parsecmd(cmd,len);
        std::string t =  rev.fileName;
        FILE * stream = fopen(t.c_str(),"a+");
        if (stream)
        {
            if (filesize(stream) != rev.offset)
            {
                //      printf("写入文件失败\n");
            }
            else
            {
                fwrite(&rev.buffer[0],rev.buffer.size(),1,stream);
            }
            fclose(stream);
            printf("%s 文件写入成功 %u\n",rev.fileName.c_str(),rev.offset);
        }
        else printf("文件不存在 %s",rev.fileName.c_str());
    }
#endif
}
void CocosNet::sendToServer(int index,int reqId, const char *content)
{
    this->updateClient(index);
    protoStringCmd cmd;
    cmd.reqID = reqId;
    cmd.content = content;
    sendObject(index, &cmd);
}

/*
 * »∑∂®Œƒº˛¥Û–° ∫Õ ∆ º÷µ
 */
void CocosNet::sendFile(int index,const char *fileName)
{
	stWaitSendFileInfo* info = new stWaitSendFileInfo();
	info->fileName = fileName;
	std::string realpath = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName);
	info->netIndex = index;
	FILE *file = fopen(realpath.c_str(),"rb");
	if (!file)
	{
		delete info;
		return;
	}
	info->fileSize = filesize(file);
	fclose(file);
	files.write(info);
}

void CocosNet::doSendFile()
{
	stWaitSendFileInfo* info;
	if (files.readOnly(info))
	{
		if (info->offset >= info->fileSize)
		{
			files.pop();
			delete info;
		}
		else
		{
			int left = info->fileSize - info->offset;
			if (left >= 8192) left = 8192;
			std::string realpath = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(info->fileName.c_str());
			FILE *file = fopen(realpath.c_str(),"rb");
			if (!file) return;
			fseek(file,info->offset,SEEK_CUR);
			stSendFileInfo cmd;
			cmd.fileName = info->fileName;
			cmd.buffer.resize(left);
			cmd.offset = info->offset;
			fread(&cmd.buffer[0],left,1,file);
			sendObject(info->netIndex,&cmd);
			fclose(file);
			info->offset += left;
		}
	}
}