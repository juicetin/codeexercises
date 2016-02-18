#include <stdio.h>
#include <stdlib.h>

// TODO
void mergesort(int * arr, int size)
{
	int mid_i = size/2;
}

int main()
{
	int n = 30;
	int * arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		arr[i] = n-i;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
}
