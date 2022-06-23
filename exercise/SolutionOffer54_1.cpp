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
    int index = 0, res = 0;
    bool found = false;
    int kthLargest(TreeNode *root, int k) {
        inorder(root, k);
        return res;
    }

    void inorder(TreeNode *root, int k){
        if (found ||  root == nullptr)
            return;

        inorder(root->right, k);
        index++;
        if (index == k){
            res = root->val;
            found = true;
        }
        inorder(root->left, k);
    }
};