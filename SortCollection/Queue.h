#pragma once

typedef int Data;

#define LEN 100

typedef struct _cqueue {
	Data QueArr[LEN];
	int front;
	int rear;
	int numofdata;
} CQueue;

typedef CQueue Queue;

void QueInit(Queue*);
void Enqueue(Queue*, Data);
Data Dequeue(Queue*);
int isEmpty(Queue*);
int isFull(Queue*);