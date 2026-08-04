#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {

            auto current = q.front();
            q.pop();

            string word = current.first;
            int level = current.second;

            if (word == endWord)
                return level;

            for (int i = 0; i < word.size(); i++) {

                string temp = word;

                for (char c = 'a'; c <= 'z'; c++) {

                    temp[i] = c;

                    if (dict.count(temp)) {

                        q.push({temp, level + 1});
                        dict.erase(temp);

                    }
                }
            }
        }

        return 0;
    }
};

int main() {

    vector<string> wordList = {
        "hot","dot","dog","lot","log","cog"
    };

    Solution sol;

    cout << sol.ladderLength("hit", "cog", wordList);

    return 0;
}