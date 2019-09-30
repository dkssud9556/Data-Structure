#include "Queue.h"
#include <stdio.h>
#include <Windows.h>

int NextPos(int pos) {
	if (pos == LEN - 1)
		return 0;
	return pos + 1;
}

void QueInit(Queue* pq) {
	pq->front = 0;
	pq->rear = 0;
	pq->numofdata = 0;
}

void Enqueue(Queue* pq, Data data) {
	if (isFull(pq)) {
		printf("Queue is Full");
		exit(1);
	}
	pq->rear = NextPos(pq->rear);
	pq->QueArr[pq->rear] = data;
	(pq->numofdata)++;
}

Data Dequeue(Queue* pq) {
	if (isEmpty(pq)) {
		printf("Queue is Empty");
		exit(1);
	}
	pq->front = NextPos(pq->front);
	(pq->numofdata)--;
	return pq->QueArr[pq->front];
}

int isEmpty(Queue* pq) {
	return !(pq->numofdata);
}

int isFull(Queue* pq) {
	if (pq->numofdata == LEN)
		return 1;
	return 0;
}