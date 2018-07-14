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
	printf("ʵ��9  ��ϣ��\n");
	Posx(++x, y);
	printf("һ��ʵ��Ŀ��\n");
	Posx(x, y);
	printf("  ����ʵ��Ŀ�������չ�ϣ����ص㣬��Ϥ��ϣ��\n");
	Posx(x, y);
	printf("  �Ĵ�����ASL�ļ��㡣\n");

	Posx(++x, y);
	printf("����ʵ������\n");
	Posx(x, y);
	printf("  ��֪һ������Ϊ 15 �Ĺؼ�������Ϊ \n");
	Posx(x, y);
	printf("  19��38��12��40��41��39��54��76��35��47��80,\n");
	Posx(x, y);
	printf("  14��9��44��60}\n");
	Posx(x, y);
	printf("   �ٰ�������̽�ⷨ����һ������Ϊ18�Ĺ�ϣ��\n");
	Posx(x, y);
	printf("   �ڰ�������ַ������һ������Ϊ18�Ĺ�ϣ��\n");
	
	Posx(x, y);
	printf("   �۷ֱ������������ϣ���ASL��\n");

	++x;
	Posx(++x, 68);
	printf("�س���ʼ\n");
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
		printf("1.����̽�ⷨ               2.��ʽ��ַ��               3.�˳�");
		Table_line(3, 26, 66, '-');
		Pos(4, 28);
		printf("��ѡ���ܣ�1-3����");
		scanf_s("%d", &sele);


		switch (sele)
		{
		case 1:
			
			InitHash(H);
			CreatHash(H,C);
			HashTraverse(H, PrintKey,C);
			DestoryHash(H);
			C = 0;
			printf("\n�س������");
			getchar();
			getchar();
			break;

		case 2:
			CreatHashList(HL,n);
			HashTraverseList(HL, PrintKey, n);
			DestoryHashList(HL,n);
			printf("\n�س������");
			getchar();
			getchar();
			break;

		
		case 3:
			
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

	} while (sele != 3);

}