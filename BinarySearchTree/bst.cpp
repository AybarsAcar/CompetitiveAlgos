#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
  int value;
  Node *left;
  Node *right;

  Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

/**
 * @brief
 * Inserts the value into the tree
 * given the root of the tree
 *
 * @param root
 * @param value
 * @return Node*
 */
Node *Insert(Node *root, int value)
{
  if (root == nullptr)
  {
    return new Node(value);
  }

  if (root->value > value)
  {
    // insert left
    root->left = Insert(root->left, value);
  }
  else
  {
    // insert right
    root->right = Insert(root->right, value);
  }

  return root;
}

/**
 * @brief
 * return true if the value exists in the given key
 *
 * @param root
 * @param value
 * @return Bool
 */
bool Search(Node *root, int value)
{
  if (root == nullptr)
    return false;

  if (root->value == value)
    return true;

  if (root->value > value)
    return Search(root->left, value);

  return Search(root->right, value);
}

Node *FindMin(Node *root)
{
  while (root->left != nullptr)
  {
    root = root->left;
  }

  return root;
}

/**
 * @brief
 * Removes the node from the binary tree
 *
 * @param root
 * @param value
 * @return Node*
 */
Node *Remove(Node *root, int value)
{
  // Searching phase
  if (root == nullptr)
  {
    return nullptr;
  }
  else if (value < root->value)
  {
    root->left = Remove(root->left, value);
  }
  else if (value > root->value)
  {
    root->right = Remove(root->right, value);
  }

  // Removing phase
  else
  {
    // when the current node matches with the key

    // case 1: No Children
    if (root->left == nullptr && root->right == nullptr)
    {
      delete root;
      root = nullptr;
    }

    // case 2: Single Child
    else if (root->left == nullptr)
    {
      // deleting a node with a right sub-tree
      Node *temp = root;
      root = root->right; // point the root the child
      delete temp;
    }
    else if (root->right == nullptr)
    {
      // deleting a node with a left sub-tree
      Node *temp = root;
      root = root->left;
      delete temp;
    }

    // case 3: 2 children
    else
    {
      Node *temp = FindMin(root->right);

      // copy the data
      root->value = temp->value;

      // remove teh next in order successor
      root->right = Remove(root->right, temp->value);
    }
  }

  return root;
}

void PrintInOrder(Node *root)
{
  if (root == nullptr)
  {
    return;
  }

  PrintInOrder(root->left);

  cout << root->value << " ";

  PrintInOrder(root->right);
}

/**
 * @brief
 * Prints all the elements in the BST given its root
 * between lower and upper values
 *
 * @param root
 * @param lower
 * @param upper
 */
void PrintInRange(Node *root, int lower, int upper)
{
  // base case
  if (root == nullptr)
    return;

  if (root->value >= lower && root->value <= upper)
  {
    // call on both sides
    PrintInRange(root->left, lower, upper);

    cout << root->value << " ";

    PrintInRange(root->right, lower, upper);
  }
  else if (root->value > upper)
  {
    // only go onto left side as its value is higher than upper
    PrintInRange(root->left, lower, upper);
  }
  else
  {
    // only go onto right side as its value is lower than lower
    PrintInRange(root->right, lower, upper);
  }
}

void PrintAllPathsToLeaves(Node *root, vector<int> &path)
{
  if (root == nullptr)
    return;

  if (root->left == nullptr && root->right == nullptr)
  {
    // print vector
    for (auto val : path)
    {
      cout << val << "->";
    }
    cout << root->value << " ";
    cout << endl;
    return;
  }

  path.push_back(root->value);

  PrintAllPathsToLeaves(root->left, path);

  PrintAllPathsToLeaves(root->right, path);

  // backtracking
  path.pop_back();
}

int main()
{
  Node *root = nullptr;
  int a[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

  for (auto val : a)
  {
    root = Insert(root, val);
  }

  PrintInOrder(root);
  cout << endl;

  cout << Search(root, 200) << endl;

  Remove(root, 6);

  PrintInOrder(root);
  cout << endl;

  PrintInRange(root, 8, 13);
  cout << endl;

  vector<int> path;
  PrintAllPathsToLeaves(root, path);

  return 0;
}