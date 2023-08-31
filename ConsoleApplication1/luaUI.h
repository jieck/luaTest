#pragma once
#include "UI.h"
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
int luaCreateWidget(lua_State* L);
int luaCreateWidgetWithIdAndType(lua_State* L);

int luaSetId(lua_State* L);
int luaSetType(lua_State* L);
int luaGetId(lua_State* L);
int luaGetType(lua_State* L);

int luaGc(lua_State* L);

static const luaL_Reg regUIMethods[] = {
	{"createWidget", luaCreateWidget},
	{"createWidgetWithIdAndType",luaCreateWidgetWithIdAndType},
	{NULL, NULL},
};

static const luaL_Reg regWidgetMethods[] = {
	{"setId", luaSetId},
	{"getId", luaGetId},
	{"setType", luaSetType},
	{"getType", luaGetType},
	{"__gc", luaGc},
	{NULL, NULL},
};

// 负责创建原表，注册方法到原表，以及将创建方法引用到库里面
int openUILib(lua_State* L);