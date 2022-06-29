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


//二叉树的中序遍历，非递归实现（使用栈）。
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> traversalStack;
        TreeNode *cur = root;

        while (!traversalStack.empty() || cur != nullptr){
            while (cur != nullptr){
                traversalStack.push(cur);
                cur = cur->left;
            }

            cur = traversalStack.top();
            traversalStack.pop();
            res.push_back(cur->val);

            cur = cur->right;
        }

        return res;
    }
};