#include  <stdio.h>

void BubbleSort(int *Array, int size)
{
	int i ,j, temp;
	for(i = 0; i < size; i++) {
		for(j = size - 1; j > i; j--)
		  if(Array[j] < Array[j - 1])
		  {
				temp = Array[j];
				Array[j] = Array[j-1];
				Array[j - 1] = temp;
		  }
	}
}
