#include  <stdlib.h>
#include  <time.h>

int Random(int start, int end)
{
	srand((unsigned int) time(NULL));	
	return (rand() % (end - start + 1)) + start;
}

int RandomizedPartition(int *Array, int start, int end)
{
	int seed = Random(start, end);
	int temp;
	temp = Array[end];
	Array[end] = Array[seed];
	Array[seed] = temp;

	int i = start - 1;
	int j = start;
	for (; j < end; j++) {
		if (Array[j] <= Array[end]) {
			i++;
			if (i != j) {
				temp = Array[i];
				Array[i] = Array[j];
				Array[j] = temp;
			} 
		}
	}

	i++;
	temp = Array[i];
	Array[i] = Array[end];
	Array[end] = temp;

	return i;
}
