#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0, sum = 0;
    int ans = INT_MAX;

    for (int right = 0; right < n; right++) {
        sum += nums[right];

        while (sum >= target) {
            ans = min(ans, right - left + 1);
            sum -= nums[left++];
        }
    }

    return ans == INT_MAX ? 0 : ans;
}

int main() {
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    cout << minSubArrayLen(target, nums) << endl;

    return 0;
}