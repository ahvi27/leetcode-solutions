#include <iostream>
#include <bitset>
#include <cstdint>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;

    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }

    return result;
}

int main() {
    uint32_t n;

    cout << "Enter an unsigned integer: ";
    cin >> n;

    uint32_t reversed = reverseBits(n);

    cout << "Original bits : " << bitset<32>(n) << endl;
    cout << "Reversed bits : " << bitset<32>(reversed) << endl;
    cout << "Result        : " << reversed << endl;

    return 0;
}