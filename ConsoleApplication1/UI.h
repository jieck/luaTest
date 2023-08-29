#pragma once
#include <iostream>
#include <string>
using namespace std;
enum WidgetType
{
	widget,
	button,
	label,
};
class Widget {
public:
	Widget();
	Widget(string id, string type);
	~Widget();

	string getId();
	void setId(string id);

	string getType();
private:
	string _id;
	string _type;
};