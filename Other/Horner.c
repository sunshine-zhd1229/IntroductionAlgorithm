#include  <stdio.h>
#include  <stdlib.h>

int main(void)
{
	int x, n, result = 0, *CoeArray, *p;
	printf("input x and n: \n");
	scanf("%d%d", &x, &n);
	CoeArray = (int *)malloc(n * sizeof(int));
	p = CoeArray;
	printf("Input coe and: \n");
	while(scanf("%d", p++) != EOF);
	p--;
	while(p != CoeArray - 1)
	{
		result = result * x + *p;
		p--;
	}

	printf("result = %d\n", result);
	exit(0);
}
