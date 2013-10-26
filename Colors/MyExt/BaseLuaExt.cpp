//
//  BaseLuaExt.cpp
//  Dragon
//
//  Created by GameDeveloper on 13-8-13.
//
//

#include "BaseLuaExt.h"
#include "LuaCocos2d.h"
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "tolua++.h"
#include "tolua_fix.h"
}

extern int  tolua_MyUI1_open (lua_State* tolua_S);
TOLUA_API int  tolua_BitMap_open (lua_State* tolua_S);
TOLUA_API int  tolua_luaCocosNet_open (lua_State* tolua_S);

NS_CC_BEGIN
BaseLuaExt* BaseLuaExt::create()
{
	BaseLuaExt * baseLuaExt = new BaseLuaExt();
	if (baseLuaExt)
	{
		baseLuaExt->init();
	}
	return baseLuaExt;
}
bool BaseLuaExt::init()
{
	tolua_BitMap_open(CCLuaEngine::defaultEngine()->getLuaState());
    tolua_MyUI1_open(CCLuaEngine::defaultEngine()->getLuaState());
    tolua_luaCocosNet_open(CCLuaEngine::defaultEngine()->getLuaState());
    return true;
}
NS_CC_END