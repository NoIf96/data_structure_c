#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

 // �����
#define LIST_INIT_SIZE 20     //˳���ռ��ʼ����С
#define LISTINCEMENT 10       //˳���ռ�������

#define OVERFLOW 0
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;           //����Status����
typedef int ElemType;         // ����ElemType����

 // ˳���ṹ��
typedef struct {
	ElemType *elem;           //˳������
	int length;               //˳�����
	int listsize;             //˳����С
}SqList;


int compare(ElemType e1, ElemType e2);;
int visit(ElemType *node);

 // ˳����������
Status InitList(SqList &L);     //�����˳����ɹ�����OK
Status DestoryList(SqList &L);  //����˳����ɹ�����OK
Status ClearList(SqList &L);    //����˳����ɹ�����OK
Status ListEmpty(SqList L);     //���˳����Ƿ�Ϊ�գ����򷵻�TRUE�����򷵻�FALSE
Status ListLength(SqList L);    //����˳���������Ԫ�ظ���
Status GetElem(SqList L, int i, ElemType &e);      //��e����˳����е�i������Ԫ�أ�������                             
Status LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));   //����˳����е�һ������compare������Ԫ��λ��
Status PriorElem(SqList L, ElemType cur_e, ElemType* &pre_e);      //��cur_e��˳���������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��
Status NextElem(SqList L, ElemType cur_e, ElemType* &pre_e);       //��cur_e��˳���������Ԫ�أ��Ҳ������һ��������next_e�������ĺ��
Status ListInsert(SqList &L, int i, ElemType e);           //��˳����е�i��λ�ò����µ�����Ԫ��e�������ȼ�һ��
Status ListDelete(SqList &L, int i, ElemType &e);          //ɾ��˳����е�i������Ԫ�أ�����e���ո�Ϊ����Ԫ�أ�˳����ȼ�һ
Status ListTraverse(SqList L, Status(*visit)(ElemType *node));                 //���ζ�˳����е��ú���visit����
void ListRank(SqList &L);
void MergeList(SqList La, SqList Lb, SqList &Lc);           //˳���ϲ�

#endif