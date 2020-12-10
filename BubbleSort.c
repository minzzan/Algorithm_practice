#include <stdio.h>
#define MAX_SIZE 10

int A[MAX_SIZE] = { 3,7,1,6,8,4,2,7,5,9 };

void SWAP(int a, int b)
{
	int temp;
	temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}

void BubbleSort()
{
	for (int i = 0; i < MAX_SIZE-1; i++)
	{
		for (int j = 0; j < MAX_SIZE-i-1; j++)
		{
			if (A[j] > A[j + 1])
			{
				SWAP(j, j + 1);
			}
		}
	}
}

int main()
{
	
	BubbleSort();

	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", A[i]);
	}

	return 0;
}

