#include<stdio.h>
#include <stdlib.h>

#include "SqQueue_oper.h"

//初始化循环队列
Status InitQueue(SqQueue &Q)
{
	Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base)
		exit(OVERFLOW);

	Q.queuesize = MAXQSIZE;
	Q.front = Q.rear = 0;

	return OK;
}

//初始化循环队列（指定大小重载），用于杨辉三角
Status InitQueue(SqQueue &Q, int maxqsize)
{
	Q.base = new QElemType[maxqsize];
	if (!Q.base)
		exit(OVERFLOW);

	Q.queuesize = maxqsize;
	Q.front = Q.rear = 0;

	return OK;
}

//销毁队列
Status DestroyQueue(SqQueue &Q)
{
	free(Q.base);
	Q.base = NULL;
	Q.front = Q.rear = 0;
	Q.queuesize = 0;

	return OK;
}

//重置队列
Status ClearQueue(SqQueue &Q)
{
	free(Q.base);
	InitQueue(Q);

	return OK;
}

//检测队列是否为空
Status QueueEmpty(SqQueue Q)
{
	if (!(Q.front == Q.rear))  
		return FALSE;

	return OK;
}

//计算队列长度
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + Q.queuesize) % Q.queuesize;
}

//返回队头
Status Gethead(SqQueue Q, QElemType &e)
{
	if (QueueEmpty(Q))       //检测队列是否为空
		return ERROR;

	e = Q.base[Q.front];

	return OK;
}

//插入新队尾
Status EnQueue(SqQueue &Q, QElemType e)
{
	if ((Q.rear + 1) % Q.queuesize == Q.front)  //检测队列空间是否足够
		return ERROR;

	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.queuesize;        //移动尾指针

	return OK;
}

//删除队头
Status DeQueue(SqQueue &Q, QElemType &e)
{
	if (QueueEmpty(Q))            //检测队列是否为空
		return ERROR;

	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.queuesize;      //移动头指针

	return OK;
}

//打印队列
Status QueueTraverse(SqQueue Q, bool(*visit)(QElemType *e))
{
	for (int i = Q.front;i < Q.rear && (*visit)(&Q.base[i]);i++);
	 
	return OK;
}

bool visit(QElemType *e)
{
	if (!e)
		return ERROR;
	printf("%2d ", *e);
	return TRUE;
}

//杨辉三角
void yanghui(int n) {
	SqQueue Q;
	QElemType e, s;
	int k = 2;

	InitQueue(Q, n + 2);

	for (int i = k; i <= n;i++)
		printf(" ");
	printf("1 \n");

	EnQueue(Q, 0);
	EnQueue(Q, 1);
	EnQueue(Q, 1);

	while (k < n) {
		for (int i = 1;i <= n - k;i++)
			printf(" ");
		EnQueue(Q, 0);

		do {
			
			DeQueue(Q, s);
			Gethead(Q, e);

			if (e)
				printf("%d ", e);
			else
				printf("\n");

			EnQueue(Q, s + e);

		} while (e != 0);
		k++;
	}

	DeQueue(Q, e);
	while (!QueueEmpty(Q)) {
		DeQueue(Q, e);
		printf("%d ", e);
	}

}
