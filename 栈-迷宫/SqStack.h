#pragma once
#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED

// �����
#define STACK_INIT_SIZE 100     //�ռ��ʼ����С
#define STACKINCEMENT 10       //�ռ�������

#define  TRUE        1
#define  FALSE       0
#define  OK          1
#define  ERROR       0
#define  INFEASIBLE -1
#define  OVERFLOW    2


typedef int Status;

//����
typedef struct {
	int x;
	int y;
}PosType;

//λ����Ϣ
typedef struct {
	PosType coord;   //����
	int di;          //����
}SElemType;

//ջ
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;





#endif
