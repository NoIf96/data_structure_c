#pragma once
#ifndef POLYNOMIALOPERATION_H_INCLUDED
#define POLYNOMIALOPERATION_H_INCLUDED

#include"Polynomial.h"

void CreatPolyn(polynomial &P, int m);           //����m���ϵ����ָ����������ʾһԪ����ʽ����������p
void DestroyPolyn(polynomial &P);                //����һԪ����ʽp
void PrintPolyn(polynomial P);                   //��ӡ���һԪ����ʽp
int PolynLength(polynomial P);                   //����һԪ����ʽp�е�����
void AddPolyn(polynomial &Pa, polynomial &Pb);   //������㣬������pb
void SubtractPolyn(polynomial &Pa, polynomial &Pb);//������㣬������pb
void MultiplyPolyn(polynomial &Pa, polynomial &Pb);//������㣬������pb

int cmp(term a, term b); 

#endif