#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<string>> memo;

vector<string> solve(string s, unordered_set<string>& dict) {

    if (memo.count(s))
        return memo[s];

    vector<string> result;

    if (s.empty()) {
        result.push_back("");
        return result;
    }

    for (int i = 1; i <= s.size(); i++) {

        string word = s.substr(0, i);

        if (dict.count(word)) {

            vector<string> rest = solve(s.substr(i), dict);

            for (string sentence : rest) {

                if (sentence.empty())
                    result.push_back(word);
                else
                    result.push_back(word + " " + sentence);
            }
        }
    }

    return memo[s] = result;
}


int main() {

    string s = "catsanddog";

    vector<string> wordDict = {
        "cat",
        "cats",
        "and",
        "sand",
        "dog"
    };

    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    vector<string> ans = solve(s, dict);

    for (string x : ans) {
        cout << x << endl;
    }

    return 0;
}