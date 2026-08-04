#include <iostream>
#include <bitset>
#include <cstdint>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;

    while (n) {
        n &= (n - 1);
        count++;
    }

    return count;
}

int main() {
    uint32_t n;

    cout << "Enter an unsigned integer: ";
    cin >> n;

    cout << "Binary representation: " << bitset<32>(n) << endl;
    cout << "Number of 1 bits: " << hammingWeight(n) << endl;

    return 0;
}