#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"Menu.h"
#include"LinkList.h"

int main(void) {
	LinkList L;

	InitList(L);

	intro();
	Menu_StrList(L);
	
	DestroyList(L);

	return 0;
}

