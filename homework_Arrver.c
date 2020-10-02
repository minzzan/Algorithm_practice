#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SZ 20

int list[20] = { 0 };

void swap(int a, int b)
{
	int temp = list[a];
	list[a] = list[b];
	list[b] = temp;
}

void bubbleSort()
{
	int i, j;
	for (i = 0; i < SZ; i++)
	{
		for (j = 0; j < SZ-1; j++)
		{
			if (list[j] > list[j + 1])
			{
				swap(j, j + 1);
			}
		}
	}
}

void showlist()
{
	for (int i = 0; i < SZ; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}

int main()
{
	srand(time(NULL)); //정해진 seed값을 변경하기 위함. (실행할때마다 다른 난수)
	for (int i = 0;i < SZ;i++)
	{
		list[i] = rand() % 1000; //0~1000 내의 난수 생성
	}
	showlist();
	bubbleSort();
	showlist();
	
	return 0;
}
