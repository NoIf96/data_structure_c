#pragma once
#ifndef BITREEOPER_H_INCLUDE
#define BITREEOPER_H_INCLUDE

#include "BiTree.h"

Status InitBiTree(BiTree &T);              //����ն�����T
void DestoryBiTree(BiTree &T);             //���ٶ�����T

Status CreateBiTree(BiTree &T);            //���������T

void ClearBiTree(BiTree &T);               //��ն�����T
Status BiTreeEmpty(BiTree T);              //���������Ƿ�Ϊ��
void BiTreeDepth(BiTree T, int level, int &n);   //��������T�����
BiTPos Root(BiTree T);                     //������T�ĸ�
void BiNode_Pos(BiTree T, TElemType value,BiTPos &e);//��������ֵΪvalue�Ľ��λ��
TElemType Value(BiTree T,BiTPos e);        //���ؽ��e��ֵ
void Assign(BiTree T, BiTPos &e, TElemType value);  //�޸Ľ��e��ֵ
void Parent(BiTree T, BiTPos e, BiTPos &p);         //����e��˫��
BiTPos LeftChild(BiTree T, BiTPos e);               //����e������
BiTPos RightChild(BiTree T, BiTPos e);              //����e���Һ���
BiTPos LeftSibling(BiTree T, BiTPos e);             //����e�����ֵ�
BiTPos RightSibling(BiTree T, BiTPos e);            //����e�����ֵ�
Status InsertChild(BiTree &T, BiTPos p, int LR, BiTree c);  //����
Status DeleteChild(BiTree &T, BiTPos p, int LR);            //ɾ��

/*
 *����
 *������
 *ʵ��
 */  

/*
 * Visit()
 */
Status PrintElement(TElemType e);

/*
 * ����
 */
Status PreOrderTraverse(BiTree T,Status (*Visit)(TElemType e));

/*
 * ����
 */
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

/*
 * ����
 */
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

/*
 * ����
 */
Status LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType e));



/*
 *����
 *������
 *ʵ��
 */

 /*
 * ��������������T
 */

Status CreateBiThrTree(BiThrTree & Thrt);

/*
 * ����
 */
Status InOrderThreading(BiThrTree &Thrt, BiThrTree &T);
void InThreading(BiThrPos &p,BiThrPos &pre);
Status InOrderTraveres_Thr(BiThrTree Thrt, Status(*Visit)(TElemType e));
void DestoryBiThrTree(BiThrTree &Thrt, BiThrTree &T);


#endif // !BITREEOPER_H_INCLUDE



















