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
    TreeNode *invertTree(TreeNode *root) {
        queue<TreeNode *> bfsQueue;
        if (root != nullptr)
            bfsQueue.push(root);

        while (!bfsQueue.empty()){
            TreeNode *cur = bfsQueue.front();
            bfsQueue.pop();

            TreeNode *temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;

            if (cur->left)
                bfsQueue.push(cur->left);
            if (cur->right)
                bfsQueue.push(cur->right);
        }

        return root;
    }
};