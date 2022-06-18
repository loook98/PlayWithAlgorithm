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
private:
    int res = 1;

    int depth(TreeNode *node){
        if (node == nullptr)
            return 0;

        int l = depth(node->left);
        int r = depth(node->right);
        res = max(res, l + r + 1);
        return max(l, r) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode *root) {
        depth(root);
        return res-1;
    }
};