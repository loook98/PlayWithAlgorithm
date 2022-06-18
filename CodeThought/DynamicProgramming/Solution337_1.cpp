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

//记忆化搜索
class Solution {
public:
    unordered_map<TreeNode *, int> dp;

    int rob(TreeNode *root) {
        if (dp[root] != 0)
            return dp[root];
        if (root == nullptr)
            return 0;

        int choose = 0, dontChoose = 0;
        choose += root->val;
        if (root->left){
            choose += rob(root->left->left);
            choose += rob(root->left->right);
        }
        if (root->right){
            choose += rob(root->right->left);
            choose += rob(root->right->right);
        }

        dontChoose += rob(root->left);
        dontChoose += rob(root->right);

        dp[root] = max(choose, dontChoose);
        return dp[root];
    }
};