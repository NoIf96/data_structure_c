#pragma once
#ifndef TOOLBASE_H_INCLUDED
#define TOOLBASE_H_INCLUDED

#define map_x 10
#define map_y 10


/**************************************************************/
/*  定位工具  */
//x行数，y列数

//定位函数
void Pos(int x, int y);

//定位函数——x自增
void Posx(int &x, int y);

//定位函数——y自增
void Posy(int x, int &y);
/**************************************************************/

/**************************************************************/
/*表格制作工具*/
/*
*  xy为起始坐标（行列）        *
*  Length 长度   Wide 宽度     *
*  A横向边框符   B竖向边框符   *
*  C分割线符号                 *
*/


//边框构建函数  xy为起始坐标  AB为边框符号
void Table_border(int x, int y, int Length, int Wide, char A, char B);

//分割线构建函数  xy为起始坐标  C为边框符号
void Table_line(int x, int y, int Length, char C);

//分割线构建函数（复数）  xy为起始坐标  C为边框符号  times为重复次数  h为每次重复相距行数
void Table_lines(int x, int y, int Length, char C, int times, int h);

//表格底构建函数  xy为起始坐标  C为边框符号  Length位10以上值是可以使用
void Table_tail(int x, int y, int Length, char C);
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
void Map_border(int x, int y, int Length, int Wide, int map_xy[map_x][map_y]);

//地图横线构建函数  xy为起始坐标  C为边框符号
void Map_line(int tx, int bs, int x, int y, int Length, int map_xy[map_x][map_y]);

//地图竖线构建函数  xy为起始坐标  C为边框符号
void Map_string(int tx, int bs, int x, int y, int Length, int map_xy[map_x][map_y]);
void Map_play(int tx, int bs, int x, int y, int map_xy[map_x][map_y]);
//void M_m(int x, int y, int map[map_x][map_y]);
/**************************************************************/

#endif