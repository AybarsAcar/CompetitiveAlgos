#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/********
INPUT:
5 3
C1 1 1
C2 2 1
C3 3 2
C4 0 1
C5 2 3

OUTPUT: C4 C1 C2
********/

class Car
{
public:
  string id;
  int x, y;

  // returns the square of the distance
  int Distance() const
  {
    return x * x + y * y;
  }

  Car(string id, int x, int y) : id(id), x(x), y(y) {}
};

// comparison to create a max heap
class CarCompare
{
public:
  bool operator()(const Car a, const Car b)
  {
    return a.Distance() < b.Distance();
  }
};

bool DistanceCompareAscending(Car a, Car b)
{
  return a.Distance() < b.Distance();
}

void PrintKNearestCars(vector<Car> cars, int k)
{
  // create a max heap of size k and insert first k elements
  priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k);

  // iterate over the remaining cars
  for (int i = k; i < cars.size(); i++)
  {
    auto car = cars[i];

    if (car.Distance() < max_heap.top().Distance())
    {
      // replace the max element of the heap
      // pop the top element and insert the current car we are iterating over
      max_heap.pop();
      max_heap.push(car);
    }
  }

  // optionally we can sort our result
  vector<Car> output;

  // all the cars inside the heap are the K-smalles distances
  while (!max_heap.empty())
  {
    output.push_back(max_heap.top());
    max_heap.pop();
  }

  // cars will be in the reverse order
  reverse(output.begin(), output.end());

  for (auto car : output)
  {
    cout << car.id << endl;
  }
}

int main()
{

  int N, K;
  cin >> N >> K;

  string id;
  int x, y;

  vector<Car> cars;

  for (int i = 0; i < N; i++)
  {
    cin >> id >> x >> y;

    Car car(id, x, y);
    cars.push_back(car);
  }

  PrintKNearestCars(cars, K);

  return 0;
}