/*
** Lua binding: GLES_Render
** Generated automatically by tolua++-1.0.92 on Sat Sep 28 17:31:04 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"
#include "GLES-Render.h"
/* Exported function */
TOLUA_API int  tolua_GLES_Render_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_GLESDebugDraw (lua_State* tolua_S)
{
 GLESDebugDraw* self = (GLESDebugDraw*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"b2Vec2");
 tolua_usertype(tolua_S,"float32");
 tolua_usertype(tolua_S,"b2Draw");
 tolua_usertype(tolua_S,"b2AABB");
 tolua_usertype(tolua_S,"GLESDebugDraw");
 tolua_usertype(tolua_S,"b2Color");
 tolua_usertype(tolua_S,"b2Transform");
}

/* method: new of class  GLESDebugDraw */
#ifndef TOLUA_DISABLE_tolua_GLES_Render_GLESDebugDraw_new00
static int tolua_GLES_Render_GLESDebugDraw_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GLESDebugDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GLESDebugDraw* tolua_ret = (GLESDebugDraw*)  Mtolua_new((GLESDebugDraw)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GLESDebugDraw");
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

/* method: new_local of class  GLESDebugDraw */
#ifndef TOLUA_DISABLE_tolua_GLES_Render_GLESDebugDraw_new00_local
static int tolua_GLES_Render_GLESDebugDraw_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GLESDebugDraw",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   GLESDebugDraw* tolua_ret = (GLESDebugDraw*)  Mtolua_new((GLESDebugDraw)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GLESDebugDraw");
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

