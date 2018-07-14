#include<stdio.h>
#include<stdlib.h>
#include "Menu.h"
#include "BST_oper.h"
#include "tool_base.h"

void intro()
{
	int x = 5;
	int y = 30;
	Table_border(3, y, 50, 21, '*', '|');
	y++;
	Posx(x, 44);
	printf("实验8  二叉排序树\n");
	Posx(++x, y);
	printf("一、实验目的\n");
	Posx(x, y);
	printf("    本次实验目的是掌握二叉排序树的特点，熟悉针对\n");
	Posx(x, y);
	printf(" 二叉排序树的各种操作。\n");

	Posx(++x, y);
	printf("二、实验内容\n");
	Posx(x, y);
	printf(" 已知一个长度为 15 的线性表，其关键字序列为{19，\n");
	Posx(x, y);
	printf(" 38，12，40，41，39，54，76，35，47，80，14，9，\n");
	Posx(x, y);
	printf(" 44，60}，编程实现如下功能：\n");
	Posx(x, y);
	printf("     ①按各元素的顺序构造一棵二叉排序树\n");
	Posx(x, y);
	printf("     ②中序遍历二叉排序树\n");
	Posx(x, y);
	printf("     ③删除 54\n");
	Posx(x, y);
	printf("     ④中序遍历二叉排序树\n");
	Posx(x, y);
	printf("     ⑤销毁二叉排序树\n");
	++x;
	Posx(++x, 68);
	printf("回车后开始\n");
	getchar();
	system("cls");
}

void Menu_pre()
{
	int sele;
	BSTree T;
	ElemType e;

	T = NULL;
	e.datachar = '0';
	e.dataint = 0;

	do {
		system("cls");
		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("选择");
		Table_lines(3, 26, 58, '-', 3, 2);

		Pos(4, 28);
		printf("1.构造           2.插入         3.删除         4.返回\n");

		Pos(8, 26);
		printf("当前数据状况:");
		Pos(9, 28);
		if (T)
			InOrderTraverse(T, PrintElement);
		else
			printf("空");

		Pos(6, 28);
		printf("请选择功能（1-4）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Table_tail(18, 26, 58, '-');
			Table_border(1, 25, 70, 8, '-','|');
			Pos(2, 28);
			printf("（测试数据{19 38 12 40 41 39 54 76 "
				                        "35 47 80 14 9 44 60}）");
			Table_line(3, 26, 68, '-');
			Pos(4, 28);
			printf("请录入数据:");
			

			for (int i = 1; i <= 15;i++) {
				scanf_s("%d", &e.key);
				InsertBST(T, e);

			}

			Table_tail(6, 26, 68, '-');
			break;

		case 2:
			Pos(11, 28);
		
			printf("请输入插入结点关键字：");
			scanf_s("%d", &e.key);
			InsertBST(T, e);

			Table_tail(18, 26, 58, '-');

			break;

		case 3:
			Pos(11, 28);
			printf("请输入删除结点关键字：");
			scanf_s("%d", &e.key);
			Pos(12, 28);
			if (DeleteBST(T,e.key))
				printf("结点以删除");
			else
				printf("删除结点不存在");
			Table_tail(18, 26, 58, '-');
			break;

		case 4:

			Table_tail(18, 26, 58, '-');
			break;

		default:
			Pos(15, 28);
			printf("请正确选择!!!");
			Table_tail(18, 26, 58, '-');
			break;
		}

	} while (sele != 4);

	DestoryBSTree(T);
}
