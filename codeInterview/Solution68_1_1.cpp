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
        if (root == nullptr)
            return nullptr;

        if (p->val == root->val || q->val == root->val)
            return root;

        if ((p->val < root->val && q->val > root->val) || (q->val < root->val && p->val > root->val))
            return root;

        if (p->val < root->val) { //p,q都在root左侧
            return lowestCommonAncestor(root->left, p, q);
        } else{
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};