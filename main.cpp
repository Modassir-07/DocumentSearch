#include <iostream>
#include <fstream>
#include <string>
#include "dict.h"
#include "search.h"
using namespace std;

int main() {
    Dict dict;
    SearchEngine engine;

    string filepath;
    cout << "Enter path to text file: ";
    getline(cin, filepath);

    ifstream fin(filepath);
    if (!fin.is_open()) {
        cerr << "Failed to open file.\n";
        return 1;
    }

    string line;
    int book_code = 1, page = 1, paragraph = 1, sentence_no = 1;

    while (getline(fin, line)) {
        if (line.empty()) {
            paragraph++;
            continue;
        }
        dict.insert_sentence(book_code, page, paragraph, sentence_no, line);
        engine.insert_sentence(book_code, page, paragraph, sentence_no, line);
        sentence_no++;
    }

    fin.close();
    cout << "File processed successfully.\n";

    // Interactive search & count loop
    string input;
    while (true) {
        cout << "\nOptions:\n1. Word Count\n2. Pattern Search\n3. Dump Dictionary\n4. Exit\nChoose: ";
        int choice;
        cin >> choice;
        cin.ignore(); // flush newline

        if (choice == 1) {
            cout << "Enter word: ";
            getline(cin, input);
            cout << "Count of \"" << input << "\" = " << dict.get_word_count(input) << endl;
        } else if (choice == 2) {
            cout << "Enter pattern: ";
            getline(cin, input);
            int n_matches = 0;
            Node* head = engine.search(input, n_matches);
            cout << n_matches << " match(es) found.\n";
            Node* curr = head;
            while (curr) {
                cout << "Match → Book " << curr->book_code
                     << ", Page " << curr->page
                     << ", Para " << curr->paragraph
                     << ", Sentence " << curr->sentence_no
                     << ", Offset " << curr->offset << endl;
                curr = curr->right;
            }
        } else if (choice == 3) {
            dict.dump_dictionary("output_dict.txt");
            cout << "Dictionary dumped to output_dict.txt\n";
        } else {
            break;
        }
    }

    return 0;
}
