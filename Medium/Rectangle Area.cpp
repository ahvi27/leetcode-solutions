#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {

        long long area1 = 1LL * (ax2 - ax1) * (ay2 - ay1);
        long long area2 = 1LL * (bx2 - bx1) * (by2 - by1);

        int width = max(0, min(ax2, bx2) - max(ax1, bx1));
        int height = max(0, min(ay2, by2) - max(ay1, by1));

        long long overlap = 1LL * width * height;

        return area1 + area2 - overlap;
    }
};

int main() {
    Solution sol;

    cout << sol.computeArea(
        -3, 0, 3, 4,
        0, -1, 9, 2
    ) << endl;  // 45

    return 0;
}