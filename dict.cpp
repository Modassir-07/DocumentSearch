#include "dict.h"
TrieNode::TrieNode() {
    cnt = 0;
    word = nullptr;
    children = new TrieNode*[101];
    for (int i = 0; i < 101; ++i) {
        children[i] = nullptr;
    }
}

TrieNode::~TrieNode() {
    for (int i = 0; i < 101; ++i) {
        if (children[i]) delete children[i];
    }
    delete[] children;
    if (word) delete word;
}

void TrieNode::insert(string w) {
    int place;
    TrieNode* at = this;
    for (char &ch : w) {
        place = (int)ch;
        if ('A' <= place && place <= 'Z') {
            place += 32;
            ch += 32;
        }
        if (place > 'Z') place -= 26;
        if (!at->children[place]) at->children[place] = new TrieNode();
        at = at->children[place];
    }
    at->cnt++;
    at->word = new string(w);
}

Dict::Dict() {
    root = new TrieNode();
}

Dict::~Dict() {
    delete root;
}

string separators = " .,-:!\"'()?[];@";

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence) {
    string w = "";
    for (char c : sentence) {
        if (separators.find(c) != string::npos) {
            if (!w.empty()) {
                root->insert(w);
                w = "";
            }
        } else {
            w += c;
        }
    }
    if (!w.empty()) root->insert(w);
}

int Dict::get_word_count(string w) {
    TrieNode* at = root;
    for (char ch : w) {
        int place = (int)ch;
        if ('A' <= place && place <= 'Z') place += 32;
        if (place > 'Z') place -= 26;
        if (!at->children[place]) return 0;
        at = at->children[place];
    }
    return at->cnt;
}

void print(TrieNode* root, ofstream& fout) {
    if (root->word) fout << *(root->word) << "," << root->cnt << endl;
    for (int i = 0; i < 101; ++i) {
        if (root->children[i]) print(root->children[i], fout);
    }
}

void Dict::dump_dictionary(string filename) {
    ofstream fout(filename);
    print(root, fout);
    fout.close();
}