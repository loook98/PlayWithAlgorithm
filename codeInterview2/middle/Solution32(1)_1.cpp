#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode *root) {
        queue<TreeNode *> queue;
        vector<int> res;
        if (root == nullptr)
            return res;
        queue.push(root);
        while (!queue.empty()){
            TreeNode *cur = queue.front();
            queue.pop();
            res.push_back(cur->val);

            if (cur->left)
                queue.push(cur->left);
            if (cur->right)
                queue.push(cur->right);
        }

        return res;
    }
};