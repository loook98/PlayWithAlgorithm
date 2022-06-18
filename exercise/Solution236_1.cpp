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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || root == p || root == q)
            return root;

        TreeNode *leftRet = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightRet = lowestCommonAncestor(root->right, p, q);

        if (leftRet == nullptr && rightRet == nullptr)
            return nullptr;
        else if (leftRet && rightRet)
            return root;
        else if (leftRet)
            return leftRet;
        else //rightRet != null
            return rightRet;
    }
};