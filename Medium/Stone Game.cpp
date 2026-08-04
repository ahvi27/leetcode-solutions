#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {5, 3, 4, 5};

    cout << (sol.stoneGame(piles) ? "true" : "false") << endl;

    return 0;
}