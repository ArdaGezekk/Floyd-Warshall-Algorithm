/*****Please include following header files*****/
// stdio.h
/***********************************************/

#define VERTICES_COUNT 4
#define INF 99999

void Print(int distance[][VERTICES_COUNT])
{
	printf("Shortest distances between every pair of vertices: \n");

	for (int i = 0; i < VERTICES_COUNT; ++i)
	{
		for (int j = 0; j < VERTICES_COUNT; ++j)
		{
			if (distance[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", distance[i][j]);
		}

		printf("\n");
	}
}

void FloydWarshall(int graph[][VERTICES_COUNT])
{
	int distance[VERTICES_COUNT][VERTICES_COUNT];

	for (int i = 0; i < VERTICES_COUNT; i++)
		for (int j = 0; j < VERTICES_COUNT; j++)
			distance[i][j] = graph[i][j];

	for (int k = 0; k < VERTICES_COUNT; k++)
	{
		for (int i = 0; i < VERTICES_COUNT; i++)
		{
			for (int j = 0; j < VERTICES_COUNT; j++)
			{
				if (distance[i][k] + distance[k][j] < distance[i][j])
					distance[i][j] = distance[i][k] + distance[k][j];
			}
		}
	}

	Print(distance);
}
