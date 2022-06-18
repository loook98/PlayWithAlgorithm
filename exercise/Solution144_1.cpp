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
    //教科书上经典的非递归实现，先序遍历
    //一直沿着左节点向下遍历（直到遇到null为止），遍历的过程中输出，stack用于记录一个字数遍历完后他的父节点（通过pop出--c++ pop不返回）
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stack;
        TreeNode *cur = root;

        while (!stack.empty() || cur != nullptr){
            while (cur != nullptr){
                res.emplace_back(cur->val);
                stack.emplace(cur);
                cur = cur->left;
            }
            cur = stack.top();
            stack.pop();
            cur = cur->right;
        }
        return res;
    }
};
