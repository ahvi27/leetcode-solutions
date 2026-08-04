#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr)
            return targetSum == root->val;

        int remaining = targetSum - root->val;

        return hasPathSum(root->left, remaining) ||
               hasPathSum(root->right, remaining);
    }
};

int main() {
    /*
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \       \
        7    2       1

    Target Sum = 22

    Path: 5 -> 4 -> 11 -> 2
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution sol;

    int targetSum = 22;

    if (sol.hasPathSum(root, targetSum))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}