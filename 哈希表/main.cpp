#include<stdio.h>
#include<stdlib.h>
#include"HashTable_oper.h"
#include"tool_base.h"

void intro();
void Menu();

int main(void) {
	int n = 0;
	HashTable H;
	HashTableList HL[18];
	ElemType e;

	intro();
	Menu();
	
	printf("\n");

	return 0;

}

void intro()
{
	int x = 5;
	int y = 30;
	Table_border(3, y, 50, 19, '*', '|');
	y++;
	Posx(x, 44);
	printf("实验9  哈希表\n");
	Posx(++x, y);
	printf("一、实验目的\n");
	Posx(x, y);
	printf("  本次实验目的是掌握哈希表的特点，熟悉哈希表\n");
	Posx(x, y);
	printf("  的创建及ASL的计算。\n");

	Posx(++x, y);
	printf("二、实验内容\n");
	Posx(x, y);
	printf("  已知一个长度为 15 的关键字序列为 \n");
	Posx(x, y);
	printf("  19，38，12，40，41，39，54，76，35，47，80,\n");
	Posx(x, y);
	printf("  14，9，44，60}\n");
	Posx(x, y);
	printf("   ①按照线性探测法创建一个长度为18的哈希表。\n");
	Posx(x, y);
	printf("   ②按照链地址法创建一个长度为18的哈希表。\n");
	
	Posx(x, y);
	printf("   ③分别计算这两个哈希表的ASL。\n");

	++x;
	Posx(++x, 68);
	printf("回车后开始\n");
	getchar();
	system("cls");
}

void Menu()
{
	HashTable H;
	HashTableList HL[18];
	ElemType e;
	int sele,n = 0;
	double C = 0;

	do {
		system("cls");
		Table_border(1, 25, 68, 5, '*', '|');
		Pos(2, 28);
		printf("1.线性探测法               2.链式地址法               3.退出");
		Table_line(3, 26, 66, '-');
		Pos(4, 28);
		printf("请选择功能（1-3）：");
		scanf_s("%d", &sele);


		switch (sele)
		{
		case 1:
			
			InitHash(H);
			CreatHash(H,C);
			HashTraverse(H, PrintKey,C);
			DestoryHash(H);
			C = 0;
			printf("\n回车后继续");
			getchar();
			getchar();
			break;

		case 2:
			CreatHashList(HL,n);
			HashTraverseList(HL, PrintKey, n);
			DestoryHashList(HL,n);
			printf("\n回车后继续");
			getchar();
			getchar();
			break;

		
		case 3:
			
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

	} while (sele != 3);

}