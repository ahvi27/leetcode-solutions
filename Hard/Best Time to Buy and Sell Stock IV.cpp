#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n == 0 || k == 0) return 0;

    // Unlimited transactions case
    if (k >= n / 2) {
        int profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }

    vector<vector<int>> dp(k + 1, vector<int>(2));

    for (int i = 0; i <= k; i++)
        dp[i][1] = INT_MIN;

    for (int price : prices) {
        for (int i = k; i >= 1; i--) {
            dp[i][0] = max(dp[i][0], dp[i][1] + price);
            dp[i][1] = max(dp[i][1], dp[i - 1][0] - price);
        }
    }

    return dp[k][0];
}

int main() {
    int n, k;

    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cout << "Enter maximum transactions: ";
    cin >> k;

    cout << "Maximum Profit: " << maxProfit(k, prices) << endl;

    return 0;
}