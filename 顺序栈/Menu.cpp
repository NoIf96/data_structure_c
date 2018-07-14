#include<stdio.h>
#include<stdlib.h>


#include"tool_base.h"
#include"SqStack_oper.h"
#include "Menu.h"


//���ܲ˵�
void intro() {
	int x = 5;
	int y = 30;
	Table_border(3, y, 50, 18, '*', '|');
	y++;
	Posx(x, 44);
	printf("ʵ��4 ˳��ջ��ʵ��\n");
	Posx(++x, y);
	printf("һ��ʵ��Ŀ��\n");
	Posx(x, y);
	printf(" 1.����ʹ��VC++�ϻ�����ջ�Ļ���������\n");
	Posx(x, y);
	printf(" 2. �����˽�ջ�����ԣ�����ջ�ĸ��ֻ���������\n");

	Posx(++x, y);
	printf("����ʵ������\n");
	Posx(x, y);
	printf(" 1.ջ��˳��洢�ṹ�µĸ��ֻ�������,������ʼ\n");
	Posx(x, y);
	printf("   �������٣���ջ����ջ��ȡջ��Ԫ�أ���ջ�ĳ�\n");
	Posx(x, y);
	printf("   �ȡ����пա��ȡ�����ÿ�����������������벻\n");
	Posx(x, y);
	printf("   �����������ݽ��в��ԡ�\n");
	Posx(x, y);
	printf(" 2.ʹ��˳��ջʵ�ֱ��ʽ��ֵ���㷨��\n");

	++x;
	Posx(++x, 68);
	printf("�س���ʼ\n");
	getchar();
	system("cls");
}






//���ܲ˵�
void Menu_test(SqStack &S) {
	int sele;
	S.top = S.base;

	do {
		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("˳��ջ����");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("1.����           2.����          3.����          4.�˳�\n");

		Data_State(S,8);

		Pos(6, 28);
		printf("��ѡ���ܣ�1-4����");
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
				printf("�빹��˳��ջS");
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
			printf("����ȷѡ��!!!");
			Table_tail(18, 26, 58, '-');
			break;
		}




	} while (sele != 4);
}

//����˵�
void Test_StrStack(SqStack &S)
{
	int n, m, x;
	SElemType e;

	if (!S.base) {
		/*SqStack A;
		S = A;*/
	}

	//Ϊ˳��ջ����ռ�
	InitStack(S);

	//�����߿�
	Table_border(1, 25, 60, 25, '*', '|');
	Table_line(3, 26, 58, '-');


	//��ȡ˳��ջ���ݸ���
	Pos(2, 26);
	printf("������˳��ջ���ݸ�����");
	scanf_s("%d", &n);

	m = n + 6;
	Table_line(m, 26, 58, '-');
	//��ȡ���ݹ���˳��ջ
	x = 4;
	for (int i = 1;i <= n;i++) {
		Posx(x, 26);
		printf("��%d�����ݣ�", i);
		scanf_s("%d", &e);

		Push(S, e);
	}

	//��ӡ˳��ջS
	Pos(m + 2, 26);
	printf("˳��ջS��");
	StackTraverse(S, visit);

	//�߿�β
	Table_tail(23, 26, 58, '-');
}

//���Բ˵�
void Test_oper(SqStack &S) {
	int sele;
	SElemType e;

	do {
		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("˳��ջ����");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(11, 26, 58, '-');
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("  1.����               2.ɾ��             3.����\n");

		Data_State(S,12);

		Pos(6, 28);
		printf("��ѡ���ܣ�1-3����");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Pos(8, 28);
			if (!S.stacksize) {
				printf("�빹��˳��ջS");
				Table_tail(18, 26, 58, '-');
				break;
			}
			printf("���������ֵ��");
			scanf_s("%d", &e);
			Push(S, e);

			break;

		case 2:
			Pos(8, 28);
			if (!S.stacksize) {
				printf("�빹��˳��ջS");
				Table_tail(18, 26, 58, '-');
				break;
			}
			if (Pop(S, e))
				printf("ɾ��Ԫ��Ϊ��%d", e);
			else
				printf("˳��ջSΪ��");

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

void Data_State(SqStack S,int x) {
	int length;

	Posx(x, 28);
	printf("��ǰ����״����\n");
	Posx(x, 27);
	if (S.base) {
		if (StackEmpty(S))
			printf("˳��ջS����");
		else {
			printf("˳��ջS��");
			StackTraverse(S, visit);
			Pos(x, 27);
			printf("˳��ջ���ȣ�");
			length = StackLength(S);
			printf("%d", length);

			Pos(16, 27);
			printf("ջ�ף�");
			printf("%d", *S.base);
			Pos(17, 27);
			printf("ջ����");
			printf("%d", *--S.top);
		}
		
	}

	else
		printf("˳��ջS�����ڣ������٣�");
}