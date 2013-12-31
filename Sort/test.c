#include  <stdio.h>
#include  <string.h>
#include  "sort.h"

#define     SIZE	4

void Print(int A[]); 
int compare(const void *a, const void *b);

int main(void) 
{
	int A[SIZE];
	int i;
	for (i = 0; i < 4; i++) {
		scanf("%d", &A[i]);
		getchar();
	}
	
	Print(A);
	//InsertionSortAllType(A, SIZE, sizeof(char), compare);
	//MergeSort(A, 0, SIZE - 1);
	//BubbleSort(A, SIZE);
	//QuickSort(A, 0, 7);
	//InsertionSortAllType(A, 8, sizeof(int), compare);
	//CountSort(A, SIZE, 8);
	BaseSortBin(A, 4, 12, 3);
	Print(A);
	return 0;
}

void Print(int A[]) 
{
	int i;
	for (i = 0; i < SIZE; i++)
	  printf("%d ", A[i]);
	printf("\n");
}

int compare(const void *a, const void *b)
{
	if(*(char*)a > *(char*)b)
	  return 1;
	else if (*(char*)a == *(char*)b)
	  return 0;
	else
	  return -1;
}
