#include<stdio.h>
#include<stdlib.h>

#include "Menu.h"
#include "SqQueue_oper.h"
#include "tool_base.h"

/*Table均为边框工具函数
 *
 *Pos均为光标定位函数
 *
 */

void intro()
{
	int x = 5;
	int y = 30;
	Table_border(3, y, 50, 18, '*', '|');
	y++;
	Posx(x, 44);
	printf("实验5 队列的实现\n");
	Posx(++x, y);
	printf("一、实验目的\n");
	Posx(x, y);
	printf(" 1.掌握使用VC++上机调试栈的基本方法；\n");
	Posx(x, y);
	printf(" 2.深入了解队列的特性，掌握队列的各种基本操作。\n");

	Posx(++x, y);
	printf("二、实验内容\n");
	Posx(x, y);
	printf(" 1.循环队列的各种基本操作，包括初始化，销毁，\n");
	Posx(x, y);
	printf("   出队，入队，取队头元素，求队列长度、“判队\n");
	Posx(x, y);
	printf("   空”、“判队满”等。对于每个操作，都必须输\n");
	Posx(x, y);
	printf("   入不少于两组数据进行测试。\n");
	Posx(x, y);
	printf(" 2.使用循环队列实现输出杨辉三角的算法。\n");

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
		
		Pos(4, 28);
		printf("  1.测试              2.杨辉三角            3.返回\n");

		

		Pos(6, 28);
		printf("请选择功能（1-3）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Menu_test();
			Table_tail(18, 26, 58, '-');
			break;

		case 2:
			Pos(8, 28);
			printf("请输入杨辉三角行数：");
			scanf_s("%d", &n);
			Table_tail(18, 26, 58, '-');
			system("cls");
			yanghui(n);
			printf("\n\n***请回车后返回***");
			getchar();
			
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

void Menu_test()
{
	int sele;
	SqQueue Q;
	InitQueue(Q);

	do {
		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("循环队列测试");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("1.构造           2.重置          3.操作          4.返回\n");

		Data_State(Q, 8);

		Pos(6, 28);
		printf("请选择功能（1-4）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Table_tail(18, 26, 58, '-');
			Test_StrStack(Q);
			break;

		case 2:
			if (!Q.queuesize) {
				Pos(12, 48);
				printf("请构建循环队列Q");
				Table_tail(18, 26, 58, '-');
				break;
			}

			ClearQueue(Q);
			Table_tail(18, 26, 58, '-');
			break;

		case 3:
			Table_tail(18, 26, 58, '-');
			Test_oper(Q);
			break;

		case 4:
			if (Q.base)
				DestroyQueue(Q);
			
			break;

		default:
			printf("请正确选择!!!");
			Table_tail(18, 26, 58, '-');
			break;
		}




	} while (sele != 4);


}

void Test_StrStack(SqQueue &Q)
{
	int n, m, x;
	QElemType e;

	

	//构建边框
	Table_border(1, 25, 60, 25, '*', '|');
	Table_line(3, 26, 58, '-');


	//获取循环队列Ｑ数据个数
	Pos(2, 26);
	printf("请输入循环队列Ｑ数据个数：");
	scanf_s("%d", &n);
	
	m = n + 6;
	Table_line(m, 26, 58, '-');
	//获取数据构建循环队列Ｑ
	x = 4;
	for (int i = 1;i <= n;i++) {
		Posx(x, 26);
		printf("第%d个数据：", i);
		scanf_s("%d", &e);

		EnQueue(Q, e);
	}

	//打印循环队列Ｑ
	Pos(m + 2, 26);
	printf("循环队列Ｑ：");
	QueueTraverse(Q, visit);

	//边框尾
	Table_tail(23, 26, 58, '-');
}

void Test_oper(SqQueue &Q) {
	int sele;
	QElemType e;

	do {
		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("循环队列Q操作");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(11, 26, 58, '-');
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("  1.插入               2.删除             3.返回\n");

		Data_State(Q, 12);

		Pos(6, 28);
		printf("请选择功能（1-3）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Pos(8, 28);
			if (!Q.queuesize) {
				printf("请构建循环队列Q");
				Table_tail(18, 26, 58, '-');
				break;
			}
			printf("请输入插入值：");
			scanf_s("%d", &e);
			EnQueue(Q, e);

			break;

		case 2:
			Pos(8, 28);
			if (!Q.queuesize) {
				printf("请构循环队列Q");
				Table_tail(18, 26, 58, '-');
				break;
			}
			if (DeQueue(Q, e))
				printf("删除元素为：%d", e);
			else
				printf("循环队列Q为空");

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


void Data_State(SqQueue Q, int x) {
	int length;

	Posx(x, 28);
	printf("当前数据状况：\n");
	Posx(x, 27);
	if (Q.base) {
		if (QueueEmpty(Q))
			printf("循环队列Q：空");
		else {
			printf("循环队列Q：");
			QueueTraverse(Q, visit);
			Pos(x, 27);
			printf("循环队列Q长度：");
			length = QueueLength(Q);
			printf("%d", length);

			Pos(16, 27);
			printf("队头：");
			printf("%d", Q.base[Q.front]);
			Pos(17, 27);
			printf("队尾：");
			printf("%d", Q.base[Q.rear-1]);
		}

	}

	else
		printf("循环队列Q不存在（已销毁）");
}