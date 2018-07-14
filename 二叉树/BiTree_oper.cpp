#include "BiTree_oper.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* \
* \���� BiTree T
* \����ն�����T
*/
Status InitBiTree(BiTree & T)
{
	T = NULL;

	return OK;
}

/*
 * \������T����
 * \���� BiTree T 
 * \���ٶ�����T 
 */
void DestoryBiTree(BiTree & T)
{
	
	if (T) {
		
		DestoryBiTree(T->lchild);
		DestoryBiTree(T->rchild);
		
		free(T);
		T = NULL;
		
	}
}


/*
 * \
 * \���� BiTree T 
 * \��������� T
 */
Status CreateBiTree(BiTree & T)
{
	TElemType e;

	e = getchar();

	while (e == ' ')
		e = getchar();

	if (e == '#')
		T = NULL;

	else
	{
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->data = e;

		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}


/*
 * \������T����
 * \���� BiTree T
 * \��ն�����T
 */
void ClearBiTree(BiTree & T)
{
	DestoryBiTree(T);
	InitBiTree(T);
}

/*
 * \������T����
 * \���� BiTree T
 * \��������TΪ�գ��򷵻�TRUE�����򷵻�FALSE
 */
Status BiTreeEmpty(BiTree T)
{
	if (T)
		return FALSE;

	return TRUE;
	
}

/*
 * \������T����
 * \���� BiTree T
 * \���ض�����T�����
 */
void BiTreeDepth(BiTree T, int level, int &n)
{
	
	if(T)
	{
		if (level > n)
			n = level;

		BiTreeDepth(T->lchild,level+1,n );
		BiTreeDepth(T->rchild,level+1,n );
	}

}

/*
 * \������T����
 * \���� BiTree T
 * \���ض�����T�ĸ�
 */
BiTPos Root(BiTree T)
{
	return T;
}

/*
 * \������T����,valueΪT��ĳ����ֵ
 * \���� BiTree T,TElemType value,BiTPos e
 * \��������ֵΪvalue�Ľ��λ��
 */
void BiNode_Pos(BiTree T, TElemType value,BiTPos &e)
{
	if (T) {
		if (T->data == value) {
			e = T;
			return;

		}

		BiNode_Pos(T->lchild, value, e);
		BiNode_Pos(T->rchild, value, e);
	}
}


/*
 * \������T����
 * \���� BiTree T,BiTPos e
 * \����e��ֵ
 */
TElemType Value(BiTree T, BiTPos e)
{
	return e->data;
}

/*
 * \������T���ڣ�e��T��ĳһ���
 * \���� BiTree T,TiTPos e,TElemType value
 * \��value��ֵ�������e
 */
void Assign(BiTree T, BiTPos &e, TElemType value)
{
	e->data = value;
}

/*
 * \������T���ڣ�e��T��ĳһ���
 * \���� BiTree T,BiTPos e,BiTPos &p
 * \��e��T�ķǸ���㣬�򷵻�e��˫�ף����򷵻ء��ա�
 */
void Parent(BiTree T, BiTPos e, BiTPos &p)
{
	if (T) 
	{
		if (T == e)
			p = NULL;
		if (T->lchild == e || T->rchild == e)
		{
			p = T;
			return;
		}

		Parent(T->lchild, e, p);
		Parent(T->rchild, e, p);
	}
}

/*
 * \������T���ڣ�e��T��ĳһ���
 * \���� BiTree T,BiTPos e
 * \����e�����ӣ����������򷵻ء��ա�
 */
BiTPos LeftChild(BiTree T, BiTPos e)
{
	if (!e->lchild)
		return NULL;

	return e->lchild;
}

/*
 * \������T���ڣ�e��T��ĳһ���
 * \���� BiTree T,BiTPos e
 * \����e���Һ��ӣ������Һ����򷵻ء��ա�
 */
BiTPos RightChild(BiTree T, BiTPos e)
{
	if (!e->rchild)
		return NULL;

	return e->rchild;
}

/*
 * \������T���ڣ�e��T��ĳһ���
 * \���� BiTree T,BiTPos e
 * \����e�����ֵܣ���e��T���ӻ������ֵ��򷵻ء��ա�
 */
BiTPos LeftSibling(BiTree T, BiTPos e)
{
	BiTPos p;
	Parent(T, e, p);
	if (!p || p == T || !(p->lchild))
		return NULL;
	else
		return p->lchild;
}

/*
 * \������T���ڣ�e��T��ĳһ���
 * \���� BiTree T,BiTPos e
 * \����e�����ֵܣ���e��T�Һ��ӻ������ֵ��򷵻ء��ա�
 */
BiTPos RightSibling(BiTree T, BiTPos e)
{
	BiTPos p;
	Parent(T, e, p);
	if (!p || p == T || !(p->rchild))
		return NULL;
	else
		return p->rchild;
}

/*
 * \������T���ڣ�pָ��T��ĳ����㣬LRΪ0��1���ǿն�����c��T���ཻ����������Ϊ��
 * \���� BiTree T, BiTPos p, int LR, BiTree c
 * \����LRΪ0��1������cΪT��p��ָ��������������������
 * \p��ָ����ԭ�������������������Ϊc������
 */
Status InsertChild(BiTree &T, BiTPos p, int LR, BiTree c)
{
	if(LR == 0)
	{
		c->lchild = p->lchild;
		p->lchild = c;
	}

	else if (LR == 1)
	{
		c->rchild = p->rchild;
		p->rchild = c;
	}

	return OK;
}

/*
 * \������T���ڣ�pָ��T��ĳ����㣬LRΪ0��1
 * \���� BiTree T, BiTPos p, int LR
 * \����LRΪ0��1��ɾ��T��p��ָ������������������
 */
Status DeleteChild(BiTree &T, BiTPos p, int LR)
{

	if(LR == 0)
	{
		if (p->lchild) {
			DeleteChild(T, p->lchild, 0);
			DeleteChild(T, p->lchild, 1);

			free(p->lchild);
			p->lchild = NULL;
		}
	}

	else if(LR == 1)
	{
		if (p->rchild) {
			DeleteChild(T, p->rchild, 0);
			DeleteChild(T, p->rchild, 1);

			free(p->rchild);
			p->rchild = NULL;
		}
	}
	

	return OK;
}


/*
 *����
 *������
 *ʵ��
 */

/*
 * *Visit()
 */
Status PrintElement(TElemType e)
{
	printf("%c ", e);
	return OK;
}

/*
 * ����
 */
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
	if (T)
	{
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}

/*
 * ����
 */
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
	if (T)
	{
		if (InOrderTraverse(T->lchild, Visit))
			if (Visit(T->data))
				if (InOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
			
	}
	else
		return OK;
}

/*
 * ����
 */
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) 
{
	if (T)
	{
		if (PostOrderTraverse(T->lchild, Visit))
			if (PostOrderTraverse(T->rchild, Visit))
				if (Visit(T->data))
					return OK;
		return ERROR;

	}
	else
		return OK;
}

