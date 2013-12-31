#include  <stdio.h>
#include  <math.h>
#include  <string.h>

void BaseSortBin(int *Array, int length, int digitNum, int radix)
{
	int countSize = (int)pow(2, radix) - 1;
	int count[countSize + 1];
	int result[length];
	int num = (int)ceil((double)digitNum / radix);
	int mask = countSize;
	int i, j, k;
	memset(result, 0, length * sizeof(int));
	for (i = 1; i <= num; i++) {
		memset(count, 0, (countSize + 1) * sizeof(int));
		for (j = 0; j < length; j++) {
			count[(Array[j] >> ((i - 1) * radix)) & mask]++;
		}

		for (j = 1; j <= countSize; j++) {
			count[j] += count[j - 1];
		}

		for (j = length - 1; j>= 0; j--) {
			k = (Array[j] >> ((i - 1) * radix)) & mask;
			count[k]--;
			result[count[k]] = Array[j];
		}
		memcpy(Array, result, length * sizeof(int));
	}
}
