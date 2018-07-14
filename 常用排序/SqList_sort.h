#pragma once
#ifndef SQLISTSORT_H_INCLUDED
#define SQLISTSORT_H_INCLUDED

#include"SqList.h"

//’€∞Î≤Â»Î≈≈–Ú
void BInsertSort(SqList L);

//√∞≈›≈≈–Ú
void BubbleSort(SqList L);

//∂—≈≈–Ú
void HeapAdjuset(HeapType &H, int s, int m);
void HeapSort(HeapType H);

//2-¬∑πÈ≤¢≈≈–Ú
void Merge(RcdType SR[], RcdType TR[], int i, int m, int n);
void Msort(RcdType SR[], RcdType TRl[], int s, int t);
void MergeSort(SqList L);

//ππ‘Ï
void CreatSqList(SqList &L);

//±È¿˙
void SqListTraverse(SqList L, void(*Visit)(RcdType e));
void PrintKey(RcdType e);


#endif