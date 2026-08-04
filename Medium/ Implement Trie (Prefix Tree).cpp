#include <iostream>
#include <string>
using namespace std;

class Trie {
private:
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx])
                return false;
            node = node->child[idx];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->child[idx])
                return false;
            node = node->child[idx];
        }
        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");

    cout << boolalpha;
    cout << trie.search("apple") << endl;      // true
    cout << trie.search("app") << endl;        // false
    cout << trie.startsWith("app") << endl;    // true

    trie.insert("app");
    cout << trie.search("app") << endl;        // true

    return 0;
}