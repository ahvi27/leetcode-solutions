#include <iostream>
#include <algorithm>
#include <climits>
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
    int maxSum = INT_MIN;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftGain = max(0, dfs(node->left));
        int rightGain = max(0, dfs(node->right));

        maxSum = max(maxSum, node->val + leftGain + rightGain);

        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};

int main() {
    /*
            -10
           /   \
          9     20
               /  \
             15    7
    */

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;

    cout << sol.maxPathSum(root);

    return 0;
}