#include <iostream>
#include <string>
using namespace std;

class WordDictionary {
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

    bool dfs(string& word, int index, TrieNode* node) {
        if (!node) return false;

        if (index == word.size())
            return node->isEnd;

        char c = word[index];

        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (dfs(word, index + 1, node->child[i]))
                    return true;
            }
            return false;
        }

        return dfs(word, index + 1, node->child[c - 'a']);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
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
        return dfs(word, 0, root);
    }
};

int main() {
    WordDictionary wd;

    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");

    cout << boolalpha;
    cout << wd.search("pad") << endl; // false
    cout << wd.search("bad") << endl; // true
    cout << wd.search(".ad") << endl; // true
    cout << wd.search("b..") << endl; // true

    return 0;
}