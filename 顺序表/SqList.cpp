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

//构造空顺序表，成功返回OK
Status InitList(SqList &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));  //申请空间

	if (!L.elem)                //基址为空，空间分配失败
		exit(OVERFLOW);
	L.length = 0;                 
	L.listsize = LIST_INIT_SIZE;

	return OK;
}

//销毁顺序表，成功返回OK
Status DestoryList(SqList &L) {
	free(L.elem);           //释放顺序表基址空间
	L.elem = NULL;          //初始化基址指针

	return OK;
}

//重置顺序表，成功返回OK
Status ClearList(SqList &L) {
	free(L.elem);          //释放顺序表基址空间
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
 // 重置顺序表属性
	L.length = 0;        
	L.listsize = LIST_INIT_SIZE;

	return OK;
}

//检测顺序表是否为空，空则返回TRUE，否则返回FALSE
Status ListEmpty(SqList L) {
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

//返回顺序表中数据元素个数
Status ListLength(SqList L) {
	return L.length;
}

//用e接收顺序表中第i个数据元素，并返回  
Status GetElem(SqList L, int i,ElemType &e) {
	if (i >= 1 && i <= ListLength(L))        //检测i址是否符合要求
		e = L.elem[i - 1];

	return OK;
}

//返回顺序表中第一个满足compare的数据元素位序
Status LocateElem(SqList L, ElemType e, Status(*compare)(ElemType ,ElemType)) {
	int i;
	ElemType *p;           //构建工作指针
	
	p = L.elem;
	for (i = 0;i < L.length && !(*compare)(e, *p++);i++);      //获取满足compare的下标

	if (i <= L.length)           //检测下标是否符合
		return i+1;              //返回位序
	else
		return 0;
}

//若cur_e是顺序表中数据元素，且不是第一个，则用pre_e返回它的前驱
Status PriorElem(SqList L,ElemType cur_e,ElemType* &pre_e ) {
	int i,x;
	bool Flag = 0;                          //构建下标

	for (i = 0;i < L.length && !Flag;i++)      
		if (cur_e == L.elem[i]) {
			Flag = 1;
			x = i;                          //保存符合条件下标
		} 

	if (Flag && i != 0)
		pre_e = &L.elem[x - 1];
	else
		return FALSE;

	return OK;
}

//若cur_e是顺序表中数据元素，且不是最后一个，则用next_e返回它的后继
Status NextElem(SqList L, ElemType cur_e, ElemType* &pre_e) {
	int i,x;
	bool Flag = 0;                           //构建标志

	for (i = 0;i < L.length && !Flag;i++)    
		if (cur_e == L.elem[i]) {
			Flag = 1;
			x = i;                           //保存符合条件下标
		}

	if (Flag && i != L.length - 1)
		pre_e = &L.elem[x + 1];
	else
		return FALSE;
	return OK;
}

//在顺序表中第i个位置插入新的数据元素e，并长度加一；
Status ListInsert(SqList &L, int i, ElemType e) {
	ElemType* newbase;
	ElemType *p, *q;                //构建工作指针

	if (i<1 || i>L.length + 1)      //检测i址是否符合要求
		return ERROR;

	if (L.length >= L.listsize) {                      //检测顺序表空间是否充足
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCEMENT) * sizeof(ElemType));    //增加顺序表空间
		if (!newbase)           
			exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCEMENT;
	}
	q = &(L.elem[i - 1]);                             //将插入地址赋给工作指针q
	for (p = L.elem + L.length - 1;p >= q;--p)      //利用工作指针p将从顺序表末尾数据元素后裔，直至插入元素数据位置
		*(p + 1) = *p;

	*q = e;                                           //将e值插入顺序表中
	++L.length;

	return OK;
}

//删除顺序表中第i个数据元素，并用e接收该为数据元素，顺序表长度减一
Status ListDelete(SqList &L, int i, ElemType &e) {
	ElemType *p, *q;                     //构建工作指针

	if (i<1 || i>L.length + 1)          //检测i是否符合要求
		return ERROR;

	p = &(L.elem[i - 1]);               //将要删除地址赋给工作指针p
	e = *p;                             //用e接收删除数据元素
	q = L.elem + L.length - 1;          //将末位地址赋给工作指针q

	for (++p;p <= q;++p)                //依次向前移动删除数据元素位置后数据元素，直至最后一位数据元素
		*(p - 1) = *p;
	--L.length;

	return OK;
}

//依次对顺序表中调用函数visit()
Status ListTraverse(SqList L,Status(*visit)(ElemType *node)) {
	int i;
	ElemType *p;                //构建工作指针
	p = L.elem;

	for (i = 0;i < L.length && (*visit)(p++);i++);  //依次调用visit函数
		
	printf("\n");
	if (i != L.length)
		exit(OVERFLOW);

	return OK;
}


//顺序表排序
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
	int repetition_counter;                             //重复数计数器
	ElemType *pa, *pb, *pc;                             //工作指针
	ElemType *pa_last, *pb_last;                        //辅助指针

	Lc.length = La.length + Lb.length;                  //构建顺序表C
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
	                                                     //合并顺序表A,B到C
	while (pa <= pa_last && pb <= pb_last) {             
		if (*pa <= *pb) {
			if (*pa == *pb) {                            //丢弃相同数据元素
				pb++;
				repetition_counter++; 			
			}
			*pc++ = *pa++;      
		}
		else
			*pc++ = *pb++;
	} 
	                                                    //插入剩余数据元素
	for (;pa <= pa_last;*pc++ = *pa++);
	for (;pb <= pb_last;*pc++ = *pb++);

	Lc.length -= repetition_counter;                    //计算正确C表长度
}