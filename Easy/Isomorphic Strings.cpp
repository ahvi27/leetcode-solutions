#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isIsomorphic(string s, string t) {
    vector<int> mapST(256, -1), mapTS(256, -1);

    for (int i = 0; i < s.size(); i++) {
        if (mapST[s[i]] != mapTS[t[i]])
            return false;

        mapST[s[i]] = i;
        mapTS[t[i]] = i;
    }

    return true;
}

int main() {
    string s = "egg";
    string t = "add";

    if (isIsomorphic(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}