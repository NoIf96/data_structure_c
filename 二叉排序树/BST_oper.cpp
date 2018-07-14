#include <stdio.h>
#include <stdlib.h>
#include "BST_oper.h"


/*
 *  T 为二叉排序树              *
 *  p 为查找成功结点，          *
 *    失败则为查找最后一个结点  *
 *  f 指向T双亲                 *
 *  key 关键字数据              *
 */
Status SearchBST(BSTree T, KeyType key, BSTPos f, BSTPos & p)
{
	if (!T) {                      //如果T为空则查找失败，并返回FALSE
		p = f;
		return FALSE;
	}

	else if (key == T->data.key)   //关键字匹配成功，查找成功，并返回TRUE
	{
		p = T;
		return TRUE;
	}

	else if (key < T->data.key)   //关键字key小于结点关键字查找其左子树
		return SearchBST(T->lchild, key, T, p);

	else                          //关键字key大于结点关键字查找其右子树
		return SearchBST(T->rchild, key, T, p);
}

/*
 *  T 为二叉排序树              *
 *  e 二叉排序树data域          *
 */
Status InsertBST(BSTree &T, ElemType e) {
	BSTree s;                 //插入结点
	BSTPos p;                 //查找位置结点

	if (!SearchBST(T, e.key, NULL, p))  //关键字结点原树中不存在
	{
		// 构建结点s
		if (!(s = (BiTNode *)malloc(sizeof(BiTNode))))   //为结点分配空间
			exit(OVERFLOW);
		s->data = e;                                     
		s->lchild = s->rchild = NULL;

		//当结点p为空，说明该二叉排序树不存在，s结点为其第一个结点
		if (!p)
			T = s;
		
		//判断s结点应插入p的哪一个子树
		else if (e.key < p->data.key)
			p->lchild = s;

		else
			p->rchild = s;

		return TRUE;
	}

	else
		return FALSE;
}

/*
 *  T 为二叉排序树              *
 *  key 关键字                  *
 */
Status DeleteBST(BSTree & T, KeyType key)
{
	if (!T)                     //不存在关键字为key的结点
		return FALSE;

	else {
		//匹配到关键字结点，删除该结点
		if (key == T->data.key) {   
			DeleteNode(T);
			return TRUE;
		}

		//未匹配到关键字结点，依据当前结点关键字值判断检测子树
		else if (key < T->data.key)
			return DeleteBST(T->lchild, key);

		else
			return DeleteBST(T->rchild, key);
	}
}

void DeleteNode(BSTree & p)
{
	BSTPos q,s;                    //辅助工作用结点指针

	if (!p->rchild) {              //如果只有左子树
		q = p;
		p = p->lchild;             //移动左子树
		free(q);
	}

	else if (!p->lchild) {         //如果只有右子树
		q = p;
		p = p->rchild;             //移动右子树
		free(q);
	}

	else{                          //左右子树都有
		q = p; 
		s = p->lchild;
		while (s->rchild) {
			q = s;
			s = s->rchild;
		}
		p->data = s->data;

		if (q != p)
			q->rchild = s->lchild;

		else
			q->lchild = s->lchild;

		free(s);
	}
}

void DestoryBSTree(BSTree & T)
{

	if (T) {

		DestoryBSTree(T->lchild);
		DestoryBSTree(T->rchild);

		free(T);
		T = NULL;

	}
}

/*              
 * *Visit()     *
 */
Status PrintElement(ElemType e)
{
	printf("%d ", e.key);
	return OK;
}

/*
 * 中序   *
 */
Status InOrderTraverse(BSTree T, Status(*Visit)(ElemType e))
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
