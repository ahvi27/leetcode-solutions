#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count = 0;
        int candidate = 0;

        for (int num : nums) {

            if (count == 0)
                candidate = num;

            if (num == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {3, 2, 3};

    cout << "Majority Element: "
         << sol.majorityElement(nums);

    return 0;
}