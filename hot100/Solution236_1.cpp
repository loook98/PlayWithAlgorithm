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

        TreeNode *leftRet = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightRet = lowestCommonAncestor(root->right, p ,q);

        if ( root->val == p->val || root->val == q->val){
            return root;
        } else{
            if (leftRet && rightRet)
                return root;
            else if (leftRet)
                return leftRet;
            else if (rightRet)
                return rightRet;
            else
                return nullptr;
        }
    }
};