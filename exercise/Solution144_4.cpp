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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *cur = root;
        stack<TreeNode *> preorderStack;

        while (!preorderStack.empty() || cur != nullptr){
            while (cur != nullptr){
                res.push_back(cur->val);
                preorderStack.push(cur);
                cur = cur->left;
            }

            cur = preorderStack.top();
            preorderStack.pop();

            cur = cur->right;
        }

        return res;
    }
};