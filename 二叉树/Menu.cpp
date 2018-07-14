#include <stdio.h>
#include <stdlib.h>

#include "Menu.h"

void intro()
{
	int x = 5;
	int y = 30;
	Table_border(3, y, 50, 18, '*', '|');
	y++;
	Posx(x, 44);
	printf("实验6  树与二叉树\n");
	Posx(++x, y);
	printf("一、实验目的\n");
	Posx(x, y);
	printf("     本次实验的目的是熟悉树的各种物理表示方法 \n");
	Posx(x, y);
	printf(" 及各种遍历方式(其中以二叉树为侧重点)，了解树\n");
	Posx(x, y);
	printf(" 在计算机科学及其他工程中的应用。\n");

	Posx(++x, y);
	printf("二、实验内容\n");
	Posx(x, y);
	printf(" 1.二叉树的建立。\n");
	Posx(x, y);
	printf(" 2.中序遍历二叉树 (递归和非递归形式)。\n");
	Posx(x, y);
	printf(" 3.线索二叉树的建立和遍历\n");
	Posx(x, y);
	printf(" 4.赫夫曼树和赫夫曼树编码\n");
	++x;
	Posx(++x, 68);
	printf("回车后开始\n");
	getchar();
	system("cls");
}

void Menu_pre()
{
	int sele, n;
	

	do {
		system("cls");
		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("选择");
		Table_lines(3, 26, 58, '-', 3, 2);

		Pos(4, 27);
		printf("1.二叉树               2.线索二叉树               3.返回\n");

		Pos(6, 28);
		printf("请选择功能（1-3）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Menu_BiTree();

			Table_tail(18, 26, 58, '-');
			break;

		case 2:
			Menu_BiThrTree();

			Table_tail(18, 26, 58, '-');
			
			break;

		case 3:

			Table_tail(18, 26, 58, '-');
			break;


		default:
			printf("请正确选择!!!");
			Table_tail(18, 26, 58, '-');
			break;
		}

	} while (sele != 3);

}

void Menu_BiTree()
{
	int sele;
	BiTree T;
	InitBiTree(T);
	

	do {
		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("二叉树菜单");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("1.构造                 2.操作                3.返回\n");

		Data_State_BiTree(T, 8);

		Pos(6, 28);
		printf("请选择功能（1-3）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Table_tail(18, 26, 58, '-');
			Table_border(1, 25, 60, 8, '-', '|');
			Pos(2, 28);
			printf("请输入数据（实例：-+a##*b##-c##d##/e##f##）");
			Table_line(3, 26, 58, '-');
			Pos(4, 28);
			CreateBiTree(T);
			break;

		case 2:
			
			
			if (BiTreeEmpty(T)) {
				Pos(12, 46);
				printf("请先构造二叉树");
				Table_tail(18, 26, 58, '-');
				
			}
			else {
				Table_tail(18, 26, 58, '-');
				BiTree_oper(T);
			}
			
			break;

		case 3:
			//Table_tail(18, 26, 58, '-');
			
			break;


		default:
			printf("请正确选择!!!");
			Table_tail(18, 26, 58, '-');
			break;
		}




	} while (sele != 3);

	DestoryBiTree(T);
}

void BiTree_oper(BiTree &T)
{
	int sele;

	do {
		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("二叉树菜单");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("1.先序          2.中序         3.后序          4.返回\n");

		Data_State_BiTree(T, 8);

		Pos(6, 28);
		printf("请选择功能（1-4）：");
		scanf_s("%d", &sele);

		Pos(11, 30);
		switch (sele)
		{
		case 1:
			printf(" 先序：");
			PreOrderTraverse(T, PrintElement);
			Table_tail(18, 26, 58, '-');
			
			break;

		case 2:
			printf(" 中序：");
			InOrderTraverse(T, PrintElement);
			Table_tail(18, 26, 58, '-');
			
			break;

		case 3:
			printf(" 后序：");
			PostOrderTraverse(T, PrintElement);
			Table_tail(18, 26, 58, '-');
			
			break;

		case 4:
			Table_tail(18, 26, 58, '-');

			break;

		default:
			printf("请正确选择!!!");
			Table_tail(18, 26, 58, '-');
			break;
		}




	} while (sele != 4);

}

void Menu_BiThrTree() {
	int sele;
	BiThrTree Thrt, T;
	

	do {
		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("线索二叉树菜单");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("1.构造               2.中序线索              3.返回\n");

		

		Pos(6, 28);
		printf("请选择功能（1-3）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Table_tail(18, 26, 58, '-');
			Table_border(1, 25, 60, 8, '-', '|');
			Pos(2, 28);
			printf("请输入数据（实例：-+a##*b##-c##d##/e##f##）");
			Table_line(3, 26, 58, '-');
			Pos(4, 28);
			CreateBiThrTree(T);
			break;

		case 2:
			Pos(9, 30);
			printf(" 中序：");
			InOrderThreading(Thrt, T);
			InOrderTraveres_Thr(Thrt, PrintElement);
			Table_tail(18, 26, 58, '-');
			
			
			break;

		case 3:
			//Table_tail(18, 26, 58, '-');

			break;


		default:
			printf("请正确选择!!!");
			Table_tail(18, 26, 58, '-');
			break;
		}




	} while (sele != 3);

	
}


void Data_State_BiTree(BiTree T, int x) {
	int depth;
	BiTPos p;

	Posx(x, 28);
	printf("当前数据状况：\n");
	Posx(x, 27);
	
	if (BiTreeEmpty(T))
		printf(" 二叉树T：空");
	else {
	    printf(" 二叉树T：");
		x += 3;
		Posx(x, 30);
	
		printf(" 根：");
		p = Root(T);
		printf("%c", p->data);
		Pos(x - 1, 44);
		printf(" 度：");
		BiTreeDepth(T,0,depth);
		printf("%d", depth);
				
		}

}


