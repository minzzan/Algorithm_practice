#include <stdio.h>
#define MAX_SIZE 10

int A[MAX_SIZE] = { 3,7,1,6,8,4,2,7,5,9 };

void SWAP(int x, int y)
{
	int temp = A[x];
	A[x] = A[y];
	A[y] = temp;
}

void SelctionSort()
{
	int least = 0;
	int temp = 0;



	for (int i = 0; i < MAX_SIZE; i++)
	{
		least = i;

		for (int j = i + 1; j < MAX_SIZE; j++)
		{
			if (A[j] < A[least])
			{
				SWAP(j, least);
			}
		}
	}
}

int main()
{

	SelctionSort();

	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", A[i]);
	}

	return 0;
}

