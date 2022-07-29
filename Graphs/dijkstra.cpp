#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Graph
{
  int vertices;                // number of vertices
  list<pair<int, int>> *lists; // pointer to dynamic array of lists

public:
  Graph(int vertices)
  {
    this->vertices = vertices;
    lists = new list<pair<int, int>>[vertices];
  }

  void AddEdge(int node1, int node2, int weight, bool undirected = true)
  {
    lists[node1].push_back({weight, node2});

    if (undirected)
      lists[node2].push_back({weight, node1});
  }

  int Dijkstra(int source, int destination)
  {
    vector<int> distance(vertices, INT_MAX);

    // set to store distance and node
    set<pair<int, int>> s;

    // initialise the distance
    distance[source] = 0;

    // initialise the set
    s.insert({0, source});

    while (!s.empty())
    {
      auto it = s.begin(); // first elment in the set

      int node = it->second;
      int distanceTillNow = it->first;

      s.erase(it); // pop from set

      // iterate over the neighbours of node
      for (auto neighbourPair : lists[node])
      {
        int neighbour = neighbourPair.second;
        int currentEdgeLength = neighbourPair.first;

        if (distanceTillNow + currentEdgeLength < distance[neighbour])
        {
          // remove if such a pair already exists in the set
          auto f = s.find({distance[neighbour], neighbour});

          // check if it exists
          if (f != s.end())
          {
            s.erase(f);
          }

          // update it
          distance[neighbour] = distanceTillNow + currentEdgeLength;

          s.insert({distance[neighbour], neighbour});
        }
      }
    }

    // Single Source Shortest Distance to all other nodes
    for (int i = 0; i < vertices; i++)
    {
      cout << "Node i " << i << " Dist " << distance[i] << endl;
    }

    return distance[destination];
  }
};

int main()
{
  Graph g(5);
  g.AddEdge(0, 1, 1);
  g.AddEdge(1, 2, 2);
  g.AddEdge(0, 2, 4);
  g.AddEdge(0, 3, 7);
  g.AddEdge(3, 2, 2);
  g.AddEdge(3, 4, 3);

  cout << "Shortest Distance is " << g.Dijkstra(0, 4) << endl;

  return 0;
}