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
	printf("��������{19 38 12 40 41 39 54 76 35 47 80 14 9 44 19}\n");
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
	printf("ʵ��10  �ڲ�����\n");
	Posx(++x, y);
	printf("һ��ʵ��Ŀ��\n");
	Posx(x, y);
	printf("  ʵ�ֶ�����������˽� ��\n");


	Posx(++x, y);
	printf("����ʵ������\n");
	Posx(x, y);
	printf("  ��֪һ������Ϊ 15 �����Ա���ؼ�������Ϊ \n");
	Posx(x, y);
	printf("  {19��38��12��40��41��39��54��76��35��47��80��\n");
	Posx(x, y);
	printf("  14��9��44��19}\n");
	Posx(x, y);
	printf("   �ٷֱ�ʹ���۰��������ð�����򡢶�����\n");
	Posx(x, y);
	printf("     ��2 - ·�鲢���������ùؼ�����������\n");
	Posx(x, y);
	printf("   �ڶ�ÿ�������㷨Ҫ�󲻽����������������,\n");
	Posx(x, y);
	printf("   �������ÿ�����������Ĺؼ������С�\n");
	Posx(x, y);
	printf("   �ۼ��㲢���ÿ�������������\n");
	Posx(x, y);
	printf("   �ܷ�����Щ�㷨���ȶ��ԡ�\n");

	++x;
	Posx(++x, 68);
	printf("�س���ʼ\n");
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
		printf("1.�۰��������   2.ð������   3.������   4.2-·�鲢����  5.�˳�");
		Table_line(3, 26, 66, '-');
		Pos(4, 28);
		printf("��ѡ���ܣ�1-5����");
		scanf_s("%d", &sele);

		
		switch (sele)
		{
		case 1:
			system("cls");
			printf("�۰��������\n");
			BInsertSort(L);
			printf("\n�س������");
			getchar();
			getchar();
			break;

		case 2:
			system("cls");
			printf("ð������\n");
			BubbleSort(L);
			printf("\n�س������");
			getchar();
			getchar();
			break;

		case 3:
			system("cls");
			printf("������\n");
			HeapSort(L);
			printf("\n�س������");
			getchar();
			getchar();
			break;

		case 4:
			system("cls");
			printf("2-·�鲢����\n");
			MergeSort(L);
			printf("\n�س������");
			getchar();
			getchar();
			break;

		case 5:
			printf("\n\n\n\n\n--------------bye--------------");
			printf("\n�س������");
			getchar();
			getchar();
			break;

		default:
			printf("\n\n\n����ȷѡ��\n");
			printf("\n�س������");
			getchar();
			getchar();
			break;
		}

	} while (sele != 5);

}