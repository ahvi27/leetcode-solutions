#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> events;

        for (auto& b : buildings) {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1], b[2]});
        }

        sort(events.begin(), events.end());

        priority_queue<int> pq;
        unordered_map<int,int> removed;

        pq.push(0);

        vector<vector<int>> ans;
        int prev = 0;

        for (auto& e : events) {
            int x = e.first;
            int h = e.second;

            if (h < 0)
                pq.push(-h);
            else
                removed[h]++;

            while (!pq.empty() && removed[pq.top()]) {
                removed[pq.top()]--;
                pq.pop();
            }

            int curr = pq.top();

            if (curr != prev) {
                ans.push_back({x, curr});
                prev = curr;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> buildings = {
        {2,9,10},
        {3,7,15},
        {5,12,12},
        {15,20,10},
        {19,24,8}
    };

    vector<vector<int>> result = sol.getSkyline(buildings);

    for (auto &p : result) {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }

    return 0;
}