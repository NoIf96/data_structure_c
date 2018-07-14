#pragma once
#ifndef BSTOPER_H_INCLUDED
#define BSTOPER_H_INCLUDED

#include "BST.h"

Status SearchBST(BSTree T, KeyType key, BSTPos f, BSTPos &p);//查找
Status InsertBST(BSTree &T, ElemType e);     //插入
Status DeleteBST(BSTree &T, KeyType key);    //删除
void DeleteNode(BSTree &p);                  //结点删除
void DestoryBSTree(BSTree & T);              //销毁
Status InOrderTraverse(BSTree T, Status(*Visit)(ElemType e));   //中序遍历
Status PrintElement(ElemType e);             //打印

#endif