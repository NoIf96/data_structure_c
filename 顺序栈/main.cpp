#include<stdio.h>
#include<stdlib.h>
#include "Menu.h"
#include "SqStack_oper.h"

int main(void) {
	SqStack S;

	S.stacksize = 0;

	intro();
	Menu_test(S);

	return 0;
}