#pragma once
#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

// �����
#define LIST_INIT_SIZE 20     //�ռ��ʼ����С
#define LISTINCEMENT 10       //�ռ�������

#define OVERFLOW -1
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;           //����Status����

typedef struct       //��
{
	float coef;      //ϵ��
	int expn;        //ָ��
}term, ElemType;

typedef struct LNode {        //�������
	ElemType data;            //������
	struct LNode *next;       //ָ����
}*Link, *Position;

typedef struct              //��������
{
	Link head, tail;          //ͷ��β���ָ��
	int len;                  //����Ԫ�ظ���
}LinkList;

typedef LinkList polynomial;


#endif
