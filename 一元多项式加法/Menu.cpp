#include<stdio.h>
#include<stdlib.h>


#include"tool_base.h"
#include"Menu.h"
#include"LinkList_operation.h"
#include"Polynomial_operation.h"

//���ܲ˵�
void intro() {
	int x = 5;

	Table_border(3, 25, 60, 15, '*', '|');
	Posx(x, 42);
	printf("ʵ��3 һԪ����ʽ�ӷ���ʵ��\n");
	Posx(++x, 26);
	printf("һ��ʵ��Ŀ��\n");
	Posx(x, 26);
	printf(" 1.����ʹ��VC++�ϻ��������Ա�Ļ���������\n");
	Posx(x, 26);
	printf(" 2.����һԪ����ʽ�ӷ���ʵ�֡�\n");
	
	Posx(++x, 26);
	printf("����ʵ������\n");
	Posx(x, 26);
	printf(" ���2��һԪ����ʽ�ļӷ�\n");
	Posx(x, 26);
	printf(" �������벻�����������ݽ��в��ԡ�");

	++x;
	Posx(++x, 73);
	printf("�س���ʼ\n");
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
		printf("һԪ����ʽ");
		Table_lines(3, 26, 58, '-', 3, 2);
		Pos(4, 28);
		printf("1.�ӷ�          2.����          3.�˷�          4.�˳�\n");
		 
		Pos(6, 28);
		printf("��ѡ���ܣ�1-4����");
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

	printf("������һԪ����ʽA��������");
	scanf_s("%d", &ma);
	CreatPolyn(A, ma);
	printf("\n\n�س������");
	getchar();
	getchar();

	system("cls");

	printf("������һԪ����ʽB��������");
	scanf_s("%d", &mb);
	CreatPolyn(B, mb);
	printf("\n\n�س������");
	getchar();
	getchar();
	system("cls");
}

void Menu_Add(polynomial &A, polynomial &B) {
	Table_border(1, 25, 60, 20, '*', '|');

	Pos(2, 53);
	printf("�ӷ�");
	Table_line(3, 26, 58, '-');
	Pos(4, 26);
	printf("A��");
	PrintPolyn(A);
	Pos(5, 26);
	printf("B��");
	PrintPolyn(B);
	Pos(7, 26);
	printf("A + B��");
	AddPolyn(A, B);
	PrintPolyn(A);

	
	
	Table_tail(18, 26, 58, '-');
}
void Menu_Sub(polynomial &A, polynomial &B) {
	Table_border(1, 25, 60, 20, '*', '|');

	Pos(2, 53);
	printf("����");
	Table_line(3, 26, 58, '-');
	Pos(4, 26);
	printf("A��");
	PrintPolyn(A);
	Pos(5, 26);
	printf("B��");
	PrintPolyn(B);
	Pos(7, 26);
	printf("A - B��");
	SubtractPolyn(A, B);
	PrintPolyn(A);

	

	Table_tail(18, 26, 58, '-');

}
void Menu_Mul(polynomial &A, polynomial &B) {
	Table_border(1, 25, 60, 20, '*', '|');

	Pos(2, 53);
	printf("�˷�");
	Table_line(3, 26, 58, '-');
	Pos(4, 26);
	printf("A��");
	PrintPolyn(A);
	Pos(5, 26);
	printf("B��");
	PrintPolyn(B);
	Pos(7, 26);
	printf("A * B��");
	MultiplyPolyn(A, B);
	PrintPolyn(A);

	Table_tail(18, 26, 58, '-');
}