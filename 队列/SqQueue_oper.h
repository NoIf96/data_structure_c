#pragma once
#ifndef SQQUEUEOPER_H_INCLUDED
#define SQQUEUEOPER_H_INCLUDED

#include"SqQueue.h"

//����һ���ն���Q
Status InitQueue(SqQueue &Q);
Status InitQueue(SqQueue &Q,int n);
//���ٶ���Q
Status DestroyQueue(SqQueue &Q);
//��Q��Ϊ�ն���
Status ClearQueue(SqQueue &Q);
//������Ϊ�շ���TRUE�����򷵻�FALSE
Status QueueEmpty(SqQueue Q);
//����Q��Ԫ�ظ����������г���
int QueueLength(SqQueue Q);
//�����в�Ϊ�գ�����e���ض�ͷԪ�أ�������OK�����򷵻�ERROR
Status Gethead(SqQueue Q, QElemType &e);
//����Ԫ��eΪQ���¶�β
Status EnQueue(SqQueue &Q, QElemType e);
//�����в�Ϊ�գ���ɾ��Q�Ķ�ͷԪ����e���ض�ͷԪ�أ�������OK�����򷵻�ERROR
Status DeQueue(SqQueue &Q, QElemType &e);
//�Ӷ�ͷ����β���ζԶ���ÿ��Ԫ���е��ú���visit()
Status QueueTraverse(SqQueue Q, bool(*visit)(QElemType *e));

bool visit(QElemType *e);

void yanghui(int n);//������ǣ�nΪ����

#endif