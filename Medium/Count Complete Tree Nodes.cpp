#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    int getHeight(TreeNode* node) {
        int h = 0;

        while (node) {
            h++;
            node = node->left;
        }

        return h;
    }

    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (leftHeight == rightHeight) {
            return (1 << leftHeight) + countNodes(root->right);
        } 
        else {
            return (1 << rightHeight) + countNodes(root->left);
        }
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;

    cout << sol.countNodes(root) << endl; // 6

    return 0;
}