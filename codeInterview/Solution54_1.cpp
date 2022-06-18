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
    int kthLargest(TreeNode *root, int k) {
        vector<int> vec;
        inOrder(root, vec);
        return vec[vec.size() - k];
    }

    void inOrder(TreeNode *root, vector<int> &vec) {
        if (root == nullptr)
            return;

        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }
};