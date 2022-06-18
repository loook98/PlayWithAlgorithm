#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool balanced = true;

    bool isBalanced(TreeNode *root) {
        if (root == nullptr)
            return true;

        countDepth(root);
        return balanced;
    }

    int countDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;

        int leftDepth = countDepth(root->left);
        int rightDepth = countDepth(root->right);
        if (abs(leftDepth-rightDepth)>1)
            balanced = false;
        return max(leftDepth, rightDepth) + 1;
    }
};