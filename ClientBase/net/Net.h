#pragma once
#include "handle.h"
#include "NetCommand.h"
#include "pool.h"
#include "thread.h"
/**
 * theNet.bind(command,new FuncCall<CALSS>(this,function);
 * visit()
 * {
     theNet.popCommands(); // �������ַ���Ϣ
 *}
 */

// TODO ���𲻼�϶�����
// TODO ���������Ϣ������
// TODO ���߼���ѭ����ַ��¼�
// TODO ��������Ϣ
// ���� �������Ϣ��һ���߳���

class Net:public Hanldes,public zThread,public net::RecvPackageCallback{
public:
	Net()
	{
		init();
	}
	// ��ʼ�� �������� �� �����߳�
	void init()
	{
		valid = true;
		pool::load();
		client.init"127.0.0.1",5050);
		pool.bindEvent(&client,pool::IN_EVT|pool::OUT_EVT);
		start(); // �����߳�
	}
	void stop()
	{
		valid = false;
	}
	pool::EventPool pool;
	pool.init();
	net::Client client;
	static Net & getMe()
	{
		static Net t;
		return t;
	}
	void bind(unsigned short commandID,MsgFuncHandler *handler)
	{
		addHandle(commandID,handler);
	}
	/**
	 * �߳�������
	 */
	void run()
	{
		while (valid) // ���������߳̿��
		{
			pool::EventBase *evt = pool.pullEvent();
			if (evt)
			{
				if (evt->isErr()) // ����ɾ��
				{
					pool::Event<net::Connection> *connEvt = (pool::Event<net::Connection>*) evt;
					net::Connection *conn = (net::Connection*) connEvt->target;
					if (conn)
					{
						conn->destroy();
						delete conn;
					}
					continue;
				}
				if (evt->isOut()) // д
				{
					pool::Event<net::Connection> *connEvt = (pool::Event<net::Connection>*) evt;
					if (connEvt->target)
					{
						(*connEvt)->doSend(evt);
					}
				}
				if (evt->isIn()) // ��
				{
					pool::Event<net::Connection> *connEvt = (pool::Event<net::Connection>*) evt;
					if (connEvt->target)
					{
						(*connEvt)->doRead(evt,this);
					}
				}
				
			}
		}
	}
	bool valid;

	void sendCmd(void *cmd,unsigned int len)
	{
		// ���뵽 ѭ�������� �������ַ��뱾������ ̫���򶪰�
		client.sendCmd(cmd,len);
	}
private:
	void handle(void *cmd,unsigned int len)
	{
		stNullCmd *nullCmd = (stNullCmd*) cmd;
		Hanldes::handle(nullCmd->type,cmd,len); // �����߼�
	}
	void doGetCommand(void *cmd,unsigned int len)
	{
		pushCommands(new Record(cmd,len));
	}
	void pushCommands(Record *record)
	{
	//	records.push_back(record); // ʹ��ѭ������ ������
	}
	//std::vector<Record*> records;
public:
	/**
	 * �ڳ���on_visit ����� ������ɾ��ʱ Ҫ���¼�����ȡ���Լ�
	 */
	void popCommands()
	{
		//handle(record->content,record->contentSize); ��ѭ��������ȡ����
	}
};

#define theNet Net::getMe()