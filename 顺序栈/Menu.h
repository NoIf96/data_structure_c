#pragma once
#pragma once
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "SqStack.h"

void intro();   //介绍菜单

void Menu_test(SqStack &S);//功能菜单
void Test_oper(SqStack &S);//操作子菜单
void Test_StrStack(SqStack &S);//构造				   

void Data_State(SqStack S,int x);// 数据状态


#endif
