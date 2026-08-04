#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int start, int k, int n) {
        if (k == 0 && n == 0) {
            ans.push_back(path);
            return;
        }

        if (k == 0 || n <= 0)
            return;

        for (int i = start; i <= 9; i++) {
            path.push_back(i);
            dfs(i + 1, k - 1, n - i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> result = sol.combinationSum3(3, 7);

    for (auto &v : result) {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}