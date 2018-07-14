#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"Menu.h"
#include"LinkList.h"

//介绍菜单
void intro() {
	int x = 5;

	Border(60, 18, 3, 25,'*','|');
	Posx(x, 38);
	printf("实验2 线性表在链式存储结构下的基本操作\n");
	Posx(++x, 26);
	printf("一、实验目的\n");
	Posx(x, 26);
	printf(" 1.掌握使用VC++上机调试线性表的基本方法；\n");
	Posx(x, 26);
	printf(" 2.掌握线性表的基本操作：插入、删除、查找等运算在\n");
	Posx(x, 26);
	printf(" 链式存储结构上的实现。\n");
	Posx(++x, 26);
	printf("二、实验内容\n");
	Posx(x, 26);
	printf(" 1.线性表在链式存储结构下的基本操作。\n");
	Posx(x, 26);
	printf(" 2.在此基础上实现头插法和尾插法创建单链表的算法。\n");
	Posx(x, 26);
	printf(" 3.对于每个单链表的基本操作和创建单链表算法，\n");
	Posx(x, 26);
	printf("   都必须输入不少于两组数据进行测试。");
	
	++x;
	Posx(++x, 73);
	printf("回车后开始\n");
	getchar();
	system("cls");
}

//准备菜单
void Menu_StrList(LinkList &L) {
	Link p;
	ElemType e;
	int sele,n;

	do {
		Border(50, 20, 0, 30, '*', '|');
		Pos(1, 48);
		printf("开始构造线性链表\n");
		Pos(2, 31);
		printf(" ----------------------------------------------\n");
		Pos(3, 38);
		printf("1.头插法      2.尾插法      3.退出\n");
		Pos(4, 31);
		printf(" ----------------------------------------------\n");
		Pos(5, 32);
		printf("请选择功能（1-3）：");
		scanf_s("%d", &sele);
		Pos(6, 31);
		printf(" ----------------------------------------------\n");

		switch (sele)
		{
			//头插法
		case 1:
			Pos(7, 32);
			printf("请输入要数据元素数量：");
			scanf_s("%d", &n);

			Pos(8, 32);
			printf("L:");
			for (int i = 1;i <= n;i++) {
				scanf_s("%d", &e);
				MakeNode(p, e);
				InsFirst(L,L.head, p);
			}

			Pos(17, 31);
			printf(" ------------------回车后继续------------------ \n");
			getchar();
			getchar();
			system("cls");
			Menu_test(L);
			
			break;

			//尾插法
		case 2:
			Pos(7, 32);
			printf("请输入要数据元素数量：");
			scanf_s("%d", &n);

			Pos(8, 32);
			printf("L:");
			for (int i = 1;i <= 5;i++) {
				scanf_s("%d", &e);
				MakeNode(p, e);
				Append(L, p);
			}

			Pos(17, 31);
			printf(" ------------------回车后继续------------------ \n");
			getchar();
			getchar();
			system("cls");
			Menu_test(L);

			break;

			//退出
		case 3:
			e = 0;
			MakeNode(p, e);
			Append(L, p);

			Pos(11, 51);
			printf("退出测试\n");
			Pos(17, 31);
			printf(" ------------------回车后退出------------------ \n\n\n\n");

			break;

		default:
			Pos(11, 49);
			printf("请正确选择！！！\n");
			Pos(17, 31);
			printf(" ------------------回车后继续------------------ \n");
			getchar();
			getchar();
			system("cls");

			break;
		}

	} while (sele != 3);

	
}

//功能测试子菜单
void Menu_test(LinkList &L) {
	Link p;
	int sele;
	p = NULL;

	do {
		Border(70, 20, 0, 20, '*', '|');     //构建边框
		Border_sub();
		//构建菜单
		Pos(1, 54);       
		printf("测试\n");
		Pos(3, 25);
		printf("1.属性     2.位置     3.插入     4.删除     5.重置     6.返回\n");
		
		data_status(L, p);

		Pos(5, 22);
		printf("请选择功能（1-5）：");                         //功能选择
		scanf_s("%d", &sele);                

		//功能选择模块
		switch (sele)
		{
			//属性
		case 1:
			Border_tail();
			test_attribute(L, p);
			break;

			//位置
		case 2:
			Border_tail();
			test_position(L, p);
			break;

			//插入
		case 3:
			Border_tail();
			tset_insert(L, p);
			break;

			//删除
		case 4:

			Border_tail();
			test_delete(L, p);
			break;

			//重置
		case 5:
			Border_tail();
			test_reset(L, p);
			break;

			//返回
		case 6:
			Pos(14, 51);
			printf("返回构建\n");
			

			Border_tail();

			break;

		default:
			Pos(14, 49);
			printf("请正确选择！！！\n");
			

			Border_tail();

			break;
		}
	} while (sele != 6);
}

