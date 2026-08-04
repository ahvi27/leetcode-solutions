#include <iostream>
#include <stack>
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

class BSTIterator {
public:

    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    void pushLeft(TreeNode* node) {

        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    int next() {

        TreeNode* node = st.top();
        st.pop();

        pushLeft(node->right);

        return node->val;
    }

    bool hasNext() {

        return !st.empty();
    }
};

int main() {

    /*
          7
         / \
        3   15
           /  \
          9   20
    */

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator iterator(root);

    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }

    return 0;
}