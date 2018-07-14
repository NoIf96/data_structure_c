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
	printf("ʵ��8  ����������\n");
	Posx(++x, y);
	printf("һ��ʵ��Ŀ��\n");
	Posx(x, y);
	printf("    ����ʵ��Ŀ�������ն������������ص㣬��Ϥ���\n");
	Posx(x, y);
	printf(" �����������ĸ��ֲ�����\n");

	Posx(++x, y);
	printf("����ʵ������\n");
	Posx(x, y);
	printf(" ��֪һ������Ϊ 15 �����Ա���ؼ�������Ϊ{19��\n");
	Posx(x, y);
	printf(" 38��12��40��41��39��54��76��35��47��80��14��9��\n");
	Posx(x, y);
	printf(" 44��60}�����ʵ�����¹��ܣ�\n");
	Posx(x, y);
	printf("     �ٰ���Ԫ�ص�˳����һ�ö���������\n");
	Posx(x, y);
	printf("     �������������������\n");
	Posx(x, y);
	printf("     ��ɾ�� 54\n");
	Posx(x, y);
	printf("     �������������������\n");
	Posx(x, y);
	printf("     �����ٶ���������\n");
	++x;
	Posx(++x, 68);
	printf("�س���ʼ\n");
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
		printf("ѡ��");
		Table_lines(3, 26, 58, '-', 3, 2);

		Pos(4, 28);
		printf("1.����           2.����         3.ɾ��         4.����\n");

		Pos(8, 26);
		printf("��ǰ����״��:");
		Pos(9, 28);
		if (T)
			InOrderTraverse(T, PrintElement);
		else
			printf("��");

		Pos(6, 28);
		printf("��ѡ���ܣ�1-4����");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Table_tail(18, 26, 58, '-');
			Table_border(1, 25, 70, 8, '-','|');
			Pos(2, 28);
			printf("����������{19 38 12 40 41 39 54 76 "
				                        "35 47 80 14 9 44 60}��");
			Table_line(3, 26, 68, '-');
			Pos(4, 28);
			printf("��¼������:");
			

			for (int i = 1; i <= 15;i++) {
				scanf_s("%d", &e.key);
				InsertBST(T, e);

			}

			Table_tail(6, 26, 68, '-');
			break;

		case 2:
			Pos(11, 28);
		
			printf("�����������ؼ��֣�");
			scanf_s("%d", &e.key);
			InsertBST(T, e);

			Table_tail(18, 26, 58, '-');

			break;

		case 3:
			Pos(11, 28);
			printf("������ɾ�����ؼ��֣�");
			scanf_s("%d", &e.key);
			Pos(12, 28);
			if (DeleteBST(T,e.key))
				printf("�����ɾ��");
			else
				printf("ɾ����㲻����");
			Table_tail(18, 26, 58, '-');
			break;

		case 4:

			Table_tail(18, 26, 58, '-');
			break;

		default:
			Pos(15, 28);
			printf("����ȷѡ��!!!");
			Table_tail(18, 26, 58, '-');
			break;
		}

	} while (sele != 4);

	DestoryBSTree(T);
}
