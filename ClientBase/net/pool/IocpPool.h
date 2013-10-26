#pragma once
#include <winsock2.h>
#include <MSWSock.h>
#pragma comment(lib,"ws2_32.lib")
#include "../network.h"
#include "MyList.h"
#include <list>
namespace pool{
	enum EVENT_TYPE{
		ACCEPT_EVT = 1 << 0, // ��ʼ��
		OUT_EVT = 1 << 1, // ����
		IN_EVT =1 << 2, // ���
		ERR_EVT = 1 << 3, // ����
	};
	void load()
	{
		WSADATA wsaData;
		int nResult;
		nResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	}
	
	void unload()
	{
		
	}
	class EventBase;
	/**
	 * Ŀ�����
	 */
	class Target{
	public:
		virtual HANDLE getHandle() = 0;
		virtual LPFN_ACCEPTEX getAcceptHandle(){return NULL;}
		virtual HANDLE getPeerHandle() {return NULL;}
		EventBase *inEvt;
		EventBase *outEvt;
		Target()
		{
			inEvt = outEvt = NULL;
		}
		virtual void destroy()
		{
			if (inEvt)
				delete inEvt;
			if (outEvt)
				delete outEvt;
			inEvt = NULL;
			outEvt = NULL;
		}
		virtual void doSend(pool::EventBase *evt){};
	};
	/**
	 * �¼�����
	 */
	class EventBase{
	public:
		Target * target; // Ŀ��
		OVERLAPPED     overlapped; 
		int eventType;     // ��ʶ�������������(��Ӧ�����ö��)
		unsigned dataLen; // ���ݴ���ĳ���
		virtual void deal() = 0;
		EventBase(Target * target):target(target)
		{
			
		}
		virtual HANDLE getPeerHandle() {return NULL;}
		
		bool isIn()
		{
			return eventType &IN_EVT;
		}
		bool isOut()
		{
			return eventType & OUT_EVT;
		}
		bool isErr()
		{
			return eventType & ERR_EVT;
		}
		bool isAccept()
		{
			return eventType & ACCEPT_EVT;
		}
		virtual void redo() = 0;
		static const unsigned int MAX_BUFFER_LEN = 8192;
	};
	/**
	 * �¼�
	 */
    template<typename TARGET>
	class Event:public EventBase{
    public:
        Event(TARGET *target):EventBase(target)
        {
			reset();
		}
        TARGET * operator->()
        {
            return (TARGET*)target;
        }
        bool checkValid()
        {
            return target;
        }
        
		
		                              // ÿһ���ص�����������ص��ṹ(���ÿһ��Socket��ÿһ����������Ҫ��һ��)              
		WSABUF         m_wsaBuf;                                   // WSA���͵Ļ����������ڸ��ص�������������
		char           buffer[MAX_BUFFER_LEN];                 // �����WSABUF�������ַ��Ļ�����
		           
		DWORD msgLen;
		
