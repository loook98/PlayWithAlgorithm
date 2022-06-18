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
        postOrder(root);
        return res;
    }

    //返回值: 从孩子到root的最长路径
    int postOrder(TreeNode *root) {
        if (root == nullptr)
            return 0;

        int l = postOrder(root->left);
        int r = postOrder(root->right);

        res = max({res, root->val, root->val + l, root->val + r, root->val + l + r});
        return root->val + (max(l , r) > 0 ? max(l, r) : 0);
    }
};