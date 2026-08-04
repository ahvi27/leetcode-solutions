#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string t = s + "#" + rev;
        vector<int> lps(t.size(), 0);

        for (int i = 1; i < t.size(); i++) {
            int j = lps[i - 1];
            while (j > 0 && t[i] != t[j])
                j = lps[j - 1];
            if (t[i] == t[j])
                j++;
            lps[i] = j;
        }

        return rev.substr(0, s.size() - lps.back()) + s;
    }
};

int main() {
    Solution sol;

    cout << sol.shortestPalindrome("aacecaaa") << endl; // aaacecaaa
    cout << sol.shortestPalindrome("abcd") << endl;     // dcbabcd

    return 0;
}