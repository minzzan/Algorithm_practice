//too difficult....

#include <stdio.h>
#define MAX_SIZE 10

int A[MAX_SIZE] = { 3,7,1,6,8,4,2,7,5,9 };

void InsertionSort()
{
	int key, temp;
	for (int i = 1; i < MAX_SIZE; i++)
	{
		int j = i - 1;
		while ((A[j] > A[j + 1]) && (j >= 0))
		{
			temp = A[j];
			A[j] = A[j + 1];
			A[j + 1] = temp;
			j--;
		}
	}
}

int main()
{
	
	InsertionSort();

	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", A[i]);
	}

	return 0;
}

