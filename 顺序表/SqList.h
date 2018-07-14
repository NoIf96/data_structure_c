#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

 // 定义宏
#define LIST_INIT_SIZE 20     //顺序表空间初始化大小
#define LISTINCEMENT 10       //顺序表空间增加量

#define OVERFLOW 0
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;           //定义Status类型
typedef int ElemType;         // 定义ElemType类型

 // 顺序表结构体
typedef struct {
	ElemType *elem;           //顺序表变量
	int length;               //顺序表长度
	int listsize;             //顺序表大小
}SqList;


int compare(ElemType e1, ElemType e2);;
int visit(ElemType *node);

 // 顺序表基本操作
Status InitList(SqList &L);     //构造空顺序表，成功返回OK
Status DestoryList(SqList &L);  //销毁顺序表，成功返回OK
Status ClearList(SqList &L);    //重置顺序表，成功返回OK
Status ListEmpty(SqList L);     //检测顺序表是否为空，空则返回TRUE，否则返回FALSE
Status ListLength(SqList L);    //返回顺序表中数据元素个数
Status GetElem(SqList L, int i, ElemType &e);      //用e接收顺序表中第i个数据元素，并返回                             
Status LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));   //返回顺序表中第一个满足compare的数据元素位序
Status PriorElem(SqList L, ElemType cur_e, ElemType* &pre_e);      //若cur_e是顺序表中数据元素，且不是第一个，则用pre_e返回它的前驱
Status NextElem(SqList L, ElemType cur_e, ElemType* &pre_e);       //若cur_e是顺序表中数据元素，且不是最后一个，则用next_e返回它的后继
Status ListInsert(SqList &L, int i, ElemType e);           //在顺序表中第i个位置插入新的数据元素e，并长度加一；
Status ListDelete(SqList &L, int i, ElemType &e);          //删除顺序表中第i个数据元素，并用e接收该为数据元素，顺序表长度减一
Status ListTraverse(SqList L, Status(*visit)(ElemType *node));                 //依次对顺序表中调用函数visit（）
void ListRank(SqList &L);
void MergeList(SqList La, SqList Lb, SqList &Lc);           //顺序表合并

#endif