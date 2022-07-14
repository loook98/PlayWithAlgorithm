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
    int res = 0; //全局变量记录这个问题的答案, ★在后序遍历的遍历的位置更新★

    int diameterOfBinaryTree(TreeNode *root) {
        postOrder(root);

        return res - 1;
    }

    //此函数返回值为「从node的孩子节点到node的路径上有几个节点」
    int postOrder(TreeNode *node){
        if (node == nullptr)
            return 0;

        int leftRet = postOrder(node->left);
        int rightRet = postOrder(node->right);

        res = max({res, leftRet + rightRet + 1});

        return 1 + max(leftRet, rightRet);
    }
};