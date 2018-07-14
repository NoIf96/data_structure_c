#pragma once
#ifndef HASHTABLEOPER_H_INCLUDED
#define HASHTABLEOPER_H_INCLUDED

#include"HashTable.h"

//构造
Status InitHash(HashTable &H);
void CreatHash(HashTable &H,double &C);

//销毁
void DestoryHash(HashTable &H);

//哈希函数
int Hash(KeyType K);

//冲突
int collision(int p, int c);

//查找
Status SearchHash(HashTable H, KeyType K, int&p, int &c);

//插入
Status InsertHash(HashTable &H, ElemType e,double &C);

//链地址
void CreatHashList(HashTableList HL[],int &n);
void DestoryHashList(HashTableList HL[],int n);
Status InsertListHash(HashTableList HL[], ElemType e);

//遍历
Status HashTraverse(HashTable H, Status(*Visit)(ElemType e),double C);
Status HashTraverseList(HashTableList HL[], Status(*Visit)(ElemType e), int n);
Status PrintKey(ElemType e);

#endif