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
	{"createWidget"},
	{"createWidgetWithIdAndType"},
	{NULL, NULL},
};

static const luaL_Reg regWidgetMethods[] = {
	{"setId", luaSetId},
	{"getId", luaGetId},
	{"setType", luaSetType},
	{"getType", luaGetType},
	{NULL, NULL},
};

int openUILib(lua_State* L);