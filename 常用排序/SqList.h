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

//�������ݽṹ��
typedef  struct{
	int        data_int;
	char       data_char;
}InfoType;

//��¼�ṹ��
typedef  struct{
	KeyType    key;                    //�ؼ�����
	InfoType   otherinfo;              //����������
}RcdType;

//˳���ṹ��
typedef  struct{
	RcdType    r[MAXSIZE + 1];         //r[0]���û��ڱ�
	int        length;                 //˳�����
}SqList;

typedef  SqList HeapType;

#endif