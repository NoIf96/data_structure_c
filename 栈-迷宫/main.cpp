#include<stdio.h>
#include<stdlib.h>
#include "SqStack_oper.h"
#include "maze_oper.h"
#include "Menu.h"

int main(void) {
	SqStack S;
	PosType start, end;
	int x, y;
	int map[10][10] = { 0 };
	start = { 1,1 };
	end = { 8,8 };
	x = 7;
	y = 35;



	InitStack(S);

	Map_pr(x, y, start, end, map);
	S_E(y, start, end, map);
	MazePath(S, map, start, end);
	maze_map(map, start, end);
	Path(x, y, S,map);
	
	
	Pos(x + end.x, y + 2 * end.y);
	printf("%2c", '#');
	
	
	Pos(20, 0);
	getchar();
	return 0;
}

