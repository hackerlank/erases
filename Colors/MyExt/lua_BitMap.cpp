/*
** Lua binding: BitMap
** Generated automatically by tolua++-1.0.92 on Sun Sep 29 20:43:57 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

#include "BitMap.h"
/* Exported function */
TOLUA_API int  tolua_BitMap_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_BitMap (lua_State* tolua_S)
{
 BitMap* self = (BitMap*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"BitMap");
}

/* method: new of class  BitMap */
#ifndef TOLUA_DISABLE_tolua_BitMap_BitMap_new00
static int tolua_BitMap_BitMap_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BitMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   BitMap* tolua_ret = (BitMap*)  Mtolua_new((BitMap)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BitMap");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BitMap */
#ifndef TOLUA_DISABLE_tolua_BitMap_BitMap_new00_local
static int tolua_BitMap_BitMap_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BitMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   BitMap* tolua_ret = (BitMap*)  Mtolua_new((BitMap)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BitMap");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBlockId of class  BitMap */
#ifndef TOLUA_DISABLE_tolua_BitMap_BitMap_getBlockId00
static int tolua_BitMap_BitMap_getBlockId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BitMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BitMap* self = (BitMap*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBlockId'",NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getBlockId(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBlockId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOffset of class  BitMap */
#ifndef TOLUA_DISABLE_tolua_BitMap_BitMap_getOffset00
static int tolua_BitMap_BitMap_getOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BitMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BitMap* self = (BitMap*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOffset'",NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->getOffset(index);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  BitMap */
#ifndef TOLUA_DISABLE_tolua_BitMap_BitMap_set00
static int tolua_BitMap_BitMap_set00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BitMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BitMap* self = (BitMap*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
  {
   self->set(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  BitMap */
#ifndef TOLUA_DISABLE_tolua_BitMap_BitMap_set01
static int tolua_BitMap_BitMap_set01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BitMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  BitMap* self = (BitMap*)  tolua_tousertype(tolua_S,1,0);
  unsigned int startindex = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int size = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
  unsigned int value = ((unsigned int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'",NULL);
#endif
  {
   self->set(startindex,size,value);
  }
 }
 return 0;
tolua_lerror:
 return tolua_BitMap_BitMap_set00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: get of class  BitMap */
#ifndef TOLUA_DISABLE_tolua_BitMap_BitMap_get00
static int tolua_BitMap_BitMap_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BitMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BitMap* self = (BitMap*)  tolua_tousertype(tolua_S,1,0);
  unsigned int startindex = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
  unsigned int size = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'",NULL);
#endif
  {
   unsigned tolua_ret = (unsigned)  self->get(startindex,size);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reset of class  BitMap */
#ifndef TOLUA_DISABLE_tolua_BitMap_BitMap_reset00
static int tolua_BitMap_BitMap_reset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BitMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BitMap* self = (BitMap*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'reset'",NULL);
#endif
  {
   self->reset(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: test of class  BitMap */
#ifndef TOLUA_DISABLE_tolua_BitMap_BitMap_test00
static int tolua_BitMap_BitMap_test00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BitMap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BitMap* self = (BitMap*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'test'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->test(index);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'test'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  BitMap */
#ifndef TOLUA_DISABLE_tolua_BitMap_BitMap_clear00
static int tolua_BitMap_BitMap_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BitMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BitMap* self = (BitMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clear'",NULL);
#endif
  {
   self->clear();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clear'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: capacity of class  BitMap */
#ifndef TOLUA_DISABLE_tolua_BitMap_BitMap_capacity00
static int tolua_BitMap_BitMap_capacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BitMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BitMap* self = (BitMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'capacity'",NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->capacity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'capacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: size of class  BitMap */
#ifndef TOLUA_DISABLE_tolua_BitMap_BitMap_size00
static int tolua_BitMap_BitMap_size00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BitMap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BitMap* self = (BitMap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'size'",NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_BitMap_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"BitMap","BitMap","",tolua_collect_BitMap);
  #else
  tolua_cclass(tolua_S,"BitMap","BitMap","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"BitMap");
   tolua_function(tolua_S,"new",tolua_BitMap_BitMap_new00);
   tolua_function(tolua_S,"new_local",tolua_BitMap_BitMap_new00_local);
   tolua_function(tolua_S,".call",tolua_BitMap_BitMap_new00_local);
   tolua_function(tolua_S,"getBlockId",tolua_BitMap_BitMap_getBlockId00);
   tolua_function(tolua_S,"getOffset",tolua_BitMap_BitMap_getOffset00);
   tolua_function(tolua_S,"set",tolua_BitMap_BitMap_set00);
   tolua_function(tolua_S,"set",tolua_BitMap_BitMap_set01);
   tolua_function(tolua_S,"get",tolua_BitMap_BitMap_get00);
   tolua_function(tolua_S,"reset",tolua_BitMap_BitMap_reset00);
   tolua_function(tolua_S,"test",tolua_BitMap_BitMap_test00);
   tolua_function(tolua_S,"clear",tolua_BitMap_BitMap_clear00);
   tolua_function(tolua_S,"capacity",tolua_BitMap_BitMap_capacity00);
   tolua_function(tolua_S,"size",tolua_BitMap_BitMap_size00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_BitMap (lua_State* tolua_S) {
 return tolua_BitMap_open(tolua_S);
};
#endif

