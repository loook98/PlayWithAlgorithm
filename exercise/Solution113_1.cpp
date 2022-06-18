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

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> path;
        backTracking(root, path, 0, targetSum);
        return res;
    }

    void backTracking(TreeNode *cur, vector<int> &path, int pathSum, int targetSum) {
        if (cur == nullptr)
            return;

        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr && pathSum == targetSum - cur->val){
            res.push_back(path);
        }
        backTracking(cur->left, path, pathSum + cur->val, targetSum);
        backTracking(cur->right, path, pathSum + cur->val, targetSum);
        path.pop_back();
    }
};