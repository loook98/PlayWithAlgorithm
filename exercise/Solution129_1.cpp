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
    int res = 0;

    int sumNumbers(TreeNode *root) {
        if (root)
            dfs(root, 0);
        return res;
    }

    void dfs(TreeNode *root, int parentVal) {
        int curVal = parentVal * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            res += curVal;

        if (root->left)
            dfs(root->left, curVal);
        if (root->right)
            dfs(root->right, curVal);
    }
};