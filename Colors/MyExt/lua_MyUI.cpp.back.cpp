/*
** Lua binding: MyUI1
** Generated automatically by tolua++-1.0.92 on Sat Sep 28 10:29:39 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

#include "cocos2d.h"
#include "MyUI.h"
USING_NS_CC;
using namespace myui;
/* Exported function */
TOLUA_API int  tolua_MyUI1_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CCPoint (lua_State* tolua_S)
{
 CCPoint* self = (CCPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Tree (lua_State* tolua_S)
{
 Tree* self = (Tree*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_ScrollView (lua_State* tolua_S)
{
 ScrollView* self = (ScrollView*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Bubble (lua_State* tolua_S)
{
 Bubble* self = (Bubble*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Table (lua_State* tolua_S)
{
 Table* self = (Table*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Image (lua_State* tolua_S)
{
 Image* self = (Image*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CCSize (lua_State* tolua_S)
{
 CCSize* self = (CCSize*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_List (lua_State* tolua_S)
{
 List* self = (List*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Button (lua_State* tolua_S)
{
 Button* self = (Button*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_HPLabel (lua_State* tolua_S)
{
 HPLabel* self = (HPLabel*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Base (lua_State* tolua_S)
{
 Base* self = (Base*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Slider (lua_State* tolua_S)
{
 Slider* self = (Slider*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCPoint");
 tolua_usertype(tolua_S,"CCLayer");
 tolua_usertype(tolua_S,"Label");
 tolua_usertype(tolua_S,"Window");
 tolua_usertype(tolua_S,"Bubble");
 tolua_usertype(tolua_S,"cocos2d::CCEvent");
 tolua_usertype(tolua_S,"Image");
 tolua_usertype(tolua_S,"CCSize");
 tolua_usertype(tolua_S,"List");
 tolua_usertype(tolua_S,"Button");
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"Base");
 tolua_usertype(tolua_S,"ScrollView");
 tolua_usertype(tolua_S,"Panel");
 tolua_usertype(tolua_S,"Choice");
 tolua_usertype(tolua_S,"cocos2d::CCSet");
 tolua_usertype(tolua_S,"Tree");
 tolua_usertype(tolua_S,"CCImage");
 tolua_usertype(tolua_S,"std::list<Base*>");
 tolua_usertype(tolua_S,"Table");
 tolua_usertype(tolua_S,"HPLabel");
 tolua_usertype(tolua_S,"std::vector<std::string>");
 tolua_usertype(tolua_S,"CCSprite");
 tolua_usertype(tolua_S,"CCTouch");
 tolua_usertype(tolua_S,"CCRect");
 tolua_usertype(tolua_S,"CCAction");
 tolua_usertype(tolua_S,"Slider");
}

/* method: new of class  Base */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Base_new00
static int tolua_MyUI1_Base_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Base* tolua_ret = (Base*)  Mtolua_new((Base)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Base");
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

/* method: new_local of class  Base */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Base_new00_local
static int tolua_MyUI1_Base_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Base* tolua_ret = (Base*)  Mtolua_new((Base)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Base");
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

/* method: setMoveable of class  Base */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Base_setMoveable00
static int tolua_MyUI1_Base_setMoveable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Base",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
  bool moveableTag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMoveable'",NULL);
#endif
  {
   self->setMoveable(moveableTag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMoveable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hide of class  Base */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Base_hide00
static int tolua_MyUI1_Base_hide00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hide'",NULL);
#endif
  {
   self->hide();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hide'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Base */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Base_show00
static int tolua_MyUI1_Base_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nowTouchPoint of class  Base */
#ifndef TOLUA_DISABLE_tolua_get_Base_nowTouchPoint
static int tolua_get_Base_nowTouchPoint(lua_State* tolua_S)
{
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchPoint'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->nowTouchPoint,"CCPoint");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nowTouchPoint of class  Base */
#ifndef TOLUA_DISABLE_tolua_set_Base_nowTouchPoint
static int tolua_set_Base_nowTouchPoint(lua_State* tolua_S)
{
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchPoint'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nowTouchPoint = *((CCPoint*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isActive of class  Base */
#ifndef TOLUA_DISABLE_tolua_get_Base_isActive
static int tolua_get_Base_isActive(lua_State* tolua_S)
{
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isActive'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isActive);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isActive of class  Base */
#ifndef TOLUA_DISABLE_tolua_set_Base_isActive
static int tolua_set_Base_isActive(lua_State* tolua_S)
{
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isActive'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isActive = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: moveAble of class  Base */
#ifndef TOLUA_DISABLE_tolua_get_Base_moveAble
static int tolua_get_Base_moveAble(lua_State* tolua_S)
{
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'moveAble'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->moveAble);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: moveAble of class  Base */
#ifndef TOLUA_DISABLE_tolua_set_Base_moveAble
static int tolua_set_Base_moveAble(lua_State* tolua_S)
{
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'moveAble'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->moveAble = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: panel of class  Base */
#ifndef TOLUA_DISABLE_tolua_get_Base_panel_ptr
static int tolua_get_Base_panel_ptr(lua_State* tolua_S)
{
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'panel'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->panel,"Panel");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: panel of class  Base */
#ifndef TOLUA_DISABLE_tolua_set_Base_panel_ptr
static int tolua_set_Base_panel_ptr(lua_State* tolua_S)
{
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'panel'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Panel",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->panel = ((Panel*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: parent of class  Base */
#ifndef TOLUA_DISABLE_tolua_get_Base_parent_ptr
static int tolua_get_Base_parent_ptr(lua_State* tolua_S)
{
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->parent,"CCNode");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: parent of class  Base */
#ifndef TOLUA_DISABLE_tolua_set_Base_parent_ptr
static int tolua_set_Base_parent_ptr(lua_State* tolua_S)
{
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->parent = ((CCNode*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLocation of class  Base */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Base_setLocation00
static int tolua_MyUI1_Base_setLocation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Base",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
  AlignType alignType = ((AlignType) (int)  tolua_tonumber(tolua_S,2,0));
  const CCSize* splitSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  const CCPoint* gridLocation = ((const CCPoint*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLocation'",NULL);
#endif
  {
   self->setLocation(alignType,*splitSize,*gridLocation);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLocation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInView of class  Base */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Base_setInView00
static int tolua_MyUI1_Base_setInView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Base",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Base* self = (Base*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInView'",NULL);
#endif
  {
   self->setInView(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_create00
static int tolua_MyUI1_Image_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* pngName = ((const char*)  tolua_tostring(tolua_S,2,NULL));
  {
   Image* tolua_ret = (Image*)  Image::create(pngName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Image");
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

/* method: checkIn of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_checkIn00
static int tolua_MyUI1_Image_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_checkIn01
static int tolua_MyUI1_Image_checkIn01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(*point);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_MyUI1_Image_checkIn00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOutLine of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_setOutLine00
static int tolua_MyUI1_Image_setOutLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  const char* pngName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOutLine'",NULL);
#endif
  {
   self->setOutLine(pngName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOutLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_doTouch00
static int tolua_MyUI1_Image_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent event = ((TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sprite of class  Image */
#ifndef TOLUA_DISABLE_tolua_get_Image_sprite_ptr
static int tolua_get_Image_sprite_ptr(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->sprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sprite of class  Image */
#ifndef TOLUA_DISABLE_tolua_set_Image_sprite_ptr
static int tolua_set_Image_sprite_ptr(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
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

/* method: show of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_show00
static int tolua_MyUI1_Image_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_draw00
static int tolua_MyUI1_Image_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'",NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: replacePng of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_replacePng00
static int tolua_MyUI1_Image_replacePng00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'replacePng'",NULL);
#endif
  {
   self->replacePng(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'replacePng'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_checkIn02
static int tolua_MyUI1_Image_checkIn02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint point = *((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* sprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
  const char* fileName = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(point,sprite,fileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_MyUI1_Image_checkIn01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkInRect of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_checkInRect00
static int tolua_MyUI1_Image_checkInRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint point = *((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* sprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkInRect'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkInRect(point,sprite);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkInRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createImage of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_createImage00
static int tolua_MyUI1_Image_createImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCImage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  const char* fileName = ((const char*)  tolua_tostring(tolua_S,2,0));
  CCImage* image = ((CCImage*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createImage'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->createImage(fileName,image);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
    tolua_pushusertype(tolua_S,(void*)image,"CCImage");
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_delete00
static int tolua_MyUI1_Image_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_new00
static int tolua_MyUI1_Image_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Image* tolua_ret = (Image*)  Mtolua_new((Image)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Image");
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

/* method: new_local of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_new00_local
static int tolua_MyUI1_Image_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Image* tolua_ret = (Image*)  Mtolua_new((Image)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Image");
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

/* method: runAction of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_runAction00
static int tolua_MyUI1_Image_runAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  CCAction* action = ((CCAction*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'runAction'",NULL);
#endif
  {
   self->runAction(action);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'runAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewSize of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_getViewSize00
static int tolua_MyUI1_Image_getViewSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewSize'",NULL);
#endif
  {
   CCSize tolua_ret = (CCSize)  self->getViewSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: imageSize of class  Image */
#ifndef TOLUA_DISABLE_tolua_get_Image_imageSize
static int tolua_get_Image_imageSize(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->imageSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: imageSize of class  Image */
#ifndef TOLUA_DISABLE_tolua_set_Image_imageSize
static int tolua_set_Image_imageSize(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->imageSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: resizeable of class  Image */
#ifndef TOLUA_DISABLE_tolua_get_Image_resizeable
static int tolua_get_Image_resizeable(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resizeable'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->resizeable);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: resizeable of class  Image */
#ifndef TOLUA_DISABLE_tolua_set_Image_resizeable
static int tolua_set_Image_resizeable(lua_State* tolua_S)
{
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resizeable'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->resizeable = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setsize of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_setsize00
static int tolua_MyUI1_Image_setsize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setsize'",NULL);
#endif
  {
   self->setsize(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setsize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInView of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_setInView00
static int tolua_MyUI1_Image_setInView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInView'",NULL);
#endif
  {
   self->setInView(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setResizeable of class  Image */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Image_setResizeable00
static int tolua_MyUI1_Image_setResizeable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Image",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* self = (Image*)  tolua_tousertype(tolua_S,1,0);
  bool tag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setResizeable'",NULL);
#endif
  {
   self->setResizeable(tag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setResizeable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Button */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Button_create00
static int tolua_MyUI1_Button_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Button",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isstring(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,NULL));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,NULL));
  {
   Button* tolua_ret = (Button*)  Button::create(upName,downName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Button");
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

/* method: doTouch of class  Button */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Button_doTouch00
static int tolua_MyUI1_Button_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent event = ((TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: up of class  Button */
#ifndef TOLUA_DISABLE_tolua_get_Button_up
static int tolua_get_Button_up(lua_State* tolua_S)
{
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'up'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->up);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: up of class  Button */
#ifndef TOLUA_DISABLE_tolua_set_Button_up
static int tolua_set_Button_up(lua_State* tolua_S)
{
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'up'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->up = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Button */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Button_new00
static int tolua_MyUI1_Button_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Button",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Button* tolua_ret = (Button*)  Mtolua_new((Button)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Button");
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

/* method: new_local of class  Button */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Button_new00_local
static int tolua_MyUI1_Button_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Button",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Button* tolua_ret = (Button*)  Mtolua_new((Button)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Button");
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

/* method: draw of class  Button */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Button_draw00
static int tolua_MyUI1_Button_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'",NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  Button */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Button_checkIn00
static int tolua_MyUI1_Button_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Button",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Button* self = (Button*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(*point);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Choice */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Choice_create00
static int tolua_MyUI1_Choice_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Choice",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isstring(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,NULL));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,NULL));
  {
   Choice* tolua_ret = (Choice*)  Choice::create(upName,downName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Choice");
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

/* method: doTouch of class  Choice */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Choice_doTouch00
static int tolua_MyUI1_Choice_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Choice",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Choice* self = (Choice*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent event = ((TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: choiceAble of class  Choice */
#ifndef TOLUA_DISABLE_tolua_get_Choice_choiceAble
static int tolua_get_Choice_choiceAble(lua_State* tolua_S)
{
  Choice* self = (Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'choiceAble'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->choiceAble);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: choiceAble of class  Choice */
#ifndef TOLUA_DISABLE_tolua_set_Choice_choiceAble
static int tolua_set_Choice_choiceAble(lua_State* tolua_S)
{
  Choice* self = (Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'choiceAble'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->choiceAble = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  Choice */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Choice_checkIn00
static int tolua_MyUI1_Choice_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Choice",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Choice* self = (Choice*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(*point);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  Choice */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Choice_draw00
static int tolua_MyUI1_Choice_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Choice",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Choice* self = (Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'",NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Bubble */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Bubble_create00
static int tolua_MyUI1_Bubble_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Bubble",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   Bubble* tolua_ret = (Bubble*)  Bubble::create(upName,downName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Bubble");
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

/* method: doTouch of class  Bubble */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Bubble_doTouch00
static int tolua_MyUI1_Bubble_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Bubble",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Bubble* self = (Bubble*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent event = ((TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Bubble */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Bubble_new00
static int tolua_MyUI1_Bubble_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Bubble",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Bubble* tolua_ret = (Bubble*)  Mtolua_new((Bubble)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Bubble");
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

/* method: new_local of class  Bubble */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Bubble_new00_local
static int tolua_MyUI1_Bubble_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Bubble",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Bubble* tolua_ret = (Bubble*)  Mtolua_new((Bubble)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Bubble");
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

/* method: checkIn of class  Bubble */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Bubble_checkIn00
static int tolua_MyUI1_Bubble_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Bubble",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Bubble* self = (Bubble*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(*point);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  Bubble */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Bubble_draw00
static int tolua_MyUI1_Bubble_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Bubble",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Bubble* self = (Bubble*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'",NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: popUp of class  Bubble */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Bubble_popUp00
static int tolua_MyUI1_Bubble_popUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Bubble",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Bubble* self = (Bubble*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popUp'",NULL);
#endif
  {
   self->popUp();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Slider_create00
static int tolua_MyUI1_Slider_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Slider",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   Slider* tolua_ret = (Slider*)  Slider::create(upName,downName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Slider");
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

/* method: init of class  Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Slider_init00
static int tolua_MyUI1_Slider_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Slider",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(upName,downName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Slider_checkIn00
static int tolua_MyUI1_Slider_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Slider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Slider_doTouch00
static int tolua_MyUI1_Slider_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Slider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent event = ((TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: backSprite of class  Slider */
#ifndef TOLUA_DISABLE_tolua_get_Slider_backSprite_ptr
static int tolua_get_Slider_backSprite_ptr(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'backSprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->backSprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: backSprite of class  Slider */
#ifndef TOLUA_DISABLE_tolua_set_Slider_backSprite_ptr
static int tolua_set_Slider_backSprite_ptr(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'backSprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->backSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sliderSprite of class  Slider */
#ifndef TOLUA_DISABLE_tolua_get_Slider_sliderSprite_ptr
static int tolua_get_Slider_sliderSprite_ptr(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sliderSprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->sliderSprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sliderSprite of class  Slider */
#ifndef TOLUA_DISABLE_tolua_set_Slider_sliderSprite_ptr
static int tolua_set_Slider_sliderSprite_ptr(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sliderSprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sliderSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getValue of class  Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Slider_getValue00
static int tolua_MyUI1_Slider_getValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Slider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValue'",NULL);
#endif
  {
   float tolua_ret = (float)  self->getValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setValue of class  Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Slider_setValue00
static int tolua_MyUI1_Slider_setValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Slider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setValue'",NULL);
#endif
  {
   self->setValue(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  Slider */
#ifndef TOLUA_DISABLE_tolua_get_Slider_value
static int tolua_get_Slider_value(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  Slider */
#ifndef TOLUA_DISABLE_tolua_set_Slider_value
static int tolua_set_Slider_value(lua_State* tolua_S)
{
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->value = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Slider_new00
static int tolua_MyUI1_Slider_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Slider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Slider* tolua_ret = (Slider*)  Mtolua_new((Slider)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Slider");
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

/* method: new_local of class  Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Slider_new00_local
static int tolua_MyUI1_Slider_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Slider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Slider* tolua_ret = (Slider*)  Mtolua_new((Slider)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Slider");
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

/* method: getMaxValue of class  Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Slider_getMaxValue00
static int tolua_MyUI1_Slider_getMaxValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Slider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Slider* self = (Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaxValue'",NULL);
#endif
  {
   float tolua_ret = (float)  self->getMaxValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaxValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Label */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Label_create00
static int tolua_MyUI1_Label_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Label",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* content = ((const char*)  tolua_tostring(tolua_S,2,0));
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  {
   Label* tolua_ret = (Label*)  Label::create(content,*size);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Label");
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

/* method: init of class  Label */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Label_init00
static int tolua_MyUI1_Label_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Label",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Label* self = (Label*)  tolua_tousertype(tolua_S,1,0);
  const char* content = ((const char*)  tolua_tostring(tolua_S,2,0));
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(content,*size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArgs of class  Label */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Label_getArgs00
static int tolua_MyUI1_Label_getArgs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Label",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"std::vector<std::string>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* content = ((const char*)  tolua_tostring(tolua_S,2,0));
  int argc = ((int)  tolua_tonumber(tolua_S,3,0));
  std::vector<std::string>* args = ((std::vector<std::string>*)  tolua_tousertype(tolua_S,4,0));
  {
   const char* tolua_ret = (const char*)  Label::getArgs(content,argc,*args);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArgs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  Label */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Label_checkIn00
static int tolua_MyUI1_Label_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Label",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Label* self = (Label*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  Label */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Label_doTouch00
static int tolua_MyUI1_Label_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Label",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Label* self = (Label*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent event = ((TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rect of class  Label */
#ifndef TOLUA_DISABLE_tolua_get_Label_rect
static int tolua_get_Label_rect(lua_State* tolua_S)
{
  Label* self = (Label*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->rect,"CCRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rect of class  Label */
#ifndef TOLUA_DISABLE_tolua_set_Label_rect
static int tolua_set_Label_rect(lua_State* tolua_S)
{
  Label* self = (Label*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rect = *((CCRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setNumber of class  Label */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Label_setNumber00
static int tolua_MyUI1_Label_setNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Label",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Label* self = (Label*)  tolua_tousertype(tolua_S,1,0);
  int tag = ((int)  tolua_tonumber(tolua_S,2,0));
  double value = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setNumber'",NULL);
#endif
  {
   self->setNumber(tag,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNumber of class  Label */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Label_getNumber00
static int tolua_MyUI1_Label_getNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Label",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Label* self = (Label*)  tolua_tousertype(tolua_S,1,0);
  int tag = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumber'",NULL);
#endif
  {
   double tolua_ret = (double)  self->getNumber(tag);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  Label */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Label_draw00
static int tolua_MyUI1_Label_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Label",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Label* self = (Label*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'",NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_HPLabel_create00
static int tolua_MyUI1_HPLabel_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HPLabel",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isstring(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* backName = ((const char*)  tolua_tostring(tolua_S,2,NULL));
  const char* showName = ((const char*)  tolua_tostring(tolua_S,3,NULL));
  {
   HPLabel* tolua_ret = (HPLabel*)  HPLabel::create(backName,showName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HPLabel");
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

/* method: init of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_HPLabel_init00
static int tolua_MyUI1_HPLabel_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HPLabel",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HPLabel* self = (HPLabel*)  tolua_tousertype(tolua_S,1,0);
  const char* backName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* showName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(backName,showName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setValue of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_HPLabel_setValue00
static int tolua_MyUI1_HPLabel_setValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HPLabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HPLabel* self = (HPLabel*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setValue'",NULL);
#endif
  {
   self->setValue(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: viewSize of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_HPLabel_viewSize
static int tolua_get_HPLabel_viewSize(lua_State* tolua_S)
{
  HPLabel* self = (HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'viewSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->viewSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: viewSize of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_HPLabel_viewSize
static int tolua_set_HPLabel_viewSize(lua_State* tolua_S)
{
  HPLabel* self = (HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'viewSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->viewSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxValue of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_HPLabel_maxValue
static int tolua_get_HPLabel_maxValue(lua_State* tolua_S)
{
  HPLabel* self = (HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxValue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->maxValue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxValue of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_HPLabel_maxValue
static int tolua_set_HPLabel_maxValue(lua_State* tolua_S)
{
  HPLabel* self = (HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxValue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->maxValue = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_HPLabel_value
static int tolua_get_HPLabel_value(lua_State* tolua_S)
{
  HPLabel* self = (HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_HPLabel_value
static int tolua_set_HPLabel_value(lua_State* tolua_S)
{
  HPLabel* self = (HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->value = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: backSprite of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_HPLabel_backSprite_ptr
static int tolua_get_HPLabel_backSprite_ptr(lua_State* tolua_S)
{
  HPLabel* self = (HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'backSprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->backSprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: backSprite of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_HPLabel_backSprite_ptr
static int tolua_set_HPLabel_backSprite_ptr(lua_State* tolua_S)
{
  HPLabel* self = (HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'backSprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->backSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: valueSprite of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_HPLabel_valueSprite_ptr
static int tolua_get_HPLabel_valueSprite_ptr(lua_State* tolua_S)
{
  HPLabel* self = (HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'valueSprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->valueSprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: valueSprite of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_HPLabel_valueSprite_ptr
static int tolua_set_HPLabel_valueSprite_ptr(lua_State* tolua_S)
{
  HPLabel* self = (HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'valueSprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->valueSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_HPLabel_new00
static int tolua_MyUI1_HPLabel_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HPLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   HPLabel* tolua_ret = (HPLabel*)  Mtolua_new((HPLabel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HPLabel");
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

/* method: new_local of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_HPLabel_new00_local
static int tolua_MyUI1_HPLabel_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HPLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   HPLabel* tolua_ret = (HPLabel*)  Mtolua_new((HPLabel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HPLabel");
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

/* method: draw of class  HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_HPLabel_draw00
static int tolua_MyUI1_HPLabel_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HPLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HPLabel* self = (HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'",NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Tree_new00
static int tolua_MyUI1_Tree_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Tree* tolua_ret = (Tree*)  Mtolua_new((Tree)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Tree");
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

/* method: new_local of class  Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Tree_new00_local
static int tolua_MyUI1_Tree_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Tree* tolua_ret = (Tree*)  Mtolua_new((Tree)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Tree");
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

/* method: create of class  Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Tree_create00
static int tolua_MyUI1_Tree_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* image = ((Image*)  tolua_tousertype(tolua_S,2,0));
  {
   Tree* tolua_ret = (Tree*)  Tree::create(image);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Tree");
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

/* method: addTree of class  Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Tree_addTree00
static int tolua_MyUI1_Tree_addTree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
  Tree* tree = ((Tree*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTree'",NULL);
#endif
  {
   self->addTree(tree);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Tree_show00
static int tolua_MyUI1_Tree_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Tree_visit00
static int tolua_MyUI1_Tree_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: parent of class  Tree */
#ifndef TOLUA_DISABLE_tolua_get_Tree_parent_ptr
static int tolua_get_Tree_parent_ptr(lua_State* tolua_S)
{
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->parent,"Tree");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: parent of class  Tree */
#ifndef TOLUA_DISABLE_tolua_set_Tree_parent_ptr
static int tolua_set_Tree_parent_ptr(lua_State* tolua_S)
{
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Tree",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->parent = ((Tree*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: next of class  Tree */
#ifndef TOLUA_DISABLE_tolua_get_Tree_next_ptr
static int tolua_get_Tree_next_ptr(lua_State* tolua_S)
{
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'next'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->next,"Tree");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: next of class  Tree */
#ifndef TOLUA_DISABLE_tolua_set_Tree_next_ptr
static int tolua_set_Tree_next_ptr(lua_State* tolua_S)
{
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'next'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Tree",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->next = ((Tree*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: child of class  Tree */
#ifndef TOLUA_DISABLE_tolua_get_Tree_child_ptr
static int tolua_get_Tree_child_ptr(lua_State* tolua_S)
{
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'child'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->child,"Tree");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: child of class  Tree */
#ifndef TOLUA_DISABLE_tolua_set_Tree_child_ptr
static int tolua_set_Tree_child_ptr(lua_State* tolua_S)
{
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'child'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Tree",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->child = ((Tree*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: image of class  Tree */
#ifndef TOLUA_DISABLE_tolua_get_Tree_image_ptr
static int tolua_get_Tree_image_ptr(lua_State* tolua_S)
{
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->image,"Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: image of class  Tree */
#ifndef TOLUA_DISABLE_tolua_set_Tree_image_ptr
static int tolua_set_Tree_image_ptr(lua_State* tolua_S)
{
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->image = ((Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isOpen of class  Tree */
#ifndef TOLUA_DISABLE_tolua_get_Tree_isOpen
static int tolua_get_Tree_isOpen(lua_State* tolua_S)
{
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isOpen'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isOpen);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isOpen of class  Tree */
#ifndef TOLUA_DISABLE_tolua_set_Tree_isOpen
static int tolua_set_Tree_isOpen(lua_State* tolua_S)
{
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isOpen'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isOpen = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Tree_show01
static int tolua_MyUI1_Tree_show01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Tree",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
  Tree* tree = ((Tree*)  tolua_tousertype(tolua_S,2,0));
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->show(tree,*point);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_MyUI1_Tree_show00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Tree_checkIn00
static int tolua_MyUI1_Tree_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Tree_doTouch00
static int tolua_MyUI1_Tree_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Tree",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent event = ((TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkInTree of class  Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Tree_checkInTree00
static int tolua_MyUI1_Tree_checkInTree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
  Tree* tree = ((Tree*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkInTree'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkInTree(touch,tree);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkInTree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchInTree of class  Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Tree_touchInTree00
static int tolua_MyUI1_Tree_touchInTree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Tree",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent event = ((TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
  Tree* tree = ((Tree*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchInTree'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchInTree(event,touch,tree);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchInTree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hideCloseNode of class  Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Tree_hideCloseNode00
static int tolua_MyUI1_Tree_hideCloseNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Tree* self = (Tree*)  tolua_tousertype(tolua_S,1,0);
  Tree* node = ((Tree*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hideCloseNode'",NULL);
#endif
  {
   self->hideCloseNode(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hideCloseNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  List */
#ifndef TOLUA_DISABLE_tolua_MyUI1_List_new00
static int tolua_MyUI1_List_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   List* tolua_ret = (List*)  Mtolua_new((List)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"List");
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

/* method: new_local of class  List */
#ifndef TOLUA_DISABLE_tolua_MyUI1_List_new00_local
static int tolua_MyUI1_List_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   List* tolua_ret = (List*)  Mtolua_new((List)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"List");
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

/* method: create of class  List */
#ifndef TOLUA_DISABLE_tolua_MyUI1_List_create00
static int tolua_MyUI1_List_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Image* image = ((Image*)  tolua_tousertype(tolua_S,2,0));
  {
   List* tolua_ret = (List*)  List::create(image);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"List");
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

/* method: create of class  List */
#ifndef TOLUA_DISABLE_tolua_MyUI1_List_create01
static int tolua_MyUI1_List_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Image* image = ((Image*)  tolua_tousertype(tolua_S,2,0));
  const CCSize* cellSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  {
   List* tolua_ret = (List*)  List::create(image,*cellSize);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"List");
  }
 }
 return 1;
tolua_lerror:
 return tolua_MyUI1_List_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  List */
#ifndef TOLUA_DISABLE_tolua_MyUI1_List_remove00
static int tolua_MyUI1_List_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  List* self = (List*)  tolua_tousertype(tolua_S,1,0);
  List* list = ((List*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'",NULL);
#endif
  {
   self->remove(list);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  List */
#ifndef TOLUA_DISABLE_tolua_MyUI1_List_add00
static int tolua_MyUI1_List_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  List* self = (List*)  tolua_tousertype(tolua_S,1,0);
  Image* list = ((Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
  {
   self->add(list);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  List */
#ifndef TOLUA_DISABLE_tolua_MyUI1_List_show00
static int tolua_MyUI1_List_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  List* self = (List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cellSize of class  List */
#ifndef TOLUA_DISABLE_tolua_get_List_cellSize
static int tolua_get_List_cellSize(lua_State* tolua_S)
{
  List* self = (List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->cellSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cellSize of class  List */
#ifndef TOLUA_DISABLE_tolua_set_List_cellSize
static int tolua_set_List_cellSize(lua_State* tolua_S)
{
  List* self = (List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cellSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  List */
#ifndef TOLUA_DISABLE_tolua_MyUI1_List_checkIn00
static int tolua_MyUI1_List_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  List* self = (List*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  List */
#ifndef TOLUA_DISABLE_tolua_MyUI1_List_doTouch00
static int tolua_MyUI1_List_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  List* self = (List*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent event = ((TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickImageIndex of class  List */
#ifndef TOLUA_DISABLE_tolua_MyUI1_List_pickImageIndex00
static int tolua_MyUI1_List_pickImageIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  List* self = (List*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pickImageIndex'",NULL);
#endif
  {
   int tolua_ret = (int)  self->pickImageIndex(touch);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickImageIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickImage of class  List */
#ifndef TOLUA_DISABLE_tolua_MyUI1_List_pickImage00
static int tolua_MyUI1_List_pickImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  List* self = (List*)  tolua_tousertype(tolua_S,1,0);
  const int index = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pickImage'",NULL);
#endif
  {
   Image* tolua_ret = (Image*)  self->pickImage(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Image");
   tolua_pushnumber(tolua_S,(lua_Number)index);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nowTouchImage of class  List */
#ifndef TOLUA_DISABLE_tolua_get_List_nowTouchImage_ptr
static int tolua_get_List_nowTouchImage_ptr(lua_State* tolua_S)
{
  List* self = (List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchImage'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->nowTouchImage,"Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nowTouchImage of class  List */
#ifndef TOLUA_DISABLE_tolua_set_List_nowTouchImage_ptr
static int tolua_set_List_nowTouchImage_ptr(lua_State* tolua_S)
{
  List* self = (List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchImage'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nowTouchImage = ((Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: exchageAble of class  List */
#ifndef TOLUA_DISABLE_tolua_get_List_exchageAble
static int tolua_get_List_exchageAble(lua_State* tolua_S)
{
  List* self = (List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exchageAble'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->exchageAble);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: exchageAble of class  List */
#ifndef TOLUA_DISABLE_tolua_set_List_exchageAble
static int tolua_set_List_exchageAble(lua_State* tolua_S)
{
  List* self = (List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exchageAble'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->exchageAble = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_new00
static int tolua_MyUI1_Table_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Table",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Table* tolua_ret = (Table*)  Mtolua_new((Table)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Table");
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

/* method: new_local of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_new00_local
static int tolua_MyUI1_Table_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Table",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Table* tolua_ret = (Table*)  Mtolua_new((Table)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Table");
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

/* method: create of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_create00
static int tolua_MyUI1_Table_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Table",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCSize* tableSize = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
  const CCSize* cellSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  {
   Table* tolua_ret = (Table*)  Table::create(*tableSize,*cellSize);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Table");
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

/* get function: exchageAble of class  Table */
#ifndef TOLUA_DISABLE_tolua_get_Table_exchageAble
static int tolua_get_Table_exchageAble(lua_State* tolua_S)
{
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exchageAble'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->exchageAble);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: exchageAble of class  Table */
#ifndef TOLUA_DISABLE_tolua_set_Table_exchageAble
static int tolua_set_Table_exchageAble(lua_State* tolua_S)
{
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exchageAble'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->exchageAble = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_add00
static int tolua_MyUI1_Table_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Table",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  Image* image = ((Image*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
  {
   self->add(*point,image);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: push of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_push00
static int tolua_MyUI1_Table_push00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
  Image* image = ((Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push'",NULL);
#endif
  {
   self->push(image);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_remove00
static int tolua_MyUI1_Table_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
  Image* image = ((Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'",NULL);
#endif
  {
   self->remove(image);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_checkIn00
static int tolua_MyUI1_Table_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_doTouch00
static int tolua_MyUI1_Table_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Table",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent event = ((TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickImageIndex of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_pickImageIndex00
static int tolua_MyUI1_Table_pickImageIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pickImageIndex'",NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->pickImageIndex(touch);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickImageIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickImage of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_pickImage00
static int tolua_MyUI1_Table_pickImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Table",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pickImage'",NULL);
#endif
  {
   Image* tolua_ret = (Image*)  self->pickImage(*point);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Image");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_show00
static int tolua_MyUI1_Table_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Table",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tableSize of class  Table */
#ifndef TOLUA_DISABLE_tolua_get_Table_tableSize
static int tolua_get_Table_tableSize(lua_State* tolua_S)
{
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tableSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->tableSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tableSize of class  Table */
#ifndef TOLUA_DISABLE_tolua_set_Table_tableSize
static int tolua_set_Table_tableSize(lua_State* tolua_S)
{
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tableSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tableSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cellSize of class  Table */
#ifndef TOLUA_DISABLE_tolua_get_Table_cellSize
static int tolua_get_Table_cellSize(lua_State* tolua_S)
{
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->cellSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cellSize of class  Table */
#ifndef TOLUA_DISABLE_tolua_set_Table_cellSize
static int tolua_set_Table_cellSize(lua_State* tolua_S)
{
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cellSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nowTouchImage of class  Table */
#ifndef TOLUA_DISABLE_tolua_get_Table_nowTouchImage_ptr
static int tolua_get_Table_nowTouchImage_ptr(lua_State* tolua_S)
{
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchImage'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->nowTouchImage,"Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nowTouchImage of class  Table */
#ifndef TOLUA_DISABLE_tolua_set_Table_nowTouchImage_ptr
static int tolua_set_Table_nowTouchImage_ptr(lua_State* tolua_S)
{
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchImage'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nowTouchImage = ((Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_visit00
static int tolua_MyUI1_Table_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Table",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
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

/* method: doExchange of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_doExchange00
static int tolua_MyUI1_Table_doExchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
  Image* src = ((Image*)  tolua_tousertype(tolua_S,2,0));
  Image* dest = ((Image*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doExchange'",NULL);
#endif
  {
   self->doExchange(src,dest);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doExchange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeIndex of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_removeIndex00
static int tolua_MyUI1_Table_removeIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
  Image* src = ((Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeIndex'",NULL);
#endif
  {
   self->removeIndex(src);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  Table */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Table_draw00
static int tolua_MyUI1_Table_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Table",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Table* self = (Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'",NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI1_ScrollView_create00
static int tolua_MyUI1_ScrollView_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   ScrollView* tolua_ret = (ScrollView*)  ScrollView::create(width,height);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ScrollView");
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

/* method: init of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI1_ScrollView_init00
static int tolua_MyUI1_ScrollView_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(width,height);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI1_ScrollView_add00
static int tolua_MyUI1_ScrollView_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  Image* base = ((Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
  {
   self->add(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI1_ScrollView_visit00
static int tolua_MyUI1_ScrollView_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: width of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_width
static int tolua_get_ScrollView_width(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_width
static int tolua_set_ScrollView_width(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_height
static int tolua_get_ScrollView_height(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_height
static int tolua_set_ScrollView_height(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI1_ScrollView_new00
static int tolua_MyUI1_ScrollView_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ScrollView* tolua_ret = (ScrollView*)  Mtolua_new((ScrollView)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ScrollView");
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

/* method: new_local of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI1_ScrollView_new00_local
static int tolua_MyUI1_ScrollView_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ScrollView* tolua_ret = (ScrollView*)  Mtolua_new((ScrollView)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ScrollView");
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

/* get function: eachTap of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_eachTap
static int tolua_get_ScrollView_eachTap(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eachTap'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->eachTap,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: eachTap of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_eachTap
static int tolua_set_ScrollView_eachTap(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eachTap'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->eachTap = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scrollType of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_scrollType
static int tolua_get_ScrollView_scrollType(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->scrollType);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scrollType of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_scrollType
static int tolua_set_ScrollView_scrollType(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->scrollType = ((ScrollView::SCROLL_TYPE) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEachTap of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI1_ScrollView_setEachTap00
static int tolua_MyUI1_ScrollView_setEachTap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  const CCSize eachTap = *((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEachTap'",NULL);
#endif
  {
   self->setEachTap(eachTap);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEachTap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScrollType of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI1_ScrollView_setScrollType00
static int tolua_MyUI1_ScrollView_setScrollType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  ScrollView::SCROLL_TYPE scrollType = ((ScrollView::SCROLL_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScrollType'",NULL);
#endif
  {
   self->setScrollType(scrollType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScrollType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: child of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_ScrollView_child_ptr
static int tolua_get_ScrollView_child_ptr(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'child'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->child,"Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: child of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_ScrollView_child_ptr
static int tolua_set_ScrollView_child_ptr(lua_State* tolua_S)
{
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'child'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->child = ((Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI1_ScrollView_checkIn00
static int tolua_MyUI1_ScrollView_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI1_ScrollView_doTouch00
static int tolua_MyUI1_ScrollView_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent event = ((TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI1_ScrollView_draw00
static int tolua_MyUI1_ScrollView_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'",NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Panel_create00
static int tolua_MyUI1_Panel_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Panel* tolua_ret = (Panel*)  Panel::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Panel");
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

/* get function: uis of class  Panel */
#ifndef TOLUA_DISABLE_tolua_get_Panel_uis
static int tolua_get_Panel_uis(lua_State* tolua_S)
{
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uis'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->uis,"std::list<Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: uis of class  Panel */
#ifndef TOLUA_DISABLE_tolua_set_Panel_uis
static int tolua_set_Panel_uis(lua_State* tolua_S)
{
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uis'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->uis = *((std::list<Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: actives of class  Panel */
#ifndef TOLUA_DISABLE_tolua_get_Panel_actives
static int tolua_get_Panel_actives(lua_State* tolua_S)
{
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'actives'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->actives,"std::list<Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: actives of class  Panel */
#ifndef TOLUA_DISABLE_tolua_set_Panel_actives
static int tolua_set_Panel_actives(lua_State* tolua_S)
{
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'actives'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->actives = *((std::list<Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: firsts of class  Panel */
#ifndef TOLUA_DISABLE_tolua_get_Panel_firsts
static int tolua_get_Panel_firsts(lua_State* tolua_S)
{
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firsts'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->firsts,"std::list<Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: firsts of class  Panel */
#ifndef TOLUA_DISABLE_tolua_set_Panel_firsts
static int tolua_set_Panel_firsts(lua_State* tolua_S)
{
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firsts'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->firsts = *((std::list<Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachTouch of class  Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Panel_attachTouch00
static int tolua_MyUI1_Panel_attachTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
  TouchEvent event = ((TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->attachTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addUI of class  Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Panel_addUI00
static int tolua_MyUI1_Panel_addUI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
  Base* base = ((Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addUI'",NULL);
#endif
  {
   self->addUI(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addUI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Panel_visit00
static int tolua_MyUI1_Panel_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setLocation of class  Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Panel_setLocation00
static int tolua_MyUI1_Panel_setLocation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
  AlignType alignType = ((AlignType) (int)  tolua_tonumber(tolua_S,2,0));
  const CCSize* splitSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  const CCPoint* gridLocation = ((const CCPoint*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLocation'",NULL);
#endif
  {
   self->setLocation(alignType,*splitSize,*gridLocation);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLocation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSize of class  Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Panel_setSize00
static int tolua_MyUI1_Panel_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'",NULL);
#endif
  {
   self->setSize(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rect of class  Panel */
#ifndef TOLUA_DISABLE_tolua_get_Panel_rect
static int tolua_get_Panel_rect(lua_State* tolua_S)
{
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->rect,"CCRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rect of class  Panel */
#ifndef TOLUA_DISABLE_tolua_set_Panel_rect
static int tolua_set_Panel_rect(lua_State* tolua_S)
{
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rect = *((CCRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSize of class  Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Panel_getSize00
static int tolua_MyUI1_Panel_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'",NULL);
#endif
  {
   CCSize tolua_ret = (CCSize)  self->getSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPoint of class  Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Panel_getPoint00
static int tolua_MyUI1_Panel_getPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
  AlignType alignType = ((AlignType) (int)  tolua_tonumber(tolua_S,2,0));
  const CCSize* splitSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  const CCPoint* gridLocation = ((const CCPoint*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPoint'",NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->getPoint(alignType,*splitSize,*gridLocation);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Panel_checkIn00
static int tolua_MyUI1_Panel_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(*point);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Panel_draw00
static int tolua_MyUI1_Panel_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Panel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Panel* self = (Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'",NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Window */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Window_create00
static int tolua_MyUI1_Window_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Window* tolua_ret = (Window*)  Window::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Window");
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

/* method: init of class  Window */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Window_init00
static int tolua_MyUI1_Window_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchesBegan of class  Window */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Window_ccTouchesBegan00
static int tolua_MyUI1_Window_ccTouchesBegan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cocos2d::CCSet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"cocos2d::CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::CCSet* pTouches = ((cocos2d::CCSet*)  tolua_tousertype(tolua_S,2,0));
  cocos2d::CCEvent* pEvent = ((cocos2d::CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchesBegan'",NULL);
#endif
  {
   self->ccTouchesBegan(pTouches,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchesBegan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchesMoved of class  Window */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Window_ccTouchesMoved00
static int tolua_MyUI1_Window_ccTouchesMoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cocos2d::CCSet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"cocos2d::CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::CCSet* pTouch = ((cocos2d::CCSet*)  tolua_tousertype(tolua_S,2,0));
  cocos2d::CCEvent* pEvent = ((cocos2d::CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchesMoved'",NULL);
#endif
  {
   self->ccTouchesMoved(pTouch,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchesMoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchesEnded of class  Window */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Window_ccTouchesEnded00
static int tolua_MyUI1_Window_ccTouchesEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cocos2d::CCSet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"cocos2d::CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::CCSet* pTouch = ((cocos2d::CCSet*)  tolua_tousertype(tolua_S,2,0));
  cocos2d::CCEvent* pEvent = ((cocos2d::CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchesEnded'",NULL);
#endif
  {
   self->ccTouchesEnded(pTouch,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchesEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addUI of class  Window */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Window_addUI00
static int tolua_MyUI1_Window_addUI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
  Base* base = ((Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addUI'",NULL);
#endif
  {
   self->addUI(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addUI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  Window */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Window_visit00
static int tolua_MyUI1_Window_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Window* self = (Window*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getWindowSize of class  Window */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Window_getWindowSize00
static int tolua_MyUI1_Window_getWindowSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCSize tolua_ret = (CCSize)  Window::getWindowSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWindowSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPoint of class  Window */
#ifndef TOLUA_DISABLE_tolua_MyUI1_Window_getPoint00
static int tolua_MyUI1_Window_getPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AlignType alignType = ((AlignType) (int)  tolua_tonumber(tolua_S,2,0));
  const CCSize* splitSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  const CCPoint* gridLocation = ((const CCPoint*)  tolua_tousertype(tolua_S,4,0));
  {
   CCPoint tolua_ret = (CCPoint)  Window::getPoint(alignType,*splitSize,*gridLocation);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_MyUI1_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"TOUCH_DOWN",TOUCH_DOWN);
  tolua_constant(tolua_S,"TOUCH_MOVE",TOUCH_MOVE);
  tolua_constant(tolua_S,"TOUCH_END",TOUCH_END);
  tolua_constant(tolua_S,"ALIGN_LEFT",ALIGN_LEFT);
  tolua_constant(tolua_S,"ALIGN_RIGHT",ALIGN_RIGHT);
  tolua_constant(tolua_S,"ALIGN_UP",ALIGN_UP);
  tolua_constant(tolua_S,"ALIGN_BOTTOM",ALIGN_BOTTOM);
  tolua_constant(tolua_S,"ALIGN_CENTER",ALIGN_CENTER);
  tolua_constant(tolua_S,"FIT_SELF",FIT_SELF);
  tolua_constant(tolua_S,"FIT_GRID",FIT_GRID);
  tolua_constant(tolua_S,"HANDLE_DOWN",HANDLE_DOWN);
  tolua_constant(tolua_S,"HANDLE_MOVE",HANDLE_MOVE);
  tolua_constant(tolua_S,"HANDLE_END",HANDLE_END);
  tolua_constant(tolua_S,"HANDLE_DRAW",HANDLE_DRAW);
  tolua_constant(tolua_S,"HANDLE_CLICK",HANDLE_CLICK);
  tolua_constant(tolua_S,"HANDLE_TOUCHIN",HANDLE_TOUCHIN);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Base","Base","CCNode",tolua_collect_Base);
  #else
  tolua_cclass(tolua_S,"Base","Base","CCNode",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Base");
   tolua_function(tolua_S,"new",tolua_MyUI1_Base_new00);
   tolua_function(tolua_S,"new_local",tolua_MyUI1_Base_new00_local);
   tolua_function(tolua_S,".call",tolua_MyUI1_Base_new00_local);
   tolua_function(tolua_S,"setMoveable",tolua_MyUI1_Base_setMoveable00);
   tolua_function(tolua_S,"hide",tolua_MyUI1_Base_hide00);
   tolua_function(tolua_S,"show",tolua_MyUI1_Base_show00);
   tolua_variable(tolua_S,"nowTouchPoint",tolua_get_Base_nowTouchPoint,tolua_set_Base_nowTouchPoint);
   tolua_variable(tolua_S,"isActive",tolua_get_Base_isActive,tolua_set_Base_isActive);
   tolua_variable(tolua_S,"moveAble",tolua_get_Base_moveAble,tolua_set_Base_moveAble);
   tolua_variable(tolua_S,"panel",tolua_get_Base_panel_ptr,tolua_set_Base_panel_ptr);
   tolua_variable(tolua_S,"parent",tolua_get_Base_parent_ptr,tolua_set_Base_parent_ptr);
   tolua_function(tolua_S,"setLocation",tolua_MyUI1_Base_setLocation00);
   tolua_function(tolua_S,"setInView",tolua_MyUI1_Base_setInView00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Image","Image","Base",tolua_collect_Image);
  #else
  tolua_cclass(tolua_S,"Image","Image","Base",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Image");
   tolua_function(tolua_S,"create",tolua_MyUI1_Image_create00);
   tolua_function(tolua_S,"checkIn",tolua_MyUI1_Image_checkIn00);
   tolua_function(tolua_S,"checkIn",tolua_MyUI1_Image_checkIn01);
   tolua_function(tolua_S,"setOutLine",tolua_MyUI1_Image_setOutLine00);
   tolua_function(tolua_S,"doTouch",tolua_MyUI1_Image_doTouch00);
   tolua_variable(tolua_S,"sprite",tolua_get_Image_sprite_ptr,tolua_set_Image_sprite_ptr);
   tolua_function(tolua_S,"show",tolua_MyUI1_Image_show00);
   tolua_function(tolua_S,"draw",tolua_MyUI1_Image_draw00);
   tolua_function(tolua_S,"replacePng",tolua_MyUI1_Image_replacePng00);
   tolua_function(tolua_S,"checkIn",tolua_MyUI1_Image_checkIn02);
   tolua_function(tolua_S,"checkInRect",tolua_MyUI1_Image_checkInRect00);
   tolua_function(tolua_S,"createImage",tolua_MyUI1_Image_createImage00);
   tolua_function(tolua_S,"delete",tolua_MyUI1_Image_delete00);
   tolua_function(tolua_S,"new",tolua_MyUI1_Image_new00);
   tolua_function(tolua_S,"new_local",tolua_MyUI1_Image_new00_local);
   tolua_function(tolua_S,".call",tolua_MyUI1_Image_new00_local);
   tolua_function(tolua_S,"runAction",tolua_MyUI1_Image_runAction00);
   tolua_function(tolua_S,"getViewSize",tolua_MyUI1_Image_getViewSize00);
   tolua_variable(tolua_S,"imageSize",tolua_get_Image_imageSize,tolua_set_Image_imageSize);
   tolua_variable(tolua_S,"resizeable",tolua_get_Image_resizeable,tolua_set_Image_resizeable);
   tolua_function(tolua_S,"setsize",tolua_MyUI1_Image_setsize00);
   tolua_function(tolua_S,"setInView",tolua_MyUI1_Image_setInView00);
   tolua_function(tolua_S,"setResizeable",tolua_MyUI1_Image_setResizeable00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Button","Button","Image",tolua_collect_Button);
  #else
  tolua_cclass(tolua_S,"Button","Button","Image",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Button");
   tolua_function(tolua_S,"create",tolua_MyUI1_Button_create00);
   tolua_function(tolua_S,"doTouch",tolua_MyUI1_Button_doTouch00);
   tolua_variable(tolua_S,"up",tolua_get_Button_up,tolua_set_Button_up);
   tolua_function(tolua_S,"new",tolua_MyUI1_Button_new00);
   tolua_function(tolua_S,"new_local",tolua_MyUI1_Button_new00_local);
   tolua_function(tolua_S,".call",tolua_MyUI1_Button_new00_local);
   tolua_function(tolua_S,"draw",tolua_MyUI1_Button_draw00);
   tolua_function(tolua_S,"checkIn",tolua_MyUI1_Button_checkIn00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Choice","Choice","Image",NULL);
  tolua_beginmodule(tolua_S,"Choice");
   tolua_function(tolua_S,"create",tolua_MyUI1_Choice_create00);
   tolua_function(tolua_S,"doTouch",tolua_MyUI1_Choice_doTouch00);
   tolua_variable(tolua_S,"choiceAble",tolua_get_Choice_choiceAble,tolua_set_Choice_choiceAble);
   tolua_function(tolua_S,"checkIn",tolua_MyUI1_Choice_checkIn00);
   tolua_function(tolua_S,"draw",tolua_MyUI1_Choice_draw00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Bubble","Bubble","Choice",tolua_collect_Bubble);
  #else
  tolua_cclass(tolua_S,"Bubble","Bubble","Choice",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Bubble");
   tolua_function(tolua_S,"create",tolua_MyUI1_Bubble_create00);
   tolua_function(tolua_S,"doTouch",tolua_MyUI1_Bubble_doTouch00);
   tolua_function(tolua_S,"new",tolua_MyUI1_Bubble_new00);
   tolua_function(tolua_S,"new_local",tolua_MyUI1_Bubble_new00_local);
   tolua_function(tolua_S,".call",tolua_MyUI1_Bubble_new00_local);
   tolua_function(tolua_S,"checkIn",tolua_MyUI1_Bubble_checkIn00);
   tolua_function(tolua_S,"draw",tolua_MyUI1_Bubble_draw00);
   tolua_function(tolua_S,"popUp",tolua_MyUI1_Bubble_popUp00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Slider","Slider","Image",tolua_collect_Slider);
  #else
  tolua_cclass(tolua_S,"Slider","Slider","Image",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Slider");
   tolua_function(tolua_S,"create",tolua_MyUI1_Slider_create00);
   tolua_function(tolua_S,"init",tolua_MyUI1_Slider_init00);
   tolua_function(tolua_S,"checkIn",tolua_MyUI1_Slider_checkIn00);
   tolua_function(tolua_S,"doTouch",tolua_MyUI1_Slider_doTouch00);
   tolua_variable(tolua_S,"backSprite",tolua_get_Slider_backSprite_ptr,tolua_set_Slider_backSprite_ptr);
   tolua_variable(tolua_S,"sliderSprite",tolua_get_Slider_sliderSprite_ptr,tolua_set_Slider_sliderSprite_ptr);
   tolua_function(tolua_S,"getValue",tolua_MyUI1_Slider_getValue00);
   tolua_function(tolua_S,"setValue",tolua_MyUI1_Slider_setValue00);
   tolua_variable(tolua_S,"value",tolua_get_Slider_value,tolua_set_Slider_value);
   tolua_function(tolua_S,"new",tolua_MyUI1_Slider_new00);
   tolua_function(tolua_S,"new_local",tolua_MyUI1_Slider_new00_local);
   tolua_function(tolua_S,".call",tolua_MyUI1_Slider_new00_local);
   tolua_function(tolua_S,"getMaxValue",tolua_MyUI1_Slider_getMaxValue00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Label","Label","Base",NULL);
  tolua_beginmodule(tolua_S,"Label");
   tolua_function(tolua_S,"create",tolua_MyUI1_Label_create00);
   tolua_function(tolua_S,"init",tolua_MyUI1_Label_init00);
   tolua_function(tolua_S,"getArgs",tolua_MyUI1_Label_getArgs00);
   tolua_function(tolua_S,"checkIn",tolua_MyUI1_Label_checkIn00);
   tolua_function(tolua_S,"doTouch",tolua_MyUI1_Label_doTouch00);
   tolua_variable(tolua_S,"rect",tolua_get_Label_rect,tolua_set_Label_rect);
   tolua_function(tolua_S,"setNumber",tolua_MyUI1_Label_setNumber00);
   tolua_function(tolua_S,"getNumber",tolua_MyUI1_Label_getNumber00);
   tolua_function(tolua_S,"draw",tolua_MyUI1_Label_draw00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"HPLabel","HPLabel","Base",tolua_collect_HPLabel);
  #else
  tolua_cclass(tolua_S,"HPLabel","HPLabel","Base",NULL);
  #endif
  tolua_beginmodule(tolua_S,"HPLabel");
   tolua_function(tolua_S,"create",tolua_MyUI1_HPLabel_create00);
   tolua_function(tolua_S,"init",tolua_MyUI1_HPLabel_init00);
   tolua_function(tolua_S,"setValue",tolua_MyUI1_HPLabel_setValue00);
   tolua_variable(tolua_S,"viewSize",tolua_get_HPLabel_viewSize,tolua_set_HPLabel_viewSize);
   tolua_variable(tolua_S,"maxValue",tolua_get_HPLabel_maxValue,tolua_set_HPLabel_maxValue);
   tolua_variable(tolua_S,"value",tolua_get_HPLabel_value,tolua_set_HPLabel_value);
   tolua_variable(tolua_S,"backSprite",tolua_get_HPLabel_backSprite_ptr,tolua_set_HPLabel_backSprite_ptr);
   tolua_variable(tolua_S,"valueSprite",tolua_get_HPLabel_valueSprite_ptr,tolua_set_HPLabel_valueSprite_ptr);
   tolua_function(tolua_S,"new",tolua_MyUI1_HPLabel_new00);
   tolua_function(tolua_S,"new_local",tolua_MyUI1_HPLabel_new00_local);
   tolua_function(tolua_S,".call",tolua_MyUI1_HPLabel_new00_local);
   tolua_function(tolua_S,"draw",tolua_MyUI1_HPLabel_draw00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Tree","Tree","Base",tolua_collect_Tree);
  #else
  tolua_cclass(tolua_S,"Tree","Tree","Base",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Tree");
   tolua_function(tolua_S,"new",tolua_MyUI1_Tree_new00);
   tolua_function(tolua_S,"new_local",tolua_MyUI1_Tree_new00_local);
   tolua_function(tolua_S,".call",tolua_MyUI1_Tree_new00_local);
   tolua_function(tolua_S,"create",tolua_MyUI1_Tree_create00);
   tolua_function(tolua_S,"addTree",tolua_MyUI1_Tree_addTree00);
   tolua_function(tolua_S,"show",tolua_MyUI1_Tree_show00);
   tolua_function(tolua_S,"visit",tolua_MyUI1_Tree_visit00);
   tolua_variable(tolua_S,"parent",tolua_get_Tree_parent_ptr,tolua_set_Tree_parent_ptr);
   tolua_variable(tolua_S,"next",tolua_get_Tree_next_ptr,tolua_set_Tree_next_ptr);
   tolua_variable(tolua_S,"child",tolua_get_Tree_child_ptr,tolua_set_Tree_child_ptr);
   tolua_variable(tolua_S,"image",tolua_get_Tree_image_ptr,tolua_set_Tree_image_ptr);
   tolua_variable(tolua_S,"isOpen",tolua_get_Tree_isOpen,tolua_set_Tree_isOpen);
   tolua_function(tolua_S,"show",tolua_MyUI1_Tree_show01);
   tolua_function(tolua_S,"checkIn",tolua_MyUI1_Tree_checkIn00);
   tolua_function(tolua_S,"doTouch",tolua_MyUI1_Tree_doTouch00);
   tolua_function(tolua_S,"checkInTree",tolua_MyUI1_Tree_checkInTree00);
   tolua_function(tolua_S,"touchInTree",tolua_MyUI1_Tree_touchInTree00);
   tolua_function(tolua_S,"hideCloseNode",tolua_MyUI1_Tree_hideCloseNode00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"List","List","Base",tolua_collect_List);
  #else
  tolua_cclass(tolua_S,"List","List","Base",NULL);
  #endif
  tolua_beginmodule(tolua_S,"List");
   tolua_function(tolua_S,"new",tolua_MyUI1_List_new00);
   tolua_function(tolua_S,"new_local",tolua_MyUI1_List_new00_local);
   tolua_function(tolua_S,".call",tolua_MyUI1_List_new00_local);
   tolua_function(tolua_S,"create",tolua_MyUI1_List_create00);
   tolua_function(tolua_S,"create",tolua_MyUI1_List_create01);
   tolua_function(tolua_S,"remove",tolua_MyUI1_List_remove00);
   tolua_function(tolua_S,"add",tolua_MyUI1_List_add00);
   tolua_function(tolua_S,"show",tolua_MyUI1_List_show00);
   tolua_variable(tolua_S,"cellSize",tolua_get_List_cellSize,tolua_set_List_cellSize);
   tolua_function(tolua_S,"checkIn",tolua_MyUI1_List_checkIn00);
   tolua_function(tolua_S,"doTouch",tolua_MyUI1_List_doTouch00);
   tolua_function(tolua_S,"pickImageIndex",tolua_MyUI1_List_pickImageIndex00);
   tolua_function(tolua_S,"pickImage",tolua_MyUI1_List_pickImage00);
   tolua_variable(tolua_S,"nowTouchImage",tolua_get_List_nowTouchImage_ptr,tolua_set_List_nowTouchImage_ptr);
   tolua_variable(tolua_S,"exchageAble",tolua_get_List_exchageAble,tolua_set_List_exchageAble);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Table","Table","Base",tolua_collect_Table);
  #else
  tolua_cclass(tolua_S,"Table","Table","Base",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Table");
   tolua_function(tolua_S,"new",tolua_MyUI1_Table_new00);
   tolua_function(tolua_S,"new_local",tolua_MyUI1_Table_new00_local);
   tolua_function(tolua_S,".call",tolua_MyUI1_Table_new00_local);
   tolua_function(tolua_S,"create",tolua_MyUI1_Table_create00);
   tolua_variable(tolua_S,"exchageAble",tolua_get_Table_exchageAble,tolua_set_Table_exchageAble);
   tolua_function(tolua_S,"add",tolua_MyUI1_Table_add00);
   tolua_function(tolua_S,"push",tolua_MyUI1_Table_push00);
   tolua_function(tolua_S,"remove",tolua_MyUI1_Table_remove00);
   tolua_function(tolua_S,"checkIn",tolua_MyUI1_Table_checkIn00);
   tolua_function(tolua_S,"doTouch",tolua_MyUI1_Table_doTouch00);
   tolua_function(tolua_S,"pickImageIndex",tolua_MyUI1_Table_pickImageIndex00);
   tolua_function(tolua_S,"pickImage",tolua_MyUI1_Table_pickImage00);
   tolua_function(tolua_S,"show",tolua_MyUI1_Table_show00);
   tolua_variable(tolua_S,"tableSize",tolua_get_Table_tableSize,tolua_set_Table_tableSize);
   tolua_variable(tolua_S,"cellSize",tolua_get_Table_cellSize,tolua_set_Table_cellSize);
   tolua_variable(tolua_S,"nowTouchImage",tolua_get_Table_nowTouchImage_ptr,tolua_set_Table_nowTouchImage_ptr);
   tolua_function(tolua_S,"visit",tolua_MyUI1_Table_visit00);
   tolua_function(tolua_S,"doExchange",tolua_MyUI1_Table_doExchange00);
   tolua_function(tolua_S,"removeIndex",tolua_MyUI1_Table_removeIndex00);
   tolua_function(tolua_S,"draw",tolua_MyUI1_Table_draw00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ScrollView","ScrollView","Base",tolua_collect_ScrollView);
  #else
  tolua_cclass(tolua_S,"ScrollView","ScrollView","Base",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ScrollView");
   tolua_function(tolua_S,"create",tolua_MyUI1_ScrollView_create00);
   tolua_function(tolua_S,"init",tolua_MyUI1_ScrollView_init00);
   tolua_function(tolua_S,"add",tolua_MyUI1_ScrollView_add00);
   tolua_function(tolua_S,"visit",tolua_MyUI1_ScrollView_visit00);
   tolua_variable(tolua_S,"width",tolua_get_ScrollView_width,tolua_set_ScrollView_width);
   tolua_variable(tolua_S,"height",tolua_get_ScrollView_height,tolua_set_ScrollView_height);
   tolua_function(tolua_S,"new",tolua_MyUI1_ScrollView_new00);
   tolua_function(tolua_S,"new_local",tolua_MyUI1_ScrollView_new00_local);
   tolua_function(tolua_S,".call",tolua_MyUI1_ScrollView_new00_local);
   tolua_variable(tolua_S,"eachTap",tolua_get_ScrollView_eachTap,tolua_set_ScrollView_eachTap);
   tolua_constant(tolua_S,"UP_DOWN",ScrollView::UP_DOWN);
   tolua_constant(tolua_S,"LEFT_RIGHT",ScrollView::LEFT_RIGHT);
   tolua_constant(tolua_S,"ALL",ScrollView::ALL);
   tolua_variable(tolua_S,"scrollType",tolua_get_ScrollView_scrollType,tolua_set_ScrollView_scrollType);
   tolua_function(tolua_S,"setEachTap",tolua_MyUI1_ScrollView_setEachTap00);
   tolua_function(tolua_S,"setScrollType",tolua_MyUI1_ScrollView_setScrollType00);
   tolua_variable(tolua_S,"child",tolua_get_ScrollView_child_ptr,tolua_set_ScrollView_child_ptr);
   tolua_function(tolua_S,"checkIn",tolua_MyUI1_ScrollView_checkIn00);
   tolua_function(tolua_S,"doTouch",tolua_MyUI1_ScrollView_doTouch00);
   tolua_function(tolua_S,"draw",tolua_MyUI1_ScrollView_draw00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Panel","Panel","Image",NULL);
  tolua_beginmodule(tolua_S,"Panel");
   tolua_function(tolua_S,"create",tolua_MyUI1_Panel_create00);
   tolua_variable(tolua_S,"uis",tolua_get_Panel_uis,tolua_set_Panel_uis);
   tolua_variable(tolua_S,"actives",tolua_get_Panel_actives,tolua_set_Panel_actives);
   tolua_variable(tolua_S,"firsts",tolua_get_Panel_firsts,tolua_set_Panel_firsts);
   tolua_function(tolua_S,"attachTouch",tolua_MyUI1_Panel_attachTouch00);
   tolua_function(tolua_S,"addUI",tolua_MyUI1_Panel_addUI00);
   tolua_function(tolua_S,"visit",tolua_MyUI1_Panel_visit00);
   tolua_function(tolua_S,"setLocation",tolua_MyUI1_Panel_setLocation00);
   tolua_function(tolua_S,"setSize",tolua_MyUI1_Panel_setSize00);
   tolua_variable(tolua_S,"rect",tolua_get_Panel_rect,tolua_set_Panel_rect);
   tolua_function(tolua_S,"getSize",tolua_MyUI1_Panel_getSize00);
   tolua_function(tolua_S,"getPoint",tolua_MyUI1_Panel_getPoint00);
   tolua_function(tolua_S,"checkIn",tolua_MyUI1_Panel_checkIn00);
   tolua_function(tolua_S,"draw",tolua_MyUI1_Panel_draw00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Window","Window","CCLayer",NULL);
  tolua_beginmodule(tolua_S,"Window");
   tolua_function(tolua_S,"create",tolua_MyUI1_Window_create00);
   tolua_function(tolua_S,"init",tolua_MyUI1_Window_init00);
   tolua_function(tolua_S,"ccTouchesBegan",tolua_MyUI1_Window_ccTouchesBegan00);
   tolua_function(tolua_S,"ccTouchesMoved",tolua_MyUI1_Window_ccTouchesMoved00);
   tolua_function(tolua_S,"ccTouchesEnded",tolua_MyUI1_Window_ccTouchesEnded00);
   tolua_function(tolua_S,"addUI",tolua_MyUI1_Window_addUI00);
   tolua_function(tolua_S,"visit",tolua_MyUI1_Window_visit00);
   tolua_function(tolua_S,"getWindowSize",tolua_MyUI1_Window_getWindowSize00);
   tolua_function(tolua_S,"getPoint",tolua_MyUI1_Window_getPoint00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_MyUI1 (lua_State* tolua_S) {
 return tolua_MyUI1_open(tolua_S);
};
#endif

