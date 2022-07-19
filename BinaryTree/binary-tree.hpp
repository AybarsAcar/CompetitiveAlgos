class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
  Node *root;
};