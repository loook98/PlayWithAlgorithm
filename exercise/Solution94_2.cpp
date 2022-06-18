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
        //mStack中存放上一个父节点，以便遍历完左子树后回到父节点，然后处理右子树
        stack<TreeNode *> mStack;
        TreeNode *cur = root;

        while (!mStack.empty() || cur != nullptr) {
            //遍历左子树
            while (cur != nullptr){
                mStack.push(cur);
                cur = cur->left;
            }

            //遍历完左子树后，取到它的父节点
            cur = mStack.top();
            mStack.pop();
            //遍历父节点
            res.push_back(cur->val);
            //处理右子树
            cur = cur->right;
        }
        return res;
    }
};