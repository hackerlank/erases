/**
 * email:ji.jin.dragon@gmail.com
 * Author jijinlong
 * Data 2011.10.14~~~
 * All Rights Resvered
 ***/
#pragma once
#include "sstream"
#include "stdio.h"
#include "iostream"
#include "string.h"
#include "string"
#include "vector"
#include "set"
#include <map>
#include "cocos2d.h"
#define _USE_ZLIB_
#define _USE_BASE64_
#ifdef _USE_ZLIB_ 
	#include "zlib.h"
#endif
#include "list"
#ifdef _USE_BASE64_
	#include "Base64.h"
#endif

#define IMP_SERIALIZE_DATA_START(__class__)\
	void __class__::__v_store__(serialize::Stores &sts,unsigned char tag)\

#define IMP_SERIALIZE_DATA_FUNC()\
	virtual void __v_store__(serialize::Stores &sts,unsigned char tag)\

#define IMP_SERIALIZE_DATA_FUNC_CONDITION(__result__)\
	void __v_store__(serialize::Stores &sts,unsigned char tag){\
		if ((!(__result__))&& tag == __STORE__ ) return;

#define SERIALIZE_DATA(__value__,index)\
	switch(tag)\
	{\
		case __STORE__:\
		{\
			sts.addStore(__value__,index);\
		}break;\
		case __LOAD__:\
		{\
			sts.getStore(__value__,index);\
		}break;\
	}
#define SERIALIZE_DATA_CONDITION(__value__,index,__result__)\
	switch(tag)\
	{\
		case __STORE__:\
		{\
			if ((__result__))\
			sts.addStore(__value__,index);\
		}break;\
		case __LOAD__:\
		{\
			sts.getStore(__value__,index);\
		}break;\
	}

#define IMP_SERIALIZE_DATA_END }
#define IMP_SERIALIZE_DATA_FUNC_END } 
#define CALL_SERIALIZE(__class__)\
		__class__::__store__(ss,tag);
#define __STORE__ 1
#define __LOAD__ 2

#define DEC_SERIALIZE_DATA void __v_store__(serialize::Stores &ss,unsigned char tag)

namespace serialize{
	const unsigned int MAX_NAME_SIZE= 32;
	#pragma pack(1)
	const unsigned char __DATA_OBJECT__=1; // point ����
	const unsigned char __DATA_OBJECT_MAP__ =2; // map ����<normal,point> ����
	const unsigned char __DATA_OBJECT_VECTOR__ = 3;
	const unsigned char __DATA__INT__ = 4;
	const unsigned char __DATA_FLOAT__ = 5;
	const unsigned char __DATA_UNSIGNED_INT__ = 6;
	const unsigned char __DATA_CHAR__ = 7;
	const unsigned char __DATA_LONG__ = 8;
	const unsigned char __DATA_UNSINGED_CHAR__ = 9;
	const unsigned char __DATA_UNSINGED_LONG__ = 10;
	const unsigned char __DATA_UNSINGED_FLOAT__ = 11;
	const unsigned char __DATA_LONG_LONG__ = 12;
	const unsigned char __DATA_UNSINGED_LONG_LONG__ = 13;	
	const unsigned char __VOID_STAR_POINT__ = 14;
	const unsigned char __DATA_STRING__ = 15;
	typedef int SEARCH_ARG; 
	/**
	 * ��¼ͷ���̶�����
	 **/
	struct CoreData{
		unsigned char tag; // ����
		int hashcode; // ���� ȡǰ4����У��
		unsigned int size; // ��С
		CoreData()
		{
			memset(this,0,sizeof(CoreData));
		}
	};
	#pragma pack()
	/**
	 * ��¼
	 **/
	struct Store{
		CoreData coreData; // ��¼ͷ
		std::vector<char> content; // ��¼����
		Store()
		{
		}
		/**
		 * ��ʼ��
		 * \param content �����׵�ַ
		 * \param size ��С
		 * \param name ��¼����
		 **/
		Store(void *content,int size,SEARCH_ARG name)
		{
			this->content.resize(size);
			memcpy(&this->content[0],content,size);
			//strncpy(coreData.name,name,MAX_NAME_SIZE -1 );
			coreData.hashcode = name;//sys::HashStr::calc(name);
			coreData.tag = 1;
			coreData.size = size;
		}
		/**
		 *  ��ʼ��
		 * \param tag ��¼���� __DATA_DWORD__ ��
		 * \param content �����׵�ַ
		 * \param size ��С
		 * \param name ��¼���� 
		 **/
		Store(unsigned char tag,void *content,int size,SEARCH_ARG name)
		{
			this->content.resize(size);
			memcpy(&this->content[0],content,size);
			//strncpy(coreData.name,name,MAX_NAME_SIZE -1 );
			coreData.hashcode = name;//sys::HashStr::calc(name);
			coreData.tag = tag;
			coreData.size = size;
		}
		/**
		 * ��ֵ����
		 **/
		Store & operator=(const Store & store)
		{
			content.resize(0);
			content.insert(content.begin(),store.content.begin(), store.content.end());	
			//strncpy(this->coreData.name,store.coreData.name,MAX_NAME_SIZE-1);
			this->coreData.hashcode = store.coreData.hashcode;
			coreData.tag = store.coreData.tag;
			coreData.size = store.coreData.size;
			return *this;
		}
		bool equal(SEARCH_ARG name)
		{
			return (coreData.hashcode == name /*sys::HashStr::calc(name)*/);
		}
		/**
		 * �������
		 */
		void setIndex(int index)
		{
			this->coreData.hashcode = index;
		}
		/** 
		 * ��ȡ���index
		 **/
		int getIndex()
		{
			return coreData.hashcode;
		}
	};
	/**
	 * ��
	 **/
	struct Stream{
		std::vector<char> content; // ����
		int offset;
		Stream()
		{
			NCHAR = '\0';
			offset = 0;
		}
		/**
		 * ������
		 */
		void reset();
		/**
		 * ��ʼ����
		 * \param buf�׵�ַ
		 * \param size buf����
		 **/
		Stream(void *str,unsigned int size)
		{
			content.resize(size);
			memcpy(&content[0],str,size);	
			offset = 0;
			NCHAR = '\0';
		}
		Stream & operator = (const Stream & str)
		{
			content = str.content;
			offset = str.offset;
			NCHAR = '\0';
			return *this;
		}
		/**
		 * ���ô���С
		 * \param size ����С
		 **/
		void resize(unsigned int size)
		{
			content.resize(size);
		}
#ifdef _USE_ZLIB_
		/**
		 * ѹ��
		 **/
		void compress(char *buffer,unsigned int size)
		{
			//toBase64();
			memset(buffer,0,size);
			uLongf lSize = size;
			if (!lSize) return;
			::compress((unsigned char*)buffer,&lSize,(unsigned char*)&content[0],this->size());
			content.resize(lSize);
			memcpy(&content[0],buffer,lSize);
		}
		/**
		 * ��ѹ
		 **/
		void uncompress(char *buffer,unsigned int size)
		{
			memset(buffer,0,size);
			uLongf lSize = size;
			::uncompress((unsigned char *)buffer,&lSize,(unsigned char*)&content[0],this->size());
			content.resize(lSize);
			memcpy(&content[0],buffer,lSize);
			//fromBase64(buffer,size);
		}
#endif
#ifdef _USE_BASE64_
		void toBase64()
		{
			std::string temp;
			Base64::encode(&content[0],content.size(),temp);
			content.resize(temp.size());
			memcpy(&content[0],temp.c_str(),content.size()+1);	
		}
		void fromBase64()
		{
			if (content.empty()) return;
			std::string temp;
			std::string in(&content[0],content.size());
			Base64::decode(in,temp);
			if (temp.size())
			{
				content.resize(temp.size());
				memcpy(&content[0],&temp[0],temp.size());
			}
		}
#endif
		char NCHAR; // �շ���
		/**
		 * ����������ʷ���
		 **/
		char & operator[](unsigned int i )
		{
			if (i < content.size())
				return content[i];
			return NCHAR;
		}
		char *c_str()
		{
			if (this->content.empty()) return NULL;
			return &this->content[0];
		}
		unsigned int size(){return (int)content.size();}
		
		/**
		 * д���ļ�
		 * \param fileName �ļ���
		 **/
		void writeToFile(const char * fileName);
		/**
		 * ���ļ��ж���
		 * \param fileName �ļ���
		 **/
		void readFromFile(const char *fileName);

		/**
		 * ����һ��Store
		 */
		void addStore(Store & store);
		/**
		 * ��ȡ��һ��Store
		 */
		bool pickStore(Store &store);

		/**
		 * ����һ������
		 * \param data ָ��
		 * \param size ���ݳ���
		 */
		void addData(void *data,int size);
		/**
		 * ��ȡָ�����ȵ�����
		 * \param data �ⲿ���ݻ���
		 * \param size �������ݵĳ���
		 * \return �ɹ�true ʧ��false
		 */
		bool pickData(void *data,int size);
	};
	class Stores;	
	/**
	 * ���л����� ��Ҫ�̳�֮
	 * */
	struct Object{
		/**
		 * ��2��������ת��Ϊ����
		 * \param content 2��������
		 * \param size ���ݴ�С
		 **/
		void parse(void * content,unsigned int size)
		{
			if (!size) return;
			Stream ss(content,size);
			parseRecord(ss);
		}
		/**
		 * �����ݿ�����content ��,
		 * \param content ����
		 * \param size �����С
		 **/
		void store(void *content,unsigned int size)
		{
			Stream ss = toRecord();
			if (ss.size() > size) return;
			memcpy(content,&ss[0],ss.size() < size ? ss.size() : size); 
		}
		/**
		 * �����ݿ�����content ��,
		 * \param content ���� vector
		 **/
		void store(std::vector<char>& content)
		{
			Stream ss = toRecord();
			content.resize(ss.size());
			memcpy(&content[0],&ss[0],ss.size()); 
		}
		/**
		 * �����ݿ�����content ��,
		 * \param content ���� vector
		 **/
		void store(std::vector<unsigned char>& content)
		{
			Stream ss = toRecord();
			content.resize(ss.size());
			memcpy(&content[0],&ss[0],ss.size()); 
		}
		/**
		 * ��ȡ������
		 * \return ��
		 **/
		virtual	Stream toRecord()
		{
			Stream ss;
			__store__(ss,__STORE__);
			return ss;
		}
		/**
		 * ����ת��Ϊ����
		 * \param record ��
		 * \return �ɹ� ʧ��
		 **/
		virtual bool parseRecord(Stream &record)
		{
			if (!record.size()) return false;
			__store__(record,__LOAD__);
			return true;	
		}
		/**
		* ��תΪ���� ���߶���תΪ��
		* \param ss in/out ��
		* \param tag __LOAD__ ת��Ϊ���� __STORE__ תΪ��
		* ������ʵ��
		**/
		virtual void __store__(Stream & ss,unsigned char tag);
		virtual void __v_store__(Stores & sts,unsigned char tag){
			//printf("û�ж����ʼ������%x\n",this);
		};
		/**
 		 * Ԥ������
 		 * */
		virtual void preLoad( Stream & ss){}
		/**
		 * Ԥ���洢
		 * */
		virtual void preStore(){}	
		/**
 		 * ���سɹ�
 		 * */
		virtual void beLoaded( Stream & ss){}
		/*
 		 * �洢�ɹ�
 		 * */
		virtual void beStored(){}
		/**
		 * ��ȡ���������
		 * ���������Ҫָ��־û���,��Ҫʵ�ָú���
		 * \return �ö��������
		 */
		virtual int takeKind() {return -1;}
	};
#define SERIALIZE_KIND(kind) virtual int takeKind(){return kind;}

#define DEC_STORE_CELL_FUNC(__class__,__type__)\
bool addStore(__class__ value,SEARCH_ARG name);\
bool getStore(__class__ &value,SEARCH_ARG name);

#define DO_MAKE_STREAM(__type__)\
void makeStream(__type__& value,Stream& stream)\
{\
	stream = Stream(&value,sizeof(__type__));\
}\
void makeStream(__type__* value,Stream& stream)\
{\
	stream = Stream(value,sizeof(__type__));\
}

#define DO_PARSE_STREAM(__type__)\
void parseStream(__type__& value,Stream& stream)\
{\
	if (stream.size() ==0) return;\
	if (sizeof(__type__) == stream.size())\
	{\
		value = *(__type__*) (&stream.content[0]);\
		return;\
	}\
	switch (stream.size())	\
	{\
		case sizeof(char):\
		{\
			value = (__type__)*(char*) (&stream.content[0]);\
		}break;\
		case sizeof(short):\
		{\
			 value = (__type__)*(short*) (&stream.content[0]);\
		}break;\
		case sizeof(int):\
		{\
			 value = (__type__)*(int*) (&stream.content[0]);\
		}break;\
		case sizeof(long long):\
		{\
			 value = (__type__)*(long long*) (&stream.content[0]);\
		}break;\
	}\
}\
void parseStream(__type__* value,Stream& stream)\
{\
	if (stream.size() ==0) return;\
	if (sizeof(__type__) == stream.size())\
	{\
		value = (__type__*) (&stream.content[0]);\
		return;\
	}\
	switch (stream.size())	\
	{\
		case sizeof(char):\
		{\
			value = (__type__*)(char*) (&stream.content[0]);\
		}break;\
		case sizeof(short):\
		{\
			 value = (__type__*)(short*) (&stream.content[0]);\
		}break;\
		case sizeof(int):\
		{\
			 value = (__type__*)(int*) (&stream.content[0]);\
		}break;\
		case sizeof(long long):\
		{\
			 value = (__type__*)(long long*) (&stream.content[0]);\
		}break;\
	}\
}
	/**
	 * �洢
	 **/
	class Stores{
	public:
		Stores(){
		}
		/**
		 * תΪ������
		 * \return ��
		 **/
		Stream toRecord();
		
		/**
		 * תΪ��¼����
		 * \param record ��
		 **/
		void parseRecord(Stream& record);
	
		/**
		 * ����һ��store 
		 **/
		void addStore(Store& store);
	
		/**
		 * ��ȡһ��store
		 */
		bool pickStore(Store& store,SEARCH_ARG name);
		

		DO_MAKE_STREAM(int);
		DO_MAKE_STREAM(float);
		DO_MAKE_STREAM(unsigned int);
		DO_MAKE_STREAM(double);
		DO_MAKE_STREAM(long long);
		DO_MAKE_STREAM(unsigned long long);
		DO_MAKE_STREAM(char);
		DO_MAKE_STREAM(unsigned char);
		DO_MAKE_STREAM(long);
		DO_MAKE_STREAM(short);
		DO_MAKE_STREAM(unsigned short);
		DO_MAKE_STREAM(unsigned long);
		
		DO_PARSE_STREAM(int);
		DO_PARSE_STREAM(float);
		DO_PARSE_STREAM(unsigned int);
		DO_PARSE_STREAM(double);
		DO_PARSE_STREAM(long long);
		DO_PARSE_STREAM(unsigned long long);
		DO_PARSE_STREAM(char);
		DO_PARSE_STREAM(unsigned char);
		DO_PARSE_STREAM(long);
		DO_PARSE_STREAM(unsigned short);
		DO_PARSE_STREAM(short);
		DO_PARSE_STREAM(unsigned long);
		/**
		 * ��T stream ת��Ϊ����
		 */
		template<typename T>
		void parseStream(T&object,Stream &stream)
		{
			object.parseRecord(stream);
		}
		/**
		 * ��T stream ת��Ϊ ����ָ��
		 */
		template<typename T>
		void parseStream(T * &object,Stream &stream)
		{
			int kind = 0;
			if (stream.pickData(&kind,sizeof(kind)))
			{
				//if (object == NULL)
				object = T::create(kind);
				if (object && stream.size() > sizeof(kind))
				{
					Stream os(&stream.content[sizeof(kind)], stream.size() - sizeof(kind));
					object->parseRecord(os);
				}
			}
		}
		/**
		 * ��T ����ת��Ϊstream
		 */
		template<typename T>
		void makeStream(T& object,Stream &stream)
		{
			stream = object.toRecord();
		}
		/**
		 * ��ָ�����ת��Ϊstream
		 **/
		template<typename T>
		void makeStream(T*& object,Stream &stream)
		{
			if (!object) return;
			// ָ�����ͽ����⴦�����ݿ�
			int kind = object->takeKind();
			stream.addData(&kind,sizeof(kind));
			Stream ostr = object->toRecord();
			stream.addData(ostr.c_str(),ostr.size());
		}
		/**
		 * ������string ʹstring ת��Ϊstream ����
		 */
		void makeStream(std::string str,Stream &stream);
		/**
		 * ��string �л�ȡstream
		 */
		void parseStream(std::string & str,Stream &stream);
		
		/**
		 * �־û�string ����stream
		 */
		void addStore(std::string str,SEARCH_ARG name);

		template<typename T>
		void addStore(T ty,SEARCH_ARG name)
		{
			Stream s;
			makeStream(ty,s);
			Store store (__DATA_OBJECT__,&(s.content[0]),s.size(),name);
			addStore(store);
		}
		/**
		 * ���л� point ���� �̳��� Object
		 * \param object ����ָ��
		 * \param name ��¼����
		 **/
		template <typename T>
		void addStore(T *object,SEARCH_ARG name)
		{
			if (!object) return;
			Stream s;
			makeStream(object,s);
			Store store (__DATA_OBJECT__,&(s.content[0]),s.size(),name);
			addStore(store);
		}
		/**
		 * �־û���map ����
		 */
		template<typename T,typename O>
		void doMakeCollectionStream(T& objects,O* o,Stream& s)
		{
			if (objects.empty()) return;
			std::vector<char> content;
			content.resize(1024);
			unsigned int offset = 0;
			for (typename T::iterator iter = objects.begin(); iter != objects.end();++iter)
			{
				O& rO = *iter;
				Stream s;
				makeStream(rO,s);
				unsigned int size = s.size();
				if (content.size() < offset + size + sizeof(int))
				{
					content.resize(offset + size + sizeof(int) + 1);
				}
				memcpy(&content[offset],&size,sizeof(unsigned int));
				memcpy(&content[offset + sizeof(unsigned int)],&s.content[0],s.size());
				offset += sizeof(unsigned int) + s.size();
			}
			s = Stream(&content[0],offset);
		}
		/**
		 * ���Ӽ�¼���洢��
		 * \param value std::vector<char>  ��ֵ
		 * \param name ��¼����
		 **/
		template <typename T>
		void addStore(std::list<T> objects,SEARCH_ARG name)
		{
			Stream stream;
			T *o = NULL;
			doMakeCollectionStream(objects,o,stream);
			if (stream.size())
			{
				Store store(__DATA_OBJECT_VECTOR__,&stream.content[0],stream.size(),name);
				addStore(store);
			}
		}
		/**
		 * ���Ӽ�¼���洢��
		 * \param value std::vector<char>  ��ֵ
		 * \param name ��¼����
		 **/
		template<typename T>
		void addStore(std::vector<T>& objects,SEARCH_ARG name)
		{
			Stream stream;
			T *t = NULL;
			doMakeCollectionStream(objects,t,stream);
			if (stream.size())
			{
				Store store(__DATA_OBJECT_VECTOR__,&stream.content[0],stream.size(),name);
				addStore(store);
			}
		}
		/**
		 * ���Ӽ�¼���洢��
		 * \param value std::vector<char>  ��ֵ
		 * \param name ��¼����
		 **/
		void addStore(std::vector<char>& objects,SEARCH_ARG name)
		{
			Stream stream(&objects[0],objects.size());
			if (stream.size())
			{
				Store store(__DATA_OBJECT_VECTOR__,&stream.content[0],stream.size(),name);
				addStore(store);
			}
		}
		/**
		 * ���л� <set> int unsigned short �Ȼ�������
		 * \param objects ���ݼ���
		 * \param name ��¼����
		 **/
		template<typename T>
		void addStore(std::set<T> &objects,SEARCH_ARG name)
		{
			Stream stream;
			T * o = NULL;
			doMakeCollectionStream(objects,o,stream);
			Store store(__DATA_OBJECT_VECTOR__,&stream.content[0],stream.size(),name);
			addStore(store);
		}
		/**
		 * ���л� {name,point} ���ݼ��� �̳��� Object
		 * \param objects ���ݼ���
		 * \param name ��¼����
		 **/
		template<typename Key,typename Value>
		void addStore(std::map<Key,Value>& objects,SEARCH_ARG name)
		{
			std::vector<char> content;
			content.resize(1024);
			unsigned int offset = 0;
			for (typename std::map<Key,Value>::iterator iter = objects.begin(); iter != objects.end();++iter)
			{
				// ��¼key�ĳ��� unsigned int
				// ��¼key��ֵ size
				// ��¼value�ĳ��� unsigned int 
				// ��¼value��ֵ size
				Key key = iter->first;
				Stream ss;
				makeStream(key,ss);
				unsigned int keySize = ss.size();
				Value  value = iter->second;
				Stream s; 
				makeStream(value,s);
				unsigned int valueSize = s.size(); 
				if (content.size() < offset + keySize)
				{
					content.resize(offset + keySize * 2 + valueSize + sizeof(unsigned int)*2);
				}

				memcpy(&content[offset],&keySize,ss.size());
				offset += sizeof(unsigned int);

				memcpy(&content[offset],&ss.content[0],keySize);
				offset += keySize;
				
				memcpy(&content[offset],&valueSize,sizeof(unsigned int));
				offset += sizeof(unsigned int);
				if (content.size() < offset + valueSize)
				{
					content.resize(offset + valueSize * 2 + sizeof(unsigned int) * 2);
				}

				memcpy(&content[offset],&s.content[0],s.size());
				offset += s.size();
			}
			Store store(__DATA_OBJECT_MAP__,&content[0],offset,name);
			addStore(store);
		}
		/**
		 * ��ȡ {name,point} ���ݼ��� �̳��� Object
		 * \param objects ���ݼ���
		 * \param name ��¼����
		 **/
		template<typename Key,typename Value>
		bool getStore(std::map<Key,Value> &objects,SEARCH_ARG name)
		{
			Store nowstore;
			pickStore(nowstore,name);
			if (nowstore.equal(name))
			{
				Store *store = &nowstore;
				switch( store->coreData.tag)
				{
					case __DATA_OBJECT_MAP__:
					{
						unsigned int offset = 0;
						if (store->coreData.size != store->content.size()) return false;
						while(offset < store->coreData.size )
						{
							unsigned int keySize = *(unsigned int*)&store->content[offset];
							if (keySize > store->coreData.size)
							{
								printf("[find an error %s:%u,%u]\n",__FILE__,__LINE__,keySize);
								return false;
							}
							
							Stream skey;
							skey.content.resize(keySize);
							memcpy(&skey.content[0],&store->content[offset+sizeof(unsigned int)],keySize);
							Key key;
							parseStream(key,skey);
							offset += sizeof(unsigned int) + keySize;

							unsigned int valueSize = 0;
							memcpy(&valueSize,&store->content[offset],sizeof(unsigned int));
							offset += sizeof(unsigned int);
							if (valueSize > store->coreData.size)
							{
								return false;
							}	
							Stream sr;
							sr.content.resize(valueSize);
							memcpy(&sr.content[0],&store->content[offset],valueSize);
							Value object;
							parseStream(object,sr);
							objects[key] = (object);
							offset += valueSize;
						}
						return true;
					}break;
				}

			}
			return false;
		}
		/**
		 * ��ȡ {name,point} ���ݼ��� �̳��� Object
		 * \param objects ���ݼ���
		 * \param name ��¼����
		 **/
		template<class T>
		bool getStore(std::set<T>& objects,SEARCH_ARG name)
		{
			Store nowstore;
			pickStore(nowstore,name);
			if (nowstore.equal(name))
			{
				Store *store = &nowstore;
				switch( store->coreData.tag)
				{
					case __DATA_OBJECT_VECTOR__:
					{
						unsigned int offset = 0;
						if (store->coreData.size != store->content.size()) return false;
						while(offset < store->coreData.size )
						{
							unsigned int size = *(unsigned int*)&store->content[offset];
							if (size > store->coreData.size)
							{
								printf("[find an error %s:%u, headerSize:%u,coreSize:%u]\n",__FILE__,__LINE__,size,store->coreData.size);
								break;
							}
							Stream sR;
							sR.content.resize(size);
							memcpy(&sR.content[0],&store->content[offset+sizeof(unsigned int)],size);
							T object;
							parseStream(object,sR);
							objects.insert(object);
							offset += sizeof(unsigned int) + size;
						}
						return true;
					}break;
				}
			}
			return false;
		}

		/**
		 * ��ȡ {name,point} ���ݼ��� �̳��� Object
		 * \param objects ���ݼ���
		 * \param name ��¼����
		 **/
		template<class T>
		bool getStore(std::list<T>& objects,SEARCH_ARG name)
		{
			Store nowstore;
			pickStore(nowstore,name);
			if (nowstore.equal(name))
			{
				Store *store = &nowstore;
				switch( store->coreData.tag)
				{
					case __DATA_OBJECT_VECTOR__:
					{
						unsigned int offset = 0;
						if (store->coreData.size != store->content.size()) return false;
						while(offset < store->coreData.size )
						{
							unsigned int size = *(unsigned int*)&store->content[offset];
							if (size > store->coreData.size)
							{
								printf("[find an error %s:%u,%u]\n",__FILE__,__LINE__,size);
								break;
							}
							Stream sR;
							sR.content.resize(size);
							memcpy(&sR.content[0],&store->content[offset+sizeof(unsigned int)],size);
							T object;
							parseStream(object,sR);
							objects.push_back(object);
							offset += sizeof(unsigned int) + size;
						}
						return true;
					}break;
				}
			}
			return false;
		}
		
		/**
		 * ��ȡ {name,point} ���ݼ��� �̳��� Object
		 * \param objects ���ݼ���
		 * \param name ��¼����
		 **/
		template<class T>
		bool getStore(std::vector<T>& objects,SEARCH_ARG name)
		{
			Store nowstore;
			pickStore(nowstore,name);
			if (nowstore.equal(name))
			{
				Store *store = &nowstore;
				switch( store->coreData.tag)
				{
					case __DATA_OBJECT_VECTOR__:
					{
						unsigned int offset = 0;
						if (store->coreData.size != store->content.size()) return false;
						while(offset < store->coreData.size )
						{
							unsigned int size = *(unsigned int*)&store->content[offset];
							if (size > store->coreData.size)
							{
								printf("[find an error %s:%u,%u]\n",__FILE__,__LINE__,size);
								break;
							}
							Stream sR;
							sR.content.resize(size);
							memcpy(&sR.content[0],&store->content[offset+sizeof(unsigned int)],size);
							T object;
							parseStream(object,sR);
							objects.push_back(object);
							offset += sizeof(unsigned int) + size;
						}
						return true;
					}break;
				}
			}
			return false;
		}
		/**
		 * ���Ӽ�¼���洢��
		 * \param value std::vector<char>  ��ֵ
		 * \param name ��¼����
		 **/
		bool getStore(std::vector<char>& objects,SEARCH_ARG name)
		{
			Store nowstore;
			pickStore(nowstore,name);
			if (nowstore.equal(name))
			{
				Store *store = &nowstore;
				switch( store->coreData.tag)
				{
					case __DATA_OBJECT_VECTOR__:
					{
						unsigned int offset = 0;
						if (store->coreData.size != store->content.size()) return false;
						objects.resize(store->coreData.size);
						memcpy(&objects[0],&store->content[0],store->coreData.size);
					}break;
				}
			}
			return false;
		}
		/**
		 * ��ȡ point ���� �̳��� Object
		 * \param object ����
		 * \param name ��¼����
		 **/
		template <typename T>
		bool getStore(T* &object,SEARCH_ARG name)
		{
		//	printf("[stores] store object %s\n",name.c_str());
			Store nowstore;
			pickStore(nowstore,name);
			if (nowstore.equal(name))
			{
				Store *store = &nowstore;
				if (store->content.empty()) return false;
				serialize::Stream ss(&store->content[0],store->coreData.size);
				parseStream(object,ss);
			}
			return false;
		}

		/**
		 * ��ȡ������������
		 * \param name ��¼����
		 * \param t ��¼
		 **/
		template <class T>
		bool getStore(T &t,SEARCH_ARG name)
		{
			Store nowstore;
			pickStore(nowstore,name);
			if (nowstore.equal(name))
			{
				Store *store = &nowstore;
				if (store->content.empty()) return false;
				Stream ss(&store->content[0],store->coreData.size);
				parseStream(t,ss);
				return true;
			}
			return false;
		}

		DEC_STORE_CELL_FUNC(int,__DATA__INT__);
		DEC_STORE_CELL_FUNC(unsigned short,__DATA__INT__);
		DEC_STORE_CELL_FUNC(float,__DATA_FLOAT__);
		DEC_STORE_CELL_FUNC(unsigned int ,__DATA_UNSIGNED_INT__);
		DEC_STORE_CELL_FUNC(char,__DATA_CHAR__);
		DEC_STORE_CELL_FUNC(long,__DATA_LONG__);
		DEC_STORE_CELL_FUNC(unsigned char,__DATA_UNSINGED_CHAR__);
		DEC_STORE_CELL_FUNC(unsigned long,__DATA_UNSINGED_LONG__);
		DEC_STORE_CELL_FUNC(long long,__DATA_LONG_LONG__);
		DEC_STORE_CELL_FUNC(unsigned long long,__DATA_UNSINGED_LONG_LONG__);
		/**
		 * ����һ��store
		 * \param value ������ʼ��ַ
		 * \param size ���ݳ���
		 * \param name ������
		 */
		bool addStore(const void *value,unsigned int size,SEARCH_ARG name);
			
	private:
#if (0)
		Stream stream; // ���õ�stream �˰治��
#endif	
		std::vector<Store> stores; // �������õ�store �洢
	};
};
