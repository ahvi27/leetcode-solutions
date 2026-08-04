#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* root;

    void insert(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->child[idx])
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c,
             TrieNode* node, vector<string>& result) {

        char ch = board[r][c];

        if (ch == '#' || !node->child[ch - 'a'])
            return;

        node = node->child[ch - 'a'];

        if (node->word != "") {
            result.push_back(node->word);
            node->word = "";
        }

        board[r][c] = '#';

        int rows = board.size();
        int cols = board[0].size();

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
                dfs(board, nr, nc, node, result);
        }

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();

        for (string word : words)
            insert(word);

        vector<string> result;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };

    vector<string> words = {"oath","pea","eat","rain"};

    vector<string> ans = sol.findWords(board, words);

    for (string word : ans)
        cout << word << " ";

    return 0;
}