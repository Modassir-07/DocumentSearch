#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class TrieNode {
public:
  int cnt;
  TrieNode** children;
  string* word;
  TrieNode();
  ~TrieNode();
  void insert(string word);
};

class Dict {
private:
    TrieNode* root;

public:
    Dict();
    ~Dict();
    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);
    int get_word_count(string word);
    void dump_dictionary(string filename);
};
