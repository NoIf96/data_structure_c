#include<stdio.h>
#include<stdlib.h>

#include"LinkList_operation.h"

/*Status compare(ElemType e1, ElemType e2) {
	if (e1. == e2)
		return TRUE;
	return FALSE;
}*/



Status visit(Link node) {
	if (node) {
		printf("%d ", node->data);
		return OK;
	}
	else
		return FALSE;
}

//������pָ���ֵΪe�Ľ�㣬������OK��������ʧ�ܣ��򷵻�ERROR
Status MakeNode(Link &p,ElemType e) {
	if (!(p = (Link)malloc(sizeof(LNode))))    //���ռ��Ƿ����ɹ�
		return ERROR;
	p->data = e;                               //Ϊ��㸳ֵ
	p->next = NULL;                            //�������ָ���

	return OK;
}


//�ͷ�p��ָ���
void FreeNode(Link &p) {
	free(p);                                  //�ͷŽ��
	p = NULL;                                 //�������ָ���
}


//����һ���յ���������L
Status InitList(LinkList &L) {
	Link h = (Link)malloc(sizeof(LNode));    //����ͷ���
	
	if ((!L.head) && (!L.tail))                 //��������Ƿ���� 
		exit(OVERFLOW);
	h->next = NULL;                          //��ͷ�����ָ���
	L.head = h;                              //��ͷָ��ָ��ͷ���
	L.tail = h;                              //��βָ��ָ��ͷ���
	L.len = 0;                               //��ʼ��L.len

	return OK;
}


//������������L,L���ٴ���
Status DestroyList(LinkList &L) {
	Link p, q;                               //��������ָ��p��q
	p = L.head->next;                        
	q = L.head->next;

	while (p != L.tail) {                    //�����ͷ�ÿ�����
		p = q->next;
		free(q);
		q = p;
	}  
	free(L.head);                           //�ͷ�ͷ���
	L.head = NULL;                          //��ͷָ��ָ���
	L.tail = NULL;                          //��βָ��ָ���
	L.len = 0;                              //��ʼ��L.len


	return OK;
}


//����������L����Ϊ�ձ����ͷ�ԭ����Ľ��ռ�
Status ClearList(LinkList &L) {
	Link p,q;                                //��������ָ��p��q
	p = L.head->next;
	q = L.head->next;

	while (p!=L.tail) {                      //�����ͷ�ÿ�����
		p = q->next;
		free(q);
		q = p;
	}
	L.head->next = NULL;                     //��ʼ��1ͷ���
	L.tail = L.head;
	L.len = 0;

	return OK;
}


//��֪hָ�����������ͷ��㣬��s��ָ�������ڵ�һ�����֮ǰ(ͷ�巨)
Status InsFirst(LinkList &L,Link h, Link s) {
	s->next = h->next;                    
	h->next = s;

	if (h == L.tail)                      //��һ�β���ʱ�޸�βָ�뽫��ָ��β���
		L.tail = L.head->next;

	L.len++;

	return OK;
}


//��֪hָ�����������ͷ��㣬ɾ������ĵ�һ����㲢��q����
Status DelFirst(LinkList &L,Link h, Link &q) {
	if (L.head->next == L.tail)                   //����һ�����Ϊβ��㣬��β���ָ��ͷ���
		L.tail = L.head;

	
	
	q = h->next;      
	if (q == L.tail)
		L.tail = PriorPos(L, q);
	h->next = q->next;

	
	L.len--;

	return OK;
}


//��ָ��s��ָ��һ�����������������������һ�����(β�巨)
//֮�󣬲��ı�����L��βָ��ָ���µ�β���
Status Append(LinkList &L, Link s) {
	int i = 1;

	L.tail->next = s;
	for (;s->next;i++, s = s->next);          //��s�������β���

	L.tail = s;                               //�ƶ�βָ��
	L.len += i;

	return OK;
}


//ɾ����������L�е�β��㲢��q����
//֮�󣬲��ı�����L��βָ��ָ���µ�β���
Status Remove(LinkList &L, Link &q) {
	Link p;
	p = PriorPos(L, L.tail);          //�õ�β����ǰ��
	p->next = NULL;                 
	L.tail = p;                       //��βָ��ָ��p;
	L.len--;



	return OK;
}

//������Ӻ���
//ɾ��s���
Status Delp(LinkList &L, Link &s) {
	Link p,q;                    
	p = PriorPos(L, s);                
	
	q = p->next;
	p->next = q->next;
	FreeNode(q);
	s = NULL;
	L.len--;

	return OK;
}

