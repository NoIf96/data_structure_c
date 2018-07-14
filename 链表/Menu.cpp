#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"Menu.h"
#include"LinkList.h"

//���ܲ˵�
void intro() {
	int x = 5;

	Border(60, 18, 3, 25,'*','|');
	Posx(x, 38);
	printf("ʵ��2 ���Ա�����ʽ�洢�ṹ�µĻ�������\n");
	Posx(++x, 26);
	printf("һ��ʵ��Ŀ��\n");
	Posx(x, 26);
	printf(" 1.����ʹ��VC++�ϻ��������Ա�Ļ���������\n");
	Posx(x, 26);
	printf(" 2.�������Ա�Ļ������������롢ɾ�������ҵ�������\n");
	Posx(x, 26);
	printf(" ��ʽ�洢�ṹ�ϵ�ʵ�֡�\n");
	Posx(++x, 26);
	printf("����ʵ������\n");
	Posx(x, 26);
	printf(" 1.���Ա�����ʽ�洢�ṹ�µĻ���������\n");
	Posx(x, 26);
	printf(" 2.�ڴ˻�����ʵ��ͷ�巨��β�巨������������㷨��\n");
	Posx(x, 26);
	printf(" 3.����ÿ��������Ļ��������ʹ����������㷨��\n");
	Posx(x, 26);
	printf("   ���������벻�����������ݽ��в��ԡ�");
	
	++x;
	Posx(++x, 73);
	printf("�س���ʼ\n");
	getchar();
	system("cls");
}

//׼���˵�
void Menu_StrList(LinkList &L) {
	Link p;
	ElemType e;
	int sele,n;

	do {
		Border(50, 20, 0, 30, '*', '|');
		Pos(1, 48);
		printf("��ʼ������������\n");
		Pos(2, 31);
		printf(" ----------------------------------------------\n");
		Pos(3, 38);
		printf("1.ͷ�巨      2.β�巨      3.�˳�\n");
		Pos(4, 31);
		printf(" ----------------------------------------------\n");
		Pos(5, 32);
		printf("��ѡ���ܣ�1-3����");
		scanf_s("%d", &sele);
		Pos(6, 31);
		printf(" ----------------------------------------------\n");

		switch (sele)
		{
			//ͷ�巨
		case 1:
			Pos(7, 32);
			printf("������Ҫ����Ԫ��������");
			scanf_s("%d", &n);

			Pos(8, 32);
			printf("L:");
			for (int i = 1;i <= n;i++) {
				scanf_s("%d", &e);
				MakeNode(p, e);
				InsFirst(L,L.head, p);
			}

			Pos(17, 31);
			printf(" ------------------�س������------------------ \n");
			getchar();
			getchar();
			system("cls");
			Menu_test(L);
			
			break;

			//β�巨
		case 2:
			Pos(7, 32);
			printf("������Ҫ����Ԫ��������");
			scanf_s("%d", &n);

			Pos(8, 32);
			printf("L:");
			for (int i = 1;i <= 5;i++) {
				scanf_s("%d", &e);
				MakeNode(p, e);
				Append(L, p);
			}

			Pos(17, 31);
			printf(" ------------------�س������------------------ \n");
			getchar();
			getchar();
			system("cls");
			Menu_test(L);

			break;

			//�˳�
		case 3:
			e = 0;
			MakeNode(p, e);
			Append(L, p);

			Pos(11, 51);
			printf("�˳�����\n");
			Pos(17, 31);
			printf(" ------------------�س����˳�------------------ \n\n\n\n");

			break;

		default:
			Pos(11, 49);
			printf("����ȷѡ�񣡣���\n");
			Pos(17, 31);
			printf(" ------------------�س������------------------ \n");
			getchar();
			getchar();
			system("cls");

			break;
		}

	} while (sele != 3);

	
}

