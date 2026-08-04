#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> arr;

        for (int num : nums)
            arr.push_back(to_string(num));

        sort(arr.begin(), arr.end(), [](string a, string b) {
            return a + b > b + a;
        });

        if (arr[0] == "0")
            return "0";

        string ans = "";

        for (string s : arr)
            ans += s;

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {3, 30, 34, 5, 9};

    cout << sol.largestNumber(nums);

    return 0;
}