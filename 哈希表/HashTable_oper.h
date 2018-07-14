#pragma once
#ifndef HASHTABLEOPER_H_INCLUDED
#define HASHTABLEOPER_H_INCLUDED

#include"HashTable.h"

//����
Status InitHash(HashTable &H);
void CreatHash(HashTable &H,double &C);

//����
void DestoryHash(HashTable &H);

//��ϣ����
int Hash(KeyType K);

//��ͻ
int collision(int p, int c);

//����
Status SearchHash(HashTable H, KeyType K, int&p, int &c);

//����
Status InsertHash(HashTable &H, ElemType e,double &C);

//����ַ
void CreatHashList(HashTableList HL[],int &n);
void DestoryHashList(HashTableList HL[],int n);
Status InsertListHash(HashTableList HL[], ElemType e);

//����
Status HashTraverse(HashTable H, Status(*Visit)(ElemType e),double C);
Status HashTraverseList(HashTableList HL[], Status(*Visit)(ElemType e), int n);
Status PrintKey(ElemType e);

#endif