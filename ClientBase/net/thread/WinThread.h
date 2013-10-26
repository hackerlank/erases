#pragma once
#include <list>
#include <windows.h>
#include <vector>
class zCond;
/**
* \brief �ٽ�������װ��ϵͳ�ٽ�����������ʹ��ϵͳ�ٽ���ʱ����Ҫ�ֹ���ʼ���������ٽ�������Ĳ���
*
*/
class zMutex
{

	friend class zCond;

public:
	/**
	* \brief ���캯��������һ�����������
	*
	*/
	zMutex() 
	{
		m_hMutex = CreateMutex(NULL,FALSE,NULL);
	}

	/**
	* \brief ��������������һ�����������
	*
	*/
	~zMutex()
	{
		CloseHandle(m_hMutex);
	}

	/**
	* \brief ����һ��������
	*
	*/
	inline void lock()
	{
		if( WaitForSingleObject(m_hMutex,10000) == WAIT_TIMEOUT )
		{
			//TODO error
		}
	}

	/**
	* \brief ����һ��������
	*
	*/
	inline void unlock()
	{
		ReleaseMutex(m_hMutex);
	}

private:

	HANDLE m_hMutex;    /**< ϵͳ������ */

};

/**
* \brief Wrapper
* �����ڸ��Ӻ���������ʹ��
*/
class zMutex_scope_lock
{

public:

	/**
	* \brief ���캯��
	* ��������lock����
	* \param m ��������
	*/
	zMutex_scope_lock(zMutex &m) : mlock(m)
	{
		mlock.lock();
	}

	/**
	* \brief ��������
	* ��������unlock����
	*/
	~zMutex_scope_lock()
	{
		mlock.unlock();
	}

private:

	/**
	* \brief ��������
	*/
	zMutex &mlock;

};
/**
* \brief ��װ��ϵͳ��д����ʹ����Ҫ�򵥣�ʡȥ���ֹ���ʼ��������ϵͳ��д���Ĺ�������Щ�����������ɹ��캯���������������Զ����
*
*/
class zRWLock
{

public:
	/**
	* \brief ���캯�������ڴ���һ����д��
	*
	*/
	zRWLock()
	{
		m_hMutex = CreateMutex(NULL,FALSE,NULL);
	}

	/**
	* \brief ������������������һ����д��
	*
	*/
	~zRWLock()
	{
		CloseHandle(m_hMutex);
	}

	/**
	* \brief �Զ�д�����ж���������
	*
	*/
	inline void rdlock()
	{
		WaitForSingleObject(m_hMutex,INFINITE);
	};

	/**
	* \brief �Զ�д������д��������
	*
	*/
	inline void wrlock()
	{
		WaitForSingleObject(m_hMutex,INFINITE);
	}

	/**
	* \brief �Զ�д�����н�������
	*
	*/
	inline void unlock()
	{
		ReleaseMutex(m_hMutex);
	}

private:

	HANDLE m_hMutex;    /**< ϵͳ��д�� */

};
/**
* \brief rdlock Wrapper
* �����ڸ��Ӻ����ж�д����ʹ��
*/
class zRWLock_scope_rdlock
{

public:

	/**
	* \brief ���캯��
	* ��������rdlock����
	* \param m ��������
	*/
	zRWLock_scope_rdlock(zRWLock &m) : rwlock(m)
	{
		rwlock.rdlock();
	}

	/**
	* \brief ��������
	* ��������unlock����
	*/
	~zRWLock_scope_rdlock()
	{
		rwlock.unlock();
	}

private:

	/**
	* \brief ��������
	*/
	zRWLock &rwlock;

};

/**
* \brief wrlock Wrapper
* �����ڸ��Ӻ����ж�д����ʹ��
*/
class zRWLock_scope_wrlock
{

public:

	/**
	* \brief ���캯��
	* ��������wrlock����
	* \param m ��������
	*/
	zRWLock_scope_wrlock(zRWLock &m) : rwlock(m)
	{
		rwlock.wrlock();
	}

	/**
	* \brief ��������
	* ��������unlock����
	*/
	~zRWLock_scope_wrlock()
	{
		rwlock.unlock();
	}

private:

	/**
	* \brief ��������
	*/
	zRWLock &rwlock;

};
/**
* \brief ��װ��ϵͳ����������ʹ����Ҫ�򵥣�ʡȥ���ֹ���ʼ��������ϵͳ���������Ĺ�������Щ�����������ɹ��캯���������������Զ����
*
*/
class zCond 
{

public:

	/**
	* \brief ���캯�������ڴ���һ����������
	*
	*/
	zCond()
	{
		m_hEvent = CreateEvent(NULL,FALSE,FALSE,NULL);
	}

	/**
	* \brief ������������������һ����������
	*
	*/
	~zCond()
	{
		CloseHandle(m_hEvent);
	}

	/**
	* \brief �����еȴ���������������̹߳㲥�����źţ�ʹ��Щ�߳��ܹ���������ִ��
	*
	*/
	void broadcast()
	{
		SetEvent(m_hEvent);
	}