/*
 * ����
 */
Status LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType e))
{
	if (T)
	{
		if (Visit(T->data))
			if (PostOrderTraverse(T->lchild, Visit))
				if (Visit(T->data))
					if (PostOrderTraverse(T->rchild, Visit))
						return OK;
		return ERROR;

	}
	else
		return OK;
}





/*
 *����
 *������
 *ʵ��
 */

 /*
 *
 * ���� BiThrTree T
 * �������������� T
 */
Status CreateBiThrTree(BiThrTree & Thrt)
{
	TElemType e;


	e = getchar();

	while (e == ' ')
		e = getchar();

	if (e == '#')
		Thrt = NULL;

	else
	{
		if (!(Thrt = (BiThrNode *)malloc(sizeof(BiThrNode))))
			exit(OVERFLOW);
		Thrt->data = e;
		Thrt->LTag = Link;
		Thrt->RTag = Link;

		CreateBiThrTree(Thrt->lchild);
		CreateBiThrTree(Thrt->rchild);
	}
	return OK;
}

/*
 * ����
 */
Status InOrderThreading(BiThrTree &Thrt, BiThrTree &T)
{
	BiThrPos pre;

	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrTree))))
		exit(OVERFLOW);

	Thrt->data = '#';
	Thrt->LTag = Link;
	Thrt->RTag = Thread;
	Thrt->rchild = Thrt;

	if (!T)
		Thrt->lchild = Thrt;

	else
	{
		Thrt->lchild = T;
		pre = Thrt;
		InThreading(T,pre);
		pre->rchild = Thrt;
		pre->RTag = Thread;
		Thrt->rchild = pre;
	}

	return OK;
}


void InThreading(BiThrPos &p, BiThrPos &pre)
{

	if(p)
	{
		InThreading(p->lchild, pre);

		if(!p->lchild)
		{
			p->LTag = Thread;
			p->lchild = pre;
		}

		if(!pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;

		InThreading(p->rchild, pre);
	}
}

Status InOrderTraveres_Thr(BiThrTree Thrt, Status(*Visit)(TElemType e)) {
	BiThrTree p;
	p = Thrt->lchild;
	while (p != Thrt) {
		for (;p->LTag == Link;p = p->lchild);
		Visit(p->data);
		for (;p->RTag == Thread && p->rchild != Thrt;
			Visit(p->rchild->data), p = p->rchild);
			
		p = p->rchild;
	}

	return OK;
}


void DestoryBiThrTree(BiThrTree &Thrt, BiThrTree &T)
{

	if (T->rchild != Thrt) {
		if (T->LTag == Link)
			DestoryBiThrTree(Thrt, T->lchild);
		if (T->RTag == Link)
			DestoryBiThrTree(Thrt, T->rchild);

		free(T);
		T = NULL;

		return;
	}
	free(Thrt);
	Thrt = NULL;
}








