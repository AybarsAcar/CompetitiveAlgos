#include <iostream>
#include <string>
#include <vector>

#include "trie.hpp"

using namespace std;

void FindPrefixStrings(vector<string> words, string prefix, vector<string> &output)
{
  Trie t;
  for (string word : words)
    t.Insert(word);

  output = t.Find(prefix);
}

int main()
{
  vector<string> words = {"hell", "hello", "aybars", "shuang", "love", "cpp", "java"};

  Trie trie;

  for (auto word : words)
  {
    trie.Insert(word);
  }

  bool looping = true;

  while (looping)
  {
    string word;
    cin >> word;

    if (word == "q")
    {
      looping = false;
    }

    cout << word << " exists: " << trie.Search(word) << endl;
  }

  vector<string> ws = {"abba", "abbb", "abbc", "abbd", "abaa", "abca"};

  vector<string> result;

  FindPrefixStrings(ws, "abb", result);

  for (auto w : result)
  {
    cout << w << endl;
  }

  return 0;
}