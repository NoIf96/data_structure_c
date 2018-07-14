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

//分配由p指向的值为e的结点，并返回OK，若分配失败，则返回ERROR
Status MakeNode(Link &p,ElemType e) {
	if (!(p = (Link)malloc(sizeof(LNode))))    //检测空间是否分配成功
		return ERROR;
	p->data = e;                               //为结点赋值
	p->next = NULL;                            //将结点后继指向空

	return OK;
}


//释放p所指结点
void FreeNode(Link &p) {
	free(p);                                  //释放结点
	p = NULL;                                 //将结点后继指向空
}


//构造一个空的线性链表L
Status InitList(LinkList &L) {
	Link h = (Link)malloc(sizeof(LNode));    //创建头结点
	
	if ((!L.head) && (!L.tail))                 //检测链表是否存在 
		exit(OVERFLOW);
	h->next = NULL;                          //将头结点后继指向空
	L.head = h;                              //将头指针指向头结点
	L.tail = h;                              //将尾指针指向头结点
	L.len = 0;                               //初始化L.len

	return OK;
}


//销毁线性链表L,L不再存在
Status DestroyList(LinkList &L) {
	Link p, q;                               //创建工作指针p，q
	p = L.head->next;                        
	q = L.head->next;

	while (p != L.tail) {                    //依次释放每个结点
		p = q->next;
		free(q);
		q = p;
	}  
	free(L.head);                           //释放头结点
	L.head = NULL;                          //将头指针指向空
	L.tail = NULL;                          //将尾指针指向空
	L.len = 0;                              //初始化L.len


	return OK;
}


//将线性链表L重置为空表，并释放原链表的结点空间
Status ClearList(LinkList &L) {
	Link p,q;                                //创建工作指针p，q
	p = L.head->next;
	q = L.head->next;

	while (p!=L.tail) {                      //依次释放每个结点
		p = q->next;
		free(q);
		q = p;
	}
	L.head->next = NULL;                     //初始化1头结点
	L.tail = L.head;
	L.len = 0;

	return OK;
}


//已知h指向线性链表的头结点，将s所指结点插入在第一个结点之前(头插法)
Status InsFirst(LinkList &L,Link h, Link s) {
	s->next = h->next;                    
	h->next = s;

	if (h == L.tail)                      //第一次插入时修改尾指针将其指向尾结点
		L.tail = L.head->next;

	L.len++;

	return OK;
}


//已知h指向线性链表的头结点，删除链表的第一个结点并以q返回
Status DelFirst(LinkList &L,Link h, Link &q) {
	if (L.head->next == L.tail)                   //若第一个结点为尾结点，将尾结点指向头结点
		L.tail = L.head;

	
	
	q = h->next;      
	if (q == L.tail)
		L.tail = PriorPos(L, q);
	h->next = q->next;

	
	L.len--;

	return OK;
}


//将指针s所指的一串结点链接在线性链表的最后一个结点(尾插法)
//之后，并改变链表L的尾指针指向新的尾结点
Status Append(LinkList &L, Link s) {
	int i = 1;

	L.tail->next = s;
	for (;s->next;i++, s = s->next);          //将s后结点依次插入

	L.tail = s;                               //移动尾指针
	L.len += i;

	return OK;
}


//删除线性链表L中的尾结点并以q返回
//之后，并改变链表L的尾指针指向新的尾结点
Status Remove(LinkList &L, Link &q) {
	Link p;
	p = PriorPos(L, L.tail);          //得到尾结点的前驱
	p->next = NULL;                 
	L.tail = p;                       //将尾指针指向p;
	L.len--;



	return OK;
}

//自行添加函数
//删除s结点
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

//已知p指向线性链表L中的一个结点，将s所指结点插入p所指结点之前
//并修改指针p指向新插入的结点
Status InsBefore(LinkList &L, Link &p, Link s) {
	Link q;
	
	q = PriorPos(L, p);                   //得到p的前驱
	s->next = q->next;
	q->next = s;
	p = s;                                //将p指向s结点
	L.len++;

	return OK;
}


//已知p指向线性链表L中的一个结点，将s所指结点插入p所指结点之后
//并修改指针p指向新插入的结点
Status InsAfter(LinkList &L, Link &p, Link s) {
	s->next = p->next;
	p->next = s;
	p = s;

	L.len++;
	return OK;
}


//已知p指向线性链表中的一个结点，用e更新p所指结点中数据元素的值
Status SetCurElem(Link &p, ElemType e) {
	p->data = e;

	return OK;
}


//已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值
ElemType GetCurElem(Link p) {
	
	ElemType e;
	e = p->data;

	return e;
}


//若线性表为空，则返回TRUE，否则返回FALSE
Status ListEmpty(LinkList L) {
	if (!(L.head == L.tail))
		return FALSE;
	return TRUE;
}


//返回线性表L中元素个数
int ListLength(LinkList L) {
	return L.len;
}


//返回线性链表L中头结点的位置
Position GetHead(LinkList L) {
	return L.head;
}


//返回线性链表L中最后一个结点的位置
Position GetLast(LinkList L) {
	return L.tail;
}


//已知p指向线性链表L中的一个结点，返回p所指结点的直接前驱的位置
//若无前驱，则返回NULL
Position PriorPos(LinkList L, Link p) {
	Link q;
	if (L.head == p)                         //检测p结点是否有前驱
		q = NULL;
	for (q = L.head;q&&q->next != p;q = q->next);   

	return q;
}


//已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置
//若无后继，则返回NULL
Position NextPos(LinkList L, Link p) {
	return p->next;                     //当p为尾结点是返回后继仍为NULL，所以此出无需检测
}
 

//返回p指示线性链表L中第i个结点位置并返回OK，i值不合法时返回ERROR
Status LocatePos(LinkList L, int i, Link &p) {
	p = L.head->next;
	
	if (i < 1 || i>L.len)                         //检测i是否非法
		return ERROR;
	for (int j = 1;j < i;j++,p = p->next);

	return OK;
}


//返回线性链表L中第一个与e满足函数compare（）判定关系的元素位置
//若不存在这样的元素，则返回NULL
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


//依次对L的每个元素调用函数visit（），一旦visit()失败，则操作失败
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

