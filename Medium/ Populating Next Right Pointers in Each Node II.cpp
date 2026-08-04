#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int x) {
        val = x;
        left = right = next = nullptr;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* curr = root;

        while (curr) {
            Node dummy(0);
            Node* tail = &dummy;

            while (curr) {

                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }

                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }

                curr = curr->next;
            }

            curr = dummy.next;
        }

        return root;
    }
};


void printLevels(Node* root) {
    Node* curr = root;

    while (curr) {
        Node* temp = curr;

        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << "# ";
        curr = curr->left ? curr->left : curr->right;
    }
}


int main() {

    /*
             1
           /   \
          2     3
         /       \
        4         5

    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    Solution sol;

    sol.connect(root);

    printLevels(root);

    return 0;
}