#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;
    unordered_set<string> dict;

    void dfs(string word, string beginWord, vector<string>& path) {

        if (word == beginWord) {

            vector<string> temp = path;
            reverse(temp.begin(), temp.end());

            ans.push_back(temp);

            return;
        }

        for (string p : parent[word]) {

            path.push_back(p);

            dfs(p, beginWord, path);

            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

        dict = unordered_set<string>(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return {};

        unordered_map<string, int> level;

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        int len = beginWord.size();

        while (!q.empty()) {

            string word = q.front();
            q.pop();

            int cur = level[word];

            string temp = word;

            for (int i = 0; i < len; i++) {

                char old = temp[i];

                for (char c = 'a'; c <= 'z'; c++) {

                    temp[i] = c;

                    if (!dict.count(temp))
                        continue;

                    if (!level.count(temp)) {

                        level[temp] = cur + 1;
                        q.push(temp);

                        parent[temp].push_back(word);

                    }
                    else if (level[temp] == cur + 1) {

                        parent[temp].push_back(word);

                    }
                }

                temp[i] = old;
            }
        }

        if (!level.count(endWord))
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};

int main() {

    vector<string> wordList = {
        "hot","dot","dog","lot","log","cog"
    };

    Solution sol;

    vector<vector<string>> ans =
        sol.findLadders("hit", "cog", wordList);

    for (auto &path : ans) {
        for (auto &word : path)
            cout << word << " ";
        cout << endl;
    }

    return 0;
}