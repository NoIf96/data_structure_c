#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

// �����
#define LIST_INIT_SIZE 20     //�ռ��ʼ����С
#define LISTINCEMENT 10       //�ռ�������

#define OVERFLOW 0
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int Status;           //����Status����
typedef int ElemType;         // ����ElemType����

typedef struct LNode {        //�������
	ElemType data;            //������
	struct LNode *next;       //ָ����
}*Link, *Position;

typedef struct              //��������
{
	Link head, tail;          //ͷ��β���ָ��
	int len;                  //����Ԫ�ظ���
}LinkList;

Status compare(ElemType e1, ElemType e2);
Status visit(Link node);

Status MakeNode(Link &p,ElemType e);                        
//������pָ���ֵΪe�Ľ�㣬������OK��������ʧ�ܣ��򷵻�ERROR

void FreeNode(Link &p);                             
//�ͷ�p��ָ���

Status InitList(LinkList &L);                  
//����һ���յ���������L

Status DestroyList(LinkList &L);                   
//������������L,L���ٴ���

Status ClearList(LinkList &L);    
//����������L����Ϊ�ձ����ͷ�ԭ����Ľ��ռ�

Status InsFirst(LinkList &L,Link h, Link s);
//��֪hָ�����������ͷ��㣬��s��ָ�������ڵ�һ�����֮ǰ

Status DelFirst(LinkList &L, Link h, Link &q);
//��֪hָ�����������ͷ��㣬ɾ������ĵ�һ����㲢��q����

Status Delp(LinkList &L, Link &s);

Status Append(LinkList &L, Link s);                
//��ָ��s��ָ��һ�����������������������һ�����
//֮�󣬲��ı�����L��βָ��ָ���µ�β���

Status Remove(LinkList &L, Link &s);            
//ɾ����������L�е�β��㲢��q����
//֮�󣬲��ı�����L��βָ��ָ���µ�β���

Status InsBefore(LinkList &L, Link &p, Link s);    
//��֪pָ����������L�е�һ����㣬��s��ָ������p��ָ���֮ǰ
//���޸�ָ��pָ���²���Ľ��

Status InsAfter(LinkList &L, Link &p, Link s);
//��֪pָ����������L�е�һ����㣬��s��ָ������p��ָ���֮��
//���޸�ָ��pָ���²���Ľ��

Status SetCurElem(Link &p, ElemType e);
//��֪pָ�����������е�һ����㣬��e����p��ָ���������Ԫ�ص�ֵ

ElemType GetCurElem(Link p);
//��֪pָ�����������е�һ����㣬����p��ָ���������Ԫ�ص�ֵ

Status ListEmpty(LinkList L);
//�����Ա�Ϊ�գ��򷵻�TRUE�����򷵻�FALSE

int ListLength(LinkList L);
//�������Ա�L��Ԫ�ظ���

Position GetHead(LinkList L);
//������������L��ͷ����λ��

Position GetLast(LinkList L);
//������������L�����һ������λ��

Position PriorPos(LinkList L, Link p);
//��֪pָ����������L�е�һ����㣬����p��ָ����ֱ��ǰ����λ��
//����ǰ�����򷵻�NULL

Position NextPos(LinkList L, Link p);
//��֪pָ����������L�е�һ����㣬����p��ָ����ֱ�Ӻ�̵�λ��
//���޺�̣��򷵻�NULL

Status LocatePos(LinkList L, int i, Link &p);
//����pָʾ��������L�е�i�����λ�ò�����OK��iֵ���Ϸ�ʱ����ERROR

Position LocateElem(LinkList &L, ElemType e, Status(*compare)(ElemType, ElemType));
//������������L�е�һ����e���㺯��compare�����ж���ϵ��Ԫ��λ��
//��������������Ԫ�أ��򷵻�NULL

Status ListTraverse(LinkList L, Status(*visit)(Link));
//���ζ�L��ÿ��Ԫ�ص��ú���visit������һ��visit()ʧ�ܣ������ʧ��

void ListRankcc(LinkList &L);

#endif
