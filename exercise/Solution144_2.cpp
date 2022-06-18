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
        stack<TreeNode *> m_stack;
        TreeNode *cur = root;

        while (!m_stack.empty() || cur != nullptr) {
            while (cur != nullptr) {
                res.push_back(cur->val);
                m_stack.push(cur);
                cur = cur->left;
            }

            TreeNode *parent = m_stack.top();
            m_stack.pop();
            cur = parent->right;
        }

        return res;
    }
};