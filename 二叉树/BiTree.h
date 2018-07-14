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
 *二叉树
 */
typedef  struct  BiTNode{
	TElemType   data;                           //数据域
	struct  BiTNode *lchild, *rchild;           //左右孩子指针
}BiTNode, *BiTree, *BiTPos;                     //结点，树，结点指针

/*
 *线索二叉树
 */
typedef  struct  BiThrNode {
	TElemType   data;                           //数据域
	struct  BiThrNode *lchild, *rchild;           //左右孩子指针
	PointerTag LTag, RTag;                      //左右标志
}BiThrNode, *BiThrTree, *BiThrPos;                     //结点，树，结点指针


#endif//!BITREE_H_INCLUDE