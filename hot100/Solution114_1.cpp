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
private:
    vector<TreeNode *> nodes;
public:
    void flatten(TreeNode *root) {
        if (root == nullptr)
            return;

        preOrder(root);
        int n = nodes.size();
        for (int i = 0; i < n - 1; ++i) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i+1];
        }
        nodes[n-1]->left = nullptr;
        nodes[n-1]->right = nullptr;
    }

    void preOrder(TreeNode *root) {
        if (root == nullptr)
            return;

        nodes.push_back(root);
        preOrder(root->left);
        preOrder(root->right);
    }
};