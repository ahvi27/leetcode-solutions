#include <iostream>
using namespace std;

class TreeNode {
public:
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
    int dfs(TreeNode* node, int current) {
        if (!node)
            return 0;

        current = current * 10 + node->val;

        if (!node->left && !node->right)
            return current;

        return dfs(node->left, current) +
               dfs(node->right, current);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};

int main() {

    /*
           1
          / \
         2   3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;

    cout << sol.sumNumbers(root);

    return 0;
}