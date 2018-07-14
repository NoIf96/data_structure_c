#include<stdio.h>
#include<stdlib.h>

#include "Menu.h"
#include "SqQueue_oper.h"
#include "tool_base.h"

/*Table��Ϊ�߿򹤾ߺ���
 *
 *Pos��Ϊ��궨λ����
 *
 */

void intro()
{
	int x = 5;
	int y = 30;
	Table_border(3, y, 50, 18, '*', '|');
	y++;
	Posx(x, 44);
	printf("ʵ��5 ���е�ʵ��\n");
	Posx(++x, y);
	printf("һ��ʵ��Ŀ��\n");
	Posx(x, y);
	printf(" 1.����ʹ��VC++�ϻ�����ջ�Ļ���������\n");
	Posx(x, y);
	printf(" 2.�����˽���е����ԣ����ն��еĸ��ֻ���������\n");

	Posx(++x, y);
	printf("����ʵ������\n");
	Posx(x, y);
	printf(" 1.ѭ�����еĸ��ֻ���������������ʼ�������٣�\n");
	Posx(x, y);
	printf("   ���ӣ���ӣ�ȡ��ͷԪ�أ�����г��ȡ����ж�\n");
	Posx(x, y);
	printf("   �ա������ж������ȡ�����ÿ����������������\n");
	Posx(x, y);
	printf("   �벻�����������ݽ��в��ԡ�\n");
	Posx(x, y);
	printf(" 2.ʹ��ѭ������ʵ�����������ǵ��㷨��\n");

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
		
		Pos(4, 28);
		printf("  1.����              2.�������            3.����\n");

		

		Pos(6, 28);
		printf("��ѡ���ܣ�1-3����");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Menu_test();
			Table_tail(18, 26, 58, '-');
			break;

		case 2:
			Pos(8, 28);
			printf("�������������������");
			scanf_s("%d", &n);
			Table_tail(18, 26, 58, '-');
			system("cls");
			yanghui(n);
			printf("\n\n***��س��󷵻�***");
			getchar();
			
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

void Menu_test()
{
	int sele;
	SqQueue Q;
	InitQueue(Q);

	do {
		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("ѭ�����в���");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("1.����           2.����          3.����          4.����\n");

		Data_State(Q, 8);

		Pos(6, 28);
		printf("��ѡ���ܣ�1-4����");
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
				printf("�빹��ѭ������Q");
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
			printf("����ȷѡ��!!!");
			Table_tail(18, 26, 58, '-');
			break;
		}




	} while (sele != 4);


}

void Test_StrStack(SqQueue &Q)
{
	int n, m, x;
	QElemType e;

	

	//�����߿�
	Table_border(1, 25, 60, 25, '*', '|');
	Table_line(3, 26, 58, '-');


	//��ȡѭ�����У����ݸ���
	Pos(2, 26);
	printf("������ѭ�����У����ݸ�����");
	scanf_s("%d", &n);
	
	m = n + 6;
	Table_line(m, 26, 58, '-');
	//��ȡ���ݹ���ѭ�����У�
	x = 4;
	for (int i = 1;i <= n;i++) {
		Posx(x, 26);
		printf("��%d�����ݣ�", i);
		scanf_s("%d", &e);

		EnQueue(Q, e);
	}

	//��ӡѭ�����У�
	Pos(m + 2, 26);
	printf("ѭ�����Уѣ�");
	QueueTraverse(Q, visit);

	//�߿�β
	Table_tail(23, 26, 58, '-');
}

void Test_oper(SqQueue &Q) {
	int sele;
	QElemType e;

	do {
		Table_border(1, 25, 60, 20, '*', '|');

		Pos(2, 50);
		printf("ѭ������Q����");
		Table_lines(3, 26, 58, '-', 3, 2);
		Table_line(11, 26, 58, '-');
		Table_line(15, 26, 58, '-');
		Pos(4, 28);
		printf("  1.����               2.ɾ��             3.����\n");

		Data_State(Q, 12);

		Pos(6, 28);
		printf("��ѡ���ܣ�1-3����");
		scanf_s("%d", &sele);

		switch (sele)
		{
		case 1:
			Pos(8, 28);
			if (!Q.queuesize) {
				printf("�빹��ѭ������Q");
				Table_tail(18, 26, 58, '-');
				break;
			}
			printf("���������ֵ��");
			scanf_s("%d", &e);
			EnQueue(Q, e);

			break;

		case 2:
			Pos(8, 28);
			if (!Q.queuesize) {
				printf("�빹ѭ������Q");
				Table_tail(18, 26, 58, '-');
				break;
			}
			if (DeQueue(Q, e))
				printf("ɾ��Ԫ��Ϊ��%d", e);
			else
				printf("ѭ������QΪ��");

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


void Data_State(SqQueue Q, int x) {
	int length;

	Posx(x, 28);
	printf("��ǰ����״����\n");
	Posx(x, 27);
	if (Q.base) {
		if (QueueEmpty(Q))
			printf("ѭ������Q����");
		else {
			printf("ѭ������Q��");
			QueueTraverse(Q, visit);
			Pos(x, 27);
			printf("ѭ������Q���ȣ�");
			length = QueueLength(Q);
			printf("%d", length);

			Pos(16, 27);
			printf("��ͷ��");
			printf("%d", Q.base[Q.front]);
			Pos(17, 27);
			printf("��β��");
			printf("%d", Q.base[Q.rear-1]);
		}

	}

	else
		printf("ѭ������Q�����ڣ������٣�");
}