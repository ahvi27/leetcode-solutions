#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {

public:

    int minCut(string s) {

        int n = s.size();


        vector<vector<bool>> pal(
            n,
            vector<bool>(n, false)
        );


        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || pal[i + 1][j - 1])) {

                    pal[i][j] = true;
                }
            }
        }



        vector<int> dp(n);


        for (int i = 0; i < n; i++) {

            if (pal[0][i]) {

                dp[i] = 0;

            } else {

                dp[i] = i;


                for (int j = 1; j <= i; j++) {

                    if (pal[j][i]) {

                        dp[i] = min(
                            dp[i],
                            dp[j - 1] + 1
                        );

                    }
                }
            }
        }


        return dp[n - 1];
    }
};



int main() {

    string s = "aab";


    Solution sol;


    cout << sol.minCut(s);


    return 0;
}