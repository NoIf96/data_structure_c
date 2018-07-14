#pragma once
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


void S_E(int y, PosType &start, PosType &end, int map[map_x][map_y]);
void Path(int x, int y, SqStack &S, int map[map_x][map_y]);

#endif