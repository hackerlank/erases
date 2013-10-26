/**
 * email:jjl_2009_hi@163.com
 * Author jijinlong
 * Data 2011.10.14~2012.3.18~~
 * All Rights Resvered
 ***/
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <map>
#include "tinyxml.h"
#include <vector>
namespace script{
	/**
 	 * ��ȡ����ֵ
 	 * */
	class xmlNodeAttr{
	public:
		/**
 		 * ��������
 		 * \param ext ����������
 		 * */
		virtual void setExtData(void * ext);
		/*
 		 * ��ȡ��3������
 		 * \return ��3������ָ��
 		 * **/
		virtual void*getExtData();

		void *extData; // ��������
		std::map<std::string,std::string> attrs; // �����б�
		typedef std::map<std::string,std::string>::iterator ATTR_ITER;	
		/**
 		 * �жϵ�ǰ�ڵ� ����
 		 * \param name ����
 		 * \return ���true ����false
 		 * */
		bool equal(const char *name);
		
		/**
 		 * �жϵ�ǰ�ڵ� 
 		 * \param str ����
 		 * \return ������
 		 * */
		bool equal(std::string str);
		
		/**
 		 * ��ȡ��ǰ�ڵ�
 		 * \param name ����
 		 * \param value out floatֵ
 		 * \return �������
 		 * */
		virtual bool getAttr(const char *name,float& value);
		/**
 		 * ��ȡ��ǰ�ڵ�
 		 * \param name ����
 		 * \param value out intֵ
 		 * \return �������
 		 * */
        template<class T>
        bool getAttr(const char *name,T& value)
        {
            ATTR_ITER iter = attrs.find(name);
            if (iter!=attrs.end())
            {
                value = atoi(iter->second.c_str());
                return true;
            }
            return false;
        }
		bool getAttr(const char *name,std::string &contnt);
		float getFloat(const char *name);
		int getInt(const char *name);
		bool getBool(const char *name);
		/**
 		 * ��ȡ��ǰ�ڵ�
 		 * \param name ����
 		 * \param value out �ַ������� size �����С 
 		 * \return �������
 		 * */

		virtual bool getAttr(const char *name,char *value,unsigned int size);
		/**
 		 * ��ȡ��ǰ�ڵ�����
 		 * \param name ��������
 		 * \return ����ֵ
 		 * */
		virtual const char *getAttr(const char *name);
		std::string nodeName; // ��ǰ�ڵ�
	};
///////////////////tinyxml/////////////////////////	
	
	/*
	 * tinyxml Node �ڵ�
	 **/
	class tixmlCodeNode:public xmlNodeAttr{
	public:
		tixmlCodeNode();
		~tixmlCodeNode();
		/**
 		 *\return  �ڵ�����
 		 * */
		const char*name();
		/**
 		 * ��ȡ�ӽڵ����һ���ڵ�
 		 * \return �ӽڵ���һ���ڵ�
 		 * */
		virtual tixmlCodeNode *childnext();
		/**
 		 * �ӽڵ㼯��
 		 * */
		std::vector<tixmlCodeNode*> childs;
		typedef std::vector<tixmlCodeNode*>::iterator CHILDS_ITER;
		TiXmlElement * element; // tixml �Ľڵ�
		/**
		 * �Ƿ���Ч
		 */
		bool isValid();
		/**
		 * ��ȡ�׸�����Ϊname �Ľڵ�
		 */
		tixmlCodeNode getFirstChildNode(const char *name);
		/**
		 * ��ȡ��һ������Ϊname�Ľڵ�
		 */
		tixmlCodeNode getNextNode(const char *name);
		/**
		 * ��ʼ�� 
		 * \param element �ڵ�����
		 * \return �ɹ����
		 * */
		bool init(TiXmlElement * element);
		unsigned int nowChildIndex; // ��ǰ�ӽڵ����	
		tixmlCodeNode *next; // ��ǰ��һ���ڵ� 
		tixmlCodeNode *parent; // ��ǰ���׽ڵ�
		/**
 		 * �����׸��ڵ�
 		 * */
		tixmlCodeNode *firstChild();
		/**
 		 * ���ýڵ��ı�����
 		 * <XXX>text</XXX>
 		 * ���õ�text �������text XXX Ϊ�ڵ�
 		 * */
		void setText(std::string & text);
		/**
 		 * �ͷ���Դ
 		 * \return �ɹ� ���
 		 * */
		bool release();
		std::string text; // �ı�����
        /**
         * ��ӡ��ִ����
         */
        void traceInfo();
		/**
		 * ��ֵ����
		 */
		tixmlCodeNode & operator = (const tixmlCodeNode & node);
	};
	/*
	 * ���������ļ��õ��ڵ�
	 **/
	 class tixmlCode{
	 public:
		/**
 		 * ��ʼ��
 		 * \param filename �ļ���
 		 * \return �ɹ����	
 		 * */
		virtual bool init(const char *fileName);
		/**
		 * ���ַ����г�ʼ��
		 */
		bool initFromString(const char *content);
		bool initWithXmlFile(const char *fileName);
		/**
 		 * ��ȡ<XXXX> �ڵ� ������
 		 * \param node �ڵ�
 		 * */
		virtual void takeNode(tixmlCodeNode *node){};
		/**
 		 * ��ȡ<code> �ڵ� ������
 		 * \param code �ű��ڵ�
 		 * **/
		virtual void parseCode(tixmlCodeNode *code){};
		/**
 		 * �ͷ���Դ
 		 * */
		virtual void release(){return;}
		/**
 		 * ����code  �ڵ� ��ȡִ����
 		 * \parma root NULL 
 		 * \param node ��ǰ<code>�ڵ�
 		 * \return code
 		 * */
		tixmlCodeNode * traceNode1(tixmlCodeNode *root,TiXmlNode *node);
		/**
 		 * ��ȡ�ڵ����Ϊ
 		 * \param name �ڵ�����
 		 * \return ��Ϊ
 		 * */
		virtual void * getAction(const char *name){return NULL;};
	};
	
};
