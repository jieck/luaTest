#include "luaUI.h"

int openUILib(lua_State* L) {
	luaL_newmetatable(L, "Widget");
	lua_pushvalue(L, -1);
	lua_setfield(L, -1, "__index"); // widget.__index = widget
	
	luaL_setfuncs(L, regWidgetMethods, 0); // ����Ԫ��ķ���
	luaL_newlib(L, regUIMethods); // �����������������õ�������ȫ��ģ��UI��
	return 1;
}

int luaCreateWidget(lua_State* L) {
	Widget** ppWidget = (Widget**)lua_newuserdata(L, sizeof(Widget*));
	*ppWidget = new Widget();
	// todo ����Ԫ��
	luaL_getmetatable(L, "Widget");
	lua_setmetatable(L, -2); //����ջ��Ԫ�ز���������ΪppWidget��Ԫ��
	return 1;
}


int luaCreateWidgetWithIdAndType(lua_State* L) {
	Widget** ppWidget = (Widget**)lua_newuserdata(L, sizeof(Widget*));
	string id = lua_tostring(L, 1);
	string type = lua_tostring(L, 2);
	cout << "setid: " << id << " settype:" << type << endl;
	*ppWidget = new Widget(id, type);
	
	// todo ����Ԫ��
	luaL_getmetatable(L, "Widget");
	lua_setmetatable(L, -2); //����ջ��Ԫ�ز���������ΪppWidget��Ԫ��
	return 1;
}

int luaGetId(lua_State* L) {
	//Widget** ppWidget = (Widget**)lua_touserdata(L, 1);
	Widget** ppWidget = (Widget**)luaL_checkudata(L, 1, "Widget");
	//luaL_argcheck(L, ppWidget~= NULL, 1, "nullllllll widget");
	luaL_argcheck(L, ppWidget != NULL, 1, "222");
	lua_settop(L, 0);
	lua_pushstring(L, (*ppWidget)->getId().c_str());
	return 1;
}

int luaSetId(lua_State* L) {
	Widget** ppWidget = (Widget**)lua_touserdata(L, 1);
	string id = lua_tostring(L, 2);
	//Widget** ppWidget = (Widget**)luaL_checkudata(L, 1, "Widget");
	(*ppWidget)->setId(id);
	return 1;
}

int luaGetType(lua_State* L) {
	Widget** ppWidget = (Widget**)lua_touserdata(L, 1);
	//Widget** ppWidget = (Widget**)luaL_checkudata(L, 1, "Widget");
	lua_pushstring(L, (*ppWidget)->getType().c_str());
	return 1;
}

int luaSetType(lua_State* L) {
	Widget** ppWidget = (Widget**)lua_touserdata(L, 1);
	//Widget** ppWidget = (Widget**)luaL_checkudata(L, 1, "Widget");
	if (lua_isstring(L, 2)) {
		string type = lua_tostring(L, 2);
		(*ppWidget)->setType(type);
	}
	return 1;
}

int luaGc(lua_State* L) {
	Widget** ppWidget = (Widget**)lua_touserdata(L, 1);
	//string type = lua_tostring(L, 1);
	//Widget** ppWidget = (Widget**)luaL_checkudata(L, 1, "Widget");
	cout << "gc===========" << endl;
	delete (*ppWidget);
	return 1;
}
