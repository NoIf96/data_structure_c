#include "BiTree_oper.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* \
* \参数 BiTree T
* \构造空二叉树T
*/
Status InitBiTree(BiTree & T)
{
	T = NULL;

	return OK;
}

/*
 * \二叉树T存在
 * \参数 BiTree T 
 * \销毁二叉树T 
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
 * \参数 BiTree T 
 * \构造二叉树 T
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
 * \二叉树T存在
 * \参数 BiTree T
 * \清空二叉树T
 */
void ClearBiTree(BiTree & T)
{
	DestoryBiTree(T);
	InitBiTree(T);
}

/*
 * \二叉树T存在
 * \参数 BiTree T
 * \若二叉树T为空，则返回TRUE，否则返回FALSE
 */
Status BiTreeEmpty(BiTree T)
{
	if (T)
		return FALSE;

	return TRUE;
	
}

/*
 * \二叉树T存在
 * \参数 BiTree T
 * \返回二叉树T的深度
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
 * \二叉树T存在
 * \参数 BiTree T
 * \返回二叉树T的根
 */
BiTPos Root(BiTree T)
{
	return T;
}

/*
 * \二叉树T存在,value为T中某结点的值
 * \参数 BiTree T,TElemType value,BiTPos e
 * \返回树中值为value的结点位置
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
 * \二叉树T存在
 * \参数 BiTree T,BiTPos e
 * \返回e的值
 */
TElemType Value(BiTree T, BiTPos e)
{
	return e->data;
}

/*
 * \二叉树T存在，e是T中某一结点
 * \参数 BiTree T,TiTPos e,TElemType value
 * \将value的值赋给结点e
 */
void Assign(BiTree T, BiTPos &e, TElemType value)
{
	e->data = value;
}

/*
 * \二叉树T存在，e是T中某一结点
 * \参数 BiTree T,BiTPos e,BiTPos &p
 * \若e是T的非根结点，则返回e的双亲，否则返回“空”
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
 * \二叉树T存在，e是T中某一结点
 * \参数 BiTree T,BiTPos e
 * \返回e的左孩子，若无左孩子则返回“空”
 */
BiTPos LeftChild(BiTree T, BiTPos e)
{
	if (!e->lchild)
		return NULL;

	return e->lchild;
}

/*
 * \二叉树T存在，e是T中某一结点
 * \参数 BiTree T,BiTPos e
 * \返回e的右孩子，若无右孩子则返回“空”
 */
BiTPos RightChild(BiTree T, BiTPos e)
{
	if (!e->rchild)
		return NULL;

	return e->rchild;
}

/*
 * \二叉树T存在，e是T中某一结点
 * \参数 BiTree T,BiTPos e
 * \返回e的左兄弟，若e是T左孩子或无左兄弟则返回“空”
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
 * \二叉树T存在，e是T中某一结点
 * \参数 BiTree T,BiTPos e
 * \返回e的右兄弟，若e是T右孩子或无右兄弟则返回“空”
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
 * \二叉树T存在，p指向T中某个结点，LR为0或1，非空二叉树c与T不相交，且右子树为空
 * \参数 BiTree T, BiTPos p, int LR, BiTree c
 * \根据LR为0或1，插入c为T中p所指结点的左子树或右子树，
 * \p所指结点的原有左子树或右子树则成为c右子树
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
 * \二叉树T存在，p指向T中某个结点，LR为0或1
 * \参数 BiTree T, BiTPos p, int LR
 * \根据LR为0或1，删除T中p所指结点的左子树或右子树
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
 *遍历
 *二叉树
 *实现
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
 * 先序
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
 * 中序
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
 * 后序
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
 * 层序
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
 *线索
 *二叉树
 *实现
 */

 /*
 *
 * 参数 BiThrTree T
 * 构造线索二叉树 T
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
 * 中序
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








