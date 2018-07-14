#pragma once
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include"SqQueue_oper.h"
#include"tool_base.h"

void intro();//介绍菜单
void Menu_pre();//准备菜单
void Menu_test();//测试菜单
void Test_StrStack(SqQueue &Q);//构造菜单
void Test_oper(SqQueue &Q);//操作菜单
void Data_State(SqQueue Q, int x);//状态栏


#endif