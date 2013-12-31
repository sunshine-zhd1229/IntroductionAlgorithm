#include  <stdlib.h>
#include  <string.h>

void InsertionSort(int *Array, int length)
{
	int i, j, key;
	for (i = 1; i < length; i++) {
		key = Array[i];
		for (j = i - 1; j >= 0 && Array[j] > key; j--)
		  Array[j + 1] = Array[j];  		//比key大的向后挪
		Array[j + 1] = key;
	}
}

void InsertionSortAllType(void *array, size_t nmemb, size_t memsize, int (*compar)(const void *, const void *))
{
	int i, j;
	void *key = malloc(memsize);
	for (i = 1; i < nmemb; i++) {
		memcpy(key, array + (i * memsize), memsize);
		for (j = i - 1; j >= 0; j--) {
			if (compar(key, array + j * memsize) < 0)	{
				memcpy(array + (j + 1) * memsize, array + j * memsize, memsize);  		//比key大的向后挪
			} else
			  break;
		}
		memcpy(array + (j + 1) * memsize, key, memsize);					//插入key
	}

}
