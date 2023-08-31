﻿// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <signal.h>
#include "luaUI.h"
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

static void* l_alloc(void* ud, void* ptr, size_t osize,
    size_t nsize) {
    (void)ud;  (void)osize;  /* not used */
    if (nsize == 0) {
        free(ptr);
        return NULL;
    }
    else
        return realloc(ptr, nsize);
}

double f(lua_State* L, double a, double b) {
    int isnum;
    double z;
    lua_getglobal(L, "sum");
    lua_pushnumber(L, a);
    lua_pushnumber(L, b);

    int luaError = lua_pcall(L, 2, 1, 0);
    if (luaError != LUA_OK) { return -1.0; };

    double sum = lua_tonumber(L, -1);
    lua_pop(L, 1);
    return sum;
};

double add(lua_State* L, double a, double b) {
    int isnum;
    double z;
    lua_getglobal(L, "add");
    lua_pushnumber(L, a);
    lua_pushnumber(L, b);

    int luaError = lua_pcall(L, 2, 1, 0);
    if (luaError != LUA_OK) { return -1.0; };

    double sum = lua_tonumber(L, -1);
    lua_pop(L, 1);
    return sum;
};

static int mul(lua_State* L) {
    double a = lua_tonumber(L, 1);
    double b = lua_tonumber(L, 2);
    lua_pushnumber(L, a * b);
    return 1;
}

int testCLua(lua_State* L) {
    lua_pushcfunction(L, mul);
    lua_setglobal(L, "mul");

    luaL_dofile(L, "G:\\lua_c\\ConsoleApplication1\\ConsoleApplication1\\test.lua"); // 偷下懒直接用绝对路径了
    // abort();
    //signal();
    int z = (int)nullptr;
    int i = 1 / z;
    printf("sum = %f\n", f(L, 1.2, 3.5));
    printf("add = %f", f(L, 1, 2));
    return 1;
}

int testCPPLua(lua_State* L) {
    // 注册模块
    luaL_requiref(L, "UI", openUILib, 1);


    luaL_dofile(L, "G:\\lua_c\\ConsoleApplication1\\ConsoleApplication1\\testCppLua.lua"); // 偷下懒直接用绝对路径了
    cout << "dd" << endl;
    return 1;
}

int main()
{

    lua_State* L = luaL_newstate();
    // luaL_dofile();
    luaL_openlibs(L);

    //testCLua(L); // 简单的C-Lua交互
    testCPPLua(L); // 面向对象的方式来使用lua
    //int* p = nullptr;
    //*p = 20;

    lua_close(L);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
