require "UI"

print("11111111111111111");
local oWidget = UI.createWidget();

print("oWidget GetType:"..oWidget:getType());
oWidget:setType("ccjWidget");
print("oWidget GetType1:" .. oWidget:getType());

oWidget = UI.createWidgetWithIdAndType("ccj1", "cutomType");
collectgarbage("collect")
print(oWidget:getType());
print(oWidget:getId());
oWidget:setType("ccjWidget");
print(oWidget:getType());
