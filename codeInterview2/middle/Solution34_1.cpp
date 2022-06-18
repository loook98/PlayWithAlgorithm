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
    vector<vector<int>> res;

    vector<vector<int>> pathSum(TreeNode *root, int target) {
        if (root == nullptr)
            return res;
        vector<int> path;
        dfs(root, target, path, 0);
        return res;
    }

    void dfs(TreeNode *node, int target, vector<int> &path, int pathSum) {
        if (node->left == nullptr && node->right == nullptr) {
            if (target - node->val == pathSum) {
                path.push_back(node->val);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }

        path.push_back(node->val);
        if (node->left)
            dfs(node->left, target, path, pathSum + node->val);
        if (node->right)
            dfs(node->right, target, path, pathSum + node->val);
        path.pop_back();
    }
};