//属性子菜单
void test_attribute(LinkList L, Link &p) {
	int sele, length;
	ElemType e;

	do {
		Border(70, 20, 0, 20, '*', '|');
		Border_sub();

		Pos(1, 54);
		printf("属性\n");
		Pos(3, 25);
		printf("1.空检测     2.元素数      3.访问器      4.修改器      5.返回\n");

		data_status(L, p);

		Pos(5, 22);
		printf("请选择功能（1-5）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
			//空检测
		case 1:
			Pos(12, 22);
			printf("调用LinstElem\n");
			Pos(13, 22);
			if (ListEmpty(L))
				printf("L为空表\n");
			else
				printf("L不为空\n");

			Border_tail();

			break;

			//元素数
		case 2:
			Pos(12, 22);
			printf("调用ListLength\n");
			Pos(13, 22);
			length = ListLength(L);
			printf("L共有%d个元素\n", length);

			Border_tail();

			break;

			//访问器
		case 3:
			Pos(12, 22);
			printf("调用GetCurElem\n");
			Pos(13, 22);
			if (p)
				printf("工作指针p所指的元素是%d\n",GetCurElem(p));
			else
				printf("工作指针p非法\n");

			Border_tail();

			break;

			//修改器
		case 4:
			Pos(12, 22);
			printf("调用SetCurElem\n");
			Pos(13, 22);
			if (p) {
				printf("请输入p所指的元素新值：");
				scanf_s("%d", &e);
				SetCurElem(p, e);
				printf("修改完毕，现工作指针p所指的元素是%d\n", GetCurElem(p));
			}
			else
				printf("工作指针p非法\n");
			Border_tail();

			break;

			//返回
		case 5:
			
			Border_tail();
			
			break;

		default:
			Pos(14, 49);
			printf("请正确选择！！！\n");
			
			Border_tail();

			break;
		}
	} while (sele != 5);

}
//位置子菜单
void test_position(LinkList L, Link &p) {
	int sele, i;
	Position x;
	ElemType e;

	x = NULL;

	do {
		Border(70, 20, 0, 20, '*', '|');
		Border_sub();

		Pos(1, 54);
		printf("位置\n");
		Pos(3, 25);
		printf("1.头结点     2.尾结点      3.i结点      4.特定结点     5.返回\n");
	
		data_status(L, p);

		Pos(5, 22);
		printf("请选择功能（1-5）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
			//头结点
		case 1:
			Pos(12, 22);
			printf("调用GetHead\n");
			Pos(13, 22);
			p = GetHead(L);
			printf("L的头结点地址以赋予p\n");
			
			Border_tail();

			break;

			//尾结点
		case 2:
			Pos(12, 22);
			printf("调用GetLast\n");
			Pos(13, 22);
			p = GetLast(L);
			printf("L的尾结点地址以赋予p\n");

			Border_tail();

			break;

			//i结点
		case 3:
			Pos(12, 22);
			printf("调用LocatePos\n");
			Pos(13, 22);
			printf("请输入特定元素位序：");
			scanf_s("%d", &i);
			Pos(14, 22);
			if (LocatePos(L, i, p))
				printf("L中特定元素位序结点地址以赋予p\n");
			else
				printf("输入位序非法\n");

			Border_tail();

			break;

			//特定结点
		case 4:
			Pos(12, 22);
			printf("调用LocateElem\n");
			Pos(13, 22);
			printf("请输入特定元素：");
			scanf_s("%d", &e);
			Pos(14, 22);
			if (p = LocateElem(L, e, compare))
				printf("L中特定元素地址以赋予p\n");
			else
				printf("输入元素不存在\n");


			Border_tail();

			break;

			//返回
		case 5:
		
			Border_tail();

			break;

		default:
			Pos(14, 49);
			printf("请正确选择！！！\n");

			Border_tail();

			break;
		}
	} while (sele != 5);

}
//插入子菜单
void tset_insert(LinkList &L, Link &p) {
	int sele;
	Link q;
	ElemType e;

	do {
		Border(70, 20, 0, 20, '*', '|');
		Border_sub();

		Pos(1, 54);
		printf("插入\n");
		Pos(3, 25);
		printf("1.头插法     2.尾插法      3.p结点前      4.p结点后     5.返回\n");

		data_status(L, p);

		Pos(5, 22);
		printf("请选择功能（1-5）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
			//头插法
		case 1:
			Pos(12, 22);
			printf("调用InsFirst\n");
			Pos(13, 22);
			printf("插入元素：");
			scanf_s("%d", &e);
			MakeNode(q, e);
			InsFirst(L, L.head, q);
			
			Border_tail();

			break;

			//尾插法
		case 2:
			Pos(12, 22);
			printf("调用Append\n");
			Pos(13, 22);
			printf("插入元素：");
			scanf_s("%d", &e);
			MakeNode(q, e);
			Append(L, q);

			Border_tail();

			break;

			//p结点前
		case 3:
			Pos(12, 22);
			printf("调用InsBefore\n");
			Pos(13, 22);
			if (p)
			{
				printf("插入元素：");
				scanf_s("%d", &e);
				MakeNode(q, e);
				InsBefore(L, p, q);
				Pos(14, 22);
				printf("插入成功\n");
			}
			else
				printf("插入地址非法\n");

			Border_tail();

			break;

			//p结点后
		case 4:
			Pos(12, 22);
			printf("调用InsAfter\n");
			Pos(13, 22);
			if (p)
			{
				printf("插入元素：");
				scanf_s("%d", &e);
				MakeNode(q, e);
				InsAfter(L, p, q);
				Pos(14, 22);
				printf("插入成功\n");
			}
			else
				printf("插入地址非法\n");


			Border_tail();

			break;

			//返回
		case 5:

			Border_tail();

			break;

		default:
			Pos(14, 49);
			printf("请正确选择！！！\n");

			Border_tail();

			break;
		}
	} while (sele != 5);

}
//删除子菜单
void test_delete(LinkList &L, Link &p) {
	int sele;
	Link q;

	do {
		Border(70, 20, 0, 20, '*', '|');
		Border_sub();
		Pos(1, 54);
		printf("删除\n");
		Pos(3, 25);
		printf("1.删除第一个结点      2.删除尾结点      3.删除p结点      4.返回\n");

		data_status(L, p);

		Pos(5, 22);
		printf("请选择功能（1-4）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
			//删除第一个结点
		case 1:
			Pos(12, 22);
			printf("调用DelFirst\n");
			Pos(13, 22);
			DelFirst(L, L.head, q);
			FreeNode(q);
			printf("删除成功\n");
			Border_tail();

			break;

			//删除尾结点
		case 2:
			Pos(12, 22);
			printf("调用Remove\n");
			Pos(13, 22);
			Remove(L, L.head);
			printf("删除成功\n");

			Border_tail();

			break;

			//删除p结点
		case 3:
			Pos(12, 22);
			printf("调用Delp\n");
			Pos(13, 22);
			if (p)
			{
				Delp(L, p);
				printf("删除成功\n");
			}
			else
				printf("删除地址非法\n");

			Border_tail();

			break;

			//返回
		case 4:

			Border_tail();

			break;

		default:
			Pos(14, 49);
			printf("请正确选择！！！\n");

			Border_tail();

			break;
		}
	} while (sele != 4);

}
//重置子菜单
void test_reset(LinkList &L, Link &p) {
	int sele;

	do {
		Border(70, 20, 0, 20, '*', '|');
		Border_sub();

		Pos(1, 54);
		printf("重置\n");
		Pos(3, 25);
		printf("1.重置链表            2.重置工作指针p            3.返回\n");

		data_status(L, p);

		Pos(5, 22);
		printf("请选择功能（1-3）：");
		scanf_s("%d", &sele);

		switch (sele)
		{
			//重置链表
		case 1:
			Pos(12, 22);
			printf("调用ClearList\n");
			Pos(13, 22);
			ClearList(L);
			printf("重置完毕\n");
			Border_tail();

			break;

			//重置工作指针p
		case 2:
			Pos(12, 22);
			p = NULL;
			printf("重置成功\n");

			Border_tail();

			break;

			//返回
		case 3:

			Border_tail();

			break;

		default:
			Pos(14, 49);
			printf("请正确选择！！！\n");

			Border_tail();

			break;
		}
	} while (sele != 3);
}

