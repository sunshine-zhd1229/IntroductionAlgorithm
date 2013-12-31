#include  "Random.h"
void RandomInPlace(int *Array, int length)
{
	int i;
	int temp, index;
	for (i = 0; i < length; i++) {
		index = Random(i, length - 1);
		temp = Array[i];
		Array[i] = Array[index];
		Array[index] = temp;
	}
}


