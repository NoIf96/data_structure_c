#pragma once
#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#define  TRUE        1
#define  FALSE       0
#define  OK          1
#define  ERROR       0
#define  INFEASIBLE -1
#define  OVERFLOW    2

#define  SUCCESS     1
#define  UNSUCCESS   0
#define  DUPLICATE  -1
#define  NULLKEY    -2

typedef  int    Status;
typedef  int    KeyType;

typedef  struct  ElemType {
	int dataint;
	char datachar;
	KeyType key;
}ElemType;

typedef  struct 
{
	ElemType *elem;        //数据元素存储基址
	int count;             //当前元素个数
	int sizeindex;         //默认为hashsize；
}HashTable;

typedef  struct HashTableNode
{
	HashTableNode *next;        //数据元素存储基址
	ElemType data;
}HashTableNode, *HashTableList;

#endif