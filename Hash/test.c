#include  <stdio.h>
#include  <string.h>
#include  "hash.h"

#define     SIZE	8

void Print(int A[]); 
int compare(const void *a, const void *b);

int main(void) 
{
	int A[SIZE];
	int i, k, table_index;
	Hash_Table *table;
	table = CreateHashTable();

	for (i = 0; i < 4; i++) {
		scanf("%d", &A[i]);
		if (HashInsert(table, A[i]) == HASH_INSERT_OK)
		  printf("insert ok");
		else
		  printf("table full");
		getchar();
	}
	
	for (; i < SIZE; i++) {
		scanf("%d", &A[i]);
		getchar();
	}

	for (i = 0; i < SIZE; i++) {
		k = HashSearch(table, A[i], &table_index);
		if (k != NOT_IN_TABLE) {
		  if (HashDelete(table, k, table_index) != DELETE_OK)
			printf("Delete error\n");
		  else 
			printf("Delete OK\n");
		} else
		  printf("Not in Table\n");
	}

	Print(A);
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
