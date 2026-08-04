#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:

    string fractionToDecimal(int numerator, int denominator) {

        if (numerator == 0)
            return "0";

        string ans = "";

        if ((numerator < 0) ^ (denominator < 0))
            ans += "-";

        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        ans += to_string(num / den);

        long long rem = num % den;

        if (rem == 0)
            return ans;

        ans += ".";

        unordered_map<long long, int> seen;

        while (rem != 0) {

            if (seen.find(rem) != seen.end()) {

                ans.insert(seen[rem], "(");
                ans += ")";
                break;
            }

            seen[rem] = ans.size();

            rem *= 10;

            ans += to_string(rem / den);

            rem %= den;
        }

        return ans;
    }
};

int main() {

    Solution sol;

    int numerator = 1;
    int denominator = 3;

    cout << sol.fractionToDecimal(numerator, denominator);

    return 0;
}