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
    bool found = false;

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return false;

        dfs(root, targetSum, 0);
        return found;
    }

    void dfs(TreeNode *root, int targetSum, int pathSum){
        if (found)
            return;
        if (root->left == nullptr && root->right == nullptr){
            if (pathSum + root->val == targetSum)
                found = true;
            return;
        }

        if (root->left)
            dfs(root->left, targetSum, pathSum + root->val);
        if (root->right)
            dfs(root->right, targetSum, pathSum + root->val);
    }
};