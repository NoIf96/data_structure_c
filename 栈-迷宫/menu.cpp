#include<stdio.h>
#include<stdlib.h>

#include "SqStack_oper.h"
#include "maze_oper.h"
#include "Menu.h"
#include "tool_base.h"

void S_E(int y,PosType &start,PosType &end,int map[map_x][map_y]) {
	Pos(0, y);
	printf("/为起点，#为终点");
	Pos(1, y);
	printf("请输入起点位置(x,y)：");
	scanf_s("%d %d", &start.x, &start.y);
	Pos(2, y);
	printf("请输入终点位置(x,y)：");
	scanf_s("%d %d", &end.x, &end.y);
	getchar();

	Pos(4, y);
	printf("回车后寻找路径");
	getchar();
	maze_map(map, start, end);
}

void Path(int x,int y,SqStack &S,int map[map_x][map_y]){
	int l;
	SElemType player;
	l = StackLength(S);
	for (int i = 0;i < l;i++) {
		Pop(S, player);
		Map_play(x, y, player.coord.x, player.coord.y, map);
	}
	
}

