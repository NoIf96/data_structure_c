#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include"LinkList.h"

void intro();//介绍菜单

void Menu_StrList(LinkList &L);//准备菜单
void Menu_test(LinkList &L);//功能测试子菜单

void test_attribute(LinkList L, Link &p);//属性子菜单
void test_position(LinkList L, Link &p);//位置子菜单
void tset_insert(LinkList &L, Link &p);//插入子菜单
void test_delete(LinkList &L, Link &p);//删除子菜单
void test_reset(LinkList &L, Link &p);//重置子菜单

void data_status(LinkList L, Link p);//数据状况

void Border(int Length, int Wide,int x,int y,char A,char B);//边框构建函数  xy为起始坐标  AB为边框符号																
void Border_sub();//边框分栏线
void Border_tail();//菜单调用结尾函数

void Pos(int x, int y);//定位函数
void Posx(int &x, int y);//定位函数x自增

#endif