//��֪pָ����������L�е�һ����㣬��s��ָ������p��ָ���֮ǰ
//���޸�ָ��pָ���²���Ľ��
Status InsBefore(LinkList &L, Link &p, Link s) {
	Link q;
	
	q = PriorPos(L, p);                   //�õ�p��ǰ��
	s->next = q->next;
	q->next = s;
	p = s;                                //��pָ��s���
	L.len++;

	return OK;
}


//��֪pָ����������L�е�һ����㣬��s��ָ������p��ָ���֮��
//���޸�ָ��pָ���²���Ľ��
Status InsAfter(LinkList &L, Link &p, Link s) {
	s->next = p->next;
	p->next = s;
	p = s;

	L.len++;
	return OK;
}


//��֪pָ�����������е�һ����㣬��e����p��ָ���������Ԫ�ص�ֵ
Status SetCurElem(Link &p, ElemType e) {
	p->data = e;

	return OK;
}


//��֪pָ�����������е�һ����㣬����p��ָ���������Ԫ�ص�ֵ
ElemType GetCurElem(Link p) {
	
	ElemType e;
	e = p->data;

	return e;
}


//�����Ա�Ϊ�գ��򷵻�TRUE�����򷵻�FALSE
Status ListEmpty(LinkList L) {
	if (!(L.head == L.tail))
		return FALSE;
	return TRUE;
}


//�������Ա�L��Ԫ�ظ���
int ListLength(LinkList L) {
	return L.len;
}


//������������L��ͷ����λ��
Position GetHead(LinkList L) {
	return L.head;
}


//������������L�����һ������λ��
Position GetLast(LinkList L) {
	return L.tail;
}


//��֪pָ����������L�е�һ����㣬����p��ָ����ֱ��ǰ����λ��
//����ǰ�����򷵻�NULL
Position PriorPos(LinkList L, Link p) {
	Link q;
	if (L.head == p)                         //���p����Ƿ���ǰ��
		q = NULL;
	for (q = L.head;q&&q->next != p;q = q->next);   

	return q;
}


//��֪pָ����������L�е�һ����㣬����p��ָ����ֱ�Ӻ�̵�λ��
//���޺�̣��򷵻�NULL
Position NextPos(LinkList L, Link p) {
	return p->next;                     //��pΪβ����Ƿ��غ����ΪNULL�����Դ˳�������
}
 

//����pָʾ��������L�е�i�����λ�ò�����OK��iֵ���Ϸ�ʱ����ERROR
Status LocatePos(LinkList L, int i, Link &p) {
	p = L.head->next;
	
	if (i < 1 || i>L.len)                         //���i�Ƿ�Ƿ�
		return ERROR;
	for (int j = 1;j < i;j++,p = p->next);

	return OK;
}


//������������L�е�һ����e���㺯��compare�����ж���ϵ��Ԫ��λ��
//��������������Ԫ�أ��򷵻�NULL
Status LocateElem(LinkList L, ElemType e, Position &q, int(*cmp)(ElemType, ElemType)) {

	for (q = L.head->next;q;q = q->next) {
		int x = (*cmp)(e, q->data);
		if (x == 0)
			return TRUE;
		/*else if (x == 1) {
			q = PriorPos(L, q);
		}*/
	}
	return FALSE;
}


//���ζ�L��ÿ��Ԫ�ص��ú���visit������һ��visit()ʧ�ܣ������ʧ��
Status ListTraverse(LinkList L, Status(*visit)(Link )) {
	Link p;                
	
	for (p = L.head->next;p && (*visit)(p);p=p->next);

	printf("\n");
	if (p)
		exit(OVERFLOW);

	return OK;
}


void ListRank(LinkList &L, int(*cmp)(ElemType, ElemType)) {
	
	Link p, q;

	if (L.len == 0)
		return ;

	for (p = L.head->next;p->next; p = p->next) {
		for (q = p->next;q; q = q->next) {
			if ((*cmp)(q->data, p->data) == -1) {
				Link t = PriorPos(L, p);
				Link s = PriorPos(L, q);

				s->next = q->next;

				q->next = t->next;
				t->next = q;

				p = q;
				q = p->next;

			}
		}
	}

	for (p = L.head->next;p->next;p = p->next);
	L.tail = p;

}

