#include "search.h"
#include <algorithm>

SearchEngine::SearchEngine() {}
SearchEngine::~SearchEngine() {}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence) {
    sentences.push_back({sentence, book_code, page, paragraph, sentence_no});
}

Node* SearchEngine::search(string pattern, int& n_matches) {
    transform(pattern.begin(), pattern.end(), pattern.begin(), ::tolower);
    Node* head = nullptr;
    Node* tail = nullptr;
    n_matches = 0;

    for (auto& info : sentences) {
        string sentence = info.sentence;
        transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

        size_t pos = sentence.find(pattern);
        while (pos != string::npos) {
            Node* new_node = new Node(info.book_code, info.page, info.paragraph, info.sentence_no, (int)pos);
            if (!head) head = tail = new_node;
            else {
                tail->right = new_node;
                new_node->left = tail;
                tail = new_node;
            }
            ++n_matches;
            pos = sentence.find(pattern, pos + 1);
        }
    }
    return head;
}