#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int revise = 0;

void Merge(int *Array, int p, int q, int r) 
{
	int *firstArray;		//用于存数组的前半部分
	int *secondArray;		//用于存数组的后半部分
	int i, j, k, firstNum, secNum;
	
	firstNum = q - p + 1;	//第一个数组元素个数
	secNum = r - q;			//第二个数组元素个数

	firstArray = (int *)malloc(firstNum * sizeof(int));
	secondArray = (int *)malloc(secNum * sizeof(int));

	memcpy(firstArray, Array + p, firstNum * sizeof(int));		//分别复制两个数组的元素
	memcpy(secondArray, Array + p + firstNum, secNum * sizeof(int));

	for (i = 0, j = 0, k = 0; i < firstNum && j < secNum; ) {	//  将两个数组合并
		if (firstArray[i] > secondArray[j])	
		{
			Array[p + k++] = secondArray[j++];
			revise += firstNum - i;
		}
		else
		  Array[p + k++] = firstArray[i++];
	}

	if (k < r - p + 1) {								//一个数组中的元素完全插入后，将另一个数组中剩下的数复制过去
		if(i == firstNum)
		  memcpy(Array + p + k, secondArray + j, (secNum - j) * sizeof(int));
		else 
		  memcpy(Array + p + k, firstArray + i, (firstNum - i) * sizeof(int));
	}
}

void MergeSort(int *Array, int start, int end) 
{
	int mid;
	if (start < end) {	//多于一个元素的时候对数组进行排序
		mid = (start + end) / 2;
		MergeSort(Array, start, mid);	//对前半部分进行排序
		MergeSort(Array, mid + 1, end);	//对后半部分进行排序
		Merge(Array, start, mid, end);	//将两部分合并
	}
	printf("reverse pair: %d\n", revise);
}
