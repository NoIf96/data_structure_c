#include<stdio.h>
#include<stdlib.h>
#include "SqStack_oper.h"

//����һ����ջ
Status InitStack(SqStack & S)
{
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	
	return OK;
}

//����ջS,S���ٴ���
Status DestroyStack(SqStack & S)
{
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;

	return OK;
}

//��S����Ϊ��ջ
Status ClearStack(SqStack & S)
{
	free(S.base);
	InitStack(S);

	return OK;
}

//��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
Status StackEmpty(SqStack & S)
{
	if (!(S.base == S.top))
		return FALSE;

	return TRUE;
}

//����S��Ԫ�ظ�������ջ�ĳ���
int StackLength(SqStack S)
{
	return S.top-S.base;
}

//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
Status GetTop(SqStack S, SElemType & e)
{
	if (StackEmpty(S))
		return ERROR;

	e = *(S.top - 1);

	return OK;
}

//����Ԫ��eΪ�µ�ջ��
Status Push(SqStack & S, SElemType e)
{
	if (S.top - S.base >= S.stacksize) {

		S.base = (SElemType *)realloc(S.base,
			(S.stacksize + STACKINCEMENT) * sizeof(SElemType));

		if (!S.base)
			exit(OVERFLOW);

		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCEMENT;
	}
	*S.top++ = e;

	return OK;
}

//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e����S��ֵ��������OK�����򷵻�ERROR
Status Pop(SqStack & S, SElemType & e)
{
	if (StackEmpty(S))
		return ERROR;

	e = *--S.top;

	return OK;
}

//��ջ�׵�ջ��һ�ζ�ջ��ÿ��Ԫ�ص��ú���visit������һ��visitʧ�������ʧ��
Status StackTraverse(SqStack S, Status(*visit)(SElemType *p))
{
	SElemType *p;

	for (p = S.base;p < S.top && (*visit)(p);p++);

	return OK;
}

Status visit(SElemType* p) {

	if (!p)
		return 0;

	printf("%d ", *p);

	return 1;
}