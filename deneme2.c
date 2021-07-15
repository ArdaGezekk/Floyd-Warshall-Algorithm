// Import header files for program
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//Define the number of nodes in the graph
#define N 4
#define INF 10

//Define minimum function that will be used later on to calcualte minimum values between two numbers
#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

//Define matrix of size N * N to store distances between nodes
//Initialize all distances to zero



int i,j;

for(i=0;i<N;i++)
for(j=0;j<N;j++)
 {
  printf("dist[%d][%d]:",i,j);
  scanf("%d",&dist[i][j]);
 }
int main(int argc, char *argv[])
{


  // Define iterator to iterate over distance matrix
  int src, dst, middle;

  printf("Adjacency Matrix before Floyd-Warshall Algorithm \n");
  for (src = 0; src < N; src++)
  {
    for (dst = 0; dst < N; dst++)
    {
      printf("%d ", distance_matrix[src][dst]);
    }
    printf("\n");
  }

  for (middle = 0; middle < N; middle++)
  {
    int *dm=distance_matrix[middle];
    for (src = 0; src < N; src++)
    {
      int *ds=distance_matrix[src];
      for (dst = 0; dst < N; dst++)
      {
        ds[dst]=min(ds[dst],ds[middle]+dm[dst]);
      }
    }
  }

  printf("\n");
  printf("Adjacency Matrix after Floyd-Warshall Algorithm \n");
  for (src = 0; src < N; src++)
  {
    for (dst = 0; dst < N; dst++)
    {
      printf("%d ", distance_matrix[src][dst]);
    }
    printf("\n");
  }

  return 0;
}
