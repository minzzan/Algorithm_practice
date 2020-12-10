//it's not my own code

#include <stdio.h>
#define MAX_SIZE 10

int A[MAX_SIZE] = { 3,7,1,6,8,4,2,7,5,9 };

void SWAP(int a, int b)
{
	int temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}

int Partition(int left, int right)
{
	int pivot = A[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (low <= right && pivot >= A[low])
		{
			low++;
		}
		while (high >= (left + 1) && pivot <= A[high])
		{
			high--;
		}
		if (low <= high)
		{
			SWAP(low, high);
		}
	}
	SWAP(left, high);
	return high;
}

void QuickSort(int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(left, right);
		QuickSort(left, pivot - 1);
		QuickSort(pivot + 1, right);
	}
}

int main()
{
	
	QuickSort(0,MAX_SIZE-1);

	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", A[i]);
	}

	return 0;
}

