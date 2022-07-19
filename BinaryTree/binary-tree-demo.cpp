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

  return 0;
}