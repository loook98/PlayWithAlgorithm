#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int preSum = 0;
    TreeNode *convertBST(TreeNode *root) {
        inorder(root);
        return root;
    }

    //右-中-左的中序遍历
    void inorder(TreeNode *node){
        if (node == nullptr)
            return;

        inorder(node->right);
        node->val += preSum;
        preSum = node->val;
        inorder(node->left);
    }
};