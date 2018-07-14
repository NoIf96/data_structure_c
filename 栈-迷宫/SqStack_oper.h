#pragma once
#ifndef SQSTACKOPER_H_INCLUDED
#define SQSTACKOPER_H_INCLUDED

#include"SqStack.h"

Status InitStack(SqStack &S);             //����һ����ջ
Status DestroyStack(SqStack &S);          //����ջS,S���ٴ���
Status ClearStack(SqStack &S);            //��S����Ϊ��ջ
Status StackEmpty(SqStack &S);            //��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
int  StackLength(SqStack S);              //����S��Ԫ�ظ�������ջ�ĳ���
Status GetTop(SqStack S, SElemType &e);   //��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
Status Push(SqStack &S, SElemType e);     //����Ԫ��eΪ�µ�ջ��
Status Pop(SqStack &S, SElemType &e);     //��ջ���գ���ɾ��S��ջ��Ԫ�أ���e����S��ֵ��������OK�����򷵻�ERROR
Status StackTraverse(SqStack S, Status(*visit)(SElemType *p));  //��ջ�׵�ջ��һ�ζ�ջ��ÿ��Ԫ�ص��ú���visit������һ��visitʧ�������ʧ��
Status visit(SElemType* p);

#endif