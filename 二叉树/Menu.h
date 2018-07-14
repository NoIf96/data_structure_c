#pragma once
#ifndef MENU_H_INCLUDE
#define MENU_H_INCLUDE

#include "Menu.h"
#include "BiTree_oper.h"
#include "tool_base.h"

/*Table均为边框工具函数
*
*Pos均为光标定位函数
*
*/

void intro();
void Menu_pre();//准备菜单
void Menu_BiTree();//二叉树菜单
void Data_State_BiTree(BiTree T, int x);//二叉树状态栏
void BiTree_oper(BiTree &T);//二叉树操作菜单
void Menu_BiThrTree();


#endif