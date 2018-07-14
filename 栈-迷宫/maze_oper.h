#pragma once
#ifndef MAZEOPER_H_INCLUDED
#define MAZEOPER_H_INCLUDED

#include"tool_base.h"
#include"SqStack.h"

void maze_map(int map[map_x][map_y], PosType start, PosType end);
void MazePath(SqStack &S, int map[map_x][map_y], PosType start, PosType end);
int cmp(SElemType s, SElemType k);
void Re_Path(SqStack &S, SElemType k);
void Map_pr(int x, int y, PosType start, PosType end, int map[map_x][map_y]);
void barrier(int map[map_x][map_y], SElemType player);
int Stack_cross(PosType A, int map[map_x][map_y]);
#endif