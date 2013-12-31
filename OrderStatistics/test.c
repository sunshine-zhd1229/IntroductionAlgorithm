#include  <stdio.h>
#include  <string.h>
#include  "order.h"

#define     SIZE	8

void Print(int A[]); 
int compare(const void *a, const void *b);

int main(void) 
{
	int A[SIZE];
	int i, index = 7;
	for (i = 0; i < SIZE; i++) {
		scanf("%d", &A[i]);
		getchar();
	}
	
	Print(A);
	//MaxAndMin(A, SIZE, &max, &min);
	//printf("max = %d, min = %d\n", max, min);
	printf("the %dth min number: %d\n", index, RandomizedSelect(A, 0, SIZE - 1, index));
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
