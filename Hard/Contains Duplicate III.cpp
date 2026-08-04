#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> window;

        for (int i = 0; i < nums.size(); i++) {

            long long x = nums[i];

            auto it = window.lower_bound(x - t);

            if (it != window.end() && *it <= x + t)
                return true;

            window.insert(x);

            if (window.size() > k)
                window.erase(nums[i - k]);
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,3,1};
    cout << (sol.containsNearbyAlmostDuplicate(nums1, 3, 0) ? "true" : "false") << endl;

    vector<int> nums2 = {1,5,9,1,5,9};
    cout << (sol.containsNearbyAlmostDuplicate(nums2, 2, 3) ? "true" : "false") << endl;

    return 0;
}