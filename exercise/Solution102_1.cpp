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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;

        int lastLevel = -1;
        queue<pair<TreeNode*, int>> levelQueue;
        levelQueue.push({root, 0});

        while (!levelQueue.empty()){
            auto tmpPair = levelQueue.front();
            levelQueue.pop();

            if (tmpPair.second != lastLevel){
                res.emplace_back();
                lastLevel = tmpPair.second;
            }

            res[tmpPair.second].push_back(tmpPair.first->val);

            if (tmpPair.first->left)
                levelQueue.push({tmpPair.first->left, tmpPair.second + 1});
            if (tmpPair.first->right)
                levelQueue.push({tmpPair.first->right, tmpPair.second + 1});
        }

        return res;
    }
};