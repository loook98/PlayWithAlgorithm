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
    int preorderIndex = 0; //记录前序遍历的索引
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, inorder, 0, inorder.size() - 1);
    }

    //根据inorder的[l...r]构建二叉树
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int l, int r) {
        if (l > r)
            return nullptr;

        //rootIndex为inorder[l...r]这颗子树的根节点
        int rootIndex = l;
        while (rootIndex <= r) {
            if (inorder[rootIndex] == preorder[preorderIndex])
                break;
            rootIndex++;
        }
        preorderIndex++;

        TreeNode *root = new TreeNode(inorder[rootIndex]);
        root->left = build(preorder, inorder, l, rootIndex - 1);
        root->right = build(preorder, inorder, rootIndex + 1, r);
        return root;
    }
};