//���ܲ����Ӳ˵�
void Menu_test(LinkList &L) {
	Link p;
	int sele;
	p = NULL;

	do {
		Border(70, 20, 0, 20, '*', '|');     //�����߿�
		Border_sub();
		//�����˵�
		Pos(1, 54);       
		printf("����\n");
		Pos(3, 25);
		printf("1.����     2.λ��     3.����     4.ɾ��     5.����     6.����\n");
		
		data_status(L, p);

		Pos(5, 22);
		printf("��ѡ���ܣ�1-5����");                         //����ѡ��
		scanf_s("%d", &sele);                

		//����ѡ��ģ��
		switch (sele)
		{
			//����
		case 1:
			Border_tail();
			test_attribute(L, p);
			break;

			//λ��
		case 2:
			Border_tail();
			test_position(L, p);
			break;

			//����
		case 3:
			Border_tail();
			tset_insert(L, p);
			break;

			//ɾ��
		case 4:

			Border_tail();
			test_delete(L, p);
			break;

			//����
		case 5:
			Border_tail();
			test_reset(L, p);
			break;

			//����
		case 6:
			Pos(14, 51);
			printf("���ع���\n");
			

			Border_tail();

			break;

		default:
			Pos(14, 49);
			printf("����ȷѡ�񣡣���\n");
			

			Border_tail();

			break;
		}
	} while (sele != 6);
}

