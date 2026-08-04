#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num))
                return true;
            seen.insert(num);
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1};
    cout << (sol.containsDuplicate(nums1) ? "true" : "false") << endl;

    vector<int> nums2 = {1, 2, 3, 4};
    cout << (sol.containsDuplicate(nums2) ? "true" : "false") << endl;

    return 0;
}