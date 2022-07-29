#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>

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

  void AddEdge(int node1, int node2, bool undirected = false)
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

  /**
   * @brief
   * Breadth First Search which is a Level Order Traversal
   * we visit the neigbours first
   * @param source
   */
  void BFS(int source)
  {
    queue<int> q;
    bool *visited = new bool[vertices]{false};

    q.push(source);
    visited[source] = true;

    cout << "{ ";

    while (!q.empty())
    {
      int currentNode = q.front();
      cout << currentNode << " ";
      q.pop();

      // push the neighbours of the current node into queue
      // if they are not already visited
      for (auto neighbour : lists[currentNode])
      {
        if (!visited[neighbour])
        {
          q.push(neighbour);

          // mark as visited when adding to the queue even if not visited yet
          // in case the neigbhours point to same neighour
          visited[neighbour] = true;
        }
      }
    }

    cout << "}" << endl;
  }

  /**
   * @brief
   * Depth First Search on a graph
   * @param source
   */
  void DFS(int source)
  {
    bool *visited = new bool[vertices]{false};

    cout << "{ ";

    DFSHelper(source, visited);

    cout << "}" << endl;
  }

  void DFSHelper(int node, bool *visited)
  {
    visited[node] = true;

    cout << node << " ";

    // make a dfs call on all its unvisited neighbours
    for (int neighbour : lists[node])
    {
      if (!visited[neighbour])
      {
        DFSHelper(neighbour, visited);
      }
    }
  }

  /**
   * @brief
   * Graph must be a Directed Acyclic Graph
   * if not DAG, returns { }
   */
  void TopologicalSort()
  {
    vector<int> indegree(vertices, 0);

    // iterate over all edges to find the right indegree
    for (int i = 0; i < vertices; i++)
    {
      for (auto neighbour : lists[i])
      {
        indegree[neighbour]++;
      }
    }

    cout << "{ ";

    // BFS
    queue<int> q;

    for (int i = 0; i < vertices; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }

    while (!q.empty())
    {
      int node = q.front();

      cout << node << " ";

      q.pop();

      // iterate over the neighbours of this node and reduce their indegree by -1
      for (auto neighbour : lists[node])
      {
        indegree[neighbour]--;

        if (indegree[neighbour] == 0)
        {
          q.push(neighbour);
        }
      }
    }

    cout << "}" << endl;
  }
};

int main()
{
  Graph g(6);

  g.AddEdge(0, 2);
  g.AddEdge(2, 3);
  g.AddEdge(3, 5);
  g.AddEdge(4, 5);
  g.AddEdge(1, 4);
  g.AddEdge(1, 2);

  g.PrintAdjacencyList();

  g.BFS(3);
  g.DFS(3);

  g.TopologicalSort();

  return 0;
}