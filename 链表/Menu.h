#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include"LinkList.h"

void intro();//���ܲ˵�

void Menu_StrList(LinkList &L);//׼���˵�
void Menu_test(LinkList &L);//���ܲ����Ӳ˵�

void test_attribute(LinkList L, Link &p);//�����Ӳ˵�
void test_position(LinkList L, Link &p);//λ���Ӳ˵�
void tset_insert(LinkList &L, Link &p);//�����Ӳ˵�
void test_delete(LinkList &L, Link &p);//ɾ���Ӳ˵�
void test_reset(LinkList &L, Link &p);//�����Ӳ˵�

void data_status(LinkList L, Link p);//����״��

void Border(int Length, int Wide,int x,int y,char A,char B);//�߿򹹽�����  xyΪ��ʼ����  ABΪ�߿����																
void Border_sub();//�߿������
void Border_tail();//�˵����ý�β����

void Pos(int x, int y);//��λ����
void Posx(int &x, int y);//��λ����x����

#endif