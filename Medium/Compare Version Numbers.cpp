#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        int i = 0;
        int j = 0;

        int n = version1.size();
        int m = version2.size();

        while (i < n || j < m) {

            long long num1 = 0;
            long long num2 = 0;

            while (i < n && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            while (j < m && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            if (num1 > num2)
                return 1;

            if (num1 < num2)
                return -1;

            i++;
            j++;
        }

        return 0;
    }
};

int main() {

    Solution sol;

    string v1 = "1.01";
    string v2 = "1.001";

    int result = sol.compareVersion(v1, v2);

    cout << "Result: " << result << endl;

    return 0;
}