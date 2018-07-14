#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include"tool_base.h"



/**************************************************************/
/*  定位工具  */
/*
 *    x行数，y列数   *
 */

//定位函数
void Pos(int x, int y) {

	HANDLE hout;
	COORD xy = { y,x };

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, xy);

}

//定位函数——x自增
void Posx(int &x, int y) {

	HANDLE hout;
	COORD xy = { y,x };

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, xy);
	x++;
}

//定位函数——y自增
void Posy(int x, int &y) {

	HANDLE hout;
	COORD xy = { y,x };

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, xy);
	y++;
}

/**************************************************************/

/**************************************************************/
/*表格制作工具*/
/*
 *  xy为起始坐标（行列）        *   
 *  Length 长度   Wide 宽度     *
 *  A横向边框符   B竖向边框符   *
 *  C分割线符号                 *
 *  times重复次数  h相隔距离    *
 */


//边框构建函数  xy为起始坐标  AB为边框符号
void Table_border(int x, int y, int Length, int Wide, char A, char B) {
	int i, j, k;

	for (i = 0;i < Wide;i++) {
		Posx(x, y);

		if (i == 0 || i == Wide - 1)
			for (k = 0;k < Length;k++)
				printf("%c", A);

		else {
			for (j = 0;j < Length;j++) {

				if (j == 0 || j == Length - 1)
					printf("%c", B);
				else
					printf(" ");
			}
		}
	}
}


//分割线构建函数  xy为起始坐标  C为边框符号
void Table_line(int x, int y, int Length, char C) {
	int i;

	Pos(x, y);
	for (i = 0;i < Length;i++)
		printf("%c", C);
}

//分割线构建函数（复数）  xy为起始坐标  C为边框符号  times为重复次数  h为每次重复相距行数
void Table_lines(int x, int y, int Length, char C, int times, int h) {
	int i, j;

	for (i = 0;i < times;i++) {
		Pos(x, y);
		for (j = 0;j < Length;j++)
			printf("%c", C);
		x += h;
	}
}

//表格底构建函数  xy为起始坐标  C为边框符号  Length位10以上值是可以使用
void Table_tail(int x, int y, int Length, char C)
{
	int i;

	Pos(x, y);
	for (i = 0;i < Length;i++) {
		if (i == (Length - 10) / 2) {
			printf("回车后继续");
			i += 10;
		}

			printf("%c", C);
	}
		getchar();
		getchar();
		system("cls");
}

/**************************************************************/

/**************************************************************/
/*地图制作工具*/
/*
*  xy为起始坐标（行列）        *
*  Length 长度   Wide 宽度     *
*  A横向边框符   B竖向边框符   *
*  C分割线符号                 *
*  times重复次数  h相隔距离    *
*/

//地图边界构建函数  xy为起始坐标  AB为边框符号
void Map_border(int x, int y, int Length, int Wide, int map_xy[map_x][map_y]) {
	int i, j, k;

	for (i = 0;i < Wide;i++) {
		Posx(x, y);
		
		if (i == 0 || i == Wide - 1)
			for (k = 0;k < Length;k++) {
				map_xy[i][k] = -1;
				printf("%c%c", 0xa8,0x80);
			}

		else {
			for (j = 0;j < Length;j++) {

				if (j == 0 || j == Length - 1) {
					map_xy[i][j] = -1;
					printf("%c%c", 0xa8, 0x80);
				}
				else
					printf("  ");
			}
		}
	}
}


//地图横线构建函数  xy为起始坐标  C为边框符号
void Map_line(int x, int y, int mx, int my, int Length, int map_xy[map_x][map_y]) {
	int i,lx,ly;
	
	lx = x + mx;
	ly = y + 2*my;

	Pos(lx, ly);
	for (i = 0;i < Length;i++) {
		map_xy[mx][my++] = -1;
		printf("%c%c", 0xa8, 0x80);
	}
}


//地图竖线构建函数  xy为起始坐标  C为边框符号
void Map_string(int x, int y, int mx, int my, int Length, int map_xy[map_x][map_y]) {
	int i, sx, sy;
	sx = x + mx;
	sy = y + 2*my;

	for (i = 0;i < Length;i++) {
		
		Posx(sx, sy);
		map_xy[mx++][my] = -1;
		printf("%c%c", 0xa8, 0x80);
	}
}


void Map_play(int x, int y, int mx, int my,int map_xy[map_x][map_y]) {
	int lx, ly;

	lx = x + mx;
	ly = y + 2 * my;

	Pos(lx, ly);
	printf("%2c", '*');
}
/**************************************************************/