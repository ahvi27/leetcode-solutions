#include <iostream>
#include <string>
using namespace std;

int minimumPushes(string word) {
    int pushes = 0;

    for (int i = 0; i < word.size(); i++) {
        pushes += (i / 8) + 1;
    }

    return pushes;
}

int main() {
    string word;

    cout << "Enter word: ";
    cin >> word;

    cout << "Minimum pushes: " << minimumPushes(word) << endl;

    return 0;
}