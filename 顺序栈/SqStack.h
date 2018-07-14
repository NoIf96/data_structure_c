#pragma once
#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED

// �����
#define STACK_INIT_SIZE 100     //�ռ��ʼ����С
#define STACKINCEMENT 10       //�ռ�������

#define OVERFLOW -1
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int SElemType;
typedef int Status;

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;



#endif
