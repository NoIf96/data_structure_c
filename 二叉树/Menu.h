#pragma once
#ifndef MENU_H_INCLUDE
#define MENU_H_INCLUDE

#include "Menu.h"
#include "BiTree_oper.h"
#include "tool_base.h"

/*Table��Ϊ�߿򹤾ߺ���
*
*Pos��Ϊ��궨λ����
*
*/

void intro();
void Menu_pre();//׼���˵�
void Menu_BiTree();//�������˵�
void Data_State_BiTree(BiTree T, int x);//������״̬��
void BiTree_oper(BiTree &T);//�����������˵�
void Menu_BiThrTree();


#endif