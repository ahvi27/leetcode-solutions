#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> dp(n + 1, 0);
        int maxSide = 0;

        for (int i = 1; i <= m; i++) {
            int prev = 0;

            for (int j = 1; j <= n; j++) {
                int temp = dp[j];

                if (matrix[i-1][j-1] == '1') {

                    dp[j] = min({
                        dp[j],
                        dp[j-1],
                        prev
                    }) + 1;

                    maxSide = max(maxSide, dp[j]);

                } else {
                    dp[j] = 0;
                }

                prev = temp;
            }
        }

        return maxSide * maxSide;
    }
};

int main() {

    Solution sol;

    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << sol.maximalSquare(matrix) << endl;

    return 0;
}