#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class Node
{
public:
  string name;
  list<string> neighbours;

  Node(string name)
  {
    this->name = name;
  }
};

class Graph
{
  // all nodes
  // hashmap (string, Node*)
  unordered_map<string, Node *> map;

public:
  Graph(vector<string> cities)
  {
    for (string cityName : cities)
    {
      map[cityName] = new Node(cityName);
    }
  }

  void AddEdge(string cityA, string cityB, bool undirected = false)
  {
    map[cityA]->neighbours.push_back(cityB);

    if (undirected)
    {
      map[cityB]->neighbours.push_back(cityA);
    }
  }

  void PrintAdjacencyList()
  {
    for (auto pair : map)
    {
      auto city = pair.first;

      Node *node = pair.second;

      cout << city << "-> ";

      for (auto neighbour : node->neighbours)
      {
        cout << neighbour << ",";
      }

      cout << endl;
    }
  }
};

int main()
{
  vector<string> cities = {"Sydney", "Melbourne", "Newcastle", "London", "Istanbul", "New York"};

  Graph g(cities);

  g.AddEdge("Sydney", "Melbourne", true);
  g.AddEdge("Sydney", "Newcastle", true);
  g.AddEdge("London", "Istanbul");
  g.AddEdge("New York", "London");

  g.PrintAdjacencyList();

  return 0;
}