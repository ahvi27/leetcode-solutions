#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <numeric>

using namespace std;


int maxPoints(vector<vector<int>>& points) {

    int n = points.size();

    if (n <= 2)
        return n;


    int result = 0;


    for (int i = 0; i < n; i++) {

        unordered_map<string, int> mp;

        int duplicate = 0;
        int currentMax = 0;


        for (int j = i + 1; j < n; j++) {

            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];


            if (dx == 0 && dy == 0) {
                duplicate++;
                continue;
            }


            int g = gcd(abs(dx), abs(dy));

            dx /= g;
            dy /= g;


            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }


            if (dx == 0)
                dy = 1;

            if (dy == 0)
                dx = 1;


            string slope = to_string(dy) + "/" + to_string(dx);


            mp[slope]++;

            currentMax = max(currentMax, mp[slope]);
        }


        result = max(result, currentMax + duplicate + 1);
    }


    return result;
}



int main() {

    vector<vector<int>> points = {
        {1,1},
        {2,2},
        {3,3}
    };


    cout << "Maximum points: "
         << maxPoints(points)
         << endl;


    return 0;
}