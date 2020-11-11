#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF 1000000

/*10 개의 정점(Vertex) 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 를 생성하고, 아래와 같은 가중치값을
가진 간선들을 포함하는 그래프에서, Dijkstra 알고리즘을 적용하여, 시작노드 0 에서
다른 모든 노드들간의 최단 경로 거리 정보를 각 Step 에서 발견된 노드와 함께
출력하라. */

typedef struct GraphType
{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}; GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;

	min = INT_MAX;
	minpos = -1;

	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	}

	return minpos;
}

void print_status(GraphType * g)
{
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");

	for (int i = 0; i < g->n; i++)
	{
		if (distance[i] == INF)
		{
			printf(" * ");
		}
		else
		{
			printf("%2d ", distance[i]);
		}
	}

	printf("\n");
	printf("      found:      ");

	for (int i = 0; i < g->n; i++)
	{
		printf("%2d ", found[i]);
	}

	printf("\n\n");

}


void shortest_path(GraphType* g, int start) //Dijkstra function
{
	int i, u, w;

	for (i = 0; i < g->n; i++)
	{
		distance[i] = g->weight[start][i];
		found[i] = false;
	} //innitialization

	found[start] = true; // start vertex update (mark)
	distance[start] = 0;

	//Each vertex is added to Set S

	for (i = 0; i < g->n; i++)
	{
		print_status(g); //print current status including step, distance array value

		u = choose(distance, g->n, found);

		found[u] = true;

		for (w = 0; w < g->n; w++)
		{
			if (found[w] == false)
			{
				if (distance[u] + g->weight[u][w] < distance[w])
				{
					distance[w] = distance[u] + g->weight[u][w];
				}
			}
		}
	}
}


int main() {
	GraphType g = { 10,
 {{ 0,  5,  6,  INF,  INF,   INF,  INF,   INF,  7, 14 },
 { 5,  0,  5,  4,  INF,   INF,  INF,   INF,  INF,  INF},
 { 6,  5,  0,  3,  10,   11,  INF,   INF,  INF,  5},
 { INF,  4,  3,  0,  6,   INF,  INF,   INF,  INF,  INF},
 { INF,  INF,  10,  6,  0,   8,  INF,   INF,  INF,  INF},
 { INF,  INF,  11,  INF,  8,  0 ,  7,   INF,  INF,  6},
 { INF,  INF,  INF,  INF,  INF,   7, 0 ,   3,  INF,  4},
 { INF,  INF,  INF,  INF,  INF,   INF,  3, 0  ,  8,  INF},
 { 7,  INF,  INF,  INF,  INF,   INF,  INF,   8,0  , 15 },
 { 14,  INF,  5,  INF,  INF,   6,  4,   INF, 15 ,0  } }
	};

	shortest_path(&g, 0);

	return 0;
}
