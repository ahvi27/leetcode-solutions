#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long LIMIT = 1000000;

    long long countWays(vector<int>& cnt, int total) {
        long long res = 1;

        for (int i = 0; i < 26; i++) {
            int c = cnt[i];

            for (int j = 1; j <= c; j++) {
                res = res * (total - j + 1) / j;

                if (res > LIMIT)
                    return LIMIT;
            }

            total -= c;
        }

        return res;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);
        char mid = '\0';

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;

            if (freq[i] % 2)
                mid = char('a' + i);
        }

        int n = s.size() / 2;

        if (k > countWays(half, n))
            return "";

        string left = "";

        for (int pos = 0; pos < n; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = countWays(half, n - pos - 1);

                if (k > ways) {
                    k -= ways;
                    half[c]++;
                }
                else {
                    left += char('a' + c);
                    break;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid != '\0')
            return left + string(1, mid) + right;

        return left + right;
    }
};

int main() {
    Solution sol;

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    string result = sol.smallestPalindrome(s, k);

    if (result.empty())
        cout << "No possible palindrome\n";
    else
        cout << "Answer: " << result << endl;

    return 0;
}