#include <iostream>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int shifts = 0;

    while (left != right) {
        left >>= 1;
        right >>= 1;
        shifts++;
    }

    return left << shifts;
}

int main() {
    int left, right;

    cin >> left >> right;

    cout << rangeBitwiseAnd(left, right) << endl;

    return 0;
}