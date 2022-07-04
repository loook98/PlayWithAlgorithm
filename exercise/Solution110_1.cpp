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
    bool res = true;

    bool isBalanced(TreeNode *root) {
        depth(root);

        return res;
    }

    int depth(TreeNode *root){
        if (!res){
            return -1;
        }

        if (root == nullptr)
            return 0;

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        if (abs(leftDepth - rightDepth) > 1){
            res = false;
            return -1;
        }

        return max(leftDepth, rightDepth) + 1;
    }
};