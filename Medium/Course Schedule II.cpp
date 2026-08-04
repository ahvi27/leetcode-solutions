#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);

    for (auto &p : prerequisites) {
        graph[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> order;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        order.push_back(curr);

        for (int next : graph[curr]) {
            if (--indegree[next] == 0)
                q.push(next);
        }
    }

    if (order.size() != numCourses)
        return {};

    return order;
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}};

    vector<int> order = findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "No valid course order exists." << endl;
    } else {
        for (int course : order)
            cout << course << " ";
        cout << endl;
    }

    return 0;
}