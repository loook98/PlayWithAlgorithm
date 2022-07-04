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

//递归版本。（双节点在一个函数内同步递归）
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;

        return check(root->left, root->right);
    }

    //一层一层地检查
    bool check(TreeNode *l, TreeNode *r){
        if (l == nullptr && r == nullptr)
            return true;
        if ((l == nullptr && r != nullptr) ||
            (l != nullptr && r == nullptr))
            return false;

        if (l->val != r->val)
            return false;
        return check(l->left, r->right) && check(l->right, r->left);
    }
};