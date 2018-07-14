#include<stdio.h>
#include<stdlib.h>


#include"tool_base.h"
#include"SqStack_oper.h"
#include "Menu.h"


//介绍菜单
void intro() {
	int x = 5;
	int y = 30;
	Table_border(3, y, 50, 18, '*', '|');
	y++;
	Posx(x, 44);
	printf("实验4 顺序栈的实现\n");
	Posx(++x, y);
	printf("一、实验目的\n");
	Posx(x, y);
	printf(" 1.掌握使用VC++上机调试栈的基本方法；\n");
	Posx(x, y);
	printf(" 2. 深入了解栈的特性，掌握栈的各种基本操作。\n");

	Posx(++x, y);
	printf("二、实验内容\n");
	Posx(x, y);
	printf(" 1.栈在顺序存储结构下的各种基本操作,包括初始\n");
	Posx(x, y);
	printf("   化，销毁，入栈，出栈，取栈顶元素，求栈的长\n");
	Posx(x, y);
	printf("   度、“判空”等。对于每个操作，都必须输入不\n");
	Posx(x, y);
	printf("   少于两组数据进行测试。\n");
	Posx(x, y);
	printf(" 2.使用顺序栈实现表达式求值的算法。\n");

	++x;
	Posx(++x, 68);
	printf("回车后开始\n");
	getchar();
	system("cls");
}






//功能菜单
void Menu_test(SqStack &S) {
	int sele;
	S.top = S.base;

	do {
		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("顺序栈测试");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("1.构造           2.重置          3.操作          4.退出\n");

		Data_State(S,8);

		Pos(6, 28);
		printf("请选择功能（1-4）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Table_tail(18, 26, 58, '-');
			Test_StrStack(S);
			break;

		case 2:
			if (!S.stacksize) {
				Pos(12, 48);
				printf("请构建顺序栈S");
				Table_tail(18, 26, 58, '-');
				break;
			}

			ClearStack(S);
			Table_tail(18, 26, 58, '-');
			break;

		case 3:
			Table_tail(18, 26, 58, '-');
			Test_oper(S);
			break;

		case 4:
			if (S.base)
				DestroyStack(S);
			Table_tail(18, 26, 58, '-');
			break;

		default:
			printf("请正确选择!!!");
			Table_tail(18, 26, 58, '-');
			break;
		}




	} while (sele != 4);
}

//构造菜单
void Test_StrStack(SqStack &S)
{
	int n, m, x;
	SElemType e;

	if (!S.base) {
		/*SqStack A;
		S = A;*/
	}

	//为顺序栈分配空间
	InitStack(S);

	//构建边框
	Table_border(1, 25, 60, 25, '*', '|');
	Table_line(3, 26, 58, '-');


	//获取顺序栈数据个数
	Pos(2, 26);
	printf("请输入顺序栈数据个数：");
	scanf_s("%d", &n);

	m = n + 6;
	Table_line(m, 26, 58, '-');
	//获取数据构建顺序栈
	x = 4;
	for (int i = 1;i <= n;i++) {
		Posx(x, 26);
		printf("第%d个数据：", i);
		scanf_s("%d", &e);

		Push(S, e);
	}

	//打印顺序栈S
	Pos(m + 2, 26);
	printf("顺序栈S：");
	StackTraverse(S, visit);

	//边框尾
	Table_tail(23, 26, 58, '-');
}

//属性菜单
void Test_oper(SqStack &S) {
	int sele;
	SElemType e;

	do {
		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("顺序栈操作");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(11, 26, 58, '-');
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("  1.插入               2.删除             3.返回\n");

		Data_State(S,12);

		Pos(6, 28);
		printf("请选择功能（1-3）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Pos(8, 28);
			if (!S.stacksize) {
				printf("请构建顺序栈S");
				Table_tail(18, 26, 58, '-');
				break;
			}
			printf("请输入插入值：");
			scanf_s("%d", &e);
			Push(S, e);

			break;

		case 2:
			Pos(8, 28);
			if (!S.stacksize) {
				printf("请构建顺序栈S");
				Table_tail(18, 26, 58, '-');
				break;
			}
			if (Pop(S, e))
				printf("删除元素为：%d", e);
			else
				printf("顺序栈S为空");

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

void Data_State(SqStack S,int x) {
	int length;

	Posx(x, 28);
	printf("当前数据状况：\n");
	Posx(x, 27);
	if (S.base) {
		if (StackEmpty(S))
			printf("顺序栈S：空");
		else {
			printf("顺序栈S：");
			StackTraverse(S, visit);
			Pos(x, 27);
			printf("顺序栈长度：");
			length = StackLength(S);
			printf("%d", length);

			Pos(16, 27);
			printf("栈底：");
			printf("%d", *S.base);
			Pos(17, 27);
			printf("栈顶：");
			printf("%d", *--S.top);
		}
		
	}

	else
		printf("顺序栈S不存在（已销毁）");
}