		HANDLE poolHandle; // ��ǰ�ؾ��
		virtual void reset()
		{
			memset(buffer,0,MAX_BUFFER_LEN);
			memset(&overlapped,0,sizeof(overlapped));  
			m_wsaBuf.buf = buffer;
			m_wsaBuf.len = MAX_BUFFER_LEN;
			eventType     = 0;
			msgLen = 0;
		}
		virtual void deal(){};
		virtual void redo(){deal();}
    };
	/**
	 * �����¼�
	 */
	template<typename TARGET>
	class InEvent:public Event<TARGET>{
	public:
		InEvent(TARGET *target):Event<TARGET>(target)
        {
			
		}
		void deal()
		{
			DWORD dwFlags = 0;
			DWORD dwBytes = 0;
			WSABUF *p_wbuf   = &m_wsaBuf;
			OVERLAPPED *p_ol = &overlapped;

			reset();
			eventType = IN_EVT;
			int nBytesRecv = WSARecv((SOCKET)target->getHandle(), p_wbuf, 1, &msgLen, &dwFlags, p_ol, NULL );
			if ((SOCKET_ERROR == nBytesRecv) && (WSA_IO_PENDING != WSAGetLastError()))
			{
				return;
			}
		}
	};
	/**
	 * ����¼�
	 */
	template<typename TARGET>
	class OutEvent:public Event<TARGET>{
	public:
		OutEvent(TARGET *target):Event<TARGET>(target)
		{
			
		}
		void deal()
		{
			DWORD dwFlags = 0;
			DWORD dwBytes = 0;
			WSABUF *p_wbuf   = &m_wsaBuf;
			OVERLAPPED *p_ol = &overlapped;
			eventType = OUT_EVT;
			p_wbuf->buf = buffer;
			int nBytesRecv = WSASend((SOCKET)target->getHandle(), p_wbuf, 1, &dwBytes, dwFlags, p_ol, NULL );
			if ((SOCKET_ERROR == nBytesRecv) && (WSA_IO_PENDING != WSAGetLastError()))
			{
				return;
			}
			return;
		}
	};
	/**
	 *  ��ʼ���¼�
	 **/
	template<typename TARGET>
	class AcceptEvent:public Event<TARGET>{
	public:
		AcceptEvent(TARGET *target):Event<TARGET>(target)
		{
			SOCKET socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);  
			if( INVALID_SOCKET ==  socket)  
			{  
				return;  
			} 
			handle = socket;	
		}
		void deal()
		{
			DWORD dwBytes = 0;  
			eventType = ACCEPT_EVT;  
			WSABUF *p_wbuf   = &m_wsaBuf;
			OVERLAPPED *p_ol = &overlapped;
			// Ͷ��AcceptEx
			if(FALSE == (target->getAcceptHandle())((SOCKET)target->getHandle(),
								handle,
								p_wbuf->buf,0,   
										sizeof(SOCKADDR_IN)+16, sizeof(SOCKADDR_IN)+16, &dwBytes, p_ol)) 
			{  
				
			}
		}
		SOCKET handle;
		virtual HANDLE getPeerHandle() {return (HANDLE)handle;}
	};
	/**
	 * �¼��صķ�װ
	 **/
    class EventPool {
    public:
        EventPool()
        {
           
        }
		bool init()
		{
			poolHandle = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0 );
			return poolHandle != NULL;
		}
		HANDLE poolHandle;
        void bindEvent(Target *target,int eventType)
		{
			 HANDLE tempHandle = CreateIoCompletionPort((HANDLE)target->getHandle(), poolHandle, (DWORD)target, 0);
			 if (eventType & ACCEPT_EVT)
			 {
				target->inEvt = new AcceptEvent<Target>(target);
				target->inEvt->deal();
			 }
			 if (eventType & IN_EVT)
			 {
				target->inEvt = new InEvent<Target>(target);
				target->inEvt->deal();
			 }
			 if (eventType & OUT_EVT)
			 {
				target->outEvt = new OutEvent<Target>(target);
				target->doSend(target->outEvt);
			 }
		}

		EventBase* pullEvent()
		{
			// ��ȡһ���¼�
			OVERLAPPED *pOverlapped = NULL;
			Target*target = NULL;
			DWORD dataLen = 0;
			BOOL bReturn = GetQueuedCompletionStatus(
				poolHandle,
				&dataLen,
				(PULONG_PTR)&target,
				&pOverlapped,
				INFINITE
			);
			// ����յ������˳���־����ֱ���˳�
			if ( 0==(DWORD)target)
			{
				return NULL;
			}
			// �ж��Ƿ�����˴���
			if( !bReturn )  
			{  
				return NULL;  
			}  
			else  
			{
				// ��ȡ����Ĳ���
				EventBase* evt = CONTAINING_RECORD(pOverlapped, EventBase, overlapped); 
				evt->dataLen = dataLen;
				// ����evt ����״̬
				if (dataLen == 0 && (evt->isIn() || evt->isOut()))
				{
					evt->eventType = ERR_EVT; // ���ó���״̬
				}
				return evt;
			}
			return NULL;
		}
    };
 };
 namespace net{
	 class Connection:public pool::Target{
	 public:
		 virtual void destroy()
		 {
			pool::Target::destroy();
			closesocket(socket);
		 }
		 Connection()
		 {
			directDealCmd = true;
		 }
		 HANDLE getHandle(){return (HANDLE)socket;}
		 void setHandle(SOCKET socket){this->socket = socket;}
		 
		 /**
		  * ������Ϣ
		  */
		 void sendCmd(void *cmd,unsigned int len)
		 {
			Decoder  decoder;
			decoder.encode(cmd,len);
		//	sends.push_back(decoder.getRecord());
			sends.write(decoder.getRecord());
			if (outEvt)
				doSend(outEvt);
		 }
		 void recvCmdCallback(void *cmd,unsigned int len)
		 {
			// �ص��д�����Ϣ
		 }
		 Decoder decoder;
		 bool directDealCmd;
		 /** 
		  * ��ȡ��Ϣ
		  */
		 unsigned int getCmd(void *cmd,unsigned int len)
		 {
			return decoder.decode(this,cmd,len);
		 }
		 /**
		  * ����Ϣ���ܵ�����
		  **/
		 unsigned int recv(void *cmd,unsigned int size)
		 {
			unsigned int realcopy = 0;
		//	while (recvs.size())
			while (!recvs.empty())
			{
				//Record *record = recvs.front();
				Record *record = NULL;
				if (recvs->readOnly(record))
				{
					realcopy = record->recv(cmd,size);
					if (record->empty())
					{
						delete record;
						//recvs.pop_front();
						recvs.pop();
					}
					if (realcopy == size)
					{
						return size;
					}
				}else break;
			}
			return realcopy;
		}
		
		/**
		 * ��pool �д������
		 **/
		 void doRead(pool::EventBase *evt,stGetPackage *callback = NULL)
		{
			pool::Event<Connection>* event = static_cast<pool::Event<Connection>*>( evt );
			if (directDealCmd) // ֱ�Ӵ�����Ϣ
			{
				Record record(event->m_wsaBuf.buf,evt->dataLen);
				decoder.decode(&record,callback);
			}
			else
			{
				Record *record = new Record(event->m_wsaBuf.buf,evt->dataLen);
				//recvs.push_back(record);
				recvs.write(record);
			}
			evt->redo();
		}
		/**
		 * ��pool �д�����
		 **/
		void doSend(pool::EventBase *evt)
		{
			bool tag = false;
			
			pool::Event<Connection>* event = static_cast<pool::Event<Connection>*>( evt );
			event->dataLen = 0;
			event->reset();
			while (!sends.empty())
			{
				tag = true;
				Record *record = NULL;
				// record = send.front();
				if (sends.readOnly(record))
				{
					int leftLen = pool::EventBase::MAX_BUFFER_LEN;
					unsigned int realCopySize = record->recv(event->buffer,leftLen);
					evt->dataLen += realCopySize;
					if (leftLen == realCopySize)
					{
						if (record->empty())
						{
							delete record;
						//	sends.pop_front();
							sends.pop();
						}
						break;
					}
					else
					{
						leftLen -= realCopySize;
						if(!record->empty())
						{
							// TODO ERROR
						}
						//sends.pop_front();
						sends.pop();
					}
				}else break;
			}
			if (tag)
				evt->redo();
		}
		 // ��ǰ�¼� ����˲ʱ��
		 SOCKET socket;
		// std::list<Record*> recvs;
		MyList<Record*> recvs;
		// std::list<Record*> sends;
		MyList<Record*> sends;
	 };
	 class Client:public Connection{
	 public:
		 Client(const char *ip,WORD port)
		 {
			init(ip,port);
		 }
		 void init(const char *ip,WORD port)
		 {
			 socket = ::socket(AF_INET,SOCK_STREAM,0);
			if(socket == INVALID_SOCKET)
			{
				// TODO error
			}
			memset(&addrServer,0,sizeof(sockaddr_in));
			addrServer.sin_family = AF_INET;
			addrServer.sin_addr.s_addr = inet_addr(ip);
			addrServer.sin_port = htons(port);

			if(connect(socket,(const struct sockaddr *)&addrServer,sizeof(sockaddr)) != 0)
			{
				// TODO error
			}
		 }
		 struct sockaddr_in addrServer;
	 };
	 class Server:public pool::Target{
	 public:
		Server(const char *ip,WORD port)
		{
			init(ip,port);
			GUID GuidAcceptEx = WSAID_ACCEPTEX;  
			DWORD dwBytes = 0;  
			if(SOCKET_ERROR == WSAIoctl(
				socket, 
				SIO_GET_EXTENSION_FUNCTION_POINTER, 
				&GuidAcceptEx, 
				sizeof(GuidAcceptEx), 
				&m_lpfnAcceptEx, 
				sizeof(m_lpfnAcceptEx), 
				&dwBytes, 
				NULL, 
				NULL))  
			{  
			}
			
		}
		void init(const char *ip,WORD port)
		{
			struct sockaddr_in ServerAddress;

			// �������ڼ�����Socket����Ϣ

			socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

			// ����ַ��Ϣ
			ZeroMemory((char *)&ServerAddress, sizeof(ServerAddress));
			ServerAddress.sin_family = AF_INET;
			//ServerAddress.sin_addr.s_addr = htonl(INADDR_ANY);                      
			ServerAddress.sin_addr.s_addr = inet_addr(ip);         
			ServerAddress.sin_port = htons(port);                          

			// �󶨵�ַ�Ͷ˿�
			if (SOCKET_ERROR == bind(socket, (struct sockaddr *) &ServerAddress, sizeof(ServerAddress))) 
			{
				return;
			}
			else
			{
			}

			// ��ʼ���м���
			if (SOCKET_ERROR == listen(socket,SOMAXCONN))
			{
				return;
			}
			else
			{
			}
		}
	
		HANDLE getHandle(){return (HANDLE)socket;}
		SOCKET socket;
		LPFN_ACCEPTEX getAcceptHandle()
		{
			return m_lpfnAcceptEx;
		}
		LPFN_ACCEPTEX                m_lpfnAcceptEx; 
	 };
 };
