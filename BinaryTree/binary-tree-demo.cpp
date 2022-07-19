#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "binary-tree.hpp"

using namespace std;

// Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// -1 indicates nullptr

// Input for Level order build tree
// Input: 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1

/**
 * @brief
 * Level Order build
 *
 * @return Node*
 */
Node *BuildTreeLevelOrder()
{
  int data;
  cin >> data;

  // create the root node
  Node *root = new Node(data);

  // create the queue to keep the parents in level order
  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    Node *current = q.front();
    q.pop();

    int child1, child2;
    cin >> child1 >> child2;

    if (child1 != -1)
    {
      // this child will be the left child of current node
      current->left = new Node(child1);
      q.push(current->left);
    }

    if (child2 != -1)
    {
      // this child will be the right child of current node
      current->right = new Node(child2);
      q.push(current->right);
    }
  }

  return root;
}

/**
 * @brief
 * Preorder build of the Tree Root, Left, Right Tree from user inpu
 *
 * @return Node*
 */
Node *BuildTree()
{
  int data;
  cin >> data;

  if (data == -1)
  {
    return nullptr;
  }

  Node *node = new Node(data);
  node->left = BuildTree();
  node->right = BuildTree();

  return node;
}

int Height(Node *root)
{
  // base case
  if (root == nullptr)
  {
    return 0;
  }

  // height of left subtree
  int h1 = Height(root->left);

  // height of right subtree
  int h2 = Height(root->right);

  return 1 + max(h1, h2);
}

void PrintPreOrder(Node *root)
{
  if (root == nullptr)
  {
    return;
  }

  cout << root->data << " ";

  PrintPreOrder(root->left);
  PrintPreOrder(root->right);
}

/**
 * @brief
 * returns the sum of all the nodes in a given root
 * node of a Binary Tree
 *
 * @param root
 * @return int
 */
int SumNodes(Node *root)
{
  if (root == nullptr)
  {
    return 0;
  }

  return root->data + SumNodes(root->left) + SumNodes(root->right);
}

/**
 * @brief
 * returns the max distance between 2 nodes in a Binary Tree
 * given its root node
 *
 * Time Complexity: O(n^2)
 *
 * @param root
 * @return int
 */
int Diameter(Node *root)
{
  // base case
  if (root == nullptr)
    return 0;

  // recursive case
  // D1 passes through the root
  int d1 = Height(root->left) + Height(root->right);

  // the diameter lies in the left subtree
  int d2 = Diameter(root->left);

  // the diameter lies in the right subtree
  int d3 = Diameter(root->right);

  return max(d1, max(d2, d3));
}

struct HDPair
{
  int height;
  int diameter;
};

/**
 * @brief
 * returns the max distance between 2 nodes in a Binary Tree
 * given its root node
 *
 * Time Complexity: O(n)
 *
 * @param root
 * @return HDPair
 */
HDPair DiameterOptimised(Node *root)
{
  // first = height, second = diameter
  HDPair p;

  // base case
  if (root == nullptr)
  {
    p.height = p.diameter = 0;
    return p;
  }

  // recursive
  auto leftPair = DiameterOptimised(root->left);
  auto rightPair = DiameterOptimised(root->right);

  // compute the height at current node
  p.height = max(leftPair.height, rightPair.height) + 1;

  // compute the diameter
  int D1 = leftPair.height + rightPair.height;
  int D2 = leftPair.diameter;
  int D3 = rightPair.diameter;

  p.diameter = max(D1, max(D2, D3));

  return p;
}

void PrintInOrder(Node *root)
{
  if (root == nullptr)
  {
    return;
  }

  PrintInOrder(root->left);

  cout << root->data << " ";

  PrintInOrder(root->right);
}

/**
 * @brief
 * Prints the Kth level in a binary tree
 *
 * @param root
 * @param k
 */
void PrintKthLevel(Node *root, int k)
{
  if (root == nullptr || k < 0)
    return;

  if (k == 0)
    cout << root->data << " ";

  PrintKthLevel(root->left, k - 1);
  PrintKthLevel(root->right, k - 1);
}

void PrintPostOrder(Node *root)
{
  if (root == nullptr)
  {
    return;
  }

  PrintPostOrder(root->left);
  PrintPostOrder(root->right);

  cout << root->data << " ";
}

void PrintLevelOrder(Node *root)
{
  queue<Node *> q;

  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    auto temp = q.front();

    if (temp == NULL)
    {
      cout << endl;
      q.pop();

      if (!q.empty())
        q.push(NULL);
    }
    else
    {
      q.pop();
      cout << temp->data << " ";
      // push the childen
      if (temp->left)
      {
        q.push(temp->left);
      }
      if (temp->right)
      {
        q.push(temp->right);
      }
    }
  }
}

int main()
{
  auto root = BuildTreeLevelOrder();

  PrintPreOrder(root);
  cout << endl;

  PrintInOrder(root);
  cout << endl;

  PrintPostOrder(root);
  cout << endl;

  PrintLevelOrder(root);
  cout << endl;

  PrintKthLevel(root, 2);

  cout << endl;

  cout << SumNodes(root) << endl;

  cout << "Diameter is " << Diameter(root) << endl;
  cout << "Optimised Diameter is " << DiameterOptimised(root).diameter << endl;

  return 0;
}