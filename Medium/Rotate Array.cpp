#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main() {
    int n, k;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter k: ";
    cin >> k;

    rotate(nums, k);

    cout << "Rotated array: ";
    for (int x : nums)
        cout << x << " ";

    cout << endl;

    return 0;
}