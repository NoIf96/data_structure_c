#pragma once
#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

// 定义宏
#define LIST_INIT_SIZE 20     //空间初始化大小
#define LISTINCEMENT 10       //空间增加量

#define OVERFLOW -1
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;           //定义Status类型

typedef struct       //项
{
	float coef;      //系数
	int expn;        //指数
}term, ElemType;

typedef struct LNode {        //结点类型
	ElemType data;            //数据域
	struct LNode *next;       //指针域
}*Link, *Position;

typedef struct              //链表类型
{
	Link head, tail;          //头，尾结点指针
	int len;                  //链表元素个数
}LinkList;

typedef LinkList polynomial;


#endif
