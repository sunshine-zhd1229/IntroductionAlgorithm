void MaxAndMin(int *array, int length, int *max, int *min) 
{
	int i, j;
	if (length % 2) {
		*max = array[0];
		*min = array[0];
		i = 1;
		j = 2;
	} else {
		if (array[0] > array[1]) {
			*max = array[0];
			*min = array[1];
		} else {
			*max = array[1];
			*min = array[0];
		}
		i = 2;
		j = 3;
	}

	for (; i < length - 1 && j < length - 1; i = i + 2, j = j + 2) {
		if (array[i] > array[j]) {
			if (array[i] > *max)
			  *max = array[i];
			if (array[j] < *min)
			  *min = array[j];
		} else {
			if (array[j] > *max)
			  *max = array[j];
			if (array[i] < *min)
			  *min = array[i];
		}
	}
}
