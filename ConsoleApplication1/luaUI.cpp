#include "luaUI.h"
int luaCreateWidget(lua_State* L) {
	Widget** ppWidget = (Widget**)lua_newuserdata(L, sizeof(Widget*));
	*ppWidget = new Widget();
	// todo ����Ԫ��
	return 1;
}