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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *cur = root;
        stack<TreeNode *> inorderStack;

        while (!inorderStack.empty() || cur != nullptr){ //这里是cur，而不是root
            while (cur != nullptr){
                inorderStack.push(cur);
                cur = cur->left;
            }

            TreeNode *node = inorderStack.top();
            inorderStack.pop();
            res.push_back(node->val);

            cur = node->right;
        }

        return res;
    }
};