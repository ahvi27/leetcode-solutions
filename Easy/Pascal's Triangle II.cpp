#include <iostream>
#include <vector>
using namespace std;


class Solution {

public:

    vector<int> getRow(int rowIndex) {

        vector<int> row(rowIndex + 1, 1);


        for (int i = 1; i <= rowIndex; i++) {

            for (int j = i - 1; j > 0; j--) {

                row[j] = row[j] + row[j - 1];

            }
        }


        return row;
    }
};



int main() {

    int rowIndex = 4;


    Solution sol;


    vector<int> result = sol.getRow(rowIndex);


    for (int x : result) {
        cout << x << " ";
    }


    return 0;
}