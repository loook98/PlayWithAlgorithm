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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (root == nullptr)
            return res;

        int lastlevel = -1;
        queue<pair<TreeNode *, int>> levelOrderQueue;

        levelOrderQueue.push({root, 0});
        while (!levelOrderQueue.empty()) {
            auto pair = levelOrderQueue.front();
            levelOrderQueue.pop();

            if (pair.second != lastlevel) {
                res.push_back(pair.first->val);
                lastlevel = pair.second;
            }

            if (pair.first->right)
                levelOrderQueue.push({pair.first->right, pair.second + 1});
            if (pair.first->left)
                levelOrderQueue.push({pair.first->left, pair.second + 1});
        }

        return res;
    }
};