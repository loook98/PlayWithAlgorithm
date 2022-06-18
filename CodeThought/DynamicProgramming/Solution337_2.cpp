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
    int rob(TreeNode *root) {
        vector<int> val = robTree(root);
        return max(val[0], val[1]);
    }

    //返回值为[不偷root的价值，偷root的价值]
    vector<int> robTree(TreeNode *root) {
        if (root == nullptr)
            return {0, 0};

        vector<int> l = robTree(root->left);
        vector<int> r = robTree(root->right);

        int val0 = max(l[0], l[1]) + max(r[0], r[1]);
        int val1 = root->val + l[0] + r[0];

        return {val0, val1};
    }
};