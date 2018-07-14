#pragma once
#ifndef BITREE_H_INCLUDED
#define BITREE_H_INCLUDED

#define  TRUE        1
#define  FALSE       0
#define  OK          1
#define  ERROR       0
#define  INFEASIBLE -1
#define  OVERFLOW    2

typedef  int    Status;
typedef  char   TElemType;
typedef  enum  PointerTag  {Link,Thread};

/*
 *������
 */
typedef  struct  BiTNode{
	TElemType   data;                           //������
	struct  BiTNode *lchild, *rchild;           //���Һ���ָ��
}BiTNode, *BiTree, *BiTPos;                     //��㣬�������ָ��

/*
 *����������
 */
typedef  struct  BiThrNode {
	TElemType   data;                           //������
	struct  BiThrNode *lchild, *rchild;           //���Һ���ָ��
	PointerTag LTag, RTag;                      //���ұ�־
}BiThrNode, *BiThrTree, *BiThrPos;                     //��㣬�������ָ��


#endif//!BITREE_H_INCLUDE