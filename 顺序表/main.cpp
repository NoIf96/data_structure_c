#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"SqList.h"
void test_prepare(SqList &A, SqList &B, SqList &C);
void test_Ins(SqList &A);
void tese_Del(SqList &B);
void test_PN(SqList &A, SqList &B);
void test_LE_CL(SqList &C);
void test_multiterm(SqList &A, SqList &B, SqList &C);

int main(void) {
	// �����������
	SqList A, B, C;
	ElemType e;

	// ����˳���
	InitList(A);
	InitList(B);
	InitList(C);
	printf("˳���A,B,C��������ϣ��س������");
	getchar();
	system("cls");

	// ����
	test_prepare(A, B, C);
	system("cls");
	test_Ins(A);
	system("cls");
	tese_Del(B);
	system("cls");
	test_PN(A, B);
	system("cls");
	test_LE_CL(C);
	system("cls");
	test_multiterm(A, B, C);
	system("cls");

	DestoryList(A);
	DestoryList(B);
	DestoryList(C);
	printf("˳���������ϣ���������˳�����\n");

	return 0;
}


// ��ʼ����
void test_prepare(SqList &A, SqList &B, SqList &C) {
	ElemType e;

	printf("����׼����");
	printf("����A������5������\nA:");
	for (int i = 1;i <= 5;i++) {
		scanf_s("%d", &e);
		ListInsert(A, i, e);
	}
	printf("\n");
	printf("����B������5������\nB:");
	for (int i = 1;i <= 5;i++) {
		scanf_s("%d", &e);
		ListInsert(B, i, e);
	}
	printf("\n");
	printf("����C������5������\nC:");
	for (int i = 1;i <= 5;i++) {
		scanf_s("%d", &e);
		ListInsert(C, i, e);
	}
	printf("\n\n׼���������س���ʼ��һ����\n");
	
	getchar();
	getchar();
	
}

 
// ListInsert ����
void test_Ins(SqList &A) {
	ElemType e;
	int position;

	printf("ListInsert����:\n\n");
	printf("������һ����:");
	scanf_s("%d", &e);
	printf("\n��ѡ��Ҫ�����A��Ԫ��λ��:\n");
	printf("A:");
	ListTraverse(A, visit);
	scanf_s("%d", &position);
	if (ListInsert(A, position, e)) {
		printf("A:");
		ListTraverse(A, visit);
	}
	else
		printf("���Ԫ��λ�÷Ƿ�\n");

	printf("\n\nListInsert���ԣ��س���ʼ��һ����\n\n");
	getchar();
	getchar();
}


// ListDelete ����
void tese_Del(SqList &B) {
	ElemType e;
	int position;

	printf("ListDelete����:\n\n");
	printf("��ѡ��Ҫɾ����B��Ԫ��λ��:\n");
	printf("B:");
	ListTraverse(B, visit);
	scanf_s("%d", &position);
	if (ListDelete(B, position, e)) {
		printf("B:");
		ListTraverse(B, visit);
		printf("ɾ��Ԫ��:%d\n", e);
	}
	else
		printf("ɾ��Ԫ��λ�÷Ƿ�\n\n");

	printf("\n\nListDelete���Խ������س���ʼ��һ����\n\n");
	getchar();
	getchar();
}


// PriorElem �� NextElem ����
void test_PN(SqList &A, SqList &B) {
	ElemType e;
	ElemType *p = NULL;
	ElemType *q = NULL;

	printf("PriorElem & NextElem ����:\n\n");
	printf("A:");
	ListTraverse(A, visit);
	printf("B:");
	ListTraverse(B, visit);
	printf("\n��������Ҫǰ������Ԫ��(A):");
	scanf_s("%d", &e);
	if (PriorElem(A, e, p)) {
		printf("\nA��ǰ����");
		visit(p);
	}
	else
		printf("\n��������˳���A�в�����\n");
	printf("\n\n��������Ҫ�������Ԫ��(B):");
	scanf_s("%d", &e);
	if (NextElem(B, e, q)) {
		printf("\nB�ĺ�̣�");
		visit(q);
	}
	else
		printf("\n��������˳���B�в�����\n");

	printf("\n\nPriorElem & NextElem ���Խ������س���ʼ��һ����\n");
	getchar();
	getchar();
}


//ListEmpty,ClearList ����
void test_LE_CL(SqList &C) {
	printf("ListEmpty,ClearList ����:\n\n");
	printf("���˳���C�Ƿ�Ϊ��\n\n");
	if (ListEmpty(C))
		printf("C˳���Ϊ��\n\n");
	else
		printf("C˳���ǿ�\n\n");
	ClearList(C);
	getchar();
	printf("����ClearList()��,\n�ٴμ��˳���C�Ƿ�Ϊ��\n\n");
	if (ListEmpty(C))
		printf("C˳���Ϊ��\n\n");
	else
		printf("C˳���ǿ�\n\n");
	
	printf("\n\nListEmpty,ClearList���Խ������س���ʼ��һ����\n\n");
	getchar();
	
}


//�㷨2.7MergeList��ListRank, LocateElem��ListLength,GetElem ����
void test_multiterm(SqList &A, SqList &B, SqList &C) {
	ElemType e;
	int position, length_List;

	printf("�㷨2.7MergeList��ListRank��LocateElem��ListLength,GetElem ����:\n\n");
	printf("A:");
	ListTraverse(A, visit);
	printf("\n\nB:");
	ListTraverse(B, visit);
	ListRank(A);
	ListRank(B);
	MergeList(A, B, C);
	printf("\n\nC:");
	ListTraverse(C, visit);
	length_List = ListLength(C);
	printf("\n\n˳���C����Ϊ%d\n\n", length_List);
	printf("��ѡ����Ҫ��ȡ˳���C�����ݵ�λ��");
	scanf_s("%d", &position);
	GetElem(C, position, e);
	printf("\n˳���C��λ��%d������%d\n", position, e);

	printf("\n\n������ϣ��س����˳�����\n");
	getchar();
	getchar();
}
