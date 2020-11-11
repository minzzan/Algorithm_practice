#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAX_VERTICES 100
#define INF 1000000

/*10 개의 정점(Vertex) 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 를 생성하고, 아래와 같은 가중치값을
가진 간선들을 포함하는 그래프에서, Floyd 알고리즘을 적용하여, 각 정점을 이용하는
최단경로의 결과 배열 A 의 결과를 각각 출력하라.  */

typedef struct GraphType
{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}; GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void print_array_A(GraphType * g)
{
	int i, j;
	printf("=============================\n");
	
	for (i = 0; i < g->n; i++)
	{
		for (j = 0; j < g->n; j++)
		{
			if (A[i][j] == INF)
			{
				printf("  * ");
			}
			else
			{
				printf("%3d ", A[i][j]);
			}
		}
		printf("\n");
	}
	printf("=============================\n");
}


void floyd(GraphType* g)
{
	int i, j, k;

	// Array A's Initialization
	for (i = 0; i < g->n; i++)
	{
		for (j = 0; j < g->n; j++)
		{
			A[i][j] = g->weight[i][j];
		}
	}

	print_array_A(g);

	//Using multiple loop,implement floyed scheme
	for (k = 0; k < g->n; k++)
	{
		for (i = 0; i < g->n; i++)
		{
			for (j = 0; j < g->n; j++)
			{
				if (A[i][k] + A[k][j] < A[i][j])
				{
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
		print_array_A(g);
	}
}

int main(void) 
{
 GraphType g = { 7,
	{{ 0,  7,  INF, INF,   3,  10, INF },
	{ 7,  0,    4,  10,   2,   6, INF },
	{ INF,  4,    0,   2, INF, INF, INF },
	{ INF, 10,    2,   0,  11,   9,   4 },
	{ 3,  2,  INF,  11,   0, INF,   5 },
	{ 10,  6,  INF,   9, INF,   0, INF },
	{ INF, INF, INF,   4,   5, INF,   0 } }

 };

	floyd(&g);

	return 0;
}
