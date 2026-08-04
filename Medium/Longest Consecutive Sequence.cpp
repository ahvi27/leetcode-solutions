#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());

        int longest = 0;

        for (int num : s) {

            if (!s.count(num - 1)) {

                int current = num;
                int length = 1;

                while (s.count(current + 1)) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};

int main() {

    vector<int> nums = {100, 4, 200, 1, 3, 2};

    Solution sol;

    cout << sol.longestConsecutive(nums);

    return 0;
}