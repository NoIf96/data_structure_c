#pragma once
#ifndef SQSTACK_H_INCLUDED
#define SQSTACK_H_INCLUDED

// 定义宏
#define STACK_INIT_SIZE 100     //空间初始化大小
#define STACKINCEMENT 10       //空间增加量

#define  TRUE        1
#define  FALSE       0
#define  OK          1
#define  ERROR       0
#define  INFEASIBLE -1
#define  OVERFLOW    2


typedef int Status;

//坐标
typedef struct {
	int x;
	int y;
}PosType;

//位置信息
typedef struct {
	PosType coord;   //坐标
	int di;          //方向
}SElemType;

//栈
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;





#endif
