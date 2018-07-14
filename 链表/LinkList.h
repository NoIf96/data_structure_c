#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

// 定义宏
#define LIST_INIT_SIZE 20     //空间初始化大小
#define LISTINCEMENT 10       //空间增加量

#define OVERFLOW 0
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;           //定义Status类型
typedef int ElemType;         // 定义ElemType类型

typedef struct LNode {        //结点类型
	ElemType data;            //数据域
	struct LNode *next;       //指针域
}*Link, *Position;

typedef struct              //链表类型
{
	Link head, tail;          //头，尾结点指针
	int len;                  //链表元素个数
}LinkList;

Status compare(ElemType e1, ElemType e2);
Status visit(Link node);

Status MakeNode(Link &p,ElemType e);                        
//分配由p指向的值为e的结点，并返回OK，若分配失败，则返回ERROR

void FreeNode(Link &p);                             
//释放p所指结点

Status InitList(LinkList &L);                  
//构造一个空的线性链表L

Status DestroyList(LinkList &L);                   
//销毁线性链表L,L不再存在

Status ClearList(LinkList &L);    
//将线性链表L重置为空表，并释放原链表的结点空间

Status InsFirst(LinkList &L,Link h, Link s);
//已知h指向线性链表的头结点，将s所指结点插入在第一个结点之前

Status DelFirst(LinkList &L, Link h, Link &q);
//已知h指向线性链表的头结点，删除链表的第一个结点并以q返回

Status Delp(LinkList &L, Link &s);

Status Append(LinkList &L, Link s);                
//将指针s所指的一串结点链接在线性链表的最后一个结点
//之后，并改变链表L的尾指针指向新的尾结点

Status Remove(LinkList &L, Link &s);            
//删除线性链表L中的尾结点并以q返回
//之后，并改变链表L的尾指针指向新的尾结点

Status InsBefore(LinkList &L, Link &p, Link s);    
//已知p指向线性链表L中的一个结点，将s所指结点插入p所指结点之前
//并修改指针p指向新插入的结点

Status InsAfter(LinkList &L, Link &p, Link s);
//已知p指向线性链表L中的一个结点，将s所指结点插入p所指结点之后
//并修改指针p指向新插入的结点

Status SetCurElem(Link &p, ElemType e);
//已知p指向线性链表中的一个结点，用e更新p所指结点中数据元素的值

ElemType GetCurElem(Link p);
//已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值

Status ListEmpty(LinkList L);
//若线性表为空，则返回TRUE，否则返回FALSE

int ListLength(LinkList L);
//返回线性表L中元素个数

Position GetHead(LinkList L);
//返回线性链表L中头结点的位置

Position GetLast(LinkList L);
//返回线性链表L中最后一个结点的位置

Position PriorPos(LinkList L, Link p);
//已知p指向线性链表L中的一个结点，返回p所指结点的直接前驱的位置
//若无前驱，则返回NULL

Position NextPos(LinkList L, Link p);
//已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置
//若无后继，则返回NULL

Status LocatePos(LinkList L, int i, Link &p);
//返回p指示线性链表L中第i个结点位置并返回OK，i值不合法时返回ERROR

Position LocateElem(LinkList &L, ElemType e, Status(*compare)(ElemType, ElemType));
//返回线性链表L中第一个与e满足函数compare（）判定关系的元素位置
//若不存在这样的元素，则返回NULL

Status ListTraverse(LinkList L, Status(*visit)(Link));
//依次对L的每个元素调用函数visit（），一旦visit()失败，则操作失败

void ListRankcc(LinkList &L);

#endif
