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
    int index = 0;
    bool found = false;
    int res = -1;
    int kthSmallest(TreeNode *root, int k) {
        inorder(root, k);

        return res;
    }

    void inorder(TreeNode *root, int k){
        if (found)
            return;

        if (root->left)
            inorder(root->left, k);
        index++;
        if (index == k){
            res = root->val;
            found = true;
        }
        if (root->right)
            inorder(root->right, k);
    }
};