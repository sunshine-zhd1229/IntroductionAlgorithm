#include  "Random.h"

int RandomizedSelect(int *Array, int start, int end, int index)
{
	if (start == end) {
		return Array[start];
	}
	
	int position = RandomizedPartition(Array, start, end);
	int k = position - start + 1;
	if (index == k)
	  return Array[position];
	else if (index > k)
	  return RandomizedSelect(Array, position + 1, end, index - k);
	else
	  return RandomizedSelect(Array, start, position - 1, index);
}
