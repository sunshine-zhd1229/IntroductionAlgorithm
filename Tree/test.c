#include  <stdio.h>
#include  <string.h>
#include  "BinarySearchTree.h"

#define     SIZE	11

void Print(int A[]); 
void PrintKey(void *data);
int compare(const void *a, const void *b);

int main(void) 
{
	int A[SIZE];
	int i;
	for (i = 0; i < SIZE; i++) {
		scanf("%d", &A[i]);
		getchar();
	}
	TreeNode *Tree, *temp, *p;
	Print(A);
	Tree = CreateTree(A, SIZE, sizeof(int), compare);
	InOrderTreeWalk(Tree, PrintKey);
	printf("\n");
	temp = MaximumOfTree(Tree);
	PrintKey(temp->data);
	p = SuccessorOfTree(Tree, temp);
	if (p != NULL)
		PrintKey(p->data);
	else 
	  printf("NULL");
	p = PredecessorOfTree(Tree, temp);
	if (p != NULL)
		PrintKey(p->data);
	else 
	  printf("NULL");
	temp = MinimumOfTree(Tree);
	PrintKey(temp->data);
	p = SuccessorOfTree(Tree, temp);
	if (p != NULL) {
		p = SearchInTree(Tree, p->data, compare);
		p = DeleteFromTree(&Tree, p);
		PrintKey(p->data);
	}
	else 
	  printf("NULL");
	p = PredecessorOfTree(Tree, temp);
	if (p != NULL)
		PrintKey(p->data);
	else 
	  printf("NULL");
	p = SuccessorOfTree(Tree, NULL);
	if (p != NULL)
	  PrintKey(p->data);
	else 
	  printf("NULL");
	p =PredecessorOfTree(Tree, NULL);
	if (p != NULL)
		PrintKey(p->data);
	else 
	  printf("NULL");
	printf("\n");
	InOrderTreeWalk(Tree, PrintKey);
	return 0;
}

void Print(int A[]) 
{
	int i;
	for (i = 0; i < SIZE; i++)
	  printf("%d ", A[i]);
	printf("\n");
}

void PrintKey(void * data)
{
	printf("%d ", *(int *)data);
}

int compare(const void *a, const void *b)
{
	if(*(int*)a > *(int*)b)
	  return 1;
	else if (*(int *)a == *(int *)b)
	  return 0;
	else
	  return -1;
}
