#include  <stdio.h>

int Partition(int Array[], int start, int end)
{
	int i = start - 1;
	int j = start;
	int temp;
	for (; j < end; j++) {
		if (Array[j] <= Array[end]) {
			i++;
			if (i != j) {
				temp = Array[j];
				Array[j] = Array[i];
				Array[i] = temp;
			}
		}
	}

	temp = Array[end];
	Array[end] = Array[i + 1];
	Array[i + 1] = temp;
	return i + 1;
}

void QuickSort(int Array[], int start, int end)
{
	if (end - start  + 1 < 3) {
		int partition = Partition(Array, start, end);
		QuickSort(Array, start, partition - 1);
		QuickSort(Array, partition + 1, end);
	}
}
