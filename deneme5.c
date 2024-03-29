// Floyd-Warshall Algorithm in C
#include <stdio.h>
// defining the number of vertices
#define nV 4
#define INF 1000000
void printMatrix(int matrix[][nV]);
// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV]) {
  int matrix[nV][nV], i, j, k;
  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];
  // Adding vertices individually
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}
void printMatrix(int matrix[][nV]) {
    for (int j = 0; j < nV; j++) {
      if (matrix[0][j] == INF)
        printf("%4s", "INF");
      else
        printf("Shortest path from node 1 to node %d is: %4d\n",j,matrix[0][j]);
    }
    printf("\n");
  }
int main() {
  int graph[nV][nV] = {{ 0 ,  3  , 1000000 ,  5  },
                      {  2  , 0 ,  1000000  , 4 },
                      { 1000000 ,  1  , 0 ,  1000000  },
                      {  1000000  , 1000000 ,  2  , 0}};
  floydWarshall(graph);
}
