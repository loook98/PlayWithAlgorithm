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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<pair<TreeNode *, int>> traversalStack; //pair表示节点node出栈过几次
        TreeNode *cur = root;

        while (!traversalStack.empty() || cur != nullptr){
            while (cur != nullptr){
                traversalStack.push({cur, 0});
                cur = cur->left;
            }

            auto tempPair = traversalStack.top();
            traversalStack.pop();
            TreeNode *node = tempPair.first;
            int poppedCnt = tempPair.second;

            if (poppedCnt == 0){
                traversalStack.push({node,1});
                cur = node->right;
            } else{
                res.push_back(node->val);
            }
        }

        return res;
    }
};