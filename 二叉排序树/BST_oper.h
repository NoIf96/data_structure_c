#pragma once
#ifndef BSTOPER_H_INCLUDED
#define BSTOPER_H_INCLUDED

#include "BST.h"

Status SearchBST(BSTree T, KeyType key, BSTPos f, BSTPos &p);//����
Status InsertBST(BSTree &T, ElemType e);     //����
Status DeleteBST(BSTree &T, KeyType key);    //ɾ��
void DeleteNode(BSTree &p);                  //���ɾ��
void DestoryBSTree(BSTree & T);              //����
Status InOrderTraverse(BSTree T, Status(*Visit)(ElemType e));   //�������
Status PrintElement(ElemType e);             //��ӡ

#endif