#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Node {

public:

    int val;

    vector<Node*> neighbors;


    Node(int _val) {

        val = _val;

    }
};



class Solution {

public:

    unordered_map<Node*, Node*> mp;


    Node* cloneGraph(Node* node) {


        if (node == nullptr)
            return nullptr;


        if (mp.count(node))
            return mp[node];


        Node* clone = new Node(node->val);


        mp[node] = clone;


        for (Node* neighbor : node->neighbors) {

            clone->neighbors.push_back(
                cloneGraph(neighbor)
            );

        }


        return clone;
    }
};



int main() {


    Node* node1 = new Node(1);
    Node* node2 = new Node(2);


    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node1);


    Solution sol;


    Node* cloned = sol.cloneGraph(node1);


    cout << cloned->val;


    return 0;
}