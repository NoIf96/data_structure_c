#include<stdio.h>
#include <stdlib.h>

#include "SqQueue_oper.h"

//��ʼ��ѭ������
Status InitQueue(SqQueue &Q)
{
	Q.base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q.base)
		exit(OVERFLOW);

	Q.queuesize = MAXQSIZE;
	Q.front = Q.rear = 0;

	return OK;
}

//��ʼ��ѭ�����У�ָ����С���أ��������������
Status InitQueue(SqQueue &Q, int maxqsize)
{
	Q.base = new QElemType[maxqsize];
	if (!Q.base)
		exit(OVERFLOW);

	Q.queuesize = maxqsize;
	Q.front = Q.rear = 0;

	return OK;
}

//���ٶ���
Status DestroyQueue(SqQueue &Q)
{
	free(Q.base);
	Q.base = NULL;
	Q.front = Q.rear = 0;
	Q.queuesize = 0;

	return OK;
}

//���ö���
Status ClearQueue(SqQueue &Q)
{
	free(Q.base);
	InitQueue(Q);

	return OK;
}

//�������Ƿ�Ϊ��
Status QueueEmpty(SqQueue Q)
{
	if (!(Q.front == Q.rear))  
		return FALSE;

	return OK;
}

//������г���
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + Q.queuesize) % Q.queuesize;
}

//���ض�ͷ
Status Gethead(SqQueue Q, QElemType &e)
{
	if (QueueEmpty(Q))       //�������Ƿ�Ϊ��
		return ERROR;

	e = Q.base[Q.front];

	return OK;
}

//�����¶�β
Status EnQueue(SqQueue &Q, QElemType e)
{
	if ((Q.rear + 1) % Q.queuesize == Q.front)  //�����пռ��Ƿ��㹻
		return ERROR;

	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.queuesize;        //�ƶ�βָ��

	return OK;
}

//ɾ����ͷ
Status DeQueue(SqQueue &Q, QElemType &e)
{
	if (QueueEmpty(Q))            //�������Ƿ�Ϊ��
		return ERROR;

	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % Q.queuesize;      //�ƶ�ͷָ��

	return OK;
}

//��ӡ����
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

//�������
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
