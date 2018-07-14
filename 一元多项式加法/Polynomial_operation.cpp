#include<stdio.h>
#include<stdlib.h>

#include"Polynomial_operation.h"
#include"LinkList_operation.h"


//输入m项的系数和指数，建立表示一元多项式的有序链表p
void CreatPolyn(polynomial &P, int m) {
	Link h, q, s;
	ElemType e;

	InitList(P);
	h = P.head;

	e.coef = 0.0;
	e.expn = -1;

	SetCurElem(h, e);
	
	for (int i = 1;i <= m;i++) {

		printf(" 请输入第%d项数据：\n", i);
		printf(" 系数：");
		scanf_s("%f", &e.coef);
		printf(" 指数：");
		scanf_s("%d", &e.expn);

		if (!LocateElem(P, e, q, cmp)) {
			if (MakeNode(s, e))
				InsFirst(P, h, s);
			 
		}
	}
	
	ListRank(P, cmp);
}

//销毁一元多项式p
void DestroyPolyn(polynomial &P) {
	FreeNode(P.head);
}

//打印输出一元多项式p
void PrintPolyn(polynomial P) {
	Link q;
	
	for (q = P.head->next;q->next;q = q->next) {
		if (q->data.expn == 0) {
			printf(" %.2f", q->data.coef);
			printf("+");
		}
		else {
			printf(" %.2fX^%d ", q->data.coef, q->data.expn);
			printf("+");
		}
	}
	printf(" %.2fX^%d ", q->data.coef, q->data.expn);

	printf("\n");
}

//返回一元多项式p中的项数
int PolynLength(polynomial P) {
	return P.len;
}

//相加运算，并销毁pb
void AddPolyn(polynomial &Pa, polynomial &Pb) {
	Link ha, hb;
	Position qa, qb;

	ha = Pa.head;
	hb = Pb.head;

	qa = NextPos(Pa, ha);
	qb = NextPos(Pb, hb);
	
	while (qa && qb) {
		term a, b, sum;
		a = GetCurElem(qa);
		b = GetCurElem(qb);

		switch (cmp(a,b))
		{
		case -1:
			ha = qa;
			qa = NextPos(Pa, qa);
			break;

		case 0:
			
			sum.coef = a.coef + b.coef;
			sum.expn = a.expn;
			if(sum.coef != 0) {
				SetCurElem(qa, sum);
				ha = qa;
			}
			else{
				DelFirst(Pa, ha, qa);
				FreeNode(qa);
			}
			DelFirst(Pb, hb, qb);
			FreeNode(qb);
			qb = NextPos(Pb, hb);
			qa = NextPos(Pa, ha);
			break;

		case 1:
			DelFirst(Pb, hb, qb);
			InsFirst(Pa, ha, qb);
			qb = NextPos(Pb, hb);
			ha = NextPos(Pa, ha);
			break;

		default:
			break;
		}
	}
	
	if (!ListEmpty(Pb)) 
		Append(Pa, qb);
	
	FreeNode(hb);
	
}

//相减运算，并销毁pb
void SubtractPolyn(polynomial &Pa, polynomial &Pb) {
	Link ha, hb;
	Position qa, qb;
	term e;

	hb = Pb.head;
	

	for (qb = hb->next;qb;qb = qb->next) {
		e.coef = -(qb->data.coef);
		e.expn = qb->data.expn;
		SetCurElem(qb, e);
	}
	
	AddPolyn(Pa, Pb);
	
}

//相乘运算，并销毁pb
void MultiplyPolyn(polynomial &Pa, polynomial &Pb) {
	Link ha, hb,hc;
	Position qa, qb;
	ElemType e;
	polynomial Pc;
	CreatPolyn(Pc, 0);

	ha = Pa.head;
	hb = Pb.head;
	hc = Pc.head;

	qa = NextPos(Pa, ha);

	while (qa) {
		Link s, q, hd;
		polynomial Pd;
		CreatPolyn(Pd, 0);
		hd = Pd.head;

		qb = NextPos(Pb, hb);
		while (qb) {
			e.coef = qa->data.coef * qb->data.coef;
			e.expn = qa->data.expn + qb->data.expn;

			if (!LocateElem(Pd, e, q, cmp)) 
				if (MakeNode(s, e))
					InsFirst(Pd, hd, s);

			qb = qb->next;
		}
		ListRank(Pd, cmp);

		if (!hc->next) {
			Append(Pc, hd->next);
			FreeNode(hd);
		}
		else
			AddPolyn(Pc, Pd);
	

		qa = qa->next;
	}
	ListRank(Pc,cmp);

	ha->next = hc->next;
	FreeNode(hc);
	FreeNode(hb);

}

int cmp(term a, term b) {
	if (a.expn == b.expn)
		return 0;
	else if (a.expn > b.expn)
		return 1;
	else
		return -1;
}
