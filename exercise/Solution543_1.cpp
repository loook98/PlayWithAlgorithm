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
    int res = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        postOrder(root);
        return res;
    }

    //函数返回值为「左子树到当前根节点的路径(节点数)」和「右子树到当前根节点的路径（节点数）」的最大值
    int postOrder(TreeNode *root) {
        if (root == nullptr)
            return 0;

        int leftMaxPath = postOrder(root->left);
        int rightMaxPath = postOrder(root->right);
        //过当前节点的最大路径（节点数）
        int curRootPath = leftMaxPath + rightMaxPath + 1;
        res = max(res, curRootPath - 1); //题目里的路径是「路径上的节点数-1」
        return max(leftMaxPath, rightMaxPath) + 1;
    }
};