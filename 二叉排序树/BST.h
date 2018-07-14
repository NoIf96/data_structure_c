#pragma once
#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#define  TRUE        1
#define  FALSE       0
#define  OK          1
#define  ERROR       0
#define  INFEASIBLE -1
#define  OVERFLOW    2

typedef  int    Status;
typedef  int   KeyType;

typedef  struct  ElemType {
	int dataint;
	char datachar;
	KeyType key;
}ElemType;

typedef  struct  BiTNode {
	ElemType  data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BSTree, *BSTPos;


#endif