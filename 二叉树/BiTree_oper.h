#pragma once
#ifndef BITREEOPER_H_INCLUDE
#define BITREEOPER_H_INCLUDE

#include "BiTree.h"

Status InitBiTree(BiTree &T);              //构造空二叉树T
void DestoryBiTree(BiTree &T);             //销毁二叉树T

Status CreateBiTree(BiTree &T);            //构造二叉树T

void ClearBiTree(BiTree &T);               //清空二叉树T
Status BiTreeEmpty(BiTree T);              //检测二叉树是否为空
void BiTreeDepth(BiTree T, int level, int &n);   //检测二叉树T的深度
BiTPos Root(BiTree T);                     //二叉树T的根
void BiNode_Pos(BiTree T, TElemType value,BiTPos &e);//返回树中值为value的结点位置
TElemType Value(BiTree T,BiTPos e);        //返回结点e的值
void Assign(BiTree T, BiTPos &e, TElemType value);  //修改结点e的值
void Parent(BiTree T, BiTPos e, BiTPos &p);         //求结点e的双亲
BiTPos LeftChild(BiTree T, BiTPos e);               //返回e的左孩子
BiTPos RightChild(BiTree T, BiTPos e);              //返回e的右孩子
BiTPos LeftSibling(BiTree T, BiTPos e);             //返回e的左兄弟
BiTPos RightSibling(BiTree T, BiTPos e);            //返回e的右兄弟
Status InsertChild(BiTree &T, BiTPos p, int LR, BiTree c);  //插入
Status DeleteChild(BiTree &T, BiTPos p, int LR);            //删除

/*
 *遍历
 *二叉树
 *实现
 */  

/*
 * Visit()
 */
Status PrintElement(TElemType e);

/*
 * 先序
 */
Status PreOrderTraverse(BiTree T,Status (*Visit)(TElemType e));

/*
 * 中序
 */
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

/*
 * 后序
 */
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e));

/*
 * 层序
 */
Status LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType e));



/*
 *线索
 *二叉树
 *实现
 */

 /*
 * 构造线索二叉树T
 */

Status CreateBiThrTree(BiThrTree & Thrt);

/*
 * 中序
 */
Status InOrderThreading(BiThrTree &Thrt, BiThrTree &T);
void InThreading(BiThrPos &p,BiThrPos &pre);
Status InOrderTraveres_Thr(BiThrTree Thrt, Status(*Visit)(TElemType e));
void DestoryBiThrTree(BiThrTree &Thrt, BiThrTree &T);


#endif // !BITREEOPER_H_INCLUDE



