/* method: new of class  GLESDebugDraw */
#ifndef TOLUA_DISABLE_tolua_GLES_Render_GLESDebugDraw_new01
static int tolua_GLES_Render_GLESDebugDraw_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GLESDebugDraw",0,&tolua_err) ||
   //  (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"float32",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float32 ratio = tolua_tonumber(tolua_S,2,0);
  {
   GLESDebugDraw* tolua_ret = (GLESDebugDraw*)  Mtolua_new((GLESDebugDraw)(ratio));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GLESDebugDraw");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GLES_Render_GLESDebugDraw_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GLESDebugDraw */
#ifndef TOLUA_DISABLE_tolua_GLES_Render_GLESDebugDraw_new01_local
static int tolua_GLES_Render_GLESDebugDraw_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GLESDebugDraw",0,&tolua_err) ||
     //(tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"float32",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float32 ratio =  tolua_tonumber(tolua_S,2,0);
  {
   GLESDebugDraw* tolua_ret = (GLESDebugDraw*)  Mtolua_new((GLESDebugDraw)(ratio));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GLESDebugDraw");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_GLES_Render_GLESDebugDraw_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawPolygon of class  GLESDebugDraw */
#ifndef TOLUA_DISABLE_tolua_GLES_Render_GLESDebugDraw_DrawPolygon00
static int tolua_GLES_Render_GLESDebugDraw_DrawPolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GLESDebugDraw",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const b2Vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const b2Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GLESDebugDraw* self = (GLESDebugDraw*)  tolua_tousertype(tolua_S,1,0);
  const b2Vec2* vertices = ((const b2Vec2*)  tolua_tousertype(tolua_S,2,0));
  int vertexCount = ((int)  tolua_tonumber(tolua_S,3,0));
  const b2Color* color = ((const b2Color*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawPolygon'",NULL);
#endif
  {
   self->DrawPolygon(vertices,vertexCount,*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawPolygon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawSolidPolygon of class  GLESDebugDraw */
#ifndef TOLUA_DISABLE_tolua_GLES_Render_GLESDebugDraw_DrawSolidPolygon00
static int tolua_GLES_Render_GLESDebugDraw_DrawSolidPolygon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GLESDebugDraw",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const b2Vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const b2Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GLESDebugDraw* self = (GLESDebugDraw*)  tolua_tousertype(tolua_S,1,0);
  const b2Vec2* vertices = ((const b2Vec2*)  tolua_tousertype(tolua_S,2,0));
  int vertexCount = ((int)  tolua_tonumber(tolua_S,3,0));
  const b2Color* color = ((const b2Color*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawSolidPolygon'",NULL);
#endif
  {
   self->DrawSolidPolygon(vertices,vertexCount,*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawSolidPolygon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawCircle of class  GLESDebugDraw */
#ifndef TOLUA_DISABLE_tolua_GLES_Render_GLESDebugDraw_DrawCircle00
static int tolua_GLES_Render_GLESDebugDraw_DrawCircle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GLESDebugDraw",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const b2Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"float32",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const b2Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GLESDebugDraw* self = (GLESDebugDraw*)  tolua_tousertype(tolua_S,1,0);
  const b2Vec2* center = ((const b2Vec2*)  tolua_tousertype(tolua_S,2,0));
  float32 radius = *((float32*)  tolua_tousertype(tolua_S,3,0));
  const b2Color* color = ((const b2Color*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawCircle'",NULL);
#endif
  {
   self->DrawCircle(*center,radius,*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawCircle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawSolidCircle of class  GLESDebugDraw */
#ifndef TOLUA_DISABLE_tolua_GLES_Render_GLESDebugDraw_DrawSolidCircle00
static int tolua_GLES_Render_GLESDebugDraw_DrawSolidCircle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GLESDebugDraw",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const b2Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"float32",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const b2Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const b2Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GLESDebugDraw* self = (GLESDebugDraw*)  tolua_tousertype(tolua_S,1,0);
  const b2Vec2* center = ((const b2Vec2*)  tolua_tousertype(tolua_S,2,0));
  float32 radius = *((float32*)  tolua_tousertype(tolua_S,3,0));
  const b2Vec2* axis = ((const b2Vec2*)  tolua_tousertype(tolua_S,4,0));
  const b2Color* color = ((const b2Color*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawSolidCircle'",NULL);
#endif
  {
   self->DrawSolidCircle(*center,radius,*axis,*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawSolidCircle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawSegment of class  GLESDebugDraw */
#ifndef TOLUA_DISABLE_tolua_GLES_Render_GLESDebugDraw_DrawSegment00
static int tolua_GLES_Render_GLESDebugDraw_DrawSegment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GLESDebugDraw",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const b2Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const b2Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const b2Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GLESDebugDraw* self = (GLESDebugDraw*)  tolua_tousertype(tolua_S,1,0);
  const b2Vec2* p1 = ((const b2Vec2*)  tolua_tousertype(tolua_S,2,0));
  const b2Vec2* p2 = ((const b2Vec2*)  tolua_tousertype(tolua_S,3,0));
  const b2Color* color = ((const b2Color*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawSegment'",NULL);
#endif
  {
   self->DrawSegment(*p1,*p2,*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawSegment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawTransform of class  GLESDebugDraw */
#ifndef TOLUA_DISABLE_tolua_GLES_Render_GLESDebugDraw_DrawTransform00
static int tolua_GLES_Render_GLESDebugDraw_DrawTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GLESDebugDraw",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const b2Transform",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GLESDebugDraw* self = (GLESDebugDraw*)  tolua_tousertype(tolua_S,1,0);
  const b2Transform* xf = ((const b2Transform*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawTransform'",NULL);
#endif
  {
   self->DrawTransform(*xf);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawPoint of class  GLESDebugDraw */
#ifndef TOLUA_DISABLE_tolua_GLES_Render_GLESDebugDraw_DrawPoint00
static int tolua_GLES_Render_GLESDebugDraw_DrawPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GLESDebugDraw",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const b2Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"float32",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const b2Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GLESDebugDraw* self = (GLESDebugDraw*)  tolua_tousertype(tolua_S,1,0);
  const b2Vec2* p = ((const b2Vec2*)  tolua_tousertype(tolua_S,2,0));
  float32 size = *((float32*)  tolua_tousertype(tolua_S,3,0));
  const b2Color* color = ((const b2Color*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawPoint'",NULL);
#endif
  {
   self->DrawPoint(*p,size,*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DrawAABB of class  GLESDebugDraw */
#ifndef TOLUA_DISABLE_tolua_GLES_Render_GLESDebugDraw_DrawAABB00
static int tolua_GLES_Render_GLESDebugDraw_DrawAABB00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GLESDebugDraw",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"b2AABB",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const b2Color",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GLESDebugDraw* self = (GLESDebugDraw*)  tolua_tousertype(tolua_S,1,0);
  b2AABB* aabb = ((b2AABB*)  tolua_tousertype(tolua_S,2,0));
  const b2Color* color = ((const b2Color*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DrawAABB'",NULL);
#endif
  {
   self->DrawAABB(aabb,*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawAABB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_GLES_Render_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"GLESDebugDraw","GLESDebugDraw","b2Draw",tolua_collect_GLESDebugDraw);
  #else
  tolua_cclass(tolua_S,"GLESDebugDraw","GLESDebugDraw","b2Draw",NULL);
  #endif
  tolua_beginmodule(tolua_S,"GLESDebugDraw");
   tolua_function(tolua_S,"new",tolua_GLES_Render_GLESDebugDraw_new00);
   tolua_function(tolua_S,"new_local",tolua_GLES_Render_GLESDebugDraw_new00_local);
   tolua_function(tolua_S,".call",tolua_GLES_Render_GLESDebugDraw_new00_local);
   tolua_function(tolua_S,"new",tolua_GLES_Render_GLESDebugDraw_new01);
   tolua_function(tolua_S,"new_local",tolua_GLES_Render_GLESDebugDraw_new01_local);
   tolua_function(tolua_S,".call",tolua_GLES_Render_GLESDebugDraw_new01_local);
   tolua_function(tolua_S,"DrawPolygon",tolua_GLES_Render_GLESDebugDraw_DrawPolygon00);
   tolua_function(tolua_S,"DrawSolidPolygon",tolua_GLES_Render_GLESDebugDraw_DrawSolidPolygon00);
   tolua_function(tolua_S,"DrawCircle",tolua_GLES_Render_GLESDebugDraw_DrawCircle00);
   tolua_function(tolua_S,"DrawSolidCircle",tolua_GLES_Render_GLESDebugDraw_DrawSolidCircle00);
   tolua_function(tolua_S,"DrawSegment",tolua_GLES_Render_GLESDebugDraw_DrawSegment00);
   tolua_function(tolua_S,"DrawTransform",tolua_GLES_Render_GLESDebugDraw_DrawTransform00);
   tolua_function(tolua_S,"DrawPoint",tolua_GLES_Render_GLESDebugDraw_DrawPoint00);
   tolua_function(tolua_S,"DrawAABB",tolua_GLES_Render_GLESDebugDraw_DrawAABB00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_GLES_Render (lua_State* tolua_S) {
 return tolua_GLES_Render_open(tolua_S);
};
#endif

