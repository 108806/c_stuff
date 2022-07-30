#include <stdlib.h>
#include <stdio.h>


void min_max(int *arr, int size, int *min, int *max)
{
	int idx;
	* min = arr[0], * max = arr[0];
	
	for (idx = 0; idx < size-1; idx++) {
		if (arr[idx] < *min) *min = arr[idx];
		if (arr[idx] > *max) *max = arr[idx];
	}
}


int main()
{
	int arr[8] = { 13, 38, 37, 24, 51, 21, 3 },
		amin, amax;
	min_max(arr, 8, &amin, &amax);
	printf("min : %d\tmax :%d\n", amin, amax);

	return 0;
}
