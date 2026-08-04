#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;

        Node* leftmost = root;

        while (leftmost->left != nullptr) {
            Node* current = leftmost;

            while (current != nullptr) {

                current->left->next = current->right;

                if (current->next != nullptr)
                    current->right->next = current->next->left;

                current = current->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};

void printLevels(Node* root) {
    while (root) {
        Node* current = root;

        while (current) {
            cout << current->val << " ";
            current = current->next;
        }

        cout << "# ";
        root = root->left;
    }
}

int main() {

    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;

    sol.connect(root);

    printLevels(root);

    return 0;
}