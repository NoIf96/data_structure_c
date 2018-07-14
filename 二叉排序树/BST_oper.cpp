#include <stdio.h>
#include <stdlib.h>
#include "BST_oper.h"


/*
 *  T Ϊ����������              *
 *  p Ϊ���ҳɹ���㣬          *
 *    ʧ����Ϊ�������һ�����  *
 *  f ָ��T˫��                 *
 *  key �ؼ�������              *
 */
Status SearchBST(BSTree T, KeyType key, BSTPos f, BSTPos & p)
{
	if (!T) {                      //���TΪ�������ʧ�ܣ�������FALSE
		p = f;
		return FALSE;
	}

	else if (key == T->data.key)   //�ؼ���ƥ��ɹ������ҳɹ���������TRUE
	{
		p = T;
		return TRUE;
	}

	else if (key < T->data.key)   //�ؼ���keyС�ڽ��ؼ��ֲ�����������
		return SearchBST(T->lchild, key, T, p);

	else                          //�ؼ���key���ڽ��ؼ��ֲ�����������
		return SearchBST(T->rchild, key, T, p);
}

/*
 *  T Ϊ����������              *
 *  e ����������data��          *
 */
Status InsertBST(BSTree &T, ElemType e) {
	BSTree s;                 //������
	BSTPos p;                 //����λ�ý��

	if (!SearchBST(T, e.key, NULL, p))  //�ؼ��ֽ��ԭ���в�����
	{
		// �������s
		if (!(s = (BiTNode *)malloc(sizeof(BiTNode))))   //Ϊ������ռ�
			exit(OVERFLOW);
		s->data = e;                                     
		s->lchild = s->rchild = NULL;

		//�����pΪ�գ�˵���ö��������������ڣ�s���Ϊ���һ�����
		if (!p)
			T = s;
		
		//�ж�s���Ӧ����p����һ������
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
 *  T Ϊ����������              *
 *  key �ؼ���                  *
 */
Status DeleteBST(BSTree & T, KeyType key)
{
	if (!T)                     //�����ڹؼ���Ϊkey�Ľ��
		return FALSE;

	else {
		//ƥ�䵽�ؼ��ֽ�㣬ɾ���ý��
		if (key == T->data.key) {   
			DeleteNode(T);
			return TRUE;
		}

		//δƥ�䵽�ؼ��ֽ�㣬���ݵ�ǰ���ؼ���ֵ�жϼ������
		else if (key < T->data.key)
			return DeleteBST(T->lchild, key);

		else
			return DeleteBST(T->rchild, key);
	}
}

void DeleteNode(BSTree & p)
{
	BSTPos q,s;                    //���������ý��ָ��

	if (!p->rchild) {              //���ֻ��������
		q = p;
		p = p->lchild;             //�ƶ�������
		free(q);
	}

	else if (!p->lchild) {         //���ֻ��������
		q = p;
		p = p->rchild;             //�ƶ�������
		free(q);
	}

	else{                          //������������
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
 * ����   *
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
