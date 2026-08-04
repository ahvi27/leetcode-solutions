#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {

public:

    vector<vector<string>> ans;


    bool isPalindrome(string &s, int left, int right) {

        while (left < right) {

            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }



    void backtrack(string &s, int start, vector<string>& path) {

        if (start == s.size()) {

            ans.push_back(path);

            return;
        }


        for (int end = start; end < s.size(); end++) {


            if (isPalindrome(s, start, end)) {


                path.push_back(
                    s.substr(start, end - start + 1)
                );


                backtrack(s, end + 1, path);


                path.pop_back();
            }
        }
    }



    vector<vector<string>> partition(string s) {

        vector<string> path;

        backtrack(s, 0, path);

        return ans;
    }
};



int main() {

    string s = "aab";


    Solution sol;


    vector<vector<string>> result = sol.partition(s);



    for (auto &row : result) {

        cout << "[";

        for (auto &word : row)
            cout << word << " ";

        cout << "]\n";
    }


    return 0;
}