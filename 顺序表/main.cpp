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
	// 所需变量定义
	SqList A, B, C;
	ElemType e;

	// 创建顺序表
	InitList(A);
	InitList(B);
	InitList(C);
	printf("顺序表A,B,C，构建完毕，回车后继续");
	getchar();
	system("cls");

	// 测试
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
	printf("顺序表销毁完毕，任意键后退出程序\n");

	return 0;
}


// 开始测试
void test_prepare(SqList &A, SqList &B, SqList &C) {
	ElemType e;

	printf("测试准备：");
	printf("请往A表输入5个数：\nA:");
	for (int i = 1;i <= 5;i++) {
		scanf_s("%d", &e);
		ListInsert(A, i, e);
	}
	printf("\n");
	printf("请往B表输入5个数：\nB:");
	for (int i = 1;i <= 5;i++) {
		scanf_s("%d", &e);
		ListInsert(B, i, e);
	}
	printf("\n");
	printf("请往C表输入5个数：\nC:");
	for (int i = 1;i <= 5;i++) {
		scanf_s("%d", &e);
		ListInsert(C, i, e);
	}
	printf("\n\n准备结束，回车后开始下一测试\n");
	
	getchar();
	getchar();
	
}

 
// ListInsert 测试
void test_Ins(SqList &A) {
	ElemType e;
	int position;

	printf("ListInsert测试:\n\n");
	printf("请输入一个数:");
	scanf_s("%d", &e);
	printf("\n请选择要插入表A中元素位置:\n");
	printf("A:");
	ListTraverse(A, visit);
	scanf_s("%d", &position);
	if (ListInsert(A, position, e)) {
		printf("A:");
		ListTraverse(A, visit);
	}
	else
		printf("添加元素位置非法\n");

	printf("\n\nListInsert测试，回车后开始下一测试\n\n");
	getchar();
	getchar();
}


// ListDelete 测试
void tese_Del(SqList &B) {
	ElemType e;
	int position;

	printf("ListDelete测试:\n\n");
	printf("请选择要删除表B中元素位置:\n");
	printf("B:");
	ListTraverse(B, visit);
	scanf_s("%d", &position);
	if (ListDelete(B, position, e)) {
		printf("B:");
		ListTraverse(B, visit);
		printf("删除元素:%d\n", e);
	}
	else
		printf("删除元素位置非法\n\n");

	printf("\n\nListDelete测试结束，回车后开始下一测试\n\n");
	getchar();
	getchar();
}


// PriorElem 与 NextElem 测试
void test_PN(SqList &A, SqList &B) {
	ElemType e;
	ElemType *p = NULL;
	ElemType *q = NULL;

	printf("PriorElem & NextElem 测试:\n\n");
	printf("A:");
	ListTraverse(A, visit);
	printf("B:");
	ListTraverse(B, visit);
	printf("\n请输入想要前驱数据元素(A):");
	scanf_s("%d", &e);
	if (PriorElem(A, e, p)) {
		printf("\nA的前驱：");
		visit(p);
	}
	else
		printf("\n输入数据顺序表A中不存在\n");
	printf("\n\n请输入想要后继数据元素(B):");
	scanf_s("%d", &e);
	if (NextElem(B, e, q)) {
		printf("\nB的后继：");
		visit(q);
	}
	else
		printf("\n输入数据顺序表B中不存在\n");

	printf("\n\nPriorElem & NextElem 测试结束，回车后开始下一测试\n");
	getchar();
	getchar();
}


//ListEmpty,ClearList 测试
void test_LE_CL(SqList &C) {
	printf("ListEmpty,ClearList 测试:\n\n");
	printf("检测顺序表C是否为空\n\n");
	if (ListEmpty(C))
		printf("C顺序表为空\n\n");
	else
		printf("C顺序表非空\n\n");
	ClearList(C);
	getchar();
	printf("调用ClearList()后,\n再次检测顺序表C是否为空\n\n");
	if (ListEmpty(C))
		printf("C顺序表为空\n\n");
	else
		printf("C顺序表非空\n\n");
	
	printf("\n\nListEmpty,ClearList测试结束，回车后开始下一测试\n\n");
	getchar();
	
}


//算法2.7MergeList，ListRank, LocateElem，ListLength,GetElem 测试
void test_multiterm(SqList &A, SqList &B, SqList &C) {
	ElemType e;
	int position, length_List;

	printf("算法2.7MergeList，ListRank，LocateElem，ListLength,GetElem 测试:\n\n");
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
	printf("\n\n顺序表C长度为%d\n\n", length_List);
	printf("请选择想要获取顺序表C中数据的位序：");
	scanf_s("%d", &position);
	GetElem(C, position, e);
	printf("\n顺序表C中位序%d数据是%d\n", position, e);

	printf("\n\n测试完毕，回车后退出测试\n");
	getchar();
	getchar();
}
