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
	printf("ʵ��6  ���������\n");
	Posx(++x, y);
	printf("һ��ʵ��Ŀ��\n");
	Posx(x, y);
	printf("     ����ʵ���Ŀ������Ϥ���ĸ��������ʾ���� \n");
	Posx(x, y);
	printf(" �����ֱ�����ʽ(�����Զ�����Ϊ���ص�)���˽���\n");
	Posx(x, y);
	printf(" �ڼ������ѧ�����������е�Ӧ�á�\n");

	Posx(++x, y);
	printf("����ʵ������\n");
	Posx(x, y);
	printf(" 1.�������Ľ�����\n");
	Posx(x, y);
	printf(" 2.������������� (�ݹ�ͷǵݹ���ʽ)��\n");
	Posx(x, y);
	printf(" 3.�����������Ľ����ͱ���\n");
	Posx(x, y);
	printf(" 4.�շ������ͺշ���������\n");
	++x;
	Posx(++x, 68);
	printf("�س���ʼ\n");
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
		printf("ѡ��");
		Table_lines(3, 26, 58, '-', 3, 2);

		Pos(4, 27);
		printf("1.������               2.����������               3.����\n");

		Pos(6, 28);
		printf("��ѡ���ܣ�1-3����");
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
			printf("����ȷѡ��!!!");
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
		printf("�������˵�");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("1.����                 2.����                3.����\n");

		Data_State_BiTree(T, 8);

		Pos(6, 28);
		printf("��ѡ���ܣ�1-3����");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Table_tail(18, 26, 58, '-');
			Table_border(1, 25, 60, 8, '-', '|');
			Pos(2, 28);
			printf("���������ݣ�ʵ����-+a##*b##-c##d##/e##f##��");
			Table_line(3, 26, 58, '-');
			Pos(4, 28);
			CreateBiTree(T);
			break;

		case 2:
			
			
			if (BiTreeEmpty(T)) {
				Pos(12, 46);
				printf("���ȹ��������");
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
			printf("����ȷѡ��!!!");
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
		printf("�������˵�");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("1.����          2.����         3.����          4.����\n");

		Data_State_BiTree(T, 8);

		Pos(6, 28);
		printf("��ѡ���ܣ�1-4����");
		scanf_s("%d", &sele);

		Pos(11, 30);
		switch (sele)
		{
		case 1:
			printf(" ����");
			PreOrderTraverse(T, PrintElement);
			Table_tail(18, 26, 58, '-');
			
			break;

		case 2:
			printf(" ����");
			InOrderTraverse(T, PrintElement);
			Table_tail(18, 26, 58, '-');
			
			break;

		case 3:
			printf(" ����");
			PostOrderTraverse(T, PrintElement);
			Table_tail(18, 26, 58, '-');
			
			break;

		case 4:
			Table_tail(18, 26, 58, '-');

			break;

		default:
			printf("����ȷѡ��!!!");
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
		printf("�����������˵�");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("1.����               2.��������              3.����\n");

		

		Pos(6, 28);
		printf("��ѡ���ܣ�1-3����");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Table_tail(18, 26, 58, '-');
			Table_border(1, 25, 60, 8, '-', '|');
			Pos(2, 28);
			printf("���������ݣ�ʵ����-+a##*b##-c##d##/e##f##��");
			Table_line(3, 26, 58, '-');
			Pos(4, 28);
			CreateBiThrTree(T);
			break;

		case 2:
			Pos(9, 30);
			printf(" ����");
			InOrderThreading(Thrt, T);
			InOrderTraveres_Thr(Thrt, PrintElement);
			Table_tail(18, 26, 58, '-');
			
			
			break;

		case 3:
			//Table_tail(18, 26, 58, '-');

			break;


		default:
			printf("����ȷѡ��!!!");
			Table_tail(18, 26, 58, '-');
			break;
		}




	} while (sele != 3);

	
}


void Data_State_BiTree(BiTree T, int x) {
	int depth;
	BiTPos p;

	Posx(x, 28);
	printf("��ǰ����״����\n");
	Posx(x, 27);
	
	if (BiTreeEmpty(T))
		printf(" ������T����");
	else {
	    printf(" ������T��");
		x += 3;
		Posx(x, 30);
	
		printf(" ����");
		p = Root(T);
		printf("%c", p->data);
		Pos(x - 1, 44);
		printf(" �ȣ�");
		BiTreeDepth(T,0,depth);
		printf("%d", depth);
				
		}

}


