#include<stdio.h>
#include<stdlib.h>

#include"SqList.h"

int compare(ElemType e1, ElemType e2) {
	if (e1 == e2)
		return TRUE;
	return FALSE;
}

int visit(ElemType *node) {
	if (node) {
		printf("%d ", *node);
		return OK;
	}
	else
		return FALSE;
}

//�����˳����ɹ�����OK
Status InitList(SqList &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));  //����ռ�

	if (!L.elem)                //��ַΪ�գ��ռ����ʧ��
		exit(OVERFLOW);
	L.length = 0;                 
	L.listsize = LIST_INIT_SIZE;

	return OK;
}

//����˳����ɹ�����OK
Status DestoryList(SqList &L) {
	free(L.elem);           //�ͷ�˳����ַ�ռ�
	L.elem = NULL;          //��ʼ����ַָ��

	return OK;
}

//����˳����ɹ�����OK
Status ClearList(SqList &L) {
	free(L.elem);          //�ͷ�˳����ַ�ռ�
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
 // ����˳�������
	L.length = 0;        
	L.listsize = LIST_INIT_SIZE;

	return OK;
}

//���˳����Ƿ�Ϊ�գ����򷵻�TRUE�����򷵻�FALSE
Status ListEmpty(SqList L) {
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

//����˳���������Ԫ�ظ���
Status ListLength(SqList L) {
	return L.length;
}

//��e����˳����е�i������Ԫ�أ�������  
Status GetElem(SqList L, int i,ElemType &e) {
	if (i >= 1 && i <= ListLength(L))        //���iַ�Ƿ����Ҫ��
		e = L.elem[i - 1];

	return OK;
}

//����˳����е�һ������compare������Ԫ��λ��
Status LocateElem(SqList L, ElemType e, Status(*compare)(ElemType ,ElemType)) {
	int i;
	ElemType *p;           //��������ָ��
	
	p = L.elem;
	for (i = 0;i < L.length && !(*compare)(e, *p++);i++);      //��ȡ����compare���±�

	if (i <= L.length)           //����±��Ƿ����
		return i+1;              //����λ��
	else
		return 0;
}

//��cur_e��˳���������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��
Status PriorElem(SqList L,ElemType cur_e,ElemType* &pre_e ) {
	int i,x;
	bool Flag = 0;                          //�����±�

	for (i = 0;i < L.length && !Flag;i++)      
		if (cur_e == L.elem[i]) {
			Flag = 1;
			x = i;                          //������������±�
		} 

	if (Flag && i != 0)
		pre_e = &L.elem[x - 1];
	else
		return FALSE;

	return OK;
}

//��cur_e��˳���������Ԫ�أ��Ҳ������һ��������next_e�������ĺ��
Status NextElem(SqList L, ElemType cur_e, ElemType* &pre_e) {
	int i,x;
	bool Flag = 0;                           //������־

	for (i = 0;i < L.length && !Flag;i++)    
		if (cur_e == L.elem[i]) {
			Flag = 1;
			x = i;                           //������������±�
		}

	if (Flag && i != L.length - 1)
		pre_e = &L.elem[x + 1];
	else
		return FALSE;
	return OK;
}

//��˳����е�i��λ�ò����µ�����Ԫ��e�������ȼ�һ��
Status ListInsert(SqList &L, int i, ElemType e) {
	ElemType* newbase;
	ElemType *p, *q;                //��������ָ��

	if (i<1 || i>L.length + 1)      //���iַ�Ƿ����Ҫ��
		return ERROR;

	if (L.length >= L.listsize) {                      //���˳���ռ��Ƿ����
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCEMENT) * sizeof(ElemType));    //����˳���ռ�
		if (!newbase)           
			exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCEMENT;
	}
	q = &(L.elem[i - 1]);                             //�������ַ��������ָ��q
	for (p = L.elem + L.length - 1;p >= q;--p)      //���ù���ָ��p����˳���ĩβ����Ԫ�غ��ᣬֱ������Ԫ������λ��
		*(p + 1) = *p;

	*q = e;                                           //��eֵ����˳�����
	++L.length;

	return OK;
}

//ɾ��˳����е�i������Ԫ�أ�����e���ո�Ϊ����Ԫ�أ�˳����ȼ�һ
Status ListDelete(SqList &L, int i, ElemType &e) {
	ElemType *p, *q;                     //��������ָ��

	if (i<1 || i>L.length + 1)          //���i�Ƿ����Ҫ��
		return ERROR;

	p = &(L.elem[i - 1]);               //��Ҫɾ����ַ��������ָ��p
	e = *p;                             //��e����ɾ������Ԫ��
	q = L.elem + L.length - 1;          //��ĩλ��ַ��������ָ��q

	for (++p;p <= q;++p)                //������ǰ�ƶ�ɾ������Ԫ��λ�ú�����Ԫ�أ�ֱ�����һλ����Ԫ��
		*(p - 1) = *p;
	--L.length;

	return OK;
}

//���ζ�˳����е��ú���visit()
Status ListTraverse(SqList L,Status(*visit)(ElemType *node)) {
	int i;
	ElemType *p;                //��������ָ��
	p = L.elem;

	for (i = 0;i < L.length && (*visit)(p++);i++);  //���ε���visit����
		
	printf("\n");
	if (i != L.length)
		exit(OVERFLOW);

	return OK;
}


//˳�������
void ListRank(SqList &L) { 
	ElemType *p = NULL;
	ElemType *q = NULL;
	ElemType *f = NULL;
	ElemType t;

	p = L.elem;
	f = L.elem + L.length - 1;
	
	for (p;p <= f;p++) {
		for (q = p;q <= f;q++) {
			if (*q <= *p) {
				t = *p;
				*p = *q;
				*q = t;

			}
		}
	}

}

void MergeList(SqList La, SqList Lb, SqList &Lc) {
	int repetition_counter;                             //�ظ���������
	ElemType *pa, *pb, *pc;                             //����ָ��
	ElemType *pa_last, *pb_last;                        //����ָ��

	Lc.length = La.length + Lb.length;                  //����˳���C
	Lc.listsize = Lc.length;
	Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem)
		exit(OVERFLOW);

	pa = La.elem;                                  
	pb = Lb.elem;
	pc = Lc.elem;
	repetition_counter = 0;

	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	                                                     //�ϲ�˳���A,B��C
	while (pa <= pa_last && pb <= pb_last) {             
		if (*pa <= *pb) {
			if (*pa == *pb) {                            //������ͬ����Ԫ��
				pb++;
				repetition_counter++; 			
			}
			*pc++ = *pa++;      
		}
		else
			*pc++ = *pb++;
	} 
	                                                    //����ʣ������Ԫ��
	for (;pa <= pa_last;*pc++ = *pa++);
	for (;pb <= pb_last;*pc++ = *pb++);

	Lc.length -= repetition_counter;                    //������ȷC����
}