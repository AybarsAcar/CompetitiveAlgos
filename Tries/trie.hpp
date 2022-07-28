#include <unordered_map>
#include <string>

using namespace std;

class Node
{
public:
  char data;
  unordered_map<char, Node *> children;
  bool isTerminal;

public:
  Node(char data)
  {
    this->data = data;
    isTerminal = false;
  }
};

class Trie
{
  Node *root;

public:
  Trie();

  void Insert(string word);
  bool Search(string word);
  void DepthFirstSearch(Node *temp, vector<string> &v, string word);
  vector<string> Find(string str);
};

Trie::Trie()
{
  root = new Node('\0');
}

void Trie::Insert(string word)
{
  Node *current = root;

  for (char ch : word)
  {
    // if the word does not exist in the children map
    if (current->children.count(ch) == 0)
    {
      // create a new node and add as a child
      Node *newNode = new Node(ch);
      current->children[ch] = newNode;
    }

    // move to the next node
    current = current->children[ch];
  }

  // we are at the last node so assign it as terminal node
  current->isTerminal = true;
}

bool Trie::Search(string word)
{
  Node *current = root;

  for (char ch : word)
  {
    if (current->children.count(ch) == 0)
    {
      return false;
    }

    current = current->children[ch];
  }

  return current->isTerminal;
}

void Trie::DepthFirstSearch(Node *temp, vector<string> &v, string word)
{
  if (temp->isTerminal)
  {
    v.push_back(word);
  }

  if (temp->children.empty())
  {
    return;
  }

  for (auto p : temp->children)
  {
    word.push_back(p.first);

    DepthFirstSearch(temp->children[p.first], v, word);

    word.pop_back();
  }
}

vector<string> Trie::Find(string str)
{
  vector<string> output;

  Node *current = root;

  string word = "";

  for (int i = 0; i < str.length(); i++)
  {
    if (current->children.count(str[i]) == 0)
    {
      return output;
    }

    word.push_back(str[i]);
    current = current->children[str[i]];
  }

  if (current->isTerminal)
  {
    output.push_back(word);
  }

  DepthFirstSearch(current, output, word);

  sort(output.begin(), output.end());

  return output;
}