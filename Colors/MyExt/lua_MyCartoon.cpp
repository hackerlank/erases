/*
** Lua binding: mycartoon
** Generated automatically by tolua++-1.0.92 on Wed Oct 23 23:01:34 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

#include "mycartoon.h"
/* Exported function */
TOLUA_API int  tolua_mycartoon_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_cartoon_frame_data (lua_State* tolua_S)
{
 cartoon_frame_data* self = (cartoon_frame_data*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_cartoon_file_head (lua_State* tolua_S)
{
 cartoon_file_head* self = (cartoon_file_head*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_MyCartoon (lua_State* tolua_S)
{
 MyCartoon* self = (MyCartoon*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_temp_texture (lua_State* tolua_S)
{
 temp_texture* self = (temp_texture*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_texture_data_len (lua_State* tolua_S)
{
 texture_data_len* self = (texture_data_len*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_cartoon_sprite_head (lua_State* tolua_S)
{
 cartoon_sprite_head* self = (cartoon_sprite_head*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_texture_data (lua_State* tolua_S)
{
 texture_data* self = (texture_data*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_MyFrame (lua_State* tolua_S)
{
 MyFrame* self = (MyFrame*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"cartoon_frame_data");
 tolua_usertype(tolua_S,"cartoon_file_head");
 tolua_usertype(tolua_S,"MyCartoon");
 tolua_usertype(tolua_S,"my_cartoon_file");
 tolua_usertype(tolua_S,"cartoon_sprite_head");
 tolua_usertype(tolua_S,"temp_texture");
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"CCTexture2D");
 tolua_usertype(tolua_S,"cc_timeval");
 tolua_usertype(tolua_S,"CCSprite");
 tolua_usertype(tolua_S,"texture_data_len");
 tolua_usertype(tolua_S,"CCSpriteFrame");
 tolua_usertype(tolua_S,"texture_data");
 tolua_usertype(tolua_S,"MyFrame");
}

/* get function: textureId of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_get_MyFrame_textureId
static int tolua_get_MyFrame_textureId(lua_State* tolua_S)
{
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textureId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->textureId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: textureId of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_set_MyFrame_textureId
static int tolua_set_MyFrame_textureId(lua_State* tolua_S)
{
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textureId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->textureId = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frameId of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_get_MyFrame_frameId
static int tolua_get_MyFrame_frameId(lua_State* tolua_S)
{
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frameId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->frameId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: frameId of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_set_MyFrame_frameId
static int tolua_set_MyFrame_frameId(lua_State* tolua_S)
{
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frameId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->frameId = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_get_MyFrame_name
static int tolua_get_MyFrame_name(lua_State* tolua_S)
{
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_set_MyFrame_name
static int tolua_set_MyFrame_name(lua_State* tolua_S)
{
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->name = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frame of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_get_MyFrame_frame_ptr
static int tolua_get_MyFrame_frame_ptr(lua_State* tolua_S)
{
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frame'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->frame,"CCSpriteFrame");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: frame of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_set_MyFrame_frame_ptr
static int tolua_set_MyFrame_frame_ptr(lua_State* tolua_S)
{
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frame'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSpriteFrame",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->frame = ((CCSpriteFrame*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: next of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_get_MyFrame_next_ptr
static int tolua_get_MyFrame_next_ptr(lua_State* tolua_S)
{
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'next'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->next,"MyFrame");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: next of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_set_MyFrame_next_ptr
static int tolua_set_MyFrame_next_ptr(lua_State* tolua_S)
{
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'next'",NULL);
  if (!tolua_isusertype(tolua_S,2,"MyFrame",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->next = ((MyFrame*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyFrame_new00
static int tolua_mycartoon_MyFrame_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MyFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MyFrame* tolua_ret = (MyFrame*)  Mtolua_new((MyFrame)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MyFrame");
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

/* method: new_local of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyFrame_new00_local
static int tolua_mycartoon_MyFrame_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MyFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MyFrame* tolua_ret = (MyFrame*)  Mtolua_new((MyFrame)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MyFrame");
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

/* method: addFrame of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyFrame_addFrame00
static int tolua_mycartoon_MyFrame_addFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyFrame",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
  const char* pngName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFrame'",NULL);
#endif
  {
   self->addFrame(pngName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addFrame of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyFrame_addFrame01
static int tolua_mycartoon_MyFrame_addFrame01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
  CCTexture2D* texture = ((CCTexture2D*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFrame'",NULL);
#endif
  {
   self->addFrame(texture);
  }
 }
 return 0;
tolua_lerror:
 return tolua_mycartoon_MyFrame_addFrame00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: pushFrame of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyFrame_pushFrame00
static int tolua_mycartoon_MyFrame_pushFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MyFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
  MyFrame* frame = ((MyFrame*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushFrame'",NULL);
#endif
  {
   MyFrame* tolua_ret = (MyFrame*)  self->pushFrame(frame);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MyFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyFrame_create00
static int tolua_mycartoon_MyFrame_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MyFrame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTexture2D* texture = ((CCTexture2D*)  tolua_tousertype(tolua_S,2,0));
  {
   MyFrame* tolua_ret = (MyFrame*)  MyFrame::create(texture);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MyFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyFrame_create01
static int tolua_mycartoon_MyFrame_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MyFrame",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* frameName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   MyFrame* tolua_ret = (MyFrame*)  MyFrame::create(frameName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MyFrame");
  }
 }
 return 1;
tolua_lerror:
 return tolua_mycartoon_MyFrame_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCount of class  MyFrame */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyFrame_getCount00
static int tolua_mycartoon_MyFrame_getCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyFrame* self = (MyFrame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCount'",NULL);
#endif
  {
   int tolua_ret = (int)  self->getCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyCartoon_create00
static int tolua_mycartoon_MyCartoon_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MyCartoon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MyCartoon* tolua_ret = (MyCartoon*)  MyCartoon::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MyCartoon");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rootFrame of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_get_MyCartoon_rootFrame_ptr
static int tolua_get_MyCartoon_rootFrame_ptr(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rootFrame'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->rootFrame,"MyFrame");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rootFrame of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_set_MyCartoon_rootFrame_ptr
static int tolua_set_MyCartoon_rootFrame_ptr(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rootFrame'",NULL);
  if (!tolua_isusertype(tolua_S,2,"MyFrame",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rootFrame = ((MyFrame*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sprite of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_get_MyCartoon_sprite_ptr
static int tolua_get_MyCartoon_sprite_ptr(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->sprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sprite of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_set_MyCartoon_sprite_ptr
static int tolua_set_MyCartoon_sprite_ptr(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: next of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_get_MyCartoon_next_ptr
static int tolua_get_MyCartoon_next_ptr(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'next'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->next,"MyCartoon");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: next of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_set_MyCartoon_next_ptr
static int tolua_set_MyCartoon_next_ptr(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'next'",NULL);
  if (!tolua_isusertype(tolua_S,2,"MyCartoon",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->next = ((MyCartoon*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: pushFrame of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyCartoon_pushFrame00
static int tolua_mycartoon_MyCartoon_pushFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyCartoon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MyFrame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
  MyFrame* frame = ((MyFrame*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushFrame'",NULL);
#endif
  {
   MyFrame* tolua_ret = (MyFrame*)  self->pushFrame(frame);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MyFrame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyCartoon_new00
static int tolua_mycartoon_MyCartoon_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MyCartoon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MyCartoon* tolua_ret = (MyCartoon*)  Mtolua_new((MyCartoon)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MyCartoon");
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

/* method: new_local of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyCartoon_new00_local
static int tolua_mycartoon_MyCartoon_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MyCartoon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MyCartoon* tolua_ret = (MyCartoon*)  Mtolua_new((MyCartoon)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MyCartoon");
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

/* method: getCount of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyCartoon_getCount00
static int tolua_mycartoon_MyCartoon_getCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyCartoon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCount'",NULL);
#endif
  {
   int tolua_ret = (int)  self->getCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: blockId of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_get_MyCartoon_blockId
static int tolua_get_MyCartoon_blockId(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blockId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->blockId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: blockId of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_set_MyCartoon_blockId
static int tolua_set_MyCartoon_blockId(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blockId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->blockId = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: pushCartoon of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyCartoon_pushCartoon00
static int tolua_mycartoon_MyCartoon_pushCartoon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyCartoon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"MyCartoon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
  MyCartoon* cartoon = ((MyCartoon*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pushCartoon'",NULL);
#endif
  {
   self->pushCartoon(cartoon);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pushCartoon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: showBlockId of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_get_MyCartoon_showBlockId
static int tolua_get_MyCartoon_showBlockId(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'showBlockId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->showBlockId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: showBlockId of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_set_MyCartoon_showBlockId
static int tolua_set_MyCartoon_showBlockId(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'showBlockId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->showBlockId = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nowFrameShowTime of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_get_MyCartoon_nowFrameShowTime
static int tolua_get_MyCartoon_nowFrameShowTime(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowFrameShowTime'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->nowFrameShowTime,"cc_timeval");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nowFrameShowTime of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_set_MyCartoon_nowFrameShowTime
static int tolua_set_MyCartoon_nowFrameShowTime(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowFrameShowTime'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"cc_timeval",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nowFrameShowTime = *((cc_timeval*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: nextFrame of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyCartoon_nextFrame00
static int tolua_mycartoon_MyCartoon_nextFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyCartoon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nextFrame'",NULL);
#endif
  {
   self->nextFrame();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'nextFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nowFrame of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_get_MyCartoon_nowFrame_ptr
static int tolua_get_MyCartoon_nowFrame_ptr(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowFrame'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->nowFrame,"MyFrame");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nowFrame of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_set_MyCartoon_nowFrame_ptr
static int tolua_set_MyCartoon_nowFrame_ptr(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowFrame'",NULL);
  if (!tolua_isusertype(tolua_S,2,"MyFrame",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nowFrame = ((MyFrame*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: startFrameId of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_get_MyCartoon_startFrameId
static int tolua_get_MyCartoon_startFrameId(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startFrameId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->startFrameId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: startFrameId of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_set_MyCartoon_startFrameId
static int tolua_set_MyCartoon_startFrameId(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'startFrameId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->startFrameId = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cartoonPlayCount of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_get_MyCartoon_cartoonPlayCount
static int tolua_get_MyCartoon_cartoonPlayCount(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cartoonPlayCount'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->cartoonPlayCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cartoonPlayCount of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_set_MyCartoon_cartoonPlayCount
static int tolua_set_MyCartoon_cartoonPlayCount(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cartoonPlayCount'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cartoonPlayCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cartoonPlayTimeOut of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_get_MyCartoon_cartoonPlayTimeOut
static int tolua_get_MyCartoon_cartoonPlayTimeOut(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cartoonPlayTimeOut'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->cartoonPlayTimeOut);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cartoonPlayTimeOut of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_set_MyCartoon_cartoonPlayTimeOut
static int tolua_set_MyCartoon_cartoonPlayTimeOut(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cartoonPlayTimeOut'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cartoonPlayTimeOut = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: endFrameId of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_get_MyCartoon_endFrameId
static int tolua_get_MyCartoon_endFrameId(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endFrameId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->endFrameId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: endFrameId of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_set_MyCartoon_endFrameId
static int tolua_set_MyCartoon_endFrameId(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'endFrameId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->endFrameId = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nowFrameId of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_get_MyCartoon_nowFrameId
static int tolua_get_MyCartoon_nowFrameId(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowFrameId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->nowFrameId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nowFrameId of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_set_MyCartoon_nowFrameId
static int tolua_set_MyCartoon_nowFrameId(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowFrameId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nowFrameId = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eachFrameTime of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_get_MyCartoon_eachFrameTime
static int tolua_get_MyCartoon_eachFrameTime(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eachFrameTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->eachFrameTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: eachFrameTime of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_set_MyCartoon_eachFrameTime
static int tolua_set_MyCartoon_eachFrameTime(lua_State* tolua_S)
{
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eachFrameTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->eachFrameTime = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFrame of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyCartoon_setFrame00
static int tolua_mycartoon_MyCartoon_setFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyCartoon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
  int frameStartId = ((int)  tolua_tonumber(tolua_S,2,0));
  int frameEndId = ((int)  tolua_tonumber(tolua_S,3,0));
  int timeout = ((int)  tolua_tonumber(tolua_S,4,0));
  int count = ((int)  tolua_tonumber(tolua_S,5,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFrame'",NULL);
#endif
  {
   self->setFrame(frameStartId,frameEndId,timeout,count);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showFrame of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyCartoon_showFrame00
static int tolua_mycartoon_MyCartoon_showFrame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyCartoon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
  int frameStartId = ((int)  tolua_tonumber(tolua_S,2,0));
  int frameEndId = ((int)  tolua_tonumber(tolua_S,3,0));
  int timeout = ((int)  tolua_tonumber(tolua_S,4,0));
  int count = ((int)  tolua_tonumber(tolua_S,5,-1));
  int blockId = ((int)  tolua_tonumber(tolua_S,6,-1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'showFrame'",NULL);
#endif
  {
   self->showFrame(frameStartId,frameEndId,timeout,count,blockId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showFrame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyCartoon_visit00
static int tolua_mycartoon_MyCartoon_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyCartoon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'",NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addFrameEvent of class  MyCartoon */
#ifndef TOLUA_DISABLE_tolua_mycartoon_MyCartoon_addFrameEvent00
static int tolua_mycartoon_MyCartoon_addFrameEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyCartoon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyCartoon* self = (MyCartoon*)  tolua_tousertype(tolua_S,1,0);
  int frameId = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFrameEvent'",NULL);
#endif
  {
   self->addFrameEvent(frameId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addFrameEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: version of class  cartoon_file_head */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_file_head_version
static int tolua_get_cartoon_file_head_version(lua_State* tolua_S)
{
  cartoon_file_head* self = (cartoon_file_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'version'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->version);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: version of class  cartoon_file_head */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_file_head_version
static int tolua_set_cartoon_file_head_version(lua_State* tolua_S)
{
  cartoon_file_head* self = (cartoon_file_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'version'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy(self->version,tolua_tostring(tolua_S,2,0),4-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sprite_count of class  cartoon_file_head */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_file_head_sprite_count
static int tolua_get_cartoon_file_head_sprite_count(lua_State* tolua_S)
{
  cartoon_file_head* self = (cartoon_file_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite_count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->sprite_count);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sprite_count of class  cartoon_file_head */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_file_head_sprite_count
static int tolua_set_cartoon_file_head_sprite_count(lua_State* tolua_S)
{
  cartoon_file_head* self = (cartoon_file_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite_count'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sprite_count = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: all_frame_count of class  cartoon_file_head */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_file_head_all_frame_count
static int tolua_get_cartoon_file_head_all_frame_count(lua_State* tolua_S)
{
  cartoon_file_head* self = (cartoon_file_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'all_frame_count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->all_frame_count);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: all_frame_count of class  cartoon_file_head */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_file_head_all_frame_count
static int tolua_set_cartoon_file_head_all_frame_count(lua_State* tolua_S)
{
  cartoon_file_head* self = (cartoon_file_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'all_frame_count'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->all_frame_count = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: textures_count of class  cartoon_file_head */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_file_head_textures_count
static int tolua_get_cartoon_file_head_textures_count(lua_State* tolua_S)
{
  cartoon_file_head* self = (cartoon_file_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textures_count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->textures_count);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: textures_count of class  cartoon_file_head */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_file_head_textures_count
static int tolua_set_cartoon_file_head_textures_count(lua_State* tolua_S)
{
  cartoon_file_head* self = (cartoon_file_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'textures_count'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->textures_count = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: idle_value of class  cartoon_file_head */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_file_head_idle_value
static int tolua_get_cartoon_file_head_idle_value(lua_State* tolua_S)
{
  cartoon_file_head* self = (cartoon_file_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'idle_value'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->idle_value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: idle_value of class  cartoon_file_head */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_file_head_idle_value
static int tolua_set_cartoon_file_head_idle_value(lua_State* tolua_S)
{
  cartoon_file_head* self = (cartoon_file_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'idle_value'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy(self->idle_value,tolua_tostring(tolua_S,2,0),36-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  cartoon_file_head */
#ifndef TOLUA_DISABLE_tolua_mycartoon_cartoon_file_head_clear00
static int tolua_mycartoon_cartoon_file_head_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"cartoon_file_head",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  cartoon_file_head* self = (cartoon_file_head*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  cartoon_file_head */
#ifndef TOLUA_DISABLE_tolua_mycartoon_cartoon_file_head_new00
static int tolua_mycartoon_cartoon_file_head_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"cartoon_file_head",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   cartoon_file_head* tolua_ret = (cartoon_file_head*)  Mtolua_new((cartoon_file_head)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cartoon_file_head");
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

/* method: new_local of class  cartoon_file_head */
#ifndef TOLUA_DISABLE_tolua_mycartoon_cartoon_file_head_new00_local
static int tolua_mycartoon_cartoon_file_head_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"cartoon_file_head",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   cartoon_file_head* tolua_ret = (cartoon_file_head*)  Mtolua_new((cartoon_file_head)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cartoon_file_head");
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

/* get function: size of class  texture_data_len */
#ifndef TOLUA_DISABLE_tolua_get_texture_data_len_size
static int tolua_get_texture_data_len_size(lua_State* tolua_S)
{
  texture_data_len* self = (texture_data_len*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->size);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: size of class  texture_data_len */
#ifndef TOLUA_DISABLE_tolua_set_texture_data_len_size
static int tolua_set_texture_data_len_size(lua_State* tolua_S)
{
  texture_data_len* self = (texture_data_len*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'size'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->size = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  texture_data_len */
#ifndef TOLUA_DISABLE_tolua_mycartoon_texture_data_len_new00
static int tolua_mycartoon_texture_data_len_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"texture_data_len",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   texture_data_len* tolua_ret = (texture_data_len*)  Mtolua_new((texture_data_len)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"texture_data_len");
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

/* method: new_local of class  texture_data_len */
#ifndef TOLUA_DISABLE_tolua_mycartoon_texture_data_len_new00_local
static int tolua_mycartoon_texture_data_len_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"texture_data_len",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   texture_data_len* tolua_ret = (texture_data_len*)  Mtolua_new((texture_data_len)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"texture_data_len");
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

/* get function: content of class  texture_data */
#ifndef TOLUA_DISABLE_tolua_get_texture_data_content
static int tolua_get_texture_data_content(lua_State* tolua_S)
{
  texture_data* self = (texture_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'content'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->content);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: content of class  texture_data */
#ifndef TOLUA_DISABLE_tolua_set_texture_data_content
static int tolua_set_texture_data_content(lua_State* tolua_S)
{
  texture_data* self = (texture_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'content'",NULL);
  if (!tolua_isstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->content = ((char*)  tolua_tostring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  texture_data */
#ifndef TOLUA_DISABLE_tolua_mycartoon_texture_data_clear00
static int tolua_mycartoon_texture_data_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"texture_data",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  texture_data* self = (texture_data*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  texture_data */
#ifndef TOLUA_DISABLE_tolua_mycartoon_texture_data_new00
static int tolua_mycartoon_texture_data_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"texture_data",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   texture_data* tolua_ret = (texture_data*)  Mtolua_new((texture_data)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"texture_data");
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

/* method: new_local of class  texture_data */
#ifndef TOLUA_DISABLE_tolua_mycartoon_texture_data_new00_local
static int tolua_mycartoon_texture_data_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"texture_data",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   texture_data* tolua_ret = (texture_data*)  Mtolua_new((texture_data)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"texture_data");
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

/* get function: frame_count of class  cartoon_sprite_head */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_sprite_head_frame_count
static int tolua_get_cartoon_sprite_head_frame_count(lua_State* tolua_S)
{
  cartoon_sprite_head* self = (cartoon_sprite_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frame_count'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->frame_count);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: frame_count of class  cartoon_sprite_head */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_sprite_head_frame_count
static int tolua_set_cartoon_sprite_head_frame_count(lua_State* tolua_S)
{
  cartoon_sprite_head* self = (cartoon_sprite_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frame_count'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->frame_count = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  cartoon_sprite_head */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_sprite_head_x
static int tolua_get_cartoon_sprite_head_x(lua_State* tolua_S)
{
  cartoon_sprite_head* self = (cartoon_sprite_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  cartoon_sprite_head */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_sprite_head_x
static int tolua_set_cartoon_sprite_head_x(lua_State* tolua_S)
{
  cartoon_sprite_head* self = (cartoon_sprite_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  cartoon_sprite_head */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_sprite_head_y
static int tolua_get_cartoon_sprite_head_y(lua_State* tolua_S)
{
  cartoon_sprite_head* self = (cartoon_sprite_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  cartoon_sprite_head */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_sprite_head_y
static int tolua_set_cartoon_sprite_head_y(lua_State* tolua_S)
{
  cartoon_sprite_head* self = (cartoon_sprite_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: w of class  cartoon_sprite_head */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_sprite_head_w
static int tolua_get_cartoon_sprite_head_w(lua_State* tolua_S)
{
  cartoon_sprite_head* self = (cartoon_sprite_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->w);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: w of class  cartoon_sprite_head */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_sprite_head_w
static int tolua_set_cartoon_sprite_head_w(lua_State* tolua_S)
{
  cartoon_sprite_head* self = (cartoon_sprite_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->w = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: h of class  cartoon_sprite_head */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_sprite_head_h
static int tolua_get_cartoon_sprite_head_h(lua_State* tolua_S)
{
  cartoon_sprite_head* self = (cartoon_sprite_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'h'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->h);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: h of class  cartoon_sprite_head */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_sprite_head_h
static int tolua_set_cartoon_sprite_head_h(lua_State* tolua_S)
{
  cartoon_sprite_head* self = (cartoon_sprite_head*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'h'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->h = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  cartoon_sprite_head */
#ifndef TOLUA_DISABLE_tolua_mycartoon_cartoon_sprite_head_clear00
static int tolua_mycartoon_cartoon_sprite_head_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"cartoon_sprite_head",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  cartoon_sprite_head* self = (cartoon_sprite_head*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  cartoon_sprite_head */
#ifndef TOLUA_DISABLE_tolua_mycartoon_cartoon_sprite_head_new00
static int tolua_mycartoon_cartoon_sprite_head_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"cartoon_sprite_head",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   cartoon_sprite_head* tolua_ret = (cartoon_sprite_head*)  Mtolua_new((cartoon_sprite_head)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cartoon_sprite_head");
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

/* method: new_local of class  cartoon_sprite_head */
#ifndef TOLUA_DISABLE_tolua_mycartoon_cartoon_sprite_head_new00_local
static int tolua_mycartoon_cartoon_sprite_head_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"cartoon_sprite_head",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   cartoon_sprite_head* tolua_ret = (cartoon_sprite_head*)  Mtolua_new((cartoon_sprite_head)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cartoon_sprite_head");
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

/* get function: texture_id of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_frame_data_texture_id
static int tolua_get_cartoon_frame_data_texture_id(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texture_id'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->texture_id);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: texture_id of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_frame_data_texture_id
static int tolua_set_cartoon_frame_data_texture_id(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'texture_id'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->texture_id = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tx of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_frame_data_tx
static int tolua_get_cartoon_frame_data_tx(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tx'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tx);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tx of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_frame_data_tx
static int tolua_set_cartoon_frame_data_tx(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tx'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tx = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ty of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_frame_data_ty
static int tolua_get_cartoon_frame_data_ty(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ty'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ty);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ty of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_frame_data_ty
static int tolua_set_cartoon_frame_data_ty(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ty'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ty = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tw of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_frame_data_tw
static int tolua_get_cartoon_frame_data_tw(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tw'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tw);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tw of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_frame_data_tw
static int tolua_set_cartoon_frame_data_tw(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tw'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tw = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: th of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_frame_data_th
static int tolua_get_cartoon_frame_data_th(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'th'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->th);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: th of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_frame_data_th
static int tolua_set_cartoon_frame_data_th(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'th'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->th = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ox of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_frame_data_ox
static int tolua_get_cartoon_frame_data_ox(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ox'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ox);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ox of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_frame_data_ox
static int tolua_set_cartoon_frame_data_ox(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ox'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ox = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: oy of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_frame_data_oy
static int tolua_get_cartoon_frame_data_oy(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'oy'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->oy);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: oy of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_frame_data_oy
static int tolua_set_cartoon_frame_data_oy(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'oy'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->oy = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: w of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_frame_data_w
static int tolua_get_cartoon_frame_data_w(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->w);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: w of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_frame_data_w
static int tolua_set_cartoon_frame_data_w(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->w = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: h of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_get_cartoon_frame_data_h
static int tolua_get_cartoon_frame_data_h(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'h'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->h);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: h of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_set_cartoon_frame_data_h
static int tolua_set_cartoon_frame_data_h(lua_State* tolua_S)
{
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'h'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->h = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: clear of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_mycartoon_cartoon_frame_data_clear00
static int tolua_mycartoon_cartoon_frame_data_clear00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"cartoon_frame_data",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  cartoon_frame_data* self = (cartoon_frame_data*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_mycartoon_cartoon_frame_data_new00
static int tolua_mycartoon_cartoon_frame_data_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"cartoon_frame_data",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   cartoon_frame_data* tolua_ret = (cartoon_frame_data*)  Mtolua_new((cartoon_frame_data)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cartoon_frame_data");
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

/* method: new_local of class  cartoon_frame_data */
#ifndef TOLUA_DISABLE_tolua_mycartoon_cartoon_frame_data_new00_local
static int tolua_mycartoon_cartoon_frame_data_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"cartoon_frame_data",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   cartoon_frame_data* tolua_ret = (cartoon_frame_data*)  Mtolua_new((cartoon_frame_data)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"cartoon_frame_data");
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

/* get function: index of class  temp_texture */
#ifndef TOLUA_DISABLE_tolua_get_temp_texture_index
static int tolua_get_temp_texture_index(lua_State* tolua_S)
{
  temp_texture* self = (temp_texture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'index'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->index);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: index of class  temp_texture */
#ifndef TOLUA_DISABLE_tolua_set_temp_texture_index
static int tolua_set_temp_texture_index(lua_State* tolua_S)
{
  temp_texture* self = (temp_texture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'index'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->index = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pngName of class  temp_texture */
#ifndef TOLUA_DISABLE_tolua_get_temp_texture_pngName
static int tolua_get_temp_texture_pngName(lua_State* tolua_S)
{
  temp_texture* self = (temp_texture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pngName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->pngName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pngName of class  temp_texture */
#ifndef TOLUA_DISABLE_tolua_set_temp_texture_pngName
static int tolua_set_temp_texture_pngName(lua_State* tolua_S)
{
  temp_texture* self = (temp_texture*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pngName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pngName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  temp_texture */
#ifndef TOLUA_DISABLE_tolua_mycartoon_temp_texture_new00
static int tolua_mycartoon_temp_texture_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"temp_texture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   temp_texture* tolua_ret = (temp_texture*)  Mtolua_new((temp_texture)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"temp_texture");
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

/* method: new_local of class  temp_texture */
#ifndef TOLUA_DISABLE_tolua_mycartoon_temp_texture_new00_local
static int tolua_mycartoon_temp_texture_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"temp_texture",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   temp_texture* tolua_ret = (temp_texture*)  Mtolua_new((temp_texture)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"temp_texture");
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

/* method: read of class  my_cartoon_file */
#ifndef TOLUA_DISABLE_tolua_mycartoon_my_cartoon_file_read00
static int tolua_mycartoon_my_cartoon_file_read00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"my_cartoon_file",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"MyCartoon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  my_cartoon_file* self = (my_cartoon_file*)  tolua_tousertype(tolua_S,1,0);
  const char* aniFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  MyCartoon* rootCartoon = ((MyCartoon*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'read'",NULL);
#endif
  {
   self->read(aniFile,rootCartoon);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'read'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write of class  my_cartoon_file */
#ifndef TOLUA_DISABLE_tolua_mycartoon_my_cartoon_file_write00
static int tolua_mycartoon_my_cartoon_file_write00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"my_cartoon_file",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"MyCartoon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  my_cartoon_file* self = (my_cartoon_file*)  tolua_tousertype(tolua_S,1,0);
  const char* aniFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  MyCartoon* rootCartoon = ((MyCartoon*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'write'",NULL);
#endif
  {
   self->write(aniFile,rootCartoon);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getwriteablepath of class  my_cartoon_file */
#ifndef TOLUA_DISABLE_tolua_mycartoon_my_cartoon_file_getwriteablepath00
static int tolua_mycartoon_my_cartoon_file_getwriteablepath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"my_cartoon_file",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   std::string tolua_ret = (std::string)  my_cartoon_file::getwriteablepath(filename);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getwriteablepath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_mycartoon_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"MyFrame","MyFrame","",tolua_collect_MyFrame);
  #else
  tolua_cclass(tolua_S,"MyFrame","MyFrame","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"MyFrame");
   tolua_variable(tolua_S,"textureId",tolua_get_MyFrame_textureId,tolua_set_MyFrame_textureId);
   tolua_variable(tolua_S,"frameId",tolua_get_MyFrame_frameId,tolua_set_MyFrame_frameId);
   tolua_variable(tolua_S,"name",tolua_get_MyFrame_name,tolua_set_MyFrame_name);
   tolua_variable(tolua_S,"frame",tolua_get_MyFrame_frame_ptr,tolua_set_MyFrame_frame_ptr);
   tolua_variable(tolua_S,"next",tolua_get_MyFrame_next_ptr,tolua_set_MyFrame_next_ptr);
   tolua_function(tolua_S,"new",tolua_mycartoon_MyFrame_new00);
   tolua_function(tolua_S,"new_local",tolua_mycartoon_MyFrame_new00_local);
   tolua_function(tolua_S,".call",tolua_mycartoon_MyFrame_new00_local);
   tolua_function(tolua_S,"addFrame",tolua_mycartoon_MyFrame_addFrame00);
   tolua_function(tolua_S,"addFrame",tolua_mycartoon_MyFrame_addFrame01);
   tolua_function(tolua_S,"pushFrame",tolua_mycartoon_MyFrame_pushFrame00);
   tolua_function(tolua_S,"create",tolua_mycartoon_MyFrame_create00);
   tolua_function(tolua_S,"create",tolua_mycartoon_MyFrame_create01);
   tolua_function(tolua_S,"getCount",tolua_mycartoon_MyFrame_getCount00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"MyCartoon","MyCartoon","CCNode",tolua_collect_MyCartoon);
  #else
  tolua_cclass(tolua_S,"MyCartoon","MyCartoon","CCNode",NULL);
  #endif
  tolua_beginmodule(tolua_S,"MyCartoon");
   tolua_function(tolua_S,"create",tolua_mycartoon_MyCartoon_create00);
   tolua_variable(tolua_S,"rootFrame",tolua_get_MyCartoon_rootFrame_ptr,tolua_set_MyCartoon_rootFrame_ptr);
   tolua_variable(tolua_S,"sprite",tolua_get_MyCartoon_sprite_ptr,tolua_set_MyCartoon_sprite_ptr);
   tolua_variable(tolua_S,"next",tolua_get_MyCartoon_next_ptr,tolua_set_MyCartoon_next_ptr);
   tolua_function(tolua_S,"pushFrame",tolua_mycartoon_MyCartoon_pushFrame00);
   tolua_function(tolua_S,"new",tolua_mycartoon_MyCartoon_new00);
   tolua_function(tolua_S,"new_local",tolua_mycartoon_MyCartoon_new00_local);
   tolua_function(tolua_S,".call",tolua_mycartoon_MyCartoon_new00_local);
   tolua_function(tolua_S,"getCount",tolua_mycartoon_MyCartoon_getCount00);
   tolua_variable(tolua_S,"blockId",tolua_get_MyCartoon_blockId,tolua_set_MyCartoon_blockId);
   tolua_function(tolua_S,"pushCartoon",tolua_mycartoon_MyCartoon_pushCartoon00);
   tolua_variable(tolua_S,"showBlockId",tolua_get_MyCartoon_showBlockId,tolua_set_MyCartoon_showBlockId);
   tolua_variable(tolua_S,"nowFrameShowTime",tolua_get_MyCartoon_nowFrameShowTime,tolua_set_MyCartoon_nowFrameShowTime);
   tolua_function(tolua_S,"nextFrame",tolua_mycartoon_MyCartoon_nextFrame00);
   tolua_variable(tolua_S,"nowFrame",tolua_get_MyCartoon_nowFrame_ptr,tolua_set_MyCartoon_nowFrame_ptr);
   tolua_variable(tolua_S,"startFrameId",tolua_get_MyCartoon_startFrameId,tolua_set_MyCartoon_startFrameId);
   tolua_variable(tolua_S,"cartoonPlayCount",tolua_get_MyCartoon_cartoonPlayCount,tolua_set_MyCartoon_cartoonPlayCount);
   tolua_variable(tolua_S,"cartoonPlayTimeOut",tolua_get_MyCartoon_cartoonPlayTimeOut,tolua_set_MyCartoon_cartoonPlayTimeOut);
   tolua_variable(tolua_S,"endFrameId",tolua_get_MyCartoon_endFrameId,tolua_set_MyCartoon_endFrameId);
   tolua_variable(tolua_S,"nowFrameId",tolua_get_MyCartoon_nowFrameId,tolua_set_MyCartoon_nowFrameId);
   tolua_variable(tolua_S,"eachFrameTime",tolua_get_MyCartoon_eachFrameTime,tolua_set_MyCartoon_eachFrameTime);
   tolua_function(tolua_S,"setFrame",tolua_mycartoon_MyCartoon_setFrame00);
   tolua_function(tolua_S,"showFrame",tolua_mycartoon_MyCartoon_showFrame00);
   tolua_function(tolua_S,"visit",tolua_mycartoon_MyCartoon_visit00);
   tolua_function(tolua_S,"addFrameEvent",tolua_mycartoon_MyCartoon_addFrameEvent00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"cartoon_file_head","cartoon_file_head","",tolua_collect_cartoon_file_head);
  #else
  tolua_cclass(tolua_S,"cartoon_file_head","cartoon_file_head","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"cartoon_file_head");
   tolua_variable(tolua_S,"version",tolua_get_cartoon_file_head_version,tolua_set_cartoon_file_head_version);
   tolua_variable(tolua_S,"sprite_count",tolua_get_cartoon_file_head_sprite_count,tolua_set_cartoon_file_head_sprite_count);
   tolua_variable(tolua_S,"all_frame_count",tolua_get_cartoon_file_head_all_frame_count,tolua_set_cartoon_file_head_all_frame_count);
   tolua_variable(tolua_S,"textures_count",tolua_get_cartoon_file_head_textures_count,tolua_set_cartoon_file_head_textures_count);
   tolua_variable(tolua_S,"idle_value",tolua_get_cartoon_file_head_idle_value,tolua_set_cartoon_file_head_idle_value);
   tolua_function(tolua_S,"clear",tolua_mycartoon_cartoon_file_head_clear00);
   tolua_function(tolua_S,"new",tolua_mycartoon_cartoon_file_head_new00);
   tolua_function(tolua_S,"new_local",tolua_mycartoon_cartoon_file_head_new00_local);
   tolua_function(tolua_S,".call",tolua_mycartoon_cartoon_file_head_new00_local);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"texture_data_len","texture_data_len","",tolua_collect_texture_data_len);
  #else
  tolua_cclass(tolua_S,"texture_data_len","texture_data_len","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"texture_data_len");
   tolua_variable(tolua_S,"size",tolua_get_texture_data_len_size,tolua_set_texture_data_len_size);
   tolua_function(tolua_S,"new",tolua_mycartoon_texture_data_len_new00);
   tolua_function(tolua_S,"new_local",tolua_mycartoon_texture_data_len_new00_local);
   tolua_function(tolua_S,".call",tolua_mycartoon_texture_data_len_new00_local);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"texture_data","texture_data","",tolua_collect_texture_data);
  #else
  tolua_cclass(tolua_S,"texture_data","texture_data","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"texture_data");
   tolua_variable(tolua_S,"content",tolua_get_texture_data_content,tolua_set_texture_data_content);
   tolua_function(tolua_S,"clear",tolua_mycartoon_texture_data_clear00);
   tolua_function(tolua_S,"new",tolua_mycartoon_texture_data_new00);
   tolua_function(tolua_S,"new_local",tolua_mycartoon_texture_data_new00_local);
   tolua_function(tolua_S,".call",tolua_mycartoon_texture_data_new00_local);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"cartoon_sprite_head","cartoon_sprite_head","",tolua_collect_cartoon_sprite_head);
  #else
  tolua_cclass(tolua_S,"cartoon_sprite_head","cartoon_sprite_head","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"cartoon_sprite_head");
   tolua_variable(tolua_S,"frame_count",tolua_get_cartoon_sprite_head_frame_count,tolua_set_cartoon_sprite_head_frame_count);
   tolua_variable(tolua_S,"x",tolua_get_cartoon_sprite_head_x,tolua_set_cartoon_sprite_head_x);
   tolua_variable(tolua_S,"y",tolua_get_cartoon_sprite_head_y,tolua_set_cartoon_sprite_head_y);
   tolua_variable(tolua_S,"w",tolua_get_cartoon_sprite_head_w,tolua_set_cartoon_sprite_head_w);
   tolua_variable(tolua_S,"h",tolua_get_cartoon_sprite_head_h,tolua_set_cartoon_sprite_head_h);
   tolua_function(tolua_S,"clear",tolua_mycartoon_cartoon_sprite_head_clear00);
   tolua_function(tolua_S,"new",tolua_mycartoon_cartoon_sprite_head_new00);
   tolua_function(tolua_S,"new_local",tolua_mycartoon_cartoon_sprite_head_new00_local);
   tolua_function(tolua_S,".call",tolua_mycartoon_cartoon_sprite_head_new00_local);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"cartoon_frame_data","cartoon_frame_data","",tolua_collect_cartoon_frame_data);
  #else
  tolua_cclass(tolua_S,"cartoon_frame_data","cartoon_frame_data","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"cartoon_frame_data");
   tolua_variable(tolua_S,"texture_id",tolua_get_cartoon_frame_data_texture_id,tolua_set_cartoon_frame_data_texture_id);
   tolua_variable(tolua_S,"tx",tolua_get_cartoon_frame_data_tx,tolua_set_cartoon_frame_data_tx);
   tolua_variable(tolua_S,"ty",tolua_get_cartoon_frame_data_ty,tolua_set_cartoon_frame_data_ty);
   tolua_variable(tolua_S,"tw",tolua_get_cartoon_frame_data_tw,tolua_set_cartoon_frame_data_tw);
   tolua_variable(tolua_S,"th",tolua_get_cartoon_frame_data_th,tolua_set_cartoon_frame_data_th);
   tolua_variable(tolua_S,"ox",tolua_get_cartoon_frame_data_ox,tolua_set_cartoon_frame_data_ox);
   tolua_variable(tolua_S,"oy",tolua_get_cartoon_frame_data_oy,tolua_set_cartoon_frame_data_oy);
   tolua_variable(tolua_S,"w",tolua_get_cartoon_frame_data_w,tolua_set_cartoon_frame_data_w);
   tolua_variable(tolua_S,"h",tolua_get_cartoon_frame_data_h,tolua_set_cartoon_frame_data_h);
   tolua_function(tolua_S,"clear",tolua_mycartoon_cartoon_frame_data_clear00);
   tolua_function(tolua_S,"new",tolua_mycartoon_cartoon_frame_data_new00);
   tolua_function(tolua_S,"new_local",tolua_mycartoon_cartoon_frame_data_new00_local);
   tolua_function(tolua_S,".call",tolua_mycartoon_cartoon_frame_data_new00_local);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"temp_texture","temp_texture","",tolua_collect_temp_texture);
  #else
  tolua_cclass(tolua_S,"temp_texture","temp_texture","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"temp_texture");
   tolua_variable(tolua_S,"index",tolua_get_temp_texture_index,tolua_set_temp_texture_index);
   tolua_variable(tolua_S,"pngName",tolua_get_temp_texture_pngName,tolua_set_temp_texture_pngName);
   tolua_function(tolua_S,"new",tolua_mycartoon_temp_texture_new00);
   tolua_function(tolua_S,"new_local",tolua_mycartoon_temp_texture_new00_local);
   tolua_function(tolua_S,".call",tolua_mycartoon_temp_texture_new00_local);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"my_cartoon_file","my_cartoon_file","",NULL);
  tolua_beginmodule(tolua_S,"my_cartoon_file");
   tolua_function(tolua_S,"read",tolua_mycartoon_my_cartoon_file_read00);
   tolua_function(tolua_S,"write",tolua_mycartoon_my_cartoon_file_write00);
   tolua_function(tolua_S,"getwriteablepath",tolua_mycartoon_my_cartoon_file_getwriteablepath00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_mycartoon (lua_State* tolua_S) {
 return tolua_mycartoon_open(tolua_S);
};
#endif