//�����Ӳ˵�
void test_attribute(LinkList L, Link &p) {
	int sele, length;
	ElemType e;

	do {
		Border(70, 20, 0, 20, '*', '|');
		Border_sub();

		Pos(1, 54);
		printf("����\n");
		Pos(3, 25);
		printf("1.�ռ��     2.Ԫ����      3.������      4.�޸���      5.����\n");

		data_status(L, p);

		Pos(5, 22);
		printf("��ѡ���ܣ�1-5����");
		scanf_s("%d", &sele);

		switch (sele)
		{
			//�ռ��
		case 1:
			Pos(12, 22);
			printf("����LinstElem\n");
			Pos(13, 22);
			if (ListEmpty(L))
				printf("LΪ�ձ�\n");
			else
				printf("L��Ϊ��\n");

			Border_tail();

			break;

			//Ԫ����
		case 2:
			Pos(12, 22);
			printf("����ListLength\n");
			Pos(13, 22);
			length = ListLength(L);
			printf("L����%d��Ԫ��\n", length);

			Border_tail();

			break;

			//������
		case 3:
			Pos(12, 22);
			printf("����GetCurElem\n");
			Pos(13, 22);
			if (p)
				printf("����ָ��p��ָ��Ԫ����%d\n",GetCurElem(p));
			else
				printf("����ָ��p�Ƿ�\n");

			Border_tail();

			break;

			//�޸���
		case 4:
			Pos(12, 22);
			printf("����SetCurElem\n");
			Pos(13, 22);
			if (p) {
				printf("������p��ָ��Ԫ����ֵ��");
				scanf_s("%d", &e);
				SetCurElem(p, e);
				printf("�޸���ϣ��ֹ���ָ��p��ָ��Ԫ����%d\n", GetCurElem(p));
			}
			else
				printf("����ָ��p�Ƿ�\n");
			Border_tail();

			break;

			//����
		case 5:
			
			Border_tail();
			
			break;

		default:
			Pos(14, 49);
			printf("����ȷѡ�񣡣���\n");
			
			Border_tail();

			break;
		}
	} while (sele != 5);

}
//λ���Ӳ˵�
void test_position(LinkList L, Link &p) {
	int sele, i;
	Position x;
	ElemType e;

	x = NULL;

	do {
		Border(70, 20, 0, 20, '*', '|');
		Border_sub();

		Pos(1, 54);
		printf("λ��\n");
		Pos(3, 25);
		printf("1.ͷ���     2.β���      3.i���      4.�ض����     5.����\n");
	
		data_status(L, p);

		Pos(5, 22);
		printf("��ѡ���ܣ�1-5����");
		scanf_s("%d", &sele);

		switch (sele)
		{
			//ͷ���
		case 1:
			Pos(12, 22);
			printf("����GetHead\n");
			Pos(13, 22);
			p = GetHead(L);
			printf("L��ͷ����ַ�Ը���p\n");
			
			Border_tail();

			break;

			//β���
		case 2:
			Pos(12, 22);
			printf("����GetLast\n");
			Pos(13, 22);
			p = GetLast(L);
			printf("L��β����ַ�Ը���p\n");

			Border_tail();

			break;

			//i���
		case 3:
			Pos(12, 22);
			printf("����LocatePos\n");
			Pos(13, 22);
			printf("�������ض�Ԫ��λ��");
			scanf_s("%d", &i);
			Pos(14, 22);
			if (LocatePos(L, i, p))
				printf("L���ض�Ԫ��λ�����ַ�Ը���p\n");
			else
				printf("����λ��Ƿ�\n");

			Border_tail();

			break;

			//�ض����
		case 4:
			Pos(12, 22);
			printf("����LocateElem\n");
			Pos(13, 22);
			printf("�������ض�Ԫ�أ�");
			scanf_s("%d", &e);
			Pos(14, 22);
			if (p = LocateElem(L, e, compare))
				printf("L���ض�Ԫ�ص�ַ�Ը���p\n");
			else
				printf("����Ԫ�ز�����\n");


			Border_tail();

			break;

			//����
		case 5:
		
			Border_tail();

			break;

		default:
			Pos(14, 49);
			printf("����ȷѡ�񣡣���\n");

			Border_tail();

			break;
		}
	} while (sele != 5);

}
//�����Ӳ˵�
void tset_insert(LinkList &L, Link &p) {
	int sele;
	Link q;
	ElemType e;

	do {
		Border(70, 20, 0, 20, '*', '|');
		Border_sub();

		Pos(1, 54);
		printf("����\n");
		Pos(3, 25);
		printf("1.ͷ�巨     2.β�巨      3.p���ǰ      4.p����     5.����\n");

		data_status(L, p);

		Pos(5, 22);
		printf("��ѡ���ܣ�1-5����");
		scanf_s("%d", &sele);

		switch (sele)
		{
			//ͷ�巨
		case 1:
			Pos(12, 22);
			printf("����InsFirst\n");
			Pos(13, 22);
			printf("����Ԫ�أ�");
			scanf_s("%d", &e);
			MakeNode(q, e);
			InsFirst(L, L.head, q);
			
			Border_tail();

			break;

			//β�巨
		case 2:
			Pos(12, 22);
			printf("����Append\n");
			Pos(13, 22);
			printf("����Ԫ�أ�");
			scanf_s("%d", &e);
			MakeNode(q, e);
			Append(L, q);

			Border_tail();

			break;

			//p���ǰ
		case 3:
			Pos(12, 22);
			printf("����InsBefore\n");
			Pos(13, 22);
			if (p)
			{
				printf("����Ԫ�أ�");
				scanf_s("%d", &e);
				MakeNode(q, e);
				InsBefore(L, p, q);
				Pos(14, 22);
				printf("����ɹ�\n");
			}
			else
				printf("�����ַ�Ƿ�\n");

			Border_tail();

			break;

			//p����
		case 4:
			Pos(12, 22);
			printf("����InsAfter\n");
			Pos(13, 22);
			if (p)
			{
				printf("����Ԫ�أ�");
				scanf_s("%d", &e);
				MakeNode(q, e);
				InsAfter(L, p, q);
				Pos(14, 22);
				printf("����ɹ�\n");
			}
			else
				printf("�����ַ�Ƿ�\n");


			Border_tail();

			break;

			//����
		case 5:

			Border_tail();

			break;

		default:
			Pos(14, 49);
			printf("����ȷѡ�񣡣���\n");

			Border_tail();

			break;
		}
	} while (sele != 5);

}
//ɾ���Ӳ˵�
void test_delete(LinkList &L, Link &p) {
	int sele;
	Link q;

	do {
		Border(70, 20, 0, 20, '*', '|');
		Border_sub();
		Pos(1, 54);
		printf("ɾ��\n");
		Pos(3, 25);
		printf("1.ɾ����һ�����      2.ɾ��β���      3.ɾ��p���      4.����\n");

		data_status(L, p);

		Pos(5, 22);
		printf("��ѡ���ܣ�1-4����");
		scanf_s("%d", &sele);

		switch (sele)
		{
			//ɾ����һ�����
		case 1:
			Pos(12, 22);
			printf("����DelFirst\n");
			Pos(13, 22);
			DelFirst(L, L.head, q);
			FreeNode(q);
			printf("ɾ���ɹ�\n");
			Border_tail();

			break;

			//ɾ��β���
		case 2:
			Pos(12, 22);
			printf("����Remove\n");
			Pos(13, 22);
			Remove(L, L.head);
			printf("ɾ���ɹ�\n");

			Border_tail();

			break;

			//ɾ��p���
		case 3:
			Pos(12, 22);
			printf("����Delp\n");
			Pos(13, 22);
			if (p)
			{
				Delp(L, p);
				printf("ɾ���ɹ�\n");
			}
			else
				printf("ɾ����ַ�Ƿ�\n");

			Border_tail();

			break;

			//����
		case 4:

			Border_tail();

			break;

		default:
			Pos(14, 49);
			printf("����ȷѡ�񣡣���\n");

			Border_tail();

			break;
		}
	} while (sele != 4);

}
//�����Ӳ˵�
void test_reset(LinkList &L, Link &p) {
	int sele;

	do {
		Border(70, 20, 0, 20, '*', '|');
		Border_sub();

		Pos(1, 54);
		printf("����\n");
		Pos(3, 25);
		printf("1.��������            2.���ù���ָ��p            3.����\n");

		data_status(L, p);

		Pos(5, 22);
		printf("��ѡ���ܣ�1-3����");
		scanf_s("%d", &sele);

		switch (sele)
		{
			//��������
		case 1:
			Pos(12, 22);
			printf("����ClearList\n");
			Pos(13, 22);
			ClearList(L);
			printf("�������\n");
			Border_tail();

			break;

			//���ù���ָ��p
		case 2:
			Pos(12, 22);
			p = NULL;
			printf("���óɹ�\n");

			Border_tail();

			break;

			//����
		case 3:

			Border_tail();

			break;

		default:
			Pos(14, 49);
			printf("����ȷѡ�񣡣���\n");

			Border_tail();

			break;
		}
	} while (sele != 3);
}