	/**
	* \brief �����еȴ���������������̷߳����źţ�ʹ��Щ�߳��ܹ���������ִ��
	*
	*/
	void signal()
	{
		SetEvent(m_hEvent);
	}

	/**
	* \brief �ȴ��ض���������������
	*
	*
	* \param m_hMutex ��Ҫ�ȴ��Ļ�����
	*/
	void wait(zMutex &mutex)
	{
		WaitForSingleObject(m_hEvent,INFINITE);
	}

private:

	HANDLE m_hEvent;    /**< ϵͳ�������� */

};

/**
* \brief ��װ���̲߳���������ʹ���̵߳Ļ���
*
*/
class zThread
{
public:

	/**
	* \brief ���캯��������һ������
	*
	* \param name �߳�����
	* \param joinable ��������߳��˳���ʱ���Ƿ񱣴�״̬�����Ϊtrue��ʾ�߳��˳�����״̬�����򽫲������˳�״̬
	*/
	zThread(const std::string &name = std::string("zThread"),const bool joinable = true) 
		: threadName(name),alive(false),complete(false),joinable(joinable) { m_hThread = NULL; };

	/**
	* \brief ������������������һ�����󣬻��ն���ռ�
	*
	*/
	virtual ~zThread()
	{
		if (NULL != m_hThread)
		{
			CloseHandle(m_hThread);
		}
	};

	/**
	* \brief ʹ��ǰ�߳�˯��ָ����ʱ�䣬��
	*
	*
	* \param sec ָ����ʱ�䣬��
	*/
	static void sleep(const long sec)
	{
		::Sleep(1000 * sec);
	}

	/**
	* \brief ʹ��ǰ�߳�˯��ָ����ʱ�䣬����
	*
	*
	* \param msec ָ����ʱ�䣬����
	*/
	static void msleep(const long msec)
	{
		::Sleep(msec);
	}

	/**
	* \brief ʹ��ǰ�߳�˯��ָ����ʱ�䣬΢��
	*
	*
	* \param usec ָ����ʱ�䣬΢��
	*/
	static void usleep(const long usec)
	{
		::Sleep(usec / 1000);
	}

	/**
	* \brief �߳��Ƿ���joinable��
	*
	*
	* \return joinable
	*/
	const bool isJoinable() const
	{
		return joinable;
	}

	/**
	* \brief ����߳��Ƿ�������״̬
	*
	* \return �߳��Ƿ�������״̬
	*/
	const bool isAlive() const
	{
		return alive;
	}

	static DWORD WINAPI threadFunc(void *arg);
	bool start();
	void join();

	/**
	* \brief ���������߳�
	*
	* ��ʵֻ�����ñ�ǣ���ô�̵߳�run���ص�ѭ���ؼ�������ǣ�����������Ѿ����ã����˳�ѭ��
	*
	*/
	void final()
	{
		complete = true;
	}

	/**
	* \brief �ж��߳��Ƿ����������ȥ
	*
	* ��Ҫ����run()����ѭ���У��ж�ѭ���Ƿ����ִ����ȥ
	*
	* \return �߳����ص��Ƿ����ִ��
	*/
	const bool isFinal() const 
	{
		return complete;
	}

	/**
	* \brief ���鹹�������߳����ص�������ÿ����Ҫʵ��������������Ҫ�����������
	*
	* ���������ѭ����Ҫ��ÿ��ѭ������߳��˳����isFinal()�������ܹ���֤�̰߳�ȫ�˳�
	* <pre>
	*   while(!isFinal())
	*   {
	*     ...
	*   }
	*   </pre>
	*
	*/
	virtual void run() = 0;
	/**
	* \brief �����߳�����
	*
	* \return �߳�����
	*/
	const std::string &getThreadName() const
	{
		return threadName;
	}

public:

	std::string threadName;      /**< �߳����� */
	zMutex mlock;          /**< ������ */
	volatile bool alive;      /**< �߳��Ƿ������� */
	volatile bool complete;
	HANDLE m_hThread;        /**< �̱߳�� */
	bool joinable;          /**< �߳����ԣ��Ƿ�����joinable��� */

}; 

/**
* \brief ���߳̽��з���������
*
*/
class zThreadGroup
{

public:

	struct Callback
	{
		virtual void exec(zThread *e)=0;
		virtual ~Callback(){};
	};

	typedef std::vector<zThread *> Container;  /**< �������� */

	zThreadGroup();
	~zThreadGroup();
	void add(zThread *thread);
	zThread *getByIndex(const Container::size_type index);
	zThread *operator[] (const Container::size_type index);
	void joinAll();
	void execAll(Callback &cb);

	const Container::size_type size()
	{
		zRWLock_scope_rdlock scope_rdlock(rwlock);
		return vts.size();
	}

private:

	Container vts;                /**< �߳����� */
	zRWLock rwlock;                /**< ��д�� */

};