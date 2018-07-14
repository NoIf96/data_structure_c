#include<stdio.h>
#include<stdlib.h>


#include"tool_base.h"
#include"Menu.h"
#include"LinkList_operation.h"
#include"Polynomial_operation.h"

//介绍菜单
void intro() {
	int x = 5;

	Table_border(3, 25, 60, 15, '*', '|');
	Posx(x, 42);
	printf("实验3 一元多项式加法的实现\n");
	Posx(++x, 26);
	printf("一、实验目的\n");
	Posx(x, 26);
	printf(" 1.掌握使用VC++上机调试线性表的基本方法；\n");
	Posx(x, 26);
	printf(" 2.掌握一元多项式加法的实现。\n");
	
	Posx(++x, 26);
	printf("二、实验内容\n");
	Posx(x, 26);
	printf(" 完成2个一元多项式的加法\n");
	Posx(x, 26);
	printf(" 必须输入不少于两组数据进行测试。");

	++x;
	Posx(++x, 73);
	printf("回车后开始\n");
	getchar();
	system("cls");
}

void Menu_StrList() {
	int sele;

	do {
		polynomial A;
		polynomial B;

		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("一元多项式");
		Table_lines(3, 26, 58, '-', 3, 2);
		Pos(4, 28);
		printf("1.加法          2.减法          3.乘法          4.退出\n");
		 
		Pos(6, 28);
		printf("请选择功能（1-4）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Menu_Cre(A, B);
			Menu_Add(A, B);
			
			break;

		case 2:
			Menu_Cre(A, B);
			Menu_Sub(A, B);

			break;

		case 3:
			Menu_Cre(A, B);
			Menu_Mul(A, B);

			break;

		case 4:
			DestroyPolyn(A);
			Table_tail(18, 26, 58, '-');
			break;

		default:
			break;
		}



	} while (sele != 4);

}

void Menu_Cre(polynomial &A, polynomial &B) {
	int ma, mb;

	system("cls");
	InitList(A);
	InitList(B);

	printf("请输入一元多项式A的项数：");
	scanf_s("%d", &ma);
	CreatPolyn(A, ma);
	printf("\n\n回车后继续");
	getchar();
	getchar();

	system("cls");

	printf("请输入一元多项式B的项数：");
	scanf_s("%d", &mb);
	CreatPolyn(B, mb);
	printf("\n\n回车后继续");
	getchar();
	getchar();
	system("cls");
}

void Menu_Add(polynomial &A, polynomial &B) {
	Table_border(1, 25, 60, 20, '*', '|');

	Pos(2, 53);
	printf("加法");
	Table_line(3, 26, 58, '-');
	Pos(4, 26);
	printf("A：");
	PrintPolyn(A);
	Pos(5, 26);
	printf("B：");
	PrintPolyn(B);
	Pos(7, 26);
	printf("A + B：");
	AddPolyn(A, B);
	PrintPolyn(A);

	
	
	Table_tail(18, 26, 58, '-');
}
void Menu_Sub(polynomial &A, polynomial &B) {
	Table_border(1, 25, 60, 20, '*', '|');

	Pos(2, 53);
	printf("减法");
	Table_line(3, 26, 58, '-');
	Pos(4, 26);
	printf("A：");
	PrintPolyn(A);
	Pos(5, 26);
	printf("B：");
	PrintPolyn(B);
	Pos(7, 26);
	printf("A - B：");
	SubtractPolyn(A, B);
	PrintPolyn(A);

	

	Table_tail(18, 26, 58, '-');

}
void Menu_Mul(polynomial &A, polynomial &B) {
	Table_border(1, 25, 60, 20, '*', '|');

	Pos(2, 53);
	printf("乘法");
	Table_line(3, 26, 58, '-');
	Pos(4, 26);
	printf("A：");
	PrintPolyn(A);
	Pos(5, 26);
	printf("B：");
	PrintPolyn(B);
	Pos(7, 26);
	printf("A * B：");
	MultiplyPolyn(A, B);
	PrintPolyn(A);

	Table_tail(18, 26, 58, '-');
}