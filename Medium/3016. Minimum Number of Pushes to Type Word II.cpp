#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int minimumPushes(string word) {
    vector<int> freq(26, 0);

    for (char c : word)
        freq[c - 'a']++;

    sort(freq.begin(), freq.end(), greater<int>());

    int ans = 0;

    for (int i = 0; i < 26 && freq[i] > 0; i++) {
        ans += freq[i] * (i / 8 + 1);
    }

    return ans;
}

int main() {
    string word;
    cin >> word;

    cout << minimumPushes(word) << endl;

    return 0;
}