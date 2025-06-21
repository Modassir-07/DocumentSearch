# Document Search Engine

A C++ based tool for indexing and searching text documents using trie-based dictionary and efficient pattern matching.

---

## 🔍 Features

- ✅ Build a word frequency dictionary from text documents
- ✅ Perform case-insensitive pattern search (even if pattern starts/ends mid-word)
- ✅ Extract word counts
- ✅ Export dictionary to a text file

---

## 📁 File Overview

| File            | Description                                        |
|-----------------|----------------------------------------------------|
| `dict.h/cpp`    | Implements a Trie-based word dictionary            |
| `search.h/cpp`  | Stores sentences and performs substring search     |
| `Node.h/cpp`    | Defines linked list nodes for search result output |
| `main.cpp`      | Driver code to load input file and run operations  |
| `output_dict.txt` | (Generated) File with word counts                |

---

## 🛠️ How to Compile & Run

```bash
g++ -std=c++17 main.cpp dict.cpp search.cpp Node.cpp -o main
./main
```
You'll be prompted to enter the path of a .txt file and can choose options to:

Insert sentences

Search for patterns

Count word frequency

Dump dictionary to a file

📌 Notes
Input files must be .txt. For PDFs, convert them to .txt manually.

Pattern matching is case-insensitive and can detect substrings inside words.

Proper memory management is handled using destructors.

✍️ Author
Modassir Faruquee
GitHub: Modassir-07