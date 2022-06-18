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
    int index = 0, res;
    int kthLargest(TreeNode *root, int k) {
        inOrder(root, k);
        return res;
    }

    void inOrder(TreeNode *root, int k) { //先右节点再当前节点，再左节点遍历的顺序就是逆序排列的顺序
        if (root == nullptr || index >= k)
            return;

        inOrder(root->right, k);
        index++;
        if (index == k)
            res = root->val;

        inOrder(root->left, k);
    }
};