#include <stdio.h>
#include "Queue.h"

#define ARR_LEN 20
#define ARR_LEN_M 10

void Print(int arr[]);
void Selection(int arr[]);
void Bubble(int arr[]);
void Insertion(int arr[]);
void Radix(int arr[]);
void Merge(int arr[], int, int, int);
void MergeSort(int arr[], int, int);
void QuickSort(int arr[], int, int);
void Bubble_Improved(int arr[]);

int main() {
	int arr1[ARR_LEN] = { 15,0,54,34,7,5,1,3,8,9,45,61,20,17,48,51,38,81,33,90 };
	int arr2[ARR_LEN] = { 15,0,54,34,7,5,1,3,8,9,45,61,20,17,48,51,38,81,33,90 };
	int arr3[ARR_LEN] = { 15,0,54,34,7,5,1,3,8,9,45,61,20,17,48,51,38,81,33,90 };
	int arr4[ARR_LEN] = { 15,0,54,34,7,5,1,3,8,9,45,61,20,17,48,51,38,81,33,90 };
	int arr5[ARR_LEN] = { 15,0,54,34,7,5,1,3,8,9,45,61,20,17,48,51,38,81,33,90 };
	int arr6[ARR_LEN] = { 15,0,54,34,7,5,1,3,8,9,45,61,20,17,48,51,38,81,33,90 };
	int arrRadix[ARR_LEN] = { 89, 10, 34, 50, 30, 28, 62, 38, 14, 56, 79, 51, 43, 98, 45, 12, 35, 81, 99, 13 };

	Selection(arr1); puts("");
	Bubble(arr2); puts("");
	Insertion(arr3); puts("");
	Radix(arrRadix); puts("");
	printf("병합 정렬 전 : "); Print(arr4);
	MergeSort(arr4, 0, ARR_LEN - 1); 
	printf("병합 정렬 후 : "); Print(arr4); puts("");
	printf("퀵 정렬 전 : "); Print(arr5);
	QuickSort(arr5, 0, ARR_LEN - 1); printf("퀵 정렬 후 : "); Print(arr5); puts("");
	Bubble_Improved(arr6);
}

void Print(int arr[]) {
	for (int i = 0; i < ARR_LEN; i++) {
		printf("%3d", arr[i]);
	}
	puts("");
}

void Selection(int arr[]) {
	int minidx, i, j;
	printf("선택 정렬 전 : "); Print(arr);
	for (i = 0; i < ARR_LEN; i++) {
		minidx = i;
		for (j = minidx; j < ARR_LEN; j++) {
			if (arr[minidx] > arr[j])
				minidx = j;

		}
		if (i != minidx) {
			int temp = arr[minidx];
			arr[minidx] = arr[i];
			arr[i] = temp;
		}
	}
	printf("선택 정렬 후 : "); Print(arr);
}

void Bubble(int arr[]) {
	int i, j, k = 0;
	printf("버블 정렬 전 : "); Print(arr);
	for (i = 0; i < ARR_LEN; i++) {
		for (j = 0; j < ARR_LEN - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("버블 정렬 후 : "); Print(arr);
}

void Bubble_Improved(int arr[]) {
	int i, j, k = 0;
	printf("개선 버블 정렬 전 : "); Print(arr);
	for (i = 0; i < ARR_LEN; i++) {
		int flg = 1;
		for (j = 0; j < ARR_LEN - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flg = 0;
			}
		}
		if (flg)
			break;
	}
	printf("개선 버블 정렬 후 : "); Print(arr);
}

void Insertion(int arr[]) {
	printf("삽입 정렬 전 : "); Print(arr);
	for (int i = 1; i < ARR_LEN; i++) {
		for (int j = i; j >= 1; j--) {
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
			else {
				break;
			}
		}
	}
	printf("삽입 정렬 후 : "); Print(arr);
}

void Radix(int arr[]) {
	Queue q0, q1, q2, q3, q4, q5, q6, q7, q8, q9;
	Queue* qlist[] = { &q0, &q1, &q2, &q3, &q4, &q5, &q6, &q7, &q8, &q9 };
	int i, j = 0;
	printf("기수 정렬 전 : "); Print(arr);
	for (i = 0; i < 10; i++)
		QueInit(qlist[i]);
	for (i = 0; i < ARR_LEN; i++)
		Enqueue(qlist[arr[i] % 10], arr[i]);
	for (i = 0; i < 10; i++) {
		for (; !isEmpty(qlist[i]); j++)
			arr[j] = Dequeue(qlist[i]);
	}
	j = 0;
	for (i = 0; i < ARR_LEN; i++)
		Enqueue(qlist[arr[i] / 10], arr[i]);
	for (i = 0; i < 10; i++) {
		for (; !isEmpty(qlist[i]); j++)
			arr[j] = Dequeue(qlist[i]);
	}
	printf("기수 정렬 후 : "); Print(arr);
}
int sorted[ARR_LEN];
void Merge(int arr[], int start, int mid, int end) {
	int i, j, k, l;
	i = start; j = mid + 1; k = start;
	while (i <= mid && j <= end) {
		if (arr[i] > arr[j])
			sorted[k++] = arr[j++];
		else
			sorted[k++] = arr[i++];
	}
	if (i > mid) {
		for (l = j; l <= end; l++)
			sorted[k++] = arr[l];
	}
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = arr[l];
	}
	for (l = start; l <= end; l++)
		arr[l] = sorted[l];
}

void MergeSort(int arr[], int start, int end) {
	int mid;
	
	if (end > start) {
		mid = (end + start) / 2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);
		Merge(arr, start, mid, end);
	}
}

void QuickSort(int arr[], int start, int end) {
	int pivot = start, i = start + 1, j = end, temp;
	if (start < end) {
		while (i <= j) {
			if (arr[pivot] < arr[i] && arr[pivot] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				i++;
				j--;
			}
			else if (arr[pivot] > arr[i] && arr[pivot] > arr[j])
				i++;
			else if (arr[pivot] < arr[i] && arr[pivot] < arr[j])
				j--;
			else if (arr[pivot] > arr[i] && arr[pivot] < arr[j]) {
				i++;
				j--;
			}
		}
	}
	temp = arr[pivot];
	arr[pivot] = arr[j];
	arr[j] = temp;
	if(start < j)
		QuickSort(arr, start, j - 1);
	if(i < end)
		QuickSort(arr, i, end);
}