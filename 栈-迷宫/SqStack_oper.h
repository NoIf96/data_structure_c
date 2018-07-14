#pragma once
#ifndef SQSTACKOPER_H_INCLUDED
#define SQSTACKOPER_H_INCLUDED

#include"SqStack.h"

Status InitStack(SqStack &S);             //构造一个空栈
Status DestroyStack(SqStack &S);          //销毁栈S,S不再存在
Status ClearStack(SqStack &S);            //把S重置为空栈
Status StackEmpty(SqStack &S);            //若栈S为空栈。则返回TRUE，否则返回FALSE
int  StackLength(SqStack S);              //返回S的元素个数，即栈的长度
Status GetTop(SqStack S, SElemType &e);   //若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
Status Push(SqStack &S, SElemType e);     //插入元素e为新的栈顶
Status Pop(SqStack &S, SElemType &e);     //若栈不空，则删除S的栈顶元素，用e返回S其值，并返回OK，否则返回ERROR
Status StackTraverse(SqStack S, Status(*visit)(SElemType *p));  //从栈底到栈顶一次对栈中每个元素调用函数visit（），一旦visit失败则操作失败
Status visit(SElemType* p);

#endif