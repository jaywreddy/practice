#include <stdio.h>
#include <limits.h>

class Dijkastra
{
private:
  template <size_t len>
  int getMin(int dist[len], bool sptSet[len])
  {
     // Initialize min value
     int min = INT_MAX;
     int min_index;

     for (int v = 0; v < len; v++)
       if (sptSet[v] == false && dist[v] <= min)
           min = dist[v], min_index = v;

     return min_index;
  }
public:
  //Template function allows use for multiple array sizes
  //size_t is an unsigned long
  template <size_t len>
  int* dijkastra( int start, int matrix[len][len])
  {
    printf("size: %lu \n", len);
    static int dist[len]; //output array
    bool visited[len]; //marks if nodes have been visited

    //initialize distance and visited
    for (int i = 0; i<len; i++)
    {
      dist[i] = INT_MAX;
      visited[i] = false;
    }

    //distance to start is fixed
    dist[start] = 0;

    //iterate through all nodes, selecting closest each time
    for (int iter = 0; iter < len-1; iter ++)
    {
      //find closest node and mark it as visited
      int current = getMin<len>(dist, visited);
      visited[current] = true;

      //update all neighbors
      for (int v = 0; v < len; v++)
      {
        if(!visited[v] && matrix[current][v] && dist[current]!= INT_MAX
                       && dist[current] + matrix[current][v] < dist[v])
         {
           dist[v] = dist[current] + matrix[current][v];
         }
      }
    }
    return dist;
  }
};

template <int len>
void printSolution(int dist[len])
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < len; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
  int mat[5][5] = {
    {0,1,0,0,1},
    {1,0,1,0,1},
    {0,1,0,1,0},
    {0,0,1,0,1},
    {1,1,0,1,0}
  };
  int node = 0;
  Dijkastra G = Dijkastra();
  int* dist = G.dijkastra(node, mat);
  printSolution<5>(dist);
}
