#include "UI.h"


Widget::Widget() :_id("--"), _type("widget") {
	cout << "Widget ctor" << endl;
};

Widget::Widget(string id, string type):_id(id), _type(type) {
	cout << "Widget ctor with id type" << endl;
};

Widget::~Widget() {
	cout << "~ Widget" << endl;
};

void Widget::setId(string id) {
	this->_id = id;
};

string Widget::getId() {
	return this->_id;
};


string Widget::getType() {
	return this->_type;
};


void Widget::setType(string type) {
	this->_type = type;
};

