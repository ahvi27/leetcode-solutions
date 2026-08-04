#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


string reverseWords(string s) {

    vector<string> words;

    string word;


    for (char c : s) {

        if (c != ' ') {

            word += c;

        } else {

            if (!word.empty()) {

                words.push_back(word);

                word = "";
            }
        }
    }


    if (!word.empty())
        words.push_back(word);



    reverse(words.begin(), words.end());


    string result = "";


    for (int i = 0; i < words.size(); i++) {

        result += words[i];

        if (i != words.size() - 1)
            result += " ";
    }


    return result;
}



int main() {

    string s = "the sky is blue";


    cout << reverseWords(s) << endl;


    return 0;
}