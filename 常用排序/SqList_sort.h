#pragma once
#ifndef SQLISTSORT_H_INCLUDED
#define SQLISTSORT_H_INCLUDED

#include"SqList.h"

//�۰��������
void BInsertSort(SqList L);

//ð������
void BubbleSort(SqList L);

//������
void HeapAdjuset(HeapType &H, int s, int m);
void HeapSort(HeapType H);

//2-·�鲢����
void Merge(RcdType SR[], RcdType TR[], int i, int m, int n);
void Msort(RcdType SR[], RcdType TRl[], int s, int t);
void MergeSort(SqList L);

//����
void CreatSqList(SqList &L);

//����
void SqListTraverse(SqList L, void(*Visit)(RcdType e));
void PrintKey(RcdType e);


#endif