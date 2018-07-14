#include<stdio.h>
#include<stdlib.h>
#include"SqList_sort.h"
#include"tool_base.h"

void intro();
void Menu(SqList L);

int main(void) {
	SqList L;
	L.length = 0;
	intro();
	Pos(8, 28);
	printf("测试数据{19 38 12 40 41 39 54 76 35 47 80 14 9 44 19}\n");
	Pos(10, 42);
	CreatSqList(L);
	Menu(L);

	printf("\n");
	
	
	
	

	printf("\n");
	return 0;
}

void intro()
{
	int x = 5;
	int y = 30;
	Table_border(3, y, 50, 21, '*', '|');
	y++;
	Posx(x, 44);
	printf("实验10  内部排序\n");
	Posx(++x, y);
	printf("一、实验目的\n");
	Posx(x, y);
	printf("  实现对排序的深入了解 。\n");


	Posx(++x, y);
	printf("二、实验内容\n");
	Posx(x, y);
	printf("  已知一个长度为 15 的线性表，其关键字序列为 \n");
	Posx(x, y);
	printf("  {19，38，12，40，41，39，54，76，35，47，80，\n");
	Posx(x, y);
	printf("  14，9，44，19}\n");
	Posx(x, y);
	printf("   ①分别使用折半插入排序、冒泡排序、堆排序\n");
	Posx(x, y);
	printf("     和2 - 路归并排序对这个该关键字序列排序。\n");
	Posx(x, y);
	printf("   ②对每种排序算法要求不仅输出最终有序序列,\n");
	Posx(x, y);
	printf("   还有输出每趟排序后产生的关键字序列。\n");
	Posx(x, y);
	printf("   ③计算并输出每种排序的趟数。\n");
	Posx(x, y);
	printf("   ④分析这些算法的稳定性。\n");

	++x;
	Posx(++x, 68);
	printf("回车后开始\n");
	getchar();
	system("cls");
}

void Menu(SqList L)
{
	int sele, n;


	do {
		system("cls");
		Table_border(1, 25, 68, 5, '*', '|');
		Pos(2, 28);
		printf("1.折半插入排序   2.冒泡排序   3.堆排序   4.2-路归并排序  5.退出");
		Table_line(3, 26, 66, '-');
		Pos(4, 28);
		printf("请选择功能（1-5）：");
		scanf_s("%d", &sele);

		
		switch (sele)
		{
		case 1:
			system("cls");
			printf("折半插入排序\n");
			BInsertSort(L);
			printf("\n回车后继续");
			getchar();
			getchar();
			break;

		case 2:
			system("cls");
			printf("冒泡排序\n");
			BubbleSort(L);
			printf("\n回车后继续");
			getchar();
			getchar();
			break;

		case 3:
			system("cls");
			printf("堆排序\n");
			HeapSort(L);
			printf("\n回车后继续");
			getchar();
			getchar();
			break;

		case 4:
			system("cls");
			printf("2-路归并排序\n");
			MergeSort(L);
			printf("\n回车后继续");
			getchar();
			getchar();
			break;

		case 5:
			printf("\n\n\n\n\n--------------bye--------------");
			printf("\n回车后继续");
			getchar();
			getchar();
			break;

		default:
			printf("\n\n\n请正确选择\n");
			printf("\n回车后继续");
			getchar();
			getchar();
			break;
		}

	} while (sele != 5);

}