#pragma once
#ifndef POLYNOMIALOPERATION_H_INCLUDED
#define POLYNOMIALOPERATION_H_INCLUDED

#include"Polynomial.h"

void CreatPolyn(polynomial &P, int m);           //输入m项的系数和指数，建立表示一元多项式的有序链表p
void DestroyPolyn(polynomial &P);                //销毁一元多项式p
void PrintPolyn(polynomial P);                   //打印输出一元多项式p
int PolynLength(polynomial P);                   //返回一元多项式p中的项数
void AddPolyn(polynomial &Pa, polynomial &Pb);   //相加运算，并销毁pb
void SubtractPolyn(polynomial &Pa, polynomial &Pb);//相减运算，并销毁pb
void MultiplyPolyn(polynomial &Pa, polynomial &Pb);//相乘运算，并销毁pb

int cmp(term a, term b); 

#endif