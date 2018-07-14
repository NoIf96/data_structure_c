#include<stdio.h>
#include<stdlib.h>

#include"SqStack.h"
#include"SqStack_oper.h"
#include"maze_oper.h"
#include"tool_base.h"

void maze_map(int map[map_x][map_y],PosType start,PosType end) {
	int x, y;
	x = 7;
	y = 35;

	Map_border(x, y, map_x, map_y, map);
	Map_string(x, y, 1, 3, 2, map);
	Map_string(x, y, 1, 7, 2, map);
	Map_string(x, y, 4, 4, 2, map);
	Map_string(x, y, 6, 2, 2, map);
	Map_string(x, y, 6, 6, 2, map);
	Map_line(x, y, 3, 5, 2, map);
	Map_line(x, y, 4, 2, 2, map);
	Map_line(x, y, 7, 3, 2, map);
	Map_line(x, y, 7, 6, 2, map);
	Map_line(x, y, 8, 1, 1, map);
	Pos(x + start.x, y + 2 * start.y);
	printf("/");
	Pos(x + end.x, y + 2 * end.y);
	printf("#");
}



void MazePath(SqStack &S,int map[map_x][map_y],PosType start,PosType end) {
	
	SqStack K;
	SElemType player;
	
	InitStack(K);

	player.coord = start;
	player.di = 2;

	int x = 0;

	do {
		

		if (Stack_cross(player.coord, map)) {
			Push(K, player);
		}

		switch (player.di)
		{
		case 2://向下
			if (map[player.coord.x + 1][player.coord.y] == 0) {
				x = 0;
				player.coord.x++;
				map[player.coord.x][player.coord.y] = 5;
				Push(S, player);
			}
			else {
				if (x == 4) {
					x = 0;
					Pop(K, player);
					Re_Path(S, player);
					Push(S, player);

					barrier(map, player);
				}
				x++;
				player.di = 4;
			}
			

			break;

		case 4://向左
			if (map[player.coord.x][player.coord.y-1] == 0) {
				x = 0;
				player.coord.y--;
				map[player.coord.x][player.coord.y] = 5;
				Push(S, player);
			}
			else {
				if (x == 4) {
					x = 0;
					Pop(K, player);
					Re_Path(S, player);
					Push(S, player);

					barrier(map, player);
				}
				x++;
				player.di = 8;
			}

			break;

		case 8://向上
			if (map[player.coord.x - 1][player.coord.y] == 0) {
				x = 0;
				player.coord.x--;
				map[player.coord.x][player.coord.y] = 5;
				Push(S, player);		
			}
			else {
				if (x == 4) {
					x = 0;
					Pop(K, player);
					Re_Path(S, player);
					Push(S, player);

					barrier(map, player);
				}
				x++;
				player.di = 6;
			}
			
			break;

		case 6://向右
			if (map[player.coord.x][player.coord.y + 1] == 0) {
				x = 0;
				player.coord.y++;
				map[player.coord.x][player.coord.y] = 5;
				Push(S, player);
			}
			else
			{
				if (x == 4) {
					x = 0;
					Pop(K, player);
					Re_Path(S, player);
					Push(S, player);

					barrier(map, player);
				}
				x++;
				player.di = 2;
			}
			break;

		default:
			break;
		}

	} while (player.coord.x != end.x || player.coord.y != end.y);

}

void Re_Path(SqStack &S, SElemType k) {
	SElemType e;
	Pop(S, e);
	while (!(cmp(e, k))) 
		Pop(S, e);

	
}

int Stack_cross(PosType A,int map[map_x][map_y] ) {
	int x = 0;

	if (map[A.x + 1][A.y] == 0)
		x++;
	if (map[A.x - 1][A.y] == 0)
		x++;
	if (map[A.x][A.y + 1] == 0)
		x++;
	if (map[A.x][A.y - 1] == 0)
		x++;

	if (x > 1)
		return 1;

	return 0;
}

void Map_pr(int x, int y, PosType start, PosType end,int map[map_x][map_y]) {
	int n = x;

	Pos(x - 1, y);
	for (int i = 0; i < 10;i++) {
		printf("%2d", i);
	}

	for (int j = 0;j < 10;j++) {
		Posx(n, y - 2);
		printf("%d", j);

	}
	maze_map(map, start, end);

}

int cmp(SElemType s, SElemType k) {
	if (s.coord.x == k.coord.x && s.coord.y == k.coord.y)
		return 1;

	return 0;
}

void barrier(int map[map_x][map_y], SElemType player) {

	switch (player.di)
	{
	case 2://向下
		

        if (map[player.coord.x + 1][player.coord.y] != -1)
					map[player.coord.x + 1][player.coord.y] = 4;
			
		


		break;

	case 4://向左
		
				
		if (map[player.coord.x][player.coord.y - 1] != -1)
			map[player.coord.x][player.coord.y - 1] = 4;

		break;

	case 8://向上
		
				if (map[player.coord.x - 1][player.coord.y] != -1)
					map[player.coord.x - 1][player.coord.y] = 4;

		break;

	case 6://向右
	
				if (map[player.coord.x][player.coord.y + 1] != -1)
					map[player.coord.x][player.coord.y + 1] = 4;

		break;

	default:
		break;
	}

}


