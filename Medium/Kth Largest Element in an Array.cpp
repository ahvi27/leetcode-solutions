#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return *(nums.end() - k);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    cout << sol.findKthLargest(nums1, 2) << endl; // 5

    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << sol.findKthLargest(nums2, 4) << endl; // 4

    return 0;
}