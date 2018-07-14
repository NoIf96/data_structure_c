#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include"tool_base.h"



/**************************************************************/
/*  ��λ����  */
/*
 *    x������y����   *
 */

//��λ����
void Pos(int x, int y) {

	HANDLE hout;
	COORD xy = { y,x };

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, xy);

}

//��λ��������x����
void Posx(int &x, int y) {

	HANDLE hout;
	COORD xy = { y,x };

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, xy);
	x++;
}

//��λ��������y����
void Posy(int x, int &y) {

	HANDLE hout;
	COORD xy = { y,x };

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, xy);
	y++;
}

/**************************************************************/

/**************************************************************/
/*�����������*/
/*
 *  xyΪ��ʼ���꣨���У�        *   
 *  Length ����   Wide ���     *
 *  A����߿��   B����߿��   *
 *  C�ָ��߷���                 *
 *  times�ظ�����  h�������    *
 */


//�߿򹹽�����  xyΪ��ʼ����  ABΪ�߿����
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


//�ָ��߹�������  xyΪ��ʼ����  CΪ�߿����
void Table_line(int x, int y, int Length, char C) {
	int i;

	Pos(x, y);
	for (i = 0;i < Length;i++)
		printf("%c", C);
}

//�ָ��߹���������������  xyΪ��ʼ����  CΪ�߿����  timesΪ�ظ�����  hΪÿ���ظ��������
void Table_lines(int x, int y, int Length, char C, int times, int h) {
	int i, j;

	for (i = 0;i < times;i++) {
		Pos(x, y);
		for (j = 0;j < Length;j++)
			printf("%c", C);
		x += h;
	}
}

//���׹�������  xyΪ��ʼ����  CΪ�߿����  Lengthλ10����ֵ�ǿ���ʹ��
void Table_tail(int x, int y, int Length, char C)
{
	int i;

	Pos(x, y);
	for (i = 0;i < Length;i++) {
		if (i == (Length - 10) / 2) {
			printf("�س������");
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
/*��ͼ��������*/
/*
*  xyΪ��ʼ���꣨���У�        *
*  Length ����   Wide ���     *
*  A����߿��   B����߿��   *
*  C�ָ��߷���                 *
*  times�ظ�����  h�������    *
*/

//��ͼ�߽繹������  xyΪ��ʼ����  ABΪ�߿����
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


//��ͼ���߹�������  xyΪ��ʼ����  CΪ�߿����
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


//��ͼ���߹�������  xyΪ��ʼ����  CΪ�߿����
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