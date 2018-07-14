#include<stdio.h>
#include<stdlib.h>
#include "SqStack_oper.h"

//构造一个空栈
Status InitStack(SqStack & S)
{
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	
	return OK;
}

//销毁栈S,S不再存在
Status DestroyStack(SqStack & S)
{
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;

	return OK;
}

//把S重置为空栈
Status ClearStack(SqStack & S)
{
	free(S.base);
	InitStack(S);

	return OK;
}

//若栈S为空栈。则返回TRUE，否则返回FALSE
Status StackEmpty(SqStack & S)
{
	if (!(S.base == S.top))
		return FALSE;

	return TRUE;
}

//返回S的元素个数，即栈的长度
int StackLength(SqStack S)
{
	return S.top-S.base;
}

//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
Status GetTop(SqStack S, SElemType & e)
{
	if (StackEmpty(S))
		return ERROR;

	e = *(S.top - 1);

	return OK;
}

//插入元素e为新的栈顶
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

//若栈不空，则删除S的栈顶元素，用e返回S其值，并返回OK，否则返回ERROR
Status Pop(SqStack & S, SElemType & e)
{
	if (StackEmpty(S))
		return ERROR;

	e = *--S.top;

	return OK;
}

//从栈底到栈顶一次对栈中每个元素调用函数visit（），一旦visit失败则操作失败
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