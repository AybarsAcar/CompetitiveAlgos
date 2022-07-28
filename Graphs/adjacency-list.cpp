#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

/**
 * @brief
 * Graph stored as adjacency list
 */
class Graph
{
  int vertices;     // number of vertices
  list<int> *lists; // pointer to dynamic array of lists

public:
  Graph(int vertices)
  {
    this->vertices = vertices;
    lists = new list<int>[vertices];
  }

  void AddEdge(int node1, int node2, bool undirected = true)
  {
    lists[node1].push_back(node2);

    if (undirected)
    {
      lists[node2].push_back(node1);
    }
  }

  void PrintAdjacencyList()
  {
    // iterate over all the rows
    for (int i = 0; i < vertices; i++)
    {
      cout << i << "->";
      // iterate over every element of ith linked list
      for (auto node : lists[i])
      {
        cout << node << " ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Graph g(6);

  g.AddEdge(0, 1);
  g.AddEdge(0, 4);
  g.AddEdge(2, 1);
  g.AddEdge(3, 4);
  g.AddEdge(4, 5);
  g.AddEdge(2, 3);
  g.AddEdge(3, 5);

  g.PrintAdjacencyList();

  return 0;
}