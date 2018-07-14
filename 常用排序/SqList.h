#pragma once
#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

#define  TRUE        1
#define  FALSE       0
#define  OK          1
#define  ERROR       0
#define  INFEASIBLE -1
#define  OVERFLOW    2

#define  MAXSIZE    20

typedef  int   Status;
typedef  int   KeyType;

//其他数据结构体
typedef  struct{
	int        data_int;
	char       data_char;
}InfoType;

//记录结构体
typedef  struct{
	KeyType    key;                    //关键字项
	InfoType   otherinfo;              //其他数据项
}RcdType;

//顺序表结构体
typedef  struct{
	RcdType    r[MAXSIZE + 1];         //r[0]闲置或哨兵
	int        length;                 //顺序表长度
}SqList;

typedef  SqList HeapType;

#endif