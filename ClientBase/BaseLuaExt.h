/**
 * 
 */
#pragma once
#include "script_support/CCScriptSupport.h"
#include "CCLuaEngine.h"
NS_CC_BEGIN
/**
 * ��ͼlua����չ
 */
class BaseLuaExt:public CCLuaEngine{
public:
	BaseLuaExt()
	{
	}
	static BaseLuaExt* create();
	/**
	 * lua��������չ
	 */
	void initLuaExt();

	void doString(const char *cmd);
private:
};


NS_CC_END