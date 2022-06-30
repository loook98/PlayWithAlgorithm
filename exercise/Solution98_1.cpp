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
    TreeNode *prev = nullptr;
    bool res = true;

    bool isValidBST(TreeNode *root) {
        inorder(root);
        return res;
    }

    void inorder(TreeNode *root) {
        if (!res)
            return;

        if (root == nullptr)
            return;

        inorder(root->left);

        if (prev == nullptr){
            prev = root;
        } else{
            if (prev->val >= root->val){
                res = false;
                return;
            } else{
                prev = root;
            }
        }

        inorder(root->right);
    }
};