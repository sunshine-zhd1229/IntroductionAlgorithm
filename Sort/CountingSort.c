#include  <stdio.h>
#include  <string.h>

void CountSort(int *Array, int length, int limit) {
	int result[length];
	int count[limit + 1];
	int i;
	memset(count, 0, (limit + 1) * sizeof(int));
	for (i = 0; i < length; i++)
	  count[Array[i]]++;
	for (i = 1; i <= limit; i++)
	  count[i] = count[i] + count[i - 1];
	for (i = length - 1; i >= 0; i--) {
	  count[Array[i]]--; 
	  result[count[Array[i]]] = Array[i];
	}
	memcpy(Array, result, length * sizeof(int));
}
