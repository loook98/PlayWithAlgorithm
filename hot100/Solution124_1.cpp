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
        res = max(res, dfs(root));
        return res;
    }

    int dfs(TreeNode *root){ //返回值为到root的最大路径
        if (root == nullptr)
            return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);
        res = max({res, root->val, root->val + l, root->val + r, root->val + l + r});//更新最值
        return root->val + (max(l , r) > 0 ? max(l , r) : 0);
    }
};