#pragma once
#ifndef SQQUEUEOPER_H_INCLUDED
#define SQQUEUEOPER_H_INCLUDED

#include"SqQueue.h"

//构造一个空队列Q
Status InitQueue(SqQueue &Q);
Status InitQueue(SqQueue &Q,int n);
//销毁队列Q
Status DestroyQueue(SqQueue &Q);
//将Q清为空队列
Status ClearQueue(SqQueue &Q);
//若队列为空返回TRUE，否则返回FALSE
Status QueueEmpty(SqQueue Q);
//返回Q的元素个数，及队列长度
int QueueLength(SqQueue Q);
//若队列不为空，则用e返回队头元素，并返回OK，否则返回ERROR
Status Gethead(SqQueue Q, QElemType &e);
//插入元素e为Q的新队尾
Status EnQueue(SqQueue &Q, QElemType e);
//若队列不为空，则删除Q的队头元素用e返回队头元素，并返回OK，否则返回ERROR
Status DeQueue(SqQueue &Q, QElemType &e);
//从队头到队尾依次对队列每个元素中调用函数visit()
Status QueueTraverse(SqQueue Q, bool(*visit)(QElemType *e));

bool visit(QElemType *e);

void yanghui(int n);//杨辉三角，n为行数

#endif