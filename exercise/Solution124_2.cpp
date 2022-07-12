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
    int res = INT32_MIN;

    int maxPathSum(TreeNode *root) {
        int rootMax = postOrder(root);


        return res;
    }

    //返回值为从「从下边到当前节点root」的最大路径
    int postOrder(TreeNode *root){
        if (root == nullptr)
            return 0;

        int leftMax = postOrder(root->left);
        int rightMax = postOrder(root->right);

        res = max({res, root->val, root->val + leftMax, root->val + rightMax, root->val + leftMax + rightMax});
        return max({root->val, root->val + leftMax, root->val + rightMax});
    }
};