//����״��
void data_status(LinkList L, Link p) {
	ElemType pe;

	Pos(7, 22);
	printf("��ǰ����״����\n");
	Pos(9, 22);
	printf("��������L��");
	ListTraverse(L, visit);
	Pos(10, 22);
	printf("����ָ��p��");
	if (p) {
		if (p == L.head)
			printf("ͷ���");
		else {
			pe = GetCurElem(p);
			printf("%d", pe);
		}
	}
	else
		printf("NULL\n");
}

//�߿򹹽�����  xyΪ��ʼ����  ABΪ�߿����
void Border(int Length, int Wide,int x,int y,char A,char B) {
	int i, j, k;
	for (i = 0;i < Wide;i++) {
		//���к�β��
		Pos(x++, y);
		if (i == 0 || i == Wide - 1)
			for (k = 0;k < Length;k++)
				printf("%c",A);
		
		else {
			for (j = 0;j < Length;j++) {
				//�߽�
				if (j == 0 || j == Length - 1)
					printf("%c",B);
				else
				printf(" ");
			}
		}

		printf("\n");
	}


}

//�߿������
void Border_sub() {
	Pos(2, 21);
	printf(" ------------------------------------------------------------------\n");
	Pos(4, 21);
	printf(" ------------------------------------------------------------------\n");
	Pos(6, 21);
	printf(" ------------------------------------------------------------------\n");
	Pos(11, 21);
	printf(" ------------------------------------------------------------------\n");
}

//�˵����ý�β����
void Border_tail()
{
	Pos(17, 21);
	printf(" ----------------------------�س������---------------------------- \n");
	getchar();
	getchar();
	system("cls");
}

//��λ����
void Pos(int x, int y)
{

	HANDLE hout;
	COORD xy = { y,x };

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, xy);

}

//��λ����x����
void Posx(int &x, int y)
{

	HANDLE hout;
	COORD xy = { y,x };

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, xy);
	x++;

}
