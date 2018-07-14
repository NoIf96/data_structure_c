#pragma once
#ifndef SQQUEUE_H_INCLUDED
#define SQQUEUE_H_INCLUDED

// 定义宏
#define MAXQSIZE 100     //空间初始化大小
#define STACKINCEMENT 10       //空间增加量

#define OVERFLOW -1
#define ERROR 0
#define OK 1
#define FALSE 0
#define TRUE 1

typedef int QElemType;
typedef int Status;

typedef struct {
	QElemType *base; 
	int front;
	int rear;
	int queuesize;
}SqQueue; 


#endif