//数据状况
void data_status(LinkList L, Link p) {
	ElemType pe;

	Pos(7, 22);
	printf("当前数据状况：\n");
	Pos(9, 22);
	printf("线性链表L：");
	ListTraverse(L, visit);
	Pos(10, 22);
	printf("工作指针p：");
	if (p) {
		if (p == L.head)
			printf("头结点");
		else {
			pe = GetCurElem(p);
			printf("%d", pe);
		}
	}
	else
		printf("NULL\n");
}

//边框构建函数  xy为起始坐标  AB为边框符号
void Border(int Length, int Wide,int x,int y,char A,char B) {
	int i, j, k;
	for (i = 0;i < Wide;i++) {
		//首行和尾行
		Pos(x++, y);
		if (i == 0 || i == Wide - 1)
			for (k = 0;k < Length;k++)
				printf("%c",A);
		
		else {
			for (j = 0;j < Length;j++) {
				//边界
				if (j == 0 || j == Length - 1)
					printf("%c",B);
				else
				printf(" ");
			}
		}

		printf("\n");
	}


}

//边框分栏线
void Border_sub() {
	Pos(2, 21);
	printf(" ------------------------------------------------------------------\n");
	Pos(4, 21);
	printf(" ------------------------------------------------------------------\n");
	Pos(6, 21);
	printf(" ------------------------------------------------------------------\n");
	Pos(11, 21);
	printf(" ------------------------------------------------------------------\n");
}

//菜单调用结尾函数
void Border_tail()
{
	Pos(17, 21);
	printf(" ----------------------------回车后继续---------------------------- \n");
	getchar();
	getchar();
	system("cls");
}

//定位函数
void Pos(int x, int y)
{

	HANDLE hout;
	COORD xy = { y,x };

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, xy);

}

//定位函数x自增
void Posx(int &x, int y)
{

	HANDLE hout;
	COORD xy = { y,x };

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, xy);
	x++;

}
