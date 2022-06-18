
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
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode *root, int target) {
        dfs(root, target);
        return res;
    }

    void dfs(TreeNode *root, int num){
        if (root == nullptr)
            return;

        path.emplace_back(root->val);
        num -= root->val;
        if (root->left == nullptr && root->right == nullptr && num == 0)
            res.emplace_back(path);

        dfs(root->left, num);
        dfs(root->right, num);
        path.pop_back();
    }
};

