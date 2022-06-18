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
    //中序遍历，教科书上的经典实现
    //与先序遍历思路一致，一直沿着左节点向下遍历（直到遇到null为止）,stack用于记录一个字数遍历完后他的父节点（通过pop出--c++ pop不返回），输出
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;
        TreeNode *cur = root;

        while (!stack.empty() || cur != nullptr){
            //一直沿着左节点向下遍历（直到遇到null为止）
            while (cur != nullptr){
                stack.emplace(cur);
                cur = cur->left;
            }
            cur = stack.top();
            stack.pop();
            res.emplace_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};

