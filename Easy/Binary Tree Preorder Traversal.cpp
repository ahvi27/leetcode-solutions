#include <iostream>
#include <vector>

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


void preorder(TreeNode* root, vector<int>& result) {

    if (root == nullptr)
        return;


    // Root
    result.push_back(root->val);

    // Left
    preorder(root->left, result);

    // Right
    preorder(root->right, result);
}


vector<int> preorderTraversal(TreeNode* root) {

    vector<int> result;

    preorder(root, result);

    return result;
}


int main() {

    /*
             1
              \
               2
              /
             3
    */


    TreeNode* root = new TreeNode(1);

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);


    vector<int> ans = preorderTraversal(root);


    for (int x : ans) {
        cout << x << " ";
    }


    return 0;
}