#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string smallestPalindrome(string s) {
    vector<int> freq(26, 0);

    for (char c : s) {
        freq[c - 'a']++;
    }

    string left = "";
    char middle = '\0';

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            middle = char('a' + i);
        }

        left += string(freq[i] / 2, char('a' + i));
    }

    string right = left;
    reverse(right.begin(), right.end());

    if (middle != '\0') {
        return left + middle + right;
    }

    return left + right;
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Smallest Palindromic Rearrangement: ";
    cout << smallestPalindrome(s) << endl;

    return 0;
}