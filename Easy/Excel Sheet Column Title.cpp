#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {

        string ans = "";

        while (columnNumber > 0) {

            columnNumber--;

            ans += char('A' + (columnNumber % 26));

            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {

    Solution sol;

    int columnNumber = 701;

    cout << sol.convertToTitle(columnNumber);

    return 0;
}