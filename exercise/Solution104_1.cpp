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
    int maxDepth(TreeNode *root) {
        int res = 0;
        queue<pair<TreeNode *, int>> bfsQueue;
        if (root)
            bfsQueue.push({root, 1});
        while (!bfsQueue.empty()){
            auto nodeAndLevel = bfsQueue.front();
            bfsQueue.pop();
            TreeNode *node = nodeAndLevel.first;
            int level = nodeAndLevel.second;

            if (level > res)
                res = nodeAndLevel.second;

            if (node->left)
                bfsQueue.push({node->left, level + 1});
            if (node->right)
                bfsQueue.push({node->right, level + 1});
        }

        return res;
    }
};